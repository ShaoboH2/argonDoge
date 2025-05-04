#!/usr/bin/env bash

CLI="dogecoin-cli -regtest"
ADDR=$($CLI getnewaddress)
OUTFILE="difficulty.csv"

echo "block,time,difficulty" > "$OUTFILE"

TOTAL=40

for ((i=1; i<=TOTAL; i++)); do
    cycle_pos=$(( (i-1) % 40 + 1 ))

    if (( cycle_pos <= 10 )); then
        sleep 10
    elif (( cycle_pos <= 20 )); then
        sleep 2
    elif (( cycle_pos <= 30 )); then
        sleep 20
    else
        sleep 10
    fi

    # Mine one block
    $CLI generatetoaddress 1 "$ADDR" > /dev/null

    # Fetch height and difficulty
    height=$($CLI getblockcount)
    difficulty=$($CLI getdifficulty)

    # Fetch this block’s hash and then its on-chain timestamp
    hash=$($CLI getblockhash "$height")
    timestamp=$($CLI getblock "$hash" | grep -Po '"time":\s*\K[0-9]+')

    # Append to CSV
    echo "${height},${timestamp},${difficulty}" >> "$OUTFILE"
    echo "[$i/$TOTAL] Mined block $height @ $timestamp — difficulty: $difficulty"
done

echo "Simulation complete. Results saved to $(pwd)/$OUTFILE"
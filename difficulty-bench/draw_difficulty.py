import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
from matplotlib.gridspec import GridSpec

# Load data
files = [
    ('difficulty_digishield.csv', 'DigiShield', 'blue'),
    ('difficulty_adaptive.csv', 'Adaptive', 'orange'),
    ('difficulty_lwma.csv', 'LWMA', 'green')
]

dataframes = [(pd.read_csv(path), label, color) for path, label, color in files]

# Events and annotations (clean and short, placed better)
events = {
    5: "Switch to new algo",
    10: "↑ Hashrate (10s→2s)",
    20: "↓ Hashrate (→20s)",
    30: "Stable (10s)"
}

# Set up 2x2 plot
fig = plt.figure(figsize=(18, 10))
gs = GridSpec(2, 2, figure=fig)
axes = [
    fig.add_subplot(gs[0, 0]),  # DigiShield
    fig.add_subplot(gs[0, 1]),  # Adaptive
    fig.add_subplot(gs[1, 0]),  # LWMA
    fig.add_subplot(gs[1, 1])   # Combined
]

# Plot individual
for ax, (df, label, color) in zip(axes[:3], dataframes):
    ax.plot(df['block'], df['difficulty'], label=label, color=color)
    ax.set_title(f'{label} Difficulty')
    ax.set_xlabel('Block')
    ax.set_ylabel('Difficulty')
    ax.legend()

    ymax = df['difficulty'].max()
    for i, (x, text) in enumerate(events.items()):
        ax.axvline(x=x, color='gray', linestyle='--', linewidth=1)
        ax.annotate(
            text, xy=(x, ymax * 0.95), xytext=(x + 1, ymax * (0.8 - 0.1*i)),
            textcoords='data', fontsize=8,
            arrowprops=dict(arrowstyle='->', color='gray'),
            bbox=dict(boxstyle="round", fc="white", ec="gray", alpha=0.8)
        )

# Plot combined log-scale
combined_ax = axes[3]
for df, label, color in dataframes:
    combined_ax.plot(df['block'], df['difficulty'], label=label, color=color)
combined_ax.set_yscale('log')
combined_ax.set_title('Combined Difficulty (Log Scale)')
combined_ax.set_xlabel('Block')
combined_ax.set_ylabel('Difficulty (log)')

# Add annotations
max_diff = max([df['difficulty'].max() for df, _, _ in dataframes])
for i, (x, text) in enumerate(events.items()):
    combined_ax.axvline(x=x, color='gray', linestyle='--', linewidth=1)
    combined_ax.annotate(
        text, xy=(x, max_diff), xytext=(x + 1, max_diff / (2 ** (i + 1))),
        textcoords='data', fontsize=8,
        arrowprops=dict(arrowstyle='->', color='gray'),
        bbox=dict(boxstyle="round", fc="white", ec="gray", alpha=0.8)
    )

combined_ax.legend()

fig.suptitle("Difficulty Adjustment Behavior Across Algorithms", fontsize=16)
plt.tight_layout(rect=[0, 0, 1, 0.96])
output_path = "difficulty_comparison_plot.png"
plt.savefig(output_path)
plt.show()

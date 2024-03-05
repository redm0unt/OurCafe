import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 100 * 2 * np.pi, 100)
plt.close()

y = np.sin(x)
plt.plot(x, y, label='sin(x)')
plt.legend()
plt.title('sin(x) graph')

plt.axhline(0, color='black', lw=1)
plt.axvline(0, color='black', lw=1)
plt.annotate(0, (0, 0), xytext=(5, -10), textcoords='offset points')

print(x)
print()
print("The set above 🔼 should have been visualized sin(x) graph ")
print("All worked fine, but there was nohting because docker doesn't fetched GUI.")
print("But the code is working fine ✅ and now it's in container")



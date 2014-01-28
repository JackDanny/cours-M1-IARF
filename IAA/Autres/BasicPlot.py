'''
def greet(hour):
    if hour < 0 or hour > 23:
        raise ValueError("invalid input value.")
    
    if hour < 12:
        print 'Good morning!'
    elif hour >= 12 and hour < 20:
        print 'Good afternoon!'
    else:
        import ipdb;ipdb.set_trace()
        print 'Good evening!'
'''



print 'Hello World!'

# This will import the numpy library
# and give it the np abbreviation
import numpy as np
# This will import the plotting library
import matplotlib.pyplot as plt
# Linspace will return 1000 points,
# evenly spaced between -4 and +4
X = np.linspace(-4, 4, 1000)
# Y[i] = X[i]**2
Y = X**2
# Plot using a red line ('r')
plt.plot(X, Y, 'r')
# arange returns integers ranging from -4 to +4
# (the upper argument is excluded!)
Ints = np.arange(-4,5)
# We plot these on top of the previous plot
# using blue circles (o means a little circle)
plt.plot(Ints, Ints**2, 'bo')
# You may notice that the plot is tight around the line
# Set the display limits to see better
plt.xlim(-4.5,4.5)
plt.ylim(-1,17)
plt.show()









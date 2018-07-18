class Solution(object):
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        def gcd(x,y):
            if x < y:return gcd(y,x)
            if y == 0:return x
            elif x%2 == 0:
                if y%2 == 0:return gcd(x>>1,y>>1)<<1
                else:return gcd(x>>1,y)
            else:
                if y%2 == 0:return gcd(x,y>>1)
                else:return gcd(y,x-y)

        if z > x+y:return False
        if z == y or z == x or z == x+y:return True
        return z%gcd(x,y) == 0
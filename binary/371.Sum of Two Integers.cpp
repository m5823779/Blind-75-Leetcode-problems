class Solution {
public:
    int getSum(int a, int b) {
		// add => 1, 1 => 0
		//	   => 0, 1 => 1
		//	   => 1, 0 => 1
		//	   => 0, 0 => 0
		// Use XOR operator (^) => add => a ^ b
		
		// carry bit => 1, 1 => 1
		//			 => 1, 0 => 0
		//			 => 0, 1 => 0
		//			 => 0, 0 => 0
		// Use & operator => carry bit => (a & b) << 1
		
		//		 1 0 1  => 5
		//	 	 0 1 1  => 3
		//	 ---------------- add
		//	     1 1 0      (a ^ b)
		//	   0 0 1 0      (a & b) << 1
		//	 ---------------- add
		//	   0 1 0 0      (a ^ b)
		//   0 0 1 0 0      (a & b) << 1
		//   ---------------- add
		//   0 0 0 0 0      (a ^ b)
		//   0 1 0 0 0      (a & b) << 1 
		//   ---------------- add
		//   0 1 0 0 0  => 8(a ^ b)
		//   0 0 0 0 0      (a & b) << 1  => stop
		
		// 1. a = (a ^ b)
		// 2. b = (a & b)
		// 3. if b == 0 =>stop
  
        
		while (b) {
            int carry = (a & b & 0x7fffffff) << 1;
			a = (a ^ b);
			b = carry;
            
		}
        return a;
		// time complexity: O(1)
    }
};
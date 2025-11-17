class Solution {
public:
/*
    we can remove substring where count(a) = count(b)

    approach ????

    it doesn't matter how you removed those, all of them in 1 
    time or differently, it'll be same

    e.g.
    aabb
    0123

    I can remove the whole string from idx 0 to 3

    and I can also remove from idx 1 to 2 and then concatenate
    and then string look like this ab 
    then again I can remove


    so I'll use stack of chars, where I'll put chars 1 by 1
    when the chars opposite I'll pop it out.

    return the stack size that'll be our final output.

*/
    int minLengthAfterRemovals(string s) {
        stack<char> stk;
        for(auto ch : s) {
            if(stk.empty() or stk.top() == ch) stk.push(ch);
            else stk.pop();
        }
        return stk.size();
    }
};
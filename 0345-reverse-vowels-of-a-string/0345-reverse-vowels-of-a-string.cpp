class Solution
{
    public:
        void reverse(string &s)
        {
            int low = 0;
            int high = s.size() - 1;
            set<char> st;
            st.insert({ 'a',
                'e',
                'i',
                'o',
                'u',
                'A',
                'E',
                'I',
                'O',
                'U' });
            while (low <= high)
            {
                char a = s[low];
                char b = s[high];

                if (st.find(a) != st.end() && st.find(b) != st.end())
                {
                    swap(s[low], s[high]);
                    low++;
                    high--;
                }
                else if (st.find(a) != st.end())
                    high--;
            
            else
            {
                low++;
            }
        }
}
string reverseVowels(string s)
{
    reverse(s);
  
    return s;

}
};
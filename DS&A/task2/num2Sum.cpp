void twoNumSum(std::vector<int>& v, int k){
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i+1; j < v.size(); j++)
        {
            if (v[i] + v[j] == k)
            {
                std::cout<<v[i] << " and "<< v[j]<<std::endl;
            }
            
        }
        
    }
    
}

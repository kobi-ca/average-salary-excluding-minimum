#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>

namespace original {

    class Solution {
    public:
        double average(std::vector<int>& salary) {
            double res;
            int n=salary.size(),sum=0;
            sort(salary.begin(),salary.end());
            for(int i=0;i<salary.size();i++)
            {
                sum+=salary[i];
            }
            res = sum - (salary[0] + salary[n-1]);
            res/=(n-2);
            return res;
        }
    };

}

namespace modern {

   double average(const std::vector<int>& salary) {
       const auto [min_iter, max_iter] = std::minmax_element(salary.cbegin(), salary.cend());
       const auto min = *min_iter, max = *max_iter;
       const auto sum = std::accumulate(salary.cbegin(), salary.cend(), 0);
       return (sum - min - max - 0.0) / (salary.size() - 2.0);
   }
}

namespace plain {

    double average(const std::vector<int>& salary) {
        int sum{}, max{std::numeric_limits<int>::min()}, min{std::numeric_limits<int>::max()};
        for(const auto v : salary) {
            sum += v;
            if (v < min) {
                min = v;
            }
            if (v > max) {
                max = v;
            }
        }
        return (sum - min - max - 0.0) / (salary.size() - 2.0);
    }

}

int main() {
    {
        auto v = std::vector{4000, 3000, 1000, 2000};
        std::clog << original::Solution{}.average(v) << '\n';
    }
    {
        const auto v = std::vector{4000, 3000, 1000, 2000};
        std::clog << modern::average(v) << '\n';
    }

    {
        auto v = std::vector{1000,2000,3000};
        std::clog << original::Solution{}.average(v) << '\n';
    }
    {
        const auto v = std::vector{1000,2000,3000};
        std::clog << modern::average(v) << '\n';
    }


    return 0;
}

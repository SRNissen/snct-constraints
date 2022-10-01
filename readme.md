usage example:

in `your_library.h`:

```cpp
#pragma once
#include "snct_constraints.hpp"

namespace your
{
	using Divisor = snct::Constrained<double, snct::Not<0.0>, snct::Finite>;
	
	double inverse(Divisor d);
}

```

in `your_library.cpp`:

```cpp
#include "your_library.h"

namespace your
{
	double inverse(Divisor d)
	{
		return 1/d; //no error handling - all possible values of d are valid for division.
	}
}
```

in user `main.cpp`:

```cpp
#include your_library.h

int main()
{
	if constexpr(exceptions_enabled)
	{
		return inverse(0.25); //will throw snct::Constraint_Exception if 0.25 is not a valid Divisor
	}
	else
	{
		auto optional_divisor = your::Divisor::factory(0.25);   // returns std::nullopt_t if 0.25 is
																// not a valid your::Divisor
		if(optional_divisor)
			return inverse(*optional_divisor);
		else
			/*do your preferred non-exceptional error handling*/;
	}
    }
```

#include "jcdomain.h"
#include "jcapi.h"
#include "JContainers/src/JContainers/src/jc_interface.h"

namespace jc::domain
{
	void* get(const char* a_name)
	{
		return api::getDomainInterface()->get_domain_with_name(a_name);
	}

	void* getDefault()
	{
		return api::getDomainInterface()->get_default_domain();
	}
}
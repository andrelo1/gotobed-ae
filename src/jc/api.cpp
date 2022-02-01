#include "api.h"
#include "apistorage.h"
#include "JContainers/src/JContainers/src/jc_interface.h"

namespace jc::api
{
	template<class F>
	void obtain_func(const char* a_funcName, const char* a_className, F& a_func) {
		a_func = reinterpret_cast<F>(detail::Storage::get().reflectionInterface->tes_function_of_class(a_funcName, a_className));

		if (!a_func) {
			spdlog::error(FMT_STRING("couldn't obtain jc function {}::{}"), a_className, a_funcName);
		}
	}

	bool initApi(const jc::root_interface* a_root)
	{
		if (!a_root) {
			spdlog::critical("couldn't get jc root interface");
			return false;
		}

		auto& storage = detail::Storage::get();

		storage.reflectionInterface = a_root->query_interface<jc::reflection_interface>();

		if (!storage.reflectionInterface) {
			spdlog::critical("couldn't get jc reflection interface");
			return false;
		}

		storage.domainInterface = a_root->query_interface<jc::domain_interface>();

		if (!storage.domainInterface) {
			spdlog::critical("couldn't get jc domain interface");
			return false;
		}

		obtain_func("solveFlt", "JDB", storage.JDB_solveFlt);
		obtain_func("solveInt", "JDB", storage.JDB_solveInt);
		obtain_func("solveStr", "JDB", storage.JDB_solveStr);
		obtain_func("solveObj", "JDB", storage.JDB_solveObj);
		obtain_func("solveForm", "JDB", storage.JDB_solveForm);
		obtain_func("solveFltSetter", "JDB", storage.JDB_solveFltSetter);
		obtain_func("solveIntSetter", "JDB", storage.JDB_solveIntSetter);
		obtain_func("solveStrSetter", "JDB", storage.JDB_solveStrSetter);
		obtain_func("solveObjSetter", "JDB", storage.JDB_solveObjSetter);
		obtain_func("solveFormSetter", "JDB", storage.JDB_solveFormSetter);
		obtain_func("setObj", "JDB", storage.JDB_setObj);
		obtain_func("hasPath", "JDB", storage.JDB_hasPath);
		obtain_func("allKeys", "JDB", storage.JDB_allKeys);
		obtain_func("allValues", "JDB", storage.JDB_allValues);
		obtain_func("writeToFile", "JDB", storage.JDB_writeToFile);
		//obtain_func("readFromFile", "JDB", storage.JDB_readFromFile);
		obtain_func("root", "JDB", storage.JDB_root);

		obtain_func("setEntry", "JFormDB", storage.JFormDB_setEntry);
		obtain_func("makeEntry", "JFormDB", storage.JFormDB_makeEntry);
		obtain_func("findEntry", "JFormDB", storage.JFormDB_findEntry);
		obtain_func("solveFlt", "JFormDB", storage.JFormDB_solveFlt);
		obtain_func("solveInt", "JFormDB", storage.JFormDB_solveInt);
		obtain_func("solveStr", "JFormDB", storage.JFormDB_solveStr);
		obtain_func("solveObj", "JFormDB", storage.JFormDB_solveObj);
		obtain_func("solveForm", "JFormDB", storage.JFormDB_solveForm);
		obtain_func("solveFltSetter", "JFormDB", storage.JFormDB_solveFltSetter);
		obtain_func("solveIntSetter", "JFormDB", storage.JFormDB_solveIntSetter);
		obtain_func("solveStrSetter", "JFormDB", storage.JFormDB_solveStrSetter);
		obtain_func("solveObjSetter", "JFormDB", storage.JFormDB_solveObjSetter);
		obtain_func("solveFormSetter", "JFormDB", storage.JFormDB_solveFormSetter);
		obtain_func("hasPath", "JFormDB", storage.JFormDB_hasPath);
		obtain_func("allKeys", "JFormDB", storage.JFormDB_allKeys);
		obtain_func("allValues", "JFormDB", storage.JFormDB_allValues);
		obtain_func("getInt", "JFormDB", storage.JFormDB_getInt);
		obtain_func("getFlt", "JFormDB", storage.JFormDB_getFlt);
		obtain_func("getStr", "JFormDB", storage.JFormDB_getStr);
		obtain_func("getObj", "JFormDB", storage.JFormDB_getObj);
		obtain_func("getForm", "JFormDB", storage.JFormDB_getForm);
		obtain_func("setInt", "JFormDB", storage.JFormDB_setInt);
		obtain_func("setFlt", "JFormDB", storage.JFormDB_setFlt);
		obtain_func("setStr", "JFormDB", storage.JFormDB_setStr);
		obtain_func("setObj", "JFormDB", storage.JFormDB_setObj);
		obtain_func("setForm", "JFormDB", storage.JFormDB_setForm);

		obtain_func("retain", "JValue", storage.JValue_retain);
		obtain_func("release", "JValue", storage.JValue_release);
		obtain_func("releaseAndRetain", "JValue", storage.JValue_releaseAndRetain);
		obtain_func("releaseObjectsWithTag", "JValue", storage.JValue_releaseObjectsWithTag);
		obtain_func("zeroLifetime", "JValue", storage.JValue_zeroLifetime);
		obtain_func("addToPool", "JValue", storage.JValue_addToPool);
		obtain_func("cleanPool", "JValue", storage.JValue_cleanPool);
		obtain_func("shallowCopy", "JValue", storage.JValue_shallowCopy);
		obtain_func("deepCopy", "JValue", storage.JValue_deepCopy);
		obtain_func("isExists", "JValue", storage.JValue_isExists);
		obtain_func("isArray", "JValue", storage.JValue_isArray);
		obtain_func("isMap", "JValue", storage.JValue_isMap);
		obtain_func("isFormMap", "JValue", storage.JValue_isFormMap);
		obtain_func("isIntegerMap", "JValue", storage.JValue_isIntegerMap);
		obtain_func("empty", "JValue", storage.JValue_empty);
		obtain_func("count", "JValue", storage.JValue_count);
		obtain_func("clear", "JValue", storage.JValue_clear);
		obtain_func("readFromFile", "JValue", storage.JValue_readFromFile);
		obtain_func("readFromDirectory", "JValue", storage.JValue_readFromDirectory);
		obtain_func("objectFromPrototype", "JValue", storage.JValue_objectFromPrototype);
		obtain_func("writeToFile", "JValue", storage.JValue_writeToFile);
		obtain_func("hasPath", "JValue", storage.JValue_hasPath);
		obtain_func("solvedValueType", "JValue", storage.JValue_solvedValueType);
		obtain_func("solveFlt", "JValue", storage.JValue_solveFlt);
		obtain_func("solveInt", "JValue", storage.JValue_solveInt);
		obtain_func("solveStr", "JValue", storage.JValue_solveStr);
		obtain_func("solveObj", "JValue", storage.JValue_solveObj);
		obtain_func("solveForm", "JValue", storage.JValue_solveForm);
		obtain_func("solveFltSetter", "JValue", storage.JValue_solveFltSetter);
		obtain_func("solveIntSetter", "JValue", storage.JValue_solveIntSetter);
		obtain_func("solveStrSetter", "JValue", storage.JValue_solveStrSetter);
		obtain_func("solveObjSetter", "JValue", storage.JValue_solveObjSetter);
		obtain_func("solveFormSetter", "JValue", storage.JValue_solveFormSetter);
		obtain_func("evalLuaFlt", "JValue", storage.JValue_evalLuaFlt);
		obtain_func("evalLuaInt", "JValue", storage.JValue_evalLuaInt);
		obtain_func("evalLuaStr", "JValue", storage.JValue_evalLuaStr);
		obtain_func("evalLuaObj", "JValue", storage.JValue_evalLuaObj);
		obtain_func("evalLuaForm", "JValue", storage.JValue_evalLuaForm);

		obtain_func("object", "JArray", storage.JArray_object);
		obtain_func("objectWithSize", "JArray", storage.JArray_objectWithSize);
		obtain_func("objectWithInts", "JArray", storage.JArray_objectWithInts);
		obtain_func("objectWithStrings", "JArray", storage.JArray_objectWithStrings);
		obtain_func("objectWithFloats", "JArray", storage.JArray_objectWithFloats);
		obtain_func("objectWithBooleans", "JArray", storage.JArray_objectWithBooleans);
		obtain_func("objectWithForms", "JArray", storage.JArray_objectWithForms);
		obtain_func("subArray", "JArray", storage.JArray_subArray);
		obtain_func("addFromArray", "JArray", storage.JArray_addFromArray);
		obtain_func("addFromFormList", "JArray", storage.JArray_addFromFormList);
		obtain_func("getInt", "JArray", storage.JArray_getInt);
		obtain_func("getFlt", "JArray", storage.JArray_getFlt);
		obtain_func("getStr", "JArray", storage.JArray_getStr);
		obtain_func("getObj", "JArray", storage.JArray_getObj);
		obtain_func("getForm", "JArray", storage.JArray_getForm);
		obtain_func("findInt", "JArray", storage.JArray_findInt);
		obtain_func("findFlt", "JArray", storage.JArray_findFlt);
		obtain_func("findStr", "JArray", storage.JArray_findStr);
		obtain_func("findObj", "JArray", storage.JArray_findObj);
		obtain_func("findForm", "JArray", storage.JArray_findForm);
		obtain_func("setInt", "JArray", storage.JArray_setInt);
		obtain_func("setFlt", "JArray", storage.JArray_setFlt);
		obtain_func("setStr", "JArray", storage.JArray_setStr);
		obtain_func("setObj", "JArray", storage.JArray_setObj);
		obtain_func("setForm", "JArray", storage.JArray_setForm);
		obtain_func("addInt", "JArray", storage.JArray_addInt);
		obtain_func("addFlt", "JArray", storage.JArray_addFlt);
		obtain_func("addStr", "JArray", storage.JArray_addStr);
		obtain_func("addObj", "JArray", storage.JArray_addObj);
		obtain_func("addForm", "JArray", storage.JArray_addForm);
		obtain_func("count", "JArray", storage.JArray_count);
		obtain_func("clear", "JArray", storage.JArray_clear);
		obtain_func("eraseIndex", "JArray", storage.JArray_eraseIndex);
		obtain_func("eraseRange", "JArray", storage.JArray_eraseRange);
		obtain_func("valueType", "JArray", storage.JArray_valueType);
		obtain_func("swapItems", "JArray", storage.JArray_swapItems);
		obtain_func("sort", "JArray", storage.JArray_sort);
		obtain_func("unique", "JArray", storage.JArray_unique);
		obtain_func("writeToIntegerPArray", "JArray", storage.JArray_writeToIntegerPArray);
		obtain_func("writeToFloatPArray", "JArray", storage.JArray_writeToFloatPArray);
		obtain_func("writeToFormPArray", "JArray", storage.JArray_writeToFormPArray);
		obtain_func("writeToStringPArray", "JArray", storage.JArray_writeToStringPArray);

		obtain_func("object", "JMap", storage.JMap_object);
		obtain_func("getInt", "JMap", storage.JMap_getInt);
		obtain_func("getFlt", "JMap", storage.JMap_getFlt);
		obtain_func("getStr", "JMap", storage.JMap_getStr);
		obtain_func("getObj", "JMap", storage.JMap_getObj);
		obtain_func("getForm", "JMap", storage.JMap_getForm);
		obtain_func("setInt", "JMap", storage.JMap_setInt);
		obtain_func("setFlt", "JMap", storage.JMap_setFlt);
		obtain_func("setStr", "JMap", storage.JMap_setStr);
		obtain_func("setObj", "JMap", storage.JMap_setObj);
		obtain_func("setForm", "JMap", storage.JMap_setForm);
		obtain_func("hasKey", "JMap", storage.JMap_hasKey);
		obtain_func("valueType", "JMap", storage.JMap_valueType);
		obtain_func("allKeys", "JMap", storage.JMap_allKeys);
		obtain_func("allKeysPArray", "JMap", storage.JMap_allKeysPArray);
		obtain_func("allValues", "JMap", storage.JMap_allValues);
		obtain_func("removeKey", "JMap", storage.JMap_removeKey);
		obtain_func("count", "JMap", storage.JMap_count);
		obtain_func("clear", "JMap", storage.JMap_clear);
		obtain_func("addPairs", "JMap", storage.JMap_addPairs);
		obtain_func("nextKey", "JMap", storage.JMap_nextKey);
		obtain_func("getNthKey", "JMap", storage.JMap_getNthKey);

		return true;
	}

	void onJCAPIAvailable(const jc::root_interface* a_root)
	{
		if (!initApi(a_root)) {
			SKSE::stl::report_and_fail("JContainers initialization error, see log for details");
		}

		spdlog::info("jc api initialized");
	}

	void onPostLoad()
	{
		auto result = SKSE::GetMessagingInterface()->RegisterListener(JC_PLUGIN_NAME, [](SKSE::MessagingInterface::Message* a_msg) {
			if (a_msg && a_msg->type == jc::message_root_interface) {
				onJCAPIAvailable(jc::root_interface::from_void(a_msg->data));
			}
		});

		if (!result) {
			SKSE::stl::report_and_fail("JContainers initialization error, see log for details");
		}
	}

	void init()
	{
		SKSE::GetMessagingInterface()->RegisterListener("SKSE", [](SKSE::MessagingInterface::Message* a_msg) {
			if (a_msg && a_msg->type == SKSE::MessagingInterface::kPostLoad) {
				onPostLoad();
			}
		});
	}

	const reflection_interface* getReflectionInterface()
	{
		return detail::Storage::get().reflectionInterface;
	}

	const domain_interface* getDomainInterface()
	{
		return detail::Storage::get().domainInterface;
	}
}
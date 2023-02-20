#include <PyROL_Teuchos_Custom.hpp>
#include <Teuchos_ENull.hpp>
#include <Teuchos_FilteredIterator.hpp>
#include <Teuchos_ParameterEntry.hpp>
#include <Teuchos_ParameterEntryValidator.hpp>
#include <Teuchos_ParameterList.hpp>
#include <Teuchos_ParameterListModifier.hpp>
#include <Teuchos_PtrDecl.hpp>
#include <Teuchos_RCPDecl.hpp>
#include <Teuchos_RCPNode.hpp>
#include <Teuchos_StringIndexedOrderedValueObjectContainer.hpp>
#include <Teuchos_VerbosityLevel.hpp>
#include <Teuchos_any.hpp>
#include <Teuchos_iostream_helpers.hpp>
#include <cwchar>
#include <deque>
#include <ios>
#include <istream>
#include <iterator>
#include <locale>
#include <memory>
#include <ostream>
#include <sstream> // __str__
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>

#include <functional>
#include "PyROL_Smart_Holder.hpp"
#include <string>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>


#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// Teuchos::any::holder file:Teuchos_any.hpp line:268
struct PyCallBack_Teuchos_any_holder_bool_t : public Teuchos::any::holder<bool> {
	using Teuchos::any::holder<bool>::holder;

	const class std::type_info & type() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<bool> *>(this), "type");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<const class std::type_info &>::value) {
				static pybind11::detail::override_caster_t<const class std::type_info &> caster;
				return pybind11::detail::cast_ref<const class std::type_info &>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const class std::type_info &>(std::move(o));
		}
		return holder::type();
	}
	std::string typeName() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<bool> *>(this), "typeName");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
				static pybind11::detail::override_caster_t<std::string> caster;
				return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<std::string>(std::move(o));
		}
		return holder::typeName();
	}
	class Teuchos::any::placeholder * clone() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<bool> *>(this), "clone");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class Teuchos::any::placeholder *>::value) {
				static pybind11::detail::override_caster_t<class Teuchos::any::placeholder *> caster;
				return pybind11::detail::cast_ref<class Teuchos::any::placeholder *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class Teuchos::any::placeholder *>(std::move(o));
		}
		return holder::clone();
	}
	bool same(const class Teuchos::any::placeholder & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<bool> *>(this), "same");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return holder::same(a0);
	}
};

// Teuchos::any::holder file:Teuchos_any.hpp line:268
struct PyCallBack_Teuchos_any_holder_int_t : public Teuchos::any::holder<int> {
	using Teuchos::any::holder<int>::holder;

	const class std::type_info & type() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<int> *>(this), "type");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<const class std::type_info &>::value) {
				static pybind11::detail::override_caster_t<const class std::type_info &> caster;
				return pybind11::detail::cast_ref<const class std::type_info &>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const class std::type_info &>(std::move(o));
		}
		return holder::type();
	}
	std::string typeName() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<int> *>(this), "typeName");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
				static pybind11::detail::override_caster_t<std::string> caster;
				return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<std::string>(std::move(o));
		}
		return holder::typeName();
	}
	class Teuchos::any::placeholder * clone() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<int> *>(this), "clone");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class Teuchos::any::placeholder *>::value) {
				static pybind11::detail::override_caster_t<class Teuchos::any::placeholder *> caster;
				return pybind11::detail::cast_ref<class Teuchos::any::placeholder *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class Teuchos::any::placeholder *>(std::move(o));
		}
		return holder::clone();
	}
	bool same(const class Teuchos::any::placeholder & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<int> *>(this), "same");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return holder::same(a0);
	}
};

// Teuchos::any::holder file:Teuchos_any.hpp line:268
struct PyCallBack_Teuchos_any_holder_double_t : public Teuchos::any::holder<double> {
	using Teuchos::any::holder<double>::holder;

	const class std::type_info & type() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<double> *>(this), "type");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<const class std::type_info &>::value) {
				static pybind11::detail::override_caster_t<const class std::type_info &> caster;
				return pybind11::detail::cast_ref<const class std::type_info &>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const class std::type_info &>(std::move(o));
		}
		return holder::type();
	}
	std::string typeName() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<double> *>(this), "typeName");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
				static pybind11::detail::override_caster_t<std::string> caster;
				return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<std::string>(std::move(o));
		}
		return holder::typeName();
	}
	class Teuchos::any::placeholder * clone() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<double> *>(this), "clone");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class Teuchos::any::placeholder *>::value) {
				static pybind11::detail::override_caster_t<class Teuchos::any::placeholder *> caster;
				return pybind11::detail::cast_ref<class Teuchos::any::placeholder *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class Teuchos::any::placeholder *>(std::move(o));
		}
		return holder::clone();
	}
	bool same(const class Teuchos::any::placeholder & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<double> *>(this), "same");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return holder::same(a0);
	}
};

// Teuchos::any::holder file:Teuchos_any.hpp line:268
struct PyCallBack_Teuchos_any_holder_std_string_t : public Teuchos::any::holder<std::string> {
	using Teuchos::any::holder<std::string>::holder;

	const class std::type_info & type() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<std::string> *>(this), "type");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<const class std::type_info &>::value) {
				static pybind11::detail::override_caster_t<const class std::type_info &> caster;
				return pybind11::detail::cast_ref<const class std::type_info &>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const class std::type_info &>(std::move(o));
		}
		return holder::type();
	}
	std::string typeName() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<std::string> *>(this), "typeName");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
				static pybind11::detail::override_caster_t<std::string> caster;
				return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<std::string>(std::move(o));
		}
		return holder::typeName();
	}
	class Teuchos::any::placeholder * clone() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<std::string> *>(this), "clone");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class Teuchos::any::placeholder *>::value) {
				static pybind11::detail::override_caster_t<class Teuchos::any::placeholder *> caster;
				return pybind11::detail::cast_ref<class Teuchos::any::placeholder *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class Teuchos::any::placeholder *>(std::move(o));
		}
		return holder::clone();
	}
	bool same(const class Teuchos::any::placeholder & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<std::string> *>(this), "same");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return holder::same(a0);
	}
};

// Teuchos::any::holder file:Teuchos_any.hpp line:268
struct PyCallBack_Teuchos_any_holder_Teuchos_ParameterList_t : public Teuchos::any::holder<Teuchos::ParameterList> {
	using Teuchos::any::holder<Teuchos::ParameterList>::holder;

	const class std::type_info & type() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<Teuchos::ParameterList> *>(this), "type");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<const class std::type_info &>::value) {
				static pybind11::detail::override_caster_t<const class std::type_info &> caster;
				return pybind11::detail::cast_ref<const class std::type_info &>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const class std::type_info &>(std::move(o));
		}
		return holder::type();
	}
	std::string typeName() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<Teuchos::ParameterList> *>(this), "typeName");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<std::string>::value) {
				static pybind11::detail::override_caster_t<std::string> caster;
				return pybind11::detail::cast_ref<std::string>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<std::string>(std::move(o));
		}
		return holder::typeName();
	}
	class Teuchos::any::placeholder * clone() const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<Teuchos::ParameterList> *>(this), "clone");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<class Teuchos::any::placeholder *>::value) {
				static pybind11::detail::override_caster_t<class Teuchos::any::placeholder *> caster;
				return pybind11::detail::cast_ref<class Teuchos::any::placeholder *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<class Teuchos::any::placeholder *>(std::move(o));
		}
		return holder::clone();
	}
	bool same(const class Teuchos::any::placeholder & a0) const override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::any::holder<Teuchos::ParameterList> *>(this), "same");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<bool>::value) {
				static pybind11::detail::override_caster_t<bool> caster;
				return pybind11::detail::cast_ref<bool>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<bool>(std::move(o));
		}
		return holder::same(a0);
	}
};

// Teuchos::bad_any_cast file:Teuchos_any.hpp line:324
struct PyCallBack_Teuchos_bad_any_cast : public Teuchos::bad_any_cast {
	using Teuchos::bad_any_cast::bad_any_cast;

	const char * what() const throw() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const Teuchos::bad_any_cast *>(this), "what");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<const char *>::value) {
				static pybind11::detail::override_caster_t<const char *> caster;
				return pybind11::detail::cast_ref<const char *>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<const char *>(std::move(o));
		}
		return runtime_error::what();
	}
};

void bind_Teuchos_iostream_helpers(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// Teuchos::enumIstreamExtractor(std::istream &, enum Teuchos::EVerbosityLevel &) file:Teuchos_iostream_helpers.hpp line:58
	M("Teuchos").def("enumIstreamExtractor", (std::istream & (*)(std::istream &, enum Teuchos::EVerbosityLevel &)) &Teuchos::enumIstreamExtractor<Teuchos::EVerbosityLevel>, "C++: Teuchos::enumIstreamExtractor(std::istream &, enum Teuchos::EVerbosityLevel &) --> std::istream &", pybind11::return_value_policy::automatic, pybind11::arg("std_is"), pybind11::arg("enum_value"));

	// Teuchos::EVerbosityLevel file:Teuchos_VerbosityLevel.hpp line:62
	pybind11::enum_<Teuchos::EVerbosityLevel>(M("Teuchos"), "EVerbosityLevel", pybind11::arithmetic(), "Verbosity level.\n\n \n\n ", pybind11::module_local())
		.value("VERB_DEFAULT", Teuchos::VERB_DEFAULT)
		.value("VERB_NONE", Teuchos::VERB_NONE)
		.value("VERB_LOW", Teuchos::VERB_LOW)
		.value("VERB_MEDIUM", Teuchos::VERB_MEDIUM)
		.value("VERB_HIGH", Teuchos::VERB_HIGH)
		.value("VERB_EXTREME", Teuchos::VERB_EXTREME)
		.export_values();

;

	// Teuchos::toString(const enum Teuchos::EVerbosityLevel) file:Teuchos_VerbosityLevel.hpp line:80
	M("Teuchos").def("toString", (std::string (*)(const enum Teuchos::EVerbosityLevel)) &Teuchos::toString, "Return a std::string representation of the verbosity level.\n\n \n\n \n\nC++: Teuchos::toString(const enum Teuchos::EVerbosityLevel) --> std::string", pybind11::arg("verbLevel"));

	// Teuchos::includesVerbLevel(const enum Teuchos::EVerbosityLevel, const enum Teuchos::EVerbosityLevel, const bool) file:Teuchos_VerbosityLevel.hpp line:96
	M("Teuchos").def("includesVerbLevel", [](const enum Teuchos::EVerbosityLevel & a0, const enum Teuchos::EVerbosityLevel & a1) -> bool { return Teuchos::includesVerbLevel(a0, a1); }, "", pybind11::arg("verbLevel"), pybind11::arg("requestedVerbLevel"));
	M("Teuchos").def("includesVerbLevel", (bool (*)(const enum Teuchos::EVerbosityLevel, const enum Teuchos::EVerbosityLevel, const bool)) &Teuchos::includesVerbLevel, "Return true if the verbosity level includes the given level.\n\n \n\n           [in] The verbosity level that is in effect.\n \n\n\n           [in] The verbosity level the client is asking if\n           is included in verbLevel.\n \n\n\n           [in] Set to true if the level in\n           requestedVerbLevel is the default verbosity level.  In\n           this case, if verbLevel==VERB_DEFAULT, then this function\n           will return true.  The default value is false.\n\nC++: Teuchos::includesVerbLevel(const enum Teuchos::EVerbosityLevel, const enum Teuchos::EVerbosityLevel, const bool) --> bool", pybind11::arg("verbLevel"), pybind11::arg("requestedVerbLevel"), pybind11::arg("isDefaultLevel"));

	// Teuchos::incrVerbLevel(const enum Teuchos::EVerbosityLevel, const int) file:Teuchos_VerbosityLevel.hpp line:112
	M("Teuchos").def("incrVerbLevel", (enum Teuchos::EVerbosityLevel (*)(const enum Teuchos::EVerbosityLevel, const int)) &Teuchos::incrVerbLevel, "Return an increased or decreased verbosity level.\n\n \n\n           [in] The base verbosity level.\n \n\n\n           [in] The number of levels to increase (>0) or decrease (<0).\n\n See the function implementation for details on what it does!\n\nC++: Teuchos::incrVerbLevel(const enum Teuchos::EVerbosityLevel, const int) --> enum Teuchos::EVerbosityLevel", pybind11::arg("inputVerbLevel"), pybind11::arg("numLevels"));

	{ // Teuchos::any file:Teuchos_any.hpp line:154
		pybind11::class_<Teuchos::any, std::shared_ptr<Teuchos::any>> cl(M("Teuchos"), "any", "Modified boost::any class, which is a container for a templated\n value.", pybind11::module_local());
		cl.def( pybind11::init( [](){ return new Teuchos::any(); } ) );
		cl.def( pybind11::init( [](Teuchos::any const &o){ return new Teuchos::any(o); } ) );
		cl.def("assign", (class Teuchos::any & (Teuchos::any::*)(const class Teuchos::any &)) &Teuchos::any::operator=<Teuchos::any>, "C++: Teuchos::any::operator=(const class Teuchos::any &) --> class Teuchos::any &", pybind11::return_value_policy::automatic, pybind11::arg("rhs"));
		cl.def("swap", (class Teuchos::any & (Teuchos::any::*)(class Teuchos::any &)) &Teuchos::any::swap, "Method for swapping the contents of two any classes\n\nC++: Teuchos::any::swap(class Teuchos::any &) --> class Teuchos::any &", pybind11::return_value_policy::automatic, pybind11::arg("rhs"));
		cl.def("assign", (class Teuchos::any & (Teuchos::any::*)(const class Teuchos::any &)) &Teuchos::any::operator=, "Copy the value held in rhs\n\nC++: Teuchos::any::operator=(const class Teuchos::any &) --> class Teuchos::any &", pybind11::return_value_policy::automatic, pybind11::arg("rhs"));
		cl.def("empty", (bool (Teuchos::any::*)() const) &Teuchos::any::empty, "Return true if nothing is being stored\n\nC++: Teuchos::any::empty() const --> bool");
		cl.def("type", (const class std::type_info & (Teuchos::any::*)() const) &Teuchos::any::type, "Return the type of value being stored\n\nC++: Teuchos::any::type() const --> const class std::type_info &", pybind11::return_value_policy::automatic);
		cl.def("typeName", (std::string (Teuchos::any::*)() const) &Teuchos::any::typeName, "Return the name of the type\n\nC++: Teuchos::any::typeName() const --> std::string");
		cl.def("same", (bool (Teuchos::any::*)(const class Teuchos::any &) const) &Teuchos::any::same, "Return if two any objects are the same or not.\n  \n\n This function with throw an exception if\n           operator== can't be applied to the held type!\n\nC++: Teuchos::any::same(const class Teuchos::any &) const --> bool", pybind11::arg("other"));
		cl.def("access_content", (class Teuchos::any::placeholder * (Teuchos::any::*)()) &Teuchos::any::access_content, "C++: Teuchos::any::access_content() --> class Teuchos::any::placeholder *", pybind11::return_value_policy::automatic);

		cl.def("__str__", [](Teuchos::any const &o) -> std::string { std::ostringstream s; Teuchos::operator<<(s, o); return s.str(); } );

		{ // Teuchos::any::placeholder file:Teuchos_any.hpp line:249
			auto & enclosing_class = cl;
			pybind11::class_<Teuchos::any::placeholder, std::shared_ptr<Teuchos::any::placeholder>> cl(enclosing_class, "placeholder", ". ", pybind11::module_local());
			cl.def("type", (const class std::type_info & (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::type, ". \n\nC++: Teuchos::any::placeholder::type() const --> const class std::type_info &", pybind11::return_value_policy::automatic);
			cl.def("typeName", (std::string (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::typeName, ". \n\nC++: Teuchos::any::placeholder::typeName() const --> std::string");
			cl.def("clone", (class Teuchos::any::placeholder * (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::clone, ". \n\nC++: Teuchos::any::placeholder::clone() const --> class Teuchos::any::placeholder *", pybind11::return_value_policy::automatic);
			cl.def("same", (bool (Teuchos::any::placeholder::*)(const class Teuchos::any::placeholder &) const) &Teuchos::any::placeholder::same, ". \n\nC++: Teuchos::any::placeholder::same(const class Teuchos::any::placeholder &) const --> bool", pybind11::arg("other"));
			cl.def("assign", (class Teuchos::any::placeholder & (Teuchos::any::placeholder::*)(const class Teuchos::any::placeholder &)) &Teuchos::any::placeholder::operator=, "C++: Teuchos::any::placeholder::operator=(const class Teuchos::any::placeholder &) --> class Teuchos::any::placeholder &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		}

		{ // Teuchos::any::holder file:Teuchos_any.hpp line:268
			auto & enclosing_class = cl;
			pybind11::class_<Teuchos::any::holder<bool>, std::shared_ptr<Teuchos::any::holder<bool>>, PyCallBack_Teuchos_any_holder_bool_t, Teuchos::any::placeholder> cl(enclosing_class, "holder_bool_t", "", pybind11::module_local());
			cl.def( pybind11::init<const bool &>(), pybind11::arg("value") );

			cl.def( pybind11::init( [](PyCallBack_Teuchos_any_holder_bool_t const &o){ return new PyCallBack_Teuchos_any_holder_bool_t(o); } ) );
			cl.def( pybind11::init( [](Teuchos::any::holder<bool> const &o){ return new Teuchos::any::holder<bool>(o); } ) );
			cl.def_readwrite("held", &Teuchos::any::holder<bool>::held);
			cl.def("type", (const class std::type_info & (Teuchos::any::holder<bool>::*)() const) &Teuchos::any::holder<bool>::type, "C++: Teuchos::any::holder<bool>::type() const --> const class std::type_info &", pybind11::return_value_policy::automatic);
			cl.def("typeName", (std::string (Teuchos::any::holder<bool>::*)() const) &Teuchos::any::holder<bool>::typeName, "C++: Teuchos::any::holder<bool>::typeName() const --> std::string");
			cl.def("clone", (class Teuchos::any::placeholder * (Teuchos::any::holder<bool>::*)() const) &Teuchos::any::holder<bool>::clone, "C++: Teuchos::any::holder<bool>::clone() const --> class Teuchos::any::placeholder *", pybind11::return_value_policy::automatic);
			cl.def("same", (bool (Teuchos::any::holder<bool>::*)(const class Teuchos::any::placeholder &) const) &Teuchos::any::holder<bool>::same, "C++: Teuchos::any::holder<bool>::same(const class Teuchos::any::placeholder &) const --> bool", pybind11::arg("other"));
			cl.def("assign", (class Teuchos::any::holder<bool> & (Teuchos::any::holder<bool>::*)(const class Teuchos::any::holder<bool> &)) &Teuchos::any::holder<bool>::operator=, "C++: Teuchos::any::holder<bool>::operator=(const class Teuchos::any::holder<bool> &) --> class Teuchos::any::holder<bool> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			cl.def("type", (const class std::type_info & (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::type, ". \n\nC++: Teuchos::any::placeholder::type() const --> const class std::type_info &", pybind11::return_value_policy::automatic);
			cl.def("typeName", (std::string (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::typeName, ". \n\nC++: Teuchos::any::placeholder::typeName() const --> std::string");
			cl.def("clone", (class Teuchos::any::placeholder * (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::clone, ". \n\nC++: Teuchos::any::placeholder::clone() const --> class Teuchos::any::placeholder *", pybind11::return_value_policy::automatic);
			cl.def("same", (bool (Teuchos::any::placeholder::*)(const class Teuchos::any::placeholder &) const) &Teuchos::any::placeholder::same, ". \n\nC++: Teuchos::any::placeholder::same(const class Teuchos::any::placeholder &) const --> bool", pybind11::arg("other"));
			cl.def("assign", (class Teuchos::any::placeholder & (Teuchos::any::placeholder::*)(const class Teuchos::any::placeholder &)) &Teuchos::any::placeholder::operator=, "C++: Teuchos::any::placeholder::operator=(const class Teuchos::any::placeholder &) --> class Teuchos::any::placeholder &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		}

		{ // Teuchos::any::holder file:Teuchos_any.hpp line:268
			auto & enclosing_class = cl;
			pybind11::class_<Teuchos::any::holder<int>, std::shared_ptr<Teuchos::any::holder<int>>, PyCallBack_Teuchos_any_holder_int_t, Teuchos::any::placeholder> cl(enclosing_class, "holder_int_t", "", pybind11::module_local());
			cl.def( pybind11::init<const int &>(), pybind11::arg("value") );

			cl.def( pybind11::init( [](PyCallBack_Teuchos_any_holder_int_t const &o){ return new PyCallBack_Teuchos_any_holder_int_t(o); } ) );
			cl.def( pybind11::init( [](Teuchos::any::holder<int> const &o){ return new Teuchos::any::holder<int>(o); } ) );
			cl.def_readwrite("held", &Teuchos::any::holder<int>::held);
			cl.def("type", (const class std::type_info & (Teuchos::any::holder<int>::*)() const) &Teuchos::any::holder<int>::type, "C++: Teuchos::any::holder<int>::type() const --> const class std::type_info &", pybind11::return_value_policy::automatic);
			cl.def("typeName", (std::string (Teuchos::any::holder<int>::*)() const) &Teuchos::any::holder<int>::typeName, "C++: Teuchos::any::holder<int>::typeName() const --> std::string");
			cl.def("clone", (class Teuchos::any::placeholder * (Teuchos::any::holder<int>::*)() const) &Teuchos::any::holder<int>::clone, "C++: Teuchos::any::holder<int>::clone() const --> class Teuchos::any::placeholder *", pybind11::return_value_policy::automatic);
			cl.def("same", (bool (Teuchos::any::holder<int>::*)(const class Teuchos::any::placeholder &) const) &Teuchos::any::holder<int>::same, "C++: Teuchos::any::holder<int>::same(const class Teuchos::any::placeholder &) const --> bool", pybind11::arg("other"));
			cl.def("assign", (class Teuchos::any::holder<int> & (Teuchos::any::holder<int>::*)(const class Teuchos::any::holder<int> &)) &Teuchos::any::holder<int>::operator=, "C++: Teuchos::any::holder<int>::operator=(const class Teuchos::any::holder<int> &) --> class Teuchos::any::holder<int> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			cl.def("type", (const class std::type_info & (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::type, ". \n\nC++: Teuchos::any::placeholder::type() const --> const class std::type_info &", pybind11::return_value_policy::automatic);
			cl.def("typeName", (std::string (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::typeName, ". \n\nC++: Teuchos::any::placeholder::typeName() const --> std::string");
			cl.def("clone", (class Teuchos::any::placeholder * (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::clone, ". \n\nC++: Teuchos::any::placeholder::clone() const --> class Teuchos::any::placeholder *", pybind11::return_value_policy::automatic);
			cl.def("same", (bool (Teuchos::any::placeholder::*)(const class Teuchos::any::placeholder &) const) &Teuchos::any::placeholder::same, ". \n\nC++: Teuchos::any::placeholder::same(const class Teuchos::any::placeholder &) const --> bool", pybind11::arg("other"));
			cl.def("assign", (class Teuchos::any::placeholder & (Teuchos::any::placeholder::*)(const class Teuchos::any::placeholder &)) &Teuchos::any::placeholder::operator=, "C++: Teuchos::any::placeholder::operator=(const class Teuchos::any::placeholder &) --> class Teuchos::any::placeholder &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		}

		{ // Teuchos::any::holder file:Teuchos_any.hpp line:268
			auto & enclosing_class = cl;
			pybind11::class_<Teuchos::any::holder<double>, std::shared_ptr<Teuchos::any::holder<double>>, PyCallBack_Teuchos_any_holder_double_t, Teuchos::any::placeholder> cl(enclosing_class, "holder_double_t", "", pybind11::module_local());
			cl.def( pybind11::init<const double &>(), pybind11::arg("value") );

			cl.def( pybind11::init( [](PyCallBack_Teuchos_any_holder_double_t const &o){ return new PyCallBack_Teuchos_any_holder_double_t(o); } ) );
			cl.def( pybind11::init( [](Teuchos::any::holder<double> const &o){ return new Teuchos::any::holder<double>(o); } ) );
			cl.def_readwrite("held", &Teuchos::any::holder<double>::held);
			cl.def("type", (const class std::type_info & (Teuchos::any::holder<double>::*)() const) &Teuchos::any::holder<double>::type, "C++: Teuchos::any::holder<double>::type() const --> const class std::type_info &", pybind11::return_value_policy::automatic);
			cl.def("typeName", (std::string (Teuchos::any::holder<double>::*)() const) &Teuchos::any::holder<double>::typeName, "C++: Teuchos::any::holder<double>::typeName() const --> std::string");
			cl.def("clone", (class Teuchos::any::placeholder * (Teuchos::any::holder<double>::*)() const) &Teuchos::any::holder<double>::clone, "C++: Teuchos::any::holder<double>::clone() const --> class Teuchos::any::placeholder *", pybind11::return_value_policy::automatic);
			cl.def("same", (bool (Teuchos::any::holder<double>::*)(const class Teuchos::any::placeholder &) const) &Teuchos::any::holder<double>::same, "C++: Teuchos::any::holder<double>::same(const class Teuchos::any::placeholder &) const --> bool", pybind11::arg("other"));
			cl.def("assign", (class Teuchos::any::holder<double> & (Teuchos::any::holder<double>::*)(const class Teuchos::any::holder<double> &)) &Teuchos::any::holder<double>::operator=, "C++: Teuchos::any::holder<double>::operator=(const class Teuchos::any::holder<double> &) --> class Teuchos::any::holder<double> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			cl.def("type", (const class std::type_info & (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::type, ". \n\nC++: Teuchos::any::placeholder::type() const --> const class std::type_info &", pybind11::return_value_policy::automatic);
			cl.def("typeName", (std::string (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::typeName, ". \n\nC++: Teuchos::any::placeholder::typeName() const --> std::string");
			cl.def("clone", (class Teuchos::any::placeholder * (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::clone, ". \n\nC++: Teuchos::any::placeholder::clone() const --> class Teuchos::any::placeholder *", pybind11::return_value_policy::automatic);
			cl.def("same", (bool (Teuchos::any::placeholder::*)(const class Teuchos::any::placeholder &) const) &Teuchos::any::placeholder::same, ". \n\nC++: Teuchos::any::placeholder::same(const class Teuchos::any::placeholder &) const --> bool", pybind11::arg("other"));
			cl.def("assign", (class Teuchos::any::placeholder & (Teuchos::any::placeholder::*)(const class Teuchos::any::placeholder &)) &Teuchos::any::placeholder::operator=, "C++: Teuchos::any::placeholder::operator=(const class Teuchos::any::placeholder &) --> class Teuchos::any::placeholder &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		}

		{ // Teuchos::any::holder file:Teuchos_any.hpp line:268
			auto & enclosing_class = cl;
			pybind11::class_<Teuchos::any::holder<std::string>, std::shared_ptr<Teuchos::any::holder<std::string>>, PyCallBack_Teuchos_any_holder_std_string_t, Teuchos::any::placeholder> cl(enclosing_class, "holder_std_string_t", "", pybind11::module_local());
			cl.def( pybind11::init<const std::string &>(), pybind11::arg("value") );

			cl.def( pybind11::init( [](PyCallBack_Teuchos_any_holder_std_string_t const &o){ return new PyCallBack_Teuchos_any_holder_std_string_t(o); } ) );
			cl.def( pybind11::init( [](Teuchos::any::holder<std::string> const &o){ return new Teuchos::any::holder<std::string>(o); } ) );
			cl.def_readwrite("held", &Teuchos::any::holder<std::string>::held);
			cl.def("type", (const class std::type_info & (Teuchos::any::holder<std::string>::*)() const) &Teuchos::any::holder<std::string >::type, "C++: Teuchos::any::holder<std::string >::type() const --> const class std::type_info &", pybind11::return_value_policy::automatic);
			cl.def("typeName", (std::string (Teuchos::any::holder<std::string>::*)() const) &Teuchos::any::holder<std::string >::typeName, "C++: Teuchos::any::holder<std::string >::typeName() const --> std::string");
			cl.def("clone", (class Teuchos::any::placeholder * (Teuchos::any::holder<std::string>::*)() const) &Teuchos::any::holder<std::string >::clone, "C++: Teuchos::any::holder<std::string >::clone() const --> class Teuchos::any::placeholder *", pybind11::return_value_policy::automatic);
			cl.def("same", (bool (Teuchos::any::holder<std::string>::*)(const class Teuchos::any::placeholder &) const) &Teuchos::any::holder<std::string >::same, "C++: Teuchos::any::holder<std::string >::same(const class Teuchos::any::placeholder &) const --> bool", pybind11::arg("other"));
			cl.def("assign", (class Teuchos::any::holder<std::string > & (Teuchos::any::holder<std::string>::*)(const class Teuchos::any::holder<std::string > &)) &Teuchos::any::holder<std::string >::operator=, "C++: Teuchos::any::holder<std::string >::operator=(const class Teuchos::any::holder<std::string > &) --> class Teuchos::any::holder<std::string > &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			cl.def("type", (const class std::type_info & (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::type, ". \n\nC++: Teuchos::any::placeholder::type() const --> const class std::type_info &", pybind11::return_value_policy::automatic);
			cl.def("typeName", (std::string (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::typeName, ". \n\nC++: Teuchos::any::placeholder::typeName() const --> std::string");
			cl.def("clone", (class Teuchos::any::placeholder * (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::clone, ". \n\nC++: Teuchos::any::placeholder::clone() const --> class Teuchos::any::placeholder *", pybind11::return_value_policy::automatic);
			cl.def("same", (bool (Teuchos::any::placeholder::*)(const class Teuchos::any::placeholder &) const) &Teuchos::any::placeholder::same, ". \n\nC++: Teuchos::any::placeholder::same(const class Teuchos::any::placeholder &) const --> bool", pybind11::arg("other"));
			cl.def("assign", (class Teuchos::any::placeholder & (Teuchos::any::placeholder::*)(const class Teuchos::any::placeholder &)) &Teuchos::any::placeholder::operator=, "C++: Teuchos::any::placeholder::operator=(const class Teuchos::any::placeholder &) --> class Teuchos::any::placeholder &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		}

		{ // Teuchos::any::holder file:Teuchos_any.hpp line:268
			auto & enclosing_class = cl;
			pybind11::class_<Teuchos::any::holder<Teuchos::ParameterList>, std::shared_ptr<Teuchos::any::holder<Teuchos::ParameterList>>, PyCallBack_Teuchos_any_holder_Teuchos_ParameterList_t, Teuchos::any::placeholder> cl(enclosing_class, "holder_Teuchos_ParameterList_t", "", pybind11::module_local());
			cl.def( pybind11::init<const class Teuchos::ParameterList &>(), pybind11::arg("value") );

			cl.def( pybind11::init( [](PyCallBack_Teuchos_any_holder_Teuchos_ParameterList_t const &o){ return new PyCallBack_Teuchos_any_holder_Teuchos_ParameterList_t(o); } ) );
			cl.def( pybind11::init( [](Teuchos::any::holder<Teuchos::ParameterList> const &o){ return new Teuchos::any::holder<Teuchos::ParameterList>(o); } ) );
			cl.def_readwrite("held", &Teuchos::any::holder<Teuchos::ParameterList>::held);
			cl.def("type", (const class std::type_info & (Teuchos::any::holder<Teuchos::ParameterList>::*)() const) &Teuchos::any::holder<Teuchos::ParameterList>::type, "C++: Teuchos::any::holder<Teuchos::ParameterList>::type() const --> const class std::type_info &", pybind11::return_value_policy::automatic);
			cl.def("typeName", (std::string (Teuchos::any::holder<Teuchos::ParameterList>::*)() const) &Teuchos::any::holder<Teuchos::ParameterList>::typeName, "C++: Teuchos::any::holder<Teuchos::ParameterList>::typeName() const --> std::string");
			cl.def("clone", (class Teuchos::any::placeholder * (Teuchos::any::holder<Teuchos::ParameterList>::*)() const) &Teuchos::any::holder<Teuchos::ParameterList>::clone, "C++: Teuchos::any::holder<Teuchos::ParameterList>::clone() const --> class Teuchos::any::placeholder *", pybind11::return_value_policy::automatic);
			cl.def("same", (bool (Teuchos::any::holder<Teuchos::ParameterList>::*)(const class Teuchos::any::placeholder &) const) &Teuchos::any::holder<Teuchos::ParameterList>::same, "C++: Teuchos::any::holder<Teuchos::ParameterList>::same(const class Teuchos::any::placeholder &) const --> bool", pybind11::arg("other"));
			cl.def("assign", (class Teuchos::any::holder<class Teuchos::ParameterList> & (Teuchos::any::holder<Teuchos::ParameterList>::*)(const class Teuchos::any::holder<class Teuchos::ParameterList> &)) &Teuchos::any::holder<Teuchos::ParameterList>::operator=, "C++: Teuchos::any::holder<Teuchos::ParameterList>::operator=(const class Teuchos::any::holder<class Teuchos::ParameterList> &) --> class Teuchos::any::holder<class Teuchos::ParameterList> &", pybind11::return_value_policy::automatic, pybind11::arg(""));
			cl.def("type", (const class std::type_info & (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::type, ". \n\nC++: Teuchos::any::placeholder::type() const --> const class std::type_info &", pybind11::return_value_policy::automatic);
			cl.def("typeName", (std::string (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::typeName, ". \n\nC++: Teuchos::any::placeholder::typeName() const --> std::string");
			cl.def("clone", (class Teuchos::any::placeholder * (Teuchos::any::placeholder::*)() const) &Teuchos::any::placeholder::clone, ". \n\nC++: Teuchos::any::placeholder::clone() const --> class Teuchos::any::placeholder *", pybind11::return_value_policy::automatic);
			cl.def("same", (bool (Teuchos::any::placeholder::*)(const class Teuchos::any::placeholder &) const) &Teuchos::any::placeholder::same, ". \n\nC++: Teuchos::any::placeholder::same(const class Teuchos::any::placeholder &) const --> bool", pybind11::arg("other"));
			cl.def("assign", (class Teuchos::any::placeholder & (Teuchos::any::placeholder::*)(const class Teuchos::any::placeholder &)) &Teuchos::any::placeholder::operator=, "C++: Teuchos::any::placeholder::operator=(const class Teuchos::any::placeholder &) --> class Teuchos::any::placeholder &", pybind11::return_value_policy::automatic, pybind11::arg(""));
		}

	}
	{ // Teuchos::bad_any_cast file:Teuchos_any.hpp line:324
		pybind11::class_<Teuchos::bad_any_cast, std::shared_ptr<Teuchos::bad_any_cast>, PyCallBack_Teuchos_bad_any_cast, std::runtime_error> cl(M("Teuchos"), "bad_any_cast", "Thrown if any_cast is attempted between two incompatable types.", pybind11::module_local());
		cl.def( pybind11::init<const std::string>(), pybind11::arg("msg") );

		cl.def( pybind11::init( [](PyCallBack_Teuchos_bad_any_cast const &o){ return new PyCallBack_Teuchos_bad_any_cast(o); } ) );
		cl.def( pybind11::init( [](Teuchos::bad_any_cast const &o){ return new Teuchos::bad_any_cast(o); } ) );
		cl.def("assign", (class Teuchos::bad_any_cast & (Teuchos::bad_any_cast::*)(const class Teuchos::bad_any_cast &)) &Teuchos::bad_any_cast::operator=, "C++: Teuchos::bad_any_cast::operator=(const class Teuchos::bad_any_cast &) --> class Teuchos::bad_any_cast &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	// Teuchos::any_cast(class Teuchos::any &) file:Teuchos_any.hpp line:339
	M("Teuchos").def("any_cast", (bool & (*)(class Teuchos::any &)) &Teuchos::any_cast<bool>, "C++: Teuchos::any_cast(class Teuchos::any &) --> bool &", pybind11::return_value_policy::automatic, pybind11::arg("operand"));

	// Teuchos::any_cast(class Teuchos::any &) file:Teuchos_any.hpp line:339
	M("Teuchos").def("any_cast", (int & (*)(class Teuchos::any &)) &Teuchos::any_cast<int>, "C++: Teuchos::any_cast(class Teuchos::any &) --> int &", pybind11::return_value_policy::automatic, pybind11::arg("operand"));

	// Teuchos::any_cast(class Teuchos::any &) file:Teuchos_any.hpp line:339
	M("Teuchos").def("any_cast", (double & (*)(class Teuchos::any &)) &Teuchos::any_cast<double>, "C++: Teuchos::any_cast(class Teuchos::any &) --> double &", pybind11::return_value_policy::automatic, pybind11::arg("operand"));

	// Teuchos::any_cast(class Teuchos::any &) file:Teuchos_any.hpp line:339
	M("Teuchos").def("any_cast", (std::string & (*)(class Teuchos::any &)) &Teuchos::any_cast<std::string>, "C++: Teuchos::any_cast(class Teuchos::any &) --> std::string &", pybind11::return_value_policy::automatic, pybind11::arg("operand"));

	// Teuchos::any_cast(class Teuchos::any &) file:Teuchos_any.hpp line:339
	M("Teuchos").def("any_cast", (class Teuchos::ParameterList & (*)(class Teuchos::any &)) &Teuchos::any_cast<Teuchos::ParameterList>, "C++: Teuchos::any_cast(class Teuchos::any &) --> class Teuchos::ParameterList &", pybind11::return_value_policy::automatic, pybind11::arg("operand"));

	// Teuchos::any_cast(const class Teuchos::any &) file:Teuchos_any.hpp line:375
	M("Teuchos").def("any_cast", (const bool & (*)(const class Teuchos::any &)) &Teuchos::any_cast<bool>, "C++: Teuchos::any_cast(const class Teuchos::any &) --> const bool &", pybind11::return_value_policy::automatic, pybind11::arg("operand"));

	// Teuchos::any_cast(const class Teuchos::any &) file:Teuchos_any.hpp line:375
	M("Teuchos").def("any_cast", (const int & (*)(const class Teuchos::any &)) &Teuchos::any_cast<int>, "C++: Teuchos::any_cast(const class Teuchos::any &) --> const int &", pybind11::return_value_policy::automatic, pybind11::arg("operand"));

	// Teuchos::any_cast(const class Teuchos::any &) file:Teuchos_any.hpp line:375
	M("Teuchos").def("any_cast", (const double & (*)(const class Teuchos::any &)) &Teuchos::any_cast<double>, "C++: Teuchos::any_cast(const class Teuchos::any &) --> const double &", pybind11::return_value_policy::automatic, pybind11::arg("operand"));

	// Teuchos::any_cast(const class Teuchos::any &) file:Teuchos_any.hpp line:375
	M("Teuchos").def("any_cast", (const std::string & (*)(const class Teuchos::any &)) &Teuchos::any_cast<std::string>, "C++: Teuchos::any_cast(const class Teuchos::any &) --> const std::string &", pybind11::return_value_policy::automatic, pybind11::arg("operand"));

	// Teuchos::any_cast(const class Teuchos::any &) file:Teuchos_any.hpp line:375
	M("Teuchos").def("any_cast", (const class Teuchos::ParameterList & (*)(const class Teuchos::any &)) &Teuchos::any_cast<Teuchos::ParameterList>, "C++: Teuchos::any_cast(const class Teuchos::any &) --> const class Teuchos::ParameterList &", pybind11::return_value_policy::automatic, pybind11::arg("operand"));

	// Teuchos::toString(const class Teuchos::any &) file:Teuchos_any.hpp line:398
	M("Teuchos").def("toString", (std::string (*)(const class Teuchos::any &)) &Teuchos::toString, "Converts the value in any to a std::string.\n    \n\n This function with throw an exception if\n             the held type can't be printed via operator<< !\n\nC++: Teuchos::toString(const class Teuchos::any &) --> std::string", pybind11::arg("rhs"));

	// Teuchos::swap(class Teuchos::any &, class Teuchos::any &) file:Teuchos_any.hpp line:439
	M("Teuchos").def("swap", (void (*)(class Teuchos::any &, class Teuchos::any &)) &Teuchos::swap, "Special swap for other code to find via Argument Dependent Lookup\n\nC++: Teuchos::swap(class Teuchos::any &, class Teuchos::any &) --> void", pybind11::arg("a"), pybind11::arg("b"));

}

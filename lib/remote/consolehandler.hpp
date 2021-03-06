/* Icinga 2 | (c) 2012 Icinga GmbH | GPLv2+ */

#ifndef CONSOLEHANDLER_H
#define CONSOLEHANDLER_H

#include "remote/httphandler.hpp"
#include "base/scriptframe.hpp"

namespace icinga
{

struct ApiScriptFrame
{
	double Seen{0};
	int NextLine{1};
	std::map<String, String> Lines;
	Dictionary::Ptr Locals;
};

class ConsoleHandler final : public HttpHandler
{
public:
	DECLARE_PTR_TYPEDEFS(ConsoleHandler);

	bool HandleRequest(const ApiUser::Ptr& user, HttpRequest& request,
		HttpResponse& response, const Dictionary::Ptr& params) override;

	static std::vector<String> GetAutocompletionSuggestions(const String& word, ScriptFrame& frame);

private:
	static bool ExecuteScriptHelper(HttpRequest& request, HttpResponse& response,
		const Dictionary::Ptr& params, const String& command, const String& session, bool sandboxed);
	static bool AutocompleteScriptHelper(HttpRequest& request, HttpResponse& response,
		const Dictionary::Ptr& params, const String& command, const String& session, bool sandboxed);

};

}

#endif /* CONSOLEHANDLER_H */

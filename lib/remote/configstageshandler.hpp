/* Icinga 2 | (c) 2012 Icinga GmbH | GPLv2+ */

#ifndef CONFIGSTAGESHANDLER_H
#define CONFIGSTAGESHANDLER_H

#include "remote/httphandler.hpp"

namespace icinga
{

class ConfigStagesHandler final : public HttpHandler
{
public:
	DECLARE_PTR_TYPEDEFS(ConfigStagesHandler);

	bool HandleRequest(const ApiUser::Ptr& user, HttpRequest& request,
		HttpResponse& response, const Dictionary::Ptr& params) override;

private:
	void HandleGet(const ApiUser::Ptr& user, HttpRequest& request,
		HttpResponse& response, const Dictionary::Ptr& params);
	void HandlePost(const ApiUser::Ptr& user, HttpRequest& request,
		HttpResponse& response, const Dictionary::Ptr& params);
	void HandleDelete(const ApiUser::Ptr& user, HttpRequest& request,
		HttpResponse& response, const Dictionary::Ptr& params);

};

}

#endif /* CONFIGSTAGESHANDLER_H */

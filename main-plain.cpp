// Example usage of plain-text http server. Look at the examples directory for more examples
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "HTTPAcceptor.hpp"
#include "HTTPBasicAuthHandler.hpp"
#include "HTTPConstants.hpp"
#include "HTTPMessage.hpp"
#include <nlohmann/json.hpp>

std::unique_ptr<HTTP::HTTPMessage> call_back(std::unique_ptr<HTTP::HTTPMessage> HTTPClientMessage, HTTP::BasicAuth::BasicAuthHandler* auth_handler=nullptr){
	try{
		using json = nlohmann::json;
		auto parsed_json = json::parse(HTTPClientMessage->GetRawBody());
		int int_value = parsed_json["value_one"];
		std::string string_value = parsed_json["value_two"];
		std::string returner = "value_one: " + std::to_string(int_value) + " value_two: " + string_value;
		std::unique_ptr<HTTP::HTTPMessage> HTTPResponseMessage = std::make_unique<HTTP::HTTPMessage>();
		HTTPResponseMessage->SetHTTPVersion("HTTP/1.1");
		HTTPResponseMessage->SetResponseCode(HTTP::HTTPConst::HTTP_RESPONSE_CODE::CREATED);
		HTTPResponseMessage->AddHeader("Content-Type", "text/plain");
		HTTPResponseMessage->AddHeader("Content-Length", std::to_string(returner.size()));
		HTTPResponseMessage->SetRawBody(std::move(returner));
		return HTTPResponseMessage;
	}catch(const std::exception& e){
		std::cout << "Invalid request from user-agent\n";
		std::unique_ptr<HTTP::HTTPMessage> HTTPResponseMessage = std::make_unique<HTTP::HTTPMessage>();
		std::string returner = "Invalid request body, rejected by origin-server";
		HTTPResponseMessage->SetHTTPVersion("HTTP/1.1");
		HTTPResponseMessage->SetResponseType("Bad Request");
		HTTPResponseMessage->SetResponseCode(HTTP::HTTPConst::HTTP_RESPONSE_CODE::BAD_REQUEST);
		HTTPResponseMessage->AddHeader("Content-Type", "text/plain");
		HTTPResponseMessage->AddHeader("Content-Length", std::to_string(returner.size()));
		HTTPResponseMessage->SetRawBody(std::move(returner));
		return HTTPResponseMessage;
	}
}

std::unique_ptr<HTTP::HTTPMessage> auth_call_back(std::unique_ptr<HTTP::HTTPMessage> HTTPClientMessage, HTTP::BasicAuth::BasicAuthHandler* auth_handler=nullptr){
	try{
		using json = nlohmann::json;
		auto parsed_json = json::parse(HTTPClientMessage->GetRawBody());
		int int_value = parsed_json["value_one"];
		std::string string_value = parsed_json["value_two"];
		std::string returner = "value_one: " + std::to_string(int_value) + " value_two: " + string_value;
		std::unique_ptr<HTTP::HTTPMessage> HTTPResponseMessage = std::make_unique<HTTP::HTTPMessage>();
		HTTPResponseMessage->SetHTTPVersion("HTTP/1.1");
		HTTPResponseMessage->SetResponseCode(HTTP::HTTPConst::HTTP_RESPONSE_CODE::CREATED);
		HTTPResponseMessage->AddHeader("Content-Type", "text/plain");
		HTTPResponseMessage->AddHeader("Content-Length", std::to_string(returner.size()));
		HTTPResponseMessage->SetRawBody(std::move(returner));
		return HTTPResponseMessage;
	}catch(const std::exception& e){
		std::cout << "Invalid request from user-agent\n";
		std::unique_ptr<HTTP::HTTPMessage> HTTPResponseMessage = std::make_unique<HTTP::HTTPMessage>();
		std::string returner = "Invalid request body, rejected by origin-server";
		HTTPResponseMessage->SetHTTPVersion("HTTP/1.1");
		HTTPResponseMessage->SetResponseType("Bad Request");
		HTTPResponseMessage->SetResponseCode(HTTP::HTTPConst::HTTP_RESPONSE_CODE::BAD_REQUEST);
		HTTPResponseMessage->AddHeader("Content-Type", "text/plain");
		HTTPResponseMessage->AddHeader("Content-Length", std::to_string(returner.size()));
		HTTPResponseMessage->SetRawBody(std::move(returner));
		return HTTPResponseMessage;
	}
}

int main(int argc, const char* argv[]){

	std::vector<HTTP::HTTPHandler::HTTPPostEndpoint> post_endpoint = { {"/poster","application/json", call_back} };

	std::unique_ptr<HTTP::HTTPAcceptor::HTTPAcceptor> http_acceptor = std::make_unique<HTTP::HTTPAcceptor::HTTPAcceptorPlainText>();
	http_acceptor->HTTPStreamSock(
			"127.0.0.1", // IPv4 addr
			9876, // bind port
			10,  // backlog
			HTTP::HTTPConst::HTTP_SERVER_TYPE::PLAINTEXT_SERVER,  // server type (Plaintext/SSL)
			"./configs/html_src", // HTML src-root (or your own path)
			post_endpoint // json endpoint and callback fn
			// "./cert.pem",
			// "./key.pem"
			);
	http_acceptor->HTTPStreamAccept();

	return 0;
}

#ifndef _FORMATTER_
#define _FORMATTER_

#include <string>
#include <memory>

namespace loglady {
namespace formatter {

class Formatter {
public:
    virtual ~Formatter() {}

    /**
     * @brief Interface for the formatters.
     *        A formatter will mutate how a message is logged, and which
     *        informations will be displayed. 
     * 
     * @param param_message Raw message
     * @return void Formated string
     */
    virtual void Format(std::string& param_message) const = 0;
};

class DefaultFormatter : public Formatter {
public:
    /**
     * @brief Base formatter
     *        Does not mutate the message by itself 
     * 
     * @param param_message Raw message
     * @return void Formated string
     */
    void Format(std::string& param_message) const override {}
};

void FormatterAdapter(std::shared_ptr<Formatter> param_formatter, std::string& param_message);

} // namespace formatter
} // namespace loglady

#endif // _FORMATTER_
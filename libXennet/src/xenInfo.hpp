#ifndef XENINFO_HPP
#define XENINFO_HPP

#include "xenMain.hpp"

namespace Xennet
{

    class Info
    {
    public:
        /** Default constructor */
        Info();
        /** Default destructor */
        virtual ~Info();

        std::string getVersion();
        std::string getDescription();
        std::string getCopyright();
    protected:
    private:
    };

} // namespace Xennet

#endif // XENINFO_HPP

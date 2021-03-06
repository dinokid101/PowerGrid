#include "facade.h"
#include "skillinfo.h"
#include "varpbits.h"


namespace RS {

IMPL_JACE_CONSTRUCTORS(Facade)
IMPL_RSCLASS_GET(Facade)

IMPL_ARRAY_METHOD(Facade, getSkills, SkillInfo)
IMPL_OBJECT_METHOD(Facade, getVarpbits, Varpbits)

} // namespace bridge

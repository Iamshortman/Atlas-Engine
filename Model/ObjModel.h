#include <string>
#include "Model.h"

class ObjModel : public Model
{
	public:
		ObjModel(std::string FileName);
		virtual void Render();

};
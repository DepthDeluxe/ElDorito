#include "ModuleForge.hpp"
#include "../Patches/Forge.hpp"

namespace
{
	bool CommandDeleteAll(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		Patches::Forge::DeleteAll();
		return true;
	}

	bool CommandCanvas(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		Patches::Forge::CanvasMap();
		return true;
	}
}

namespace Modules
{
	ModuleForge::ModuleForge() : ModuleBase("Forge")
	{
		VarCloneDepth = AddVariableFloat("CloneDepth", "clone_depth", "Depth at which the object will be cloned", eCommandFlagsNone, 1.0f);
		VarCloneMultiplier = AddVariableInt("CloneMultiplier", "clone_multiplier", "Number of consecutive times the object will be cloned", eCommandFlagsNone, 1);
		VarRotationSnap = AddVariableFloat("RotationSnap", "rotation_snap", "Angle in degrees at which object rotation will be snapped", eCommandFlagsNone, 0);
		VarRotationSensitivity = AddVariableFloat("RotationSensitivity", "rotation_sensitivity", "Controls the sensitivity of object rotation", eCommandFlagsArchived, 1.0f);
		VarMonitorSpeed = AddVariableFloat("MonitorSpeed", "monitor_speed", "Controls the movement speed of the monitor", eCommandFlagsArchived, 1.0f);

		AddCommand("DeleteAll", "delete_all", "Delete all objects that are the same as the object under the crosshair", eCommandFlagsHostOnly, CommandDeleteAll);
		AddCommand("Canvas", "canvas", "Delete all objects on the map", eCommandFlagsHostOnly, CommandCanvas);
	}
}
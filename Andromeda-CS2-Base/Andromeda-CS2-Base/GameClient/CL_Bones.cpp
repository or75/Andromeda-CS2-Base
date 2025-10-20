#include "CL_Bones.hpp"

#include <CS2/SDK/Types/CEntityData.hpp>

static CL_Bones g_CL_Bones{};

std::vector<std::string> g_AllTraceVisibleCheckBones =
{
	"head_0",
	"pelvis",
	"arm_lower_r",
	"arm_lower_l",
	"ankle_r",
	"ankle_l",
};

auto CL_Bones::GetBonePositionByName( C_CSPlayerPawn* pC_CSPlayerPawn , const char* szBoneName ) -> Vector3
{
	Vector3 BonePosition;

	if ( auto* pSkeletonInstance = pC_CSPlayerPawn->m_pGameSceneNode()->GetSkeletonInstance(); pSkeletonInstance )
	{
		pSkeletonInstance->CalcWorldSpaceBones( FLAG_ALL_BONE_FLAGS );

		const auto& Model = pSkeletonInstance->m_modelState().m_hModel();

		if ( !Model.is_valid() )
			return BonePosition;

		const auto BoneIndex = pC_CSPlayerPawn->GetBoneIdByName( szBoneName );

		if ( BoneIndex != -1 && pSkeletonInstance->GetBonePosition( BoneIndex , BonePosition ) )
			return BonePosition;
		else
			DEV_LOG( "[error] GetBoneIdByName: %s\n" , szBoneName );
	}

	return BonePosition;
}

auto GetCL_Bones() -> CL_Bones*
{
	return &g_CL_Bones;
}

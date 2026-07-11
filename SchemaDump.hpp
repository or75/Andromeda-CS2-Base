class CWorldCompositionChunkReferenceElement_t // server
{
	CUtlString m_strMapToLoad; // 0x0000
	CUtlString m_strLandmarkName; // 0x0008
};
class C_INIT_PositionWarpScalar : public CParticleFunctionInitializer // particles
{
	Vector m_vecWarpMin; // 0x01E0
	Vector m_vecWarpMax; // 0x01EC
	CPerParticleFloatInput m_InputValue; // 0x01F8
	float32 m_flPrevPosScale; // 0x0368
	int32 m_nScaleControlPointNumber; // 0x036C
	int32 m_nControlPointNumber; // 0x0370
};
class C_OP_ForceControlPointStub : public CParticleFunctionPreEmission // particles
{
	int32 m_ControlPoint; // 0x01E0
};
class RenderProjectedMaterial_t // particles
{
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hMaterial; // 0x0000
};
class AimMatrixOpFixedSettings_t // animgraphlib
{
	CAnimAttachment m_attachment; // 0x0000
	CAnimInputDamping m_damping; // 0x0080
	CPoseHandle[10] m_poseCacheHandles; // 0x0098
	AimMatrixBlendMode m_eBlendMode; // 0x00C0
	float32 m_flMaxYawAngle; // 0x00C4
	float32 m_flMaxPitchAngle; // 0x00C8
	int32 m_nSequenceMaxFrame; // 0x00CC
	int32 m_nBoneMaskIndex; // 0x00D0
	bool m_bTargetIsPosition; // 0x00D4
	bool m_bUseBiasAndClamp; // 0x00D5
	float32 m_flBiasAndClampYawOffset; // 0x00D8
	float32 m_flBiasAndClampPitchOffset; // 0x00DC
	CBlendCurve m_biasAndClampBlendCurve; // 0x00E0
};
class InfoForResourceTypeCVoxelVisibility // resourcesystem
{
};
class WrappedPhysicsJoint_t // server
{
	IPhysicsJoint* m_pJoint; // 0x0000
};
class SoundCommand_t // server
{
	float32 m_time; // 0x0008
	float32 m_deltaTime; // 0x000C
	soundcommands_t m_command; // 0x0010
	float32 m_value; // 0x0014
};
class CTakeDamageResult // server
{
	CTakeDamageInfo* m_pOriginatingInfo; // 0x0000
	CUtlLeanVector< DestructiblePartDamageRequest_t > m_DestructibleHitGroupRequests; // 0x0008
	int32 m_nHealthLost; // 0x0018
	int32 m_nHealthBefore; // 0x001C
	float32 m_flDamageDealt; // 0x0020
	float32 m_flPreModifiedDamage; // 0x0024
	VectorWS m_vDamagePosition; // 0x0028
	int32 m_nTotalledHealthLost; // 0x0034
	float32 m_flTotalledDamageDealt; // 0x0038
	float32 m_flTotalledPreModifiedDamage; // 0x003C
	float32 m_flNewDamageAccumulatorValue; // 0x0040
	TakeDamageFlags_t m_nDamageFlags; // 0x0048
	bool m_bWasDamageSuppressed; // 0x0050
	bool m_bSuppressFlinch; // 0x0051
	HitGroup_t m_nOverrideFlinchHitGroup; // 0x0054
};
class C_OP_RenderMaterialProxy : public CParticleFunctionRenderer // particles
{
	int32 m_nMaterialControlPoint; // 0x0228
	MaterialProxyType_t m_nProxyType; // 0x022C
	CUtlVector< MaterialVariable_t > m_MaterialVars; // 0x0230
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hOverrideMaterial; // 0x0248
	CParticleCollectionFloatInput m_flMaterialOverrideEnabled; // 0x0250
	CParticleCollectionVecInput m_vecColorScale; // 0x03C0
	CPerParticleFloatInput m_flAlpha; // 0x0A78
	ParticleColorBlendType_t m_nColorBlendType; // 0x0BE8
};
class CNmFloatEaseNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	float32 m_flEaseTime; // 0x0010
	float32 m_flStartValue; // 0x0014
	int16 m_nInputValueNodeIdx; // 0x0018
	NmEasingOperation_t m_easingOp; // 0x001A
	bool m_bUseStartValue; // 0x001B
};
class CAimMatrixUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	AimMatrixOpFixedSettings_t m_opFixedSettings; // 0x0070
	AnimVectorSource m_target; // 0x0168
	CAnimParamHandle m_paramIndex; // 0x016C
	HSequence m_hSequence; // 0x0170
	bool m_bResetChild; // 0x0174
	bool m_bLockWhenWaning; // 0x0175
};
class CAnimFrameBlockAnim // animationsystem
{
	int32 m_nStartFrame; // 0x0000
	int32 m_nEndFrame; // 0x0004
	CUtlVector< int32 > m_segmentIndexArray; // 0x0008
};
class CSeqPoseSetting // animationsystem
{
	CBufferString m_sPoseParameter; // 0x0000
	CBufferString m_sAttachment; // 0x0010
	CBufferString m_sReferenceSequence; // 0x0020
	float32 m_flValue; // 0x0030
	bool m_bX; // 0x0034
	bool m_bY; // 0x0035
	bool m_bZ; // 0x0036
	int32 m_eType; // 0x0038
};
class CNmCachedFloatNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	NmCachedValueMode_t m_mode; // 0x0014
};
class CRagdollComponentUpdater : public CAnimComponentUpdater // animgraphlib
{
	CUtlVector< CAnimNodePath > m_ragdollNodePaths; // 0x0030
	CUtlVector< CAnimNodePath > m_followAttachmentNodePaths; // 0x0048
	CUtlVector< int32 > m_boneIndices; // 0x0060
	CUtlVector< CUtlString > m_boneNames; // 0x0078
	CUtlVector< WeightList > m_weightLists; // 0x0090
	CUtlVector< int32 > m_boneToWeightIndices; // 0x00A8
	float32 m_flSpringFrequencyMin; // 0x00C0
	float32 m_flSpringFrequencyMax; // 0x00C4
	float32 m_flMaxStretch; // 0x00C8
	bool m_bSolidCollisionAtZeroWeight; // 0x00CC
};
class CNmRootMotionEvent : public CNmEvent // animlib
{
	float32 m_flBlendTimeSeconds; // 0x0018
};
class CTwistConstraint : public CBaseConstraint // modellib
{
	bool m_bInverse; // 0x0060
	Quaternion m_qParentBindRotation; // 0x0070
	Quaternion m_qChildBindRotation; // 0x0080
};
class MotionBlendItem // animgraphlib
{
	CSmartPtr< CMotionNode > m_pChild; // 0x0000
	float32 m_flKeyValue; // 0x0008
};
class C_OP_EndCapDecay : public CParticleFunctionOperator // particles
{
};
class VMixPresetDSPDesc_t // soundsystem_lowlevel
{
	CUtlString m_effectName; // 0x0000
};
class CNmFloatChannelData // animlib
{
	CStrongHandle< InfoForResourceTypeCNmSkeleton > m_skeleton; // 0x0000
	CGlobalSymbol m_setID; // 0x0008
	CUtlVector< CNmFloatChannelData::ChannelSettings_t > m_channelSettings; // 0x0010
	CUtlVector< uint16 > m_compressedData; // 0x0028
	CUtlVector< uint32 > m_compressedOffsets; // 0x0040
};
class CTurnHelperUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	AnimValueSource m_facingTarget; // 0x0074
	float32 m_turnStartTimeOffset; // 0x0078
	float32 m_turnDuration; // 0x007C
	bool m_bMatchChildDuration; // 0x0080
	float32 m_manualTurnOffset; // 0x0084
	bool m_bUseManualTurnOffset; // 0x0088
};
class CNmParameterizedBlendNode::BlendRange_t // animlib
{
	int16 m_nInputIdx0; // 0x0000
	int16 m_nInputIdx1; // 0x0002
	Range_t m_parameterValueRange; // 0x0004
};
class CDecalInstance // server
{
	CGlobalSymbol m_sDecalGroup; // 0x0000
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hMaterial; // 0x0008
	CUtlStringToken m_sSequenceName; // 0x0010
	CHandle< CBaseEntity > m_hEntity; // 0x0014
	int32 m_nBoneIndex; // 0x0018
	int32 m_nTriangleIndex; // 0x001C
	Vector m_vPositionLS; // 0x0020
	Vector m_vPositionOS; // 0x002C
	Vector m_vNormalLS; // 0x0038
	Vector m_vNormalOS; // 0x0044
	Vector m_vSAxisLS; // 0x0050
	DecalFlags_t m_nFlags; // 0x005C
	Color m_Color; // 0x0060
	float32 m_flWidth; // 0x0064
	float32 m_flHeight; // 0x0068
	float32 m_flDepth; // 0x006C
	CTransformWS m_transform; // 0x0070
	float32 m_flAnimationScale; // 0x0090
	float32 m_flAnimationStartTime; // 0x0094
	GameTime_t m_flPlaceTime; // 0x0098
	float32 m_flFadeStartTime; // 0x009C
	float32 m_flFadeDuration; // 0x00A0
	float32 m_flLightingOriginOffset; // 0x00A4
	float32 m_flBoundingRadiusSqr; // 0x00B0
	int16 m_nSequenceIndex; // 0x00B4
	bool m_bIsAdjacent; // 0x00B6
	bool m_bDoDecalLightmapping; // 0x00B7
};
class CBaseAnimGraphDestructibleParts_GraphController : public CAnimGraphControllerBase // server
{
};
class C_INIT_RandomColor : public CParticleFunctionInitializer // particles
{
	Color m_ColorMin; // 0x01FC
	Color m_ColorMax; // 0x0200
	Color m_TintMin; // 0x0204
	Color m_TintMax; // 0x0208
	float32 m_flTintPerc; // 0x020C
	float32 m_flUpdateThreshold; // 0x0210
	int32 m_nTintCP; // 0x0214
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0218
	ParticleColorBlendMode_t m_nTintBlendMode; // 0x021C
	float32 m_flLightAmplification; // 0x0220
};
class SteamAudioPathSettings_t // steamaudio
{
	int32 m_nNumVisSamples; // 0x0000
	float32 m_flProbeVisRadius; // 0x0004
	float32 m_flProbeVisThreshold; // 0x0008
	float32 m_flProbePathRange; // 0x000C
};
class CNmVirtualParameterFloatNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	int16 m_nChildNodeIdx; // 0x0010
};
class CNmTargetInfoNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	CNmTargetInfoNode::Info_t m_infoType; // 0x0014
	bool m_bIsWorldSpaceTarget; // 0x0018
};
class CSpinUpdateBase : public CParticleFunctionOperator // particles
{
};
class C_OP_PositionLock : public CParticleFunctionOperator // particles
{
	CParticleTransformInput m_TransformInput; // 0x01D8
	float32 m_flStartTime_min; // 0x0240
	float32 m_flStartTime_max; // 0x0244
	float32 m_flStartTime_exp; // 0x0248
	float32 m_flEndTime_min; // 0x024C
	float32 m_flEndTime_max; // 0x0250
	float32 m_flEndTime_exp; // 0x0254
	float32 m_flRange; // 0x0258
	CParticleCollectionFloatInput m_flRangeBias; // 0x0260
	float32 m_flJumpThreshold; // 0x03D0
	float32 m_flPrevPosScale; // 0x03D4
	bool m_bLockRot; // 0x03D8
	CParticleCollectionVecInput m_vecScale; // 0x03E0
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0A98
	ParticleAttributeIndex_t m_nFieldOutputPrev; // 0x0A9C
};
class CAnimParameterBase // animgraphlib
{
	CGlobalSymbol m_name; // 0x0018
	CUtlString m_sComment; // 0x0020
	CUtlString m_group; // 0x0028
	AnimParamID m_id; // 0x0030
	CUtlString m_componentName; // 0x0048
	bool m_bNetworkingRequested; // 0x0068
	bool m_bIsReferenced; // 0x0069
};
class CTimeRemainingMetricEvaluator : public CMotionMetricEvaluator // animgraphlib
{
	bool m_bMatchByTimeRemaining; // 0x0050
	float32 m_flMaxTimeRemaining; // 0x0054
	bool m_bFilterByTimeRemaining; // 0x0058
	float32 m_flMinTimeRemaining; // 0x005C
};
class GAME_HEADER // server
{
	CUtlString m_sComment; // 0x0000
	int32 m_nSpawnGroupCount; // 0x0008
	CUtlString m_sLandmark; // 0x0010
	CUtlString m_sRequiredAddons; // 0x0018
};
class CGameScriptedMoveDef_t // server
{
	Vector m_vDestOffset; // 0x0000
	CHandle< CBaseEntity > m_hDestEntity; // 0x000C
	QAngle m_angDest; // 0x0010
	float32 m_flDuration; // 0x001C
	float32 m_flAngRate; // 0x0020
	float32 m_flMoveSpeed; // 0x0024
	bool m_bAimDisabled; // 0x0028
	bool m_bIgnoreRotation; // 0x0029
	ForcedCrouchState_t m_nForcedCrouchState; // 0x002C
};
class CBtNodeDecorator : public CBtNode // server
{
};
class dynpitchvol_t : public dynpitchvol_base_t // server
{
};
class C_INIT_PositionWarp : public CParticleFunctionInitializer // particles
{
	CParticleCollectionVecInput m_vecWarpMin; // 0x01E0
	CParticleCollectionVecInput m_vecWarpMax; // 0x0898
	int32 m_nScaleControlPointNumber; // 0x0F50
	int32 m_nControlPointNumber; // 0x0F54
	int32 m_nRadiusComponent; // 0x0F58
	float32 m_flWarpTime; // 0x0F5C
	float32 m_flWarpStartTime; // 0x0F60
	float32 m_flPrevPosScale; // 0x0F64
	bool m_bInvertWarp; // 0x0F68
	bool m_bUseCount; // 0x0F69
};
class CTargetSelectorUpdateNode : public CAnimUpdateNodeBase // animgraphlib
{
	TargetSelectorAngleMode_t m_eAngleMode; // 0x0060
	CUtlVector< CAnimUpdateNodeRef > m_children; // 0x0068
	CAnimParamHandle m_hTargetPosition; // 0x0084
	CAnimParamHandle m_hTargetFacePositionParameter; // 0x0086
	CAnimParamHandle m_hMoveHeadingParameter; // 0x0088
	CAnimParamHandle m_hDesiredMoveHeadingParameter; // 0x008A
	bool m_bTargetPositionIsWorldSpace; // 0x008C
	bool m_bTargetFacePositionIsWorldSpace; // 0x008D
	bool m_bEnablePhaseMatching; // 0x008E
	float32 m_flPhaseMatchingMaxRootMotionSkip; // 0x0090
};
class InfoForResourceTypeCModel // resourcesystem
{
};
class C_OP_RemapAverageScalarValuetoCP : public CParticleFunctionPreEmission // particles
{
	SetStatisticExpressionType_t m_nExpression; // 0x01E0
	CParticleCollectionFloatInput m_flDecimalPlaces; // 0x01E8
	int32 m_nOutControlPointNumber; // 0x0358
	int32 m_nOutVectorField; // 0x035C
	ParticleAttributeIndex_t m_nField; // 0x0360
	CParticleRemapFloatInput m_flOutputRemap; // 0x0368
};
class C_OP_SetPerChildControlPoint : public CParticleFunctionOperator // particles
{
	int32 m_nChildGroupID; // 0x01D8
	int32 m_nFirstControlPoint; // 0x01DC
	int32 m_nNumControlPoints; // 0x01E0
	CParticleCollectionFloatInput m_nParticleIncrement; // 0x01E8
	CParticleCollectionFloatInput m_nFirstSourcePoint; // 0x0358
	bool m_bSetOrientation; // 0x04C8
	ParticleAttributeIndex_t m_nOrientationField; // 0x04CC
	bool m_bNumBasedOnParticleCount; // 0x04D0
};
class CSosSoundEventGroupSchema // soundsystem
{
	SosGroupType_t m_nGroupType; // 0x0008
	bool m_bBlocksEvents; // 0x000C
	int32 m_nBlockMaxCount; // 0x0010
	float32 m_flMemberLifespanTime; // 0x0014
	bool m_bInvertMatch; // 0x0018
	SosGroupFieldBehavior_t m_Behavior_EventName; // 0x001C
	CUtlString m_matchSoundEventName; // 0x0020
	bool m_bMatchEventSubString; // 0x0028
	CUtlString m_matchSoundEventSubString; // 0x0030
	SosGroupFieldBehavior_t m_Behavior_EntIndex; // 0x0038
	float32 m_flEntIndex; // 0x003C
	SosGroupFieldBehavior_t m_Behavior_Opvar; // 0x0040
	float32 m_flOpvar; // 0x0044
	SosGroupFieldBehavior_t m_Behavior_String; // 0x0048
	CUtlString m_opvarString; // 0x0050
	CUtlVector< CSosGroupActionSchema* > m_vActions; // 0x0058
};
class FeTwistConstraint_t // physicslib
{
	uint16 nNodeOrient; // 0x0000
	uint16 nNodeEnd; // 0x0002
	float32 flTwistRelax; // 0x0004
	float32 flSwingRelax; // 0x0008
};
class CNmSyncTrack::EventMarker_t // animlib
{
	NmPercent_t m_startTime; // 0x0000
	CGlobalSymbol m_ID; // 0x0008
};
class CNmConstVectorNode::CDefinition : public CNmVectorValueNode::CDefinition // animlib
{
	Vector m_value; // 0x0010
};
class CAnimationGraphVisualizerSphere : public CAnimationGraphVisualizerPrimitiveBase // animgraphlib
{
	VectorAligned m_vWsPosition; // 0x0040
	float32 m_flRadius; // 0x0050
	Color m_Color; // 0x0054
};
class CBoneConstraintRbf : public CBoneConstraintBase // modellib
{
	CUtlVector< std::pair< CUtlString, uint32 > > m_inputBones; // 0x0020
	CUtlVector< std::pair< CUtlString, uint32 > > m_outputBones; // 0x0038
};
class VelocitySampler // server
{
	Vector m_prevSample; // 0x0000
	GameTime_t m_fPrevSampleTime; // 0x000C
	float32 m_fIdealSampleRate; // 0x0010
};
class C_OP_RenderScreenShake : public CParticleFunctionRenderer // particles
{
	float32 m_flDurationScale; // 0x0228
	float32 m_flRadiusScale; // 0x022C
	float32 m_flFrequencyScale; // 0x0230
	float32 m_flAmplitudeScale; // 0x0234
	ParticleAttributeIndex_t m_nRadiusField; // 0x0238
	ParticleAttributeIndex_t m_nDurationField; // 0x023C
	ParticleAttributeIndex_t m_nFrequencyField; // 0x0240
	ParticleAttributeIndex_t m_nAmplitudeField; // 0x0244
	int32 m_nFilterCP; // 0x0248
};
class CVoiceContainerVsndTrigger : public CVoiceContainerBase // soundsystem_voicecontainers
{
	CUtlString m_namespace; // 0x0070
	CVsndTriggerSlot m_slot1; // 0x0078
	CVsndTriggerSlot m_slot2; // 0x0100
	CVsndTriggerSlot m_slot3; // 0x0188
	CVsndTriggerSlot m_slot4; // 0x0210
	CVsndTriggerSlot m_slot5; // 0x0298
	CVsndTriggerSlot m_slot6; // 0x0320
	CVsndTriggerSlot m_slot7; // 0x03A8
	CVsndTriggerSlot m_slot8; // 0x0430
	CVsndTriggerSlot m_slot9; // 0x04B8
	CVsndTriggerSlot m_slot10; // 0x0540
	CVsndTriggerSlot m_slot11; // 0x05C8
	CVsndTriggerSlot m_slot12; // 0x0650
	CVsndTriggerSlot m_slot13; // 0x06D8
	CVsndTriggerSlot m_slot14; // 0x0760
	CVsndTriggerSlot m_slot15; // 0x07E8
	CVsndTriggerSlot m_slot16; // 0x0870
};
class CAnimNodePath // animgraphlib
{
	AnimNodeID[11] m_path; // 0x0000
	int32 m_nCount; // 0x002C
};
class CNmSkeleton // animlib
{
	CGlobalSymbol m_ID; // 0x0000
	CUtlLeanVector< CGlobalSymbol > m_boneIDs; // 0x0008
	CUtlVector< int32 > m_parentIndices; // 0x0018
	CUtlVector< CTransform > m_parentSpaceReferencePose; // 0x0030
	CUtlVector< CTransform > m_modelSpaceReferencePose; // 0x0048
	int32 m_numBonesToSampleAtLowLOD; // 0x0060
	CUtlLeanVector< NmBoneMaskSetDefinition_t > m_maskDefinitions; // 0x0088
	CUtlLeanVector< CNmSkeleton::SecondarySkeleton_t > m_secondarySkeletons; // 0x00A8
	CUtlLeanVector< CNmFloatChannelSet_t > m_floatChannelSets; // 0x00B8
	bool m_bIsPropSkeleton; // 0x00C8
};
class CModelConfigElement_SetMaterialGroup : public CModelConfigElement // modellib
{
	CUtlString m_MaterialGroupName; // 0x0048
};
class CPhysicsBodyGameMarkup // server
{
	CUtlString m_TargetBody; // 0x0000
	CGlobalSymbol m_Tag; // 0x0008
};
class C_OP_ContinuousEmitter : public CParticleFunctionEmitter // particles
{
	CParticleCollectionFloatInput m_flEmissionDuration; // 0x01E0
	CParticleCollectionFloatInput m_flStartTime; // 0x0350
	CParticleCollectionFloatInput m_flEmitRate; // 0x04C0
	float32 m_flEmissionScale; // 0x0630
	float32 m_flScalePerParentParticle; // 0x0634
	bool m_bInitFromKilledParentParticles; // 0x0638
	EventTypeSelection_t m_nEventType; // 0x063C
	int32 m_nSnapshotControlPoint; // 0x0640
	CUtlString m_strSnapshotSubset; // 0x0648
	int32 m_nLimitPerUpdate; // 0x0650
	bool m_bForceEmitOnFirstUpdate; // 0x0654
	bool m_bForceEmitOnLastUpdate; // 0x0655
};
class constraint_breakableparams_t // vphysics2
{
	float32 strength; // 0x0000
	float32 forceLimit; // 0x0004
	float32 torqueLimit; // 0x0008
	float32[2] bodyMassScale; // 0x000C
	bool isActive; // 0x0014
};
class CModelConfigElement_RandomColor : public CModelConfigElement // modellib
{
	CColorGradient m_Gradient; // 0x0048
};
class CNmCachedPoseWriteTask : public CNmPoseTask // animlib
{
};
class InfoForResourceTypeCPostProcessingResource // resourcesystem
{
};
class RelationshipOverride_t : public Relationship_t // server
{
	CHandle< CBaseEntity > entity; // 0x0008
	Class_T classType; // 0x000C
};
class ParticleAttributeIndex_t // particles
{
	int32 m_Value; // 0x0000
};
class CVoiceContainerMultiBlender : public CVoiceContainerBase // soundsystem_voicecontainers
{
	CSoundContainerReferenceArray m_soundsToPlay; // 0x0070
	float32 m_flBlendFactor; // 0x00A8
	float32 m_flCrossover; // 0x00AC
};
class FeBuildSDFRigid_t : public FeSDFRigid_t // physicslib
{
	int32 m_nPriority; // 0x0050
	uint32 m_nVertexMapHash; // 0x0054
	uint32 m_nAntitunnelGroupBits; // 0x0058
};
class IAnimationGraphInstance // animgraphlib
{
};
class AI_GroundRootMotionMotor_DebugSnapshotData_t : public DebugSnapshotBaseStructuredData_t // server
{
	CGlobalSymbol desired_movement_gait_set; // 0x0008
	CGlobalSymbol desired_movement_gait; // 0x0010
	CGlobalSymbol current_movement_gait_set; // 0x0018
	CGlobalSymbol current_movement_gait; // 0x0020
	CGlobalSymbol movement_setting_id; // 0x0028
	CGlobalSymbol gait_switch_blocked_reason; // 0x0030
	bool b_goal_completion_allowed; // 0x0038
	CGlobalSymbol state; // 0x0040
	int32 n_state_active_tick_count; // 0x0048
	bool b_has_path; // 0x004C
	float32 f_remaining_ground_path_length; // 0x0050
	float32 f_current_speed; // 0x0054
	CGlobalSymbol move_type; // 0x0058
	float32 f_forward_strafing_angle_actual; // 0x0060
	float32 f_forward_strafing_angle_desired; // 0x0064
	float32 f_current_lean; // 0x0068
	float32 f_target_lean; // 0x006C
	CUtlVector< AI_GroundRootMotionMotor_DebugSnapshotData_t::Event_t > vec_events; // 0x0070
};
class CSndBeatTrack // soundsystem
{
	CUtlString m_name; // 0x0000
	SndBeatTrackPlaybackType_t m_playbackType; // 0x0020
	int32 m_nTranspose; // 0x0024
	bool m_bSyncToVoice; // 0x0028
	float32 m_flBPM; // 0x002C
};
class CSoundContainerReferenceArray // soundsystem_voicecontainers
{
	bool m_bUseReference; // 0x0000
	CUtlVector< CStrongHandle< InfoForResourceTypeCVoiceContainerBase > > m_sounds; // 0x0008
	CUtlVector< CVoiceContainerBase* > m_pSounds; // 0x0020
};
class VPhysXAggregateData_t // modellib
{
	uint16 m_nFlags; // 0x0000
	uint16 m_nRefCounter; // 0x0002
	CUtlVector< uint32 > m_bonesHash; // 0x0008
	CUtlVector< CUtlString > m_boneNames; // 0x0020
	CUtlVector< uint16 > m_indexNames; // 0x0038
	CUtlVector< uint16 > m_indexHash; // 0x0050
	CUtlVector< matrix3x4a_t > m_bindPose; // 0x0068
	CUtlVector< VPhysXBodyPart_t > m_parts; // 0x0080
	CUtlVector< PhysShapeMarkup_t > m_shapeMarkups; // 0x0098
	CUtlVector< VPhysXConstraint2_t > m_constraints2; // 0x00B0
	CUtlVector< VPhysXJoint_t > m_joints; // 0x00C8
	PhysFeModelDesc_t* m_pFeModel; // 0x00E0
	CUtlVector< uint16 > m_boneParents; // 0x00E8
	CUtlVector< uint32 > m_surfacePropertyHashes; // 0x0100
	CUtlVector< VPhysXCollisionAttributes_t > m_collisionAttributes; // 0x0118
	CUtlVector< CUtlString > m_debugPartNames; // 0x0130
	CUtlString m_embeddedKeyvalues; // 0x0148
};
class CSolveIKChainUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	CUtlVector< CSolveIKTargetHandle_t > m_targetHandles; // 0x0070
	SolveIKChainPoseOpFixedSettings_t m_opFixedData; // 0x0088
};
class DebugSnapshotBaseStructuredData_t // server
{
};
class CNavVolumeCalculatedVector : public CNavVolume // server
{
};
class C_INIT_InitialSequenceFromModel : public CParticleFunctionInitializer // particles
{
	int32 m_nControlPointNumber; // 0x01E0
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E4
	ParticleAttributeIndex_t m_nFieldOutputAnim; // 0x01E8
	float32 m_flInputMin; // 0x01EC
	float32 m_flInputMax; // 0x01F0
	float32 m_flOutputMin; // 0x01F4
	float32 m_flOutputMax; // 0x01F8
	ParticleSetMethod_t m_nSetMethod; // 0x01FC
};
class C_OP_FadeInSimple : public CParticleFunctionOperator // particles
{
	float32 m_flFadeInTime; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
};
class C_INIT_OffsetVectorToVector : public CParticleFunctionInitializer // particles
{
	ParticleAttributeIndex_t m_nFieldInput; // 0x01E0
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E4
	Vector m_vecOutputMin; // 0x01E8
	Vector m_vecOutputMax; // 0x01F4
	CRandomNumberGeneratorParameters m_randomnessParameters; // 0x0200
};
class C_OP_ModelCull : public CParticleFunctionOperator // particles
{
	int32 m_nControlPointNumber; // 0x01D8
	bool m_bBoundBox; // 0x01DC
	bool m_bCullOutside; // 0x01DD
	bool m_bUseBones; // 0x01DE
	char[128] m_HitboxSetName; // 0x01DF
};
class C_OP_FadeAndKillForTracers : public CParticleFunctionOperator // particles
{
	float32 m_flStartFadeInTime; // 0x01D8
	float32 m_flEndFadeInTime; // 0x01DC
	float32 m_flStartFadeOutTime; // 0x01E0
	float32 m_flEndFadeOutTime; // 0x01E4
	float32 m_flStartAlpha; // 0x01E8
	float32 m_flEndAlpha; // 0x01EC
};
class RnSoftbodyCapsule_t // physicslib
{
	Vector[2] m_vCenter; // 0x0000
	float32 m_flRadius; // 0x0018
	uint16[2] m_nParticle; // 0x001C
};
class EventClientProcessGameInput_t // engine2
{
	EngineLoopState_t m_LoopState; // 0x0000
	float32 m_flRealTime; // 0x0028
	float32 m_flFrameTime; // 0x002C
};
class InfoForResourceTypeManifestTestResource_t // resourcesystem
{
};
class C_OP_CollideWithParentParticles : public CParticleFunctionConstraint // particles
{
	CPerParticleFloatInput m_flParentRadiusScale; // 0x01D8
	CPerParticleFloatInput m_flRadiusScale; // 0x0348
};
class C_OP_LerpToInitialPosition : public CParticleFunctionOperator // particles
{
	int32 m_nControlPointNumber; // 0x01D8
	CPerParticleFloatInput m_flInterpolation; // 0x01E0
	ParticleAttributeIndex_t m_nCacheField; // 0x0350
	CParticleCollectionFloatInput m_flScale; // 0x0358
	CParticleCollectionVecInput m_vecScale; // 0x04C8
};
class VMixConvolutionDesc_t // soundsystem_lowlevel
{
	float32 m_fldbGain; // 0x0000
	float32 m_flPreDelayMS; // 0x0004
	float32 m_flWetMix; // 0x0008
	float32 m_fldbLow; // 0x000C
	float32 m_fldbMid; // 0x0010
	float32 m_fldbHigh; // 0x0014
	float32 m_flLowCutoffFreq; // 0x0018
	float32 m_flHighCutoffFreq; // 0x001C
};
class CVMixSubgraphSwitchProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixSubgraphSwitchDesc_t m_desc; // 0x0020
};
class CFeJiggleBone // physicslib
{
	uint32 m_nFlags; // 0x0000
	float32 m_flLength; // 0x0004
	float32 m_flTipMass; // 0x0008
	float32 m_flYawStiffness; // 0x000C
	float32 m_flYawDamping; // 0x0010
	float32 m_flPitchStiffness; // 0x0014
	float32 m_flPitchDamping; // 0x0018
	float32 m_flAlongStiffness; // 0x001C
	float32 m_flAlongDamping; // 0x0020
	float32 m_flAngleLimit; // 0x0024
	float32 m_flMinYaw; // 0x0028
	float32 m_flMaxYaw; // 0x002C
	float32 m_flYawFriction; // 0x0030
	float32 m_flYawBounce; // 0x0034
	float32 m_flMinPitch; // 0x0038
	float32 m_flMaxPitch; // 0x003C
	float32 m_flPitchFriction; // 0x0040
	float32 m_flPitchBounce; // 0x0044
	float32 m_flBaseMass; // 0x0048
	float32 m_flBaseStiffness; // 0x004C
	float32 m_flBaseDamping; // 0x0050
	float32 m_flBaseMinLeft; // 0x0054
	float32 m_flBaseMaxLeft; // 0x0058
	float32 m_flBaseLeftFriction; // 0x005C
	float32 m_flBaseMinUp; // 0x0060
	float32 m_flBaseMaxUp; // 0x0064
	float32 m_flBaseUpFriction; // 0x0068
	float32 m_flBaseMinForward; // 0x006C
	float32 m_flBaseMaxForward; // 0x0070
	float32 m_flBaseForwardFriction; // 0x0074
	float32 m_flRadius0; // 0x0078
	float32 m_flRadius1; // 0x007C
	Vector m_vPoint0; // 0x0080
	Vector m_vPoint1; // 0x008C
	uint16 m_nCollisionMask; // 0x0098
};
class AnimComponentID // modellib
{
	uint32 m_id; // 0x0000
};
class CFootDefinition // modellib
{
	CUtlString m_name; // 0x0000
	CUtlString m_ankleBoneName; // 0x0008
	CUtlString m_toeBoneName; // 0x0010
	Vector m_vBallOffset; // 0x0018
	Vector m_vHeelOffset; // 0x0024
	float32 m_flFootLength; // 0x0030
	float32 m_flBindPoseDirectionMS; // 0x0034
	float32 m_flTraceHeight; // 0x0038
	float32 m_flTraceRadius; // 0x003C
};
class CSubtractUpdateNode : public CBinaryUpdateNode // animgraphlib
{
	BinaryNodeChildOption m_footMotionTiming; // 0x0094
	bool m_bApplyToFootMotion; // 0x0098
	bool m_bApplyChannelsSeparately; // 0x0099
	bool m_bUseModelSpace; // 0x009A
};
class CMotionNodeBlend1D : public CMotionNode // animgraphlib
{
	CUtlVector< MotionBlendItem > m_blendItems; // 0x0028
	int32 m_nParamIndex; // 0x0040
};
class CNavVolumeSphericalShell : public CNavVolumeSphere // navlib
{
	float32 m_flRadiusInner; // 0x0088
};
class PulseScriptedSequenceData_t // server
{
	int32 m_nActorID; // 0x0000
	CUtlString m_szPreIdleSequence; // 0x0008
	CUtlString m_szEntrySequence; // 0x0010
	CUtlString m_szSequence; // 0x0018
	CUtlString m_szExitSequence; // 0x0020
	ScriptedMoveTo_t m_nMoveTo; // 0x0028
	SharedMovementGait_t m_nMoveToGait; // 0x002C
	ScriptedHeldWeaponBehavior_t m_nHeldWeaponBehavior; // 0x0030
	bool m_bLoopPreIdleSequence; // 0x0034
	bool m_bLoopActionSequence; // 0x0035
	bool m_bLoopPostIdleSequence; // 0x0036
	bool m_bIgnoreLookAt; // 0x0037
};
class C_OP_NormalizeVector : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	float32 m_flScale; // 0x01DC
};
class C_OP_RenderClothForce : public CParticleFunctionRenderer // particles
{
};
class SteamAudioCustomDataOcclusionSettings_t // steamaudio
{
	bool m_bEnablePathing; // 0x0000
	bool m_bEnableReflections; // 0x0001
	int32 m_nReflectionRays; // 0x0004
	int32 m_nReflectionBounces; // 0x0008
};
class VMixBoxverbDesc_t // soundsystem_lowlevel
{
	float32 m_flSizeMax; // 0x0000
	float32 m_flSizeMin; // 0x0004
	float32 m_flComplexity; // 0x0008
	float32 m_flDiffusion; // 0x000C
	float32 m_flModDepth; // 0x0010
	float32 m_flModRate; // 0x0014
	bool m_bParallel; // 0x0018
	VMixFilterDesc_t m_filterType; // 0x001C
	float32 m_flWidth; // 0x002C
	float32 m_flHeight; // 0x0030
	float32 m_flDepth; // 0x0034
	float32 m_flFeedbackScale; // 0x0038
	float32 m_flFeedbackWidth; // 0x003C
	float32 m_flFeedbackHeight; // 0x0040
	float32 m_flFeedbackDepth; // 0x0044
	float32 m_flOutputGain; // 0x0048
	float32 m_flTaps; // 0x004C
};
class FeCtrlOffset_t // physicslib
{
	Vector vOffset; // 0x0000
	uint16 nCtrlParent; // 0x000C
	uint16 nCtrlChild; // 0x000E
};
class InfoForResourceTypeCAnimData // resourcesystem
{
};
class CNavHullPresetVData // navlib
{
	CUtlVector< CUtlString > m_vecNavHulls; // 0x0000
};
class CNavVolume // navlib
{
};
class CAnimGraphControllerBase // server
{
	ExternalAnimGraphHandle_t m_hExternalGraph; // 0x0010
};
class C_OP_RemapScalarEndCap : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldInput; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
	float32 m_flInputMin; // 0x01E0
	float32 m_flInputMax; // 0x01E4
	float32 m_flOutputMin; // 0x01E8
	float32 m_flOutputMax; // 0x01EC
};
class CSoundContainerReference // soundsystem_voicecontainers
{
	CUtlString m_namespace; // 0x0000
	bool m_bUseReference; // 0x0008
	CStrongHandle< InfoForResourceTypeCVoiceContainerBase > m_sound; // 0x0010
	CVoiceContainerBase* m_pSound; // 0x0018
};
class CNmReferencePoseNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
};
class CAnimKeyData // animationsystem
{
	CBufferString m_name; // 0x0000
	CUtlVector< CAnimBone > m_boneArray; // 0x0010
	CUtlVector< CAnimUser > m_userArray; // 0x0028
	CUtlVector< CBufferString > m_morphArray; // 0x0040
	int32 m_nChannelElements; // 0x0058
	CUtlVector< CAnimDataChannelDesc > m_dataChannelArray; // 0x0060
};
class MaterialParam_t // materialsystem2
{
	CUtlString m_name; // 0x0000
};
class CDestructiblePart // server
{
	CGlobalSymbol m_DebugName; // 0x0000
	HitGroup_t m_nHitGroup; // 0x0008
	bool m_bDisableHitGroupWhenDestroyed; // 0x000C
	CUtlVector< HitGroup_t > m_nOtherHitgroupsToDestroyWhenFullyDestructed; // 0x0010
	bool m_bOnlyDestroyWhenGibbing; // 0x0028
	CGlobalSymbol m_sBodyGroupName; // 0x0030
	CUtlVector< CDestructiblePart_DamageLevel > m_DamageLevels; // 0x0038
};
class CNmEventConsumer // server
{
};
class levellist_t // server
{
	CUtlString m_sMapName; // 0x0000
	CUtlString m_sLandmarkName; // 0x0008
	CEntityHandle m_hEntLandmark; // 0x0010
	VectorWS m_vecLandmarkOrigin; // 0x0014
	QAngle m_vecLandmarkAngles; // 0x0020
};
class C_OP_RepeatedTriggerChildGroup : public CParticleFunctionPreEmission // particles
{
	int32 m_nChildGroupID; // 0x01E0
	CParticleCollectionFloatInput m_flClusterRefireTime; // 0x01E8
	CParticleCollectionFloatInput m_flClusterSize; // 0x0358
	CParticleCollectionFloatInput m_flClusterCooldown; // 0x04C8
	bool m_bLimitChildCount; // 0x0638
};
class C_OP_TurbulenceForce : public CParticleFunctionForce // particles
{
	float32 m_flNoiseCoordScale0; // 0x01E8
	float32 m_flNoiseCoordScale1; // 0x01EC
	float32 m_flNoiseCoordScale2; // 0x01F0
	float32 m_flNoiseCoordScale3; // 0x01F4
	Vector m_vecNoiseAmount0; // 0x01F8
	Vector m_vecNoiseAmount1; // 0x0204
	Vector m_vecNoiseAmount2; // 0x0210
	Vector m_vecNoiseAmount3; // 0x021C
};
class SequenceWeightedList_t // particles
{
	int32 m_nSequence; // 0x0000
	float32 m_flRelativeWeight; // 0x0004
};
class C_OP_RemapParticleCountToScalar : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	CParticleCollectionFloatInput m_nInputMin; // 0x01E0
	CParticleCollectionFloatInput m_nInputMax; // 0x0350
	CParticleCollectionFloatInput m_flOutputMin; // 0x04C0
	CParticleCollectionFloatInput m_flOutputMax; // 0x0630
	bool m_bActiveRange; // 0x07A0
	ParticleSetMethod_t m_nSetMethod; // 0x07A4
};
class constraint_hingeparams_t // vphysics2
{
	VectorWS worldPosition; // 0x0000
	Vector worldAxisDirection; // 0x000C
	constraint_axislimit_t hingeAxis; // 0x0018
	constraint_breakableparams_t constraint; // 0x0028
};
class CChoiceUpdateNode : public CAnimUpdateNodeBase // animgraphlib
{
	CUtlVector< CAnimUpdateNodeRef > m_children; // 0x0060
	CUtlVector< float32 > m_weights; // 0x0078
	CUtlVector< float32 > m_blendTimes; // 0x0090
	ChoiceMethod m_choiceMethod; // 0x00A8
	ChoiceChangeMethod m_choiceChangeMethod; // 0x00AC
	ChoiceBlendMethod m_blendMethod; // 0x00B0
	float32 m_blendTime; // 0x00B4
	bool m_bCrossFade; // 0x00B8
	bool m_bResetChosen; // 0x00B9
	bool m_bDontResetSameSelection; // 0x00BA
};
class CBoneConstraintPoseSpaceBone : public CBaseConstraint // modellib
{
	CUtlVector< CBoneConstraintPoseSpaceBone::Input_t > m_inputList; // 0x0060
};
class inv_image_light_fill_t // client
{
	Vector color; // 0x0000
	QAngle angle; // 0x000C
	float32 brightness; // 0x0018
};
class C_INIT_RingWave : public CParticleFunctionInitializer // particles
{
	CParticleTransformInput m_TransformInput; // 0x01E0
	CParticleCollectionFloatInput m_flParticlesPerOrbit; // 0x0248
	CPerParticleFloatInput m_flInitialRadius; // 0x03B8
	CPerParticleFloatInput m_flThickness; // 0x0528
	CPerParticleFloatInput m_flInitialSpeedMin; // 0x0698
	CPerParticleFloatInput m_flInitialSpeedMax; // 0x0808
	CPerParticleFloatInput m_flRoll; // 0x0978
	CPerParticleFloatInput m_flPitch; // 0x0AE8
	CPerParticleFloatInput m_flYaw; // 0x0C58
	bool m_bEvenDistribution; // 0x0DC8
	bool m_bXYVelocityOnly; // 0x0DC9
};
class C_OP_BoxConstraint : public CParticleFunctionConstraint // particles
{
	CParticleCollectionVecInput m_vecMin; // 0x01D8
	CParticleCollectionVecInput m_vecMax; // 0x0890
	int32 m_nCP; // 0x0F48
	bool m_bLocalSpace; // 0x0F4C
	bool m_bAccountForRadius; // 0x0F4D
};
class CSSDSMsg_ViewTargetList // scenesystem
{
	SceneViewId_t m_viewId; // 0x0000
	CUtlString m_ViewName; // 0x0010
	CUtlVector< CSSDSMsg_ViewTarget > m_Targets; // 0x0018
};
class MaterialParamBuffer_t : public MaterialParam_t // materialsystem2
{
	CUtlBinaryBlock m_value; // 0x0008
};
class InfoForResourceTypeCAnimationGroup // resourcesystem
{
};
class C_OP_LockToSavedSequentialPathV2 : public CParticleFunctionOperator // particles
{
	float32 m_flFadeStart; // 0x01D8
	float32 m_flFadeEnd; // 0x01DC
	bool m_bCPPairs; // 0x01E0
	CPathParameters m_PathParams; // 0x01F0
};
class C_OP_DistanceBetweenVecs : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	CPerParticleVecInput m_vecPoint1; // 0x01E0
	CPerParticleVecInput m_vecPoint2; // 0x0898
	CPerParticleFloatInput m_flInputMin; // 0x0F50
	CPerParticleFloatInput m_flInputMax; // 0x10C0
	CPerParticleFloatInput m_flOutputMin; // 0x1230
	CPerParticleFloatInput m_flOutputMax; // 0x13A0
	ParticleSetMethod_t m_nSetMethod; // 0x1510
	bool m_bDeltaTime; // 0x1514
};
class CMaterialDrawDescriptor // modellib
{
	float32 m_flUvDensity; // 0x0000
	Vector m_vTintColor; // 0x0004
	float32 m_flAlpha; // 0x0010
	uint16 m_nNumMeshlets; // 0x0016
	uint32 m_nFirstMeshlet; // 0x001C
	uint32 m_nAppliedIndexOffset; // 0x0020
	uint8 m_nDepthVertexBufferIndex; // 0x0024
	uint8 m_nMeshletPackedIVBIndex; // 0x0025
	CUtlLeanVector< CMaterialDrawDescriptor::RigidMeshPart_t > m_rigidMeshParts; // 0x0028
	CUtlLeanVector< uint16 > m_rootBvhNodes; // 0x0038
	RenderPrimitiveType_t m_nPrimitiveType; // 0x0048
	int32 m_nBaseVertex; // 0x004C
	int32 m_nVertexCount; // 0x0050
	int32 m_nStartIndex; // 0x0054
	int32 m_nIndexCount; // 0x0058
	CRenderBufferBinding m_indexBuffer; // 0x00C0
	CRenderBufferBinding m_meshletPackedIVB; // 0x00E0
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_material; // 0x0110
};
class CDecalGroupVData // server
{
	CUtlVector< DecalGroupOption_t > m_vecOptions; // 0x0000
	float32 m_flTotalProbability; // 0x0018
};
class CNmEventConsumerParticle : public CNmEventConsumer // server
{
};
class PostProcessingTonemapParameters_t // materialsystem2
{
	float32 m_flExposureBias; // 0x0000
	float32 m_flShoulderStrength; // 0x0004
	float32 m_flLinearStrength; // 0x0008
	float32 m_flLinearAngle; // 0x000C
	float32 m_flToeStrength; // 0x0010
	float32 m_flToeNum; // 0x0014
	float32 m_flToeDenom; // 0x0018
	float32 m_flWhitePoint; // 0x001C
	float32 m_flLuminanceSource; // 0x0020
	float32 m_flExposureBiasShadows; // 0x0024
	float32 m_flExposureBiasHighlights; // 0x0028
	float32 m_flMinShadowLum; // 0x002C
	float32 m_flMaxShadowLum; // 0x0030
	float32 m_flMinHighlightLum; // 0x0034
	float32 m_flMaxHighlightLum; // 0x0038
};
class CSAdditionalPerRoundStats_t // server
{
	int32 m_numChickensKilled; // 0x0000
	int32 m_killsWhileBlind; // 0x0004
	int32 m_bombCarrierkills; // 0x0008
	float32 m_flBurnDamageInflicted; // 0x000C
	float32 m_flBlastDamageInflicted; // 0x0010
	int32 m_iDinks; // 0x0014
	bool m_bFreshStartThisRound; // 0x0018
	bool m_bBombPlantedAndAlive; // 0x0019
	int32 m_nDefuseStarts; // 0x001C
	int32 m_nHostagePickUps; // 0x0020
	int32 m_numTeammatesFlashed; // 0x0024
	CUtlString m_strAnnotationsWorkshopId; // 0x0028
};
class FeAxialEdgeBend_t // physicslib
{
	float32 te; // 0x0000
	float32 tv; // 0x0004
	float32 flDist; // 0x0008
	float32[4] flWeight; // 0x000C
	uint16[6] nNode; // 0x001C
};
class CAnimBoneDifference // animationsystem
{
	CBufferString m_name; // 0x0000
	CBufferString m_parent; // 0x0010
	Vector m_posError; // 0x0020
	bool m_bHasRotation; // 0x002C
	bool m_bHasMovement; // 0x002D
};
class CJiggleBoneUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	JiggleBoneSettingsList_t m_opFixedData; // 0x0070
};
class CNmSampleTask : public CNmPoseTask // animlib
{
};
class IParticleEffect // particleslib
{
};
class CPerParticleFloatInput : public CParticleFloatInput // particleslib
{
};
class CAnimData // animationsystem
{
	CBufferString m_name; // 0x0010
	CUtlVector< CAnimDesc > m_animArray; // 0x0020
	CUtlVector< CAnimDecoder > m_decoderArray; // 0x0038
	int32 m_nMaxUniqueFrameIndex; // 0x0050
	CUtlVector< CAnimFrameSegment > m_segmentArray; // 0x0058
};
class C_OP_RenderSound : public CParticleFunctionRenderer // particles
{
	float32 m_flDurationScale; // 0x0228
	float32 m_flSndLvlScale; // 0x022C
	float32 m_flPitchScale; // 0x0230
	float32 m_flVolumeScale; // 0x0234
	ParticleAttributeIndex_t m_nSndLvlField; // 0x0238
	ParticleAttributeIndex_t m_nDurationField; // 0x023C
	ParticleAttributeIndex_t m_nPitchField; // 0x0240
	ParticleAttributeIndex_t m_nVolumeField; // 0x0244
	int32 m_nChannel; // 0x0248
	int32 m_nCPReference; // 0x024C
	char[256] m_pszSoundName; // 0x0250
	bool m_bSuppressStopSoundEvent; // 0x0350
};
class VMixDynamics3BandDesc_t // soundsystem_lowlevel
{
	float32 m_fldbGainOutput; // 0x0000
	float32 m_flRMSTimeMS; // 0x0004
	float32 m_fldbKneeWidth; // 0x0008
	float32 m_flDepth; // 0x000C
	float32 m_flWetMix; // 0x0010
	float32 m_flTimeScale; // 0x0014
	float32 m_flLowCutoffFreq; // 0x0018
	float32 m_flHighCutoffFreq; // 0x001C
	bool m_bPeakMode; // 0x0020
	VMixDynamicsBand_t[3] m_bandDesc; // 0x0024
};
class FeStiffHingeBuild_t // physicslib
{
	float32 flMaxAngle; // 0x0000
	float32 flStrength; // 0x0004
	float32[3] flMotionBias; // 0x0008
	uint16[3] nNode; // 0x0014
};
class CFootLockUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	FootLockPoseOpFixedSettings m_opFixedSettings; // 0x0070
	CUtlVector< FootFixedSettings > m_footSettings; // 0x00E0
	CAnimInputDamping m_hipShiftDamping; // 0x00F8
	CAnimInputDamping m_rootHeightDamping; // 0x0110
	float32 m_flStrideCurveScale; // 0x0128
	float32 m_flStrideCurveLimitScale; // 0x012C
	float32 m_flStepHeightIncreaseScale; // 0x0130
	float32 m_flStepHeightDecreaseScale; // 0x0134
	float32 m_flHipShiftScale; // 0x0138
	float32 m_flBlendTime; // 0x013C
	float32 m_flMaxRootHeightOffset; // 0x0140
	float32 m_flMinRootHeightOffset; // 0x0144
	float32 m_flTiltPlanePitchSpringStrength; // 0x0148
	float32 m_flTiltPlaneRollSpringStrength; // 0x014C
	bool m_bApplyFootRotationLimits; // 0x0150
	bool m_bApplyHipShift; // 0x0151
	bool m_bModulateStepHeight; // 0x0152
	bool m_bResetChild; // 0x0153
	bool m_bEnableVerticalCurvedPaths; // 0x0154
	bool m_bEnableRootHeightDamping; // 0x0155
};
class CAnimUpdateNodeBase // animgraphlib
{
	CAnimNodePath m_nodePath; // 0x0018
	AnimNodeNetworkMode m_networkMode; // 0x0048
	CUtlString m_name; // 0x0050
};
class CAnimationGroup // animationsystem
{
	uint32 m_nFlags; // 0x0010
	CBufferString m_name; // 0x0018
	CUtlVector< CStrongHandle< InfoForResourceTypeCAnimData > > m_localHAnimArray_Handle; // 0x0060
	CUtlVector< CStrongHandle< InfoForResourceTypeCAnimationGroup > > m_includedGroupArray_Handle; // 0x0078
	CStrongHandle< InfoForResourceTypeCSequenceGroupData > m_directHSeqGroup_Handle; // 0x0090
	CAnimKeyData m_decodeKey; // 0x0098
	CUtlVector< CBufferString > m_szScripts; // 0x0110
	CUtlVector< CStrongHandleVoid > m_AdditionalExtRefs; // 0x0128
};
class ResponseParams // server
{
	int16 odds; // 0x0010
	int16 flags; // 0x0012
	ResponseFollowup* m_pFollowup; // 0x0018
};
class IHasAttributes // server
{
};
class C_OP_SetControlPointFieldToWater : public CParticleFunctionPreEmission // particles
{
	int32 m_nSourceCP; // 0x01E0
	int32 m_nDestCP; // 0x01E4
	int32 m_nCPField; // 0x01E8
};
class CVoiceContainerStaticAdditiveSynth : public CVoiceContainerAsyncGenerator // soundsystem_voicecontainers
{
	CUtlVector< CVoiceContainerStaticAdditiveSynth::CTone > m_tones; // 0x0080
};
class CVoiceContainerDecayingSineWave : public CVoiceContainerGenerator // soundsystem_voicecontainers
{
	float32 m_flFrequency; // 0x0070
	float32 m_flDecayTime; // 0x0074
};
class CConcreteAnimParameter : public CAnimParameterBase // animgraphlib
{
	AnimParamButton_t m_previewButton; // 0x0070
	AnimParamNetworkSetting m_eNetworkSetting; // 0x0074
	bool m_bUseMostRecentValue; // 0x0078
	bool m_bAutoReset; // 0x0079
	bool m_bGameWritable; // 0x007A
	bool m_bGraphWritable; // 0x007B
};
class CSelectorUpdateNode : public CAnimUpdateNodeBase // animgraphlib
{
	CUtlVector< CAnimUpdateNodeRef > m_children; // 0x0060
	CUtlVector< int8 > m_tags; // 0x0078
	CBlendCurve m_blendCurve; // 0x0094
	CAnimValue< float32 > m_flBlendTime; // 0x009C
	CAnimParamHandle m_hParameter; // 0x00A4
	int32 m_nTagIndex; // 0x00A8
	SelectorTagBehavior_t m_eTagBehavior; // 0x00AC
	bool m_bResetOnChange; // 0x00B0
	bool m_bLockWhenWaning; // 0x00B1
	bool m_bSyncCyclesOnChange; // 0x00B2
};
class InfoForResourceTypeCDOTANovelsList // resourcesystem
{
};
class CDestructiblePartsSystemData // server
{
	CUtlOrderedMap< HitGroup_t, CDestructiblePart > m_PartsDataByHitGroup; // 0x0000
	CRangeInt m_nMinMaxNumberHitGroupsToDestroyWhenGibbing; // 0x0028
};
class DebugDrawBoneTransforms_t : public DebugSnapshotBaseStructuredData_t // server
{
	CUtlVectorFixedGrowable< CTransform, 128 > vecBones; // 0x0010
};
class AI_MotorServices_DebugSnapshotData_t::MotorPathWaypoint_t // server
{
	VectorWS position; // 0x0000
	uint32 nav_type; // 0x000C
	uint32 flags; // 0x0010
};
class C_OP_SetControlPointFieldToScalarExpression : public CParticleFunctionPreEmission // particles
{
	ScalarExpressionType_t m_nExpression; // 0x01E0
	CParticleCollectionFloatInput m_flInput1; // 0x01E8
	CParticleCollectionFloatInput m_flInput2; // 0x0358
	CParticleRemapFloatInput m_flOutputRemap; // 0x04C8
	int32 m_nOutputCP; // 0x0638
	int32 m_nOutVectorField; // 0x063C
	CParticleCollectionFloatInput m_flInterpolation; // 0x0640
};
class C_OP_ControlPointToRadialScreenSpace : public CParticleFunctionPreEmission // particles
{
	int32 m_nCPIn; // 0x01E0
	Vector m_vecCP1Pos; // 0x01E4
	int32 m_nCPOut; // 0x01F0
	int32 m_nCPOutField; // 0x01F4
	int32 m_nCPSSPosOut; // 0x01F8
};
class C_OP_RenderStatusEffectCitadel : public CParticleFunctionRenderer // particles
{
	CStrongHandle< InfoForResourceTypeCTextureBase > m_pTextureColorWarp; // 0x0228
	CStrongHandle< InfoForResourceTypeCTextureBase > m_pTextureNormal; // 0x0230
	CStrongHandle< InfoForResourceTypeCTextureBase > m_pTextureMetalness; // 0x0238
	CStrongHandle< InfoForResourceTypeCTextureBase > m_pTextureRoughness; // 0x0240
	CStrongHandle< InfoForResourceTypeCTextureBase > m_pTextureSelfIllum; // 0x0248
	CStrongHandle< InfoForResourceTypeCTextureBase > m_pTextureDetail; // 0x0250
};
class CStaticPoseCacheBuilder : public CStaticPoseCache // animgraphlib
{
};
class CTargetWarpUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	TargetWarpAngleMode_t m_eAngleMode; // 0x0074
	CAnimParamHandle m_hTargetPositionParameter; // 0x0078
	CAnimParamHandle m_hTargetUpVectorParameter; // 0x007A
	CAnimParamHandle m_hTargetFacePositionParameter; // 0x007C
	CAnimParamHandle m_hMoveHeadingParameter; // 0x007E
	CAnimParamHandle m_hDesiredMoveHeadingParameter; // 0x0080
	TargetWarpCorrectionMethod m_eCorrectionMethod; // 0x0084
	TargetWarpTimingMethod m_eTargetWarpTimingMethod; // 0x0088
	bool m_bTargetFacePositionIsWorldSpace; // 0x008C
	bool m_bTargetPositionIsWorldSpace; // 0x008D
	bool m_bOnlyWarpWhenTagIsFound; // 0x008E
	bool m_bWarpOrientationDuringTranslation; // 0x008F
	bool m_bWarpAroundCenter; // 0x0090
	float32 m_flMaxAngle; // 0x0094
};
class ResourceId_t // resourcefile
{
	uint64 m_Value; // 0x0000
};
class ResponseContext_t // server
{
	CUtlSymbolLarge m_iszName; // 0x0000
	CUtlSymbolLarge m_iszValue; // 0x0008
	GameTime_t m_fExpirationTime; // 0x0010
};
class C_OP_PointVectorAtNextParticle : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	CPerParticleFloatInput m_flInterpolation; // 0x01E0
	bool m_bPrevious; // 0x0350
};
class C_INIT_LifespanFromVelocity : public CParticleFunctionInitializer // particles
{
	Vector m_vecComponentScale; // 0x01E0
	float32 m_flTraceOffset; // 0x01EC
	float32 m_flMaxTraceLength; // 0x01F0
	float32 m_flTraceTolerance; // 0x01F4
	int32 m_nMaxPlanes; // 0x01F8
	char[128] m_CollisionGroupName; // 0x0200
	ParticleTraceSet_t m_nTraceSet; // 0x0280
	bool m_bIncludeWater; // 0x0290
};
class VecInputMaterialVariable_t // particles
{
	CUtlString m_strVariable; // 0x0000
	CParticleCollectionVecInput m_vecInput; // 0x0008
};
class CVMixDynamics3BandProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixDynamics3BandDesc_t m_desc; // 0x0020
};
class CVoiceContainerGenerator : public CVoiceContainerBase // soundsystem_voicecontainers
{
};
class VMixEnvelopeDesc_t // soundsystem_lowlevel
{
	float32 m_flAttackTimeMS; // 0x0000
	float32 m_flHoldTimeMS; // 0x0004
	float32 m_flReleaseTimeMS; // 0x0008
};
class CBodyGroupSetting // animgraphlib
{
	CUtlString m_BodyGroupName; // 0x0000
	int32 m_nBodyGroupOption; // 0x0008
};
class CNmTransitionEvent : public CNmEvent // animlib
{
	NmTransitionRule_t m_rule; // 0x0018
	CGlobalSymbol m_ID; // 0x0020
};
class CNmFloatCurveEvent : public CNmEvent // animlib
{
	CGlobalSymbol m_ID; // 0x0018
	CPiecewiseCurve m_curve; // 0x0020
};
class NmFloatCurveCompressionSettings_t // animlib
{
	NmCompressionSettings_t::QuantizationRange_t m_range; // 0x0000
	bool m_bIsStatic; // 0x0008
};
class ExternalAnimGraphHandle_t // server
{
	uint32 m_Value; // 0x0000
};
class DestructiblePartDamageRequest_t // server
{
	HitGroup_t m_nHitGroup; // 0x0000
	int32 m_nDamageLevel; // 0x0004
	uint16 m_nDesiredHealth; // 0x0008
	EDestructibleParts_DestroyParameterFlags m_nDestroyFlags; // 0x000C
	DamageTypes_t m_nDamageType; // 0x0010
	float32 m_flBreakDamage; // 0x0014
	float32 m_flBreakDamageRadius; // 0x0018
	CHandle< CBaseEntity > m_hAttacker; // 0x001C
	VectorWS m_vWsBreakDamageOrigin; // 0x0020
	Vector m_vWsBreakDamageForce; // 0x002C
};
class CVMixBoxverbProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixBoxverbDesc_t m_desc; // 0x0020
};
class VMixPannerDesc_t // soundsystem_lowlevel
{
	VMixPannerType_t m_type; // 0x0000
	float32 m_flStrength; // 0x0004
};
class CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	CUtlString m_name; // 0x0008
	int32 m_nChannels; // 0x0014
	float32 m_flxfade; // 0x0018
};
class FeTreeChildren_t // physicslib
{
	uint16[2] nChild; // 0x0000
};
class FollowAttachmentData // animationsystem
{
	int32 m_boneIndex; // 0x0000
	AttachmentHandle_t m_attachmentHandle; // 0x0004
};
class CDirectPlaybackUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	bool m_bFinishEarly; // 0x0074
	bool m_bResetOnFinish; // 0x0075
	CUtlVector< CDirectPlaybackTagData > m_allTags; // 0x0078
};
class CSkillFloat // server
{
	float32[4] m_pValue; // 0x0000
};
class FeAntiTunnelProbeBuild_t // physicslib
{
	float32 flWeight; // 0x0000
	float32 flActivationDistance; // 0x0004
	float32 flBias; // 0x0008
	float32 flCurvature; // 0x000C
	uint32 nFlags; // 0x0010
	uint16 nProbeNode; // 0x0014
	CUtlVector< uint16 > targetNodes; // 0x0018
};
class PulseRuntimeVarIndex_t // pulse_runtime_lib
{
	int32 m_Value; // 0x0000
};
class CNmBitFlags // animlib
{
	uint32 m_flags; // 0x0000
};
class CNmTargetPointNode::CDefinition : public CNmVectorValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	bool m_bIsWorldSpaceTarget; // 0x0012
};
class VsInputSignature_t // rendersystemdx11
{
	CUtlVector< VsInputSignatureElement_t > m_elems; // 0x0000
	CUtlVector< VsInputSignatureElement_t > m_depth_elems; // 0x0018
};
class CInventoryImageData // client
{
	InventoryNodeType_t m_nNodeType; // 0x0000
	CUtlString name; // 0x0008
	inv_image_data_t inventory_image_data; // 0x0010
};
class AI_MotorServices_DebugSnapshotData_t // server
{
	CGlobalSymbol active_motor; // 0x0000
	float32 desired_speed; // 0x0008
	Vector motor_velocity; // 0x000C
	CUtlVector< AI_MotorServices_DebugSnapshotData_t::MotorPathWaypoint_t > motor_path; // 0x0018
};
class locksound_t // server
{
	CGameSoundEventName sLockedSound; // 0x0008
	CGameSoundEventName sUnlockedSound; // 0x0010
	GameTime_t flwaitSound; // 0x0018
};
class FuncMoverMovementSummary_t // server
{
	float32 flStartT; // 0x0000
	float32 flEndT; // 0x0004
	int32 nStartNodeIndex; // 0x0008
	int32 nStopNodeIndex; // 0x000C
	int32 nMovementMode; // 0x0010
	FuncMoverMovementSummaryFlags_t nFlags; // 0x0014
	GameTick_t nTick; // 0x0018
	CHandle< CPathMover > hPathMover; // 0x001C
};
class C_OP_QuantizeFloat : public CParticleFunctionOperator // particles
{
	CPerParticleFloatInput m_InputValue; // 0x01D8
	ParticleAttributeIndex_t m_nOutputField; // 0x0348
};
class C_OP_BasicMovement : public CParticleFunctionOperator // particles
{
	CParticleCollectionVecInput m_Gravity; // 0x01D8
	CParticleCollectionFloatInput m_fDrag; // 0x0890
	CParticleMassCalculationParameters m_massControls; // 0x0A00
	int32 m_nMaxConstraintPasses; // 0x0E58
	bool m_bUseNewCode; // 0x0E5C
};
class CAudioMorphData // soundsystem_voicecontainers
{
	CUtlVector< float32 > m_times; // 0x0000
	CUtlVector< uint32 > m_nameHashCodes; // 0x0018
	CUtlVector< CUtlString > m_nameStrings; // 0x0030
	CUtlVector< CUtlVector< float32 > > m_samples; // 0x0048
	float32 m_flEaseIn; // 0x0060
	float32 m_flEaseOut; // 0x0064
};
class CVMixUtilityProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixUtilityDesc_t m_desc; // 0x0020
};
class CVMixAdditionalOutput // soundsystem_lowlevel
{
	CUtlString m_name; // 0x0000
};
class CSosGroupActionLimitSchema : public CSosGroupActionSchema // soundsystem
{
	int32 m_nMaxCount; // 0x0008
	SosActionStopType_t m_nStopType; // 0x000C
	SosActionLimitSortType_t m_nSortType; // 0x0010
	bool m_bStopImmediate; // 0x0014
	bool m_bCountStopped; // 0x0015
};
class CPulse_Constant // pulse_runtime_lib
{
	CPulseValueFullType m_Type; // 0x0000
	KeyValues3 m_Value; // 0x0018
};
class EventServerBeginSimulate_t : public EventSimulate_t // engine2
{
};
class C_INIT_CreationNoise : public CParticleFunctionInitializer // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E0
	bool m_bAbsVal; // 0x01E4
	bool m_bAbsValInv; // 0x01E5
	float32 m_flOffset; // 0x01E8
	float32 m_flOutputMin; // 0x01EC
	float32 m_flOutputMax; // 0x01F0
	float32 m_flNoiseScale; // 0x01F4
	float32 m_flNoiseScaleLoc; // 0x01F8
	Vector m_vecOffsetLoc; // 0x01FC
	float32 m_flWorldTimeScale; // 0x0208
};
class C_INIT_CreateWithinBox : public CParticleFunctionInitializer // particles
{
	CPerParticleVecInput m_vecMin; // 0x01E0
	CPerParticleVecInput m_vecMax; // 0x0898
	int32 m_nControlPointNumber; // 0x0F50
	bool m_bLocalSpace; // 0x0F54
	CRandomNumberGeneratorParameters m_randomnessParameters; // 0x0F58
	bool m_bUseNewCode; // 0x0F60
};
class CVMixPresetDSPProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixPresetDSPDesc_t m_desc; // 0x0020
};
class CSosGroupActionMemberCountEnvelopeSchema : public CSosGroupActionSchema // soundsystem
{
	int32 m_nBaseCount; // 0x0008
	int32 m_nTargetCount; // 0x000C
	float32 m_flBaseValue; // 0x0010
	float32 m_flTargetValue; // 0x0014
	float32 m_flAttack; // 0x0018
	float32 m_flDecay; // 0x001C
	CUtlString m_resultVarName; // 0x0020
	bool m_bSaveToGroup; // 0x0028
};
class CNmTransitionEventConditionNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	CGlobalSymbol m_requireRuleID; // 0x0010
	CNmBitFlags m_eventConditionRules; // 0x0018
	int16 m_nSourceStateNodeIdx; // 0x001C
	NmTransitionRuleCondition_t m_ruleCondition; // 0x001E
};
class ModelSkeletonData_t // modellib
{
	CUtlVector< CUtlString > m_boneName; // 0x0000
	CUtlVector< int16 > m_nParent; // 0x0018
	CUtlVector< float32 > m_boneSphere; // 0x0030
	CUtlVector< uint32 > m_nFlag; // 0x0048
	CUtlVector< Vector > m_bonePosParent; // 0x0060
	CUtlVector< QuaternionStorage > m_boneRotParent; // 0x0078
	CUtlVector< float32 > m_boneScaleParent; // 0x0090
};
class CNmConstBoolNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	bool m_bValue; // 0x0010
};
class CWayPointHelperInstanceData // animgraphlib
{
	Vector m_vMovement; // 0x0000
	QAngle m_vRotation; // 0x000C
	Vector m_vWaypointPosWS; // 0x0018
	bool m_bStopUpdatingWaypointPos; // 0x0024
};
class CNmZeroPoseNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
};
class EventSimpleLoopFrameUpdate_t // engine2
{
	EngineLoopState_t m_LoopState; // 0x0000
	float32 m_flRealTime; // 0x0028
	float32 m_flFrameTime; // 0x002C
};
class CCS2UIPawnGraphController : public CAnimGraphControllerBase // client
{
	CAnimGraph2ParamOptionalRef< float32 > m_nAnimationSeed; // 0x0088
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_characterMode; // 0x00A0
	CAnimGraph2ParamOptionalRef< bool > m_bCharacterModeReset; // 0x00B8
	CAnimGraph2ParamOptionalRef< float32 > m_nTeamPreviewVariant; // 0x00D0
	CAnimGraph2ParamOptionalRef< float32 > m_nTeamPreviewRandom; // 0x00E8
	CAnimGraph2ParamOptionalRef< float32 > m_nTeamPreviewPosition; // 0x0100
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_endOfMatchCelebration; // 0x0118
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_action; // 0x0130
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_bannerAnimation; // 0x0148
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_weaponCategory; // 0x0160
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_weaponType; // 0x0178
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_weaponState; // 0x0190
	CAnimGraph2ParamOptionalRef< float32 > m_inspectTurnAngle; // 0x01A8
	CAnimGraph2ParamOptionalRef< bool > m_bCT; // 0x01C0
};
class CRR_Response // server
{
	uint8 m_Type; // 0x0000
	char[192] m_szResponseName; // 0x0001
	char[128] m_szMatchingRule; // 0x00C1
	ResponseParams m_Params; // 0x0160
	float32 m_fMatchScore; // 0x0180
	bool m_bAnyMatchingRulesInCooldown; // 0x0184
	char* m_szSpeakerContext; // 0x0188
	char* m_szWorldContext; // 0x0190
	ResponseFollowup m_Followup; // 0x0198
	CUtlSymbol m_recipientFilter; // 0x01CA
};
class C_OP_RemapScalarOnceTimed : public CParticleFunctionOperator // particles
{
	bool m_bProportional; // 0x01D8
	ParticleAttributeIndex_t m_nFieldInput; // 0x01DC
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E0
	float32 m_flInputMin; // 0x01E4
	float32 m_flInputMax; // 0x01E8
	float32 m_flOutputMin; // 0x01EC
	float32 m_flOutputMax; // 0x01F0
	float32 m_flRemapTime; // 0x01F4
};
class CNmEvent // animlib
{
	NmPercent_t m_flStartTime; // 0x0008
	NmPercent_t m_flDuration; // 0x000C
	CGlobalSymbol m_syncID; // 0x0010
};
class ModelBoneFlexDriverControl_t // modellib
{
	ModelBoneFlexComponent_t m_nBoneComponent; // 0x0000
	CUtlString m_flexController; // 0x0008
	uint32 m_flexControllerToken; // 0x0010
	float32 m_flMin; // 0x0014
	float32 m_flMax; // 0x0018
};
class C_OP_OrientTo2dDirection : public CParticleFunctionOperator // particles
{
	CPerParticleVecInput m_vecInput; // 0x01D8
	float32 m_flRotOffset; // 0x0890
	float32 m_flSpinStrength; // 0x0894
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0898
};
class C_OP_VelocityMatchingForce : public CParticleFunctionOperator // particles
{
	float32 m_flDirScale; // 0x01D8
	float32 m_flSpdScale; // 0x01DC
	float32 m_flNeighborDistance; // 0x01E0
	float32 m_flFacingStrength; // 0x01E4
	bool m_bUseAABB; // 0x01E8
	int32 m_nCPBroadcast; // 0x01EC
};
class C_OP_LockPoints : public CParticleFunctionOperator // particles
{
	int32 m_nMinCol; // 0x01D8
	int32 m_nMaxCol; // 0x01DC
	int32 m_nMinRow; // 0x01E0
	int32 m_nMaxRow; // 0x01E4
	int32 m_nControlPoint; // 0x01E8
	float32 m_flBlendValue; // 0x01EC
};
class CBlend2DInstanceData // animgraphlib
{
	Vector2D m_dampedValue; // 0x0008
	float32 m_flCycle; // 0x0044
	float32 m_flPrevCycle; // 0x0048
};
class CPathAnimMotorUpdater : public CPathAnimMotorUpdaterBase // animgraphlib
{
};
class SummaryTakeDamageInfo_t // server
{
	int32 nSummarisedCount; // 0x0000
	CTakeDamageInfo info; // 0x0008
	CTakeDamageResult result; // 0x0120
	CHandle< CBaseEntity > hTarget; // 0x0180
};
class C_INIT_CreateOnModel : public CParticleFunctionInitializer // particles
{
	CParticleModelInput m_modelInput; // 0x01E0
	CParticleTransformInput m_transformInput; // 0x0240
	int32 m_nForceInModel; // 0x02A8
	bool m_bScaleToVolume; // 0x02AC
	bool m_bEvenDistribution; // 0x02AD
	CParticleCollectionFloatInput m_nDesiredHitbox; // 0x02B0
	int32 m_nHitboxValueFromControlPointIndex; // 0x0420
	CParticleCollectionVecInput m_vecHitBoxScale; // 0x0428
	float32 m_flBoneVelocity; // 0x0AE0
	float32 m_flMaxBoneVelocity; // 0x0AE4
	CParticleCollectionVecInput m_vecDirectionBias; // 0x0AE8
	char[128] m_HitboxSetName; // 0x11A0
	bool m_bLocalCoords; // 0x1220
	bool m_bUseBones; // 0x1221
	bool m_bUseMesh; // 0x1222
	CParticleCollectionFloatInput m_flShellSize; // 0x1228
};
class C_OP_SetControlPointOrientationToCPVelocity : public CParticleFunctionPreEmission // particles
{
	int32 m_nCPInput; // 0x01E0
	int32 m_nCPOutput; // 0x01E4
};
class SteamAudioCustomDataDimensionsSettings_t // steamaudio
{
	int32 m_nAmbisonicsOrderOutsideField; // 0x0000
	int32 m_nAmbisonicsOrderInsideSizeField; // 0x0004
	float32 m_flOutsideThreshold; // 0x0008
	float32 m_flSizeThreshold; // 0x000C
	float32 m_flInsideThreshold; // 0x0010
};
class CSteamAudioBakedOcclusionData // steamaudio
{
	SteamAudioCustomDataOcclusionSettings_t m_settings; // 0x0000
	CSteamAudioProbeData m_probes; // 0x0010
	CUtlVector< float32 > m_vecPathingRatio; // 0x0018
	CUtlVector< float32 > m_vecPathingDeviation; // 0x0030
	CUtlVector< float32 > m_vecReflectionEnergy; // 0x0048
};
class CTwoBoneIKUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	TwoBoneIKSettings_t m_opFixedData; // 0x0070
};
class CNmTarget // animlib
{
	CTransform m_transform; // 0x0000
	CGlobalSymbol m_boneID; // 0x0020
	bool m_bIsBoneTarget; // 0x0028
	bool m_bIsUsingBoneSpaceOffsets; // 0x0029
	bool m_bHasOffsets; // 0x002A
	bool m_bIsSet; // 0x002B
};
class CScriptUniformRandomStream // server
{
	HSCRIPT m_hScriptScope; // 0x0008
	int32 m_nInitialSeed; // 0x009C
};
class C_OP_SelectivelyEnableChildren : public CParticleFunctionPreEmission // particles
{
	CParticleCollectionFloatInput m_nChildGroupID; // 0x01E0
	CParticleCollectionFloatInput m_nFirstChild; // 0x0350
	CParticleCollectionFloatInput m_nNumChildrenToEnable; // 0x04C0
	bool m_bPlayEndcapOnStop; // 0x0630
	bool m_bDestroyImmediately; // 0x0631
};
class RnHalfEdge_t // physicslib
{
	uint8 m_nNext; // 0x0000
	uint8 m_nTwin; // 0x0001
	uint8 m_nOrigin; // 0x0002
	uint8 m_nFace; // 0x0003
};
class PulseGraphExecutionHistoryCursorDesc_t // pulse_runtime_lib
{
	CUtlVector< PulseCursorID_t > vecAncestorCursorIDs; // 0x0000
	PulseDocNodeID_t nSpawnNodeID; // 0x0018
	PulseDocNodeID_t nRetiredAtNodeID; // 0x001C
	float32 flLastReferenced; // 0x0020
	int32 nLastValidEntryIdx; // 0x0024
	bool bWasAnObservableComputation; // 0x0028
};
class SlopeData // animgraphlib
{
	Vector m_vSlopeNormal; // 0x0000
};
class CCompositeMaterialEditorDoc // compositematerialslib
{
	int32 m_nVersion; // 0x0008
	CUtlVector< CompositeMaterialEditorPoint_t > m_Points; // 0x0010
	KeyValues3 m_KVthumbnail; // 0x0028
};
class SoundOpvarTraceResult_t // server
{
	VectorWS vPos; // 0x0000
	bool bDidHit; // 0x000C
	float32 flDistSqrToCenter; // 0x0010
};
class C_OP_SetFromCPSnapshot : public CParticleFunctionOperator // particles
{
	int32 m_nControlPointNumber; // 0x01D8
	CUtlString m_strSnapshotSubset; // 0x01E0
	ParticleAttributeIndex_t m_nAttributeToRead; // 0x01E8
	ParticleAttributeIndex_t m_nAttributeToWrite; // 0x01EC
	int32 m_nLocalSpaceCP; // 0x01F0
	bool m_bRandom; // 0x01F4
	bool m_bReverse; // 0x01F5
	int32 m_nRandomSeed; // 0x01F8
	CParticleCollectionFloatInput m_nSnapShotStartPoint; // 0x0200
	CParticleCollectionFloatInput m_nSnapShotIncrement; // 0x0370
	CPerParticleFloatInput m_flInterpolation; // 0x04E0
	bool m_bSubSample; // 0x0650
	bool m_bPrev; // 0x0651
};
class C_OP_ClampVector : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	CPerParticleVecInput m_vecOutputMin; // 0x01E0
	CPerParticleVecInput m_vecOutputMax; // 0x0898
};
class C_OP_RemapDensityToVector : public CParticleFunctionOperator // particles
{
	float32 m_flRadiusScale; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
	float32 m_flDensityMin; // 0x01E0
	float32 m_flDensityMax; // 0x01E4
	Vector m_vecOutputMin; // 0x01E8
	Vector m_vecOutputMax; // 0x01F4
	bool m_bUseParentDensity; // 0x0200
	int32 m_nVoxelGridResolution; // 0x0204
};
class CTakeDamageInfo // server
{
	Vector m_vecDamageForce; // 0x0008
	VectorWS m_vecDamagePosition; // 0x0014
	VectorWS m_vecReportedPosition; // 0x0020
	Vector m_vecDamageDirection; // 0x002C
	CHandle< CBaseEntity > m_hInflictor; // 0x0038
	CHandle< CBaseEntity > m_hAttacker; // 0x003C
	CHandle< CBaseEntity > m_hAbility; // 0x0040
	float32 m_flDamage; // 0x0044
	float32 m_flTotalledDamage; // 0x0048
	DamageTypes_t m_bitsDamageType; // 0x004C
	int32 m_iDamageCustom; // 0x0050
	AmmoIndex_t m_iAmmoType; // 0x0054
	float32 m_flOriginalDamage; // 0x0060
	bool m_bShouldBleed; // 0x0064
	bool m_bShouldSpark; // 0x0065
	TakeDamageFlags_t m_nDamageFlags; // 0x0070
	HitGroup_t m_iHitGroupId; // 0x0078
	int32 m_nNumObjectsPenetrated; // 0x007C
	float32 m_flFriendlyFireDamageReductionRatio; // 0x0080
	bool m_bStoppedBullet; // 0x0084
	CUtlLeanVector< DestructiblePartDamageRequest_t > m_DestructibleHitGroupRequests; // 0x0100
	bool m_bInTakeDamageFlow; // 0x0110
};
class C_INIT_DistanceCull : public CParticleFunctionInitializer // particles
{
	int32 m_nControlPoint; // 0x01E0
	CParticleCollectionFloatInput m_flDistance; // 0x01E8
	bool m_bCullInside; // 0x0358
};
class C_INIT_RemapTransformOrientationToRotations : public CParticleFunctionInitializer // particles
{
	CParticleTransformInput m_TransformInput; // 0x01E0
	Vector m_vecRotation; // 0x0248
	bool m_bUseQuat; // 0x0254
	bool m_bWriteNormal; // 0x0255
};
class C_INIT_CreateInEpitrochoid : public CParticleFunctionInitializer // particles
{
	int32 m_nComponent1; // 0x01E0
	int32 m_nComponent2; // 0x01E4
	CParticleTransformInput m_TransformInput; // 0x01E8
	CPerParticleFloatInput m_flParticleDensity; // 0x0250
	CPerParticleFloatInput m_flOffset; // 0x03C0
	CPerParticleFloatInput m_flRadius1; // 0x0530
	CPerParticleFloatInput m_flRadius2; // 0x06A0
	bool m_bUseCount; // 0x0810
	bool m_bUseLocalCoords; // 0x0811
	bool m_bOffsetExistingPos; // 0x0812
};
class C_OP_SetControlPointPositions : public CParticleFunctionPreEmission // particles
{
	bool m_bUseWorldLocation; // 0x01E0
	bool m_bOrient; // 0x01E1
	bool m_bSetOnce; // 0x01E2
	int32 m_nCP1; // 0x01E4
	int32 m_nCP2; // 0x01E8
	int32 m_nCP3; // 0x01EC
	int32 m_nCP4; // 0x01F0
	Vector m_vecCP1Pos; // 0x01F4
	Vector m_vecCP2Pos; // 0x0200
	Vector m_vecCP3Pos; // 0x020C
	Vector m_vecCP4Pos; // 0x0218
	int32 m_nHeadLocation; // 0x0224
};
class CSosGroupActionSetSoundeventParameterSchema : public CSosGroupActionSchema // soundsystem
{
	int32 m_nMaxCount; // 0x0008
	float32 m_flMinValue; // 0x000C
	float32 m_flMaxValue; // 0x0010
	CUtlString m_opvarName; // 0x0018
	SosActionSetParamSortType_t m_nSortType; // 0x0020
};
class CVoiceContainerNull : public CVoiceContainerGenerator // soundsystem_voicecontainers
{
};
class AnimScriptHandle // modellib
{
	uint32 m_id; // 0x0000
};
class CNmOrNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	CUtlLeanVectorFixedGrowable< int16, 4 > m_conditionNodeIndices; // 0x0010
};
class InfoForResourceTypeCResourceManifestInternal // resourcefile
{
};
class CollisionDetailLayerInfo_t // physicslib
{
	CUtlString m_sDescription; // 0x0000
	CUtlString m_sFriendlyName; // 0x0008
	bool m_bIsQueryOnly; // 0x0010
	CUtlString m_sParentDetailLayer; // 0x0018
	CUtlVector< CollisionDetailLayerInfo_t::Name_t > m_vecSubtreeDetailLayers; // 0x0020
	bool m_bNotPickable; // 0x0038
};
class CAnimEncodedFrames // animationsystem
{
	CBufferString m_fileName; // 0x0000
	int32 m_nFrames; // 0x0010
	int32 m_nFramesPerBlock; // 0x0014
	CUtlVector< CAnimFrameBlockAnim > m_frameblockArray; // 0x0018
	CAnimEncodeDifference m_usageDifferences; // 0x0030
};
class VPhysXConstraint2_t // modellib
{
	uint32 m_nFlags; // 0x0000
	uint16 m_nParent; // 0x0004
	uint16 m_nChild; // 0x0006
	VPhysXConstraintParams_t m_params; // 0x0008
};
class CNmBlend2DNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
	CUtlLeanVectorFixedGrowable< int16, 5 > m_sourceNodeIndices; // 0x0010
	CUtlLeanVectorFixedGrowable< Vector2D, 10 > m_values; // 0x0028
	CUtlLeanVectorFixedGrowable< uint8, 30 > m_indices; // 0x0080
	CUtlLeanVectorFixedGrowable< uint8, 10 > m_hullIndices; // 0x00A8
	int16 m_nInputParameterNodeIdx0; // 0x00C0
	int16 m_nInputParameterNodeIdx1; // 0x00C2
	bool m_bAllowLooping; // 0x00C4
};
class CWarpSectionAnimTagBase : public CAnimTagBase // animgraphlib
{
};
class EventClientSceneSystemThreadStateChange_t // engine2
{
	bool m_bThreadsActive; // 0x0000
};
class CEmptyEntityInstance // entity2
{
};
class C_OP_RemapDotProductToCP : public CParticleFunctionPreEmission // particles
{
	int32 m_nInputCP1; // 0x01E0
	int32 m_nInputCP2; // 0x01E4
	int32 m_nOutputCP; // 0x01E8
	int32 m_nOutVectorField; // 0x01EC
	CParticleCollectionFloatInput m_flInputMin; // 0x01F0
	CParticleCollectionFloatInput m_flInputMax; // 0x0360
	CParticleCollectionFloatInput m_flOutputMin; // 0x04D0
	CParticleCollectionFloatInput m_flOutputMax; // 0x0640
};
class C_INIT_CreateFromParentParticles : public CParticleFunctionInitializer // particles
{
	float32 m_flVelocityScale; // 0x01E0
	float32 m_flIncrement; // 0x01E4
	bool m_bRandomDistribution; // 0x01E8
	int32 m_nRandomSeed; // 0x01EC
	bool m_bSubFrame; // 0x01F0
	bool m_bSetRopeSegmentID; // 0x01F1
};
class C_OP_IntraParticleForce : public CParticleFunctionForce // particles
{
	float32 m_flAttractionMinDistance; // 0x01E8
	float32 m_flAttractionMaxDistance; // 0x01EC
	float32 m_flAttractionMaxStrength; // 0x01F0
	float32 m_flRepulsionMinDistance; // 0x01F4
	float32 m_flRepulsionMaxDistance; // 0x01F8
	float32 m_flRepulsionMaxStrength; // 0x01FC
	bool m_bUseAABB; // 0x0200
};
class CVMixFilterProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixFilterDesc_t m_desc; // 0x0020
};
class FeHingeLimitBuild_t // physicslib
{
	uint16[6] nNode; // 0x0000
	uint32 nFlags; // 0x000C
	float32 flLimitCW; // 0x0010
	float32 flLimitCCW; // 0x0014
};
class CNmIDEventPercentageThroughNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	int16 m_nSourceStateNodeIdx; // 0x0010
	CNmBitFlags m_eventConditionRules; // 0x0014
	CGlobalSymbol m_eventID; // 0x0018
};
class CNmControlParameterBoolNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
};
class EventPreDataUpdate_t // engine2
{
	int32 m_nCount; // 0x0000
};
class CDSPPresetMixgroupModifierTable // soundsystem
{
	CUtlVector< CDspPresetModifierList > m_table; // 0x0000
};
class VMixEffectChainDesc_t // soundsystem_lowlevel
{
	CUtlString m_effectName; // 0x0000
};
class HitReactFixedSettings_t // animgraphlib
{
	int32 m_nWeightListIndex; // 0x0000
	int32 m_nEffectedBoneCount; // 0x0004
	float32 m_flMaxImpactForce; // 0x0008
	float32 m_flMinImpactForce; // 0x000C
	float32 m_flWhipImpactScale; // 0x0010
	float32 m_flCounterRotationScale; // 0x0014
	float32 m_flDistanceFadeScale; // 0x0018
	float32 m_flPropagationScale; // 0x001C
	float32 m_flWhipDelay; // 0x0020
	float32 m_flSpringStrength; // 0x0024
	float32 m_flWhipSpringStrength; // 0x0028
	float32 m_flMaxAngleRadians; // 0x002C
	int32 m_nHipBoneIndex; // 0x0030
	float32 m_flHipBoneTranslationScale; // 0x0034
	float32 m_flHipDipSpringStrength; // 0x0038
	float32 m_flHipDipImpactScale; // 0x003C
	float32 m_flHipDipDelay; // 0x0040
};
class CNmParameterizedBlendNode::Parameterization_t // animlib
{
	CUtlLeanVectorFixedGrowable< CNmParameterizedBlendNode::BlendRange_t, 5 > m_blendRanges; // 0x0000
	Range_t m_parameterRange; // 0x0048
};
class CPhysSurfacePropertiesAudio // modellib
{
	float32 m_reflectivity; // 0x0000
	float32 m_hardnessFactor; // 0x0004
	float32 m_roughnessFactor; // 0x0008
	float32 m_roughThreshold; // 0x000C
	float32 m_hardThreshold; // 0x0010
	float32 m_hardVelocityThreshold; // 0x0014
	float32 m_flStaticImpactVolume; // 0x0018
	float32 m_flOcclusionFactor; // 0x001C
};
class CRelativeTransform // server
{
	bool m_bTransformIsWorldSpace; // 0x0000
	CTransform m_transform; // 0x0010
	CTransformWS m_transformWS; // 0x0030
	CHandle< CBaseEntity > m_hEntity; // 0x0050
};
class ParticlePreviewBodyGroup_t // particles
{
	CUtlString m_bodyGroupName; // 0x0000
	int32 m_nValue; // 0x0008
};
class C_OP_GlobalLight : public CParticleFunctionOperator // particles
{
	float32 m_flScale; // 0x01D8
	bool m_bClampLowerRange; // 0x01DC
	bool m_bClampUpperRange; // 0x01DD
};
class C_INIT_RandomSequence : public CParticleFunctionInitializer // particles
{
	int32 m_nSequenceMin; // 0x01E0
	int32 m_nSequenceMax; // 0x01E4
	bool m_bShuffle; // 0x01E8
	bool m_bLinear; // 0x01E9
	CUtlVector< SequenceWeightedList_t > m_WeightedList; // 0x01F0
};
class C_INIT_CreateFromCPs : public CParticleFunctionInitializer // particles
{
	int32 m_nIncrement; // 0x01E0
	int32 m_nMinCP; // 0x01E4
	int32 m_nMaxCP; // 0x01E8
	CParticleCollectionFloatInput m_nDynamicCPCount; // 0x01F0
};
class CSosGroupActionSchema // soundsystem
{
};
class FeFollowNode_t // physicslib
{
	uint16 nParentNode; // 0x0000
	uint16 nChildNode; // 0x0002
	float32 flWeight; // 0x0004
};
class CAnimParamHandle // animgraphlib
{
	AnimParamType_t m_type; // 0x0000
	uint8 m_index; // 0x0001
};
class CSmoothFunc // server
{
	float32 m_flSmoothAmplitude; // 0x0008
	float32 m_flSmoothBias; // 0x000C
	float32 m_flSmoothDuration; // 0x0010
	float32 m_flSmoothRemainingTime; // 0x0014
	int32 m_nSmoothDir; // 0x0018
};
class C_OP_MovementMoveAlongSkinnedCPSnapshot : public CParticleFunctionOperator // particles
{
	int32 m_nControlPointNumber; // 0x01D8
	int32 m_nSnapshotControlPointNumber; // 0x01DC
	bool m_bSetNormal; // 0x01E0
	bool m_bSetRadius; // 0x01E1
	CPerParticleFloatInput m_flInterpolation; // 0x01E8
	CPerParticleFloatInput m_flTValue; // 0x0358
};
class SteamAudioReverbSettings_t // steamaudio
{
	int32 m_nNumRays; // 0x0000
	int32 m_nNumBounces; // 0x0004
	float32 m_flIRDuration; // 0x0008
	int32 m_nAmbisonicsOrder; // 0x000C
	bool m_bExportScene; // 0x0010
};
class CEntityAttributeTable // entity2
{
	CUtlOrderedMap< CUtlStringTokenNoRegistration, Attribute_t > m_Attributes; // 0x0000
	CUtlOrderedMap< CUtlStringTokenNoRegistration, CUtlString > m_Names; // 0x0028
};
class CFiringModeFloat // server
{
	float32[2] m_flValues; // 0x0000
};
class C_OP_RemapCPtoVector : public CParticleFunctionOperator // particles
{
	int32 m_nCPInput; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
	int32 m_nLocalSpaceCP; // 0x01E0
	Vector m_vInputMin; // 0x01E4
	Vector m_vInputMax; // 0x01F0
	Vector m_vOutputMin; // 0x01FC
	Vector m_vOutputMax; // 0x0208
	float32 m_flStartTime; // 0x0214
	float32 m_flEndTime; // 0x0218
	float32 m_flInterpRate; // 0x021C
	ParticleSetMethod_t m_nSetMethod; // 0x0220
	bool m_bOffset; // 0x0224
	bool m_bAccelerate; // 0x0225
};
class CSeqMultiFetchFlag // animationsystem
{
	bool m_bRealtime; // 0x0000
	bool m_bCylepose; // 0x0001
	bool m_b0D; // 0x0002
	bool m_b1D; // 0x0003
	bool m_b2D; // 0x0004
	bool m_b2D_TRI; // 0x0005
};
class CNmParticleEvent : public CNmEvent // animlib
{
	CNmEventRelevance_t m_relevance; // 0x0018
	CNmParticleEvent::Type_t m_type; // 0x001C
	CNmEventTargetEntity_t m_target; // 0x0020
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_hParticleSystem; // 0x0028
	CUtlString m_tags; // 0x0030
	bool m_bStopImmediately; // 0x0038
	bool m_bDetachFromOwner; // 0x0039
	bool m_bPlayEndCap; // 0x003A
	CUtlString m_attachmentPoint0; // 0x0040
	ParticleAttachment_t m_attachmentType0; // 0x0048
	CUtlString m_attachmentPoint1; // 0x0050
	ParticleAttachment_t m_attachmentType1; // 0x0058
	CUtlString m_config; // 0x0060
	CUtlString m_effectForConfig; // 0x0068
};
class CNmSyncTrack::Event_t // animlib
{
	CGlobalSymbol m_ID; // 0x0000
	NmPercent_t m_startTime; // 0x0008
	NmPercent_t m_duration; // 0x000C
};
class InfoForResourceTypeCVSoundEventScriptList // resourcesystem
{
};
class PhysBlockHeader_t // server
{
	int32 nSaved; // 0x0000
	uint64 pWorldObject; // 0x0008
};
class lerpdata_t // server
{
	CHandle< CBaseEntity > m_hEnt; // 0x0000
	MoveType_t m_MoveType; // 0x0004
	GameTime_t m_flStartTime; // 0x0008
	VectorWS m_vecStartOrigin; // 0x000C
	Quaternion m_qStartRot; // 0x0020
	ParticleIndex_t m_nFXIndex; // 0x0030
};
class C_OP_LerpScalar : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	CPerParticleFloatInput m_flOutput; // 0x01E0
	float32 m_flStartTime; // 0x0350
	float32 m_flEndTime; // 0x0354
};
class C_OP_RenderModels : public CParticleFunctionRenderer // particles
{
	bool m_bOnlyRenderInEffectsBloomPass; // 0x0228
	bool m_bOnlyRenderInEffectsWaterPass; // 0x0229
	bool m_bUseMixedResolutionRendering; // 0x022A
	bool m_bOnlyRenderInEffecsGameOverlay; // 0x022B
	CUtlVector< ModelReference_t > m_ModelList; // 0x0230
	ParticleAttributeIndex_t m_nBodyGroupField; // 0x0248
	ParticleAttributeIndex_t m_nSubModelField; // 0x024C
	bool m_bIgnoreNormal; // 0x0250
	bool m_bOrientZ; // 0x0251
	bool m_bCenterOffset; // 0x0252
	CPerParticleVecInput m_vecLocalOffset; // 0x0258
	CPerParticleVecInput m_vecLocalRotation; // 0x0910
	bool m_bIgnoreRadius; // 0x0FC8
	int32 m_nModelScaleCP; // 0x0FCC
	CPerParticleVecInput m_vecComponentScale; // 0x0FD0
	bool m_bLocalScale; // 0x1688
	int32 m_nSizeCullBloat; // 0x168C
	bool m_bAnimated; // 0x1690
	CPerParticleFloatInput m_flAnimationRate; // 0x1698
	bool m_bScaleAnimationRate; // 0x1808
	bool m_bForceLoopingAnimation; // 0x1809
	bool m_bResetAnimOnStop; // 0x180A
	bool m_bManualAnimFrame; // 0x180B
	ParticleAttributeIndex_t m_nAnimationScaleField; // 0x180C
	ParticleAttributeIndex_t m_nAnimationField; // 0x1810
	ParticleAttributeIndex_t m_nManualFrameField; // 0x1814
	char[256] m_ActivityName; // 0x1818
	char[256] m_SequenceName; // 0x1918
	bool m_bEnableClothSimulation; // 0x1A18
	bool m_bDisableClothGroundCollision; // 0x1A19
	char[64] m_ClothEffectName; // 0x1A1A
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hOverrideMaterial; // 0x1A60
	bool m_bOverrideTranslucentMaterials; // 0x1A68
	CPerParticleFloatInput m_nSkin; // 0x1A70
	CUtlVector< MaterialVariable_t > m_MaterialVars; // 0x1BE0
	CPerParticleFloatInput m_flRenderFilter; // 0x1BF8
	CPerParticleFloatInput m_flManualModelSelection; // 0x1D68
	CParticleModelInput m_modelInput; // 0x1ED8
	int32 m_nLOD; // 0x1F38
	char[256] m_EconSlotName; // 0x1F3C
	bool m_bOriginalModel; // 0x203C
	bool m_bSuppressTint; // 0x203D
	RenderModelSubModelFieldType_t m_nSubModelFieldType; // 0x2040
	bool m_bDisableShadows; // 0x2044
	bool m_bDisableDepthPrepass; // 0x2045
	bool m_bAcceptsDecals; // 0x2046
	bool m_bForceDrawInterlevedWithSiblings; // 0x2047
	bool m_bDoNotDrawInParticlePass; // 0x2048
	bool m_bAllowApproximateTransforms; // 0x2049
	char[260] m_szRenderAttribute; // 0x204A
	CParticleCollectionFloatInput m_flRadiusScale; // 0x2150
	CParticleCollectionFloatInput m_flAlphaScale; // 0x22C0
	CParticleCollectionFloatInput m_flRollScale; // 0x2430
	ParticleAttributeIndex_t m_nAlpha2Field; // 0x25A0
	CParticleCollectionVecInput m_vecColorScale; // 0x25A8
	ParticleColorBlendType_t m_nColorBlendType; // 0x2C60
	CUtlString m_strLightStyle; // 0x2C68
	CPerParticleFloatInput m_flLightStyleTime; // 0x2C70
};
class FeSimdSpringIntegrator_t // physicslib
{
	uint16[4][2] nNode; // 0x0000
	fltx4 flSpringRestLength; // 0x0010
	fltx4 flSpringConstant; // 0x0020
	fltx4 flSpringDamping; // 0x0030
	fltx4 flNodeWeight0; // 0x0040
};
class CParticleModelInput : public CParticleInput // particleslib
{
	ParticleModelType_t m_nType; // 0x0010
	CParticleNamedValueRef m_NamedValue; // 0x0018
	int32 m_nControlPoint; // 0x0058
};
class CHitBoxSetList // modellib
{
	CUtlVector< CHitBoxSet > m_HitBoxSets; // 0x0000
};
class CMoverInstanceData // animgraphlib
{
	float32 m_flDampedValue; // 0x0000
	Vector m_vMovement; // 0x0004
	CRotation m_Rotation; // 0x001C
	CRotation m_TargetOrientation; // 0x0020
};
class CNmExternalPoseNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
	bool m_bShouldSampleRootMotion; // 0x0010
};
class ModelEmbeddedMesh_t // modellib
{
	CUtlString m_Name; // 0x0000
	int32 m_nMeshIndex; // 0x0010
	int32 m_nDataBlock; // 0x0014
	int32 m_nMorphBlock; // 0x0018
	CUtlVector< ModelMeshBufferData_t > m_vertexBuffers; // 0x0020
	CUtlVector< ModelMeshBufferData_t > m_indexBuffers; // 0x0038
	CUtlVector< ModelMeshBufferData_t > m_toolsBuffers; // 0x0050
	int32 m_nVBIBBlock; // 0x0068
	int32 m_nToolsVBBlock; // 0x006C
};
class PrecipitationFilter_t // server
{
	float32 m_flMaxRadius; // 0x0000
};
class PathMoverEntitySpawn // server
{
	CHandle< CFuncMover > hMover; // 0x0000
	CUtlVector< CHandle< CBaseEntity > > vecOtherEntities; // 0x0008
};
class CNavVolumeSphere : public CNavVolume // navlib
{
	VectorWS m_vCenter; // 0x0078
	float32 m_flRadius; // 0x0084
};
class C_INIT_InitialRepulsionVelocity : public CParticleFunctionInitializer // particles
{
	char[128] m_CollisionGroupName; // 0x01E0
	ParticleTraceSet_t m_nTraceSet; // 0x0260
	Vector m_vecOutputMin; // 0x0264
	Vector m_vecOutputMax; // 0x0270
	int32 m_nControlPointNumber; // 0x027C
	bool m_bPerParticle; // 0x0280
	bool m_bTranslate; // 0x0281
	bool m_bProportional; // 0x0282
	float32 m_flTraceLength; // 0x0284
	bool m_bPerParticleTR; // 0x0288
	bool m_bInherit; // 0x0289
	int32 m_nChildCP; // 0x028C
	int32 m_nChildGroupID; // 0x0290
};
class C_INIT_InitialVelocityFromHitbox : public CParticleFunctionInitializer // particles
{
	float32 m_flVelocityMin; // 0x01E0
	float32 m_flVelocityMax; // 0x01E4
	int32 m_nControlPointNumber; // 0x01E8
	char[128] m_HitboxSetName; // 0x01EC
	bool m_bUseBones; // 0x026C
};
class C_INIT_RemapNamedModelBodyPartToScalar : public C_INIT_RemapNamedModelElementToScalar // particles
{
};
class CSndBeatPatternManager // soundsystem
{
	CUtlVector< CSndBeatPattern > m_vecPatterns; // 0x0038
	CUtlVector< CSndBeatTrack > m_vecActiveTracks; // 0x0070
};
class CNmScaleTask : public CNmPoseTask // animlib
{
};
class CMotionGraphConfig // animgraphlib
{
	float32[4] m_paramValues; // 0x0000
	float32 m_flDuration; // 0x0010
	MotionIndex m_nMotionIndex; // 0x0014
	int32 m_nSampleStart; // 0x0018
	int32 m_nSampleCount; // 0x001C
};
class CStateMachineInstanceData // animgraphlib
{
	float32 m_flTimeInState; // 0x0000
	CAnimNetVar< int32 > m_currentTransitionIndex; // 0x0004
	int32 m_prevStateIndex; // 0x0010
	int32 m_scheduledTransitionIndex; // 0x0014
};
class CAnimGraphSettingsManager // animgraphlib
{
	CUtlVector< CSmartPtr< CAnimGraphSettingsGroup > > m_settingsGroups; // 0x0018
};
class EngineLoopState_t // engine2
{
	int32 m_nPlatWindowWidth; // 0x0018
	int32 m_nPlatWindowHeight; // 0x001C
	int32 m_nRenderWidth; // 0x0020
	int32 m_nRenderHeight; // 0x0024
};
class AI_BaseNPCAnimGraph_DebugSnapshotData_t // server
{
	CGlobalSymbol e_action_desired; // 0x0000
	CGlobalSymbol e_action_handshake_restart; // 0x0008
	CGlobalSymbol e_action_handshake_body_authority_current; // 0x0010
	CGlobalSymbol e_action_handshake_body_authority_desired; // 0x0018
	CGlobalSymbol e_movement_type_desired; // 0x0020
	CGlobalSymbol e_movement_handshake_restart; // 0x0028
	CGlobalSymbol e_movement_handshake_body_authority_current; // 0x0030
	CGlobalSymbol e_movement_handshake_body_authority_desired; // 0x0038
};
class C_INIT_StatusEffect : public CParticleFunctionInitializer // particles
{
	Detail2Combo_t m_nDetail2Combo; // 0x01E0
	float32 m_flDetail2Rotation; // 0x01E4
	float32 m_flDetail2Scale; // 0x01E8
	float32 m_flDetail2BlendFactor; // 0x01EC
	float32 m_flColorWarpIntensity; // 0x01F0
	float32 m_flDiffuseWarpBlendToFull; // 0x01F4
	float32 m_flEnvMapIntensity; // 0x01F8
	float32 m_flAmbientScale; // 0x01FC
	Color m_specularColor; // 0x0200
	float32 m_flSpecularScale; // 0x0204
	float32 m_flSpecularExponent; // 0x0208
	float32 m_flSpecularExponentBlendToFull; // 0x020C
	float32 m_flSpecularBlendToFull; // 0x0210
	Color m_rimLightColor; // 0x0214
	float32 m_flRimLightScale; // 0x0218
	float32 m_flReflectionsTintByBaseBlendToNone; // 0x021C
	float32 m_flMetalnessBlendToFull; // 0x0220
	float32 m_flSelfIllumBlendToFull; // 0x0224
};
class C_OP_ColorInterpolate : public CParticleFunctionOperator // particles
{
	Color m_ColorFade; // 0x01D8
	float32 m_flFadeStartTime; // 0x01E8
	float32 m_flFadeEndTime; // 0x01EC
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01F0
	bool m_bEaseInOut; // 0x01F4
};
class C_OP_WindForce : public CParticleFunctionForce // particles
{
	Vector m_vForce; // 0x01E8
};
class CVoiceContainerRandomSampler : public CVoiceContainerAsyncGenerator // soundsystem_voicecontainers
{
	float32 m_flAmplitude; // 0x0080
	float32 m_flAmplitudeJitter; // 0x0084
	float32 m_flTimeJitter; // 0x0088
	float32 m_flMaxLength; // 0x008C
	int32 m_nNumDelayVariations; // 0x0090
	CUtlVector< CStrongHandle< InfoForResourceTypeCVoiceContainerBase > > m_grainResources; // 0x0098
};
class CVoiceContainerRealtimeFMSineWave : public CVoiceContainerGenerator // soundsystem_voicecontainers
{
	float32 m_flCarrierFrequency; // 0x0070
	float32 m_flModulatorFrequency; // 0x0074
	float32 m_flModulatorAmount; // 0x0078
};
class VPhysXConstraintParams_t // modellib
{
	int8 m_nType; // 0x0000
	int8 m_nTranslateMotion; // 0x0001
	int8 m_nRotateMotion; // 0x0002
	int8 m_nFlags; // 0x0003
	Vector[2] m_anchor; // 0x0004
	QuaternionStorage[2] m_axes; // 0x001C
	float32 m_maxForce; // 0x003C
	float32 m_maxTorque; // 0x0040
	float32 m_linearLimitValue; // 0x0044
	float32 m_linearLimitRestitution; // 0x0048
	float32 m_linearLimitSpring; // 0x004C
	float32 m_linearLimitDamping; // 0x0050
	float32 m_twistLowLimitValue; // 0x0054
	float32 m_twistLowLimitRestitution; // 0x0058
	float32 m_twistLowLimitSpring; // 0x005C
	float32 m_twistLowLimitDamping; // 0x0060
	float32 m_twistHighLimitValue; // 0x0064
	float32 m_twistHighLimitRestitution; // 0x0068
	float32 m_twistHighLimitSpring; // 0x006C
	float32 m_twistHighLimitDamping; // 0x0070
	float32 m_swing1LimitValue; // 0x0074
	float32 m_swing1LimitRestitution; // 0x0078
	float32 m_swing1LimitSpring; // 0x007C
	float32 m_swing1LimitDamping; // 0x0080
	float32 m_swing2LimitValue; // 0x0084
	float32 m_swing2LimitRestitution; // 0x0088
	float32 m_swing2LimitSpring; // 0x008C
	float32 m_swing2LimitDamping; // 0x0090
	Vector m_goalPosition; // 0x0094
	QuaternionStorage m_goalOrientation; // 0x00A0
	Vector m_goalAngularVelocity; // 0x00B0
	float32 m_driveSpringX; // 0x00BC
	float32 m_driveSpringY; // 0x00C0
	float32 m_driveSpringZ; // 0x00C4
	float32 m_driveDampingX; // 0x00C8
	float32 m_driveDampingY; // 0x00CC
	float32 m_driveDampingZ; // 0x00D0
	float32 m_driveSpringTwist; // 0x00D4
	float32 m_driveSpringSwing; // 0x00D8
	float32 m_driveSpringSlerp; // 0x00DC
	float32 m_driveDampingTwist; // 0x00E0
	float32 m_driveDampingSwing; // 0x00E4
	float32 m_driveDampingSlerp; // 0x00E8
	int32 m_solverIterationCount; // 0x00EC
	float32 m_projectionLinearTolerance; // 0x00F0
	float32 m_projectionAngularTolerance; // 0x00F4
};
class CPulseRuntimeMethodArg // pulse_runtime_lib
{
	CKV3MemberNameWithStorage m_Name; // 0x0000
	CUtlString m_Description; // 0x0038
	CPulseValueFullType m_Type; // 0x0040
};
class ManifestTestResource_t // resourcesystem
{
	CUtlString m_name; // 0x0000
	CStrongHandle< InfoForResourceTypeManifestTestResource_t > m_child; // 0x0008
};
class C_OP_DifferencePreviousParticle : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldInput; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
	float32 m_flInputMin; // 0x01E0
	float32 m_flInputMax; // 0x01E4
	float32 m_flOutputMin; // 0x01E8
	float32 m_flOutputMax; // 0x01EC
	ParticleSetMethod_t m_nSetMethod; // 0x01F0
	bool m_bActiveRange; // 0x01F4
	bool m_bSetPreviousParticle; // 0x01F5
};
class C_OP_RemapDirectionToCPToVector : public CParticleFunctionOperator // particles
{
	int32 m_nCP; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
	float32 m_flScale; // 0x01E0
	float32 m_flOffsetRot; // 0x01E4
	Vector m_vecOffsetAxis; // 0x01E8
	bool m_bNormalize; // 0x01F4
	ParticleAttributeIndex_t m_nFieldStrength; // 0x01F8
};
class C_INIT_DistanceToCPInit : public CParticleFunctionInitializer // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E0
	CPerParticleFloatInput m_flInputMin; // 0x01E8
	CPerParticleFloatInput m_flInputMax; // 0x0358
	CPerParticleFloatInput m_flOutputMin; // 0x04C8
	CPerParticleFloatInput m_flOutputMax; // 0x0638
	int32 m_nStartCP; // 0x07A8
	bool m_bLOS; // 0x07AC
	char[128] m_CollisionGroupName; // 0x07AD
	ParticleTraceSet_t m_nTraceSet; // 0x0830
	CPerParticleFloatInput m_flMaxTraceLength; // 0x0838
	float32 m_flLOSScale; // 0x09A8
	ParticleSetMethod_t m_nSetMethod; // 0x09AC
	bool m_bActiveRange; // 0x09B0
	Vector m_vecDistanceScale; // 0x09B4
	float32 m_flRemapBias; // 0x09C0
};
class CSteamAudioBakedDimensionsData // steamaudio
{
	SteamAudioCustomDataDimensionsSettings_t m_settings; // 0x0000
	CSteamAudioProbeData m_probes; // 0x0018
	CUtlVector< float32 > m_vecInOut; // 0x0020
	CUtlVector< float32 > m_vecSize; // 0x0038
	CUtlVector< CSteamAudioAmbisonicsField > m_vecOutsideField; // 0x0050
	CUtlVector< CSteamAudioAmbisonicsField > m_vecInsideSmallSizeField; // 0x0068
	CSteamAudioMovableBakedData< CSteamAudioBakedDimensionsData > m_movables; // 0x0080
};
class VMixPlateverbDesc_t // soundsystem_lowlevel
{
	float32 m_flPrefilter; // 0x0000
	float32 m_flInputDiffusion1; // 0x0004
	float32 m_flInputDiffusion2; // 0x0008
	float32 m_flDecay; // 0x000C
	float32 m_flDamp; // 0x0010
	float32 m_flFeedbackDiffusion1; // 0x0014
	float32 m_flFeedbackDiffusion2; // 0x0018
};
class RnBlendVertex_t // physicslib
{
	uint16 m_nWeight0; // 0x0000
	uint16 m_nIndex0; // 0x0002
	uint16 m_nWeight1; // 0x0004
	uint16 m_nIndex1; // 0x0006
	uint16 m_nWeight2; // 0x0008
	uint16 m_nIndex2; // 0x000A
	uint16 m_nFlags; // 0x000C
	uint16 m_nTargetIndex; // 0x000E
};
class CSequenceUpdateNodeBase : public CLeafUpdateNode // animgraphlib
{
	float32 m_playbackSpeed; // 0x006C
	bool m_bLoop; // 0x0070
};
class PulseGraphExecutionHistoryNodeDesc_t // pulse_runtime_lib
{
	CBufferString strCellDesc; // 0x0000
	PulseSymbol_t strBindingName; // 0x0010
};
class InfoForResourceTypeCVDataResource // resourcesystem
{
};
class FloatInputMaterialVariable_t // particles
{
	CUtlString m_strVariable; // 0x0000
	CParticleCollectionFloatInput m_flInput; // 0x0008
};
class MaterialOverride_t : public BaseSceneObjectOverride_t // worldrenderer
{
	uint32 m_nSubSceneObject; // 0x0004
	uint32 m_nDrawCallIndex; // 0x0008
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_pMaterial; // 0x0010
	Vector m_vLinearTintColor; // 0x0018
};
class CNmReferencePoseTask : public CNmPoseTask // animlib
{
};
class CSymbolAnimParameter : public CConcreteAnimParameter // animgraphlib
{
	CGlobalSymbol m_defaultValue; // 0x0080
};
class PARTICLE_EHANDLE__ // particleslib
{
	int32 unused; // 0x0000
};
class PostProcessingResource_t // materialsystem2
{
	bool m_bHasTonemapParams; // 0x0000
	PostProcessingTonemapParameters_t m_toneMapParams; // 0x0004
	bool m_bHasBloomParams; // 0x0040
	PostProcessingBloomParameters_t m_bloomParams; // 0x0044
	bool m_bHasVignetteParams; // 0x00CC
	PostProcessingVignetteParameters_t m_vignetteParams; // 0x00D0
	bool m_bHasLocalContrastParams; // 0x00F4
	PostProcessingLocalContrastParameters_t m_localConstrastParams; // 0x00F8
	int32 m_nColorCorrectionVolumeDim; // 0x010C
	CUtlBinaryBlock m_colorCorrectionVolumeData; // 0x0110
	bool m_bHasColorCorrection; // 0x0120
	bool m_bHasFogScatteringParams; // 0x0121
	PostProcessingFogScatteringParameters_t m_fogScatteringParams; // 0x0124
	bool m_bHasLocalExposureParams; // 0x0144
	PostProcessingLocalExposureParameters_t m_localExposureParams; // 0x0148
};
class C_INIT_RandomVector : public CParticleFunctionInitializer // particles
{
	Vector m_vecMin; // 0x01E0
	Vector m_vecMax; // 0x01EC
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01F8
	CRandomNumberGeneratorParameters m_randomnessParameters; // 0x01FC
};
class C_OP_TimeVaryingForce : public CParticleFunctionForce // particles
{
	float32 m_flStartLerpTime; // 0x01E8
	Vector m_StartingForce; // 0x01EC
	float32 m_flEndLerpTime; // 0x01F8
	Vector m_EndingForce; // 0x01FC
};
class C_INIT_ScaleVelocity : public CParticleFunctionInitializer // particles
{
	CParticleCollectionVecInput m_vecScale; // 0x01E0
};
class CVoiceContainerSetElement // soundsystem_voicecontainers
{
	CSoundContainerReference m_sound; // 0x0000
	float32 m_flVolumeDB; // 0x0020
};
class VMixDiffusorDesc_t // soundsystem_lowlevel
{
	float32 m_flSize; // 0x0000
	float32 m_flComplexity; // 0x0004
	float32 m_flFeedback; // 0x0008
	float32 m_flOutputGain; // 0x000C
};
class AnimStateID // modellib
{
	uint32 m_id; // 0x0000
};
class CNmIDToFloatNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	float32 m_defaultValue; // 0x0014
	CUtlLeanVectorFixedGrowable< CGlobalSymbol, 5 > m_IDs; // 0x0018
	CUtlLeanVectorFixedGrowable< float32, 5 > m_values; // 0x0048
};
class CStateNodeStateData // animgraphlib
{
	CAnimUpdateNodeRef m_pChild; // 0x0000
	bitfield:1 m_bExclusiveRootMotion; // 0x0000
	bitfield:1 m_bExclusiveRootMotionFirstFrame; // 0x0000
};
class CMoodVData // animationsystem
{
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCModel > > m_sModelName; // 0x0000
	MoodType_t m_nMoodType; // 0x00E0
	CUtlVector< MoodAnimationLayer_t > m_animationLayers; // 0x00E8
};
class CVoiceContainerAnalysisBase // soundsystem_voicecontainers
{
	CPiecewiseCurve m_curve; // 0x0008
};
class CSoundInfoHeader // soundsystem_voicecontainers
{
};
class RnSoftbodySpring_t // physicslib
{
	uint16[2] m_nParticle; // 0x0000
	float32 m_flLength; // 0x0004
};
class CChoiceInstanceData // animgraphlib
{
	CAnimNetVar< int32 > m_currentChoice; // 0x0010
	int32 m_previousChoice; // 0x001C
	CAnimNetVar< float32 > m_flClipStartTime; // 0x0020
	float32 m_choicePreviousCycle; // 0x002C
};
class C_OP_MovementPlaceOnGround : public CParticleFunctionOperator // particles
{
	CPerParticleFloatInput m_flOffset; // 0x01D8
	float32 m_flMaxTraceLength; // 0x0348
	float32 m_flTolerance; // 0x034C
	CPerParticleVecInput m_vecTraceDir; // 0x0350
	float32 m_flTraceOffset; // 0x0A08
	float32 m_flLerpRate; // 0x0A0C
	char[128] m_CollisionGroupName; // 0x0A10
	ParticleTraceSet_t m_nTraceSet; // 0x0A90
	int32 m_nRefCP1; // 0x0A94
	int32 m_nRefCP2; // 0x0A98
	int32 m_nLerpCP; // 0x0A9C
	ParticleTraceMissBehavior_t m_nTraceMissBehavior; // 0x0AA8
	bool m_bIncludeShotHull; // 0x0AAC
	bool m_bIncludeWater; // 0x0AAD
	bool m_bSetNormal; // 0x0AB0
	bool m_bScaleOffset; // 0x0AB1
	int32 m_nPreserveOffsetCP; // 0x0AB4
	int32 m_nIgnoreCP; // 0x0AB8
};
class CVoiceContainerLoopTrigger : public CVoiceContainerBase // soundsystem_voicecontainers
{
	float32 m_flRetriggerTimeMin; // 0x0070
	float32 m_flRetriggerTimeMax; // 0x0074
	float32 m_flFadeTime; // 0x0078
	bool m_bCrossFade; // 0x007C
	CSoundContainerReference m_sound; // 0x0080
};
class RnMeshDesc_t : public RnShapeDesc_t // physicslib
{
	RnMesh_t m_Mesh; // 0x0018
};
class CNmStateNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
	int16 m_nChildNodeIdx; // 0x0010
	CUtlLeanVectorFixedGrowable< CGlobalSymbol, 3 > m_entryEvents; // 0x0018
	CUtlLeanVectorFixedGrowable< CGlobalSymbol, 3 > m_executeEvents; // 0x0038
	CUtlLeanVectorFixedGrowable< CGlobalSymbol, 3 > m_exitEvents; // 0x0058
	CUtlLeanVectorFixedGrowable< CNmStateNode::TimedEvent_t, 1 > m_timedRemainingEvents; // 0x0078
	CUtlLeanVectorFixedGrowable< CNmStateNode::TimedEvent_t, 1 > m_timedElapsedEvents; // 0x0090
	int16 m_nLayerWeightNodeIdx; // 0x00A8
	int16 m_nLayerRootMotionWeightNodeIdx; // 0x00AA
	int16 m_nLayerBoneMaskNodeIdx; // 0x00AC
	bool m_bIsOffState; // 0x00AE
	bool m_bUseActualElapsedTimeInStateForTimedEvents; // 0x00AF
};
class CPairedSequenceComponentUpdater : public CAnimComponentUpdater // animgraphlib
{
};
class CCycleControlClipUpdateNode : public CLeafUpdateNode // animgraphlib
{
	CUtlVector< TagSpan_t > m_tags; // 0x0060
	HSequence m_hSequence; // 0x007C
	float32 m_duration; // 0x0080
	AnimValueSource m_valueSource; // 0x0084
	CAnimParamHandle m_paramIndex; // 0x0088
	bool m_bLockWhenWaning; // 0x008A
};
class CNetworkTransmitComponent // server
{
	uint8 m_nTransmitStateOwnedCounter; // 0x0184
};
class ragdollelement_t // server
{
	Vector originParentSpace; // 0x0000
	int32 parentIndex; // 0x0020
	float32 m_flRadius; // 0x0024
	int32 m_nHeight; // 0x0028
};
class C_OP_RenderScreenVelocityRotate : public CParticleFunctionRenderer // particles
{
	float32 m_flRotateRateDegrees; // 0x0228
	float32 m_flForwardDegrees; // 0x022C
};
class CNmFrameSnapEvent : public CNmEvent // animlib
{
	NmFrameSnapEventMode_t m_frameSnapMode; // 0x0018
};
class FootPinningPoseOpFixedData_t // animgraphlib
{
	CUtlVector< FootFixedData_t > m_footInfo; // 0x0000
	float32 m_flBlendTime; // 0x0018
	float32 m_flLockBreakDistance; // 0x001C
	float32 m_flMaxLegTwist; // 0x0020
	int32 m_nHipBoneIndex; // 0x0024
	bool m_bApplyLegTwistLimits; // 0x0028
	bool m_bApplyFootRotationLimits; // 0x0029
};
class CollisionGroupContext_t // particles
{
	int32 m_nCollisionGroupNumber; // 0x0000
};
class C_OP_SetControlPointPositionToTimeOfDayValue : public CParticleFunctionPreEmission // particles
{
	int32 m_nControlPointNumber; // 0x01E0
	char[128] m_pszTimeOfDayParameter; // 0x01E4
	Vector m_vecDefaultValue; // 0x0264
};
class C_INIT_RandomNamedModelMeshGroup : public C_INIT_RandomNamedModelElement // particles
{
};
class SndBeatEventKeys_t // soundsystem
{
	float32 m_flKey; // 0x0008
};
class CNmReferencedGraphNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
	int16 m_nReferencedGraphIdx; // 0x0010
	int16 m_nFallbackNodeIdx; // 0x0012
};
class CNmChainLookatNode::CDefinition : public CNmPassthroughNode::CDefinition // animlib
{
	CGlobalSymbol m_endEffectorBoneID; // 0x0018
	Vector m_endEffectorForwardAxis; // 0x0020
	Vector m_endEffectorOffset; // 0x002C
	int16 m_nLookatTargetNodeIdx; // 0x0038
	int16 m_nEnabledNodeIdx; // 0x003A
	float32 m_flBlendTimeSeconds; // 0x003C
	CUtlVectorFixedGrowable< float32, 5 > m_chainWeights; // 0x0040
	uint8 m_nChainLength; // 0x0070
	bool m_bIsTargetInWorldSpace; // 0x0071
};
class CNmGraphEventConditionNode::Condition_t // animlib
{
	CGlobalSymbol m_eventID; // 0x0000
	NmGraphEventTypeCondition_t m_eventTypeCondition; // 0x0008
};
class SkeletonBoneBounds_t // modellib
{
	Vector m_vecCenter; // 0x0000
	Vector m_vecSize; // 0x000C
};
class inv_image_camera_t // client
{
	QAngle angle; // 0x0000
	float32 fov; // 0x000C
	float32 znear; // 0x0010
	float32 zfar; // 0x0014
	Vector target; // 0x0018
	Vector target_nudge; // 0x0024
	float32 orbit_distance; // 0x0030
};
class CCopyRecipientFilter // server
{
	int32 m_Flags; // 0x0008
	CUtlVector< CPlayerSlot > m_Recipients; // 0x0010
	CPlayerSlot m_slotPlayerExcludedDueToPrediction; // 0x0030
};
class C_OP_ConstrainLineLength : public CParticleFunctionConstraint // particles
{
	float32 m_flMinDistance; // 0x01D8
	float32 m_flMaxDistance; // 0x01DC
};
class C_OP_RemapParticleCountOnScalarEndCap : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	int32 m_nInputMin; // 0x01DC
	int32 m_nInputMax; // 0x01E0
	float32 m_flOutputMin; // 0x01E4
	float32 m_flOutputMax; // 0x01E8
	bool m_bBackwards; // 0x01EC
	ParticleSetMethod_t m_nSetMethod; // 0x01F0
};
class C_INIT_RemapTransformToVector : public CParticleFunctionInitializer // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E0
	Vector m_vInputMin; // 0x01E4
	Vector m_vInputMax; // 0x01F0
	Vector m_vOutputMin; // 0x01FC
	Vector m_vOutputMax; // 0x0208
	CParticleTransformInput m_TransformInput; // 0x0218
	CParticleTransformInput m_LocalSpaceTransform; // 0x0280
	float32 m_flStartTime; // 0x02E8
	float32 m_flEndTime; // 0x02EC
	ParticleSetMethod_t m_nSetMethod; // 0x02F0
	bool m_bOffset; // 0x02F4
	bool m_bAccelerate; // 0x02F5
	float32 m_flRemapBias; // 0x02F8
};
class VPhysEntityId_t // vphysics2
{
	uint32 m_Id; // 0x0000
};
class CBlend2DUpdateNode : public CAnimUpdateNodeBase // animgraphlib
{
	CUtlVector< BlendItem_t > m_items; // 0x0060
	CUtlVector< TagSpan_t > m_tags; // 0x0078
	CParamSpanUpdater m_paramSpans; // 0x0090
	CUtlVector< int32 > m_nodeItemIndices; // 0x00A8
	CAnimInputDamping m_damping; // 0x00C0
	AnimValueSource m_blendSourceX; // 0x00D8
	CAnimParamHandle m_paramX; // 0x00DC
	AnimValueSource m_blendSourceY; // 0x00E0
	CAnimParamHandle m_paramY; // 0x00E4
	Blend2DMode m_eBlendMode; // 0x00E8
	float32 m_playbackSpeed; // 0x00EC
	bool m_bLoop; // 0x00F0
	bool m_bLockBlendOnReset; // 0x00F1
	bool m_bLockWhenWaning; // 0x00F2
	bool m_bAnimEventsAndTagsOnMostWeightedOnly; // 0x00F3
};
class CNmSyncEventIndexConditionNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	int16 m_nSourceStateNodeIdx; // 0x0010
	CNmSyncEventIndexConditionNode::TriggerMode_t m_triggerMode; // 0x0012
	int32 m_syncEventIdx; // 0x0014
};
class CSpeedScaleUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	CAnimParamHandle m_paramIndex; // 0x0070
};
class CPulse_Variable // pulse_runtime_lib
{
	PulseSymbol_t m_Name; // 0x0000
	CUtlString m_Description; // 0x0010
	CPulseValueFullType m_Type; // 0x0018
	KeyValues3 m_DefaultValue; // 0x0030
	PulseVariableKeysSource_t m_nKeysSource; // 0x0044
	bool m_bIsPublicBlackboardVariable; // 0x0048
	bool m_bIsObservable; // 0x0049
	PulseDocNodeID_t m_nEditorNodeID; // 0x004C
	KeyValues3 m_Metadata; // 0x0050
};
class AnimTagID // modellib
{
	uint32 m_id; // 0x0000
};
class ParticleNode_t // server
{
	CHandle< CBaseEntity > m_hEntity; // 0x0000
	ParticleIndex_t m_iIndex; // 0x0004
	GameTime_t m_flStartTime; // 0x0008
	float32 m_flGrowthDuration; // 0x000C
	VectorWS m_vecGrowthOrigin; // 0x0010
	float32 m_flEndcapTime; // 0x001C
	bool m_bMarkedForDelete; // 0x0020
};
class CResponseCriteriaSet // server
{
	int32 m_nNumPrefixedContexts; // 0x0030
	bool m_bOverrideOnAppend; // 0x0034
};
class C_OP_RenderStandardLight : public CParticleFunctionRenderer // particles
{
	ParticleLightTypeChoiceList_t m_nLightType; // 0x0228
	uint16 m_nMaxAllowed; // 0x022C
	CParticleCollectionVecInput m_vecColorScale; // 0x0230
	ParticleColorBlendType_t m_nColorBlendType; // 0x08E8
	CUtlString m_strLightStyle; // 0x08F0
	CPerParticleFloatInput m_flLightStyleTime; // 0x08F8
	CPerParticleFloatInput m_flIntensity; // 0x0A68
	bool m_bCastShadows; // 0x0BD8
	bool m_bDynamicBounce; // 0x0BD9
	CParticleCollectionFloatInput m_flBounceScale; // 0x0BE0
	CParticleCollectionFloatInput m_flTheta; // 0x0D50
	CParticleCollectionFloatInput m_flPhi; // 0x0EC0
	CParticleCollectionFloatInput m_flRadiusMultiplier; // 0x1030
	StandardLightingAttenuationStyle_t m_nAttenuationStyle; // 0x11A0
	CParticleCollectionFloatInput m_flFalloffLinearity; // 0x11A8
	CParticleCollectionFloatInput m_flFiftyPercentFalloff; // 0x1318
	CParticleCollectionFloatInput m_flZeroPercentFalloff; // 0x1488
	bool m_bRenderDiffuse; // 0x15F8
	bool m_bRenderSpecular; // 0x15F9
	CUtlString m_lightCookie; // 0x1600
	int32 m_nPriority; // 0x1608
	ParticleLightFogLightingMode_t m_nFogLightingMode; // 0x160C
	CParticleCollectionRendererFloatInput m_flFogContribution; // 0x1610
	ParticleLightBehaviorChoiceList_t m_nCapsuleLightBehavior; // 0x1780
	float32 m_flCapsuleLength; // 0x1784
	bool m_bReverseOrder; // 0x1788
	bool m_bClosedLoop; // 0x1789
	ParticleAttributeIndex_t m_nPrevPntSource; // 0x178C
	float32 m_flMaxLength; // 0x1790
	float32 m_flMinLength; // 0x1794
	bool m_bIgnoreDT; // 0x1798
	float32 m_flConstrainRadiusToLengthRatio; // 0x179C
	float32 m_flLengthScale; // 0x17A0
	float32 m_flLengthFadeInTime; // 0x17A4
};
class C_OP_RenderLightBeam : public CParticleFunctionRenderer // particles
{
	uint16 m_nMaxAllowed; // 0x0228
	CParticleCollectionVecInput m_vColorBlend; // 0x0230
	ParticleColorBlendType_t m_nColorBlendType; // 0x08E8
	CUtlString m_strLightStyle; // 0x08F0
	CPerParticleFloatInput m_flLightStyleTime; // 0x08F8
	CParticleCollectionFloatInput m_flBrightnessLumensPerMeter; // 0x0A68
	CParticleCollectionFloatInput m_flNumberOfLightsToCreate; // 0x0BD8
	bool m_bCastShadows; // 0x0D48
	bool m_bDynamicBounce; // 0x0D49
	CParticleCollectionFloatInput m_flBounceScale; // 0x0D50
	CParticleCollectionFloatInput m_flSkirt; // 0x0EC0
	CParticleCollectionFloatInput m_flRange; // 0x1030
	CParticleCollectionFloatInput m_flThickness; // 0x11A0
	CParticleCollectionFloatInput m_flInnerConeAngle; // 0x1310
	CParticleCollectionFloatInput m_flOuterConeAngle; // 0x1480
	CParticleCollectionVecInput m_vecConeRotationOffset; // 0x15F0
	ParticleLightFogLightingMode_t m_nFogLightingMode; // 0x1CA8
	CParticleCollectionRendererFloatInput m_flFogContribution; // 0x1CB0
	CPerParticleFloatInput m_flRenderFilter; // 0x1E20
	bool m_bDebugOrientation; // 0x1F90
};
class CSeqSeqDescFlag // animationsystem
{
	bool m_bLooping; // 0x0000
	bool m_bSnap; // 0x0001
	bool m_bAutoplay; // 0x0002
	bool m_bPost; // 0x0003
	bool m_bHidden; // 0x0004
	bool m_bMulti; // 0x0005
	bool m_bLegacyDelta; // 0x0006
	bool m_bLegacyWorldspace; // 0x0007
	bool m_bLegacyCyclepose; // 0x0008
	bool m_bLegacyRealtime; // 0x0009
	bool m_bModelDoc; // 0x000A
};
class CStateNodeTransitionData // animgraphlib
{
	CBlendCurve m_curve; // 0x0000
	CAnimValue< float32 > m_blendDuration; // 0x0008
	CAnimValue< float32 > m_resetCycleValue; // 0x0010
	bitfield:1 m_bReset; // 0x0000
	bitfield:3 m_resetCycleOption; // 0x0000
};
class CToggleComponentActionUpdater : public CAnimActionUpdater // animgraphlib
{
	AnimComponentID m_componentID; // 0x0018
	bool m_bSetEnabled; // 0x001C
};
class CNmFootstepEventIDNode::CDefinition : public CNmIDValueNode::CDefinition // animlib
{
	int16 m_nSourceStateNodeIdx; // 0x0010
	CNmBitFlags m_eventConditionRules; // 0x0014
};
class CNmStateMachineNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
	CUtlLeanVectorFixedGrowable< CNmStateMachineNode::StateDefinition_t, 5 > m_stateDefinitions; // 0x0010
	int16 m_nDefaultStateIndex; // 0x0130
};
class CFuseProgram // mathlib_extended
{
	CUtlVector< uint8 > m_programBuffer; // 0x0000
	CUtlVector< FuseVariableIndex_t > m_variablesRead; // 0x0018
	CUtlVector< FuseVariableIndex_t > m_variablesWritten; // 0x0030
	int32 m_nMaxTempVarsUsed; // 0x0048
};
class CAI_Expresser // server
{
	CUtlDict< GameTime_t > m_conceptCooldowns; // 0x0010
	CUtlDict< GameTime_t > m_ruleCooldowns; // 0x0038
	GameTime_t m_flStopTalkTime; // 0x0060
	GameTime_t m_flStopTalkTimeWithoutDelay; // 0x0064
	GameTime_t m_flQueuedSpeechTime; // 0x0068
	GameTime_t m_flBlockedTalkTime; // 0x006C
	int32 m_voicePitch; // 0x0070
	GameTime_t m_flLastTimeAcceptedSpeak; // 0x0074
	bool m_bAllowSpeakingInterrupts; // 0x0078
	bool m_bConsiderSceneInvolvementAsSpeech; // 0x0079
	bool m_bSceneEntityDisabled; // 0x007A
	int32 m_nLastSpokenPriority; // 0x007C
	CBaseModelEntity* m_pOuter; // 0x0098
};
class ModelConfigHandle_t // server
{
	uint32 m_Value; // 0x0000
};
class C_OP_DriveCPFromGlobalSoundFloat : public CParticleFunctionPreEmission // particles
{
	int32 m_nOutputControlPoint; // 0x01E0
	int32 m_nOutputField; // 0x01E4
	float32 m_flInputMin; // 0x01E8
	float32 m_flInputMax; // 0x01EC
	float32 m_flOutputMin; // 0x01F0
	float32 m_flOutputMax; // 0x01F4
	CUtlString m_StackName; // 0x01F8
	CUtlString m_OperatorName; // 0x0200
	CUtlString m_FieldName; // 0x0208
};
class World_t // worldrenderer
{
	WorldBuilderParams_t m_builderParams; // 0x0000
	CUtlVector< NodeData_t > m_worldNodes; // 0x0060
	BakedLightingInfo_t m_worldLightingInfo; // 0x0078
	CUtlVector< CStrongHandleCopyable< InfoForResourceTypeCEntityLump > > m_entityLumps; // 0x00C0
};
class CCachedPose // animgraphlib
{
	CUtlVector< CTransform > m_transforms; // 0x0008
	CUtlVector< float32 > m_morphWeights; // 0x0020
	HSequence m_hSequence; // 0x0038
	float32 m_flCycle; // 0x003C
};
class ConfigIndex // animgraphlib
{
	uint16 m_nGroup; // 0x0000
	uint16 m_nConfig; // 0x0002
};
class PulseGraphInstanceID_t // pulse_runtime_lib
{
	uint32 m_Value; // 0x0000
};
class CMaterialAttributeAnimTag : public CAnimTagBase // animgraphlib
{
	CUtlString m_AttributeName; // 0x0058
	MatterialAttributeTagType_t m_AttributeType; // 0x0060
	float32 m_flValue; // 0x0064
	Color m_Color; // 0x0068
};
class EventClientAdvanceNonRenderedFrame_t // engine2
{
};
class CMovementStatsProperty // server
{
	int32 m_nUseCounter; // 0x0010
	CVectorExponentialMovingAverage m_emaMovementDirection; // 0x0014
};
class C_OP_RemapControlPointDirectionToVector : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	float32 m_flScale; // 0x01DC
	int32 m_nControlPointNumber; // 0x01E0
};
class C_OP_ScreenSpacePositionOfTarget : public CParticleFunctionOperator // particles
{
	CPerParticleVecInput m_vecTargetPosition; // 0x01D8
	bool m_bOututBehindness; // 0x0890
	ParticleAttributeIndex_t m_nBehindFieldOutput; // 0x0894
	CParticleRemapFloatInput m_flBehindOutputRemap; // 0x0898
	ParticleSetMethod_t m_nBehindSetMethod; // 0x0A08
};
class C_INIT_PositionOffset : public CParticleFunctionInitializer // particles
{
	CPerParticleVecInput m_OffsetMin; // 0x01E0
	CPerParticleVecInput m_OffsetMax; // 0x0898
	CParticleTransformInput m_TransformInput; // 0x0F50
	bool m_bLocalCoords; // 0x0FB8
	bool m_bProportional; // 0x0FB9
	CRandomNumberGeneratorParameters m_randomnessParameters; // 0x0FBC
};
class C_OP_ChladniWave : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	CPerParticleFloatInput m_flInputMin; // 0x01E0
	CPerParticleFloatInput m_flInputMax; // 0x0350
	CPerParticleFloatInput m_flOutputMin; // 0x04C0
	CPerParticleFloatInput m_flOutputMax; // 0x0630
	CPerParticleVecInput m_vecWaveLength; // 0x07A0
	CPerParticleVecInput m_vecHarmonics; // 0x0E58
	ParticleSetMethod_t m_nSetMethod; // 0x1510
	int32 m_nLocalSpaceControlPoint; // 0x1514
	bool m_b3D; // 0x1518
};
class AnimationSnapshotBase_t // animationsystem
{
	float32 m_flRealTime; // 0x0000
	matrix3x4a_t m_rootToWorld; // 0x0010
	bool m_bBonesInWorldSpace; // 0x0040
	CUtlVector< uint32 > m_boneSetupMask; // 0x0048
	CUtlVector< matrix3x4a_t > m_boneTransforms; // 0x0060
	CUtlVector< float32 > m_flexControllers; // 0x0078
	AnimationSnapshotType_t m_SnapshotType; // 0x0090
	bool m_bHasDecodeDump; // 0x0094
	AnimationDecodeDebugDumpElement_t m_DecodeDump; // 0x0098
};
class CNmTwoBoneIKNode::CDefinition : public CNmPassthroughNode::CDefinition // animlib
{
	CGlobalSymbol m_effectorBoneID; // 0x0018
	int16 m_nEffectorTargetNodeIdx; // 0x0020
	int16 m_nEnabledNodeIdx; // 0x0022
	float32 m_flBlendTimeSeconds; // 0x0024
	NmIKBlendMode_t m_blendMode; // 0x0028
	bool m_bIsTargetInWorldSpace; // 0x0029
	float32 m_flChainRotationWeight; // 0x002C
};
class CNmSoundEvent : public CNmEvent // animlib
{
	CNmEventRelevance_t m_relevance; // 0x0018
	CUtlString m_name; // 0x0020
	CNmSoundEvent::Position_t m_position; // 0x0028
	CUtlString m_attachmentName; // 0x0030
	CUtlString m_tags; // 0x0038
	bool m_bContinuePlayingSoundAtDurationEnd; // 0x0040
	float32 m_flDurationInterruptionThreshold; // 0x0044
};
class CBoneMaskUpdateNode : public CBinaryUpdateNode // animgraphlib
{
	int32 m_nWeightListIndex; // 0x0094
	float32 m_flRootMotionBlend; // 0x0098
	BoneMaskBlendSpace m_blendSpace; // 0x009C
	BinaryNodeChildOption m_footMotionTiming; // 0x00A0
	bool m_bUseBlendScale; // 0x00A4
	AnimValueSource m_blendValueSource; // 0x00A8
	CAnimParamHandle m_hBlendParameter; // 0x00AC
};
class CCommentarySystem // server
{
	bool m_bCommentaryEnabledMidGame; // 0x0012
	GameTime_t m_flNextTeleportTime; // 0x0014
	int32 m_iTeleportStage; // 0x0018
	bool m_bCheatState; // 0x001C
	bool m_bIsFirstSpawnGroupToLoad; // 0x001D
	CUtlVector< modifiedconvars_t > m_ModifiedConvars; // 0x0020
	CHandle< CPointCommentaryNode > m_hCurrentNode; // 0x0038
	CHandle< CPointCommentaryNode > m_hActiveCommentaryNode; // 0x003C
	CHandle< CPointCommentaryNode > m_hLastCommentaryNode; // 0x0040
	CUtlVector< CHandle< CPointCommentaryNode > > m_vecNodes; // 0x0048
};
class FeFitMatrix_t // physicslib
{
	CTransform bone; // 0x0000
	Vector vCenter; // 0x0020
	uint16 nEnd; // 0x002C
	uint16 nNode; // 0x002E
	uint16 nBeginDynamic; // 0x0030
};
class CCPPScriptComponentUpdater : public CAnimComponentUpdater // animgraphlib
{
	CUtlVector< CGlobalSymbol > m_scriptsToRun; // 0x0030
};
class PostProcessingLocalContrastParameters_t // materialsystem2
{
	float32 m_flLocalContrastStrength; // 0x0000
	float32 m_flLocalContrastEdgeStrength; // 0x0004
	float32 m_flLocalContrastVignetteStart; // 0x0008
	float32 m_flLocalContrastVignetteEnd; // 0x000C
	float32 m_flLocalContrastVignetteBlur; // 0x0010
};
class dynpitchvol_base_t // server
{
	int32 preset; // 0x0000
	int32 pitchrun; // 0x0004
	int32 pitchstart; // 0x0008
	int32 spinup; // 0x000C
	int32 spindown; // 0x0010
	int32 volrun; // 0x0014
	int32 volstart; // 0x0018
	int32 fadein; // 0x001C
	int32 fadeout; // 0x0020
	int32 lfotype; // 0x0024
	int32 lforate; // 0x0028
	int32 lfomodpitch; // 0x002C
	int32 lfomodvol; // 0x0030
	int32 cspinup; // 0x0034
	int32 cspincount; // 0x0038
	int32 pitch; // 0x003C
	int32 spinupsav; // 0x0040
	int32 spindownsav; // 0x0044
	int32 pitchfrac; // 0x0048
	int32 vol; // 0x004C
	int32 fadeinsav; // 0x0050
	int32 fadeoutsav; // 0x0054
	int32 volfrac; // 0x0058
	int32 lfofrac; // 0x005C
	int32 lfomult; // 0x0060
};
class C_OP_DistanceBetweenTransforms : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	CParticleTransformInput m_TransformStart; // 0x01E0
	CParticleTransformInput m_TransformEnd; // 0x0248
	CPerParticleFloatInput m_flInputMin; // 0x02B0
	CPerParticleFloatInput m_flInputMax; // 0x0420
	CPerParticleFloatInput m_flOutputMin; // 0x0590
	CPerParticleFloatInput m_flOutputMax; // 0x0700
	float32 m_flMaxTraceLength; // 0x0870
	float32 m_flLOSScale; // 0x0874
	char[128] m_CollisionGroupName; // 0x0878
	ParticleTraceSet_t m_nTraceSet; // 0x08F8
	bool m_bLOS; // 0x08FC
	ParticleSetMethod_t m_nSetMethod; // 0x0900
};
class C_INIT_SequenceLifeTime : public CParticleFunctionInitializer // particles
{
	float32 m_flFramerate; // 0x01E0
};
class C_INIT_RandomNamedModelBodyPart : public C_INIT_RandomNamedModelElement // particles
{
};
class C_OP_RemapModelVolumetoCP : public CParticleFunctionPreEmission // particles
{
	BBoxVolumeType_t m_nBBoxType; // 0x01E0
	int32 m_nInControlPointNumber; // 0x01E4
	int32 m_nOutControlPointNumber; // 0x01E8
	int32 m_nOutControlPointMaxNumber; // 0x01EC
	int32 m_nField; // 0x01F0
	float32 m_flInputMin; // 0x01F4
	float32 m_flInputMax; // 0x01F8
	float32 m_flOutputMin; // 0x01FC
	float32 m_flOutputMax; // 0x0200
	bool m_bBBoxOnly; // 0x0204
	bool m_bCubeRoot; // 0x0205
};
class C_OP_LerpEndCapScalar : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	float32 m_flOutput; // 0x01DC
	float32 m_flLerpTime; // 0x01E0
};
class CVMixGraphDescData // soundsystem_lowlevel
{
	CUtlString m_name; // 0x0000
	int32 m_nGraphOutputChannels; // 0x0008
	bool m_bIsMainGraph; // 0x000C
};
class FeBoxRigid_t // physicslib
{
	CTransform tmFrame2; // 0x0000
	uint16 nNode; // 0x0020
	uint16 nCollisionMask; // 0x0022
	Vector vSize; // 0x0024
	uint16 nVertexMapIndex; // 0x0030
	uint16 nFlags; // 0x0032
};
class PulseRuntimeBlackboardReferenceIndex_t // pulse_runtime_lib
{
	int16 m_Value; // 0x0000
};
class CNmVirtualParameterIDNode::CDefinition : public CNmIDValueNode::CDefinition // animlib
{
	int16 m_nChildNodeIdx; // 0x0010
};
class CNavFlags // navlib
{
	uint64 m_Flags; // 0x0000
};
class C_OP_CreateParticleSystemRenderer : public CParticleFunctionRenderer // particles
{
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_hEffect; // 0x0228
	EventTypeSelection_t m_nEventType; // 0x0230
	CUtlLeanVector< CPAssignment_t > m_vecCPs; // 0x0238
	CUtlString m_szParticleConfig; // 0x0248
	CPerParticleVecInput m_AggregationPos; // 0x0250
};
class VMixVocoderDesc_t // soundsystem_lowlevel
{
	int32 m_nBandCount; // 0x0000
	float32 m_flBandwidth; // 0x0004
	float32 m_fldBModGain; // 0x0008
	float32 m_flFreqRangeStart; // 0x000C
	float32 m_flFreqRangeEnd; // 0x0010
	float32 m_fldBUnvoicedGain; // 0x0014
	float32 m_flAttackTimeMS; // 0x0018
	float32 m_flReleaseTimeMS; // 0x001C
	int32 m_nDebugBand; // 0x0020
	bool m_bPeakMode; // 0x0024
};
class RnVertex_t // physicslib
{
	uint8 m_nEdge; // 0x0000
};
class FollowAttachmentSettings_t // animgraphlib
{
	CAnimAttachment m_attachment; // 0x0000
	int32 m_boneIndex; // 0x0080
	AttachmentHandle_t m_attachmentHandle; // 0x0084
	bool m_bMatchTranslation; // 0x0085
	bool m_bMatchRotation; // 0x0086
};
class CNmSpeedScaleNode::CDefinition : public CNmSpeedScaleBaseNode::CDefinition // animlib
{
};
class EventPostDataUpdate_t // engine2
{
	int32 m_nCount; // 0x0000
};
class C_INIT_NormalAlignToCP : public CParticleFunctionInitializer // particles
{
	CParticleTransformInput m_transformInput; // 0x01E0
	ParticleControlPointAxis_t m_nControlPointAxis; // 0x0248
};
class AggregateLODSetup_t // worldrenderer
{
	Vector m_vLODOrigin; // 0x0000
	float32 m_fMaxObjectScale; // 0x000C
	CUtlVector< float32 > m_fSwitchDistances; // 0x0010
};
class IPhysicsBodyList // vphysics2
{
};
class CPerParticleVecInput : public CParticleVecInput // particleslib
{
};
class CSolveIKTargetHandle_t // animgraphlib
{
	CAnimParamHandle m_positionHandle; // 0x0000
	CAnimParamHandle m_orientationHandle; // 0x0002
};
class MaterialResourceData_t // materialsystem2
{
	CUtlString m_materialName; // 0x0000
	CUtlString m_shaderName; // 0x0008
	CUtlVector< MaterialParamInt_t > m_intParams; // 0x0010
	CUtlVector< MaterialParamFloat_t > m_floatParams; // 0x0028
	CUtlVector< MaterialParamVector_t > m_vectorParams; // 0x0040
	CUtlVector< MaterialParamTexture_t > m_textureParams; // 0x0058
	CUtlVector< MaterialParamBuffer_t > m_dynamicParams; // 0x0070
	CUtlVector< MaterialParamBuffer_t > m_dynamicTextureParams; // 0x0088
	CUtlVector< MaterialParamInt_t > m_intAttributes; // 0x00A0
	CUtlVector< MaterialParamFloat_t > m_floatAttributes; // 0x00B8
	CUtlVector< MaterialParamVector_t > m_vectorAttributes; // 0x00D0
	CUtlVector< MaterialParamTexture_t > m_textureAttributes; // 0x00E8
	CUtlVector< MaterialParamString_t > m_stringAttributes; // 0x0100
	CUtlVector< CUtlString > m_renderAttributesUsed; // 0x0118
};
class CRandStopwatch : public CStopwatchBase // server
{
	float32 m_flMinInterval; // 0x000C
	float32 m_flMaxInterval; // 0x0010
};
class C_OP_DragRelativeToPlane : public CParticleFunctionOperator // particles
{
	CParticleCollectionFloatInput m_flDragAtPlane; // 0x01D8
	CParticleCollectionFloatInput m_flFalloff; // 0x0348
	bool m_bDirectional; // 0x04B8
	CParticleCollectionVecInput m_vecPlaneNormal; // 0x04C0
	int32 m_nControlPointNumber; // 0x0B78
};
class C_OP_MaxVelocity : public CParticleFunctionOperator // particles
{
	CPerParticleFloatInput m_flMaxVelocity; // 0x01D8
	CPerParticleFloatInput m_flMinVelocity; // 0x0348
};
class C_OP_RemapBoundingVolumetoCP : public CParticleFunctionPreEmission // particles
{
	int32 m_nOutControlPointNumber; // 0x01E0
	float32 m_flInputMin; // 0x01E4
	float32 m_flInputMax; // 0x01E8
	float32 m_flOutputMin; // 0x01EC
	float32 m_flOutputMax; // 0x01F0
};
class FourCovMatrices3 // physicslib
{
	FourVectors m_vDiag; // 0x0000
	fltx4 m_flXY; // 0x0030
	fltx4 m_flXZ; // 0x0040
	fltx4 m_flYZ; // 0x0050
};
class CNmGraphDefinition // animlib
{
	CGlobalSymbol m_variationID; // 0x0000
	CStrongHandle< InfoForResourceTypeCNmSkeleton > m_skeleton; // 0x0008
	CUtlVector< CStrongHandle< InfoForResourceTypeCNmSkeleton > > m_supportedSecondarySkeletons; // 0x0010
	CNmGraphVariationUserData* m_pUserData; // 0x0028
	CUtlVector< int16 > m_persistentNodeIndices; // 0x0030
	int16 m_nRootNodeIdx; // 0x0048
	CUtlVector< CGlobalSymbol > m_controlParameterIDs; // 0x0050
	CUtlVector< CGlobalSymbol > m_virtualParameterIDs; // 0x0068
	CUtlVector< int16 > m_virtualParameterNodeIndices; // 0x0080
	CUtlVector< CNmGraphDefinition::ReferencedGraphSlot_t > m_referencedGraphSlots; // 0x0098
	CUtlVector< CNmGraphDefinition::ExternalGraphSlot_t > m_externalGraphSlots; // 0x00B0
	CUtlVector< CNmGraphDefinition::ExternalPoseSlot_t > m_externalPoseSlots; // 0x00C8
	CUtlVector< CUtlString > m_nodePaths; // 0x0150
	CUtlVector< CStrongHandleVoid > m_resources; // 0x0168
};
class DynamicMeshDeformParams_t // modellib
{
	float32 m_flTensionCompressScale; // 0x0000
	float32 m_flTensionStretchScale; // 0x0004
	bool m_bRecomputeSmoothNormalsAfterAnimation; // 0x0008
	bool m_bComputeDynamicMeshTensionAfterAnimation; // 0x0009
	bool m_bSmoothNormalsAcrossUvSeams; // 0x000A
	bool m_bEnableEyeBulgeDeformation; // 0x000B
};
class CNmFloatRemapNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	CNmFloatRemapNode::RemapRange_t m_inputRange; // 0x0014
	CNmFloatRemapNode::RemapRange_t m_outputRange; // 0x001C
};
class CSeqAutoLayer // animationsystem
{
	int16 m_nLocalReference; // 0x0000
	int16 m_nLocalPose; // 0x0002
	CSeqAutoLayerFlag m_flags; // 0x0004
	float32 m_start; // 0x000C
	float32 m_peak; // 0x0010
	float32 m_tail; // 0x0014
	float32 m_end; // 0x0018
};
class InfoForResourceTypeCGcExportableExternalData // resourcesystem
{
};
class INavPathCost // navlib
{
	NavHull_t m_navHull; // 0x0008
};
class CNavVolumeAll : public CNavVolumeVector // navlib
{
};
class C_OP_RenderDeferredLight : public CParticleFunctionRenderer // particles
{
	bool m_bUseAlphaTestWindow; // 0x0228
	bool m_bUseTexture; // 0x0229
	float32 m_flRadiusScale; // 0x022C
	float32 m_flAlphaScale; // 0x0230
	ParticleAttributeIndex_t m_nAlpha2Field; // 0x0234
	CParticleCollectionVecInput m_vecColorScale; // 0x0238
	ParticleColorBlendType_t m_nColorBlendType; // 0x08F0
	float32 m_flLightDistance; // 0x08F4
	float32 m_flStartFalloff; // 0x08F8
	float32 m_flDistanceFalloff; // 0x08FC
	float32 m_flSpotFoV; // 0x0900
	ParticleAttributeIndex_t m_nAlphaTestPointField; // 0x0904
	ParticleAttributeIndex_t m_nAlphaTestRangeField; // 0x0908
	ParticleAttributeIndex_t m_nAlphaTestSharpnessField; // 0x090C
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hTexture; // 0x0910
	int32 m_nHSVShiftControlPoint; // 0x0918
};
class C_INIT_InitFloatCollection : public CParticleFunctionInitializer // particles
{
	CParticleCollectionFloatInput m_InputValue; // 0x01E0
	ParticleAttributeIndex_t m_nOutputField; // 0x0350
};
class C_OP_RemapDotProductToScalar : public CParticleFunctionOperator // particles
{
	int32 m_nInputCP1; // 0x01D8
	int32 m_nInputCP2; // 0x01DC
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E0
	float32 m_flInputMin; // 0x01E4
	float32 m_flInputMax; // 0x01E8
	float32 m_flOutputMin; // 0x01EC
	float32 m_flOutputMax; // 0x01F0
	bool m_bUseParticleVelocity; // 0x01F4
	ParticleSetMethod_t m_nSetMethod; // 0x01F8
	bool m_bActiveRange; // 0x01FC
	bool m_bUseParticleNormal; // 0x01FD
};
class CFeIndexedJiggleBone // physicslib
{
	uint32 m_nNode; // 0x0000
	uint32 m_nJiggleParent; // 0x0004
	CFeJiggleBone m_jiggleBone; // 0x0008
};
class CProductQuantizer // animgraphlib
{
	CUtlVector< CVectorQuantizer > m_subQuantizers; // 0x0000
	int32 m_nDimensions; // 0x0018
};
class CUnaryUpdateNode : public CAnimUpdateNodeBase // animgraphlib
{
	CAnimUpdateNodeRef m_pChildNode; // 0x0060
};
class CFootstepTableHandle // server
{
};
class SceneEventId_t // server
{
	uint32 m_Value; // 0x0000
};
class CNetworkOriginQuantizedVector // server
{
	CNetworkedQuantizedFloat m_vecX; // 0x0010
	CNetworkedQuantizedFloat m_vecY; // 0x0018
	CNetworkedQuantizedFloat m_vecZ; // 0x0020
};
class CMorphBundleData // modellib
{
	float32 m_flULeftSrc; // 0x0000
	float32 m_flVTopSrc; // 0x0004
	CUtlVector< float32 > m_offsets; // 0x0008
	CUtlVector< float32 > m_ranges; // 0x0020
};
class CDampedValueComponentUpdater : public CAnimComponentUpdater // animgraphlib
{
	CUtlVector< CDampedValueUpdateItem > m_items; // 0x0030
};
class CAnimStateMachineUpdater // animgraphlib
{
	CUtlVector< CStateUpdateData > m_states; // 0x0008
	CUtlVector< CTransitionUpdateData > m_transitions; // 0x0020
	int32 m_startStateIndex; // 0x0050
};
class CNmBoolValueNode::CDefinition : public CNmValueNode::CDefinition // animlib
{
};
class CHitBoxSet // modellib
{
	CUtlString m_name; // 0x0000
	uint32 m_nNameHash; // 0x0008
	CUtlVector< CHitBox > m_HitBoxes; // 0x0010
	CUtlString m_SourceFilename; // 0x0028
};
class InfoForResourceTypeCChoreoSceneResource // resourcesystem
{
};
class magnetted_objects_t // server
{
	CHandle< CBaseEntity > hEntity; // 0x0008
};
class CParticleFunctionPreEmission : public CParticleFunctionOperator // particles
{
	bool m_bRunOnce; // 0x01D8
};
class C_OP_SetSingleControlPointPosition : public CParticleFunctionPreEmission // particles
{
	bool m_bSetOnce; // 0x01E0
	int32 m_nCP1; // 0x01E4
	CParticleCollectionVecInput m_vecCP1Pos; // 0x01E8
	CParticleTransformInput m_transformInput; // 0x08A0
};
class CParticleMassCalculationParameters // particles
{
	ParticleMassMode_t m_nMassMode; // 0x0000
	CPerParticleFloatInput m_flRadius; // 0x0008
	CPerParticleFloatInput m_flNominalRadius; // 0x0178
	CPerParticleFloatInput m_flScale; // 0x02E8
};
class ISkeletonAnimationController // server
{
};
class C_OP_SetControlPointsToParticle : public CParticleFunctionOperator // particles
{
	int32 m_nChildGroupID; // 0x01D8
	int32 m_nFirstControlPoint; // 0x01DC
	int32 m_nNumControlPoints; // 0x01E0
	int32 m_nFirstSourcePoint; // 0x01E4
	bool m_bReverse; // 0x01E8
	bool m_bSetOrientation; // 0x01E9
	ParticleOrientationSetMode_t m_nOrientationMode; // 0x01EC
	ParticleParentSetMode_t m_nSetParent; // 0x01F0
};
class C_OP_ExternalGameImpulseForce : public CParticleFunctionForce // particles
{
	CPerParticleFloatInput m_flForceScale; // 0x01E8
	bool m_bRopes; // 0x0358
	bool m_bRopesZOnly; // 0x0359
	bool m_bExplosions; // 0x035A
	bool m_bParticles; // 0x035B
};
class C_OP_Callback : public CParticleFunctionRenderer // particles
{
};
class CVoiceContainerSwitch : public CVoiceContainerBase // soundsystem_voicecontainers
{
	CUtlVector< CSoundContainerReference > m_soundsToPlay; // 0x0070
};
class PhysFeModelDesc_t // physicslib
{
	CUtlVector< uint32 > m_CtrlHash; // 0x0000
	CUtlVector< CUtlString > m_CtrlName; // 0x0018
	uint32 m_nStaticNodeFlags; // 0x0030
	uint32 m_nDynamicNodeFlags; // 0x0034
	float32 m_flLocalForce; // 0x0038
	float32 m_flLocalRotation; // 0x003C
	uint16 m_nNodeCount; // 0x0040
	uint16 m_nStaticNodes; // 0x0042
	uint16 m_nRotLockStaticNodes; // 0x0044
	uint16 m_nFirstPositionDrivenNode; // 0x0046
	uint16 m_nSimdTriCount1; // 0x0048
	uint16 m_nSimdTriCount2; // 0x004A
	uint16 m_nSimdQuadCount1; // 0x004C
	uint16 m_nSimdQuadCount2; // 0x004E
	uint16 m_nQuadCount1; // 0x0050
	uint16 m_nQuadCount2; // 0x0052
	uint16 m_nTreeDepth; // 0x0054
	uint16 m_nNodeBaseJiggleboneDependsCount; // 0x0056
	uint16 m_nRopeCount; // 0x0058
	CUtlVector< uint16 > m_Ropes; // 0x0060
	CUtlVector< FeNodeBase_t > m_NodeBases; // 0x0078
	CUtlVector< FeSimdNodeBase_t > m_SimdNodeBases; // 0x0090
	CUtlVector< FeQuad_t > m_Quads; // 0x00A8
	CUtlVector< FeSimdQuad_t > m_SimdQuads; // 0x00C0
	CUtlVector< FeSimdTri_t > m_SimdTris; // 0x00D8
	CUtlVector< FeSimdRodConstraint_t > m_SimdRods; // 0x00F0
	CUtlVector< FeSimdRodConstraintAnim_t > m_SimdRodsAnim; // 0x0108
	CUtlVector< CTransform > m_InitPose; // 0x0120
	CUtlVector< FeRodConstraint_t > m_Rods; // 0x0138
	CUtlVector< FeTwistConstraint_t > m_Twists; // 0x0150
	CUtlVector< FeHingeLimit_t > m_HingeLimits; // 0x0168
	CUtlVector< uint32 > m_AntiTunnelBytecode; // 0x0180
	CUtlVector< FeDynKinLink_t > m_DynKinLinks; // 0x0198
	CUtlVector< FeBoneMergeLink_t > m_BoneMergeLinks; // 0x01B0
	CUtlVector< FeAntiTunnelProbe_t > m_AntiTunnelProbes; // 0x01C8
	CUtlVector< uint16 > m_AntiTunnelTargetNodes; // 0x01E0
	CUtlVector< FeNodeStrayBox_t > m_NodeStrayBoxes; // 0x01F8
	CUtlVector< FeAxialEdgeBend_t > m_AxialEdges; // 0x0210
	CUtlVector< float32 > m_NodeInvMasses; // 0x0228
	CUtlVector< FeCtrlOffset_t > m_CtrlOffsets; // 0x0240
	CUtlVector< FeCtrlOsOffset_t > m_CtrlOsOffsets; // 0x0258
	CUtlVector< FeFollowNode_t > m_FollowNodes; // 0x0270
	CUtlVector< FeCollisionPlane_t > m_CollisionPlanes; // 0x0288
	CUtlVector< FeNodeIntegrator_t > m_NodeIntegrator; // 0x02A0
	CUtlVector< FeSpringIntegrator_t > m_SpringIntegrator; // 0x02B8
	CUtlVector< FeSimdSpringIntegrator_t > m_SimdSpringIntegrator; // 0x02D0
	CUtlVector< FeWorldCollisionParams_t > m_WorldCollisionParams; // 0x02E8
	CUtlVector< float32 > m_LegacyStretchForce; // 0x0300
	CUtlVector< float32 > m_NodeCollisionRadii; // 0x0318
	CUtlVector< float32 > m_DynNodeFriction; // 0x0330
	CUtlVector< float32 > m_LocalRotation; // 0x0348
	CUtlVector< float32 > m_LocalForce; // 0x0360
	CUtlVector< FeTaperedCapsuleStretch_t > m_TaperedCapsuleStretches; // 0x0378
	CUtlVector< FeTaperedCapsuleRigid_t > m_TaperedCapsuleRigids; // 0x0390
	CUtlVector< FeSphereRigid_t > m_SphereRigids; // 0x03A8
	CUtlVector< uint16 > m_WorldCollisionNodes; // 0x03C0
	CUtlVector< uint16 > m_TreeParents; // 0x03D8
	CUtlVector< uint16 > m_TreeCollisionMasks; // 0x03F0
	CUtlVector< FeTreeChildren_t > m_TreeChildren; // 0x0408
	CUtlVector< uint16 > m_FreeNodes; // 0x0420
	CUtlVector< FeFitMatrix_t > m_FitMatrices; // 0x0438
	CUtlVector< FeFitWeight_t > m_FitWeights; // 0x0450
	CUtlVector< FeNodeReverseOffset_t > m_ReverseOffsets; // 0x0468
	CUtlVector< FeAnimStrayRadius_t > m_AnimStrayRadii; // 0x0480
	CUtlVector< FeSimdAnimStrayRadius_t > m_SimdAnimStrayRadii; // 0x0498
	CUtlVector< FeKelagerBend2_t > m_KelagerBends; // 0x04B0
	CUtlVector< FeCtrlSoftOffset_t > m_CtrlSoftOffsets; // 0x04C8
	CUtlVector< CFeIndexedJiggleBone > m_JiggleBones; // 0x04E0
	CUtlVector< uint16 > m_SourceElems; // 0x04F8
	CUtlVector< uint32 > m_GoalDampedSpringIntegrators; // 0x0510
	CUtlVector< FeTri_t > m_Tris; // 0x0528
	uint16 m_nTriCount1; // 0x0540
	uint16 m_nTriCount2; // 0x0542
	uint8 m_nReservedUint8; // 0x0544
	uint8 m_nExtraPressureIterations; // 0x0545
	uint8 m_nExtraGoalIterations; // 0x0546
	uint8 m_nExtraIterations; // 0x0547
	CUtlVector< FeSDFRigid_t > m_SDFRigids; // 0x0548
	CUtlVector< FeBoxRigid_t > m_BoxRigids; // 0x0560
	CUtlVector< uint8 > m_DynNodeVertexSet; // 0x0578
	CUtlVector< uint32 > m_VertexSetNames; // 0x0590
	CUtlVector< FeRigidColliderIndices_t > m_RigidColliderPriorities; // 0x05A8
	CUtlVector< FeMorphLayerDepr_t > m_MorphLayers; // 0x05C0
	CUtlVector< uint8 > m_MorphSetData; // 0x05D8
	CUtlVector< FeVertexMapDesc_t > m_VertexMaps; // 0x05F0
	CUtlVector< uint8 > m_VertexMapValues; // 0x0608
	CUtlVector< FeEffectDesc_t > m_Effects; // 0x0620
	CUtlVector< FeCtrlOffset_t > m_LockToParent; // 0x0638
	CUtlVector< uint16 > m_LockToGoal; // 0x0650
	CUtlVector< int16 > m_SkelParents; // 0x0668
	CUtlVector< FeNodeWindBase_t > m_DynNodeWindBases; // 0x0680
	CUtlVector< FeModelSelfCollisionLayer_t > m_SelfCollisionLayers; // 0x0698
	float32 m_flInternalPressure; // 0x06B0
	float32 m_flDefaultTimeDilation; // 0x06B4
	float32 m_flWindage; // 0x06B8
	float32 m_flWindDrag; // 0x06BC
	float32 m_flDefaultSurfaceStretch; // 0x06C0
	float32 m_flDefaultThreadStretch; // 0x06C4
	float32 m_flDefaultGravityScale; // 0x06C8
	float32 m_flDefaultVelAirDrag; // 0x06CC
	float32 m_flDefaultExpAirDrag; // 0x06D0
	float32 m_flDefaultVelQuadAirDrag; // 0x06D4
	float32 m_flDefaultExpQuadAirDrag; // 0x06D8
	float32 m_flRodVelocitySmoothRate; // 0x06DC
	float32 m_flQuadVelocitySmoothRate; // 0x06E0
	float32 m_flAddWorldCollisionRadius; // 0x06E4
	float32 m_flDefaultVolumetricSolveAmount; // 0x06E8
	float32 m_flMotionSmoothCDT; // 0x06EC
	float32 m_flLocalDrag1; // 0x06F0
	uint16 m_nRodVelocitySmoothIterations; // 0x06F4
	uint16 m_nQuadVelocitySmoothIterations; // 0x06F6
};
class CModelConfigElement_SetMaterialGroupOnAttachedModels : public CModelConfigElement // modellib
{
	CUtlString m_MaterialGroupName; // 0x0048
};
class CNmConstTargetNode::CDefinition : public CNmTargetValueNode::CDefinition // animlib
{
	CNmTarget m_value; // 0x0010
};
class CNmConstFloatNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	float32 m_flValue; // 0x0010
};
class CDirectionalBlendUpdateNode : public CLeafUpdateNode // animgraphlib
{
	HSequence[8] m_hSequences; // 0x005C
	CAnimInputDamping m_damping; // 0x0080
	AnimValueSource m_blendValueSource; // 0x0098
	CAnimParamHandle m_paramIndex; // 0x009C
	float32 m_playbackSpeed; // 0x00A0
	float32 m_duration; // 0x00A4
	bool m_bLoop; // 0x00A8
	bool m_bLockBlendOnReset; // 0x00A9
};
class CStopwatch : public CStopwatchBase // server
{
	float32 m_flInterval; // 0x000C
};
class C_OP_VelocityDecay : public CParticleFunctionOperator // particles
{
	float32 m_flMinVelocity; // 0x01D8
};
class C_OP_CalculateVectorAttribute : public CParticleFunctionOperator // particles
{
	Vector m_vStartValue; // 0x01D8
	ParticleAttributeIndex_t m_nFieldInput1; // 0x01E4
	float32 m_flInputScale1; // 0x01E8
	ParticleAttributeIndex_t m_nFieldInput2; // 0x01EC
	float32 m_flInputScale2; // 0x01F0
	ControlPointReference_t m_nControlPointInput1; // 0x01F4
	float32 m_flControlPointScale1; // 0x0208
	ControlPointReference_t m_nControlPointInput2; // 0x020C
	float32 m_flControlPointScale2; // 0x0220
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0224
	Vector m_vFinalOutputScale; // 0x0228
};
class CSSDSMsg_EndFrame // scenesystem
{
	CUtlVector< CSSDSEndFrameViewInfo > m_Views; // 0x0000
};
class RnMesh_t // physicslib
{
	Vector m_vMin; // 0x0000
	Vector m_vMax; // 0x000C
	CUtlVector< RnNode_t > m_Nodes; // 0x0018
	CUtlVectorSIMDPaddedVector m_Vertices; // 0x0030
	CUtlVector< RnTriangle_t > m_Triangles; // 0x0048
	CUtlVector< RnWing_t > m_Wings; // 0x0060
	CUtlVector< uint8 > m_TriangleEdgeFlags; // 0x0078
	CUtlVector< uint8 > m_Materials; // 0x0090
	Vector m_vOrthographicAreas; // 0x00A8
	uint32 m_nFlags; // 0x00B4
	uint32 m_nDebugFlags; // 0x00B8
};
class RnPlane_t // physicslib
{
	Vector m_vNormal; // 0x0000
	float32 m_flOffset; // 0x000C
};
class CFeVertexMapBuildArray // physicslib
{
	CUtlVector< FeVertexMapBuild_t* > m_Array; // 0x0000
};
class CInputStreamUpdateNode : public CLeafUpdateNode // animgraphlib
{
};
class CAnimScriptManager // animgraphlib
{
	CUtlVector< ScriptInfo_t > m_scriptInfo; // 0x0010
};
class CAnimMovement // animationsystem
{
	int32 endframe; // 0x0000
	int32 motionflags; // 0x0004
	float32 v0; // 0x0008
	float32 v1; // 0x000C
	float32 angle; // 0x0010
	Vector vector; // 0x0014
	Vector position; // 0x0020
};
class CBlendCurve // animgraphlib
{
	float32 m_flControlPoint1; // 0x0000
	float32 m_flControlPoint2; // 0x0004
};
class SkeletonDemoDb_t // modellib
{
	CUtlVector< SkeletonAnimCapture_t* > m_AnimCaptures; // 0x0000
	CUtlVector< SkeletonAnimCapture_t::Camera_t > m_CameraTrack; // 0x0018
	float32 m_flRecordingTime; // 0x0030
};
class CNmIDSelectorNode::CDefinition : public CNmIDValueNode::CDefinition // animlib
{
	CUtlLeanVectorFixedGrowable< int16, 5 > m_conditionNodeIndices; // 0x0010
	CUtlLeanVectorFixedGrowable< CGlobalSymbol, 5 > m_values; // 0x0028
	CGlobalSymbol m_defaultValue; // 0x0058
};
class RenderInputLayoutField_t // rendersystemdx11
{
	char[32] m_pSemanticName; // 0x0000
	int8 m_nSemanticIndex; // 0x0020
	int16 m_nOffset; // 0x0028
	int8 m_nSlot; // 0x002A
	RenderSlotType_t m_nSlotType; // 0x002B
	char[32] m_szShaderSemantic; // 0x002C
};
class AABB_t // mathlib_extended
{
	Vector m_vMinBounds; // 0x0000
	Vector m_vMaxBounds; // 0x000C
};
class C_INIT_RandomVectorComponent : public CParticleFunctionInitializer // particles
{
	float32 m_flMin; // 0x01E0
	float32 m_flMax; // 0x01E4
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E8
	int32 m_nComponent; // 0x01EC
};
class C_OP_InheritFromParentParticles : public CParticleFunctionOperator // particles
{
	float32 m_flScale; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
	int32 m_nIncrement; // 0x01E0
	bool m_bRandomDistribution; // 0x01E4
};
class CBaseTrailRenderer : public CBaseRendererSource2 // particles
{
	ParticleOrientationChoiceList_t m_nOrientationType; // 0x2DF0
	int32 m_nOrientationControlPoint; // 0x2DF4
	float32 m_flMinSize; // 0x2DF8
	float32 m_flMaxSize; // 0x2DFC
	CParticleCollectionRendererFloatInput m_flStartFadeSize; // 0x2E00
	CParticleCollectionRendererFloatInput m_flEndFadeSize; // 0x2F70
	CParticleCollectionRendererFloatInput m_flSubPixelAAScale; // 0x30E0
	bool m_bClampV; // 0x3250
};
class CPhysSurfacePropertiesVehicle // modellib
{
	float32 m_wheelDrag; // 0x0000
	float32 m_wheelFrictionScale; // 0x0004
};
class CLeanMatrixInstanceData // animgraphlib
{
	float32 m_flValueY; // 0x0000
	float32 m_flValueX; // 0x0004
};
class CLookComponentUpdater : public CAnimComponentUpdater // animgraphlib
{
	CAnimParamHandle m_hLookHeading; // 0x0034
	CAnimParamHandle m_hLookHeadingNormalized; // 0x0036
	CAnimParamHandle m_hLookHeadingVelocity; // 0x0038
	CAnimParamHandle m_hLookPitch; // 0x003A
	CAnimParamHandle m_hLookDistance; // 0x003C
	CAnimParamHandle m_hLookDirection; // 0x003E
	CAnimParamHandle m_hLookTarget; // 0x0040
	CAnimParamHandle m_hLookTargetWorldSpace; // 0x0042
	bool m_bNetworkLookTarget; // 0x0044
};
class CNmIDBasedClipSelectorNode::CDefinition : public CNmClipReferenceNode::CDefinition // animlib
{
	CUtlLeanVectorFixedGrowable< int16, 5 > m_optionNodeIndices; // 0x0010
	CUtlLeanVectorFixedGrowable< CGlobalSymbol, 5 > m_optionIDs; // 0x0028
	int16 m_nParameterNodeIdx; // 0x0058
	int16 m_nFallbackNodeIdx; // 0x005A
	bool m_bIgnoreInvalidOptions; // 0x005C
};
class CSetParameterActionUpdater : public CAnimActionUpdater // animgraphlib
{
	CAnimParamHandle m_hParam; // 0x0018
	CAnimVariant m_value; // 0x001A
};
class CNmEventConsumerPulse : public CNmEventConsumer // server
{
};
class CConstantForceController // server
{
	Vector m_linear; // 0x000C
	RotationVector m_angular; // 0x0018
	Vector m_linearSave; // 0x0024
	RotationVector m_angularSave; // 0x0030
};
class C_OP_ModelSurfaceSnapshotGenerator : public CParticleFunctionPreEmission // particles
{
	int32 m_nCPSnapshot; // 0x01E0
	CParticleModelInput m_modelInput; // 0x01E8
	CParticleCollectionFloatInput m_flRecalcRate; // 0x0248
	CParticleCollectionFloatInput m_flUSpacing; // 0x03B8
	CParticleCollectionFloatInput m_flVSpacing; // 0x0528
	CParticleCollectionFloatInput m_flSurfaceOffset; // 0x0698
	bool m_bSetNormal; // 0x0808
	bool m_bSetUp; // 0x0809
	bool m_bSetGravity; // 0x080A
	bool m_bSetUV; // 0x080B
};
class C_OP_ConstrainDistanceToUserSpecifiedPath : public CParticleFunctionConstraint // particles
{
	float32 m_fMinDistance; // 0x01D8
	float32 m_flMaxDistance; // 0x01DC
	float32 m_flTimeScale; // 0x01E0
	bool m_bLoopedPath; // 0x01E4
	CUtlVector< PointDefinitionWithTimeValues_t > m_pointList; // 0x01E8
};
class ClutterTile_t // worldrenderer
{
	uint32 m_nFirstInstance; // 0x0000
	uint32 m_nLastInstance; // 0x0004
	AABB_t m_BoundsWs; // 0x0008
};
class CVoiceContainerAmpedDecayingSineWave : public CVoiceContainerDecayingSineWave // soundsystem_voicecontainers
{
	float32 m_flGainAmount; // 0x0078
};
class CVMixAutoFilterProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixAutoFilterDesc_t m_desc; // 0x0020
};
class CNmFootEvent : public CNmEvent // animlib
{
	NmFootPhase_t m_phase; // 0x0018
};
class CompositeMaterialEditorPoint_t // compositematerialslib
{
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCModel > > m_ModelName; // 0x0000
	int32 m_nSequenceIndex; // 0x00E0
	float32 m_flCycle; // 0x00E4
	KeyValues3 m_KVModelStateChoices; // 0x00E8
	bool m_bEnableChildModel; // 0x00F8
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCModel > > m_ChildModelName; // 0x0100
	CUtlVector< CompositeMaterialAssemblyProcedure_t > m_vecCompositeMaterialAssemblyProcedures; // 0x01E0
	CUtlVector< CompositeMaterial_t > m_vecCompositeMaterials; // 0x01F8
};
class CEntitySubclassVDataBase // server
{
};
class C_INIT_InitFromParentKilled : public CParticleFunctionInitializer // particles
{
	ParticleAttributeIndex_t m_nAttributeToCopy; // 0x01E0
	EventTypeSelection_t m_nEventType; // 0x01E4
};
class C_OP_RenderOmni2Light : public CParticleFunctionRenderer // particles
{
	ParticleOmni2LightTypeChoiceList_t m_nLightType; // 0x0228
	uint16 m_nMaxAllowed; // 0x022C
	CParticleCollectionVecInput m_vColorBlend; // 0x0230
	ParticleColorBlendType_t m_nColorBlendType; // 0x08E8
	CUtlString m_strLightStyle; // 0x08F0
	CPerParticleFloatInput m_flLightStyleTime; // 0x08F8
	ParticleLightUnitChoiceList_t m_nBrightnessUnit; // 0x0A68
	CPerParticleFloatInput m_flBrightnessLumens; // 0x0A70
	CPerParticleFloatInput m_flBrightnessCandelas; // 0x0BE0
	bool m_bCastShadows; // 0x0D50
	bool m_bDynamicBounce; // 0x0D51
	CParticleCollectionFloatInput m_flBounceScale; // 0x0D58
	bool m_bFog; // 0x0EC8
	CPerParticleFloatInput m_flFogScale; // 0x0ED0
	CPerParticleFloatInput m_flLuminaireRadius; // 0x1040
	CPerParticleFloatInput m_flSkirt; // 0x11B0
	CPerParticleFloatInput m_flRange; // 0x1320
	CPerParticleFloatInput m_flInnerConeAngle; // 0x1490
	CPerParticleFloatInput m_flOuterConeAngle; // 0x1600
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hLightCookie; // 0x1770
	bool m_bSphericalCookie; // 0x1778
};
class ISndSeqInstruments // soundsystem
{
};
class CNmPoseTask // animlib
{
};
class CFootCycleDefinition // modellib
{
	Vector m_vStancePositionMS; // 0x0000
	Vector m_vMidpointPositionMS; // 0x000C
	float32 m_flStanceDirectionMS; // 0x0018
	Vector m_vToStrideStartPos; // 0x001C
	CAnimCycle m_stanceCycle; // 0x0028
	CFootCycle m_footLiftCycle; // 0x002C
	CFootCycle m_footOffCycle; // 0x0030
	CFootCycle m_footStrikeCycle; // 0x0034
	CFootCycle m_footLandCycle; // 0x0038
};
class CRenderBufferBinding // modellib
{
	uint64 m_hBuffer; // 0x0000
	uint32 m_nBindOffsetBytes; // 0x0010
};
class CMotionNode // animgraphlib
{
	CUtlString m_name; // 0x0018
	AnimNodeID m_id; // 0x0020
};
class CMultiplayer_Expresser : public CAI_ExpresserWithFollowup // server
{
	bool m_bAllowMultipleScenes; // 0x00A0
};
class C_INIT_InitFloat : public CParticleFunctionInitializer // particles
{
	CPerParticleFloatInput m_InputValue; // 0x01E0
	ParticleAttributeIndex_t m_nOutputField; // 0x0350
	ParticleSetMethod_t m_nSetMethod; // 0x0354
	CPerParticleFloatInput m_InputStrength; // 0x0358
};
class CollisionDetailLayerInfo_t::Name_t // physicslib
{
	CUtlStringToken m_nNameToken; // 0x0000
	CUtlString m_sNameString; // 0x0008
};
class CSchemaSystemInternalRegistration // schemasystem
{
	Vector2D m_Vector2D; // 0x0000
	Vector m_Vector; // 0x0008
	VectorWS m_VectorWS; // 0x0014
	VectorAligned m_VectorAligned; // 0x0020
	Quaternion m_Quaternion; // 0x0030
	QAngle m_QAngle; // 0x0040
	RotationVector m_RotationVector; // 0x004C
	RadianEuler m_RadianEuler; // 0x0058
	DegreeEuler m_DegreeEuler; // 0x0064
	QuaternionStorage m_QuaternionStorage; // 0x0070
	matrix3x4_t m_matrix3x4_t; // 0x0080
	matrix3x4a_t m_matrix3x4a_t; // 0x00B0
	Color m_Color; // 0x00E0
	Vector4D m_Vector4D; // 0x00E4
	CTransform m_CTransform; // 0x0100
	KeyValues* m_pKeyValues; // 0x0120
	CUtlBinaryBlock m_CUtlBinaryBlock; // 0x0128
	CUtlString m_CUtlString; // 0x0138
	CUtlSymbol m_CUtlSymbol; // 0x0140
	CUtlStringToken m_stringToken; // 0x0144
	CUtlStringTokenWithStorage m_stringTokenWithStorage; // 0x0148
	CResourceArray< CResourcePointer< CResourceString > > m_ResourceTypes; // 0x0160
	KeyValues3 m_KV3; // 0x0168
};
class C_OP_SetCPtoVector : public CParticleFunctionOperator // particles
{
	int32 m_nCPInput; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
};
class CNmStateCompletedConditionNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	int16 m_nSourceStateNodeIdx; // 0x0010
	int16 m_nTransitionDurationOverrideNodeIdx; // 0x0012
	float32 m_flTransitionDurationSeconds; // 0x0014
};
class CBoolAnimParameter : public CConcreteAnimParameter // animgraphlib
{
	bool m_bDefaultValue; // 0x0080
};
class VPhysXBodyPart_t // modellib
{
	uint32 m_nFlags; // 0x0000
	float32 m_flMass; // 0x0004
	VPhysics2ShapeDef_t m_rnShape; // 0x0008
	uint16 m_nCollisionAttributeIndex; // 0x0080
	uint16 m_nReserved; // 0x0082
	float32 m_flInertiaScale; // 0x0084
	float32 m_flLinearDamping; // 0x0088
	float32 m_flAngularDamping; // 0x008C
	float32 m_flLinearDrag; // 0x0090
	float32 m_flAngularDrag; // 0x0094
	bool m_bOverrideMassCenter; // 0x0098
	Vector m_vMassCenterOverride; // 0x009C
};
class C_INIT_InitSkinnedPositionFromCPSnapshot : public CParticleFunctionInitializer // particles
{
	int32 m_nSnapshotControlPointNumber; // 0x01E0
	int32 m_nControlPointNumber; // 0x01E4
	bool m_bRandom; // 0x01E8
	int32 m_nRandomSeed; // 0x01EC
	bool m_bRigid; // 0x01F0
	bool m_bSetNormal; // 0x01F1
	bool m_bIgnoreDt; // 0x01F2
	float32 m_flMinNormalVelocity; // 0x01F4
	float32 m_flMaxNormalVelocity; // 0x01F8
	SnapshotIndexType_t m_nIndexType; // 0x01FC
	CPerParticleFloatInput m_flReadIndex; // 0x0200
	float32 m_flIncrement; // 0x0370
	int32 m_nFullLoopIncrement; // 0x0374
	int32 m_nSnapShotStartPoint; // 0x0378
	float32 m_flBoneVelocity; // 0x037C
	float32 m_flBoneVelocityMax; // 0x0380
	bool m_bCopyColor; // 0x0384
	bool m_bCopyAlpha; // 0x0385
	bool m_bSetRadius; // 0x0386
};
class C_OP_LerpToOtherAttribute : public CParticleFunctionOperator // particles
{
	CPerParticleFloatInput m_flInterpolation; // 0x01D8
	ParticleAttributeIndex_t m_nFieldInputFrom; // 0x0348
	ParticleAttributeIndex_t m_nFieldInput; // 0x034C
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0350
};
class InfoForResourceTypeVMapResourceData_t // worldrenderer
{
};
class RnTriangle_t // physicslib
{
	int32[3] m_nIndex; // 0x0000
};
class FourVectors2D // physicslib
{
	fltx4 x; // 0x0000
	fltx4 y; // 0x0010
};
class CStopAtGoalUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	float32 m_flOuterRadius; // 0x0074
	float32 m_flInnerRadius; // 0x0078
	float32 m_flMaxScale; // 0x007C
	float32 m_flMinScale; // 0x0080
	CAnimInputDamping m_damping; // 0x0088
};
class CNmLayerBlendNode::LayerDefinition_t // animlib
{
	int16 m_nInputNodeIdx; // 0x0000
	int16 m_nWeightValueNodeIdx; // 0x0002
	int16 m_nBoneMaskValueNodeIdx; // 0x0004
	int16 m_nRootMotionWeightValueNodeIdx; // 0x0006
	bool m_bIsSynchronized; // 0x0008
	bool m_bIgnoreEvents; // 0x0009
	bool m_bIsStateMachineLayer; // 0x000A
	NmPoseBlendMode_t m_blendMode; // 0x000B
};
class CNmRootMotionOverrideNode::CDefinition : public CNmPassthroughNode::CDefinition // animlib
{
	int16 m_desiredMovingVelocityNodeIdx; // 0x0018
	int16 m_desiredFacingDirectionNodeIdx; // 0x001A
	int16 m_linearVelocityLimitNodeIdx; // 0x001C
	int16 m_angularVelocityLimitNodeIdx; // 0x001E
	int16 m_enabledNodeIdx; // 0x0020
	float32 m_maxLinearVelocity; // 0x0024
	float32 m_maxAngularVelocityRadians; // 0x0028
	CNmBitFlags m_overrideFlags; // 0x002C
};
class CFuseSymbolTable // mathlib_extended
{
	CUtlVector< ConstantInfo_t > m_constants; // 0x0000
	CUtlVector< VariableInfo_t > m_variables; // 0x0018
	CUtlVector< FunctionInfo_t > m_functions; // 0x0030
	CUtlHashtable< CUtlStringToken, int32 > m_constantMap; // 0x0048
	CUtlHashtable< CUtlStringToken, int32 > m_variableMap; // 0x0068
	CUtlHashtable< CUtlStringToken, int32 > m_functionMap; // 0x0088
};
class C_OP_SetControlPointOrientation : public CParticleFunctionPreEmission // particles
{
	bool m_bUseWorldLocation; // 0x01E0
	bool m_bRandomize; // 0x01E2
	bool m_bSetOnce; // 0x01E3
	int32 m_nCP; // 0x01E4
	int32 m_nHeadLocation; // 0x01E8
	QAngle m_vecRotation; // 0x01EC
	QAngle m_vecRotationB; // 0x01F8
	CParticleCollectionFloatInput m_flInterpolation; // 0x0208
};
class CModelConfig // modellib
{
	CUtlString m_ConfigName; // 0x0000
	CUtlVector< CModelConfigElement* > m_Elements; // 0x0008
	bool m_bTopLevel; // 0x0020
	bool m_bActiveInEditorByDefault; // 0x0021
};
class PermModelDataAnimatedMaterialAttribute_t // modellib
{
	CUtlString m_AttributeName; // 0x0000
	int32 m_nNumChannels; // 0x0008
};
class CNewParticleEffect : public IParticleEffect // particleslib
{
	CNewParticleEffect* m_pNext; // 0x0010
	CNewParticleEffect* m_pPrev; // 0x0018
	IParticleCollection* m_pParticles; // 0x0020
	char* m_pDebugName; // 0x0028
	bitfield:1 m_bDontRemove; // 0x0000
	bitfield:1 m_bRemove; // 0x0000
	bitfield:1 m_bNeedsBBoxUpdate; // 0x0000
	bitfield:1 m_bIsFirstFrame; // 0x0000
	bitfield:1 m_bAutoUpdateBBox; // 0x0000
	bitfield:1 m_bAllocated; // 0x0000
	bitfield:1 m_bSimulate; // 0x0000
	bitfield:1 m_bShouldPerformCullCheck; // 0x0000
	bitfield:1 m_bForceNoDraw; // 0x0000
	bitfield:1 m_bSuppressScreenSpaceEffect; // 0x0000
	bitfield:1 m_bShouldSave; // 0x0000
	bitfield:1 m_bShouldSimulateDuringGamePaused; // 0x0000
	bitfield:1 m_bShouldCheckFoW; // 0x0000
	bitfield:1 m_bIsAsyncCreate; // 0x0000
	bitfield:1 m_bFreezeTransitionActive; // 0x0000
	bitfield:1 m_bFreezeTargetState; // 0x0000
	bitfield:1 m_bCanFreeze; // 0x0000
	Vector m_vSortOrigin; // 0x0040
	float32 m_flScale; // 0x004C
	PARTICLE_EHANDLE__* m_hOwner; // 0x0050
	CParticleProperty* m_pOwningParticleProperty; // 0x0058
	float32 m_flFreezeTransitionStart; // 0x0070
	float32 m_flFreezeTransitionDuration; // 0x0074
	float32 m_flFreezeTransitionOverride; // 0x0078
	Vector m_LastMin; // 0x007C
	Vector m_LastMax; // 0x0088
	CSplitScreenSlot m_nSplitScreenUser; // 0x0094
	Vector m_vecAggregationCenter; // 0x0098
	int32 m_RefCount; // 0x00D0
};
class CNmBoneMaskValueNode::CDefinition : public CNmValueNode::CDefinition // animlib
{
};
class CNmParameterizedClipSelectorNode::CDefinition : public CNmClipReferenceNode::CDefinition // animlib
{
	CUtlLeanVectorFixedGrowable< int16, 8 > m_optionNodeIndices; // 0x0010
	CUtlLeanVectorFixedGrowable< uint8, 8 > m_optionWeights; // 0x0028
	int16 m_parameterNodeIdx; // 0x0038
	bool m_bIgnoreInvalidOptions; // 0x003A
	bool m_bHasWeightsSet; // 0x003B
};
class InfoForResourceTypeIMaterial2 // resourcesystem
{
};
class CClientAlphaProperty : public IClientAlphaProperty // client
{
	uint16 m_nDistFadeStart; // 0x0010
	uint16 m_nDistFadeEnd; // 0x0012
	bitfield:14 m_nDesyncOffset; // 0x0000
	bitfield:1 m_bAlphaOverride; // 0x0000
	bitfield:1 m_bShadowAlphaOverride; // 0x0000
	bitfield:3 m_nRenderMode; // 0x0000
	bitfield:5 m_nRenderFX; // 0x0000
	uint8 m_nAlpha; // 0x0017
	float32 m_flFadeScale; // 0x0018
	GameTime_t m_flRenderFxStartTime; // 0x001C
	float32 m_flRenderFxDuration; // 0x0020
};
class CFloatExponentialMovingAverage // server
{
};
class CGameChoreoServices : public IChoreoServices // server
{
	CHandle< CBaseModelEntity > m_hOwner; // 0x0008
	CHandle< CScriptedSequence > m_hScriptedSequence; // 0x000C
	IChoreoServices::ScriptState_t m_scriptState; // 0x0010
	IChoreoServices::ChoreoState_t m_choreoState; // 0x0014
	GameTime_t m_flTimeStartedState; // 0x0018
};
class SndBeatEventKeyedFloats_t : public SndBeatEventKeys_t // soundsystem
{
	float32 m_flFloat; // 0x0010
};
class CStateMachineUpdateNode : public CAnimUpdateNodeBase // animgraphlib
{
	CAnimStateMachineUpdater m_stateMachine; // 0x0070
	CUtlVector< CStateNodeStateData > m_stateData; // 0x00C8
	CUtlVector< CStateNodeTransitionData > m_transitionData; // 0x00E0
	bool m_bBlockWaningTags; // 0x00FC
	bool m_bLockStateWhenWaning; // 0x00FD
	bool m_bResetWhenActivated; // 0x00FE
};
class InfoForResourceTypeProceduralTestResource_t // resourcesystem
{
};
class CSimpleSimTimer // server
{
	GameTime_t m_flNext; // 0x0000
	WorldGroupId_t m_nWorldGroupId; // 0x0004
};
class CNavVolumeMarkupVolume : public CNavVolume // server
{
};
class TestComponent_t // pulse_system
{
	CUtlString m_ComponentData; // 0x0008
};
class CVMixSteamAudioHybridReverbProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
};
class CVoiceContainerParameterBlender : public CVoiceContainerBase // soundsystem_voicecontainers
{
	CSoundContainerReference m_firstSound; // 0x0070
	CSoundContainerReference m_secondSound; // 0x0090
	bool m_bEnableOcclusionBlend; // 0x00B0
	CPiecewiseCurve m_curve1; // 0x00B8
	CPiecewiseCurve m_curve2; // 0x00F8
	bool m_bEnableDistanceBlend; // 0x0138
	CPiecewiseCurve m_curve3; // 0x0140
	CPiecewiseCurve m_curve4; // 0x0180
};
class CSeqBoneMaskList // animationsystem
{
	CBufferString m_sName; // 0x0000
	CUtlVector< int16 > m_nLocalBoneArray; // 0x0010
	CUtlVector< float32 > m_flBoneWeightArray; // 0x0028
	float32 m_flDefaultMorphCtrlWeight; // 0x0040
	CUtlVector< std::pair< CBufferString, float32 > > m_morphCtrlWeightArray; // 0x0048
};
class VPhysXRange_t // modellib
{
	float32 m_flMin; // 0x0000
	float32 m_flMax; // 0x0004
};
class C_OP_SetFloat : public CParticleFunctionOperator // particles
{
	CPerParticleFloatInput m_InputValue; // 0x01D8
	ParticleAttributeIndex_t m_nOutputField; // 0x0348
	ParticleSetMethod_t m_nSetMethod; // 0x034C
	CPerParticleFloatInput m_Lerp; // 0x0350
};
class IParticleSystemDefinition // particles
{
};
class TagSpan_t // animgraphlib
{
	int32 m_tagIndex; // 0x0000
	float32 m_startCycle; // 0x0004
	float32 m_endCycle; // 0x0008
};
class CSeqPoseParamDesc // animationsystem
{
	CBufferString m_sName; // 0x0000
	float32 m_flStart; // 0x0010
	float32 m_flEnd; // 0x0014
	float32 m_flLoop; // 0x0018
	bool m_bLooping; // 0x001C
};
class NmCompressionSettings_t // animlib
{
	NmCompressionSettings_t::QuantizationRange_t m_translationRangeX; // 0x0000
	NmCompressionSettings_t::QuantizationRange_t m_translationRangeY; // 0x0008
	NmCompressionSettings_t::QuantizationRange_t m_translationRangeZ; // 0x0010
	NmCompressionSettings_t::QuantizationRange_t m_scaleRange; // 0x0018
	int32 m_nTrackReadOffset; // 0x0020
	Quaternion m_constantRotation; // 0x0030
	bool m_bIsRotationStatic; // 0x0040
	bool m_bIsTranslationStatic; // 0x0041
	bool m_bIsScaleStatic; // 0x0042
};
class FuseFunctionIndex_t // mathlib_extended
{
	uint16 m_Value; // 0x0000
};
class CExternalAnimGraphList // server
{
};
class C_INIT_RemapNamedModelElementToScalar : public CParticleFunctionInitializer // particles
{
	CStrongHandle< InfoForResourceTypeCModel > m_hModel; // 0x01E0
	CUtlVector< CUtlString > m_names; // 0x01E8
	CUtlVector< float32 > m_values; // 0x0200
	ParticleAttributeIndex_t m_nFieldInput; // 0x0218
	ParticleAttributeIndex_t m_nFieldOutput; // 0x021C
	ParticleSetMethod_t m_nSetMethod; // 0x0220
	bool m_bModelFromRenderer; // 0x0224
};
class CSlowDownOnSlopesUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	float32 m_flSlowDownStrength; // 0x0070
};
class CNmTargetWarpEvent : public CNmEvent // animlib
{
	NmTargetWarpRule_t m_rule; // 0x0018
	NmTargetWarpAlgorithm_t m_algorithm; // 0x0019
};
class CPathAnimMotorUpdaterBase : public CAnimMotorUpdaterBase // animgraphlib
{
	bool m_bLockToPath; // 0x0020
};
class MaterialParamInt_t : public MaterialParam_t // materialsystem2
{
	int32 m_nValue; // 0x0008
};
class CHintMessage // server
{
	char* m_hintString; // 0x0000
	CUtlVector< char* > m_args; // 0x0008
	float32 m_duration; // 0x0020
};
class C_OP_FadeOutSimple : public CParticleFunctionOperator // particles
{
	float32 m_flFadeOutTime; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
};
class C_OP_EndCapTimedFreeze : public CParticleFunctionOperator // particles
{
	CParticleCollectionFloatInput m_flFreezeTime; // 0x01D8
};
class VMixFilterDesc_t // soundsystem_lowlevel
{
	VMixFilterType_t m_nFilterType; // 0x0000
	VMixFilterSlope_t m_nFilterSlope; // 0x0002
	bool m_bEnabled; // 0x0003
	float32 m_fldbGain; // 0x0004
	float32 m_flCutoffFreq; // 0x0008
	float32 m_flQ; // 0x000C
};
class CFootCycle : public CCycleBase // modellib
{
};
class PulseCursorID_t // pulse_runtime_lib
{
	int32 m_Value; // 0x0000
};
class TagStatus // animgraphlib
{
	TagActionStatus m_TagStatus; // 0x0000
	float32 m_flTagStartAnimTime; // 0x0004
};
class CAnimFoot // modellib
{
	CUtlString m_name; // 0x0000
	Vector m_vBallOffset; // 0x0008
	Vector m_vHeelOffset; // 0x0014
	int32 m_ankleBoneIndex; // 0x0020
	int32 m_toeBoneIndex; // 0x0024
};
class InfoForResourceTypeCEntityLump // resourcesystem
{
};
class IPhysicsMotionController // vphysics2
{
};
class C_INIT_RandomRadius : public CParticleFunctionInitializer // particles
{
	float32 m_flRadiusMin; // 0x01E0
	float32 m_flRadiusMax; // 0x01E4
	float32 m_flRadiusRandExponent; // 0x01E8
};
class C_OP_RemapVectorToRotations : public CParticleFunctionOperator // particles
{
	CPerParticleVecInput m_vecInput; // 0x01D8
	CPerParticleVecInput m_vecRotation; // 0x0890
};
class WorldBuilderParams_t // worldrenderer
{
	float32 m_flMinDrawVolumeSize; // 0x0000
	bool m_bBuildBakedLighting; // 0x0004
	bool m_bAggregateInstanceStreams; // 0x0005
	BakedLightingInfo_t m_bakedLightingInfo; // 0x0008
	uint64 m_nCompileTimestamp; // 0x0050
	uint64 m_nCompileFingerprint; // 0x0058
};
class InfoForResourceTypeCJavaScriptResource // resourcesystem
{
};
class ParticleChildrenInfo_t // particles
{
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_ChildRef; // 0x0000
	float32 m_flDelay; // 0x0008
	bool m_bEndCap; // 0x000C
	bool m_bDisableChild; // 0x000D
	ParticleDetailLevel_t m_nDetailLevel; // 0x0010
};
class ModelReference_t // particles
{
	CStrongHandle< InfoForResourceTypeCModel > m_model; // 0x0000
	float32 m_flRelativeProbabilityOfSpawn; // 0x0008
};
class CAddUpdateNode : public CBinaryUpdateNode // animgraphlib
{
	BinaryNodeChildOption m_footMotionTiming; // 0x0094
	bool m_bApplyToFootMotion; // 0x0098
	bool m_bApplyChannelsSeparately; // 0x0099
	bool m_bUseModelSpace; // 0x009A
	bool m_bApplyScale; // 0x009B
};
class CNmLegacyEvent : public CNmEvent // animlib
{
	CUtlString m_animEventClassName; // 0x0018
	KeyValues3 m_KV; // 0x0020
};
class CEntityIOOutput // entity2
{
};
class EventServerProcessNetworking_t : public EventSimulate_t // engine2
{
};
class EventServerPollNetworking_t : public EventSimulate_t // engine2
{
};
class AI_Navigator_DebugSnapshotData_t::Waypoint_t // server
{
	VectorWS position; // 0x0000
	uint32 nav_type; // 0x000C
	uint32 flags; // 0x0010
	bool is_pathcorner; // 0x0014
};
class C_INIT_RemapQAnglesToRotation : public CParticleFunctionInitializer // particles
{
	CParticleTransformInput m_TransformInput; // 0x01E0
};
class C_OP_LockToBone : public CParticleFunctionOperator // particles
{
	CParticleModelInput m_modelInput; // 0x01D8
	CParticleTransformInput m_transformInput; // 0x0238
	float32 m_flLifeTimeFadeStart; // 0x02A0
	float32 m_flLifeTimeFadeEnd; // 0x02A4
	float32 m_flJumpThreshold; // 0x02A8
	float32 m_flPrevPosScale; // 0x02AC
	char[128] m_HitboxSetName; // 0x02B0
	bool m_bRigid; // 0x0330
	bool m_bUseBones; // 0x0331
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0334
	ParticleAttributeIndex_t m_nFieldOutputPrev; // 0x0338
	ParticleRotationLockType_t m_nRotationSetType; // 0x033C
	bool m_bRigidRotationLock; // 0x0340
	CPerParticleVecInput m_vecRotation; // 0x0348
	CPerParticleFloatInput m_flRotLerp; // 0x0A00
};
class MaterialVariable_t // particles
{
	CUtlString m_strVariable; // 0x0000
	ParticleAttributeIndex_t m_nVariableField; // 0x0008
	float32 m_flScale; // 0x000C
};
class FeTri_t // physicslib
{
	uint16[3] nNode; // 0x0000
	float32 w1; // 0x0008
	float32 w2; // 0x000C
	float32 v1x; // 0x0010
	Vector2D v2; // 0x0014
};
class CNmCachedBoolNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	NmCachedValueMode_t m_mode; // 0x0014
};
class CFootMotion // modellib
{
	CUtlVector< CFootStride > m_strides; // 0x0000
	CUtlString m_name; // 0x0018
	bool m_bAdditive; // 0x0020
};
class CEnumAnimParameter : public CConcreteAnimParameter // animgraphlib
{
	uint8 m_defaultValue; // 0x0088
	CUtlVector< CUtlString > m_enumOptions; // 0x0090
	CUtlVector< uint64 > m_vecEnumReferenced; // 0x00A8
};
class InfoForResourceTypeCTestResourceData // resourcesystem
{
};
class AI_FacingServices_DebugSnapshotData_t // server
{
	VectorWS npc_position; // 0x0000
	CGlobalSymbol facing_target_source; // 0x0010
	VectorWS facing_target; // 0x0018
	CGlobalSymbol schedule_facing_priority; // 0x0028
	CGlobalSymbol strafing_source; // 0x0030
	bool strafing_enabled; // 0x0038
	CGlobalSymbol movement_id; // 0x0040
};
class AggregateSceneObject_t // worldrenderer
{
	ObjectTypeFlags_t m_allFlags; // 0x0000
	ObjectTypeFlags_t m_anyFlags; // 0x0004
	int16 m_nLayer; // 0x0008
	int16 m_instanceStream; // 0x000A
	int16 m_vertexAlbedoStream; // 0x000C
	int16 m_vertexEmissiveStream; // 0x000E
	CUtlVector< AggregateMeshInfo_t > m_aggregateMeshes; // 0x0010
	CUtlVector< AggregateLODSetup_t > m_lodSetups; // 0x0028
	CUtlVector< uint16 > m_visClusterMembership; // 0x0040
	CUtlVector< matrix3x4_t > m_fragmentTransforms; // 0x0058
	CStrongHandle< InfoForResourceTypeCModel > m_renderableModel; // 0x0070
};
class CVMixPitchShiftProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixPitchShiftDesc_t m_desc; // 0x0020
};
class CSingleFrameUpdateNode : public CLeafUpdateNode // animgraphlib
{
	CUtlVector< CSmartPtr< CAnimActionUpdater > > m_actions; // 0x0058
	CPoseHandle m_hPoseCacheHandle; // 0x0070
	HSequence m_hSequence; // 0x0074
	float32 m_flCycle; // 0x0078
};
class CNmBoneMaskSwitchNode::CDefinition : public CNmBoneMaskValueNode::CDefinition // animlib
{
	int16 m_nSwitchValueNodeIdx; // 0x0010
	int16 m_nTrueValueNodeIdx; // 0x0012
	int16 m_nFalseValueNodeIdx; // 0x0014
	float32 m_flBlendTimeSeconds; // 0x0018
	bool m_bSwitchDynamically; // 0x001C
};
class CHitReactUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	HitReactFixedSettings_t m_opFixedSettings; // 0x0070
	CAnimParamHandle m_triggerParam; // 0x00BC
	CAnimParamHandle m_hitBoneParam; // 0x00BE
	CAnimParamHandle m_hitOffsetParam; // 0x00C0
	CAnimParamHandle m_hitDirectionParam; // 0x00C2
	CAnimParamHandle m_hitStrengthParam; // 0x00C4
	float32 m_flMinDelayBetweenHits; // 0x00C8
	bool m_bResetChild; // 0x00CC
};
class CNmEventConsumerAttributes : public CNmEventConsumer // server
{
};
class C_INIT_CreateAlongPath : public CParticleFunctionInitializer // particles
{
	float32 m_fMaxDistance; // 0x01E0
	CPathParameters m_PathParams; // 0x01F0
	bool m_bUseRandomCPs; // 0x0230
	Vector m_vEndOffset; // 0x0234
	bool m_bSaveOffset; // 0x0240
};
class FeNodeWindBase_t // physicslib
{
	uint16 nNodeX0; // 0x0000
	uint16 nNodeX1; // 0x0002
	uint16 nNodeY0; // 0x0004
	uint16 nNodeY1; // 0x0006
};
class MotionIndex // animgraphlib
{
	uint16 m_nGroup; // 0x0000
	uint16 m_nMotion; // 0x0002
};
class CLeanMatrixUpdateNode : public CLeafUpdateNode // animgraphlib
{
	int32[3][3] m_frameCorners; // 0x005C
	CPoseHandle[9] m_poses; // 0x0080
	CAnimInputDamping m_damping; // 0x00A8
	AnimVectorSource m_blendSource; // 0x00C0
	CAnimParamHandle m_paramIndex; // 0x00C4
	Vector m_verticalAxis; // 0x00C8
	Vector m_horizontalAxis; // 0x00D4
	HSequence m_hSequence; // 0x00E0
	float32 m_flMaxValue; // 0x00E4
	int32 m_nSequenceMaxFrame; // 0x00E8
};
class PulseRuntimeCellIndex_t // pulse_runtime_lib
{
	int32 m_Value; // 0x0000
};
class CAnimGraphControllerPtr // server
{
	CAnimGraphControllerBase* m_pController; // 0x0000
};
class AmmoTypeInfo_t // server
{
	int32 m_nMaxCarry; // 0x0010
	CRangeInt m_nSplashSize; // 0x001C
	AmmoFlags_t m_nFlags; // 0x0024
	float32 m_flMass; // 0x0028
	CRangeFloat m_flSpeed; // 0x002C
};
class C_OP_LocalAccelerationForce : public CParticleFunctionForce // particles
{
	int32 m_nCP; // 0x01E8
	int32 m_nScaleCP; // 0x01EC
	CParticleCollectionVecInput m_vecAccel; // 0x01F0
};
class C_OP_LerpEndCapVector : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	Vector m_vecOutput; // 0x01DC
	float32 m_flLerpTime; // 0x01E8
};
class C_INIT_InheritVelocity : public CParticleFunctionInitializer // particles
{
	int32 m_nControlPointNumber; // 0x01E0
	float32 m_flVelocityScale; // 0x01E4
};
class C_OP_RampScalarLinearSimple : public CParticleFunctionOperator // particles
{
	float32 m_Rate; // 0x01D8
	float32 m_flStartTime; // 0x01DC
	float32 m_flEndTime; // 0x01E0
	ParticleAttributeIndex_t m_nField; // 0x0210
};
class C_OP_RenderClientPhysicsImpulse : public CParticleFunctionRenderer // particles
{
	CPerParticleFloatInput m_flRadius; // 0x0228
	CPerParticleFloatInput m_flMagnitude; // 0x0398
	int32 m_nSimIdFilter; // 0x0508
};
class ParticleNamedValueSource_t // particleslib
{
	CUtlString m_Name; // 0x0000
	bool m_IsPublic; // 0x0008
	CPulseValueFullType m_ValueType; // 0x0010
	ParticleNamedValueConfiguration_t m_DefaultConfig; // 0x0028
};
class CNmTimeConditionNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	int16 m_sourceStateNodeIdx; // 0x0010
	int16 m_nInputValueNodeIdx; // 0x0012
	float32 m_flComparand; // 0x0014
	CNmTimeConditionNode::ComparisonType_t m_type; // 0x0018
	CNmTimeConditionNode::Operator_t m_operator; // 0x0019
};
class CPulse_OutputConnection // pulse_runtime_lib
{
	PulseSymbol_t m_SourceOutput; // 0x0000
	PulseSymbol_t m_TargetEntity; // 0x0010
	PulseSymbol_t m_TargetInput; // 0x0020
	PulseSymbol_t m_Param; // 0x0030
};
class ChainToSolveData_t // animgraphlib
{
	int32 m_nChainIndex; // 0x0000
	IKSolverSettings_t m_SolverSettings; // 0x0004
	IKTargetSettings_t m_TargetSettings; // 0x0010
	SolveIKChainAnimNodeDebugSetting m_DebugSetting; // 0x0038
	float32 m_flDebugNormalizedValue; // 0x003C
	VectorAligned m_vDebugOffset; // 0x0040
};
class CNmFloatCurveNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	CPiecewiseCurve m_curve; // 0x0018
};
class CFlexRule // modellib
{
	int32 m_nFlex; // 0x0000
	CUtlVector< CFlexOp > m_FlexOps; // 0x0008
};
class CParticleFloatInput : public CParticleInput // particleslib
{
	ParticleFloatType_t m_nType; // 0x0010
	ParticleFloatMapType_t m_nMapType; // 0x0014
	float32 m_flLiteralValue; // 0x0018
	CParticleNamedValueRef m_NamedValue; // 0x0020
	int32 m_nControlPoint; // 0x0060
	ParticleAttributeIndex_t m_nScalarAttribute; // 0x0064
	ParticleAttributeIndex_t m_nVectorAttribute; // 0x0068
	int32 m_nVectorComponent; // 0x006C
	bool m_bReverseOrder; // 0x0070
	float32 m_flRandomMin; // 0x0074
	float32 m_flRandomMax; // 0x0078
	bool m_bHasRandomSignFlip; // 0x007C
	int32 m_nRandomSeed; // 0x0080
	ParticleFloatRandomMode_t m_nRandomMode; // 0x0084
	CUtlString m_strSnapshotSubset; // 0x0090
	float32 m_flLOD0; // 0x0098
	float32 m_flLOD1; // 0x009C
	float32 m_flLOD2; // 0x00A0
	float32 m_flLOD3; // 0x00A4
	ParticleAttributeIndex_t m_nNoiseInputVectorAttribute; // 0x00A8
	float32 m_flNoiseOutputMin; // 0x00AC
	float32 m_flNoiseOutputMax; // 0x00B0
	float32 m_flNoiseScale; // 0x00B4
	Vector m_vecNoiseOffsetRate; // 0x00B8
	float32 m_flNoiseOffset; // 0x00C4
	int32 m_nNoiseOctaves; // 0x00C8
	PFNoiseTurbulence_t m_nNoiseTurbulence; // 0x00CC
	PFNoiseType_t m_nNoiseType; // 0x00D0
	PFNoiseModifier_t m_nNoiseModifier; // 0x00D4
	float32 m_flNoiseTurbulenceScale; // 0x00D8
	float32 m_flNoiseTurbulenceMix; // 0x00DC
	float32 m_flNoiseImgPreviewScale; // 0x00E0
	bool m_bNoiseImgPreviewLive; // 0x00E4
	float32 m_flNoCameraFallback; // 0x00F0
	bool m_bUseBoundsCenter; // 0x00F4
	ParticleFloatInputMode_t m_nInputMode; // 0x00F8
	float32 m_flMultFactor; // 0x00FC
	float32 m_flInput0; // 0x0100
	float32 m_flInput1; // 0x0104
	float32 m_flOutput0; // 0x0108
	float32 m_flOutput1; // 0x010C
	float32 m_flNotchedRangeMin; // 0x0110
	float32 m_flNotchedRangeMax; // 0x0114
	float32 m_flNotchedOutputOutside; // 0x0118
	float32 m_flNotchedOutputInside; // 0x011C
	ParticleFloatRoundType_t m_nRoundType; // 0x0120
	ParticleFloatBiasType_t m_nBiasType; // 0x0124
	float32 m_flBiasParameter; // 0x0128
	CPiecewiseCurve m_Curve; // 0x0130
};
class AttachmentHandle_t // modellib
{
	uint8 m_Value; // 0x0000
};
class C_OP_RemapCPtoCP : public CParticleFunctionPreEmission // particles
{
	int32 m_nInputControlPoint; // 0x01E0
	int32 m_nOutputControlPoint; // 0x01E4
	int32 m_nInputField; // 0x01E8
	int32 m_nOutputField; // 0x01EC
	float32 m_flInputMin; // 0x01F0
	float32 m_flInputMax; // 0x01F4
	float32 m_flOutputMin; // 0x01F8
	float32 m_flOutputMax; // 0x01FC
	bool m_bDerivative; // 0x0200
	float32 m_flInterpRate; // 0x0204
};
class CSeqIKLock // animationsystem
{
	float32 m_flPosWeight; // 0x0000
	float32 m_flAngleWeight; // 0x0004
	int16 m_nLocalBone; // 0x0008
	bool m_bBonesOrientedAlongPositiveX; // 0x000A
};
class CAnimAttachment // modellib
{
	Quaternion[3] m_influenceRotations; // 0x0000
	VectorAligned[3] m_influenceOffsets; // 0x0030
	int32[3] m_influenceIndices; // 0x0060
	float32[3] m_influenceWeights; // 0x006C
	uint8 m_numInfluences; // 0x0078
};
class inv_image_map_t // client
{
	CUtlString map_name; // 0x0000
	float32 map_rotation; // 0x0008
};
class AggregateRTProxySceneObject_t // worldrenderer
{
	int16 m_nLayer; // 0x0000
	CUtlVector< RTProxyBLAS_t > m_BLASes; // 0x0008
	CUtlVector< RTProxyInstanceInfo_t > m_Instances; // 0x0020
	CUtlBinaryBlock m_VBData; // 0x0038
	CUtlBinaryBlock m_IBData; // 0x0048
	CUtlBinaryBlock m_InstanceAlbedoData; // 0x0058
	CUtlBinaryBlock m_InstanceEmissiveData; // 0x0068
};
class CVoxelVisibility // worldrenderer
{
	uint32 m_nBaseClusterCount; // 0x0040
	uint32 m_nPVSBytesPerCluster; // 0x0044
	Vector m_vMinBounds; // 0x0048
	Vector m_vMaxBounds; // 0x0054
	float32 m_flGridSize; // 0x0060
	uint32 m_nSkyVisibilityCluster; // 0x0064
	uint32 m_nSunVisibilityCluster; // 0x0068
	VoxelVisBlockOffset_t m_NodeBlock; // 0x006C
	VoxelVisBlockOffset_t m_RegionBlock; // 0x0074
	VoxelVisBlockOffset_t m_EnclosedClusterListBlock; // 0x007C
	VoxelVisBlockOffset_t m_EnclosedClustersBlock; // 0x0084
	VoxelVisBlockOffset_t m_MasksBlock; // 0x008C
	VoxelVisBlockOffset_t m_nVisBlocks; // 0x0094
};
class VMixModDelayDesc_t // soundsystem_lowlevel
{
	VMixFilterDesc_t m_feedbackFilter; // 0x0000
	bool m_bPhaseInvert; // 0x0010
	float32 m_flGlideTime; // 0x0014
	float32 m_flDelay; // 0x0018
	float32 m_flOutputGain; // 0x001C
	float32 m_flFeedbackGain; // 0x0020
	float32 m_flModRate; // 0x0024
	float32 m_flModDepth; // 0x0028
	bool m_bApplyAntialiasing; // 0x002C
};
class IPhysAggregateInstance : public IPhysicsBodyList // vphysics2
{
	void* m_pSkeleton; // 0x0008
	bool m_bIsAxisAligned; // 0x0010
};
class SkeletonAnimCapture_t::FrameStamp_t // modellib
{
	float32 m_flTime; // 0x0000
	float32 m_flEntitySimTime; // 0x0004
	bool m_bTeleportTick; // 0x0008
	bool m_bPredicted; // 0x0009
	float32 m_flCurTime; // 0x000C
	float32 m_flRealTime; // 0x0010
	int32 m_nFrameCount; // 0x0014
	int32 m_nTickCount; // 0x0018
};
class NmSyncTrackTime_t // animlib
{
	int32 m_nEventIdx; // 0x0000
	NmPercent_t m_percentageThrough; // 0x0004
};
class CNmBoneMaskNode::CDefinition : public CNmBoneMaskValueNode::CDefinition // animlib
{
	CGlobalSymbol m_boneMaskID; // 0x0010
};
class CFootStepTriggerUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	CUtlVector< FootStepTrigger > m_triggers; // 0x0070
	float32 m_flTolerance; // 0x008C
};
class C_INIT_VelocityRadialRandom : public CParticleFunctionInitializer // particles
{
	bool m_bPerParticleCenter; // 0x01E0
	int32 m_nControlPointNumber; // 0x01E4
	CPerParticleVecInput m_vecPosition; // 0x01E8
	CPerParticleVecInput m_vecFwd; // 0x08A0
	CPerParticleFloatInput m_fSpeedMin; // 0x0F58
	CPerParticleFloatInput m_fSpeedMax; // 0x10C8
	Vector m_vecLocalCoordinateSystemSpeedScale; // 0x1238
	bool m_bIgnoreDelta; // 0x1245
};
class C_INIT_RemapNamedModelMeshGroupToScalar : public C_INIT_RemapNamedModelElementToScalar // particles
{
};
class EntityIOConnectionData_t // worldrenderer
{
	CUtlString m_outputName; // 0x0000
	uint32 m_targetType; // 0x0008
	CUtlString m_targetName; // 0x0010
	CUtlString m_inputName; // 0x0018
	CUtlString m_overrideParam; // 0x0020
	float32 m_flDelay; // 0x0028
	int32 m_nTimesToFire; // 0x002C
	KeyValues3 m_paramMap; // 0x0030
};
class CParamSpanUpdater // animgraphlib
{
	CUtlVector< ParamSpan_t > m_spans; // 0x0000
};
class CParticleCollectionRendererFloatInput : public CParticleCollectionFloatInput // particleslib
{
};
class CNmFloatRangeComparisonNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	Range_t m_range; // 0x0010
	int16 m_nInputValueNodeIdx; // 0x0018
	bool m_bIsInclusiveCheck; // 0x001A
};
class InfoForResourceTypeIAnimGraphModelBinding // resourcesystem
{
};
class InfoForResourceTypeIParticleSnapshot // resourcesystem
{
};
class globalentity_t // server
{
	CUtlSymbol name; // 0x0000
	CUtlSymbol levelName; // 0x0002
	GLOBALESTATE state; // 0x0004
	int32 counter; // 0x0008
};
class C_OP_SetControlPointToVectorExpression : public CParticleFunctionPreEmission // particles
{
	VectorExpressionType_t m_nExpression; // 0x01E0
	int32 m_nOutputCP; // 0x01E4
	CParticleCollectionVecInput m_vInput1; // 0x01E8
	CParticleCollectionVecInput m_vInput2; // 0x08A0
	CPerParticleFloatInput m_flLerp; // 0x0F58
	bool m_bNormalizedOutput; // 0x10C8
};
class CPathParameters // particles
{
	int32 m_nStartControlPointNumber; // 0x0000
	int32 m_nEndControlPointNumber; // 0x0004
	int32 m_nBulgeControl; // 0x0008
	float32 m_flBulge; // 0x000C
	float32 m_flMidPoint; // 0x0010
	Vector m_vStartPointOffset; // 0x0014
	Vector m_vMidPointOffset; // 0x0020
	Vector m_vEndOffset; // 0x002C
};
class C_INIT_InitFromVectorFieldSnapshot : public CParticleFunctionInitializer // particles
{
	int32 m_nControlPointNumber; // 0x01E0
	int32 m_nLocalSpaceCP; // 0x01E4
	int32 m_nWeightUpdateCP; // 0x01E8
	bool m_bUseVerticalVelocity; // 0x01EC
	CPerParticleVecInput m_vecScale; // 0x01F0
};
class CSosGroupActionSoundeventCountSchema : public CSosGroupActionSchema // soundsystem
{
	bool m_bExcludeStoppedSounds; // 0x0008
	CUtlString m_strCountKeyName; // 0x0010
};
class CVoiceContainerTapePlayer : public CVoiceContainerAsyncGenerator // soundsystem_voicecontainers
{
	bool m_bShouldWraparound; // 0x0080
	CStrongHandle< InfoForResourceTypeCVoiceContainerBase > m_sourceAudio; // 0x0088
	float32 m_flTapeSpeedAttackTime; // 0x0090
	float32 m_flTapeSpeedReleaseTime; // 0x0094
};
class CNmVirtualParameterVectorNode::CDefinition : public CNmVectorValueNode::CDefinition // animlib
{
	int16 m_nChildNodeIdx; // 0x0010
};
class CNmConstIDNode::CDefinition : public CNmIDValueNode::CDefinition // animlib
{
	CGlobalSymbol m_value; // 0x0010
};
class CFootAdjustmentInstanceData // animgraphlib
{
	CAnimNetVar< float32 > m_flStartTime; // 0x000C
	CAnimNetVar< float32 > m_flDuration; // 0x0018
	float32 m_flStartHeadingWS; // 0x003C
};
class EventServerPostAdvanceTick_t : public EventPostAdvanceTick_t // engine2
{
	bool m_bLastTickBeforeClientUpdate; // 0x0040
};
class TextureControls_t // particles
{
	CParticleCollectionRendererFloatInput m_flFinalTextureScaleU; // 0x0000
	CParticleCollectionRendererFloatInput m_flFinalTextureScaleV; // 0x0170
	CParticleCollectionRendererFloatInput m_flFinalTextureOffsetU; // 0x02E0
	CParticleCollectionRendererFloatInput m_flFinalTextureOffsetV; // 0x0450
	CParticleCollectionRendererFloatInput m_flFinalTextureUVRotation; // 0x05C0
	CParticleCollectionRendererFloatInput m_flZoomScale; // 0x0730
	CParticleCollectionRendererFloatInput m_flDistortion; // 0x08A0
	bool m_bRandomizeOffsets; // 0x0A10
	bool m_bClampUVs; // 0x0A11
	SpriteCardPerParticleScale_t m_nPerParticleBlend; // 0x0A14
	SpriteCardPerParticleScale_t m_nPerParticleScale; // 0x0A18
	SpriteCardPerParticleScale_t m_nPerParticleOffsetU; // 0x0A1C
	SpriteCardPerParticleScale_t m_nPerParticleOffsetV; // 0x0A20
	SpriteCardPerParticleScale_t m_nPerParticleRotation; // 0x0A24
	SpriteCardPerParticleScale_t m_nPerParticleZoom; // 0x0A28
	SpriteCardPerParticleScale_t m_nPerParticleDistortion; // 0x0A2C
};
class PermEntityLumpData_t // worldrenderer
{
	CUtlString m_name; // 0x0008
	CUtlVector< CStrongHandleCopyable< InfoForResourceTypeCEntityLump > > m_childLumps; // 0x0010
	CUtlLeanVector< EntityKeyValueData_t > m_entityKeyValues; // 0x0028
};
class VMixPitchShiftDesc_t // soundsystem_lowlevel
{
	int32 m_nGrainSampleCount; // 0x0000
	float32 m_flPitchShift; // 0x0004
	int32 m_nQuality; // 0x0008
	int32 m_nProcType; // 0x000C
};
class CNmVectorInfoNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	CNmVectorInfoNode::Info_t m_desiredInfo; // 0x0012
};
class CModelConfigList // modellib
{
	bool m_bHideMaterialGroupInTools; // 0x0000
	bool m_bHideRenderColorInTools; // 0x0001
	CUtlVector< CModelConfig* > m_Configs; // 0x0008
};
class CNmCurrentSyncEventIDNode::CDefinition : public CNmIDValueNode::CDefinition // animlib
{
	int16 m_nSourceStateNodeIdx; // 0x0010
};
class CFootTrajectory // modellib
{
	Vector m_vOffset; // 0x0008
	float32 m_flRotationOffset; // 0x0014
	float32 m_flProgression; // 0x0018
};
class CEntityKeyValues // entity2
{
};
class InfoForResourceTypeCResponseRulesList // resourcesystem
{
};
class SimpleConstraintSoundProfile // server
{
	float32 m_flKeyPointMinSoundThreshold; // 0x0008
	float32 m_flKeyPointMaxSoundThreshold; // 0x000C
	float32 m_reversalSoundThresholdSmall; // 0x0010
	float32 m_reversalSoundThresholdMedium; // 0x0014
	float32 m_reversalSoundThresholdLarge; // 0x0018
};
class AggregateVertexAlbedoStreamOnDiskData_t // worldrenderer
{
	CUtlBinaryBlock m_BufferData; // 0x0000
};
class AnimationSnapshot_t : public AnimationSnapshotBase_t // animationsystem
{
	int32 m_nEntIndex; // 0x0110
	CUtlString m_modelName; // 0x0118
};
class LookAtBone_t // animgraphlib
{
	int32 m_index; // 0x0000
	float32 m_weight; // 0x0004
};
class CNmValueNode::CDefinition : public CNmGraphNode::CDefinition // animlib
{
};
class CBlendNodeInstanceData // animgraphlib
{
	float32 m_dampedValue; // 0x0000
	float32 m_flCycle; // 0x0004
	float32 m_flCycleZeroTime; // 0x0008
	float32 m_flPlaybackRate; // 0x000C
	CAnimNetVar< float32 > m_flBlendValue; // 0x0010
	float32 m_flDuration; // 0x001C
	CAnimNetVar< uint8 > m_resetCount; // 0x0020
};
class VMixDynamicsBand_t // soundsystem_lowlevel
{
	float32 m_fldbGainInput; // 0x0000
	float32 m_fldbGainOutput; // 0x0004
	float32 m_fldbThresholdBelow; // 0x0008
	float32 m_fldbThresholdAbove; // 0x000C
	float32 m_flRatioBelow; // 0x0010
	float32 m_flRatioAbove; // 0x0014
	float32 m_flAttackTimeMS; // 0x0018
	float32 m_flReleaseTimeMS; // 0x001C
	bool m_bEnable; // 0x0020
	bool m_bSolo; // 0x0021
};
class CStateNodeInstanceData // animgraphlib
{
	CRelativeArray< float32 > m_stateWeights; // 0x0000
	Vector m_vTransitionVelocityDeltaWS; // 0x0008
	CAnimNetVar< float32 > m_currentStateStartTime; // 0x0020
	CAnimNetVar< uint8 > m_resetCount; // 0x003C
};
class CPulse_RegisterInfo // pulse_runtime_lib
{
	PulseRuntimeRegisterIndex_t m_nReg; // 0x0000
	CPulseValueFullType m_Type; // 0x0008
	CKV3MemberNameWithStorage m_OriginName; // 0x0020
	int32 m_nWrittenByInstruction; // 0x0058
	int32 m_nLastReadByInstruction; // 0x005C
};
class CNmAnimationPoseNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
	int16 m_nPoseTimeValueNodeIdx; // 0x0010
	int16 m_nDataSlotIdx; // 0x0012
	Range_t m_inputTimeRemapRange; // 0x0014
	float32 m_flUserSpecifiedTime; // 0x001C
	bool m_bUseFramesAsInput; // 0x0020
};
class NavGravity_t // navlib
{
	Vector m_vGravity; // 0x0000
	bool m_bDefault; // 0x000C
};
class C_INIT_CreateSequentialPath : public CParticleFunctionInitializer // particles
{
	float32 m_fMaxDistance; // 0x01E0
	float32 m_flNumToAssign; // 0x01E4
	bool m_bLoop; // 0x01E8
	bool m_bCPPairs; // 0x01E9
	bool m_bSaveOffset; // 0x01EA
	CPathParameters m_PathParams; // 0x01F0
};
class C_OP_SetUserEvent : public CParticleFunctionOperator // particles
{
	CPerParticleFloatInput m_flInput; // 0x01D8
	CPerParticleFloatInput m_flRisingEdge; // 0x0348
	EventTypeSelection_t m_nRisingEventType; // 0x04B8
	CPerParticleFloatInput m_flFallingEdge; // 0x04C0
	EventTypeSelection_t m_nFallingEventType; // 0x0630
};
class VMixUtilityDesc_t // soundsystem_lowlevel
{
	VMixChannelOperation_t m_nOp; // 0x0000
	float32 m_flInputPan; // 0x0004
	float32 m_flOutputBalance; // 0x0008
	float32 m_fldbOutputGain; // 0x000C
	bool m_bBassMono; // 0x0010
	float32 m_flBassFreq; // 0x0014
};
class FeTaperedCapsuleRigid_t // physicslib
{
	fltx4[2] vSphere; // 0x0000
	uint16 nNode; // 0x0020
	uint16 nCollisionMask; // 0x0022
	uint16 nVertexMapIndex; // 0x0024
	uint16 nFlags; // 0x0026
};
class CMotionGraphGroup // animgraphlib
{
	CMotionSearchDB m_searchDB; // 0x0000
	CUtlVector< CSmartPtr< CMotionGraph > > m_motionGraphs; // 0x00B8
	CUtlVector< CMotionGraphConfig > m_motionGraphConfigs; // 0x00D0
	CUtlVector< int32 > m_sampleToConfig; // 0x00E8
	AnimScriptHandle m_hIsActiveScript; // 0x0100
};
class CBtNode // server
{
};
class C_OP_ClampScalar : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	CPerParticleFloatInput m_flOutputMin; // 0x01E0
	CPerParticleFloatInput m_flOutputMax; // 0x0350
};
class CFollowPathInstanceData // animgraphlib
{
	CRelativeArray< CMotionTransform > m_xLastPredictedTransformsDeltas; // 0x0000
	float32 m_dampedTurnValue; // 0x0008
	float32 m_flTurnAmount; // 0x000C
	CAnimNetVar< float32 > m_flPredictionScale; // 0x0010
	float32 m_flLastPathTime; // 0x001C
};
class C_OP_WorldTraceConstraint : public CParticleFunctionConstraint // particles
{
	int32 m_nCP; // 0x01D8
	Vector m_vecCpOffset; // 0x01DC
	ParticleCollisionMode_t m_nCollisionMode; // 0x01E8
	ParticleCollisionMode_t m_nCollisionModeMin; // 0x01EC
	ParticleTraceSet_t m_nTraceSet; // 0x01F0
	char[128] m_CollisionGroupName; // 0x01F4
	bool m_bWorldOnly; // 0x0274
	bool m_bBrushOnly; // 0x0275
	bool m_bIncludeWater; // 0x0276
	int32 m_nIgnoreCP; // 0x0278
	float32 m_flCpMovementTolerance; // 0x027C
	float32 m_flRetestRate; // 0x0280
	float32 m_flTraceTolerance; // 0x0284
	float32 m_flCollisionConfirmationSpeed; // 0x0288
	float32 m_nMaxTracesPerFrame; // 0x028C
	CPerParticleFloatInput m_flRadiusScale; // 0x0290
	CPerParticleFloatInput m_flBounceAmount; // 0x0400
	CPerParticleFloatInput m_flSlideAmount; // 0x0570
	CPerParticleFloatInput m_flRandomDirScale; // 0x06E0
	bool m_bDecayBounce; // 0x0850
	bool m_bKillonContact; // 0x0851
	float32 m_flMinSpeed; // 0x0854
	bool m_bSetNormal; // 0x0858
	ParticleAttributeIndex_t m_nStickOnCollisionField; // 0x085C
	CPerParticleFloatInput m_flStopSpeed; // 0x0860
	ParticleAttributeIndex_t m_nEntityStickDataField; // 0x09D0
	ParticleAttributeIndex_t m_nEntityStickNormalField; // 0x09D4
};
class C_INIT_RemapInitialVisibilityScalar : public CParticleFunctionInitializer // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E4
	float32 m_flInputMin; // 0x01E8
	float32 m_flInputMax; // 0x01EC
	float32 m_flOutputMin; // 0x01F0
	float32 m_flOutputMax; // 0x01F4
};
class CStateMachineComponentUpdater : public CAnimComponentUpdater // animgraphlib
{
	CAnimStateMachineUpdater m_stateMachine; // 0x0030
};
class CAnimEnum // animationsystem
{
	uint8 m_value; // 0x0000
};
class CMeshletDescriptor // modellib
{
	PackedAABB_t m_PackedAABB; // 0x0000
	CDrawCullingData m_CullingData; // 0x0008
	uint32 m_nVertexOffset; // 0x000C
	uint32 m_nTriangleOffset; // 0x0010
	uint8 m_nVertexCount; // 0x0014
	uint8 m_nTriangleCount; // 0x0015
};
class CRagdollUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	int32 m_nWeightListIndex; // 0x0070
	RagdollPoseControl m_poseControlMethod; // 0x0074
};
class PulseRuntimeStateOffset_t // pulse_runtime_lib
{
	uint16 m_Value; // 0x0000
};
class PostProcessingFogScatteringParameters_t // materialsystem2
{
	float32 m_fRadius; // 0x0000
	float32 m_fScale; // 0x0004
	float32 m_fCubemapScale; // 0x0008
	float32 m_fVolumetricScale; // 0x000C
	float32 m_fGradientScale; // 0x0010
	float32 m_fWaterScale; // 0x0014
	float32 m_fWaterDensity; // 0x0018
	float32 m_fWaterDepthBlurRadius; // 0x001C
};
class C_INIT_RemapParticleCountToNamedModelSequenceScalar : public C_INIT_RemapParticleCountToNamedModelElementScalar // particles
{
};
class SndBeatTimeSignature_t // soundsystem
{
	uint8 nNumerator; // 0x0000
	uint8 nDenominator; // 0x0001
};
class CPairedSequenceUpdateNode : public CSequenceUpdateNodeBase // animgraphlib
{
	CGlobalSymbol m_sPairedSequenceRole; // 0x0078
};
class FootLockPoseOpFixedSettings // animgraphlib
{
	CUtlVector< FootFixedData_t > m_footInfo; // 0x0000
	CAnimInputDamping m_hipDampingSettings; // 0x0018
	int32 m_nHipBoneIndex; // 0x0030
	IKSolverType m_ikSolverType; // 0x0034
	bool m_bApplyTilt; // 0x0038
	bool m_bApplyHipDrop; // 0x0039
	bool m_bAlwaysUseFallbackHinge; // 0x003A
	bool m_bApplyFootRotationLimits; // 0x003B
	bool m_bApplyLegTwistLimits; // 0x003C
	float32 m_flMaxFootHeight; // 0x0040
	float32 m_flExtensionScale; // 0x0044
	float32 m_flMaxLegTwist; // 0x0048
	bool m_bEnableLockBreaking; // 0x004C
	float32 m_flLockBreakTolerance; // 0x0050
	float32 m_flLockBlendTime; // 0x0054
	bool m_bEnableStretching; // 0x0058
	float32 m_flMaxStretchAmount; // 0x005C
	float32 m_flStretchExtensionScale; // 0x0060
};
class PulseCursorYieldToken_t // pulse_runtime_lib
{
	int32 m_Value; // 0x0000
};
class PostProcessingVignetteParameters_t // materialsystem2
{
	float32 m_flVignetteStrength; // 0x0000
	Vector2D m_vCenter; // 0x0004
	float32 m_flRadius; // 0x000C
	float32 m_flRoundness; // 0x0010
	float32 m_flFeather; // 0x0014
	Vector m_vColorTint; // 0x0018
};
class inv_image_light_barn_t // client
{
	Vector color; // 0x0000
	QAngle angle; // 0x000C
	float32 brightness; // 0x0018
	float32 orbit_distance; // 0x001C
};
class C_OP_VectorFieldSnapshot : public CParticleFunctionOperator // particles
{
	int32 m_nControlPointNumber; // 0x01D8
	ParticleAttributeIndex_t m_nAttributeToWrite; // 0x01DC
	int32 m_nLocalSpaceCP; // 0x01E0
	CPerParticleFloatInput m_flInterpolation; // 0x01E8
	CPerParticleVecInput m_vecScale; // 0x0358
	float32 m_flBoundaryDampening; // 0x0A10
	bool m_bSetVelocity; // 0x0A14
	bool m_bLockToSurface; // 0x0A15
	float32 m_flGridSpacing; // 0x0A18
};
class CSSDSMsg_PostLayer : public CSSDSMsg_LayerBase // scenesystem
{
};
class FeWeightedNode_t // physicslib
{
	uint16 nNode; // 0x0000
	uint16 nWeight; // 0x0002
};
class CNmTargetSelectorNode::CDefinition : public CNmClipReferenceNode::CDefinition // animlib
{
	CUtlLeanVectorFixedGrowable< int16, 8 > m_optionNodeIndices; // 0x0010
	float32 m_flOrientationScoreWeight; // 0x0028
	float32 m_flPositionScoreWeight; // 0x002C
	int16 m_parameterNodeIdx; // 0x0030
	bool m_bIgnoreInvalidOptions; // 0x0032
	bool m_bIsWorldSpaceTarget; // 0x0033
};
class CCurrentRotationVelocityMetricEvaluator : public CMotionMetricEvaluator // animgraphlib
{
};
class QuestProgress // server
{
};
class C_OP_RemapVelocityToVector : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	float32 m_flScale; // 0x01DC
	bool m_bNormalize; // 0x01E0
};
class C_INIT_CreateOnGrid : public CParticleFunctionInitializer // particles
{
	CParticleCollectionFloatInput m_nXCount; // 0x01E0
	CParticleCollectionFloatInput m_nYCount; // 0x0350
	CParticleCollectionFloatInput m_nZCount; // 0x04C0
	CParticleCollectionFloatInput m_nXSpacing; // 0x0630
	CParticleCollectionFloatInput m_nYSpacing; // 0x07A0
	CParticleCollectionFloatInput m_nZSpacing; // 0x0910
	int32 m_nControlPointNumber; // 0x0A80
	bool m_bLocalSpace; // 0x0A84
	bool m_bCenter; // 0x0A85
	bool m_bHollow; // 0x0A86
};
class C_OP_SetControlPointToCPVelocity : public CParticleFunctionPreEmission // particles
{
	int32 m_nCPInput; // 0x01E0
	int32 m_nCPOutputVel; // 0x01E4
	bool m_bNormalize; // 0x01E8
	int32 m_nCPOutputMag; // 0x01EC
	int32 m_nCPField; // 0x01F0
	CParticleCollectionVecInput m_vecComparisonVelocity; // 0x01F8
};
class CDspPresetModifierList // soundsystem
{
	CUtlString m_dspName; // 0x0000
	CUtlVector< CDSPMixgroupModifier > m_modifiers; // 0x0008
};
class FeBoneMergeLink_t // physicslib
{
	uint32 m_nParentHash; // 0x0000
	uint16 m_nChildNode; // 0x0004
};
class FeKelagerBend2_t // physicslib
{
	float32[3] flWeight; // 0x0000
	float32 flHeight0; // 0x000C
	uint16[3] nNode; // 0x0010
	uint16 nReserved; // 0x0016
};
class CNmVelocityBlendNode::CDefinition : public CNmParameterizedBlendNode::CDefinition // animlib
{
};
class InfoForResourceTypeCSequenceGroupData // resourcesystem
{
};
class CFlashlightEffect // client
{
	bool m_bIsOn; // 0x0010
	bool m_bMuzzleFlashEnabled; // 0x0020
	float32 m_flMuzzleFlashBrightness; // 0x0024
	Quaternion m_quatMuzzleFlashOrientation; // 0x0030
	VectorWS m_vecMuzzleFlashOrigin; // 0x0040
	float32 m_flFov; // 0x004C
	float32 m_flFarZ; // 0x0050
	float32 m_flLinearAtten; // 0x0054
	bool m_bCastsShadows; // 0x0058
	float32 m_flCurrentPullBackDist; // 0x005C
	CStrongHandle< InfoForResourceTypeCTextureBase > m_FlashlightTexture; // 0x0060
	CStrongHandle< InfoForResourceTypeCTextureBase > m_MuzzleFlashTexture; // 0x0068
	char[64] m_textureName; // 0x0070
};
class C_OP_ControlpointLight : public CParticleFunctionOperator // particles
{
	float32 m_flScale; // 0x01D8
	int32 m_nControlPoint1; // 0x0660
	int32 m_nControlPoint2; // 0x0664
	int32 m_nControlPoint3; // 0x0668
	int32 m_nControlPoint4; // 0x066C
	Vector m_vecCPOffset1; // 0x0670
	Vector m_vecCPOffset2; // 0x067C
	Vector m_vecCPOffset3; // 0x0688
	Vector m_vecCPOffset4; // 0x0694
	float32 m_LightFiftyDist1; // 0x06A0
	float32 m_LightZeroDist1; // 0x06A4
	float32 m_LightFiftyDist2; // 0x06A8
	float32 m_LightZeroDist2; // 0x06AC
	float32 m_LightFiftyDist3; // 0x06B0
	float32 m_LightZeroDist3; // 0x06B4
	float32 m_LightFiftyDist4; // 0x06B8
	float32 m_LightZeroDist4; // 0x06BC
	Color m_LightColor1; // 0x06C0
	Color m_LightColor2; // 0x06C4
	Color m_LightColor3; // 0x06C8
	Color m_LightColor4; // 0x06CC
	bool m_bLightType1; // 0x06D0
	bool m_bLightType2; // 0x06D1
	bool m_bLightType3; // 0x06D2
	bool m_bLightType4; // 0x06D3
	bool m_bLightDynamic1; // 0x06D4
	bool m_bLightDynamic2; // 0x06D5
	bool m_bLightDynamic3; // 0x06D6
	bool m_bLightDynamic4; // 0x06D7
	bool m_bUseNormal; // 0x06D8
	bool m_bUseHLambert; // 0x06D9
	bool m_bClampLowerRange; // 0x06DE
	bool m_bClampUpperRange; // 0x06DF
};
class ParticleControlPointConfiguration_t // particles
{
	CUtlString m_name; // 0x0000
	CUtlVector< ParticleControlPointDriver_t > m_drivers; // 0x0008
	ParticlePreviewState_t m_previewState; // 0x0020
};
class CVMixModDelayProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixModDelayDesc_t m_desc; // 0x0020
};
class CNmIDValueNode::CDefinition : public CNmValueNode::CDefinition // animlib
{
};
class CAnimMorphDifference // animationsystem
{
	CBufferString m_name; // 0x0000
};
class CBaseIssue // server
{
	char[64] m_szTypeString; // 0x0020
	char[260] m_szDetailsString; // 0x0060
	int32 m_iNumYesVotes; // 0x0164
	int32 m_iNumNoVotes; // 0x0168
	int32 m_iNumPotentialVotes; // 0x016C
	CVoteController* m_pVoteController; // 0x0170
};
class C_OP_RemapGravityToVector : public CParticleFunctionOperator // particles
{
	CPerParticleVecInput m_vInput1; // 0x01D8
	ParticleAttributeIndex_t m_nOutputField; // 0x0890
	ParticleSetMethod_t m_nSetMethod; // 0x0894
	bool m_bNormalizedOutput; // 0x0898
};
class C_INIT_VelocityFromNormal : public CParticleFunctionInitializer // particles
{
	float32 m_fSpeedMin; // 0x01E0
	float32 m_fSpeedMax; // 0x01E4
	bool m_bIgnoreDt; // 0x01E8
};
class CSSDSEndFrameViewInfo // scenesystem
{
	uint64 m_nViewId; // 0x0000
	CUtlString m_ViewName; // 0x0008
};
class CSosGroupActionSoundeventPrioritySchema : public CSosGroupActionSchema // soundsystem
{
	CUtlString m_priorityValue; // 0x0008
	CUtlString m_priorityVolumeScalar; // 0x0010
	CUtlString m_priorityContributeButDontRead; // 0x0018
	CUtlString m_bPriorityReadButDontContribute; // 0x0020
};
class FeSourceEdge_t // physicslib
{
	uint16[2] nNode; // 0x0000
};
class CNmStateMachineNode::StateDefinition_t // animlib
{
	int16 m_nStateNodeIdx; // 0x0000
	int16 m_nEntryConditionNodeIdx; // 0x0002
	CUtlLeanVectorFixedGrowable< CNmStateMachineNode::TransitionDefinition_t, 5 > m_transitionDefinitions; // 0x0008
};
class CChoreoUpdateNode : public CUnaryUpdateNode // animgraphlib
{
};
class CStepsRemainingMetricEvaluator : public CMotionMetricEvaluator // animgraphlib
{
	CUtlVector< int32 > m_footIndices; // 0x0050
	float32 m_flMinStepsRemaining; // 0x0068
};
class CNmIsExternalGraphSlotFilledNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	int16 m_nExternalGraphNodeIdx; // 0x0010
};
class CBoneConstraintPoseSpaceBone::Input_t // modellib
{
	Vector m_inputValue; // 0x0000
	CUtlVector< CTransform > m_outputTransformList; // 0x0010
};
class VPhysics2ShapeDef_t // modellib
{
	CUtlVector< RnSphereDesc_t > m_spheres; // 0x0000
	CUtlVector< RnCapsuleDesc_t > m_capsules; // 0x0018
	CUtlVector< RnHullDesc_t > m_hulls; // 0x0030
	CUtlVector< RnMeshDesc_t > m_meshes; // 0x0048
	CUtlVector< uint16 > m_CollisionAttributeIndices; // 0x0060
};
class CNmVirtualParameterBoolNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	int16 m_nChildNodeIdx; // 0x0010
};
class RTProxyBLAS_t // worldrenderer
{
	uint32 m_nFirstIndex; // 0x0000
	uint32 m_nIndexCount; // 0x0004
	uint32 m_nVBByteOffset; // 0x0008
	uint32 m_nBaseVertex; // 0x000C
	uint16 m_nVertexCount; // 0x0010
	VertexAlbedoFormat_t m_albedoFormat; // 0x0012
	AABB_t m_boundLs; // 0x0014
	Vector m_vVertexOriginLs; // 0x002C
	Vector m_vVertexExtentLs; // 0x0038
};
class CVMixPlateReverbProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixPlateverbDesc_t m_desc; // 0x0020
};
class CVMixBoxverb2ProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixBoxverbDesc_t m_desc; // 0x0020
};
class JiggleBoneSettingsList_t // animgraphlib
{
	CUtlVector< JiggleBoneSettings_t > m_boneSettings; // 0x0000
};
class CNmControlParameterTargetNode::CDefinition : public CNmTargetValueNode::CDefinition // animlib
{
};
class FourQuaternions // mathlib_extended
{
	fltx4 x; // 0x0000
	fltx4 y; // 0x0010
	fltx4 z; // 0x0020
	fltx4 w; // 0x0030
};
class C_OP_ChooseRandomChildrenInGroup : public CParticleFunctionPreEmission // particles
{
	int32 m_nChildGroupID; // 0x01E0
	CParticleCollectionFloatInput m_flNumberOfChildren; // 0x01E8
};
class C_OP_Cull : public CParticleFunctionOperator // particles
{
	float32 m_flCullPerc; // 0x01D8
	float32 m_flCullStart; // 0x01DC
	float32 m_flCullEnd; // 0x01E0
	float32 m_flCullExp; // 0x01E4
};
class AggregateMeshInfo_t // worldrenderer
{
	uint32 m_nVisClusterMemberOffset; // 0x0000
	uint8 m_nVisClusterMemberCount; // 0x0004
	bool m_bHasTransform; // 0x0005
	uint8 m_nLODGroupMask; // 0x0006
	int16 m_nDrawCallIndex; // 0x0008
	int16 m_nLODSetupIndex; // 0x000A
	Color m_vTintColor; // 0x000C
	ObjectTypeFlags_t m_objectFlags; // 0x0010
	int32 m_nLightProbeVolumePrecomputedHandshake; // 0x0014
	uint32 m_nInstanceStreamOffset; // 0x0018
	uint32 m_nVertexAlbedoStreamOffset; // 0x001C
	uint32 m_nVertexEmissiveStreamOffset; // 0x0020
	AggregateInstanceStream_t m_instanceStreams; // 0x0024
	float32 m_fEmissiveFactor; // 0x0028
};
class CVMixSteamAudioDirectProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
};
class FeCtrlSoftOffset_t // physicslib
{
	uint16 nCtrlParent; // 0x0000
	uint16 nCtrlChild; // 0x0002
	Vector vOffset; // 0x0004
	float32 flAlpha; // 0x0010
};
class CAnimActivity // animationsystem
{
	CBufferString m_name; // 0x0000
	int32 m_nActivity; // 0x0010
	int32 m_nFlags; // 0x0014
	int32 m_nWeight; // 0x0018
};
class MotionMatchingInstanceData // animgraphlib
{
	MotionSelection m_currentSelection; // 0x002C
	MotionSelection m_previousSelection; // 0x0084
};
class CNmFloatRemapNode::RemapRange_t // animlib
{
	float32 m_flBegin; // 0x0000
	float32 m_flEnd; // 0x0004
};
class CDampedValueUpdateItem // animgraphlib
{
	CAnimInputDamping m_damping; // 0x0000
	CAnimParamHandle m_hParamIn; // 0x0020
	CAnimParamHandle m_hParamOut; // 0x0022
};
class CFutureFacingMetricEvaluator : public CMotionMetricEvaluator // animgraphlib
{
	float32 m_flDistance; // 0x0050
	float32 m_flTime; // 0x0054
};
class NmBoneMaskSetDefinition_t // animlib
{
	CGlobalSymbol m_ID; // 0x0000
	CNmBoneWeightList m_primaryWeightList; // 0x0008
	CUtlLeanVector< CNmBoneWeightList > m_secondaryWeightLists; // 0x0118
};
class modifiedconvars_t // server
{
	char[128] pszConvar; // 0x0000
	char[128] pszCurrentValue; // 0x0080
	char[128] pszOrgValue; // 0x0100
};
class physics_save_sphere_t // server
{
	float32 radius; // 0x0000
};
class C_OP_RemapControlPointOrientationToRotation : public CParticleFunctionOperator // particles
{
	int32 m_nCP; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
	float32 m_flOffsetRot; // 0x01E0
	int32 m_nComponent; // 0x01E4
};
class C_OP_RenderTreeShake : public CParticleFunctionRenderer // particles
{
	float32 m_flPeakStrength; // 0x0228
	ParticleAttributeIndex_t m_nPeakStrengthFieldOverride; // 0x022C
	float32 m_flRadius; // 0x0230
	ParticleAttributeIndex_t m_nRadiusFieldOverride; // 0x0234
	float32 m_flShakeDuration; // 0x0238
	float32 m_flTransitionTime; // 0x023C
	float32 m_flTwistAmount; // 0x0240
	float32 m_flRadialAmount; // 0x0244
	float32 m_flControlPointOrientationAmount; // 0x0248
	int32 m_nControlPointForLinearDirection; // 0x024C
};
class C_OP_RotateVector : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	Vector m_vecRotAxisMin; // 0x01DC
	Vector m_vecRotAxisMax; // 0x01E8
	float32 m_flRotRateMin; // 0x01F4
	float32 m_flRotRateMax; // 0x01F8
	bool m_bNormalize; // 0x01FC
	CPerParticleFloatInput m_flScale; // 0x0200
};
class CSteamAudioBakedReverbData // steamaudio
{
	int32 m_nBands; // 0x0000
	CSteamAudioSceneData m_scene; // 0x0008
	CSteamAudioProbeData m_probes; // 0x0018
	CSteamAudioProbeGrid m_grid; // 0x0020
	SteamAudioReverbSettings_t m_reverbSettings; // 0x0078
	SteamAudioReverbClusteringSettings_t m_reverbClusteringSettings; // 0x008C
	SteamAudioReverbCompressionSettings_t m_reverbCompressionSettings; // 0x0098
	CSteamAudioProbeData m_clusteredProbes; // 0x00A0
	CUtlVector< int16 > m_vecClusterForProbe; // 0x00A8
	CSteamAudioCompressedReverb m_compressedData; // 0x00C0
	CSteamAudioCompressedReverb m_compressedClusteredData; // 0x0120
	CSteamAudioMovableBakedData< CSteamAudioBakedReverbData > m_movables; // 0x0180
};
class BlendItem_t // animgraphlib
{
	CUtlVector< TagSpan_t > m_tags; // 0x0000
	CAnimUpdateNodeRef m_pChild; // 0x0018
	HSequence m_hSequence; // 0x0028
	Vector2D m_vPos; // 0x002C
	float32 m_flDuration; // 0x0034
	bool m_bUseCustomDuration; // 0x0038
};
class CNmBoneWeightList // animlib
{
	CResourceName m_skeletonName; // 0x0000
	CUtlVector< CGlobalSymbol > m_boneIDs; // 0x00E0
	CUtlVector< float32 > m_weights; // 0x00F8
};
class CPulseGraphExecutionHistory // pulse_runtime_lib
{
	PulseGraphInstanceID_t m_nInstanceID; // 0x0000
	CUtlString m_strFileName; // 0x0008
	CUtlVector< PulseGraphExecutionHistoryEntry_t* > m_vecHistory; // 0x0010
	CUtlOrderedMap< PulseDocNodeID_t, PulseGraphExecutionHistoryNodeDesc_t* > m_mapCellDesc; // 0x0028
	CUtlOrderedMap< PulseCursorID_t, PulseGraphExecutionHistoryCursorDesc_t* > m_mapCursorDesc; // 0x0050
};
class C_OP_AttractToControlPoint : public CParticleFunctionForce // particles
{
	Vector m_vecComponentScale; // 0x01E8
	CPerParticleFloatInput m_fForceAmount; // 0x01F8
	CPerParticleFloatInput m_fMinimumDistance; // 0x0368
	float32 m_fFalloffPower; // 0x04D8
	CParticleTransformInput m_TransformInput; // 0x04E0
	CPerParticleFloatInput m_fForceAmountMin; // 0x0548
	bool m_bApplyMinForce; // 0x06B8
};
class VMixSubgraphSwitchDesc_t // soundsystem_lowlevel
{
	CUtlString m_name; // 0x0000
	CUtlString m_effectName; // 0x0008
	CUtlVector< CUtlString > m_subgraphs; // 0x0010
	VMixSubgraphSwitchInterpolationType_t m_interpolationMode; // 0x0028
	bool m_bOnlyTailsOnFadeOut; // 0x002C
	float32 m_flInterpolationTime; // 0x0030
};
class SelectedEditItemInfo_t // soundsystem
{
	CUtlVector< SosEditItemInfo_t > m_EditItems; // 0x0000
};
class CVMixDelayProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixDelayDesc_t m_desc; // 0x0020
};
class CNmIDEventConditionNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	int16 m_nSourceStateNodeIdx; // 0x0010
	CNmBitFlags m_eventConditionRules; // 0x0014
	CUtlVectorFixedGrowable< CGlobalSymbol, 5 > m_eventIDs; // 0x0018
};
class CAttachment // modellib
{
	CUtlString m_name; // 0x0000
	CUtlString[3] m_influenceNames; // 0x0008
	Quaternion[3] m_vInfluenceRotations; // 0x0020
	Vector[3] m_vInfluenceOffsets; // 0x0050
	float32[3] m_influenceWeights; // 0x0074
	bool[3] m_bInfluenceRootTransform; // 0x0080
	uint8 m_nInfluences; // 0x0083
	bool m_bIgnoreRotation; // 0x0084
};
class CNmStateMachineNode::TransitionDefinition_t // animlib
{
	int16 m_nTargetStateIdx; // 0x0000
	int16 m_nConditionNodeIdx; // 0x0002
	int16 m_nTransitionNodeIdx; // 0x0004
	bool m_bCanBeForced; // 0x0006
};
class EventServerPostSimulate_t : public EventSimulate_t // engine2
{
	bool m_bLastTickBeforeClientUpdate; // 0x0030
};
class VsInputSignatureElement_t // rendersystemdx11
{
	char[64] m_pName; // 0x0000
	char[64] m_pSemantic; // 0x0040
	char[64] m_pD3DSemanticName; // 0x0080
	int32 m_nD3DSemanticIndex; // 0x00C0
};
class C_OP_ConstrainDistance : public CParticleFunctionConstraint // particles
{
	CParticleCollectionFloatInput m_fMinDistance; // 0x01D8
	CParticleCollectionFloatInput m_fMaxDistance; // 0x0348
	int32 m_nControlPointNumber; // 0x04B8
	Vector m_CenterOffset; // 0x04BC
	bool m_bGlobalCenter; // 0x04C8
};
class C_OP_InstantaneousEmitter : public CParticleFunctionEmitter // particles
{
	CParticleCollectionFloatInput m_nParticlesToEmit; // 0x01E0
	CParticleCollectionFloatInput m_flStartTime; // 0x0350
	float32 m_flInitFromKilledParentParticles; // 0x04C0
	EventTypeSelection_t m_nEventType; // 0x04C4
	CParticleCollectionFloatInput m_flParentParticleScale; // 0x04C8
	int32 m_nMaxEmittedPerFrame; // 0x0638
	int32 m_nSnapshotControlPoint; // 0x063C
	CUtlString m_strSnapshotSubset; // 0x0640
};
class C_OP_RemapNamedModelBodyPartOnceTimed : public C_OP_RemapNamedModelElementOnceTimed // particles
{
};
class CAudioEmphasisSample // soundsystem_voicecontainers
{
	float32 m_flTime; // 0x0000
	float32 m_flValue; // 0x0004
};
class CNmVirtualParameterBoneMaskNode::CDefinition : public CNmBoneMaskValueNode::CDefinition // animlib
{
	int16 m_nChildNodeIdx; // 0x0010
};
class CDistanceRemainingMetricEvaluator : public CMotionMetricEvaluator // animgraphlib
{
	float32 m_flMaxDistance; // 0x0050
	float32 m_flMinDistance; // 0x0054
	float32 m_flStartGoalFilterDistance; // 0x0058
	float32 m_flMaxGoalOvershootScale; // 0x005C
	bool m_bFilterFixedMinDistance; // 0x0060
	bool m_bFilterGoalDistance; // 0x0061
	bool m_bFilterGoalOvershoot; // 0x0062
};
class CNmLayerBlendNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
	int16 m_nBaseNodeIdx; // 0x0010
	bool m_bOnlySampleBaseRootMotion; // 0x0012
	CUtlLeanVectorFixedGrowable< CNmLayerBlendNode::LayerDefinition_t, 3 > m_layerDefinition; // 0x0018
};
class C_OP_DecayOffscreen : public CParticleFunctionOperator // particles
{
	CParticleCollectionFloatInput m_flOffscreenTime; // 0x01D8
};
class C_OP_RenderGpuImplicit : public CParticleFunctionRenderer // particles
{
	bool m_bUsePerParticleRadius; // 0x0228
	uint32 m_nVertexCountKb; // 0x022C
	uint32 m_nIndexCountKb; // 0x0230
	CParticleCollectionRendererFloatInput m_fGridSize; // 0x0238
	CParticleCollectionRendererFloatInput m_fRadiusScale; // 0x03A8
	CParticleCollectionRendererFloatInput m_fIsosurfaceThreshold; // 0x0518
	int32 m_nScaleCP; // 0x0688
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hMaterial; // 0x0690
};
class C_OP_ForceBasedOnDistanceToPlane : public CParticleFunctionForce // particles
{
	float32 m_flMinDist; // 0x01E8
	Vector m_vecForceAtMinDist; // 0x01EC
	float32 m_flMaxDist; // 0x01F8
	Vector m_vecForceAtMaxDist; // 0x01FC
	Vector m_vecPlaneNormal; // 0x0208
	int32 m_nControlPointNumber; // 0x0214
	float32 m_flExponent; // 0x0218
};
class FeEffectDesc_t // physicslib
{
	CUtlString sName; // 0x0000
	uint32 nNameHash; // 0x0008
	int32 nType; // 0x000C
	KeyValues3 m_Params; // 0x0010
};
class FeSphereRigid_t // physicslib
{
	fltx4 vSphere; // 0x0000
	uint16 nNode; // 0x0010
	uint16 nCollisionMask; // 0x0012
	uint16 nVertexMapIndex; // 0x0014
	uint16 nFlags; // 0x0016
};
class CNmVirtualParameterTargetNode::CDefinition : public CNmTargetValueNode::CDefinition // animlib
{
	int16 m_nChildNodeIdx; // 0x0010
};
class CNavAttribute : public CNavFlags // navlib
{
};
class CPlayerPawnComponent // server
{
	CNetworkVarChainer __m_pChainEntity; // 0x0008
	CAnimGraphControllerPtr m_pComponentGraphController; // 0x0030
};
class CIronSightController // server
{
	bool m_bIronSightAvailable; // 0x0008
	float32 m_flIronSightAmount; // 0x000C
	float32 m_flIronSightAmountGained; // 0x0010
	float32 m_flIronSightAmountBiased; // 0x0014
};
class C_INIT_PositionOffsetToCP : public CParticleFunctionInitializer // particles
{
	int32 m_nControlPointNumberStart; // 0x01E0
	int32 m_nControlPointNumberEnd; // 0x01E4
	bool m_bLocalCoords; // 0x01E8
};
class C_OP_SetCPOrientationToGroundNormal : public CParticleFunctionOperator // particles
{
	float32 m_flInterpRate; // 0x01D8
	float32 m_flMaxTraceLength; // 0x01DC
	float32 m_flTolerance; // 0x01E0
	float32 m_flTraceOffset; // 0x01E4
	char[128] m_CollisionGroupName; // 0x01E8
	ParticleTraceSet_t m_nTraceSet; // 0x0268
	int32 m_nInputCP; // 0x026C
	int32 m_nOutputCP; // 0x0270
	bool m_bIncludeWater; // 0x0280
};
class CVMixNameInputMeter : public CVMixInputBase // soundsystem_lowlevel
{
	int32 m_nValueIndex; // 0x0010
};
class C_INIT_ScreenSpacePositionOfTarget : public CParticleFunctionInitializer // particles
{
	CPerParticleVecInput m_vecTargetPosition; // 0x01E0
	bool m_bOututBehindness; // 0x0898
	ParticleAttributeIndex_t m_nBehindFieldOutput; // 0x089C
	CParticleRemapFloatInput m_flBehindOutputRemap; // 0x08A0
};
class C_INIT_RemapParticleCountToScalar : public CParticleFunctionInitializer // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E0
	int32 m_nInputMin; // 0x01E4
	int32 m_nInputMax; // 0x01E8
	int32 m_nScaleControlPoint; // 0x01EC
	int32 m_nScaleControlPointField; // 0x01F0
	float32 m_flOutputMin; // 0x01F4
	float32 m_flOutputMax; // 0x01F8
	ParticleSetMethod_t m_nSetMethod; // 0x01FC
	bool m_bActiveRange; // 0x0200
	bool m_bInvert; // 0x0201
	bool m_bWrap; // 0x0202
	float32 m_flRemapBias; // 0x0204
};
class CVectorAnimParameter : public CConcreteAnimParameter // animgraphlib
{
	Vector m_defaultValue; // 0x0080
	bool m_bInterpolate; // 0x008C
	AnimParamVectorType_t m_vectorType; // 0x0090
};
class CNmParameterizedSelectorNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
	CUtlLeanVectorFixedGrowable< int16, 8 > m_optionNodeIndices; // 0x0010
	CUtlLeanVectorFixedGrowable< uint8, 8 > m_optionWeights; // 0x0028
	int16 m_parameterNodeIdx; // 0x0038
	bool m_bIgnoreInvalidOptions; // 0x003A
	bool m_bHasWeightsSet; // 0x003B
};
class CAnimUpdateNodeRef // animgraphlib
{
	int32 m_nodeIndex; // 0x0008
};
class CAnimBone // animationsystem
{
	CBufferString m_name; // 0x0000
	int32 m_parent; // 0x0010
	Vector m_pos; // 0x0014
	QuaternionStorage m_quat; // 0x0020
	float32 m_scale; // 0x0030
	QuaternionStorage m_qAlignment; // 0x0034
	int32 m_flags; // 0x0044
};
class RenderHairStrandInfo_t // modellib
{
	uint32[2] m_nGuideHairIndices_nSurfaceTriIndex; // 0x0000
	uint16[4] m_vGuideBary_vBaseBary; // 0x0008
	uint16[4] m_vRootOffset_flLengthScale; // 0x0010
	uint16[2] m_nPackedBaseUv; // 0x0018
	uint32 m_nPackedSurfaceNormalOs; // 0x001C
	uint32 m_nPackedSurfaceTangentOs; // 0x0020
	uint32 m_nDataOffset_Segments; // 0x0024
};
class ResponseFollowup // server
{
	char* followup_concept; // 0x0000
	char* followup_contexts; // 0x0008
	float32 followup_delay; // 0x0010
	char* followup_target; // 0x0014
	char* followup_entityiotarget; // 0x001C
	char* followup_entityioinput; // 0x0024
	float32 followup_entityiodelay; // 0x002C
	bool bFired; // 0x0030
};
class C_OP_SetSimulationRate : public CParticleFunctionPreEmission // particles
{
	CParticleCollectionFloatInput m_flSimulationScale; // 0x01E0
};
class CNmStateNode::TimedEvent_t // animlib
{
	CGlobalSymbol m_ID; // 0x0000
	float32 m_flTimeValueSeconds; // 0x0008
	CNmStateNode::TimedEvent_t::Comparison_t m_comparisionOperator; // 0x000C
};
class CAnimationGraphVisualizerText : public CAnimationGraphVisualizerPrimitiveBase // animgraphlib
{
	VectorAligned m_vWsPosition; // 0x0040
	Color m_Color; // 0x0050
	CUtlString m_Text; // 0x0058
};
class InfoForResourceTypeCVDataItemDefs // resourcesystem
{
};
class CTakeDamageSummaryScopeGuard // server
{
	CUtlVector< SummaryTakeDamageInfo_t* > m_vecSummaries; // 0x0008
};
class CVMixVocoderProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixVocoderDesc_t m_desc; // 0x0020
};
class FeCtrlOsOffset_t // physicslib
{
	uint16 nCtrlParent; // 0x0000
	uint16 nCtrlChild; // 0x0002
};
class CMotionGraphUpdateNode : public CLeafUpdateNode // animgraphlib
{
	CSmartPtr< CMotionGraph > m_pMotionGraph; // 0x0058
};
class CMotionMetricEvaluator // animgraphlib
{
	CUtlVector< float32 > m_means; // 0x0018
	CUtlVector< float32 > m_standardDeviations; // 0x0030
	float32 m_flWeight; // 0x0048
	int32 m_nDimensionStartIndex; // 0x004C
};
class GameTime_t // entity2
{
	float32 m_Value; // 0x0000
};
class EntInput_t // entity2
{
};
class C_OP_RemapNamedModelMeshGroupEndCap : public C_OP_RemapNamedModelElementEndCap // particles
{
};
class C_OP_MaintainEmitter : public CParticleFunctionEmitter // particles
{
	CParticleCollectionFloatInput m_nParticlesToMaintain; // 0x01E0
	float32 m_flStartTime; // 0x0350
	CParticleCollectionFloatInput m_flEmissionDuration; // 0x0358
	float32 m_flEmissionRate; // 0x04C8
	int32 m_nSnapshotControlPoint; // 0x04CC
	CUtlString m_strSnapshotSubset; // 0x04D0
	bool m_bEmitInstantaneously; // 0x04D8
	bool m_bFinalEmitOnStop; // 0x04D9
	CParticleCollectionFloatInput m_flScale; // 0x04E0
};
class CFeMorphLayer // physicslib
{
	CUtlString m_Name; // 0x0000
	uint32 m_nNameHash; // 0x0008
	CUtlVector< uint16 > m_Nodes; // 0x0010
	CUtlVector< Vector > m_InitPos; // 0x0028
	CUtlVector< float32 > m_Gravity; // 0x0040
	CUtlVector< float32 > m_GoalStrength; // 0x0058
	CUtlVector< float32 > m_GoalDamping; // 0x0070
};
class CMorphRectData // modellib
{
	int16 m_nXLeftDst; // 0x0000
	int16 m_nYTopDst; // 0x0002
	float32 m_flUWidthSrc; // 0x0004
	float32 m_flVHeightSrc; // 0x0008
	CUtlVector< CMorphBundleData > m_bundleDatas; // 0x0010
};
class CNetworkedCycle // animgraphlib
{
	float32 m_flCycleUnclamped; // 0x0000
	float32 m_flPrevCycleUnclamped; // 0x0004
	CAnimNetVar< float32 > m_flCyclesPerSecond; // 0x0010
	CAnimNetVar< float32 > m_flCycleZeroTime; // 0x001C
	CAnimNetVar< uint8 > m_resetCount; // 0x0028
};
class CEditableMotionGraph : public CMotionGraph // animgraphlib
{
};
class InfoForResourceTypeCPanoramaStyle // resourcesystem
{
};
class CSceneEventInfo // server
{
	int32 m_iLayer; // 0x0000
	int32 m_iPriority; // 0x0004
	HSequence m_hSequence; // 0x0008
	float32 m_flWeight; // 0x000C
	float32 m_flLastAccumulatedTime; // 0x0010
	float32 m_flLastJumpFromTime; // 0x0014
	float32 m_flLastJumpToTime; // 0x0018
	float32 m_flLastCycle; // 0x001C
	CStrongHandle< InfoForResourceTypeCNmClip > m_hAnimClip; // 0x0020
	CGlobalSymbol m_sAnimClipSlot; // 0x0028
	CGlobalSymbol m_sAnimClipSlotWeight; // 0x0030
	bool m_bHasArrived; // 0x0038
	int32 m_nType; // 0x003C
	GameTime_t m_flNext; // 0x0040
	bool m_bIsGesture; // 0x0044
	bool m_bShouldRemove; // 0x0045
	CHandle< CBaseEntity > m_hTarget; // 0x006C
	SceneEventId_t m_nSceneEventId; // 0x0070
	bool m_bClientSide; // 0x0074
	bool m_bStarted; // 0x0075
};
class C_OP_MovementRotateParticleAroundAxis : public CParticleFunctionOperator // particles
{
	CParticleCollectionVecInput m_vecRotAxis; // 0x01D8
	CParticleCollectionFloatInput m_flRotRate; // 0x0890
	CParticleTransformInput m_TransformInput; // 0x0A00
	bool m_bLocalSpace; // 0x0A68
};
class C_INIT_RadiusFromCPObject : public CParticleFunctionInitializer // particles
{
	int32 m_nControlPoint; // 0x01E0
};
class CReplicationParameters // particles
{
	ParticleReplicationMode_t m_nReplicationMode; // 0x0000
	bool m_bScaleChildParticleRadii; // 0x0004
	CParticleCollectionFloatInput m_flMinRandomRadiusScale; // 0x0008
	CParticleCollectionFloatInput m_flMaxRandomRadiusScale; // 0x0178
	CParticleCollectionVecInput m_vMinRandomDisplacement; // 0x02E8
	CParticleCollectionVecInput m_vMaxRandomDisplacement; // 0x09A0
	CParticleCollectionFloatInput m_flModellingScale; // 0x1058
};
class C_INIT_QuantizeFloat : public CParticleFunctionInitializer // particles
{
	CPerParticleFloatInput m_InputValue; // 0x01E0
	ParticleAttributeIndex_t m_nOutputField; // 0x0350
};
class CVMixDiffusorProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixDiffusorDesc_t m_desc; // 0x0020
};
class SosEditItemInfo_t // soundsystem
{
	SosEditItemType_t itemType; // 0x0000
	CUtlString itemName; // 0x0008
	CUtlString itemTypeName; // 0x0010
	CUtlString itemKVString; // 0x0020
	Vector2D itemPos; // 0x0028
};
class CDirectPlaybackInstanceData // animgraphlib
{
	Vector m_vTargetPosition; // 0x0000
	float32 m_flTargetFacing; // 0x000C
	float32 m_flInterpEndTime; // 0x0010
	float32[4] m_weights; // 0x0014
	SequenceData[4] m_sequences; // 0x0024
	uint32 m_currentSequenceIndex; // 0x0104
	CAnimNetVar< uint64 > m_currentSequenceData; // 0x0108
	float32 m_flFadeInTime; // 0x0118
	float32 m_flFadeOutTime; // 0x011C
	CAnimNetVar< float32 > m_flForcedCycle; // 0x0120
	bool m_bResetPending; // 0x0130
	CAnimNetVar< float32 > m_SequenceCycleZeroTime; // 0x0138
};
class SequenceData // animgraphlib
{
	HSequence m_hSequence; // 0x0000
	CNetworkedCycle m_cycle; // 0x0004
};
class CAnimationGraphVisualizerPie : public CAnimationGraphVisualizerPrimitiveBase // animgraphlib
{
	VectorAligned m_vWsCenter; // 0x0040
	VectorAligned m_vWsStart; // 0x0050
	VectorAligned m_vWsEnd; // 0x0060
	Color m_Color; // 0x0070
};
class CPulse_InstructionDebug // pulse_runtime_lib
{
	PulseDocNodeID_t m_nFlowNodeID; // 0x0000
	PulseDocNodeID_t m_nValueNodeID; // 0x0004
	PulseSymbol_t m_SequencePointName; // 0x0008
};
class HullFlags_t // server
{
	bool m_bHull_Human; // 0x0000
	bool m_bHull_SmallCentered; // 0x0001
	bool m_bHull_WideHuman; // 0x0002
	bool m_bHull_Tiny; // 0x0003
	bool m_bHull_Medium; // 0x0004
	bool m_bHull_TinyCentered; // 0x0005
	bool m_bHull_Large; // 0x0006
	bool m_bHull_LargeCentered; // 0x0007
	bool m_bHull_MediumTall; // 0x0008
	bool m_bHull_Small; // 0x0009
};
class C_OP_RemapExternalWindToCP : public CParticleFunctionPreEmission // particles
{
	int32 m_nCP; // 0x01E0
	int32 m_nCPOutput; // 0x01E4
	CParticleCollectionVecInput m_vecScale; // 0x01E8
	bool m_bSetMagnitude; // 0x08A0
	int32 m_nOutVectorField; // 0x08A4
};
class CTurnHelperInstanceData // animgraphlib
{
	float32 m_turnAmount; // 0x0000
	float32 m_turnStartTime; // 0x0004
	float32 m_duration; // 0x0008
};
class CMoverUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	CAnimInputDamping m_damping; // 0x0078
	AnimValueSource m_facingTarget; // 0x0090
	CAnimParamHandle m_hMoveVecParam; // 0x0094
	CAnimParamHandle m_hMoveHeadingParam; // 0x0096
	CAnimParamHandle m_hTurnToFaceParam; // 0x0098
	float32 m_flTurnToFaceOffset; // 0x009C
	float32 m_flTurnToFaceLimit; // 0x00A0
	bool m_bAdditive; // 0x00A4
	bool m_bApplyMovement; // 0x00A5
	bool m_bOrientMovement; // 0x00A6
	bool m_bApplyRotation; // 0x00A7
	bool m_bLimitOnly; // 0x00A8
};
class FuncRotatorRotationSummary_t // server
{
	GameTick_t nTick; // 0x0000
	FuncRotatorRotationSummaryFlags_t nFlags; // 0x0004
};
class entitytable_t // server
{
	int32 id; // 0x0000
	CEntityIndex edictindex; // 0x0004
	CEntityIndex saveentityindex; // 0x0008
	bool bWasSaved; // 0x0014
	SaveRestoreTableFlags_t flags; // 0x0018
	CUtlSymbolLarge classname; // 0x0020
	CUtlSymbolLarge globalname; // 0x0028
	CUtlSymbolLarge entityname; // 0x0030
	Vector landmarkModelSpace; // 0x0038
	CEntityKeyValues* m_pPrecacheEntityKeys; // 0x0048
};
class CPAssignment_t // particles
{
	int32 m_nCPNumber; // 0x0000
	CPerParticleVecInput m_Pos; // 0x0008
	ParticleOrientationSetMode_t m_nOrientationMode; // 0x06C0
};
class C_INIT_RemapParticleCountToNamedModelMeshGroupScalar : public C_INIT_RemapParticleCountToNamedModelElementScalar // particles
{
};
class CVoiceContainerBase // soundsystem_voicecontainers
{
	CVSound m_vSound; // 0x0028
	CVoiceContainerAnalysisBase* m_pEnvelopeAnalyzer; // 0x0068
};
class CNmVectorValueNode::CDefinition : public CNmValueNode::CDefinition // animlib
{
};
class PGDInstruction_t // pulse_runtime_lib
{
	PulseInstructionCode_t m_nCode; // 0x0000
	PulseRuntimeVarIndex_t m_nVar; // 0x0004
	PulseRuntimeRegisterIndex_t m_nReg0; // 0x0008
	PulseRuntimeRegisterIndex_t m_nReg1; // 0x000A
	PulseRuntimeRegisterIndex_t m_nReg2; // 0x000C
	PulseRuntimeInvokeIndex_t m_nInvokeBindingIndex; // 0x0010
	PulseRuntimeChunkIndex_t m_nChunk; // 0x0014
	int32 m_nDestInstruction; // 0x0018
	PulseRuntimeCallInfoIndex_t m_nCallInfoIndex; // 0x001C
	PulseRuntimeConstantIndex_t m_nConstIdx; // 0x0020
	PulseRuntimeDomainValueIndex_t m_nDomainValueIdx; // 0x0022
	PulseRuntimeBlackboardReferenceIndex_t m_nBlackboardReferenceIdx; // 0x0024
};
class InfoForResourceTypeCDOTAPatchNotesList // resourcesystem
{
};
class C_INIT_RandomModelSequence : public CParticleFunctionInitializer // particles
{
	char[256] m_ActivityName; // 0x01E0
	char[256] m_SequenceName; // 0x02E0
	CStrongHandle< InfoForResourceTypeCModel > m_hModel; // 0x03E0
};
class CGeneralRandomRotation : public CParticleFunctionInitializer // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E0
	float32 m_flDegrees; // 0x01E4
	float32 m_flDegreesMin; // 0x01E8
	float32 m_flDegreesMax; // 0x01EC
	float32 m_flRotationRandExponent; // 0x01F0
	bool m_bRandomlyFlipDirection; // 0x01F4
};
class C_INIT_CreateWithinCapsuleTransform : public CParticleFunctionInitializer // particles
{
	CPerParticleFloatInput m_fRadiusMin; // 0x01E0
	CPerParticleFloatInput m_fRadiusMax; // 0x0350
	CPerParticleFloatInput m_fHeight; // 0x04C0
	CParticleTransformInput m_TransformInput; // 0x0630
	CPerParticleFloatInput m_fSpeedMin; // 0x0698
	CPerParticleFloatInput m_fSpeedMax; // 0x0808
	float32 m_fSpeedRandExp; // 0x0978
	CPerParticleVecInput m_LocalCoordinateSystemSpeedMin; // 0x0980
	CPerParticleVecInput m_LocalCoordinateSystemSpeedMax; // 0x1038
	ParticleAttributeIndex_t m_nFieldOutput; // 0x16F0
	ParticleAttributeIndex_t m_nFieldVelocity; // 0x16F4
};
class C_OP_RemapNamedModelSequenceEndCap : public C_OP_RemapNamedModelElementEndCap // particles
{
};
class CClothSettingsAnimTag : public CAnimTagBase // animgraphlib
{
	float32 m_flStiffness; // 0x0058
	float32 m_flEaseIn; // 0x005C
	float32 m_flEaseOut; // 0x0060
	CUtlString m_nVertexSet; // 0x0068
};
class EventBugBugComplete_t // engine2
{
	EventBugBug_t* m_pPayload; // 0x0000
};
class INavPathCostAreaFilter // server
{
};
class CVoiceContainerVMixSnd : public CVoiceContainerBase // soundsystem
{
};
class VPhysXCollisionAttributes_t // modellib
{
	int32 m_nIncludeDetailLayerCount; // 0x0000
	uint32 m_CollisionGroup; // 0x0004
	CUtlVector< uint32 > m_InteractAs; // 0x0008
	CUtlVector< uint32 > m_InteractWith; // 0x0020
	CUtlVector< uint32 > m_InteractExclude; // 0x0038
	CUtlVector< uint32 > m_DetailLayers; // 0x0050
	CUtlString m_CollisionGroupString; // 0x0068
	CUtlVector< CUtlString > m_InteractAsStrings; // 0x0070
	CUtlVector< CUtlString > m_InteractWithStrings; // 0x0088
	CUtlVector< CUtlString > m_InteractExcludeStrings; // 0x00A0
	CUtlVector< CUtlString > m_DetailLayerStrings; // 0x00B8
};
class CSeqAutoLayerFlag // animationsystem
{
	bool m_bPost; // 0x0000
	bool m_bSpline; // 0x0001
	bool m_bXFade; // 0x0002
	bool m_bNoBlend; // 0x0003
	bool m_bLocal; // 0x0004
	bool m_bPose; // 0x0005
	bool m_bFetchFrame; // 0x0006
	bool m_bSubtract; // 0x0007
};
class CNmCachedIDNode::CDefinition : public CNmIDValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	NmCachedValueMode_t m_mode; // 0x0014
};
class EventSetTime_t // engine2
{
	EngineLoopState_t m_LoopState; // 0x0000
	int32 m_nClientOutputFrames; // 0x0028
	float64 m_flRealTime; // 0x0030
	float64 m_flRenderTime; // 0x0038
	float64 m_flRenderFrameTime; // 0x0040
	float64 m_flRenderFrameTimeUnbounded; // 0x0048
	float64 m_flRenderFrameTimeUnscaled; // 0x0050
	float64 m_flTickRemainder; // 0x0058
};
class CExampleSchemaVData_PolymorphicDerivedB : public CExampleSchemaVData_PolymorphicBase // resourcefile
{
	int32 m_nDerivedB; // 0x0010
};
class CTestPulseIOComponent_Derived : public CTestPulseIOComponent // server
{
};
class CSkeletonAnimationController : public ISkeletonAnimationController // server
{
	CSkeletonInstance* m_pSkeletonInstance; // 0x0008
};
class CMotionSearchNode // animgraphlib
{
	CUtlVector< CMotionSearchNode* > m_children; // 0x0000
	CVectorQuantizer m_quantizer; // 0x0018
	CUtlVector< CUtlVector< SampleCode > > m_sampleCodes; // 0x0038
	CUtlVector< CUtlVector< int32 > > m_sampleIndices; // 0x0050
	CUtlVector< int32 > m_selectableSamples; // 0x0068
};
class CNmVectorCreateNode::CDefinition : public CNmVectorValueNode::CDefinition // animlib
{
	int16 m_inputVectorValueNodeIdx; // 0x0010
	int16 m_inputValueXNodeIdx; // 0x0012
	int16 m_inputValueYNodeIdx; // 0x0014
	int16 m_inputValueZNodeIdx; // 0x0016
};
class CConstraintSlave // modellib
{
	Quaternion m_qBaseOrientation; // 0x0000
	Vector m_vBasePosition; // 0x0010
	uint32 m_nBoneHash; // 0x001C
	float32 m_flWeight; // 0x0020
	CUtlString m_sName; // 0x0028
};
class CSeqMultiFetch // animationsystem
{
	CSeqMultiFetchFlag m_flags; // 0x0000
	CUtlVector< int16 > m_localReferenceArray; // 0x0008
	int32[2] m_nGroupSize; // 0x0020
	int32[2] m_nLocalPose; // 0x0028
	CUtlVector< float32 > m_poseKeyArray0; // 0x0030
	CUtlVector< float32 > m_poseKeyArray1; // 0x0048
	int32 m_nLocalCyclePoseParameter; // 0x0060
	bool m_bCalculatePoseParameters; // 0x0064
	bool m_bFixedBlendWeight; // 0x0065
	float32[2] m_flFixedBlendWeightVals; // 0x0068
};
class EventSimulate_t // engine2
{
	EngineLoopState_t m_LoopState; // 0x0000
	bool m_bFirstTick; // 0x0028
	bool m_bLastTick; // 0x0029
};
class InfoForResourceTypeCNmClip // resourcesystem
{
};
class C_IronSightController // client
{
	bool m_bIronSightAvailable; // 0x0010
	float32 m_flIronSightAmount; // 0x0014
	float32 m_flIronSightAmountGained; // 0x0018
	float32 m_flIronSightAmountBiased; // 0x001C
	float32 m_flIronSightAmount_Interpolated; // 0x0020
	float32 m_flIronSightAmountGained_Interpolated; // 0x0024
	float32 m_flIronSightAmountBiased_Interpolated; // 0x0028
	float32 m_flInterpolationLastUpdated; // 0x002C
	QAngle[8] m_angDeltaAverage; // 0x0030
	QAngle m_angViewLast; // 0x0090
	Vector2D m_vecDotCoords; // 0x009C
	float32 m_flFiringInaccuracyExtraWidthMultiplier; // 0x00A4
	float32 m_flSpeedRatio; // 0x00A8
};
class CNetworkViewOffsetVector // server
{
	CNetworkedQuantizedFloat m_vecX; // 0x0010
	CNetworkedQuantizedFloat m_vecY; // 0x0018
	CNetworkedQuantizedFloat m_vecZ; // 0x0020
};
class CMotorController // server
{
	float32 m_speed; // 0x0008
	float32 m_maxTorque; // 0x000C
	Vector m_axis; // 0x0010
	float32 m_inertiaFactor; // 0x001C
};
class CNmFloatCurveEventNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	CGlobalSymbol m_eventID; // 0x0010
	int16 m_nDefaultNodeIdx; // 0x0018
	float32 m_flDefaultValue; // 0x001C
	CNmBitFlags m_eventConditionRules; // 0x0020
};
class CNmFloatValueNode::CDefinition : public CNmValueNode::CDefinition // animlib
{
};
class inv_image_data_t // client
{
	inv_image_map_t map; // 0x0000
	inv_image_item_t item; // 0x0010
	inv_image_camera_t camera; // 0x0030
	inv_image_light_sun_t lightsun; // 0x0064
	inv_image_light_fill_t lightfill; // 0x0080
	inv_image_light_barn_t light0; // 0x009C
	inv_image_light_barn_t light1; // 0x00BC
	inv_image_clearcolor_t clearcolor; // 0x00DC
};
class C_OP_ParentVortices : public CParticleFunctionForce // particles
{
	float32 m_flForceScale; // 0x01E8
	Vector m_vecTwistAxis; // 0x01EC
	bool m_bFlipBasedOnYaw; // 0x01F8
};
class CSosGroupActionSoundeventMinMaxValuesSchema : public CSosGroupActionSchema // soundsystem
{
	CUtlString m_strQueryPublicFieldName; // 0x0008
	CUtlString m_strDelayPublicFieldName; // 0x0010
	bool m_bExcludeStoppedSounds; // 0x0018
	bool m_bExcludeDelayedSounds; // 0x0019
	bool m_bExcludeSoundsBelowThreshold; // 0x001A
	float32 m_flExcludeSoundsMinThresholdValue; // 0x001C
	bool m_bExcludSoundsAboveThreshold; // 0x0020
	float32 m_flExcludeSoundsMaxThresholdValue; // 0x0024
	CUtlString m_strMinValueName; // 0x0028
	CUtlString m_strMaxValueName; // 0x0030
};
class ModelBoneFlexDriver_t // modellib
{
	CUtlString m_boneName; // 0x0000
	uint32 m_boneNameToken; // 0x0008
	CUtlVector< ModelBoneFlexDriverControl_t > m_controls; // 0x0010
};
class DampedPathMotorInstanceData_t // animgraphlib
{
	Vector m_vVelocity; // 0x0000
	Vector m_vAcceleration; // 0x000C
	bool m_bStopping; // 0x0024
};
class CMorphSetData // modellib
{
	int32 m_nWidth; // 0x0010
	int32 m_nHeight; // 0x0014
	CUtlVector< MorphBundleType_t > m_bundleTypes; // 0x0018
	CUtlVector< CMorphData > m_morphDatas; // 0x0030
	CStrongHandle< InfoForResourceTypeCTextureBase > m_pTextureAtlas; // 0x0048
	CUtlVector< CFlexDesc > m_FlexDesc; // 0x0050
	CUtlVector< CFlexController > m_FlexControllers; // 0x0068
	CUtlVector< CFlexRule > m_FlexRules; // 0x0080
};
class CMorphConstraint : public CBaseConstraint // modellib
{
	CUtlString m_sTargetMorph; // 0x0060
	int32 m_nSlaveChannel; // 0x0068
	float32 m_flMin; // 0x006C
	float32 m_flMax; // 0x0070
};
class CStateActionUpdater // animgraphlib
{
	CSmartPtr< CAnimActionUpdater > m_pAction; // 0x0000
	StateActionBehavior m_eBehavior; // 0x0008
};
class FootFixedData_t // animgraphlib
{
	VectorAligned m_vToeOffset; // 0x0000
	VectorAligned m_vHeelOffset; // 0x0010
	int32 m_nTargetBoneIndex; // 0x0020
	int32 m_nAnkleBoneIndex; // 0x0024
	int32 m_nIKAnchorBoneIndex; // 0x0028
	int32 m_ikChainIndex; // 0x002C
	float32 m_flMaxIKLength; // 0x0030
	int32 m_nFootIndex; // 0x0034
	int32 m_nTagIndex; // 0x0038
	float32 m_flMaxRotationLeft; // 0x003C
	float32 m_flMaxRotationRight; // 0x0040
};
class CMarkupSearch_PathCostAreaFilter : public INavPathCostAreaFilter // server
{
	CMarkupSearchHelper m_searchHelper; // 0x0008
};
class C_INIT_RemapInitialDirectionToTransformToVector : public CParticleFunctionInitializer // particles
{
	CParticleTransformInput m_TransformInput; // 0x01E0
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0248
	float32 m_flScale; // 0x024C
	float32 m_flOffsetRot; // 0x0250
	Vector m_vecOffsetAxis; // 0x0254
	bool m_bNormalize; // 0x0260
};
class VMixFreeverbDesc_t // soundsystem_lowlevel
{
	float32 m_flRoomSize; // 0x0000
	float32 m_flDamp; // 0x0004
	float32 m_flWidth; // 0x0008
	float32 m_flLateReflections; // 0x000C
};
class CVMixDynamicsProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixDynamicsDesc_t m_desc; // 0x0020
};
class CNmIsInactiveBranchConditionNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
};
class FollowTargetOpFixedSettings_t // animgraphlib
{
	int32 m_boneIndex; // 0x0000
	bool m_bBoneTarget; // 0x0004
	int32 m_boneTargetIndex; // 0x0008
	bool m_bWorldCoodinateTarget; // 0x000C
	bool m_bMatchTargetOrientation; // 0x000D
};
class CEmitTagActionUpdater : public CAnimActionUpdater // animgraphlib
{
	int32 m_nTagIndex; // 0x0018
	bool m_bIsZeroDuration; // 0x001C
};
class CNmGraphVariationUserData // animlib
{
};
class CNmTwoBoneIKTask : public CNmPoseTask // animlib
{
	int32 m_nEffectorBoneIdx; // 0x0070
	int32 m_nEffectorTargetBoneIdx; // 0x0074
	CTransform m_targetTransform; // 0x0080
	CNmTarget m_effectorTarget; // 0x00A0
	NmIKBlendMode_t m_blendMode; // 0x00D0
	float32 m_flBlendWeight; // 0x00D4
	bool m_bIsTargetInWorldSpace; // 0x00D8
	bool m_bIsRunningFromDeserializedData; // 0x00D9
	float32 m_flChainRotationWeight; // 0x00DC
	CGlobalSymbol m_debugEffectorBoneID; // 0x00E0
};
class CBoneConstraintPoseSpaceMorph : public CBoneConstraintBase // modellib
{
	CUtlString m_sBoneName; // 0x0020
	CUtlString m_sAttachmentName; // 0x0028
	CUtlVector< CUtlString > m_outputMorph; // 0x0030
	CUtlVector< CBoneConstraintPoseSpaceMorph::Input_t > m_inputList; // 0x0048
	bool m_bClamp; // 0x0060
};
class EventProfileStorageAvailable_t // engine2
{
	CSplitScreenSlot m_nSplitScreenSlot; // 0x0000
};
class InfoForResourceTypeCVSoundStackScriptList // resourcesystem
{
};
class C_OP_CollideWithSelf : public CParticleFunctionConstraint // particles
{
	CPerParticleFloatInput m_flRadiusScale; // 0x01D8
	CPerParticleFloatInput m_flMinimumSpeed; // 0x0348
};
class C_INIT_PlaneCull : public CParticleFunctionInitializer // particles
{
	int32 m_nControlPoint; // 0x01E0
	CParticleCollectionFloatInput m_flDistance; // 0x01E8
	bool m_bCullInside; // 0x0358
};
class C_OP_RemapDistanceToLineSegmentToVector : public C_OP_RemapDistanceToLineSegmentBase // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01F0
	Vector m_vMinOutputValue; // 0x01F4
	Vector m_vMaxOutputValue; // 0x0200
};
class C_OP_PercentageBetweenTransformLerpCPs : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	float32 m_flInputMin; // 0x01DC
	float32 m_flInputMax; // 0x01E0
	CParticleTransformInput m_TransformStart; // 0x01E8
	CParticleTransformInput m_TransformEnd; // 0x0250
	int32 m_nOutputStartCP; // 0x02B8
	int32 m_nOutputStartField; // 0x02BC
	int32 m_nOutputEndCP; // 0x02C0
	int32 m_nOutputEndField; // 0x02C4
	ParticleSetMethod_t m_nSetMethod; // 0x02C8
	bool m_bActiveRange; // 0x02CC
	bool m_bRadialCheck; // 0x02CD
};
class CVMixSteamAudioHRTFProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
};
class CVoiceContainerGranulator : public CVoiceContainerAsyncGenerator // soundsystem_voicecontainers
{
	float32 m_flGrainLength; // 0x0080
	float32 m_flGrainCrossfadeAmount; // 0x0084
	float32 m_flStartJitter; // 0x0088
	float32 m_flPlaybackJitter; // 0x008C
	bool m_bShouldWraparound; // 0x0090
	CStrongHandle< InfoForResourceTypeCVoiceContainerBase > m_sourceAudio; // 0x0098
};
class COrientationWarpUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	OrientationWarpMode_t m_eMode; // 0x0074
	CAnimParamHandle m_hTargetParam; // 0x0078
	CAnimParamHandle m_hTargetPositionParam; // 0x007A
	CAnimParamHandle m_hFallbackTargetPositionParam; // 0x007C
	OrientationWarpTargetOffsetMode_t m_eTargetOffsetMode; // 0x0080
	float32 m_flTargetOffset; // 0x0084
	CAnimParamHandle m_hTargetOffsetParam; // 0x0088
	CAnimInputDamping m_damping; // 0x0090
	OrientationWarpRootMotionSource_t m_eRootMotionSource; // 0x00A8
	float32 m_flMaxRootMotionScale; // 0x00AC
	bool m_bEnablePreferredRotationDirection; // 0x00B0
	AnimValueSource m_ePreferredRotationDirection; // 0x00B4
	float32 m_flPreferredRotationThreshold; // 0x00B8
};
class CAnimGraphDebugReplay // animgraphlib
{
	CUtlString m_animGraphFileName; // 0x0040
	CUtlVector< CSmartPtr< CAnimReplayFrame > > m_frameList; // 0x0048
	int32 m_startIndex; // 0x0060
	int32 m_writeIndex; // 0x0064
	int32 m_frameCount; // 0x0068
};
class MovementData // animgraphlib
{
	Vector m_goalWayPointPos; // 0x0000
	CAnimNetVar< Vector > m_vMoveDir; // 0x000C
	CAnimNetVar< Vector > m_vAcceleration; // 0x0020
	CAnimNetVar< float32 > m_flCurrentMoveSpeed; // 0x0034
	CAnimNetVar< float32 > m_flTargetMoveSpeed; // 0x0040
	CAnimNetVar< float32 > m_flGoalDistance; // 0x004C
	CAnimNetVar< float32 > m_flBoundaryRadius; // 0x0058
	bool m_bGoalChanged; // 0x0064
	CAnimNetVar< bool > m_bHasPath; // 0x0068
	CAnimNetVar< float32 > m_flFacingHeading; // 0x0074
	Vector m_vManualFacingDirection; // 0x0080
	VectorWS m_vManualFacingTarget; // 0x008C
	CAnimNetVar< uint8 > m_nFacingMode; // 0x0098
	CAnimNetVar< bool > m_bForceFacing; // 0x00A4
	CAnimNetVar< int32 > m_nActiveMotorIndex; // 0x00B0
	CAnimNetVar< bool > m_bOnGround; // 0x00BC
	CAnimNetVar< Vector > m_vFacingPosition; // 0x00C8
	Vector m_vPrevFacingPosition; // 0x00DC
};
class CAnimSkeleton // modellib
{
	CUtlVector< CTransform > m_localSpaceTransforms; // 0x0010
	CUtlVector< CTransform > m_modelSpaceTransforms; // 0x0028
	CUtlVector< CUtlString > m_boneNames; // 0x0040
	CUtlVector< CUtlVector< int32 > > m_children; // 0x0058
	CUtlVector< int32 > m_parents; // 0x0070
	CUtlVector< CAnimFoot > m_feet; // 0x0088
	CUtlVector< CUtlString > m_morphNames; // 0x00A0
	CUtlVector< int32 > m_lodBoneCounts; // 0x00B8
};
class CParticleCollectionFloatInput : public CParticleFloatInput // particleslib
{
};
class EventServerAdvanceTick_t : public EventAdvanceTick_t // engine2
{
};
class CGlobalLightBase // client
{
	bool m_bSpotLight; // 0x0010
	VectorWS m_SpotLightOrigin; // 0x0014
	QAngle m_SpotLightAngles; // 0x0020
	Vector m_ShadowDirection; // 0x002C
	Vector m_AmbientDirection; // 0x0038
	Vector m_SpecularDirection; // 0x0044
	Vector m_InspectorSpecularDirection; // 0x0050
	float32 m_flSpecularPower; // 0x005C
	float32 m_flSpecularIndependence; // 0x0060
	Color m_SpecularColor; // 0x0064
	bool m_bStartDisabled; // 0x0068
	bool m_bEnabled; // 0x0069
	Color m_LightColor; // 0x006A
	Color m_AmbientColor1; // 0x006E
	Color m_AmbientColor2; // 0x0072
	Color m_AmbientColor3; // 0x0076
	float32 m_flSunDistance; // 0x007C
	float32 m_flFOV; // 0x0080
	float32 m_flNearZ; // 0x0084
	float32 m_flFarZ; // 0x0088
	bool m_bEnableShadows; // 0x008C
	bool m_bOldEnableShadows; // 0x008D
	bool m_bBackgroundClearNotRequired; // 0x008E
	float32 m_flCloudScale; // 0x0090
	float32 m_flCloud1Speed; // 0x0094
	float32 m_flCloud1Direction; // 0x0098
	float32 m_flCloud2Speed; // 0x009C
	float32 m_flCloud2Direction; // 0x00A0
	float32 m_flAmbientScale1; // 0x00B0
	float32 m_flAmbientScale2; // 0x00B4
	float32 m_flGroundScale; // 0x00B8
	float32 m_flLightScale; // 0x00BC
	float32 m_flFoWDarkness; // 0x00C0
	bool m_bEnableSeparateSkyboxFog; // 0x00C4
	Vector m_vFowColor; // 0x00C8
	VectorWS m_ViewOrigin; // 0x00D4
	QAngle m_ViewAngles; // 0x00E0
	float32 m_flViewFoV; // 0x00EC
	VectorWS[8] m_WorldPoints; // 0x00F0
	Vector2D m_vFogOffsetLayer0; // 0x04A8
	Vector2D m_vFogOffsetLayer1; // 0x04B0
	CHandle< C_BaseEntity > m_hEnvWind; // 0x04B8
	CHandle< C_BaseEntity > m_hEnvSky; // 0x04BC
};
class globalentitydatabase_t // server
{
	CUtlVector< globalentity_t > m_list; // 0x0060
};
class CParticleFunctionConstraint : public CParticleFunction // particles
{
};
class CVMixDualCompressorProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixDualCompressorDesc_t m_desc; // 0x0020
};
class CAnimationGraphVisualizerAxis : public CAnimationGraphVisualizerPrimitiveBase // animgraphlib
{
	CTransform m_xWsTransform; // 0x0040
	float32 m_flAxisSize; // 0x0060
};
class INavObstacle // server
{
	uint64 m_nId; // 0x0008
};
class CJumpHelperUpdateNode : public CSequenceUpdateNode // animgraphlib
{
	CAnimParamHandle m_hTargetParam; // 0x00B0
	Vector m_flOriginalJumpMovement; // 0x00B4
	float32 m_flOriginalJumpDuration; // 0x00C0
	float32 m_flJumpStartCycle; // 0x00C4
	float32 m_flJumpEndCycle; // 0x00C8
	JumpCorrectionMethod m_eCorrectionMethod; // 0x00CC
	bool[3] m_bTranslationAxis; // 0x00D0
	bool m_bScaleSpeed; // 0x00D3
};
class CAnimDesc_Flag // animationsystem
{
	bool m_bLooping; // 0x0000
	bool m_bAllZeros; // 0x0001
	bool m_bHidden; // 0x0002
	bool m_bDelta; // 0x0003
	bool m_bLegacyWorldspace; // 0x0004
	bool m_bModelDoc; // 0x0005
	bool m_bImplicitSeqIgnoreDelta; // 0x0006
	bool m_bAnimGraphAdditive; // 0x0007
};
class CRegionSVM // physicslib
{
	CUtlVector< RnPlane_t > m_Planes; // 0x0000
	CUtlVector< uint32 > m_Nodes; // 0x0018
};
class CCycleControlUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	AnimValueSource m_valueSource; // 0x0070
	CAnimParamHandle m_paramIndex; // 0x0074
	bool m_bLockWhenWaning; // 0x0076
};
class PulseGraphExecutionHistoryEntry_t // pulse_runtime_lib
{
	PulseCursorID_t nCursorID; // 0x0000
	PulseDocNodeID_t nEditorID; // 0x0004
	float32 flExecTime; // 0x0008
	uint32 unFlags; // 0x000C
	PulseSymbol_t tagName; // 0x0010
};
class InfoForResourceTypeCCSGOEconItem // resourcesystem
{
};
class GeneratedTextureHandle_t // compositematerialslib
{
	CUtlString m_strBitmapName; // 0x0000
};
class C_OP_SetControlPointToImpactPoint : public CParticleFunctionPreEmission // particles
{
	int32 m_nCPOut; // 0x01E0
	int32 m_nCPIn; // 0x01E4
	float32 m_flUpdateRate; // 0x01E8
	CParticleCollectionFloatInput m_flTraceLength; // 0x01F0
	float32 m_flStartOffset; // 0x0360
	float32 m_flOffset; // 0x0364
	Vector m_vecTraceDir; // 0x0368
	char[128] m_CollisionGroupName; // 0x0374
	ParticleTraceSet_t m_nTraceSet; // 0x03F4
	bool m_bSetToEndpoint; // 0x03F8
	bool m_bTraceToClosestSurface; // 0x03F9
	bool m_bIncludeWater; // 0x03FA
};
class C_OP_RemapVisibilityScalar : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldInput; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
	float32 m_flInputMin; // 0x01E0
	float32 m_flInputMax; // 0x01E4
	float32 m_flOutputMin; // 0x01E8
	float32 m_flOutputMax; // 0x01EC
	float32 m_flRadiusScale; // 0x01F0
};
class C_OP_ScreenSpaceRotateTowardTarget : public CParticleFunctionOperator // particles
{
	CPerParticleVecInput m_vecTargetPosition; // 0x01D8
	CParticleRemapFloatInput m_flOutputRemap; // 0x0890
	ParticleSetMethod_t m_nSetMethod; // 0x0A00
	CPerParticleFloatInput m_flScreenEdgeAlignmentDistance; // 0x0A08
};
class C_INIT_CreateWithinSphereTransform : public CParticleFunctionInitializer // particles
{
	CPerParticleFloatInput m_fRadiusMin; // 0x01E0
	CPerParticleFloatInput m_fRadiusMax; // 0x0350
	CPerParticleVecInput m_vecDistanceBias; // 0x04C0
	Vector m_vecDistanceBiasAbs; // 0x0B78
	CParticleTransformInput m_TransformInput; // 0x0B88
	CPerParticleFloatInput m_fSpeedMin; // 0x0BF0
	CPerParticleFloatInput m_fSpeedMax; // 0x0D60
	float32 m_fSpeedRandExp; // 0x0ED0
	bool m_bLocalCoords; // 0x0ED4
	CPerParticleVecInput m_LocalCoordinateSystemSpeedMin; // 0x0ED8
	CPerParticleVecInput m_LocalCoordinateSystemSpeedMax; // 0x1590
	ParticleAttributeIndex_t m_nFieldOutput; // 0x1C48
	ParticleAttributeIndex_t m_nFieldVelocity; // 0x1C4C
};
class C_OP_SetGravityToCP : public CParticleFunctionPreEmission // particles
{
	int32 m_nCPInput; // 0x01E0
	int32 m_nCPOutput; // 0x01E4
	CParticleCollectionFloatInput m_flScale; // 0x01E8
	bool m_bSetPosition; // 0x0358
	bool m_bSetOrientation; // 0x0359
	bool m_bSetZDown; // 0x035A
};
class FeAnimStrayRadius_t // physicslib
{
	uint16[2] nNode; // 0x0000
	float32 flMaxDist; // 0x0004
	float32 flRelaxationFactor; // 0x0008
};
class FeAntiTunnelProbe_t // physicslib
{
	float32 flWeight; // 0x0000
	uint32 nFlags; // 0x0004
	uint16 nProbeNode; // 0x0008
	uint16 nCount; // 0x000A
	uint32 nBegin; // 0x000C
	float32 flActivationDistance; // 0x0010
	float32 flCurvatureRadius; // 0x0014
	float32 flBias; // 0x0018
};
class RnShapeDesc_t // physicslib
{
	uint32 m_nCollisionAttributeIndex; // 0x0000
	uint32 m_nSurfacePropertyIndex; // 0x0004
	CUtlString m_UserFriendlyName; // 0x0008
	bool m_bUserFriendlyNameSealed; // 0x0010
	bool m_bUserFriendlyNameLong; // 0x0011
	uint32 m_nToolMaterialHash; // 0x0014
};
class CNmFloatSelectorNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	CUtlLeanVectorFixedGrowable< int16, 5 > m_conditionNodeIndices; // 0x0010
	CUtlLeanVectorFixedGrowable< float32, 5 > m_values; // 0x0028
	float32 m_flDefaultValue; // 0x0048
	float32 m_flEaseTime; // 0x004C
	NmEasingOperation_t m_easingOp; // 0x0050
};
class CModelConfigElement_SetBodygroup : public CModelConfigElement // modellib
{
	CGlobalSymbol m_GroupName; // 0x0048
	int32 m_nChoice; // 0x0050
};
class CModelConfigElement_Command : public CModelConfigElement // modellib
{
	CUtlString m_Command; // 0x0048
	KeyValues3 m_Args; // 0x0050
};
class CRenderSkeleton // modellib
{
	CUtlVector< RenderSkeletonBone_t > m_bones; // 0x0000
	CUtlVector< int32 > m_boneParents; // 0x0030
	int32 m_nBoneWeightCount; // 0x0048
};
class InfoForResourceTypeCVPhysXSurfacePropertiesList // resourcesystem
{
};
class CChoreo_GraphController : public CAnimGraphControllerBase // server
{
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_eChoreoState; // 0x0088
	CAnimGraph2ParamOptionalRef< CTransform > m_tChoreoTargetWarp; // 0x00A0
	CAnimGraph2ParamOptionalRef< CTransform > m_tChoreoExitWarp; // 0x00B8
};
class WaterWheelFrictionScale_t // server
{
	float32 m_flFractionOfWheelSubmerged; // 0x0000
	float32 m_flFrictionScale; // 0x0004
};
class CSAdditionalMatchStats_t : public CSAdditionalPerRoundStats_t // server
{
	int32 m_numRoundsSurvivedStreak; // 0x00F8
	int32 m_maxNumRoundsSurvivedStreak; // 0x00FC
	int32 m_numRoundsSurvivedTotal; // 0x0100
	int32 m_iRoundsWonWithoutPurchase; // 0x0104
	int32 m_iRoundsWonWithoutPurchaseTotal; // 0x0108
	int32 m_numFirstKills; // 0x010C
	int32 m_numClutchKills; // 0x0110
	int32 m_numPistolKills; // 0x0114
	int32 m_numSniperKills; // 0x0118
	int32 m_iNumSuicides; // 0x011C
	int32 m_iNumTeamKills; // 0x0120
	float32 m_flTeamDamage; // 0x0124
};
class C_OP_RenderCables : public CParticleFunctionRenderer // particles
{
	CParticleCollectionFloatInput m_flRadiusScale; // 0x0228
	CParticleCollectionFloatInput m_flAlphaScale; // 0x0398
	CParticleCollectionVecInput m_vecColorScale; // 0x0508
	ParticleColorBlendType_t m_nColorBlendType; // 0x0BC0
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hMaterial; // 0x0BC8
	TextureRepetitionMode_t m_nTextureRepetitionMode; // 0x0BD0
	CParticleCollectionFloatInput m_flTextureRepeatsPerSegment; // 0x0BD8
	CParticleCollectionFloatInput m_flTextureRepeatsCircumference; // 0x0D48
	CParticleCollectionFloatInput m_flColorMapOffsetV; // 0x0EB8
	CParticleCollectionFloatInput m_flColorMapOffsetU; // 0x1028
	CParticleCollectionFloatInput m_flNormalMapOffsetV; // 0x1198
	CParticleCollectionFloatInput m_flNormalMapOffsetU; // 0x1308
	bool m_bDrawCableCaps; // 0x1478
	float32 m_flCapRoundness; // 0x147C
	float32 m_flCapOffsetAmount; // 0x1480
	float32 m_flTessScale; // 0x1484
	int32 m_nMinTesselation; // 0x1488
	int32 m_nMaxTesselation; // 0x148C
	int32 m_nRoundness; // 0x1490
	bool m_nForceRoundnessFixed; // 0x1494
	bool m_bOnlyRenderInEffectsBloomPass; // 0x1495
	CParticleTransformInput m_LightingTransform; // 0x1498
	CUtlLeanVector< FloatInputMaterialVariable_t > m_MaterialFloatVars; // 0x1500
	CUtlLeanVector< VecInputMaterialVariable_t > m_MaterialVecVars; // 0x1520
};
class VoxelVisBlockOffset_t // worldrenderer
{
	uint32 m_nOffset; // 0x0000
	uint32 m_nElementCount; // 0x0004
};
class FeSimdNodeBase_t // physicslib
{
	uint16[4] nNode; // 0x0000
	uint16[4] nNodeX0; // 0x0008
	uint16[4] nNodeX1; // 0x0010
	uint16[4] nNodeY0; // 0x0018
	uint16[4] nNodeY1; // 0x0020
	uint16[4] nDummy; // 0x0028
	FourQuaternions qAdjust; // 0x0030
};
class NmPercent_t // animlib
{
	float32 m_flValue; // 0x0000
};
class CNmGraphEventConditionNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	int16 m_nSourceStateNodeIdx; // 0x0010
	CNmBitFlags m_eventConditionRules; // 0x0014
	CUtlVectorFixedGrowable< CNmGraphEventConditionNode::Condition_t, 5 > m_conditions; // 0x0018
};
class C_OP_SetPerChildControlPointFromAttribute : public CParticleFunctionOperator // particles
{
	int32 m_nChildGroupID; // 0x01D8
	int32 m_nFirstControlPoint; // 0x01DC
	int32 m_nNumControlPoints; // 0x01E0
	int32 m_nParticleIncrement; // 0x01E4
	int32 m_nFirstSourcePoint; // 0x01E8
	bool m_bNumBasedOnParticleCount; // 0x01EC
	ParticleAttributeIndex_t m_nAttributeToRead; // 0x01F0
	int32 m_nCPField; // 0x01F4
};
class C_OP_LightningSnapshotGenerator : public CParticleFunctionPreEmission // particles
{
	int32 m_nCPSnapshot; // 0x01E0
	int32 m_nCPStartPnt; // 0x01E4
	int32 m_nCPEndPnt; // 0x01E8
	CParticleCollectionFloatInput m_flSegments; // 0x01F0
	CParticleCollectionFloatInput m_flOffset; // 0x0360
	CParticleCollectionFloatInput m_flOffsetDecay; // 0x04D0
	CParticleCollectionFloatInput m_flRecalcRate; // 0x0640
	CParticleCollectionFloatInput m_flUVScale; // 0x07B0
	CParticleCollectionFloatInput m_flUVOffset; // 0x0920
	CParticleCollectionFloatInput m_flSplitRate; // 0x0A90
	CParticleCollectionFloatInput m_flRecursionSplitScale; // 0x0C00
	bool m_bScaleBranchDistance; // 0x0D70
	CParticleCollectionFloatInput m_flBranchDistanceScale; // 0x0D78
	bool m_bScaleBranchOffset; // 0x0EE8
	CParticleCollectionFloatInput m_flBranchOffsetScale; // 0x0EF0
	CParticleCollectionFloatInput m_flBranchTwist; // 0x1060
	ParticleLightnintBranchBehavior_t m_nBranchBehavior; // 0x11D0
	CParticleCollectionFloatInput m_flRadiusStart; // 0x11D8
	CParticleCollectionFloatInput m_flRadiusEnd; // 0x1348
	CParticleCollectionFloatInput m_flDedicatedPool; // 0x14B8
};
class C_OP_RemapSpeed : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	float32 m_flInputMin; // 0x01DC
	float32 m_flInputMax; // 0x01E0
	float32 m_flOutputMin; // 0x01E4
	float32 m_flOutputMax; // 0x01E8
	ParticleSetMethod_t m_nSetMethod; // 0x01EC
	bool m_bIgnoreDelta; // 0x01F0
};
class CDirectionalBlendInstanceData // animgraphlib
{
	float32 m_dampedValue; // 0x0000
	float32 m_flCycle; // 0x0014
	float32 m_flPrevCycle; // 0x0018
	CAnimNetVar< float32 > m_flPlaybackRate; // 0x001C
	CAnimNetVar< float32 > m_flCycleZeroTime; // 0x0028
	CAnimNetVar< float32 > m_resetCycleValue; // 0x0034
	CAnimNetVar< float32 > m_resetCount; // 0x0040
};
class CNmFloatComparisonNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	int16 m_nComparandValueNodeIdx; // 0x0012
	CNmFloatComparisonNode::Comparison_t m_comparison; // 0x0014
	float32 m_flEpsilon; // 0x0018
	float32 m_flComparisonValue; // 0x001C
};
class EventClientOutput_t // engine2
{
	EngineLoopState_t m_LoopState; // 0x0000
	float32 m_flRenderTime; // 0x0028
	float32 m_flRealTime; // 0x002C
	float32 m_flRenderFrameTimeUnbounded; // 0x0030
	bool m_bRenderOnly; // 0x0034
};
class CPathQueryUtil // server
{
	CTransform m_PathToEntityTransform; // 0x0010
	CUtlVector< Vector > m_vecPathSamplePositions; // 0x0030
	CUtlVector< float32 > m_vecPathSampleParameters; // 0x0048
	CUtlVector< float32 > m_vecPathSampleDistances; // 0x0060
	bool m_bIsClosedLoop; // 0x0078
};
class ragdoll_t // server
{
	CUtlVector< ragdollelement_t > list; // 0x0000
	CUtlVector< ragdollhierarchyjoint_t > hierarchyJoints; // 0x0018
	CUtlVector< int32 > boneIndex; // 0x0030
	bool allowStretch; // 0x0048
	bool unused; // 0x0049
};
class CNavHullVData // navlib
{
	bool m_bAgentEnabled; // 0x0000
	float32 m_agentRadius; // 0x0004
	float32 m_agentHeight; // 0x0008
	bool m_agentShortHeightEnabled; // 0x000C
	float32 m_agentShortHeight; // 0x0010
	bool m_agentCrawlEnabled; // 0x0014
	float32 m_agentCrawlHeight; // 0x0018
	float32 m_agentMaxClimb; // 0x001C
	int32 m_agentMaxSlope; // 0x0020
	float32 m_agentMaxJumpDownDist; // 0x0024
	float32 m_agentMaxJumpHorizDistBase; // 0x0028
	float32 m_agentMaxJumpUpDist; // 0x002C
	int32 m_agentBorderErosion; // 0x0030
	bool m_flowMapGenerationEnabled; // 0x0034
	float32 m_flowMapNodeMaxRadius; // 0x0038
};
class C_OP_SetCPOrientationToDirection : public CParticleFunctionOperator // particles
{
	int32 m_nInputControlPoint; // 0x01D8
	int32 m_nOutputControlPoint; // 0x01DC
};
class TextureGroup_t // particles
{
	bool m_bEnabled; // 0x0000
	bool m_bReplaceTextureWithGradient; // 0x0001
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hTexture; // 0x0008
	CColorGradient m_Gradient; // 0x0010
	SpriteCardTextureType_t m_nTextureType; // 0x0028
	SpriteCardTextureChannel_t m_nTextureChannels; // 0x002C
	ParticleTextureLayerBlendType_t m_nTextureBlendMode; // 0x0030
	CParticleCollectionRendererFloatInput m_flTextureBlend; // 0x0038
	TextureControls_t m_TextureControls; // 0x01A8
};
class CVMixOscProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixOscDesc_t m_desc; // 0x0020
};
class CBaseConstraint : public CBoneConstraintBase // modellib
{
	CUtlString m_name; // 0x0020
	Vector m_vUpVector; // 0x0028
	CUtlLeanVector< CConstraintSlave > m_slaves; // 0x0038
	CUtlVector< CConstraintTarget > m_targets; // 0x0048
};
class CPhysSurfacePropertiesSoundNames // modellib
{
	CUtlString m_impactSoft; // 0x0000
	CUtlString m_impactHard; // 0x0008
	CUtlString m_scrapeSmooth; // 0x0010
	CUtlString m_scrapeRough; // 0x0018
	CUtlString m_bulletImpact; // 0x0020
	CUtlString m_rolling; // 0x0028
	CUtlString m_break; // 0x0030
	CUtlString m_strain; // 0x0038
	CUtlString m_meleeImpact; // 0x0040
	CUtlString m_pushOff; // 0x0048
	CUtlString m_skidStop; // 0x0050
	CUtlString m_resonant; // 0x0058
};
class CNmIDComparisonNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	CNmIDComparisonNode::Comparison_t m_comparison; // 0x0012
	CUtlLeanVectorFixedGrowable< CGlobalSymbol, 4 > m_comparisionIDs; // 0x0018
};
class PulseRuntimeChunkIndex_t // pulse_runtime_lib
{
	int32 m_Value; // 0x0000
};
class MaterialParamString_t : public MaterialParam_t // materialsystem2
{
	CUtlString m_value; // 0x0008
};
class EventClientPreSimulate_t : public EventSimulate_t // engine2
{
};
class inv_image_light_sun_t // client
{
	Vector color; // 0x0000
	QAngle angle; // 0x000C
	float32 brightness; // 0x0018
};
class C_OP_Diffusion : public CParticleFunctionOperator // particles
{
	float32 m_flRadiusScale; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
	int32 m_nVoxelGridResolution; // 0x01E0
};
class CSosGroupActionTimeBlockLimitSchema : public CSosGroupActionSchema // soundsystem
{
	int32 m_nMaxCount; // 0x0008
	float32 m_flMaxDuration; // 0x000C
};
class CRootMotion // animgraphlib
{
	CMotionTransform m_deltaTransform; // 0x0000
	Vector m_vVelocityMS; // 0x0010
	Vector m_vUpOverride; // 0x001C
};
class C_OP_RenderProjected : public CParticleFunctionRenderer // particles
{
	bool m_bProjectCharacter; // 0x0228
	bool m_bProjectWorld; // 0x0229
	bool m_bProjectWater; // 0x022A
	bool m_bFlipHorizontal; // 0x022B
	bool m_bEnableProjectedDepthControls; // 0x022C
	float32 m_flMinProjectionDepth; // 0x0230
	float32 m_flMaxProjectionDepth; // 0x0234
	CUtlVector< RenderProjectedMaterial_t > m_vecProjectedMaterials; // 0x0238
	CPerParticleFloatInput m_flMaterialSelection; // 0x0250
	float32 m_flAnimationTimeScale; // 0x03C0
	bool m_bOrientToNormal; // 0x03C4
	CUtlVector< MaterialVariable_t > m_MaterialVars; // 0x03C8
	CParticleCollectionFloatInput m_flRadiusScale; // 0x03E0
	CParticleCollectionFloatInput m_flAlphaScale; // 0x0550
	CParticleCollectionFloatInput m_flRollScale; // 0x06C0
	ParticleAttributeIndex_t m_nAlpha2Field; // 0x0830
	CParticleCollectionVecInput m_vecColorScale; // 0x0838
	ParticleColorBlendType_t m_nColorBlendType; // 0x0EF0
};
class CSteamAudioProbeData // steamaudio
{
	IPLProbeBatch m_pProbeBatch; // 0x0000
};
class VMixShaperDesc_t // soundsystem_lowlevel
{
	int32 m_nShape; // 0x0000
	float32 m_fldbDrive; // 0x0004
	float32 m_fldbOutputGain; // 0x0008
	float32 m_flWetMix; // 0x000C
	int32 m_nOversampleFactor; // 0x0010
};
class CAudioSentence // soundsystem_voicecontainers
{
	bool m_bShouldVoiceDuck; // 0x0000
	CUtlVector< CAudioPhonemeTag > m_RunTimePhonemes; // 0x0008
	CUtlVector< CAudioEmphasisSample > m_EmphasisSamples; // 0x0020
	CAudioMorphData m_morphData; // 0x0038
};
class CSequenceUpdateNode : public CSequenceUpdateNodeBase // animgraphlib
{
	HSequence m_hSequence; // 0x0078
	float32 m_duration; // 0x007C
	CParamSpanUpdater m_paramSpans; // 0x0080
	CUtlVector< TagSpan_t > m_tags; // 0x0098
};
class PermModelInfo_t // modellib
{
	uint32 m_nFlags; // 0x0000
	Vector m_vHullMin; // 0x0004
	Vector m_vHullMax; // 0x0010
	Vector m_vViewMin; // 0x001C
	Vector m_vViewMax; // 0x0028
	float32 m_flMass; // 0x0034
	Vector m_vEyePosition; // 0x0038
	float32 m_flMaxEyeDeflection; // 0x0044
	CUtlString m_sSurfaceProperty; // 0x0048
	CUtlString m_keyValueText; // 0x0050
};
class CNmBlendTask : public CNmBlendTaskBase // animlib
{
};
class CRemapValueUpdateItem // animgraphlib
{
	CAnimParamHandle m_hParamIn; // 0x0000
	CAnimParamHandle m_hParamOut; // 0x0002
	float32 m_flMinInputValue; // 0x0004
	float32 m_flMaxInputValue; // 0x0008
	float32 m_flMinOutputValue; // 0x000C
	float32 m_flMaxOutputValue; // 0x0010
};
class CWarpSectionAnimTag : public CWarpSectionAnimTagBase // animgraphlib
{
	bool m_bWarpPosition; // 0x0050
	bool m_bWarpOrientation; // 0x0051
};
class MoodAnimation_t // animationsystem
{
	CModelAnimNameWithDeltas m_sName; // 0x0000
	float32 m_flWeight; // 0x0008
};
class CVirtualAnimParameter : public CAnimParameterBase // animgraphlib
{
	CUtlString m_expressionString; // 0x0070
	AnimParamType_t m_eParamType; // 0x0078
};
class CVariantDefaultAllocator // entity2
{
};
class CompositeMaterialInputLooseVariable_t // compositematerialslib
{
	CUtlString m_strName; // 0x0000
	bool m_bExposeExternally; // 0x0008
	CUtlString m_strExposedFriendlyName; // 0x0010
	CUtlString m_strExposedFriendlyGroupName; // 0x0018
	bool m_bExposedVariableIsFixedRange; // 0x0020
	CUtlString m_strExposedVisibleWhenTrue; // 0x0028
	CUtlString m_strExposedHiddenWhenTrue; // 0x0030
	CUtlString m_strExposedValueList; // 0x0038
	CompositeMaterialInputLooseVariableType_t m_nVariableType; // 0x0040
	bool m_bValueBoolean; // 0x0044
	int32 m_nValueIntX; // 0x0048
	int32 m_nValueIntY; // 0x004C
	int32 m_nValueIntZ; // 0x0050
	int32 m_nValueIntW; // 0x0054
	bool m_bHasFloatBounds; // 0x0058
	float32 m_flValueFloatX; // 0x005C
	float32 m_flValueFloatX_Min; // 0x0060
	float32 m_flValueFloatX_Max; // 0x0064
	float32 m_flValueFloatY; // 0x0068
	float32 m_flValueFloatY_Min; // 0x006C
	float32 m_flValueFloatY_Max; // 0x0070
	float32 m_flValueFloatZ; // 0x0074
	float32 m_flValueFloatZ_Min; // 0x0078
	float32 m_flValueFloatZ_Max; // 0x007C
	float32 m_flValueFloatW; // 0x0080
	float32 m_flValueFloatW_Min; // 0x0084
	float32 m_flValueFloatW_Max; // 0x0088
	Color m_cValueColor4; // 0x008C
	CompositeMaterialVarSystemVar_t m_nValueSystemVar; // 0x0090
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIMaterial2 > > m_strResourceMaterial; // 0x0098
	CUtlString m_strTextureContentAssetPath; // 0x0178
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCTextureBase > > m_strTextureRuntimeResourcePath; // 0x0180
	CUtlString m_strTextureCompilationVtexTemplate; // 0x0260
	CompositeMaterialInputTextureType_t m_nTextureType; // 0x0268
	CUtlString m_strString; // 0x0270
	CUtlString m_strPanoramaPanelPath; // 0x0278
	int32 m_nPanoramaRenderRes; // 0x0280
};
class C_INIT_NormalOffset : public CParticleFunctionInitializer // particles
{
	Vector m_OffsetMin; // 0x01E0
	Vector m_OffsetMax; // 0x01EC
	int32 m_nControlPointNumber; // 0x01F8
	bool m_bLocalCoords; // 0x01FC
	bool m_bNormalize; // 0x01FD
};
class C_INIT_SetAttributeToScalarExpression : public CParticleFunctionInitializer // particles
{
	ScalarExpressionType_t m_nExpression; // 0x01E0
	CPerParticleFloatInput m_flInput1; // 0x01E8
	CPerParticleFloatInput m_flInput2; // 0x0358
	CParticleRemapFloatInput m_flOutputRemap; // 0x04C8
	ParticleAttributeIndex_t m_nOutputField; // 0x0638
	ParticleSetMethod_t m_nSetMethod; // 0x063C
};
class CVMixShaperProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixShaperDesc_t m_desc; // 0x0020
};
class CVMixFreeverbProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixFreeverbDesc_t m_desc; // 0x0020
};
class FeFitInfluence_t // physicslib
{
	uint32 nVertexNode; // 0x0000
	float32 flWeight; // 0x0004
	uint32 nMatrixNode; // 0x0008
};
class CParticleVecInput : public CParticleInput // particleslib
{
	ParticleVecType_t m_nType; // 0x0010
	Vector m_vLiteralValue; // 0x0014
	Color m_LiteralColor; // 0x0020
	CParticleNamedValueRef m_NamedValue; // 0x0028
	bool m_bFollowNamedValue; // 0x0068
	ParticleAttributeIndex_t m_nVectorAttribute; // 0x006C
	Vector m_vVectorAttributeScale; // 0x0070
	int32 m_nControlPoint; // 0x007C
	int32 m_nDeltaControlPoint; // 0x0080
	Vector m_vCPValueScale; // 0x0084
	Vector m_vCPRelativePosition; // 0x0090
	Vector m_vCPRelativeDir; // 0x009C
	CParticleFloatInput m_FloatComponentX; // 0x00A8
	CParticleFloatInput m_FloatComponentY; // 0x0218
	CParticleFloatInput m_FloatComponentZ; // 0x0388
	CParticleFloatInput m_FloatInterp; // 0x04F8
	float32 m_flInterpInput0; // 0x0668
	float32 m_flInterpInput1; // 0x066C
	Vector m_vInterpOutput0; // 0x0670
	Vector m_vInterpOutput1; // 0x067C
	CColorGradient m_Gradient; // 0x0688
	Vector m_vRandomMin; // 0x06A0
	Vector m_vRandomMax; // 0x06AC
};
class CAnimUserDifference // animationsystem
{
	CBufferString m_name; // 0x0000
	int32 m_nType; // 0x0010
};
class CExampleSchemaVData_PolymorphicBase // resourcefile
{
	int32 m_nBase; // 0x0008
};
class C_OP_GameLiquidSpill : public CParticleFunctionRenderer // particles
{
	CParticleCollectionFloatInput m_flLiquidContentsField; // 0x0228
	CParticleCollectionFloatInput m_flExpirationTime; // 0x0398
	CParticleCollectionFloatInput m_flRadius; // 0x0508
	bool m_bCheckExposedToSky; // 0x0678
	ParticleAttributeIndex_t m_nAmountAttribute; // 0x067C
};
class CPathMetricEvaluator : public CMotionMetricEvaluator // animgraphlib
{
	CUtlVector< float32 > m_pathTimeSamples; // 0x0050
	float32 m_flDistance; // 0x0068
	bool m_bExtrapolateMovement; // 0x006C
	float32 m_flMinExtrapolationSpeed; // 0x0070
};
class CNmCachedTargetNode::CDefinition : public CNmTargetValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	NmCachedValueMode_t m_mode; // 0x0014
};
class EventClientPreOutputParallelWithServer_t : public EventClientPreOutput_t // engine2
{
};
class C_OP_RenderAsModels : public CParticleFunctionRenderer // particles
{
	CUtlVector< ModelReference_t > m_ModelList; // 0x0228
	float32 m_flModelScale; // 0x0244
	bool m_bFitToModelSize; // 0x0248
	bool m_bNonUniformScaling; // 0x0249
	ParticleAttributeIndex_t m_nXAxisScalingAttribute; // 0x024C
	ParticleAttributeIndex_t m_nYAxisScalingAttribute; // 0x0250
	ParticleAttributeIndex_t m_nZAxisScalingAttribute; // 0x0254
	int32 m_nSizeCullBloat; // 0x0258
};
class C_OP_SetControlPointToPlayer : public CParticleFunctionPreEmission // particles
{
	int32 m_nCP1; // 0x01E0
	Vector m_vecCP1Pos; // 0x01E4
	bool m_bOrientToEyes; // 0x01F0
	ParticleEntityPos_t m_nPosition; // 0x01F4
	int32 m_nRadiusCP; // 0x01F8
	int32 m_nRadiusCPField; // 0x01FC
};
class WorldNodeOnDiskBufferData_t // worldrenderer
{
	int32 m_nElementCount; // 0x0000
	int32 m_nElementSizeInBytes; // 0x0004
	CUtlVector< RenderInputLayoutField_t > m_inputLayoutFields; // 0x0008
	CUtlVector< uint8 > m_pData; // 0x0020
};
class CNmClipSelectorNode::CDefinition : public CNmClipReferenceNode::CDefinition // animlib
{
	CUtlLeanVectorFixedGrowable< int16, 8 > m_optionNodeIndices; // 0x0010
	CUtlLeanVectorFixedGrowable< int16, 8 > m_conditionNodeIndices; // 0x0028
};
class CBlockSelectionMetricEvaluator : public CMotionMetricEvaluator // animgraphlib
{
};
class PulseRegisterMap_t // pulse_runtime_lib
{
	KeyValues3 m_Inparams; // 0x0000
	CKV3MemberNameSet m_InparamsWhichCanBeMoved; // 0x0010
	KeyValues3 m_Outparams; // 0x0020
};
class CAnimActionUpdater // animgraphlib
{
};
class InfoForResourceTypeCTypeScriptResource // resourcesystem
{
};
class CNmSnapWeaponTask : public CNmPoseTask // server
{
};
class C_OP_MovementLoopInsideSphere : public CParticleFunctionOperator // particles
{
	int32 m_nCP; // 0x01D8
	CParticleCollectionFloatInput m_flDistance; // 0x01E0
	CParticleCollectionVecInput m_vecScale; // 0x0350
	ParticleAttributeIndex_t m_nDistSqrAttr; // 0x0A08
};
class C_OP_CycleScalar : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nDestField; // 0x01D8
	float32 m_flStartValue; // 0x01DC
	float32 m_flEndValue; // 0x01E0
	float32 m_flCycleTime; // 0x01E4
	bool m_bDoNotRepeatCycle; // 0x01E8
	bool m_bSynchronizeParticles; // 0x01E9
	int32 m_nCPScale; // 0x01EC
	int32 m_nCPFieldMin; // 0x01F0
	int32 m_nCPFieldMax; // 0x01F4
	ParticleSetMethod_t m_nSetMethod; // 0x01F8
};
class CVMixNameInput : public CVMixInputBase // soundsystem_lowlevel
{
	CUtlString m_defaultValue; // 0x0010
};
class CSceneObjectData // modellib
{
	Vector m_vMinBounds; // 0x0000
	Vector m_vMaxBounds; // 0x000C
	CUtlLeanVector< CMaterialDrawDescriptor > m_drawCalls; // 0x0018
	CUtlLeanVector< AABB_t > m_drawBounds; // 0x0028
	CUtlLeanVector< CMeshletDescriptor > m_meshlets; // 0x0038
	CUtlLeanVector< CSceneObjectData::RTProxyDrawDescriptor_t > m_rtProxyDrawCalls; // 0x0048
	Vector4D m_vTintColor; // 0x0058
};
class SkeletonAnimCapture_t::Bone_t // modellib
{
	CUtlString m_Name; // 0x0000
	CTransform m_BindPose; // 0x0010
	int32 m_nParent; // 0x0030
};
class CSlopeComponentUpdater : public CAnimComponentUpdater // animgraphlib
{
	float32 m_flTraceDistance; // 0x0034
	CAnimParamHandle m_hSlopeAngle; // 0x0038
	CAnimParamHandle m_hSlopeAngleFront; // 0x003A
	CAnimParamHandle m_hSlopeAngleSide; // 0x003C
	CAnimParamHandle m_hSlopeHeading; // 0x003E
	CAnimParamHandle m_hSlopeNormal; // 0x0040
	CAnimParamHandle m_hSlopeNormal_WorldSpace; // 0x0042
};
class EventClientPostOutput_t // engine2
{
	EngineLoopState_t m_LoopState; // 0x0000
	float64 m_flRenderTime; // 0x0028
	float32 m_flRenderFrameTime; // 0x0030
	float32 m_flRenderFrameTimeUnbounded; // 0x0034
	bool m_bRenderOnly; // 0x0038
};
class C_OP_RemapScalar : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldInput; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
	float32 m_flInputMin; // 0x01E0
	float32 m_flInputMax; // 0x01E4
	float32 m_flOutputMin; // 0x01E8
	float32 m_flOutputMax; // 0x01EC
	bool m_bOldCode; // 0x01F0
};
class C_OP_DirectionBetweenVecsToVec : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	CPerParticleVecInput m_vecPoint1; // 0x01E0
	CPerParticleVecInput m_vecPoint2; // 0x0898
};
class C_OP_ReinitializeScalarEndCap : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	float32 m_flOutputMin; // 0x01DC
	float32 m_flOutputMax; // 0x01E0
};
class C_OP_NoiseEmitter : public CParticleFunctionEmitter // particles
{
	float32 m_flEmissionDuration; // 0x01E0
	float32 m_flStartTime; // 0x01E4
	float32 m_flEmissionScale; // 0x01E8
	int32 m_nScaleControlPoint; // 0x01EC
	int32 m_nScaleControlPointField; // 0x01F0
	int32 m_nWorldNoisePoint; // 0x01F4
	bool m_bAbsVal; // 0x01F8
	bool m_bAbsValInv; // 0x01F9
	float32 m_flOffset; // 0x01FC
	float32 m_flOutputMin; // 0x0200
	float32 m_flOutputMax; // 0x0204
	float32 m_flNoiseScale; // 0x0208
	float32 m_flWorldNoiseScale; // 0x020C
	Vector m_vecOffsetLoc; // 0x0210
	float32 m_flWorldTimeScale; // 0x021C
};
class CVMixDynamicsCompressorProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixDynamicsCompressorDesc_t m_desc; // 0x0020
};
class CVoiceContainerAsyncGenerator : public CVoiceContainerGenerator // soundsystem_voicecontainers
{
};
class FeNodeIntegrator_t // physicslib
{
	float32 flPointDamping; // 0x0000
	float32 flAnimationForceAttraction; // 0x0004
	float32 flAnimationVertexAttraction; // 0x0008
	float32 flGravity; // 0x000C
};
class FeWorldCollisionParams_t // physicslib
{
	float32 flWorldFriction; // 0x0000
	float32 flGroundFriction; // 0x0004
	uint16 nListBegin; // 0x0008
	uint16 nListEnd; // 0x000A
};
class CNmTargetOffsetNode::CDefinition : public CNmTargetValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	bool m_bIsBoneSpaceOffset; // 0x0012
	Quaternion m_rotationOffset; // 0x0020
	Vector m_translationOffset; // 0x0030
};
class CAnimFrameSegment // animationsystem
{
	int32 m_nUniqueFrameIndex; // 0x0000
	uint32 m_nLocalElementMasks; // 0x0004
	int32 m_nLocalChannel; // 0x0008
	CUtlBinaryBlock m_container; // 0x0010
};
class C_OP_QuantizeCPComponent : public CParticleFunctionPreEmission // particles
{
	CParticleCollectionFloatInput m_flInputValue; // 0x01E0
	int32 m_nCPOutput; // 0x0350
	int32 m_nOutVectorField; // 0x0354
	CParticleCollectionFloatInput m_flQuantizeValue; // 0x0358
};
class C_OP_PerParticleForce : public CParticleFunctionForce // particles
{
	CPerParticleFloatInput m_flForceScale; // 0x01E8
	CPerParticleVecInput m_vForce; // 0x0358
	int32 m_nCP; // 0x0A10
};
class CSndSeqInstruments : public ISndSeqInstruments // soundsystem
{
};
class CNmAndNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	CUtlLeanVectorFixedGrowable< int16, 4 > m_conditionNodeIndices; // 0x0010
};
class ParamSpan_t // animgraphlib
{
	CUtlVector< ParamSpanSample_t > m_samples; // 0x0000
	CAnimParamHandle m_hParam; // 0x0018
	AnimParamType_t m_eParamType; // 0x001A
	float32 m_flStartCycle; // 0x001C
	float32 m_flEndCycle; // 0x0020
};
class CNmFootEventConditionNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	int16 m_nSourceStateNodeIdx; // 0x0010
	NmFootPhaseCondition_t m_phaseCondition; // 0x0012
	CNmBitFlags m_eventConditionRules; // 0x0014
};
class CBinaryUpdateNode : public CAnimUpdateNodeBase // animgraphlib
{
	CAnimUpdateNodeRef m_pChild1; // 0x0060
	CAnimUpdateNodeRef m_pChild2; // 0x0070
	BinaryNodeTiming m_timingBehavior; // 0x0080
	float32 m_flTimingBlend; // 0x0084
	bool m_bResetChild1; // 0x0088
	bool m_bResetChild2; // 0x0089
};
class PointCameraSettings_t // server
{
	float32 m_flNearBlurryDistance; // 0x0000
	float32 m_flNearCrispDistance; // 0x0004
	float32 m_flFarCrispDistance; // 0x0008
	float32 m_flFarBlurryDistance; // 0x000C
};
class FeEdgeDesc_t // physicslib
{
	uint16[2] nEdge; // 0x0000
	uint16[2][2] nSide; // 0x0004
	uint16[2] nVirtElem; // 0x000C
};
class FeMorphLayerDepr_t // physicslib
{
	CUtlString m_Name; // 0x0000
	uint32 m_nNameHash; // 0x0008
	CUtlVector< uint16 > m_Nodes; // 0x0010
	CUtlVector< Vector > m_InitPos; // 0x0028
	CUtlVector< float32 > m_Gravity; // 0x0040
	CUtlVector< float32 > m_GoalStrength; // 0x0058
	CUtlVector< float32 > m_GoalDamping; // 0x0070
	uint32 m_nFlags; // 0x0088
};
class CModelConfigElement // modellib
{
	CUtlString m_ElementName; // 0x0008
	CUtlVector< CModelConfigElement* > m_NestedElements; // 0x0010
};
class CLookAtUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	LookAtOpFixedSettings_t m_opFixedSettings; // 0x0070
	AnimVectorSource m_target; // 0x0148
	CAnimParamHandle m_paramIndex; // 0x014C
	CAnimParamHandle m_weightParamIndex; // 0x014E
	bool m_bResetChild; // 0x0150
	bool m_bLockWhenWaning; // 0x0151
};
class CNmFootstepEventPercentageThroughNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	int16 m_nSourceStateNodeIdx; // 0x0010
	NmFootPhaseCondition_t m_phaseCondition; // 0x0012
	CNmBitFlags m_eventConditionRules; // 0x0014
};
class EventClientSimulate_t : public EventSimulate_t // engine2
{
};
class InfoForResourceTypeIPulseGraphDef // resourcesystem
{
};
class CVoiceContainerSet : public CVoiceContainerBase // soundsystem_voicecontainers
{
	CUtlVector< CVoiceContainerSetElement > m_soundsToPlay; // 0x0070
};
class CModelConfigElement_SetBodygroupOnAttachedModels : public CModelConfigElement // modellib
{
	CUtlString m_GroupName; // 0x0048
	int32 m_nChoice; // 0x0050
};
class CRenderMesh // modellib
{
	CUtlLeanVectorFixedGrowable< CSceneObjectData, 1 > m_sceneObjects; // 0x0010
	CUtlLeanVector< CBaseConstraint* > m_constraints; // 0x00D0
	CRenderSkeleton m_skeleton; // 0x00E0
	bool m_bUseUV2ForCharting; // 0x01EC
	bool m_bEmbeddedMapMesh; // 0x01ED
	DynamicMeshDeformParams_t m_meshDeformParams; // 0x0210
	CRenderGroom* m_pGroomData; // 0x0220
};
class CPlayerControllerComponent // server
{
	CNetworkVarChainer __m_pChainEntity; // 0x0008
};
class C_OP_Decay : public CParticleFunctionOperator // particles
{
	bool m_bRopeDecay; // 0x01D8
	bool m_bForcePreserveParticleOrder; // 0x01D9
};
class C_OP_SnapshotSkinToBones : public CParticleFunctionOperator // particles
{
	bool m_bTransformNormals; // 0x01D8
	bool m_bTransformRadii; // 0x01D9
	int32 m_nControlPointNumber; // 0x01DC
	float32 m_flLifeTimeFadeStart; // 0x01E0
	float32 m_flLifeTimeFadeEnd; // 0x01E4
	float32 m_flJumpThreshold; // 0x01E8
	float32 m_flPrevPosScale; // 0x01EC
};
class IPhysicsRagdollControl // vphysics2
{
};
class CSceneObjectData::RTProxyDrawDescriptor_t // modellib
{
	uint32 m_materialGroupToken; // 0x0000
	int32 m_nSrcDrawIndex; // 0x0004
	CMaterialDrawDescriptor m_drawDesc; // 0x0008
	matrix3x4_t m_mWorldFromLocal; // 0x0120
	VertexAlbedoFormat_t m_nVertexAlbedoFormat; // 0x0150
	int8 m_nVertexAlbedoVB; // 0x0151
	uint16 m_nVertexAlbedoOffset; // 0x0152
	uint16 m_nVertexAlbedoStride; // 0x0154
	VertexAlbedoFormat_t m_nVertexEmissiveFormat; // 0x0156
	int8 m_nVertexEmissiveVB; // 0x0157
	uint16 m_nVertexEmissiveOffset; // 0x0158
	uint16 m_nVertexEmissiveStride; // 0x015A
	float32 m_fEmissiveFactor; // 0x015C
};
class CNmFloatClampNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	Range_t m_clampRange; // 0x0014
};
class C_INIT_DistanceToNeighborCull : public CParticleFunctionInitializer // particles
{
	CPerParticleFloatInput m_flDistance; // 0x01E0
	bool m_bIncludeRadii; // 0x0350
	CPerParticleFloatInput m_flLifespanOverlap; // 0x0358
	ParticleAttributeIndex_t m_nFieldModify; // 0x04C8
	CPerParticleFloatInput m_flModify; // 0x04D0
	ParticleSetMethod_t m_nSetMethod; // 0x0640
	bool m_bUseNeighbor; // 0x0644
};
class CVMixAudioMeter // soundsystem_lowlevel
{
	CUtlString m_name; // 0x0000
	CUtlString m_displayName; // 0x0008
};
class FeRigidColliderIndices_t // physicslib
{
	uint16 m_nTaperedCapsuleRigidIndex; // 0x0000
	uint16 m_nSphereRigidIndex; // 0x0002
	uint16 m_nBoxRigidIndex; // 0x0004
	uint16 m_nSDFRigidIndex; // 0x0006
	uint16 m_nCollisionPlaneIndex; // 0x0008
};
class CNmVelocityBasedSpeedScaleNode::CDefinition : public CNmSpeedScaleBaseNode::CDefinition // animlib
{
};
class RenderSkeletonBone_t // modellib
{
	CUtlString m_boneName; // 0x0000
	CUtlString m_parentName; // 0x0008
	matrix3x4_t m_invBindPose; // 0x0010
	SkeletonBoneBounds_t m_bbox; // 0x0040
	float32 m_flSphereRadius; // 0x0058
};
class C_OP_RampCPLinearRandom : public CParticleFunctionPreEmission // particles
{
	int32 m_nOutControlPointNumber; // 0x01E0
	Vector m_vecRateMin; // 0x01E4
	Vector m_vecRateMax; // 0x01F0
};
class CPulseBreakpointLocation // pulse_runtime_lib
{
	PulseDocNodeID_t m_NodeID; // 0x0000
	PulseSymbol_t m_SequencePoint; // 0x0008
	PulseSymbol_t m_PortName; // 0x0018
};
class PhysShapeMarkup_t // modellib
{
	int32 m_nBodyInAggregate; // 0x0000
	int32 m_nShapeInBody; // 0x0004
	CGlobalSymbol m_sHitGroup; // 0x0008
};
class C_INIT_RemapParticleCountToNamedModelElementScalar : public C_INIT_RemapParticleCountToScalar // particles
{
	CStrongHandle< InfoForResourceTypeCModel > m_hModel; // 0x0210
	CUtlString m_outputMinName; // 0x0218
	CUtlString m_outputMaxName; // 0x0220
	bool m_bModelFromRenderer; // 0x0228
};
class C_INIT_RandomScalar : public CParticleFunctionInitializer // particles
{
	float32 m_flMin; // 0x01E0
	float32 m_flMax; // 0x01E4
	float32 m_flExponent; // 0x01E8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01EC
};
class C_OP_InheritFromParentParticlesV2 : public CParticleFunctionOperator // particles
{
	CPerParticleFloatInput m_flScale; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0348
	CPerParticleFloatInput m_nIncrement; // 0x0350
	bool m_bSubSample; // 0x04C0
	bool m_bRandomDistribution; // 0x04C1
	bool m_bReverse; // 0x04C2
	MissingParentInheritBehavior_t m_nMissingParentBehavior; // 0x04C4
	CPerParticleFloatInput m_flInterpolation; // 0x04C8
};
class PointDefinitionWithTimeValues_t : public PointDefinition_t // particles
{
	float32 m_flTimeDuration; // 0x0014
};
class CSndBeatPattern // soundsystem
{
	CUtlString m_name; // 0x0000
	SndBeatLaunchSyncType_t m_launchSyncType; // 0x000C
	float32 m_flSyncPriority; // 0x0010
	SndBeatTimeSignature_t m_timeSignature; // 0x0014
	float32 m_flLength; // 0x001C
	bool m_bLooping; // 0x0020
	SndBeatEventType_t m_launchSyncEventType; // 0x0024
	float32 m_flSyncBeatMult; // 0x0028
	SndBeatEventType_t m_playEventType; // 0x002C
	float32 m_flPlayBeatMult; // 0x0030
	SndBeatKeyType_t m_keyType; // 0x0034
	CUtlVector< SndBeatEventKeys_t > m_vecPatternKeys; // 0x0038
	CUtlVector< SndBeatEventKeyedFloats_t > m_vecPatternFloats; // 0x0050
	CUtlVector< SndBeatEventKeyedSndEvts_t > m_vecPatternSndEvts; // 0x0068
	CUtlVector< SndBeatEventKeyedMidiNotes_t > m_vecPatternMidi; // 0x0080
};
class CNmPoseNode::CDefinition : public CNmGraphNode::CDefinition // animlib
{
};
class CAnimGraphNetworkSettings : public CAnimGraphSettingsGroup // animgraphlib
{
	bool m_bNetworkingEnabled; // 0x0020
};
class MaterialGroup_t // modellib
{
	CUtlString m_name; // 0x0000
	CUtlVector< CStrongHandle< InfoForResourceTypeIMaterial2 > > m_materials; // 0x0008
};
class CNmAdditiveBlendTask : public CNmBlendTaskBase // animlib
{
};
class CFollowTargetUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	FollowTargetOpFixedSettings_t m_opFixedData; // 0x0070
	CAnimParamHandle m_hParameterPosition; // 0x0088
	CAnimParamHandle m_hParameterOrientation; // 0x008A
};
class CDebugSnapshotData_t // server
{
	CUtlString m_text; // 0x0000
	uint32 m_dataType; // 0x0008
	uint32 m_userFlags; // 0x000C
	uint32 m_userData; // 0x0010
	VectorWS m_userVector; // 0x0014
	CTransformWS m_userTransform; // 0x0020
	CGenericShapeProxy m_userShape; // 0x0040
	Color m_drawColor; // 0x00D8
	CUtlVector< CDebugDrawHistoryData* > m_vecDebugOverlayData; // 0x00E0
	DebugSnapshotBaseStructuredData_t* m_pStructuredData; // 0x00F8
	CHandle< CBaseEntity > m_hEntity; // 0x0100
	CUtlString m_sEntityName; // 0x0108
	CEntityIndex m_nEntityIndex; // 0x0110
	CUtlLeanVector< CDebugSnapshotData_t > m_children; // 0x0120
};
class CNetworkOriginCellCoordQuantizedVectorWS // server
{
	uint16 m_cellX; // 0x0010
	uint16 m_cellY; // 0x0012
	uint16 m_cellZ; // 0x0014
	uint16 m_nOutsideWorld; // 0x0016
	CNetworkedQuantizedFloat m_vecX; // 0x0018
	CNetworkedQuantizedFloat m_vecY; // 0x0020
	CNetworkedQuantizedFloat m_vecZ; // 0x0028
};
class FeRodConstraint_t // physicslib
{
	uint16[2] nNode; // 0x0000
	float32 flMaxDist; // 0x0004
	float32 flMinDist; // 0x0008
	float32 flWeight0; // 0x000C
	float32 flRelaxationFactor; // 0x0010
};
class CNmRootMotionData // animlib
{
	CUtlVector< CTransform > m_transforms; // 0x0000
	int32 m_nNumFrames; // 0x0018
	float32 m_flAverageLinearVelocity; // 0x001C
	float32 m_flAverageAngularVelocityRadians; // 0x0020
	CTransform m_totalDelta; // 0x0030
};
class CBoneConstraintPoseSpaceMorph::Input_t // modellib
{
	Vector m_inputValue; // 0x0000
	CUtlVector< float32 > m_outputWeightList; // 0x0010
};
class CLeafUpdateNode : public CAnimUpdateNodeBase // animgraphlib
{
};
class PhysSoftbodyDesc_t // modellib
{
	CUtlVector< uint32 > m_ParticleBoneHash; // 0x0000
	CUtlVector< RnSoftbodyParticle_t > m_Particles; // 0x0018
	CUtlVector< RnSoftbodySpring_t > m_Springs; // 0x0030
	CUtlVector< RnSoftbodyCapsule_t > m_Capsules; // 0x0048
	CUtlVector< CTransform > m_InitPose; // 0x0060
	CUtlVector< CUtlString > m_ParticleBoneName; // 0x0078
};
class EntComponentInfo_t // entity2
{
	char* m_pName; // 0x0000
	char* m_pCPPClassname; // 0x0008
	char* m_pNetworkDataReferencedDescription; // 0x0010
	char* m_pNetworkDataReferencedPtrPropDescription; // 0x0018
	int32 m_nRuntimeIndex; // 0x0020
	uint32 m_nFlags; // 0x0024
	CEntityComponentHelper* m_pBaseClassComponentHelper; // 0x0060
};
class InfoForResourceTypeCPanoramaLayout // resourcesystem
{
};
class CRelativeLocation // server
{
	RelativeLocationType_t m_Type; // 0x0018
	Vector m_vRelativeOffset; // 0x001C
	VectorWS m_vWorldSpacePos; // 0x0028
	CHandle< CBaseEntity > m_hEntity; // 0x0034
};
class C_OP_RemapTransformToVelocity : public CParticleFunctionOperator // particles
{
	CParticleTransformInput m_TransformInput; // 0x01D8
};
class C_OP_RenderSprites : public CBaseRendererSource2 // particles
{
	CParticleCollectionRendererFloatInput m_nSequenceOverride; // 0x2DF0
	bool m_bSequenceNumbersAreRawSequenceIndices; // 0x2F60
	ParticleOrientationChoiceList_t m_nOrientationType; // 0x2F64
	int32 m_nOrientationControlPoint; // 0x2F68
	bool m_bUseYawWithNormalAligned; // 0x2F6C
	CParticleCollectionRendererFloatInput m_flMinSize; // 0x2F70
	CParticleCollectionRendererFloatInput m_flMaxSize; // 0x30E0
	CParticleCollectionRendererFloatInput m_flSubPixelAAScale; // 0x3250
	CParticleCollectionRendererFloatInput m_flStartFadeSize; // 0x33C0
	CParticleCollectionRendererFloatInput m_flEndFadeSize; // 0x3530
	float32 m_flStartFadeDot; // 0x36A0
	float32 m_flEndFadeDot; // 0x36A4
	bool m_bDistanceAlpha; // 0x36A8
	bool m_bSoftEdges; // 0x36A9
	float32 m_flEdgeSoftnessStart; // 0x36AC
	float32 m_flEdgeSoftnessEnd; // 0x36B0
	bool m_bOutline; // 0x36B4
	Color m_OutlineColor; // 0x36B5
	int32 m_nOutlineAlpha; // 0x36BC
	float32 m_flOutlineStart0; // 0x36C0
	float32 m_flOutlineStart1; // 0x36C4
	float32 m_flOutlineEnd0; // 0x36C8
	float32 m_flOutlineEnd1; // 0x36CC
	ParticleLightingQuality_t m_nLightingMode; // 0x36D0
	CParticleCollectionRendererVecInput m_vecLightingOverride; // 0x36D8
	CParticleCollectionRendererFloatInput m_flLightingTessellation; // 0x3D90
	CParticleCollectionRendererFloatInput m_flLightingDirectionality; // 0x3F00
	bool m_bParticleShadows; // 0x4070
	float32 m_flShadowDensity; // 0x4074
	CReplicationParameters m_replicationParameters; // 0x4078
};
class CVMixControlOutput : public CVMixInputBase // soundsystem_lowlevel
{
	float32 m_flDefaultValue; // 0x0010
};
class CVMixConvolutionProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixConvolutionDesc_t m_desc; // 0x0020
};
class SkeletonAnimCapture_t // modellib
{
	CEntityIndex m_nEntIndex; // 0x0000
	CEntityIndex m_nEntParent; // 0x0004
	CUtlVector< CEntityIndex > m_ImportedCollision; // 0x0008
	CUtlString m_ModelName; // 0x0020
	CUtlString m_CaptureName; // 0x0028
	CUtlVector< SkeletonAnimCapture_t::Bone_t > m_ModelBindPose; // 0x0030
	CUtlVector< SkeletonAnimCapture_t::Bone_t > m_FeModelInitPose; // 0x0048
	int32 m_nFlexControllers; // 0x0060
	bool m_bPredicted; // 0x0064
	CUtlVector< SkeletonAnimCapture_t::Frame_t > m_Frames; // 0x00A8
};
class CMotionNodeSequence : public CMotionNode // animgraphlib
{
	CUtlVector< TagSpan_t > m_tags; // 0x0028
	HSequence m_hSequence; // 0x0040
	float32 m_flPlaybackSpeed; // 0x0044
};
class CNmControlParameterIDNode::CDefinition : public CNmIDValueNode::CDefinition // animlib
{
};
class CBtNodeComposite : public CBtNode // server
{
};
class CParticleFunction // particles
{
	CParticleCollectionFloatInput m_flOpStrength; // 0x0008
	ParticleEndcapMode_t m_nOpEndCapState; // 0x0178
	ParticleToolsState_t m_nToolsState; // 0x017C
	float32 m_flOpStartFadeInTime; // 0x0180
	float32 m_flOpEndFadeInTime; // 0x0184
	float32 m_flOpStartFadeOutTime; // 0x0188
	float32 m_flOpEndFadeOutTime; // 0x018C
	float32 m_flOpFadeOscillatePeriod; // 0x0190
	bool m_bNormalizeToStopTime; // 0x0194
	float32 m_flOpTimeOffsetMin; // 0x0198
	float32 m_flOpTimeOffsetMax; // 0x019C
	int32 m_nOpTimeOffsetSeed; // 0x01A0
	int32 m_nOpTimeScaleSeed; // 0x01A4
	float32 m_flOpTimeScaleMin; // 0x01A8
	float32 m_flOpTimeScaleMax; // 0x01AC
	bool m_bDisableOperator; // 0x01B2
	CUtlString m_Notes; // 0x01B8
};
class C_OP_MoveToHitbox : public CParticleFunctionOperator // particles
{
	CParticleModelInput m_modelInput; // 0x01D8
	CParticleTransformInput m_transformInput; // 0x0238
	float32 m_flLifeTimeLerpStart; // 0x02A4
	float32 m_flLifeTimeLerpEnd; // 0x02A8
	float32 m_flPrevPosScale; // 0x02AC
	char[128] m_HitboxSetName; // 0x02B0
	bool m_bUseBones; // 0x0330
	HitboxLerpType_t m_nLerpType; // 0x0334
	CPerParticleFloatInput m_flInterpolation; // 0x0338
};
class CSteamAudioBakedMaterialsData // steamaudio
{
	CSteamAudioProbeData m_probes; // 0x0000
	CUtlVector< uint32 > m_vecMaterialTokens; // 0x0008
	CUtlVector< float32 > m_vecMaterialWeights; // 0x0020
};
class CNmCachedPoseReadTask : public CNmPoseTask // animlib
{
};
class FootFixedSettings // animgraphlib
{
	TraceSettings_t m_traceSettings; // 0x0000
	VectorAligned m_vFootBaseBindPosePositionMS; // 0x0010
	float32 m_flFootBaseLength; // 0x0020
	float32 m_flMaxRotationLeft; // 0x0024
	float32 m_flMaxRotationRight; // 0x0028
	int32 m_footstepLandedTagIndex; // 0x002C
	bool m_bEnableTracing; // 0x0030
	float32 m_flTraceAngleBlend; // 0x0034
	int32 m_nDisableTagIndex; // 0x0038
	int32 m_nFootIndex; // 0x003C
};
class CAnimSequenceParams // animationsystem
{
	float32 m_flFadeInTime; // 0x0000
	float32 m_flFadeOutTime; // 0x0004
};
class CParticleSystemDefinition : public IParticleSystemDefinition // particles
{
	int32 m_nBehaviorVersion; // 0x0008
	CUtlVector< CParticleFunctionPreEmission* > m_PreEmissionOperators; // 0x0010
	CUtlVector< CParticleFunctionEmitter* > m_Emitters; // 0x0028
	CUtlVector< CParticleFunctionInitializer* > m_Initializers; // 0x0040
	CUtlVector< CParticleFunctionOperator* > m_Operators; // 0x0058
	CUtlVector< CParticleFunctionForce* > m_ForceGenerators; // 0x0070
	CUtlVector< CParticleFunctionConstraint* > m_Constraints; // 0x0088
	CUtlVector< CParticleFunctionRenderer* > m_Renderers; // 0x00A0
	CUtlVector< ParticleChildrenInfo_t > m_Children; // 0x00B8
	int32 m_nFirstMultipleOverride_BackwardCompat; // 0x0178
	int32 m_nInitialParticles; // 0x0258
	int32 m_nMaxParticles; // 0x025C
	int32 m_nGroupID; // 0x0260
	Vector m_BoundingBoxMin; // 0x0264
	Vector m_BoundingBoxMax; // 0x0270
	float32 m_flDepthSortBias; // 0x027C
	int32 m_nSortOverridePositionCP; // 0x0280
	bool m_bInfiniteBounds; // 0x0284
	bool m_bEnableNamedValues; // 0x0285
	CUtlString m_NamedValueDomain; // 0x0288
	CUtlVector< ParticleNamedValueSource_t* > m_NamedValueLocals; // 0x0290
	Color m_ConstantColor; // 0x02A8
	Vector m_ConstantNormal; // 0x02AC
	float32 m_flConstantRadius; // 0x02B8
	float32 m_flConstantRotation; // 0x02BC
	float32 m_flConstantRotationSpeed; // 0x02C0
	float32 m_flConstantLifespan; // 0x02C4
	int32 m_nConstantSequenceNumber; // 0x02C8
	int32 m_nConstantSequenceNumber1; // 0x02CC
	int32 m_nSnapshotControlPoint; // 0x02D0
	CStrongHandle< InfoForResourceTypeIParticleSnapshot > m_hSnapshot; // 0x02D8
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_pszCullReplacementName; // 0x02E0
	float32 m_flCullRadius; // 0x02E8
	float32 m_flCullFillCost; // 0x02EC
	int32 m_nCullControlPoint; // 0x02F0
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_hFallback; // 0x02F8
	int32 m_nFallbackMaxCount; // 0x0300
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_hLowViolenceDef; // 0x0308
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_hReferenceReplacement; // 0x0310
	float32 m_flPreSimulationTime; // 0x0318
	float32 m_flStopSimulationAfterTime; // 0x031C
	float32 m_flMaximumTimeStep; // 0x0320
	float32 m_flMaximumSimTime; // 0x0324
	float32 m_flMinimumSimTime; // 0x0328
	float32 m_flMinimumTimeStep; // 0x032C
	int32 m_nMinimumFrames; // 0x0330
	bool m_bIsGPUParticleSystem; // 0x0334
	int32 m_nMinCPULevel; // 0x0338
	int32 m_nMinGPULevel; // 0x033C
	float32 m_flNoDrawTimeToGoToSleep; // 0x0340
	float32 m_flMaxDrawDistance; // 0x0344
	float32 m_flStartFadeDistance; // 0x0348
	float32 m_flMaxCreationDistance; // 0x034C
	int32 m_nAggregationMinAvailableParticles; // 0x0350
	float32 m_flAggregateRadius; // 0x0354
	bool m_bShouldBatch; // 0x0358
	bool m_bShouldHitboxesFallbackToRenderBounds; // 0x0359
	bool m_bShouldHitboxesFallbackToSnapshot; // 0x035A
	bool m_bShouldHitboxesFallbackToCollisionHulls; // 0x035B
	InheritableBoolType_t m_nViewModelEffect; // 0x035C
	bool m_bScreenSpaceEffect; // 0x0360
	CUtlSymbolLarge m_pszTargetLayerID; // 0x0368
	int32 m_nSkipRenderControlPoint; // 0x0370
	int32 m_nAllowRenderControlPoint; // 0x0374
	bool m_bShouldSort; // 0x0378
	CUtlVector< ParticleControlPointConfiguration_t > m_controlPointConfigurations; // 0x03C0
};
class C_INIT_InitVecCollection : public CParticleFunctionInitializer // particles
{
	CParticleCollectionVecInput m_InputValue; // 0x01E0
	ParticleAttributeIndex_t m_nOutputField; // 0x0898
};
class ExtraVertexStreamOverride_t : public BaseSceneObjectOverride_t // worldrenderer
{
	uint32 m_nSubSceneObject; // 0x0004
	uint32 m_nDrawCallIndex; // 0x0008
	MeshDrawPrimitiveFlags_t m_nAdditionalMeshDrawPrimitiveFlags; // 0x000C
	CRenderBufferBinding m_extraBufferBinding; // 0x0010
};
class VMixAutoFilterDesc_t // soundsystem_lowlevel
{
	float32 m_flEnvelopeAmount; // 0x0000
	float32 m_flAttackTimeMS; // 0x0004
	float32 m_flReleaseTimeMS; // 0x0008
	VMixFilterDesc_t m_filter; // 0x000C
	float32 m_flLFOAmount; // 0x001C
	float32 m_flLFORate; // 0x0020
	float32 m_flPhase; // 0x0024
	VMixLFOShape_t m_nLFOShape; // 0x0028
};
class VMixDynamicsDesc_t // soundsystem_lowlevel
{
	float32 m_fldbGain; // 0x0000
	float32 m_fldbNoiseGateThreshold; // 0x0004
	float32 m_fldbCompressionThreshold; // 0x0008
	float32 m_fldbLimiterThreshold; // 0x000C
	float32 m_fldbKneeWidth; // 0x0010
	float32 m_flRatio; // 0x0014
	float32 m_flLimiterRatio; // 0x0018
	float32 m_flAttackTimeMS; // 0x001C
	float32 m_flReleaseTimeMS; // 0x0020
	float32 m_flRMSTimeMS; // 0x0024
	float32 m_flWetMix; // 0x0028
	bool m_bPeakMode; // 0x002C
};
class CParticleAnimTag : public CAnimTagBase // animgraphlib
{
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_hParticleSystem; // 0x0058
	CUtlString m_particleSystemName; // 0x0060
	CUtlString m_configName; // 0x0068
	bool m_bDetachFromOwner; // 0x0070
	bool m_bAggregate; // 0x0071
	bool m_bStopWhenTagEnds; // 0x0072
	bool m_bTagEndStopIsInstant; // 0x0073
	CUtlString m_attachmentName; // 0x0078
	ParticleAttachment_t m_attachmentType; // 0x0080
	CUtlString m_attachmentCP1Name; // 0x0088
	ParticleAttachment_t m_attachmentCP1Type; // 0x0090
};
class CNmSkeleton::SecondarySkeleton_t // animlib
{
	CGlobalSymbol m_attachToBoneID; // 0x0000
	CStrongHandle< InfoForResourceTypeCNmSkeleton > m_skeleton; // 0x0008
};
class SoundeventPathCornerPairNetworked_t // server
{
	VectorWS vP1; // 0x0000
	VectorWS vP2; // 0x000C
	float32 flPathLengthSqr; // 0x0018
	float32 flP1Pct; // 0x001C
	float32 flP2Pct; // 0x0020
};
class CInButtonState // server
{
	uint64[3] m_pButtonStates; // 0x0008
};
class Relationship_t // server
{
	Disposition_t disposition; // 0x0000
	int32 priority; // 0x0004
};
class C_INIT_CreateFromPlaneCache : public CParticleFunctionInitializer // particles
{
	Vector m_vecOffsetMin; // 0x01E0
	Vector m_vecOffsetMax; // 0x01EC
	bool m_bUseNormal; // 0x01F9
};
class PointDefinition_t // particles
{
	int32 m_nControlPoint; // 0x0000
	bool m_bLocalCoords; // 0x0004
	Vector m_vOffset; // 0x0008
};
class CNmSyncTrack // animlib
{
	CUtlLeanVectorFixedGrowable< CNmSyncTrack::Event_t, 10 > m_syncEvents; // 0x0000
	int32 m_nStartEventOffset; // 0x00A8
};
class CAnimInputDamping // animgraphlib
{
	DampingSpeedFunction m_speedFunction; // 0x0008
	float32 m_fSpeedScale; // 0x000C
	float32 m_fFallingSpeedScale; // 0x0010
};
class CBoneConstraintBase // modellib
{
};
class InfoForResourceTypeIParticleSystemDefinition // resourcesystem
{
};
class CNmSnapWeaponNode::CDefinition : public CNmPassthroughNode::CDefinition // server
{
	int16 m_nFlashedAmountNodeIdx; // 0x0018
	int16 m_nWeaponCategoryNodeIdx; // 0x001A
	int16 m_nWeaponTypeNodeIdx; // 0x001C
};
class CBaseRendererSource2 : public CParticleFunctionRenderer // particles
{
	CParticleCollectionRendererFloatInput m_flRadiusScale; // 0x0228
	CParticleCollectionRendererFloatInput m_flAlphaScale; // 0x0398
	CParticleCollectionRendererFloatInput m_flRollScale; // 0x0508
	ParticleAttributeIndex_t m_nAlpha2Field; // 0x0678
	CParticleCollectionRendererVecInput m_vecColorScale; // 0x0680
	ParticleColorBlendType_t m_nColorBlendType; // 0x0D38
	SpriteCardShaderType_t m_nShaderType; // 0x0D3C
	CUtlString m_strShaderOverride; // 0x0D40
	CParticleCollectionRendererFloatInput m_flCenterXOffset; // 0x0D48
	CParticleCollectionRendererFloatInput m_flCenterYOffset; // 0x0EB8
	float32 m_flBumpStrength; // 0x1028
	ParticleSequenceCropOverride_t m_nCropTextureOverride; // 0x102C
	CUtlLeanVector< TextureGroup_t > m_vecTexturesInput; // 0x1030
	float32 m_flAnimationRate; // 0x1040
	AnimationType_t m_nAnimationType; // 0x1044
	bool m_bAnimateInFPS; // 0x1048
	CParticleCollectionRendererFloatInput m_flMotionVectorScaleU; // 0x1050
	CParticleCollectionRendererFloatInput m_flMotionVectorScaleV; // 0x11C0
	CParticleCollectionRendererFloatInput m_flSelfIllumAmount; // 0x1330
	CParticleCollectionRendererFloatInput m_flDiffuseAmount; // 0x14A0
	CParticleCollectionRendererFloatInput m_flDiffuseClamp; // 0x1610
	int32 m_nLightingControlPoint; // 0x1780
	ParticleOutputBlendMode_t m_nOutputBlendMode; // 0x1784
	bool m_bGammaCorrectVertexColors; // 0x1788
	bool m_bSaturateColorPreAlphaBlend; // 0x1789
	CParticleCollectionRendererFloatInput m_flAddSelfAmount; // 0x1790
	CParticleCollectionRendererFloatInput m_flDesaturation; // 0x1900
	CParticleCollectionRendererFloatInput m_flOverbrightFactor; // 0x1A70
	int32 m_nHSVShiftControlPoint; // 0x1BE0
	ParticleFogType_t m_nFogType; // 0x1BE4
	CParticleCollectionRendererFloatInput m_flFogAmount; // 0x1BE8
	bool m_bTintByFOW; // 0x1D58
	bool m_bTintByGlobalLight; // 0x1D59
	SpriteCardPerParticleScale_t m_nPerParticleAlphaReference; // 0x1D5C
	SpriteCardPerParticleScale_t m_nPerParticleAlphaRefWindow; // 0x1D60
	ParticleAlphaReferenceType_t m_nAlphaReferenceType; // 0x1D64
	CParticleCollectionRendererFloatInput m_flAlphaReferenceSoftness; // 0x1D68
	CParticleCollectionRendererFloatInput m_flSourceAlphaValueToMapToZero; // 0x1ED8
	CParticleCollectionRendererFloatInput m_flSourceAlphaValueToMapToOne; // 0x2048
	bool m_bRefract; // 0x21B8
	bool m_bRefractSolid; // 0x21B9
	bool m_bRefract2Passes; // 0x21BA
	CParticleCollectionRendererFloatInput m_flRefractAmount; // 0x21C0
	int32 m_nRefractBlurRadius; // 0x2330
	BlurFilterType_t m_nRefractBlurType; // 0x2334
	bool m_bOnlyRenderInEffectsBloomPass; // 0x2338
	bool m_bOnlyRenderInEffectsWaterPass; // 0x2339
	bool m_bUseMixedResolutionRendering; // 0x233A
	bool m_bOnlyRenderInEffecsGameOverlay; // 0x233B
	char[128] m_stencilTestID; // 0x233C
	bool m_bStencilTestExclude; // 0x23BC
	char[128] m_stencilWriteID; // 0x23BD
	bool m_bWriteStencilOnDepthPass; // 0x243D
	bool m_bWriteStencilOnDepthFail; // 0x243E
	bool m_bReverseZBuffering; // 0x243F
	bool m_bDisableZBuffering; // 0x2440
	ParticleDepthFeatheringMode_t m_nFeatheringMode; // 0x2444
	CParticleCollectionRendererFloatInput m_flFeatheringMinDist; // 0x2448
	CParticleCollectionRendererFloatInput m_flFeatheringMaxDist; // 0x25B8
	CParticleCollectionRendererFloatInput m_flFeatheringFilter; // 0x2728
	CParticleCollectionRendererFloatInput m_flFeatheringDepthMapFilter; // 0x2898
	CParticleCollectionRendererFloatInput m_flDepthBias; // 0x2A08
	ParticleSortingChoiceList_t m_nSortMethod; // 0x2B78
	bool m_bBlendFramesSeq0; // 0x2B7C
	bool m_bMaxLuminanceBlendingSequence0; // 0x2B7D
};
class C_OP_GameDecalRenderer : public CParticleFunctionRenderer // particles
{
	CGlobalSymbol m_sDecalGroupName; // 0x0228
	EventTypeSelection_t m_nEventType; // 0x0230
	ParticleCollisionMask_t m_nInteractionMask; // 0x0238
	ParticleCollisionGroup_t m_nCollisionGroup; // 0x0240
	CPerParticleVecInput m_vecStartPos; // 0x0248
	CPerParticleVecInput m_vecEndPos; // 0x0900
	CPerParticleFloatInput m_flTraceBloat; // 0x0FB8
	CPerParticleFloatInput m_flDecalSize; // 0x1128
	CPerParticleFloatInput m_nDecalGroupIndex; // 0x1298
	CPerParticleFloatInput m_flDecalRotation; // 0x1408
	CPerParticleVecInput m_vModulationColor; // 0x1578
	bool m_bUseGameDefaultDecalSize; // 0x1C30
	bool m_bRandomDecalRotation; // 0x1C31
	bool m_bRandomlySelectDecalInGroup; // 0x1C32
	bool m_bNoDecalsOnOwner; // 0x1C33
	bool m_bVisualizeTraces; // 0x1C34
};
class CExpressionActionUpdater : public CAnimActionUpdater // animgraphlib
{
	CAnimParamHandle m_hParam; // 0x0018
	AnimParamType_t m_eParamType; // 0x001A
	AnimScriptHandle m_hScript; // 0x001C
};
class CNmClipNode::CDefinition : public CNmClipReferenceNode::CDefinition // animlib
{
	int16 m_nPlayInReverseValueNodeIdx; // 0x0010
	int16 m_nResetTimeValueNodeIdx; // 0x0012
	bool m_bSampleRootMotion; // 0x0014
	bool m_bAllowLooping; // 0x0015
	int16 m_nDataSlotIdx; // 0x0016
	CUtlVectorFixedGrowable< CGlobalSymbol, 2 > m_graphEvents; // 0x0018
	float32 m_flSpeedMultiplier; // 0x0040
	int32 m_nStartSyncEventOffset; // 0x0044
};
class CNmSpeedScaleBaseNode::CDefinition : public CNmPassthroughNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0018
	float32 m_flDefaultInputValue; // 0x001C
};
class CStaticPoseCache // animgraphlib
{
	CUtlVector< CCachedPose > m_poses; // 0x0010
	int32 m_nBoneCount; // 0x0028
	int32 m_nMorphCount; // 0x002C
};
class InfoForResourceTypeCSurfaceGraph // resourcesystem
{
};
class C_OP_RenderBlobs : public CParticleFunctionRenderer // particles
{
	CParticleCollectionRendererFloatInput m_cubeWidth; // 0x0228
	CParticleCollectionRendererFloatInput m_cutoffRadius; // 0x0398
	CParticleCollectionRendererFloatInput m_renderRadius; // 0x0508
	uint32 m_nVertexCountKb; // 0x0678
	uint32 m_nIndexCountKb; // 0x067C
	int32 m_nScaleCP; // 0x0680
	CUtlVector< MaterialVariable_t > m_MaterialVars; // 0x0688
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hMaterial; // 0x06B8
};
class CVMixStereoDelayProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
};
class PulseRuntimeDomainValueIndex_t // pulse_runtime_lib
{
	int16 m_Value; // 0x0000
};
class CAnimDataChannelDesc // animationsystem
{
	CBufferString m_szChannelClass; // 0x0000
	CBufferString m_szVariableName; // 0x0010
	int32 m_nFlags; // 0x0020
	int32 m_nType; // 0x0024
	CBufferString m_szGrouping; // 0x0028
	CBufferString m_szDescription; // 0x0038
	CUtlVector< CBufferString > m_szElementNameArray; // 0x0048
	CUtlVector< int32 > m_nElementIndexArray; // 0x0060
	CUtlVector< uint32 > m_nElementMaskArray; // 0x0078
};
class PostProcessingBloomParameters_t // materialsystem2
{
	BloomBlendMode_t m_blendMode; // 0x0000
	float32 m_flBloomStrength; // 0x0004
	float32 m_flScreenBloomStrength; // 0x0008
	float32 m_flBlurBloomStrength; // 0x000C
	float32 m_flBloomThreshold; // 0x0010
	float32 m_flBloomThresholdWidth; // 0x0014
	float32 m_flSkyboxBloomStrength; // 0x0018
	float32 m_flBloomStartValue; // 0x001C
	float32 m_flComputeBloomStrength; // 0x0020
	float32 m_flComputeBloomThreshold; // 0x0024
	float32 m_flComputeBloomRadius; // 0x0028
	float32 m_flComputeBloomEffectsScale; // 0x002C
	float32 m_flComputeBloomLensDirtStrength; // 0x0030
	float32 m_flComputeBloomLensDirtBlackLevel; // 0x0034
	float32[5] m_flBlurWeight; // 0x0038
	Vector[5] m_vBlurTint; // 0x004C
};
class CCS2ChickenGraphController : public CAnimGraphControllerBase // server
{
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_action; // 0x0088
	CAnimGraph2ParamAutoResetOptionalRef m_bActionReset; // 0x00A0
	CAnimGraph2ParamOptionalRef< float32 > m_idleVariation; // 0x00C0
	CAnimGraph2ParamOptionalRef< float32 > m_runVariation; // 0x00D8
	CAnimGraph2ParamOptionalRef< float32 > m_panicVariation; // 0x00F0
	CAnimGraph2ParamOptionalRef< float32 > m_squatVariation; // 0x0108
	CAnimGraph2ParamOptionalRef< bool > m_bInWater; // 0x0120
	bool m_bHasActionCompletedEvent; // 0x0138
	bool m_bWaitingForCompletedEvent; // 0x0139
};
class C_OP_FadeAndKill : public CParticleFunctionOperator // particles
{
	float32 m_flStartFadeInTime; // 0x01D8
	float32 m_flEndFadeInTime; // 0x01DC
	float32 m_flStartFadeOutTime; // 0x01E0
	float32 m_flEndFadeOutTime; // 0x01E4
	float32 m_flStartAlpha; // 0x01E8
	float32 m_flEndAlpha; // 0x01EC
	bool m_bForcePreserveParticleOrder; // 0x01F0
};
class C_INIT_CreateSpiralSphere : public CParticleFunctionInitializer // particles
{
	CParticleTransformInput m_TransformInput; // 0x01E0
	CPerParticleFloatInput m_flDensity; // 0x0248
	CPerParticleFloatInput m_flInitialRadius; // 0x03B8
	CPerParticleFloatInput m_flInitialSpeedMin; // 0x0528
	CPerParticleFloatInput m_flInitialSpeedMax; // 0x0698
	bool m_bUseParticleCount; // 0x0808
};
class C_OP_EnableChildrenFromParentParticleCount : public CParticleFunctionPreEmission // particles
{
	int32 m_nChildGroupID; // 0x01E0
	int32 m_nFirstChild; // 0x01E4
	CParticleCollectionFloatInput m_nNumChildrenToEnable; // 0x01E8
	bool m_bDisableChildren; // 0x0358
	bool m_bPlayEndcapOnStop; // 0x0359
	bool m_bDestroyImmediately; // 0x035A
};
class PostProcessingLocalExposureParameters_t // materialsystem2
{
	float32 m_fShadowOffsetEV; // 0x0000
	float32 m_fHighlightOffsetEV; // 0x0004
	float32 m_fSigma; // 0x0008
	float32 m_fBoostLocalContrast; // 0x000C
};
class CEntityComponentHelper // entity2
{
	uint32 m_flags; // 0x0008
	EntComponentInfo_t* m_pInfo; // 0x0010
	int32 m_nPriority; // 0x0018
	CEntityComponentHelper* m_pNext; // 0x0020
};
class C_OP_UpdateLightSource : public CParticleFunctionOperator // particles
{
	Color m_vColorTint; // 0x01D8
	float32 m_flBrightnessScale; // 0x01DC
	float32 m_flRadiusScale; // 0x01E0
	float32 m_flMinimumLightingRadius; // 0x01E4
	float32 m_flMaximumLightingRadius; // 0x01E8
	float32 m_flPositionDampingConstant; // 0x01EC
};
class CVMixControlMeter : public CVMixInputBase // soundsystem_lowlevel
{
	int32 m_nValueIndex; // 0x0010
};
class CNmClipReferenceNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
};
class CRootUpdateNode : public CUnaryUpdateNode // animgraphlib
{
};
class CNmDurationScaleNode::CDefinition : public CNmSpeedScaleBaseNode::CDefinition // animlib
{
};
class CAnimTagManagerUpdater // animgraphlib
{
	CUtlVector< CSmartPtr< CAnimTagBase > > m_tags; // 0x0038
};
class CPhysicsShake // server
{
	Vector m_force; // 0x0008
};
class C_OP_SpinUpdate : public CSpinUpdateBase // particles
{
};
class C_OP_MovementSkinnedPositionFromCPSnapshot : public CParticleFunctionOperator // particles
{
	int32 m_nSnapshotControlPointNumber; // 0x01D8
	int32 m_nControlPointNumber; // 0x01DC
	bool m_bRandom; // 0x01E0
	int32 m_nRandomSeed; // 0x01E4
	bool m_bSetNormal; // 0x01E8
	bool m_bSetRadius; // 0x01E9
	SnapshotIndexType_t m_nIndexType; // 0x01EC
	CPerParticleFloatInput m_flReadIndex; // 0x01F0
	CParticleCollectionFloatInput m_flIncrement; // 0x0360
	CParticleCollectionFloatInput m_nFullLoopIncrement; // 0x04D0
	CParticleCollectionFloatInput m_nSnapShotStartPoint; // 0x0640
	CPerParticleFloatInput m_flInterpolation; // 0x07B0
};
class C_OP_OscillateScalar : public CParticleFunctionOperator // particles
{
	float32 m_RateMin; // 0x01D8
	float32 m_RateMax; // 0x01DC
	float32 m_FrequencyMin; // 0x01E0
	float32 m_FrequencyMax; // 0x01E4
	ParticleAttributeIndex_t m_nField; // 0x01E8
	bool m_bProportional; // 0x01EC
	bool m_bProportionalOp; // 0x01ED
	float32 m_flStartTime_min; // 0x01F0
	float32 m_flStartTime_max; // 0x01F4
	float32 m_flEndTime_min; // 0x01F8
	float32 m_flEndTime_max; // 0x01FC
	float32 m_flOscMult; // 0x0200
	float32 m_flOscAdd; // 0x0204
};
class C_INIT_SkyVisCull : public CParticleFunctionInitializer // particles
{
	CParticleCollectionVecInput m_vecTestDir; // 0x01E0
	ParticleTraceSet_t m_nTraceSet; // 0x0898
	bool m_bCullOnSky; // 0x089C
};
class CVoiceContainerShapedNoise : public CVoiceContainerGenerator // soundsystem_voicecontainers
{
	bool m_bUseCurveForFrequency; // 0x0070
	float32 m_flFrequency; // 0x0074
	CPiecewiseCurve m_frequencySweep; // 0x0078
	bool m_bUseCurveForResonance; // 0x00B8
	float32 m_flResonance; // 0x00BC
	CPiecewiseCurve m_resonanceSweep; // 0x00C0
	bool m_bUseCurveForAmplitude; // 0x0100
	float32 m_flGainInDecibels; // 0x0104
	CPiecewiseCurve m_gainSweep; // 0x0108
};
class FeNodeStrayBox_t // physicslib
{
	Vector vMin; // 0x0000
	uint32 nFlags; // 0x000C
	Vector vMax; // 0x0010
	uint16[2] nNode; // 0x001C
};
class FeSoftParent_t // physicslib
{
	int32 nParent; // 0x0000
	float32 flAlpha; // 0x0004
};
class CNmMaterialAttributeEvent : public CNmEvent // animlib
{
	CNmEventTargetEntity_t m_target; // 0x0018
	CUtlString m_attributeName; // 0x0020
	CUtlStringToken m_attributeNameToken; // 0x0028
	CPiecewiseCurve m_x; // 0x0030
	CPiecewiseCurve m_y; // 0x0070
	CPiecewiseCurve m_z; // 0x00B0
	CPiecewiseCurve m_w; // 0x00F0
};
class PairedSequenceData // animgraphlib
{
	PairedSequence_t[8] m_vecPairedSequences; // 0x0000
};
class CHandshakeAnimTagBase : public CAnimTagBase // animgraphlib
{
	bool m_bIsDisableTag; // 0x0050
};
class AutoRoomDoorwayPairs_t // server
{
	VectorWS vP1; // 0x0000
	VectorWS vP2; // 0x000C
};
class C_OP_RemapCPtoScalar : public CParticleFunctionOperator // particles
{
	int32 m_nCPInput; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
	int32 m_nField; // 0x01E0
	float32 m_flInputMin; // 0x01E4
	float32 m_flInputMax; // 0x01E8
	float32 m_flOutputMin; // 0x01EC
	float32 m_flOutputMax; // 0x01F0
	float32 m_flStartTime; // 0x01F4
	float32 m_flEndTime; // 0x01F8
	float32 m_flInterpRate; // 0x01FC
	ParticleSetMethod_t m_nSetMethod; // 0x0200
};
class C_OP_PinParticleToCP : public CParticleFunctionOperator // particles
{
	int32 m_nControlPointNumber; // 0x01D8
	CParticleCollectionVecInput m_vecOffset; // 0x01E0
	bool m_bOffsetLocal; // 0x0898
	ParticleSelection_t m_nParticleSelection; // 0x089C
	CParticleCollectionFloatInput m_nParticleNumber; // 0x08A0
	ParticlePinDistance_t m_nPinBreakType; // 0x0A10
	CParticleCollectionFloatInput m_flBreakDistance; // 0x0A18
	CParticleCollectionFloatInput m_flBreakSpeed; // 0x0B88
	CParticleCollectionFloatInput m_flAge; // 0x0CF8
	int32 m_nBreakControlPointNumber; // 0x0E68
	int32 m_nBreakControlPointNumber2; // 0x0E6C
	CParticleCollectionFloatInput m_flBreakValue; // 0x0E70
	CPerParticleFloatInput m_flInterpolation; // 0x0FE0
	bool m_bRetainInitialVelocity; // 0x1150
};
class VMixFlangerDesc_t // soundsystem_lowlevel
{
	bool m_bPhaseInvert; // 0x0000
	float32 m_flGlideTime; // 0x0004
	float32 m_flDelay; // 0x0008
	float32 m_flOutputGain; // 0x000C
	float32 m_flFeedbackGain; // 0x0010
	float32 m_flFeedforwardGain; // 0x0014
	float32 m_flModRate; // 0x0018
	float32 m_flModDepth; // 0x001C
	bool m_bApplyAntialiasing; // 0x0020
};
class CModelConfigElement_UserPick : public CModelConfigElement // modellib
{
	CUtlVector< CUtlString > m_Choices; // 0x0048
};
class CFootFallAnimTag : public CAnimTagBase // animgraphlib
{
	FootFallTagFoot_t m_foot; // 0x0058
};
class SkeletonAnimCapture_t::Frame_t // modellib
{
	float32 m_flTime; // 0x0000
	SkeletonAnimCapture_t::FrameStamp_t m_Stamp; // 0x0004
	CTransform m_Transform; // 0x0020
	bool m_bTeleport; // 0x0040
	CUtlVector< CTransform > m_CompositeBones; // 0x0048
	CUtlVector< CTransform > m_SimStateBones; // 0x0060
	CUtlVector< CTransform > m_FeModelAnims; // 0x0078
	CUtlVector< VectorAligned > m_FeModelPos; // 0x0090
	CUtlVector< float32 > m_FlexControllerWeights; // 0x00A8
};
class IKTargetSettings_t // animgraphlib
{
	IKTargetSource m_TargetSource; // 0x0000
	IKBoneNameAndIndex_t m_Bone; // 0x0008
	AnimParamID m_AnimgraphParameterNamePosition; // 0x0018
	AnimParamID m_AnimgraphParameterNameOrientation; // 0x001C
	IKTargetCoordinateSystem m_TargetCoordSystem; // 0x0020
};
class C_OP_NormalLock : public CParticleFunctionOperator // particles
{
	int32 m_nControlPointNumber; // 0x01D8
};
class C_INIT_RemapParticleCountToNamedModelBodyPartScalar : public C_INIT_RemapParticleCountToNamedModelElementScalar // particles
{
};
class C_OP_SetVariable : public CParticleFunctionPreEmission // particles
{
	CParticleVariableRef m_variableReference; // 0x01E0
	CParticleTransformInput m_transformInput; // 0x0230
	Vector m_positionOffset; // 0x0298
	QAngle m_rotationOffset; // 0x02A4
	CParticleCollectionVecInput m_vecInput; // 0x02B0
	CParticleCollectionFloatInput m_floatInput; // 0x0968
};
class RnFace_t // physicslib
{
	uint8 m_nEdge; // 0x0000
};
class CAnimUpdateSharedData // animgraphlib
{
	CUtlVector< CSmartPtr< CAnimUpdateNodeBase > > m_nodes; // 0x0010
	CUtlHashtable< CAnimNodePath, int32 > m_nodeIndexMap; // 0x0028
	CUtlVector< CSmartPtr< CAnimComponentUpdater > > m_components; // 0x0048
	CSmartPtr< CAnimParameterManagerUpdater > m_pParamListUpdater; // 0x0060
	CSmartPtr< CAnimTagManagerUpdater > m_pTagManagerUpdater; // 0x0068
	CSmartPtr< CAnimScriptManager > m_scriptManager; // 0x0070
	CAnimGraphSettingsManager m_settings; // 0x0078
	CSmartPtr< CStaticPoseCacheBuilder > m_pStaticPoseCache; // 0x00A8
	CSmartPtr< CAnimSkeleton > m_pSkeleton; // 0x00B0
	CAnimNodePath m_rootNodePath; // 0x00B8
};
class CRopeOverlapHit // server
{
	CHandle< CBaseEntity > m_hEntity; // 0x0000
	CUtlVector< int32 > m_vecOverlappingLinks; // 0x0008
};
class CNavVolumeVector : public CNavVolume // navlib
{
	bool m_bHasBeenPreFiltered; // 0x0080
};
class FeBandBendLimit_t // physicslib
{
	float32 flDistMin; // 0x0000
	float32 flDistMax; // 0x0004
	uint16[6] nNode; // 0x0008
};
class CMovementComponentUpdater : public CAnimComponentUpdater // animgraphlib
{
	CUtlVector< CSmartPtr< CAnimMotorUpdaterBase > > m_motors; // 0x0030
	CAnimInputDamping m_facingDamping; // 0x0048
	int32 m_nDefaultMotorIndex; // 0x0068
	float32 m_flDefaultRunSpeed; // 0x006C
	bool m_bMoveVarsDisabled; // 0x0070
	bool m_bNetworkPath; // 0x0071
	bool m_bNetworkFacing; // 0x0072
	CAnimParamHandle[34] m_paramHandles; // 0x0073
};
class ScriptInfo_t // animgraphlib
{
	CUtlString m_code; // 0x0000
	CUtlVector< CAnimParamHandle > m_paramsModified; // 0x0008
	CUtlVector< int32 > m_proxyReadParams; // 0x0020
	CUtlVector< int32 > m_proxyWriteParams; // 0x0038
	AnimScriptType m_eScriptType; // 0x0050
};
class AnimationDecodeDebugDump_t // animationsystem
{
	AnimationProcessingType_t m_processingType; // 0x0000
	CUtlVector< AnimationDecodeDebugDumpElement_t > m_elems; // 0x0008
};
class CHintMessageQueue // server
{
	float32 m_tmMessageEnd; // 0x0000
	CUtlVector< CHintMessage* > m_messages; // 0x0008
	CBasePlayerController* m_pPlayerController; // 0x0020
};
class WaterWheelDrag_t // server
{
	float32 m_flFractionOfWheelSubmerged; // 0x0000
	float32 m_flWheelDrag; // 0x0004
};
class C_OP_LazyCullCompareFloat : public CParticleFunctionOperator // particles
{
	CPerParticleFloatInput m_flComparsion1; // 0x01D8
	CPerParticleFloatInput m_flComparsion2; // 0x0348
	CPerParticleFloatInput m_flCullTime; // 0x04B8
};
class C_INIT_GlobalScale : public CParticleFunctionInitializer // particles
{
	float32 m_flScale; // 0x01E0
	int32 m_nScaleControlPointNumber; // 0x01E4
	int32 m_nControlPointNumber; // 0x01E8
	bool m_bScaleRadius; // 0x01EC
	bool m_bScalePosition; // 0x01ED
	bool m_bScaleVelocity; // 0x01EE
};
class RnWing_t // physicslib
{
	int32[3] m_nIndex; // 0x0000
};
class FeModelSelfCollisionLayer_t // physicslib
{
	CUtlString m_Name; // 0x0000
	CUtlVector< uint16 > m_Nodes; // 0x0008
	float32 m_flParentReaction; // 0x0020
	uint32 m_nFlags; // 0x0024
	uint32[4] m_nEndIdx; // 0x0028
};
class CNmTransitionNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
	int16 m_nTargetStateNodeIdx; // 0x0010
	int16 m_nDurationOverrideNodeIdx; // 0x0012
	int16 m_timeOffsetOverrideNodeIdx; // 0x0014
	int16 m_startBoneMaskNodeIdx; // 0x0016
	float32 m_flDuration; // 0x0018
	NmPercent_t m_boneMaskBlendInTimePercentage; // 0x001C
	float32 m_flTimeOffset; // 0x0020
	CNmBitFlags m_transitionOptions; // 0x0024
	int16 m_targetSyncIDNodeIdx; // 0x0028
	NmEasingOperation_t m_blendWeightEasing; // 0x002A
	NmRootMotionBlendMode_t m_rootMotionBlend; // 0x002B
};
class CSeqCmdLayer // animationsystem
{
	int16 m_cmd; // 0x0000
	int16 m_nLocalReference; // 0x0002
	int16 m_nLocalBonemask; // 0x0004
	int16 m_nDstResult; // 0x0006
	int16 m_nSrcResult; // 0x0008
	bool m_bSpline; // 0x000A
	float32 m_flVar1; // 0x000C
	float32 m_flVar2; // 0x0010
	int16 m_nLineNumber; // 0x0014
};
class GameTick_t // entity2
{
	int32 m_Value; // 0x0000
};
class CRandomPannerControls // soundsystem_voicecontainers
{
	CUtlString m_panningControlInputName; // 0x0000
	CUtlString m_volumeControlInputName; // 0x0008
	float32 m_flMinVolume; // 0x0010
	float32 m_flMaxVolume; // 0x0014
	CUtlString m_strVectorStackParam; // 0x0018
};
class CVoiceContainerLoopXFade : public CVoiceContainerBase // soundsystem_voicecontainers
{
	CSoundContainerReference m_sound; // 0x0070
	float32 m_flLoopEnd; // 0x0090
	float32 m_flLoopStart; // 0x0094
	float32 m_flFadeOut; // 0x0098
	float32 m_flFadeIn; // 0x009C
	bool m_bPlayHead; // 0x00A0
	bool m_bPlayTail; // 0x00A1
	bool m_bEqualPow; // 0x00A2
};
class CVsndRadioButtonSlot // soundsystem_voicecontainers
{
	bool m_bEnableVsnd; // 0x0000
	CSoundContainerReference m_vsnd; // 0x0008
	bool m_bEnableEndcap; // 0x0028
	CSoundContainerReference m_endcapVsnd; // 0x0030
	bool m_bEnableLoopcap; // 0x0050
	CSoundContainerReference m_loopcapVsnd; // 0x0058
	int32 m_group; // 0x0078
	float32 m_volume; // 0x007C
	float32 m_fadeOut; // 0x0080
	EVsndPlaybackMode m_mode; // 0x0084
};
class FeAntiTunnelGroupBuild_t // physicslib
{
	uint32 m_nVertexMapHash; // 0x0000
	uint32 m_nCollisionMask; // 0x0004
};
class CFootstepLandedAnimTag : public CAnimTagBase // animgraphlib
{
	FootstepLandedFootSoundType_t m_FootstepType; // 0x0058
	CUtlString m_OverrideSoundName; // 0x0060
	CUtlString m_DebugAnimSourceString; // 0x0068
	CUtlString m_BoneName; // 0x0070
	FootstepJumpPhase_t m_footstepJumpPhase; // 0x0078
};
class CNmEntityAttributeIntEvent : public CNmEntityAttributeEventBase // animlib
{
	int32 m_nIntValue; // 0x0038
};
class EventSplitScreenStateChanged_t // engine2
{
};
class CRandSimTimer : public CSimpleSimTimer // server
{
	float32 m_flMinInterval; // 0x0008
	float32 m_flMaxInterval; // 0x000C
};
class CSteamAudioCompressedReverb // steamaudio
{
	int32 m_nChannels; // 0x0000
	int32 m_nBands; // 0x0004
	int32 m_nBins; // 0x0008
	int32 m_nProbes; // 0x000C
	CUtlVector< int32 > m_vecNumSingularValues; // 0x0010
	CUtlVector< float32 > m_vecDictionary; // 0x0028
	CUtlVector< float32 > m_vecCompressedData; // 0x0040
	IPLCompressedEnergyFields m_pCompressedData; // 0x0058
};
class EventClientPollInput_t // engine2
{
	EngineLoopState_t m_LoopState; // 0x0000
	float32 m_flRealTime; // 0x0028
};
class C_OP_RenderPoints : public CParticleFunctionRenderer // particles
{
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hMaterial; // 0x0228
};
class C_OP_SetCPOrientationToPointAtCP : public CParticleFunctionPreEmission // particles
{
	int32 m_nInputCP; // 0x01E0
	int32 m_nOutputCP; // 0x01E4
	CParticleCollectionFloatInput m_flInterpolation; // 0x01E8
	bool m_b2DOrientation; // 0x0358
	bool m_bAvoidSingularity; // 0x0359
	bool m_bPointAway; // 0x035A
};
class CVoiceContainerDefault : public CVoiceContainerBase // soundsystem_voicecontainers
{
};
class RnCapsuleDesc_t : public RnShapeDesc_t // physicslib
{
	RnCapsule_t m_Capsule; // 0x0018
};
class RnHull_t // physicslib
{
	Vector m_vCentroid; // 0x0000
	float32 m_flMaxAngularRadius; // 0x000C
	AABB_t m_Bounds; // 0x0010
	Vector m_vOrthographicAreas; // 0x0028
	matrix3x4_t m_MassProperties; // 0x0034
	float32 m_flVolume; // 0x0064
	float32 m_flSurfaceArea; // 0x0068
	CUtlVector< Vector > m_VertexPositions; // 0x0070
	CUtlVector< RnPlane_t > m_FacePlanes; // 0x0088
	uint32 m_nFlags; // 0x00A0
	CRegionSVM* m_pRegionSVM; // 0x00A8
	CUtlVector< RnVertex_t > m_Vertices; // 0x00B0
	CUtlVector< RnHalfEdge_t > m_Edges; // 0x00C8
	CUtlVector< RnFace_t > m_Faces; // 0x00E0
};
class CNmBoneMaskBlendNode::CDefinition : public CNmBoneMaskValueNode::CDefinition // animlib
{
	int16 m_nSourceMaskNodeIdx; // 0x0010
	int16 m_nTargetMaskNodeIdx; // 0x0012
	int16 m_nBlendWeightValueNodeIdx; // 0x0014
};
class CFootPinningUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	FootPinningPoseOpFixedData_t m_poseOpFixedData; // 0x0078
	FootPinningTimingSource m_eTimingSource; // 0x00A8
	CUtlVector< CAnimParamHandle > m_params; // 0x00B0
	bool m_bResetChild; // 0x00C8
};
class PairedSequence_t // animgraphlib
{
	CGlobalSymbol m_sRole; // 0x0000
	CGlobalSymbol m_sSequenceName; // 0x0008
	CAnimNetVar< uint32 > m_hSequence; // 0x0010
};
class EventClientPostSimulate_t : public EventSimulate_t // engine2
{
};
class C_OP_MultiSegmentDisplaySnapshotGenerator : public CParticleFunctionPreEmission // particles
{
	int32 m_nCPSnapshot; // 0x01E0
	ParticleMultiSegmentCountSelection_t m_nSegCount; // 0x01E4
	ParticleMultiSegmentInputSelection_t m_nInputType; // 0x01E8
	CUtlString m_strDefaultString; // 0x01F0
	CParticleCollectionFloatInput m_flValue; // 0x01F8
	CParticleCollectionFloatInput m_flScollOffset; // 0x0368
	CUtlVector< ParticleMultiSegmentSpecialCharacter_t > m_SpecialCharList; // 0x04D8
	CParticleCollectionVecInput m_vecColorUnlit; // 0x04F0
	CParticleCollectionVecInput m_vecColorLit; // 0x0BA8
	CParticleCollectionFloatInput m_flRadius; // 0x1260
	CParticleCollectionFloatInput m_flSpacing; // 0x13D0
	CParticleCollectionFloatInput m_flMinCount; // 0x1540
	CParticleCollectionFloatInput m_flMaxCount; // 0x16B0
	bool m_bPrependEmpty; // 0x1820
	CParticleCollectionFloatInput m_flDigitsAfterDecimal; // 0x1828
};
class CGenericShapeProxy // physicslib
{
	CUtlLeanVectorFixedGrowable< Vector, 8 > m_verts; // 0x0030
};
class CAnimLocalHierarchy // animationsystem
{
	CBufferString m_sBone; // 0x0000
	CBufferString m_sNewParent; // 0x0010
	int32 m_nStartFrame; // 0x0020
	int32 m_nPeakFrame; // 0x0024
	int32 m_nTailFrame; // 0x0028
	int32 m_nEndFrame; // 0x002C
};
class FeNodeBase_t // physicslib
{
	uint16 nNode; // 0x0000
	uint16[3] nDummy; // 0x0002
	uint16 nNodeX0; // 0x0008
	uint16 nNodeX1; // 0x000A
	uint16 nNodeY0; // 0x000C
	uint16 nNodeY1; // 0x000E
	QuaternionStorage qAdjust; // 0x0010
};
class InfoForResourceTypeIVectorGraphic // resourcesystem
{
};
class CompMatPropertyMutator_t // compositematerialslib
{
	bool m_bEnabled; // 0x0000
	CompMatPropertyMutatorType_t m_nMutatorCommandType; // 0x0004
	CUtlString m_strInitWith_Container; // 0x0008
	CUtlString m_strCopyProperty_InputContainerSrc; // 0x0010
	CUtlString m_strCopyProperty_InputContainerProperty; // 0x0018
	CUtlString m_strCopyProperty_TargetProperty; // 0x0020
	CUtlString m_strRandomRollInputVars_SeedInputVar; // 0x0028
	CUtlVector< CUtlString > m_vecRandomRollInputVars_InputVarsToRoll; // 0x0030
	CUtlString m_strCopyMatchingKeys_InputContainerSrc; // 0x0048
	CUtlString m_strCopyKeysWithSuffix_InputContainerSrc; // 0x0050
	CUtlString m_strCopyKeysWithSuffix_FindSuffix; // 0x0058
	CUtlString m_strCopyKeysWithSuffix_ReplaceSuffix; // 0x0060
	CompositeMaterialInputLooseVariable_t m_nSetValue_Value; // 0x0068
	CUtlString m_strGenerateTexture_TargetParam; // 0x02F0
	CUtlString m_strGenerateTexture_InitialContainer; // 0x02F8
	int32 m_nResolution; // 0x0300
	bool m_bIsScratchTarget; // 0x0304
	CUtlString m_strCompressionFormat; // 0x0308
	bool m_bSplatDebugInfo; // 0x0310
	bool m_bCaptureInRenderDoc; // 0x0311
	CUtlVector< CompMatPropertyMutator_t > m_vecTexGenInstructions; // 0x0318
	CUtlVector< CompMatPropertyMutator_t > m_vecConditionalMutators; // 0x0330
	CUtlString m_strPopInputQueue_Container; // 0x0348
	CUtlString m_strDrawText_InputContainerSrc; // 0x0350
	CUtlString m_strDrawText_InputContainerProperty; // 0x0358
	Vector2D m_vecDrawText_Position; // 0x0360
	Color m_colDrawText_Color; // 0x0368
	CUtlString m_strDrawText_Font; // 0x0370
	CUtlVector< CompMatMutatorCondition_t > m_vecConditions; // 0x0378
};
class CCSPlayerAnimationState // server
{
	CCSPlayerAnimationState::MoveType_t m_currentMoveType; // 0x0018
	CCSPlayerAnimationState::GroundMoveState_t m_groundMoveState; // 0x0019
	CCSPlayerAnimationState::Direction_t m_groundActionDirection; // 0x001A
	CCSPlayerAnimationState::AirAction_t m_airAction; // 0x001B
	bool m_bWasOnGroundLastUpdate; // 0x001C
	bool m_bWasStationaryLastUpdate; // 0x001D
	GameTick_t m_actionStartTick; // 0x0020
	GameTick_t m_staticAimTimerStartTick; // 0x0024
	GameTick_t m_plantAndTurnStartTick; // 0x0028
	float32 m_flTurnOnSpotAngle; // 0x002C
	float32 m_flPreviousAimYaw; // 0x0030
	float32 m_flPreviousHorizontalSpeed; // 0x0034
	float32 m_flFootIKOffsetLeft; // 0x0038
	float32 m_flFootIKOffsetRight; // 0x003C
	float32 m_flWeaponDropPercentageDueToMovement; // 0x0040
	float32 m_flWeaponDropSmoothDampVelocity; // 0x0044
};
class C_OP_SetControlPointToHand : public CParticleFunctionPreEmission // particles
{
	int32 m_nCP1; // 0x01E0
	int32 m_nHand; // 0x01E4
	Vector m_vecCP1Pos; // 0x01E8
	bool m_bOrientToHand; // 0x01F4
};
class CVMixSteamAudioPathingProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
};
class VertexPositionNormal_t // physicslib
{
	Vector m_vPosition; // 0x0000
	Vector m_vNormal; // 0x000C
};
class FeFitWeight_t // physicslib
{
	float32 flWeight; // 0x0000
	uint16 nNode; // 0x0004
	uint16 nDummy; // 0x0006
};
class CIntAnimParameter : public CConcreteAnimParameter // animgraphlib
{
	int32 m_defaultValue; // 0x0080
	int32 m_minValue; // 0x0084
	int32 m_maxValue; // 0x0088
};
class CAnimUser // animationsystem
{
	CBufferString m_name; // 0x0000
	int32 m_nType; // 0x0010
};
class CAnimEventDefinition // animationsystem
{
	int32 m_nFrame; // 0x0008
	int32 m_nEndFrame; // 0x000C
	float32 m_flCycle; // 0x0010
	float32 m_flDuration; // 0x0014
	KeyValues3 m_EventData; // 0x0018
	CBufferString m_sLegacyOptions; // 0x0028
	CGlobalSymbol m_sEventName; // 0x0038
};
class NmSyncTrackTimeRange_t // animlib
{
	NmSyncTrackTime_t m_startTime; // 0x0000
	NmSyncTrackTime_t m_endTime; // 0x0008
};
class RsDepthStencilStateDesc_t // rendersystemdx11
{
	bitfield:1 m_bDepthTestEnable; // 0x0000
	bitfield:1 m_bDepthWriteEnable; // 0x0000
	bitfield:4 m_depthFunc; // 0x0000
	RsStencilStateDesc_t m_stencilState; // 0x0002
};
class InfoForResourceTypeCPhysAggregateData // resourcesystem
{
};
class IPhysicsParticleRope // vphysics2
{
};
class CAnimComponentUpdater // animgraphlib
{
	CUtlString m_name; // 0x0018
	AnimComponentID m_id; // 0x0020
	AnimNodeNetworkMode m_networkMode; // 0x0024
	bool m_bStartEnabled; // 0x0028
};
class C_CommandContext // client
{
	bool needsprocessing; // 0x0000
	int32 command_number; // 0x00A0
};
class thinkfunc_t // server
{
	BASEPTR m_think; // 0x0000
	HSCRIPT m_hFn; // 0x0008
	CUtlStringToken m_nContext; // 0x0010
	GameTick_t m_nNextThinkTick; // 0x0014
	GameTick_t m_nLastThinkTick; // 0x0018
};
class C_OP_SetVectorAttributeToVectorExpression : public CParticleFunctionOperator // particles
{
	VectorExpressionType_t m_nExpression; // 0x01D8
	CPerParticleVecInput m_vInput1; // 0x01E0
	CPerParticleVecInput m_vInput2; // 0x0898
	CPerParticleFloatInput m_flLerp; // 0x0F50
	ParticleAttributeIndex_t m_nOutputField; // 0x10C0
	ParticleSetMethod_t m_nSetMethod; // 0x10C4
	bool m_bNormalizedOutput; // 0x10C8
};
class EntityKeyValueData_t // worldrenderer
{
	CUtlVector< EntityIOConnectionData_t > m_connections; // 0x0008
	CUtlBinaryBlock m_keyValuesData; // 0x0020
};
class CVoiceContainerStaticAdditiveSynth::CHarmonic // soundsystem_voicecontainers
{
	EWaveform m_nWaveform; // 0x0000
	EMidiNote m_nFundamental; // 0x0001
	int32 m_nOctave; // 0x0004
	float32 m_flCents; // 0x0008
	float32 m_flPhase; // 0x000C
	CPiecewiseCurve m_curve; // 0x0010
	CVoiceContainerStaticAdditiveSynth::CGainScalePerInstance m_volumeScaling; // 0x0050
};
class PhysicsParticleId_t // physicslib
{
	uint32 m_Value; // 0x0000
};
class CNmParameterizedBlendNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
	CUtlLeanVectorFixedGrowable< int16, 5 > m_sourceNodeIndices; // 0x0010
	int16 m_nInputParameterValueNodeIdx; // 0x0028
	bool m_bAllowLooping; // 0x002A
};
class CAnimGraphModelBinding // animgraphlib
{
	CUtlString m_modelName; // 0x0008
	CSmartPtr< CAnimUpdateSharedData > m_pSharedData; // 0x0010
};
class CAnimGraph2InstancePtr // server
{
};
class CAI_ExpresserWithFollowup : public CAI_Expresser // server
{
};
class C_INIT_VelocityRandom : public CParticleFunctionInitializer // particles
{
	int32 m_nControlPointNumber; // 0x01E0
	CPerParticleFloatInput m_fSpeedMin; // 0x01E8
	CPerParticleFloatInput m_fSpeedMax; // 0x0358
	CPerParticleVecInput m_LocalCoordinateSystemSpeedMin; // 0x04C8
	CPerParticleVecInput m_LocalCoordinateSystemSpeedMax; // 0x0B80
	bool m_bIgnoreDT; // 0x1238
	CRandomNumberGeneratorParameters m_randomnessParameters; // 0x123C
};
class C_OP_CylindricalDistanceToTransform : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	CPerParticleFloatInput m_flInputMin; // 0x01E0
	CPerParticleFloatInput m_flInputMax; // 0x0350
	CPerParticleFloatInput m_flOutputMin; // 0x04C0
	CPerParticleFloatInput m_flOutputMax; // 0x0630
	CParticleTransformInput m_TransformStart; // 0x07A0
	CParticleTransformInput m_TransformEnd; // 0x0808
	ParticleSetMethod_t m_nSetMethod; // 0x0870
	bool m_bActiveRange; // 0x0874
	bool m_bAdditive; // 0x0875
	bool m_bCapsule; // 0x0876
};
class C_OP_SetControlPointRotation : public CParticleFunctionPreEmission // particles
{
	CParticleCollectionVecInput m_vecRotAxis; // 0x01E0
	CParticleCollectionFloatInput m_flRotRate; // 0x0898
	int32 m_nCP; // 0x0A08
	int32 m_nLocalCP; // 0x0A0C
};
class CAnimationGraphVisualizerLine : public CAnimationGraphVisualizerPrimitiveBase // animgraphlib
{
	VectorAligned m_vWsPositionStart; // 0x0040
	VectorAligned m_vWsPositionEnd; // 0x0050
	Color m_Color; // 0x0060
};
class CVMixPannerProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixPannerDesc_t m_desc; // 0x0020
};
class CTaskStatusAnimTag : public CAnimTagBase // animgraphlib
{
};
class CNmFloatChannelData::ChannelSettings_t // animlib
{
	NmCompressionSettings_t::QuantizationRange_t m_range; // 0x0000
	bool m_bIsStatic; // 0x0008
};
class CMotionMatchingUpdateNode : public CLeafUpdateNode // animgraphlib
{
	CMotionDataSet m_dataSet; // 0x0058
	CUtlVector< CSmartPtr< CMotionMetricEvaluator > > m_metrics; // 0x0078
	CUtlVector< float32 > m_weights; // 0x0090
	bool m_bSearchEveryTick; // 0x00E0
	float32 m_flSearchInterval; // 0x00E4
	bool m_bSearchWhenClipEnds; // 0x00E8
	bool m_bSearchWhenGoalChanges; // 0x00E9
	CBlendCurve m_blendCurve; // 0x00EC
	float32 m_flSampleRate; // 0x00F4
	float32 m_flBlendTime; // 0x00F8
	bool m_bLockClipWhenWaning; // 0x00FC
	float32 m_flSelectionThreshold; // 0x0100
	float32 m_flReselectionTimeWindow; // 0x0104
	bool m_bEnableRotationCorrection; // 0x0108
	bool m_bGoalAssist; // 0x0109
	float32 m_flGoalAssistDistance; // 0x010C
	float32 m_flGoalAssistTolerance; // 0x0110
	CAnimInputDamping m_distanceScale_Damping; // 0x0118
	float32 m_flDistanceScale_OuterRadius; // 0x0130
	float32 m_flDistanceScale_InnerRadius; // 0x0134
	float32 m_flDistanceScale_MaxScale; // 0x0138
	float32 m_flDistanceScale_MinScale; // 0x013C
	bool m_bEnableDistanceScaling; // 0x0140
};
class VMapResourceData_t // worldrenderer
{
};
class CSosGroupActionOcclusionSchema : public CSosGroupActionSchema // soundsystem
{
	float32 m_flCalculationInterval; // 0x0008
	float32 m_flRadius; // 0x000C
	float32 m_flOcclusionScale; // 0x0010
	float32 m_flOcclusionMin; // 0x0014
	float32 m_flOcclusionMax; // 0x0018
	float32 m_flTestDepth; // 0x001C
};
class CNmFloatAngleMathNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	CNmFloatAngleMathNode::Operation_t m_operation; // 0x0012
};
class CNmBlendTaskBase : public CNmPoseTask // animlib
{
};
class AimCameraOpFixedSettings_t // animgraphlib
{
	int32 m_nChainIndex; // 0x0000
	int32 m_nCameraJointIndex; // 0x0004
	int32 m_nPelvisJointIndex; // 0x0008
	int32 m_nClavicleLeftJointIndex; // 0x000C
	int32 m_nClavicleRightJointIndex; // 0x0010
	int32 m_nDepenetrationJointIndex; // 0x0014
	CUtlVector< int32 > m_propJoints; // 0x0018
};
class SheetSequenceIntegerId_t // rendersystemdx11
{
	uint32 m_Value; // 0x0000
};
class CGameScriptedMoveData // server
{
	Vector m_vAccumulatedRootMotion; // 0x0000
	QAngle m_angAccumulatedRootMotionRotation; // 0x000C
	VectorWS m_vSrc; // 0x0018
	QAngle m_angSrc; // 0x0024
	QAngle m_angCurrent; // 0x0030
	float32 m_flLockedSpeed; // 0x003C
	float32 m_flAngRate; // 0x0040
	float32 m_flDuration; // 0x0044
	GameTime_t m_flStartTime; // 0x0048
	bool m_bActive; // 0x004C
	bool m_bTeleportOnEnd; // 0x004D
	bool m_bIgnoreRotation; // 0x004E
	bool m_bSuccess; // 0x004F
	ForcedCrouchState_t m_nForcedCrouchState; // 0x0050
	bool m_bIgnoreCollisions; // 0x0054
	Vector m_vDest; // 0x0058
	QAngle m_angDst; // 0x0064
	CHandle< CBaseEntity > m_hDestEntity; // 0x0070
};
class C_OP_PlaneCull : public CParticleFunctionOperator // particles
{
	int32 m_nPlaneControlPoint; // 0x01D8
	CParticleCollectionVecInput m_vecPlaneDirection; // 0x01E0
	bool m_bLocalSpace; // 0x0898
	float32 m_flPlaneOffset; // 0x089C
};
class C_OP_SetControlPointsToModelParticles : public CParticleFunctionOperator // particles
{
	char[128] m_HitboxSetName; // 0x01D8
	char[128] m_AttachmentName; // 0x0258
	int32 m_nFirstControlPoint; // 0x02D8
	int32 m_nNumControlPoints; // 0x02DC
	int32 m_nFirstSourcePoint; // 0x02E0
	bool m_bSkin; // 0x02E4
	bool m_bAttachment; // 0x02E5
};
class C_INIT_RemapScalarToVector : public CParticleFunctionInitializer // particles
{
	ParticleAttributeIndex_t m_nFieldInput; // 0x01E0
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E4
	float32 m_flInputMin; // 0x01E8
	float32 m_flInputMax; // 0x01EC
	Vector m_vecOutputMin; // 0x01F0
	Vector m_vecOutputMax; // 0x01FC
	float32 m_flStartTime; // 0x0208
	float32 m_flEndTime; // 0x020C
	ParticleSetMethod_t m_nSetMethod; // 0x0210
	int32 m_nControlPointNumber; // 0x0214
	bool m_bLocalCoords; // 0x0218
	float32 m_flRemapBias; // 0x021C
};
class CNmFollowBoneNode::CDefinition : public CNmPassthroughNode::CDefinition // animlib
{
	CGlobalSymbol m_bone; // 0x0018
	CGlobalSymbol m_followTargetBone; // 0x0020
	int16 m_nEnabledNodeIdx; // 0x0028
	NmFollowBoneMode_t m_mode; // 0x002A
};
class CNmControlParameterVectorNode::CDefinition : public CNmVectorValueNode::CDefinition // animlib
{
};
class CHitBox // modellib
{
	CUtlString m_name; // 0x0000
	CUtlString m_sSurfaceProperty; // 0x0008
	CUtlString m_sBoneName; // 0x0010
	Vector m_vMinBounds; // 0x0018
	Vector m_vMaxBounds; // 0x0024
	float32 m_flShapeRadius; // 0x0030
	uint32 m_nBoneNameHash; // 0x0034
	int32 m_nGroupId; // 0x0038
	uint8 m_nShapeType; // 0x003C
	bool m_bTranslationOnly; // 0x003D
	uint32 m_CRC; // 0x0040
	Color m_cRenderColor; // 0x0044
	uint16 m_nHitBoxIndex; // 0x0048
};
class CMovementHandshakeAnimTag : public CHandshakeAnimTagBase // animgraphlib
{
};
class RsRasterizerStateDesc_t // rendersystemdx11
{
	RsFillMode_t m_nFillMode; // 0x0000
	RsCullMode_t m_nCullMode; // 0x0001
	bool m_bDepthClipEnable; // 0x0002
	bool m_bMultisampleEnable; // 0x0003
	int32 m_nDepthBias; // 0x0004
	float32 m_flDepthBiasClamp; // 0x0008
	float32 m_flSlopeScaledDepthBias; // 0x000C
};
class PackedAABB_t // mathlib_extended
{
	uint32 m_nPackedMin; // 0x0000
	uint32 m_nPackedMax; // 0x0004
};
class InfoForResourceTypeCVoiceContainerBase // resourcesystem
{
};
class C_OP_RampScalarSplineSimple : public CParticleFunctionOperator // particles
{
	float32 m_Rate; // 0x01D8
	float32 m_flStartTime; // 0x01DC
	float32 m_flEndTime; // 0x01E0
	ParticleAttributeIndex_t m_nField; // 0x0210
	bool m_bEaseOut; // 0x0214
};
class Dop26_t // physicslib
{
	float32[26] m_flSupport; // 0x0000
};
class PulseRuntimeOutputIndex_t // pulse_runtime_lib
{
	int32 m_Value; // 0x0000
};
class CRemapValueComponentUpdater : public CAnimComponentUpdater // animgraphlib
{
	CUtlVector< CRemapValueUpdateItem > m_items; // 0x0030
};
class CNmBoneMaskSelectorNode::CDefinition : public CNmBoneMaskValueNode::CDefinition // animlib
{
	int16 m_defaultMaskNodeIdx; // 0x0010
	int16 m_parameterValueNodeIdx; // 0x0012
	bool m_bSwitchDynamically; // 0x0014
	CUtlLeanVectorFixedGrowable< int16, 8 > m_maskNodeIndices; // 0x0018
	CUtlLeanVectorFixedGrowable< CGlobalSymbol, 7 > m_parameterValues; // 0x0030
	float32 m_flBlendTimeSeconds; // 0x0070
};
class InfoForResourceTypeCNmGraphDefinition // resourcesystem
{
};
class C_INIT_CreatePhyllotaxis : public CParticleFunctionInitializer // particles
{
	int32 m_nControlPointNumber; // 0x01E0
	int32 m_nScaleCP; // 0x01E4
	int32 m_nComponent; // 0x01E8
	float32 m_fRadCentCore; // 0x01EC
	float32 m_fRadPerPoint; // 0x01F0
	float32 m_fRadPerPointTo; // 0x01F4
	float32 m_fpointAngle; // 0x01F8
	float32 m_fsizeOverall; // 0x01FC
	float32 m_fRadBias; // 0x0200
	float32 m_fMinRad; // 0x0204
	float32 m_fDistBias; // 0x0208
	bool m_bUseLocalCoords; // 0x020C
	bool m_bUseWithContEmit; // 0x020D
	bool m_bUseOrigRadius; // 0x020E
};
class C_INIT_AddVectorToVector : public CParticleFunctionInitializer // particles
{
	Vector m_vecScale; // 0x01E0
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01EC
	ParticleAttributeIndex_t m_nFieldInput; // 0x01F0
	Vector m_vOffsetMin; // 0x01F4
	Vector m_vOffsetMax; // 0x0200
	CRandomNumberGeneratorParameters m_randomnessParameters; // 0x020C
};
class C_OP_RestartAfterDuration : public CParticleFunctionOperator // particles
{
	float32 m_flDurationMin; // 0x01D8
	float32 m_flDurationMax; // 0x01DC
	int32 m_nCP; // 0x01E0
	int32 m_nCPField; // 0x01E4
	int32 m_nChildGroupID; // 0x01E8
	bool m_bOnlyChildren; // 0x01EC
};
class C_INIT_InitVec : public CParticleFunctionInitializer // particles
{
	CPerParticleVecInput m_InputValue; // 0x01E0
	ParticleAttributeIndex_t m_nOutputField; // 0x0898
	ParticleSetMethod_t m_nSetMethod; // 0x089C
	bool m_bNormalizedOutput; // 0x08A0
	bool m_bWritePreviousPosition; // 0x08A1
};
class vphysics_save_cphysicsbody_t : public RnBodyDesc_t // vphysics2
{
	uint64 m_nOldPointer; // 0x00E0
};
class CRangeFloat // tier2
{
	float32[2] m_pValue; // 0x0000
};
class C_OP_RemapNamedModelMeshGroupOnceTimed : public C_OP_RemapNamedModelElementOnceTimed // particles
{
};
class C_OP_RemapTransformOrientationToYaw : public CParticleFunctionOperator // particles
{
	CParticleTransformInput m_TransformInput; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0240
	float32 m_flRotOffset; // 0x0244
	float32 m_flSpinStrength; // 0x0248
};
class RnHullDesc_t : public RnShapeDesc_t // physicslib
{
	RnHull_t m_Hull; // 0x0018
};
class CAnimGraphSettingsGroup // animgraphlib
{
};
class CActionComponentUpdater : public CAnimComponentUpdater // animgraphlib
{
	CUtlVector< CSmartPtr< CAnimActionUpdater > > m_actions; // 0x0030
};
class CNmBlend1DNode::CDefinition : public CNmParameterizedBlendNode::CDefinition // animlib
{
	CNmParameterizedBlendNode::Parameterization_t m_parameterization; // 0x0030
};
class NetVarConfigIndex // animgraphlib
{
	CAnimNetVar< uint32 > m_index; // 0x0000
};
class EventClientProcessNetworking_t // engine2
{
	int32 m_nTickCount; // 0x0000
};
class InfoForResourceTypeCTextureBase // resourcesystem
{
};
class screenshake_t // client
{
	GameTime_t endtime; // 0x0000
	float32 duration; // 0x0004
	float32 amplitude; // 0x0008
	float32 frequency; // 0x000C
	GameTime_t nextShake; // 0x0010
	Vector offset; // 0x0014
	float32 angle; // 0x0020
	Vector direction; // 0x0028
	uint8 nShakeType; // 0x0034
};
class IRagdoll // server
{
};
class MaterialParamFloat_t : public MaterialParam_t // materialsystem2
{
	float32 m_flValue; // 0x0008
};
class PhysObjectHeader_t // server
{
	PhysInterfaceId_t type; // 0x0000
	CHandle< CBaseEntity > hEntity; // 0x0004
	CUtlSymbolLarge fieldName; // 0x0008
	bool bSaveObject; // 0x0010
	CUtlSymbolLarge modelName; // 0x0018
	AABB_t bbox; // 0x0020
	physics_save_sphere_t sphere; // 0x0038
	int32 iCollide; // 0x003C
};
class IEconItemInterface // server
{
};
class CSteamAudioSceneData // steamaudio
{
	IPLScene m_pScene; // 0x0000
	IPLStaticMesh m_pStaticMesh; // 0x0008
};
class CDSPMixgroupModifier // soundsystem
{
	CUtlString m_mixgroup; // 0x0000
	float32 m_flModifier; // 0x0008
	float32 m_flModifierMin; // 0x000C
	float32 m_flSourceModifier; // 0x0010
	float32 m_flSourceModifierMin; // 0x0014
	float32 m_flListenerReverbModifierWhenSourceReverbIsActive; // 0x0018
};
class CVMixImpulseResponseInput : public CVMixInputBase // soundsystem_lowlevel
{
};
class VPhysXJoint_t // modellib
{
	uint16 m_nType; // 0x0000
	uint16 m_nBody1; // 0x0002
	uint16 m_nBody2; // 0x0004
	uint16 m_nFlags; // 0x0006
	CTransform m_Frame1; // 0x0010
	CTransform m_Frame2; // 0x0030
	bool m_bEnableCollision; // 0x0050
	bool m_bIsLinearConstraintDisabled; // 0x0051
	bool m_bIsAngularConstraintDisabled; // 0x0052
	bool m_bEnableLinearLimit; // 0x0053
	VPhysXRange_t m_LinearLimit; // 0x0054
	bool m_bEnableLinearMotor; // 0x005C
	Vector m_vLinearTargetVelocity; // 0x0060
	float32 m_flMaxForce; // 0x006C
	bool m_bEnableSwingLimit; // 0x0070
	VPhysXRange_t m_SwingLimit; // 0x0074
	bool m_bEnableTwistLimit; // 0x007C
	VPhysXRange_t m_TwistLimit; // 0x0080
	bool m_bEnableAngularMotor; // 0x0088
	Vector m_vAngularTargetVelocity; // 0x008C
	float32 m_flMaxTorque; // 0x0098
	float32 m_flLinearFrequency; // 0x009C
	float32 m_flLinearDampingRatio; // 0x00A0
	float32 m_flAngularFrequency; // 0x00A4
	float32 m_flAngularDampingRatio; // 0x00A8
	float32 m_flFriction; // 0x00AC
	float32 m_flElasticity; // 0x00B0
	float32 m_flElasticDamping; // 0x00B4
	float32 m_flPlasticity; // 0x00B8
	CUtlString m_Tag; // 0x00C0
};
class CStopwatchBase : public CSimpleSimTimer // server
{
	bool m_bIsRunning; // 0x0008
};
class CPlayerInputAnimMotorUpdater : public CAnimMotorUpdaterBase // animgraphlib
{
	CUtlVector< float32 > m_sampleTimes; // 0x0020
	float32 m_flSpringConstant; // 0x003C
	float32 m_flAnticipationDistance; // 0x0040
	CAnimParamHandle m_hAnticipationPosParam; // 0x0044
	CAnimParamHandle m_hAnticipationHeadingParam; // 0x0046
	bool m_bUseAcceleration; // 0x0048
};
class CParticleProperty // particleslib
{
};
class ControlPointReference_t // particles
{
	int32 m_controlPointNameString; // 0x0000
	Vector m_vOffsetFromControlPoint; // 0x0004
	bool m_bOffsetInLocalSpace; // 0x0010
};
class C_OP_LockToPointList : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	CUtlVector< PointDefinition_t > m_pointList; // 0x01E0
	bool m_bPlaceAlongPath; // 0x01F8
	bool m_bClosedLoop; // 0x01F9
	int32 m_nNumPointsAlongPath; // 0x01FC
};
class CVSound // soundsystem_voicecontainers
{
	CUtlLeanVector< CAudioSentence > m_Sentences; // 0x0000
	int32 m_nRate; // 0x0010
	CVSoundFormat_t m_nFormat; // 0x0014
	uint32 m_nChannels; // 0x0018
	int32 m_nLoopStart; // 0x001C
	uint32 m_nSampleCount; // 0x0020
	float32 m_flDuration; // 0x0024
	uint32 m_nStreamingSize; // 0x0028
	int32 m_nLoopEnd; // 0x002C
};
class CSndSeqInstSndEvtSchema : public CSndSeqInstBaseSchema // soundsystem
{
};
class FeSimdQuad_t // physicslib
{
	uint16[4][4] nNode; // 0x0000
	fltx4 f4Slack; // 0x0020
	FourVectors[4] vShape; // 0x0030
	fltx4[4] f4Weights; // 0x00F0
};
class CNmSelectorNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
	CUtlLeanVectorFixedGrowable< int16, 8 > m_optionNodeIndices; // 0x0010
	CUtlLeanVectorFixedGrowable< int16, 8 > m_conditionNodeIndices; // 0x0028
};
class CNmFloatMathNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdxA; // 0x0010
	int16 m_nInputValueNodeIdxB; // 0x0012
	bool m_bReturnAbsoluteResult; // 0x0014
	bool m_bReturnNegatedResult; // 0x0015
	CNmFloatMathNode::Operator_t m_operator; // 0x0016
	float32 m_flValueB; // 0x0018
};
class CVPhysXSurfacePropertiesList // modellib
{
	CUtlVector< CPhysSurfaceProperties* > m_surfacePropertiesList; // 0x0000
};
class EventAdvanceTick_t : public EventSimulate_t // engine2
{
	int32 m_nCurrentTick; // 0x0030
	int32 m_nCurrentTickThisFrame; // 0x0034
	int32 m_nTotalTicksThisFrame; // 0x0038
	int32 m_nTotalTicks; // 0x003C
};
class CNmEventConsumerSound : public CNmEventConsumer // server
{
};
class C_OP_OscillateVectorSimple : public CParticleFunctionOperator // particles
{
	Vector m_Rate; // 0x01D8
	Vector m_Frequency; // 0x01E4
	ParticleAttributeIndex_t m_nField; // 0x01F0
	float32 m_flOscMult; // 0x01F4
	float32 m_flOscAdd; // 0x01F8
	bool m_bOffset; // 0x01FC
};
class C_OP_Spin : public CGeneralSpin // particles
{
};
class C_OP_AlphaDecay : public CParticleFunctionOperator // particles
{
	float32 m_flMinAlpha; // 0x01D8
};
class C_INIT_CreateParticleImpulse : public CParticleFunctionInitializer // particles
{
	CPerParticleFloatInput m_InputRadius; // 0x01E0
	CPerParticleFloatInput m_InputMagnitude; // 0x0350
	ParticleFalloffFunction_t m_nFalloffFunction; // 0x04C0
	CPerParticleFloatInput m_InputFalloffExp; // 0x04C8
	ParticleImpulseType_t m_nImpulseType; // 0x0638
};
class C_INIT_RemapInitialTransformDirectionToRotation : public CParticleFunctionInitializer // particles
{
	CParticleTransformInput m_TransformInput; // 0x01E0
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0248
	float32 m_flOffsetRot; // 0x024C
	int32 m_nComponent; // 0x0250
};
class C_OP_WorldCollideConstraint : public CParticleFunctionConstraint // particles
{
};
class BaseSceneObjectOverride_t // worldrenderer
{
	uint32 m_nSceneObjectIndex; // 0x0000
};
class CVoiceContainerLoopTriggerWithRandomPanner : public CVoiceContainerLoopTrigger // soundsystem_voicecontainers
{
	CRandomPannerControls m_randomPannerControls; // 0x00A0
};
class OldFeEdge_t // physicslib
{
	float32[3] m_flK; // 0x0000
	float32 invA; // 0x000C
	float32 t; // 0x0010
	float32 flThetaRelaxed; // 0x0014
	float32 flThetaFactor; // 0x0018
	float32 c01; // 0x001C
	float32 c02; // 0x0020
	float32 c03; // 0x0024
	float32 c04; // 0x0028
	float32 flAxialModelDist; // 0x002C
	float32[4] flAxialModelWeights; // 0x0030
	uint16[4] m_nNode; // 0x0040
};
class vphysics_save_ragdoll_control_t // vphysics2
{
	float32 m_flMinSpringFrequency; // 0x0000
	float32 m_flMaxSpringFrequency; // 0x0004
	float32 m_flMaxStretch; // 0x0008
	bool m_bSolidCollisionAtZeroWeight; // 0x000C
	bool m_bRequiresDynamicBodies; // 0x000D
	bool m_bIgnoreTeleport; // 0x000E
	Vector m_vLinearVelocityAccumulator; // 0x0010
	RotationVector m_vAngularVelocityAccumulator; // 0x001C
	Vector m_vForceAccumulator; // 0x0028
	int32 m_nBodyCount; // 0x0034
};
class PermModelExtPart_t // modellib
{
	CTransform m_Transform; // 0x0000
	CUtlString m_Name; // 0x0020
	int32 m_nParent; // 0x0028
	CStrongHandle< InfoForResourceTypeCModel > m_refModel; // 0x0030
};
class MotionDBIndex // animgraphlib
{
	uint32 m_nIndex; // 0x0000
};
class CExampleSchemaVData_PolymorphicDerivedA : public CExampleSchemaVData_PolymorphicBase // resourcefile
{
	int32 m_nDerivedA; // 0x0010
};
class EmptyTestScript : public CAnimScriptBase // host
{
	CAnimScriptParam< float32 > m_hTest; // 0x0010
};
class C_OP_RenderLights : public C_OP_RenderPoints // particles
{
	float32 m_flAnimationRate; // 0x0230
	AnimationType_t m_nAnimationType; // 0x0234
	bool m_bAnimateInFPS; // 0x0238
	float32 m_flMinSize; // 0x023C
	float32 m_flMaxSize; // 0x0240
	float32 m_flStartFadeSize; // 0x0244
	float32 m_flEndFadeSize; // 0x0248
};
class C_OP_StopAfterCPDuration : public CParticleFunctionPreEmission // particles
{
	CParticleCollectionFloatInput m_flDuration; // 0x01E0
	bool m_bDestroyImmediately; // 0x0350
	bool m_bPlayEndCap; // 0x0351
};
class C_INIT_Orient2DRelToCP : public CParticleFunctionInitializer // particles
{
	int32 m_nCP; // 0x01E0
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E4
	float32 m_flRotOffset; // 0x01E8
};
class CVMixControlInput : public CVMixInputBase // soundsystem_lowlevel
{
	float32 m_flDefaultValue; // 0x0010
};
class PulseRuntimeRegisterIndex_t // pulse_runtime_lib
{
	int16 m_Value; // 0x0000
};
class CNmTargetWarpNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
	int16 m_nClipReferenceNodeIdx; // 0x0010
	int16 m_nTargetValueNodeIdx; // 0x0012
	CNmRootMotionData::SamplingMode_t m_samplingMode; // 0x0014
	CNmTargetWarpNode::TargetUpdateRule_t m_targetUpdateRule; // 0x0015
	bool m_bAlignWithTargetAtLastWarpEvent; // 0x0016
	float32 m_flSamplingPositionErrorThresholdSq; // 0x0018
	float32 m_flMaxTangentLength; // 0x001C
	float32 m_flLerpFallbackDistanceThreshold; // 0x0020
	float32 m_flTargetUpdateDistanceThreshold; // 0x0024
	float32 m_flTargetUpdateAngleThresholdRadians; // 0x0028
	CGlobalSymbol m_alignmentBoneID; // 0x0030
};
class NavHull_t // navlib
{
	int32 m_nHullIdx; // 0x0000
};
class C_OP_RemapCPVelocityToVector : public CParticleFunctionOperator // particles
{
	int32 m_nControlPoint; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
	float32 m_flScale; // 0x01E0
	bool m_bNormalize; // 0x01E4
};
class C_OP_RenderSimpleModelCollection : public CParticleFunctionRenderer // particles
{
	bool m_bCenterOffset; // 0x0228
	CStrongHandle< InfoForResourceTypeCModel > m_hModel; // 0x0230
	CParticleModelInput m_modelInput; // 0x0238
	CParticleCollectionFloatInput m_fSizeCullScale; // 0x0298
	bool m_bDisableShadows; // 0x0408
	bool m_bDisableMotionBlur; // 0x0409
	bool m_bAcceptsDecals; // 0x040A
	CPerParticleFloatInput m_fDrawFilter; // 0x0410
	ParticleAttributeIndex_t m_nAngularVelocityField; // 0x0580
};
class C_OP_HSVShiftToCP : public CParticleFunctionPreEmission // particles
{
	int32 m_nColorCP; // 0x01E0
	int32 m_nColorGemEnableCP; // 0x01E4
	int32 m_nOutputCP; // 0x01E8
	Color m_DefaultHSVColor; // 0x01EC
};
class C_OP_SpinYaw : public CGeneralSpin // particles
{
};
class CSosGroupActionTimeLimitSchema : public CSosGroupActionSchema // soundsystem
{
	float32 m_flMaxDuration; // 0x0008
};
class CStanceOverrideUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	CUtlVector< StanceInfo_t > m_footStanceInfo; // 0x0070
	CAnimUpdateNodeRef m_pStanceSourceNode; // 0x0088
	CAnimParamHandle m_hParameter; // 0x0098
	StanceOverrideMode m_eMode; // 0x009C
};
class CCycleBase // modellib
{
	float32 m_flCycle; // 0x0000
};
class InfoForResourceTypeCDotaItemDefinitionResource // resourcesystem
{
};
class hudtextparms_t // server
{
	Color color1; // 0x0000
	Color color2; // 0x0004
	uint8 effect; // 0x0008
	uint8 channel; // 0x0009
	float32 x; // 0x000C
	float32 y; // 0x0010
};
class CVMixEnvelopeProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixEnvelopeDesc_t m_desc; // 0x0020
};
class IKBoneNameAndIndex_t // animgraphlib
{
	CUtlString m_Name; // 0x0000
};
class CAnimDecoder // animationsystem
{
	CBufferString m_szName; // 0x0000
	int32 m_nVersion; // 0x0010
	int32 m_nType; // 0x0014
};
class CFlexController // modellib
{
	CUtlString m_szName; // 0x0000
	CUtlString m_szType; // 0x0008
	float32 min; // 0x0010
	float32 max; // 0x0014
};
class CPointConstraint : public CBaseConstraint // modellib
{
};
class CParticleCollectionRendererVecInput : public CParticleCollectionVecInput // particleslib
{
};
class EventAppShutdown_t // engine2
{
	int32 m_nDummy0; // 0x0000
};
class C_OP_RenderText : public CParticleFunctionRenderer // particles
{
	Color m_OutlineColor; // 0x0228
	CUtlString m_DefaultText; // 0x0230
};
class CParticleFunctionEmitter : public CParticleFunction // particles
{
	int32 m_nEmitterIndex; // 0x01D8
};
class RnCapsule_t // physicslib
{
	Vector[2] m_vCenter; // 0x0000
	float32 m_flRadius; // 0x0018
};
class CNmFloatSpringNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	float32 m_flStartValue; // 0x0010
	float32 m_flHertz; // 0x0014
	float32 m_flDampingRatio; // 0x0018
	int16 m_nInputValueNodeIdx; // 0x001C
	bool m_bUseStartValue; // 0x001E
};
class AnimParamID // modellib
{
	uint32 m_id; // 0x0000
};
class InfoForResourceTypeCWorldNode // resourcesystem
{
};
class C_INIT_SetHitboxToClosest : public CParticleFunctionInitializer // particles
{
	int32 m_nControlPointNumber; // 0x01E0
	int32 m_nDesiredHitbox; // 0x01E4
	CParticleCollectionVecInput m_vecHitBoxScale; // 0x01E8
	char[128] m_HitboxSetName; // 0x08A0
	bool m_bUseBones; // 0x0920
	bool m_bUseClosestPointOnHitbox; // 0x0921
	ClosestPointTestType_t m_nTestType; // 0x0924
	CParticleCollectionFloatInput m_flHybridRatio; // 0x0928
	bool m_bUpdatePosition; // 0x0A98
};
class C_OP_RemapNamedModelElementOnceTimed : public CParticleFunctionOperator // particles
{
	CStrongHandle< InfoForResourceTypeCModel > m_hModel; // 0x01D8
	CUtlVector< CUtlString > m_inNames; // 0x01E0
	CUtlVector< CUtlString > m_outNames; // 0x01F8
	CUtlVector< CUtlString > m_fallbackNames; // 0x0210
	bool m_bModelFromRenderer; // 0x0228
	bool m_bProportional; // 0x0229
	ParticleAttributeIndex_t m_nFieldInput; // 0x022C
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0230
	float32 m_flRemapTime; // 0x0234
};
class C_INIT_RandomYaw : public CGeneralRandomRotation // particles
{
};
class CFutureVelocityMetricEvaluator : public CMotionMetricEvaluator // animgraphlib
{
	float32 m_flDistance; // 0x0050
	float32 m_flStoppingDistance; // 0x0054
	float32 m_flTargetSpeed; // 0x0058
	VelocityMetricMode m_eMode; // 0x005C
};
class CTaskHandshakeAnimTag : public CHandshakeAnimTagBase // animgraphlib
{
};
class CExampleSchemaVData_Monomorphic // resourcefile
{
	int32 m_nExample1; // 0x0000
	int32 m_nExample2; // 0x0004
};
class IChoreoServices // server
{
};
class C_OP_SetControlPointPositionToRandomActiveCP : public CParticleFunctionPreEmission // particles
{
	int32 m_nCP1; // 0x01E0
	int32 m_nHeadLocationMin; // 0x01E4
	int32 m_nHeadLocationMax; // 0x01E8
	CParticleCollectionFloatInput m_flResetRate; // 0x01F0
};
class CSteamAudioProbeGrid // steamaudio
{
	AABB_t m_aabb; // 0x0000
	float32 m_flSpacing; // 0x0018
	int32 m_nx; // 0x001C
	int32 m_ny; // 0x0020
	int32 m_nz; // 0x0024
	CUtlVector< CSteamAudioProbeLineSegment > m_vecLineSegments; // 0x0028
	CUtlVector< Vector > m_vecProbes; // 0x0040
};
class RnCompound_t // physicslib
{
	CUtlVector< RnSphere_t > m_Spheres; // 0x0000
	CUtlVector< RnCapsule_t > m_Capsules; // 0x0018
	CUtlVector< RnHull_t > m_Hulls; // 0x0030
	CUtlVector< RnMesh_t > m_Meshes; // 0x0048
	AABB_t m_Bounds; // 0x0060
	Vector m_vOrthographicAreas; // 0x0078
	float32 m_flSurfaceArea; // 0x0084
	float32 m_flVolume; // 0x0088
};
class CNmControlParameterFloatNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
};
class CFollowAttachmentUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	FollowAttachmentSettings_t m_opFixedData; // 0x0070
};
class COrientConstraint : public CBaseConstraint // modellib
{
};
class CAnimMotorUpdaterBase // animgraphlib
{
	CUtlString m_name; // 0x0010
	bool m_bDefault; // 0x0018
};
class CMarkupSearchHelper // server
{
	NavHull_t m_navHull; // 0x0000
	CUtlString m_tagString; // 0x0008
	CUtlString m_nameString; // 0x0010
	VectorWS m_vRefPos; // 0x0018
	bool m_bRefPosSet; // 0x0024
	bool m_bUseStepHeight; // 0x0025
	bool m_bActive; // 0x0026
};
class C_OP_RandomForce : public CParticleFunctionForce // particles
{
	Vector m_MinForce; // 0x01E8
	Vector m_MaxForce; // 0x01F4
};
class BakedLightingInfo_t::BakedShadowAssignment_t // worldrenderer
{
	uint32 m_nLightHash; // 0x0000
	uint32 m_nMapHash; // 0x0004
	int8 m_nShadowChannel; // 0x0008
};
class CSteamAudioBakedPathingData // steamaudio
{
	int32 m_nBands; // 0x0000
	CSteamAudioProbeData m_probes; // 0x0008
	CSteamAudioMovableBakedData< CSteamAudioBakedPathingData > m_movables; // 0x0010
};
class RnSoftbodyParticle_t // physicslib
{
	float32 m_flMassInv; // 0x0000
};
class CTiltTwistConstraint : public CBaseConstraint // modellib
{
	int32 m_nTargetAxis; // 0x0060
	int32 m_nSlaveAxis; // 0x0064
};
class EventServerEndAsyncPostTickWork_t // engine2
{
};
class CParticleFunctionOperator : public CParticleFunction // particles
{
};
class C_OP_ShapeMatchingConstraint : public CParticleFunctionConstraint // particles
{
	float32 m_flShapeRestorationTime; // 0x01D8
};
class SteamAudioReverbClusteringSettings_t // steamaudio
{
	bool m_bEnableClustering; // 0x0000
	int32 m_nCubeMapResolution; // 0x0004
	float32 m_flDepthThreshold; // 0x0008
};
class CVMixEQ8ProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixEQ8Desc_t m_desc; // 0x0020
};
class CVoiceContainerSelector : public CVoiceContainerBase // soundsystem_voicecontainers
{
	PlayBackMode_t m_mode; // 0x0070
	CSoundContainerReferenceArray m_soundsToPlay; // 0x0078
	CUtlVector< float32 > m_fProbabilityWeights; // 0x00B0
};
class FeCollisionPlane_t // physicslib
{
	uint16 nCtrlParent; // 0x0000
	uint16 nChildNode; // 0x0002
	RnPlane_t m_Plane; // 0x0004
	float32 flStrength; // 0x0014
};
class SelectorInstanceData_t // animgraphlib
{
	CRelativeArray< float32 > m_weights; // 0x0000
	CAnimNetVar< float32 > m_currentIndexStartTime; // 0x0008
	int32 m_currentIndex; // 0x0014
	int32 m_previousIndex; // 0x0018
};
class SkeletonAnimCapture_t::Camera_t // modellib
{
	CTransform m_tmCamera; // 0x0000
	float32 m_flTime; // 0x0020
};
class CSeqScaleSet // animationsystem
{
	CBufferString m_sName; // 0x0000
	bool m_bRootOffset; // 0x0010
	Vector m_vRootOffset; // 0x0014
	CUtlVector< int16 > m_nLocalBoneArray; // 0x0020
	CUtlVector< float32 > m_flBoneScaleArray; // 0x0038
};
class FuseVariableIndex_t // mathlib_extended
{
	uint16 m_Value; // 0x0000
};
class C_INIT_RtEnvCull : public CParticleFunctionInitializer // particles
{
	Vector m_vecTestDir; // 0x01E0
	Vector m_vecTestNormal; // 0x01EC
	bool m_bUseVelocity; // 0x01F8
	bool m_bCullOnMiss; // 0x01F9
	bool m_bLifeAdjust; // 0x01FA
	char[128] m_RtEnvName; // 0x01FB
	int32 m_nRTEnvCP; // 0x027C
	int32 m_nComponent; // 0x0280
};
class C_OP_Orient2DRelToCP : public CParticleFunctionOperator // particles
{
	float32 m_flRotOffset; // 0x01D8
	float32 m_flSpinStrength; // 0x01DC
	int32 m_nCP; // 0x01E0
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E4
};
class RTProxyInstanceInfo_t // worldrenderer
{
	RTProxyInstanceFlags_t m_nFlags; // 0x0000
	VertexAlbedoFormat_t m_albedoFormat; // 0x0001
	VertexAlbedoFormat_t m_emissiveFormat; // 0x0002
	uint16 m_nBLASCount; // 0x0004
	uint32 m_nBLASIndex; // 0x0008
	uint32 m_nVertexAlbedoByteOffset; // 0x000C
	uint32 m_nVertexEmissiveByteOffset; // 0x0010
	float32 m_fEmissiveFactor; // 0x0014
	matrix3x4_t m_mWorldFromLocal; // 0x0018
};
class CShatterGlassShard // server
{
	uint32 m_hShardHandle; // 0x0008
	CUtlVector< Vector2D > m_vecPanelVertices; // 0x0010
	Vector2D m_vLocalPanelSpaceOrigin; // 0x0028
	CStrongHandle< InfoForResourceTypeCModel > m_hModel; // 0x0030
	CHandle< CShatterGlassShardPhysics > m_hPhysicsEntity; // 0x0038
	CHandle< CFuncShatterglass > m_hParentPanel; // 0x003C
	uint32 m_hParentShard; // 0x0040
	ShatterGlassStressType m_ShatterStressType; // 0x0044
	Vector m_vecStressVelocity; // 0x0048
	bool m_bCreatedModel; // 0x0054
	float32 m_flLongestEdge; // 0x0058
	float32 m_flShortestEdge; // 0x005C
	float32 m_flLongestAcross; // 0x0060
	float32 m_flShortestAcross; // 0x0064
	float32 m_flSumOfAllEdges; // 0x0068
	float32 m_flArea; // 0x006C
	OnFrame m_nOnFrameEdge; // 0x0070
	int32 m_nSubShardGeneration; // 0x0074
	Vector2D m_vecAverageVertPosition; // 0x0078
	bool m_bAverageVertPositionIsValid; // 0x0080
	Vector2D m_vecPanelSpaceStressPositionA; // 0x0084
	Vector2D m_vecPanelSpaceStressPositionB; // 0x008C
	bool m_bStressPositionAIsValid; // 0x0094
	bool m_bStressPositionBIsValid; // 0x0095
	bool m_bFlaggedForRemoval; // 0x0096
	GameTime_t m_flPhysicsEntitySpawnedAtTime; // 0x0098
	CHandle< CBaseEntity > m_hEntityHittingMe; // 0x009C
	CUtlVector< uint32 > m_vecNeighbors; // 0x00A0
};
class sndopvarlatchdata_t // server
{
	CUtlSymbolLarge m_iszStack; // 0x0008
	CUtlSymbolLarge m_iszOperator; // 0x0010
	CUtlSymbolLarge m_iszOpvar; // 0x0018
	float32 m_flVal; // 0x0020
	VectorWS m_vPos; // 0x0024
};
class CNavPathCost : public INavPathCost // navlib
{
	bool m_bAllowLadders; // 0x0010
	bool m_bCanFly; // 0x0011
	bool m_bCanSwim; // 0x0012
	float32 m_flWaterToGroundMaxHeight; // 0x0014
	float32 m_flGroundToWaterMaxHeight; // 0x0018
	float32 m_flGroundToWaterTransitionDistance; // 0x001C
	float32 m_flWaterToGroundTransitionDistance; // 0x0020
	float32 m_flFlyingTransitionTolerance; // 0x0024
	bool m_bOptimizeFlySpacePathfinds; // 0x0028
	bool m_bStringPullFlySpacePathfinds; // 0x0029
	bool m_bSupportsTransitions; // 0x002A
	float32 m_flTransitionPenalty; // 0x002C
};
class C_OP_TeleportBeam : public CParticleFunctionOperator // particles
{
	int32 m_nCPPosition; // 0x01D8
	int32 m_nCPVelocity; // 0x01DC
	int32 m_nCPMisc; // 0x01E0
	int32 m_nCPColor; // 0x01E4
	int32 m_nCPInvalidColor; // 0x01E8
	int32 m_nCPExtraArcData; // 0x01EC
	Vector m_vGravity; // 0x01F0
	float32 m_flArcMaxDuration; // 0x01FC
	float32 m_flSegmentBreak; // 0x0200
	float32 m_flArcSpeed; // 0x0204
	float32 m_flAlpha; // 0x0208
};
class C_OP_PercentageBetweenTransforms : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	float32 m_flInputMin; // 0x01DC
	float32 m_flInputMax; // 0x01E0
	float32 m_flOutputMin; // 0x01E4
	float32 m_flOutputMax; // 0x01E8
	CParticleTransformInput m_TransformStart; // 0x01F0
	CParticleTransformInput m_TransformEnd; // 0x0258
	ParticleSetMethod_t m_nSetMethod; // 0x02C0
	bool m_bActiveRange; // 0x02C4
	bool m_bRadialCheck; // 0x02C5
};
class CVMixInputBase // soundsystem_lowlevel
{
	CUtlString m_name; // 0x0000
};
class SndBeatEventKeyedSndEvts_t : public SndBeatEventKeys_t // soundsystem
{
	CUtlString m_strSoundEventName; // 0x0010
};
class AnimNodeID // modellib
{
	uint32 m_id; // 0x0000
};
class CRenderGroom // modellib
{
	CUtlVector< RenderHairStrandInfo_t > m_hairs; // 0x0000
	CUtlVector< uint32 > m_hairPositionOffsets; // 0x0018
	CStrongHandleCopyable< InfoForResourceTypeIMaterial2 > m_hSimParamsMat; // 0x0040
	CUtlVector< int32 > m_strandSegmentCountHist; // 0x0048
	int32 m_nMaxSegmentsPerHairStrand; // 0x0078
	int32 m_nGuideHairCount; // 0x007C
	int32 m_nHairCount; // 0x0080
	int32 m_nTotalVertexCount; // 0x0084
	int32 m_nTotalSegmentCount; // 0x0088
	int32 m_nGroomGroupID; // 0x008C
	int32 m_nAttachBoneIdx; // 0x0090
	int32 m_nAttachMeshIdx; // 0x0094
	int32 m_nAttachMeshDrawCallIdx; // 0x0098
	bool m_bEnableSimulation; // 0x00AC
};
class MaterialParamTexture_t : public MaterialParam_t // materialsystem2
{
	CStrongHandle< InfoForResourceTypeCTextureBase > m_pValue; // 0x0008
};
class CRemapFloat // server
{
	float32[4] m_pValue; // 0x0000
};
class C_INIT_SetRigidAttachment : public CParticleFunctionInitializer // particles
{
	int32 m_nControlPointNumber; // 0x01E0
	ParticleAttributeIndex_t m_nFieldInput; // 0x01E4
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E8
	bool m_bLocalSpace; // 0x01EC
};
class VMixDynamicsCompressorDesc_t // soundsystem_lowlevel
{
	float32 m_fldbOutputGain; // 0x0000
	float32 m_fldbCompressionThreshold; // 0x0004
	float32 m_fldbKneeWidth; // 0x0008
	float32 m_flCompressionRatio; // 0x000C
	float32 m_flAttackTimeMS; // 0x0010
	float32 m_flReleaseTimeMS; // 0x0014
	float32 m_flRMSTimeMS; // 0x0018
	float32 m_flWetMix; // 0x001C
	bool m_bPeakMode; // 0x0020
};
class CMaterialDrawDescriptor::RigidMeshPart_t // modellib
{
	uint16 m_nRigidBLASIndex; // 0x0000
	int16 m_nBoneIndex; // 0x0002
	uint32 m_nStartIndexOffset; // 0x0004
	uint32 m_nPrimitiveCount; // 0x0008
};
class EventServerBeginAsyncPostTickWork_t // engine2
{
	bool m_bIsOncePerFrameAsyncWorkPhase; // 0x0000
};
class AI_BaseNPC_DebugSnapshotData_t : public DebugSnapshotBaseStructuredData_t // server
{
	CGlobalSymbol npc_state; // 0x0008
	CHandle< CBaseEntity > current_enemy; // 0x0010
	CUtlString s_current_schedule; // 0x0018
	CGlobalSymbol s_current_task; // 0x0020
	CUtlString s_prev_schedule; // 0x0028
	CUtlString s_npc_current_movement; // 0x0030
	CUtlString s_last_task_end_location; // 0x0038
	CUtlVector< CGlobalSymbol > conditions; // 0x0040
	CUtlVector< CGlobalSymbol > anim_events; // 0x0058
	AI_BaseNPCAnimGraph_DebugSnapshotData_t animgraph; // 0x0070
	AI_Navigator_DebugSnapshotData_t navigator; // 0x00B0
	AI_MotorServices_DebugSnapshotData_t motorServices; // 0x0100
	AI_FacingServices_DebugSnapshotData_t facingServices; // 0x0130
};
class AI_Navigator_DebugSnapshotData_t // server
{
	CGlobalSymbol s_movement_id; // 0x0000
	uint32 s_movement_serial_number; // 0x0008
	CUtlString s_goal_source_location; // 0x0010
	VectorWS last_waypoint_pos; // 0x0018
	VectorWS goal_location; // 0x0024
	CUtlVector< AI_Navigator_DebugSnapshotData_t::Waypoint_t > waypoints; // 0x0030
	CGlobalSymbol s_arrival_movement_gait_set; // 0x0048
};
class AI_GroundRootMotionMotor_DebugSnapshotData_t::Event_t // server
{
	CUtlString description; // 0x0000
	VectorWS location; // 0x0008
};
class DecalGroupOption_t // server
{
	CStrongHandleCopyable< InfoForResourceTypeIMaterial2 > m_hMaterial; // 0x0000
	CGlobalSymbol m_sSequenceName; // 0x0008
	float32 m_flProbability; // 0x0010
	bool m_bEnableAngleBetweenNormalAndGravityRange; // 0x0014
	float32 m_flMinAngleBetweenNormalAndGravity; // 0x0018
	float32 m_flMaxAngleBetweenNormalAndGravity; // 0x001C
};
class C_OP_SetToCP : public CParticleFunctionOperator // particles
{
	int32 m_nControlPointNumber; // 0x01D8
	Vector m_vecOffset; // 0x01DC
	bool m_bOffsetLocal; // 0x01E8
};
class FeBuildSphereRigid_t : public FeSphereRigid_t // physicslib
{
	int32 m_nPriority; // 0x0020
	uint32 m_nVertexMapHash; // 0x0024
	uint32 m_nAntitunnelGroupBits; // 0x0028
};
class CDirectPlaybackTagData // animgraphlib
{
	CUtlString m_sequenceName; // 0x0000
	CUtlVector< TagSpan_t > m_tags; // 0x0008
};
class PermModelData_t // modellib
{
	CUtlString m_name; // 0x0000
	PermModelInfo_t m_modelInfo; // 0x0008
	CUtlVector< PermModelExtPart_t > m_ExtParts; // 0x0060
	CUtlVector< CStrongHandle< InfoForResourceTypeCRenderMesh > > m_refMeshes; // 0x0078
	CUtlVector< uint64 > m_refMeshGroupMasks; // 0x0090
	CUtlVector< uint64 > m_refPhysGroupMasks; // 0x00A8
	CUtlVector< uint8 > m_refLODGroupMasks; // 0x00C0
	CUtlVector< float32 > m_lodGroupSwitchDistances; // 0x00D8
	CUtlVector< CStrongHandle< InfoForResourceTypeCPhysAggregateData > > m_refPhysicsData; // 0x00F0
	CUtlVector< CStrongHandle< InfoForResourceTypeCPhysAggregateData > > m_refPhysicsHitboxData; // 0x0108
	CUtlVector< CStrongHandle< InfoForResourceTypeCAnimationGroup > > m_refAnimGroups; // 0x0120
	CUtlVector< CStrongHandle< InfoForResourceTypeCSequenceGroupData > > m_refSequenceGroups; // 0x0138
	CUtlVector< CUtlString > m_meshGroups; // 0x0150
	CUtlVector< MaterialGroup_t > m_materialGroups; // 0x0168
	uint64 m_nDefaultMeshGroupMask; // 0x0180
	ModelSkeletonData_t m_modelSkeleton; // 0x0188
	CUtlVector< int16 > m_remappingTable; // 0x0230
	CUtlVector< uint16 > m_remappingTableStarts; // 0x0248
	CUtlVector< ModelBoneFlexDriver_t > m_boneFlexDrivers; // 0x0260
	CModelConfigList* m_pModelConfigList; // 0x0278
	CUtlVector< CUtlString > m_BodyGroupsHiddenInTools; // 0x0280
	CUtlVector< CStrongHandle< InfoForResourceTypeCModel > > m_refAnimIncludeModels; // 0x0298
	CUtlVector< PermModelDataAnimatedMaterialAttribute_t > m_AnimatedMaterialAttributes; // 0x02B0
	CUtlVector< ModelAnimGraph2Ref_t > m_animGraph2Refs; // 0x02C8
	CUtlVector< CStrongHandle< InfoForResourceTypeCNmSkeleton > > m_vecNmSkeletonRefs; // 0x02E0
};
class CNmOverlayBlendTask : public CNmBlendTaskBase // animlib
{
};
class SPAWNGROUP_HEADER // server
{
	CUtlString m_sGroupName; // 0x0000
	CUtlString m_sEntityLumpName; // 0x0008
	matrix3x4a_t m_vecWorldOffset; // 0x0010
	bool m_bClientSpawnGroup; // 0x0040
	bool m_bSuppressAllEntities; // 0x0041
};
class C_OP_RemapCrossProductOfTwoVectorsToVector : public CParticleFunctionOperator // particles
{
	CPerParticleVecInput m_InputVec1; // 0x01D8
	CPerParticleVecInput m_InputVec2; // 0x0890
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0F48
	bool m_bNormalize; // 0x0F4C
};
class C_OP_DensityForce : public CParticleFunctionForce // particles
{
	float32 m_flRadiusScale; // 0x01E8
	float32 m_flForceScale; // 0x01EC
	float32 m_flTargetDensity; // 0x01F0
};
class FeSimdRodConstraintAnim_t // physicslib
{
	uint16[4][2] nNode; // 0x0000
	fltx4 f4Weight0; // 0x0010
	fltx4 f4RelaxationFactor; // 0x0020
};
class CStanceScaleUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	CAnimParamHandle m_hParam; // 0x0070
};
class PulseDocNodeID_t // pulse_runtime_lib
{
	int32 m_Value; // 0x0000
};
class CNmModelSpaceBlendTask : public CNmBlendTaskBase // animlib
{
};
class CNetworkVarChainer // entity2
{
	ChangeAccessorFieldPathIndex_t m_PathIndex; // 0x0020
};
class CPhysicsBodyGameMarkupData // server
{
	CUtlDict< CPhysicsBodyGameMarkup > m_PhysicsBodyMarkupByBoneName; // 0x0000
};
class C_INIT_InitFromCPSnapshot : public CParticleFunctionInitializer // particles
{
	int32 m_nControlPointNumber; // 0x01E0
	CUtlString m_strSnapshotSubset; // 0x01E8
	ParticleAttributeIndex_t m_nAttributeToRead; // 0x01F0
	ParticleAttributeIndex_t m_nAttributeToWrite; // 0x01F4
	int32 m_nLocalSpaceCP; // 0x01F8
	bool m_bRandom; // 0x01FC
	bool m_bReverse; // 0x01FD
	CParticleCollectionFloatInput m_nSnapShotIncrement; // 0x0200
	CPerParticleFloatInput m_nManualSnapshotIndex; // 0x0370
	int32 m_nRandomSeed; // 0x04E0
	bool m_bLocalSpaceAngles; // 0x04E4
};
class AggregateVertexEmissiveStreamOnDiskData_t // worldrenderer
{
	CUtlBinaryBlock m_BufferData; // 0x0000
};
class VMixOscDesc_t // soundsystem_lowlevel
{
	VMixLFOShape_t oscType; // 0x0000
	float32 m_freq; // 0x0004
	float32 m_flPhase; // 0x0008
};
class FeVertexMapBuild_t // physicslib
{
	CUtlString m_VertexMapName; // 0x0000
	uint32 m_nNameHash; // 0x0008
	Color m_Color; // 0x000C
	float32 m_flVolumetricSolveStrength; // 0x0010
	int32 m_nScaleSourceNode; // 0x0014
	CUtlVector< float32 > m_Weights; // 0x0018
};
class RotatorQueueEntry_t // server
{
	Quaternion qTarget; // 0x0000
	RotatorTargetSpace_t eSpace; // 0x0010
};
class RotatorHistoryEntry_t // server
{
	Quaternion qInvChange; // 0x0000
	GameTime_t flTimeRotationStart; // 0x0010
};
class C_OP_RemapTransformVisibilityToScalar : public CParticleFunctionOperator // particles
{
	ParticleSetMethod_t m_nSetMethod; // 0x01D8
	CParticleTransformInput m_TransformInput; // 0x01E0
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0248
	float32 m_flInputMin; // 0x024C
	float32 m_flInputMax; // 0x0250
	float32 m_flOutputMin; // 0x0254
	float32 m_flOutputMax; // 0x0258
	float32 m_flRadius; // 0x025C
};
class C_OP_VectorNoise : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	Vector m_vecOutputMin; // 0x01DC
	Vector m_vecOutputMax; // 0x01E8
	float32 m_fl4NoiseScale; // 0x01F4
	bool m_bAdditive; // 0x01F8
	bool m_bOffset; // 0x01F9
	float32 m_flNoiseAnimationTimeScale; // 0x01FC
};
class CVMixCommand // soundsystem_lowlevel
{
	VMixGraphCommandID_t m_nCommand; // 0x0000
	uint32 m_nParameterNameHash; // 0x0004
	int32 m_nOutputSubmix; // 0x0008
	int32 m_nInputSubmix0; // 0x000C
	int32 m_nInputSubmix1; // 0x0010
	int32 m_nProcessor; // 0x0014
	int32 m_nInputValue0; // 0x0018
	int32 m_nInputValue1; // 0x001C
};
class FeDynKinLink_t // physicslib
{
	uint16 m_nParent; // 0x0000
	uint16 m_nChild; // 0x0002
};
class MotionSelection // animgraphlib
{
	NetVarConfigIndex m_nConfigIndex; // 0x0024
	CAnimNetVar< float32 > m_flCycleZeroTime; // 0x0030
	CAnimNetVar< float32 > m_flPlaybackSpeed; // 0x003C
	CAnimNetVar< float32 > m_flStartTime; // 0x0048
	int32 m_nSample; // 0x0054
};
class CInterpolatedValue // client
{
	float32 m_flStartTime; // 0x0000
	float32 m_flEndTime; // 0x0004
	float32 m_flStartValue; // 0x0008
	float32 m_flEndValue; // 0x000C
	int32 m_nInterpType; // 0x0010
};
class CGeneralSpin : public CParticleFunctionOperator // particles
{
	int32 m_nSpinRateDegrees; // 0x01D8
	int32 m_nSpinRateMinDegrees; // 0x01DC
	float32 m_fSpinRateStopTime; // 0x01E4
};
class AnimationDecodeDebugDumpElement_t // animationsystem
{
	int32 m_nEntityIndex; // 0x0000
	CUtlString m_modelName; // 0x0008
	CUtlVector< CUtlString > m_poseParams; // 0x0010
	CUtlVector< CUtlString > m_decodeOps; // 0x0028
	CUtlVector< CUtlString > m_internalOps; // 0x0040
	CUtlVector< CUtlString > m_decodedAnims; // 0x0058
};
class CPulse_Chunk // pulse_runtime_lib
{
	CUtlLeanVector< PGDInstruction_t > m_Instructions; // 0x0000
	CUtlLeanVector< CPulse_RegisterInfo > m_Registers; // 0x0010
	CUtlLeanVector< CPulse_InstructionDebug > m_InstructionDebugInfos; // 0x0020
};
class CNetworkOriginCellCoordQuantizedVector // server
{
	uint16 m_cellX; // 0x0010
	uint16 m_cellY; // 0x0012
	uint16 m_cellZ; // 0x0014
	uint16 m_nOutsideWorld; // 0x0016
	CNetworkedQuantizedFloat m_vecX; // 0x0018
	CNetworkedQuantizedFloat m_vecY; // 0x0020
	CNetworkedQuantizedFloat m_vecZ; // 0x0028
};
class C_OP_ModelDampenMovement : public CParticleFunctionOperator // particles
{
	int32 m_nControlPointNumber; // 0x01D8
	bool m_bBoundBox; // 0x01DC
	bool m_bOutside; // 0x01DD
	bool m_bUseBones; // 0x01DE
	char[128] m_HitboxSetName; // 0x01DF
	CPerParticleVecInput m_vecPosOffset; // 0x0260
	float32 m_fDrag; // 0x0918
};
class C_OP_SnapshotRigidSkinToBones : public CParticleFunctionOperator // particles
{
	bool m_bTransformNormals; // 0x01D8
	bool m_bTransformRadii; // 0x01D9
	int32 m_nControlPointNumber; // 0x01DC
};
class C_INIT_RandomYawFlip : public CParticleFunctionInitializer // particles
{
	float32 m_flPercent; // 0x01E0
};
class CAnimTagBase // animgraphlib
{
	CGlobalSymbol m_name; // 0x0018
	CUtlString m_sComment; // 0x0020
	CGlobalSymbol m_group; // 0x0028
	AnimTagID m_tagID; // 0x0030
	bool m_bIsReferenced; // 0x0048
};
class CMotionDataSet // animgraphlib
{
	CUtlVector< CMotionGraphGroup > m_groups; // 0x0000
	int32 m_nDimensionCount; // 0x0018
};
class CNmChainLookatTask : public CNmPoseTask // animlib
{
};
class CNmBodyGroupEvent : public CNmEvent // animlib
{
	CNmEventTargetEntity_t m_target; // 0x0018
	CUtlString m_groupName; // 0x0020
	int32 m_nGroupValue; // 0x0028
};
class EventPostAdvanceTick_t : public EventSimulate_t // engine2
{
	int32 m_nCurrentTick; // 0x0030
	int32 m_nCurrentTickThisFrame; // 0x0034
	int32 m_nTotalTicksThisFrame; // 0x0038
	int32 m_nTotalTicks; // 0x003C
};
class CSimTimer : public CSimpleSimTimer // server
{
	float32 m_flInterval; // 0x0008
};
class C_OP_InterpolateRadius : public CParticleFunctionOperator // particles
{
	float32 m_flStartTime; // 0x01D8
	float32 m_flEndTime; // 0x01DC
	float32 m_flStartScale; // 0x01E0
	float32 m_flEndScale; // 0x01E4
	bool m_bEaseInAndOut; // 0x01E8
	float32 m_flBias; // 0x01EC
};
class C_OP_ReadFromNeighboringParticle : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldInput; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
	int32 m_nIncrement; // 0x01E0
	CPerParticleFloatInput m_DistanceCheck; // 0x01E8
	CPerParticleFloatInput m_flInterpolation; // 0x0358
};
class C_OP_SetControlPointToHMD : public CParticleFunctionPreEmission // particles
{
	int32 m_nCP1; // 0x01E0
	Vector m_vecCP1Pos; // 0x01E4
	bool m_bOrientToHMD; // 0x01F0
};
class IKDemoCaptureSettings_t // animgraphlib
{
	CUtlString m_parentBoneName; // 0x0000
	IKChannelMode m_eMode; // 0x0008
	CUtlString m_ikChainName; // 0x0010
	CUtlString m_oneBoneStart; // 0x0018
	CUtlString m_oneBoneEnd; // 0x0020
};
class CParticleTransformInput : public CParticleInput // particleslib
{
	ParticleTransformType_t m_nType; // 0x0010
	CParticleNamedValueRef m_NamedValue; // 0x0018
	bool m_bFollowNamedValue; // 0x0058
	bool m_bSupportsDisabled; // 0x0059
	bool m_bUseOrientation; // 0x005A
	int32 m_nControlPoint; // 0x005C
	int32 m_nControlPointRangeMax; // 0x0060
	float32 m_flEndCPGrowthTime; // 0x0064
};
class CFloatAnimParameter : public CConcreteAnimParameter // animgraphlib
{
	float32 m_fDefaultValue; // 0x0080
	float32 m_fMinValue; // 0x0084
	float32 m_fMaxValue; // 0x0088
	bool m_bInterpolate; // 0x008C
};
class CTestPulseIOComponent // server
{
	CUtlString m_ComponentData; // 0x0008
	CEntityOutputTemplate< CUtlSymbolLarge > m_OnComponentTestFunc; // 0x0010
};
class C_OP_RemapAverageHitboxSpeedtoCP : public CParticleFunctionPreEmission // particles
{
	int32 m_nInControlPointNumber; // 0x01E0
	int32 m_nOutControlPointNumber; // 0x01E4
	int32 m_nField; // 0x01E8
	ParticleHitboxDataSelection_t m_nHitboxDataType; // 0x01EC
	CParticleCollectionFloatInput m_flInputMin; // 0x01F0
	CParticleCollectionFloatInput m_flInputMax; // 0x0360
	CParticleCollectionFloatInput m_flOutputMin; // 0x04D0
	CParticleCollectionFloatInput m_flOutputMax; // 0x0640
	int32 m_nHeightControlPointNumber; // 0x07B0
	CParticleCollectionVecInput m_vecComparisonVelocity; // 0x07B8
	char[128] m_HitboxSetName; // 0x0E70
};
class C_INIT_SetFloatAttributeToVectorExpression : public CParticleFunctionInitializer // particles
{
	VectorFloatExpressionType_t m_nExpression; // 0x01E0
	CPerParticleVecInput m_vInput1; // 0x01E8
	CPerParticleVecInput m_vInput2; // 0x08A0
	CParticleRemapFloatInput m_flOutputRemap; // 0x0F58
	ParticleAttributeIndex_t m_nOutputField; // 0x10C8
	ParticleSetMethod_t m_nSetMethod; // 0x10CC
};
class FeSimdTri_t // physicslib
{
	uint32[4][3] nNode; // 0x0000
	fltx4 w1; // 0x0030
	fltx4 w2; // 0x0040
	fltx4 v1x; // 0x0050
	FourVectors2D v2; // 0x0060
};
class CAimCameraUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	CAnimParamHandle m_hParameterPosition; // 0x0070
	CAnimParamHandle m_hParameterOrientation; // 0x0072
	CAnimParamHandle m_hParameterPelvisOffset; // 0x0074
	CAnimParamHandle m_hParameterCameraOnly; // 0x0076
	CAnimParamHandle m_hParameterWeaponDepenetrationDistance; // 0x0078
	CAnimParamHandle m_hParameterWeaponDepenetrationDelta; // 0x007A
	CAnimParamHandle m_hParameterCameraClearanceDistance; // 0x007C
	AimCameraOpFixedSettings_t m_opFixedSettings; // 0x0080
};
class CMorphData // modellib
{
	CUtlString m_name; // 0x0000
	CUtlVector< CMorphRectData > m_morphRectDatas; // 0x0008
};
class CDrawCullingData // modellib
{
	int8[3] m_ConeAxis; // 0x0000
	int8 m_ConeCutoff; // 0x0003
};
class CAnimationGraphVisualizerPrimitiveBase // animgraphlib
{
	CAnimationGraphVisualizerPrimitiveType m_Type; // 0x0008
	AnimNodeID[11] m_OwningAnimNodePaths; // 0x000C
	int32 m_nOwningAnimNodePathCount; // 0x0038
};
class CPhysSurfacePropertiesPhysics // modellib
{
	float32 m_friction; // 0x0000
	float32 m_elasticity; // 0x0004
	float32 m_density; // 0x0008
	float32 m_thickness; // 0x000C
	float32 m_softContactFrequency; // 0x0010
	float32 m_softContactDampingRatio; // 0x0014
};
class CBaseAnimGraphVariationUserData : public CNmGraphVariationUserData // server
{
};
class CVMixControlInputArray : public CVMixInputBase // soundsystem_lowlevel
{
	int32 m_nArrayIndex; // 0x0010
};
class CNmIDEventNode::CDefinition : public CNmIDValueNode::CDefinition // animlib
{
	int16 m_nSourceStateNodeIdx; // 0x0010
	CNmBitFlags m_eventConditionRules; // 0x0014
	CGlobalSymbol m_defaultValue; // 0x0018
};
class CSeqCmdSeqDesc // animationsystem
{
	CBufferString m_sName; // 0x0000
	CSeqSeqDescFlag m_flags; // 0x0010
	CSeqTransition m_transition; // 0x001C
	int16 m_nFrameRangeSequence; // 0x0024
	int16 m_nFrameCount; // 0x0026
	float32 m_flFPS; // 0x0028
	int16 m_nSubCycles; // 0x002C
	int16 m_numLocalResults; // 0x002E
	CUtlVector< CSeqCmdLayer > m_cmdLayerArray; // 0x0030
	CUtlVector< CAnimEventDefinition > m_eventArray; // 0x0048
	CUtlVector< CAnimActivity > m_activityArray; // 0x0060
	CUtlVector< CSeqPoseSetting > m_poseSettingArray; // 0x0078
};
class EventFrameBoundary_t // engine2
{
	float32 m_flFrameTime; // 0x0000
};
class CResponseQueue // server
{
	CUtlVector< CAI_Expresser* > m_ExpresserTargets; // 0x0038
};
class ParticleIndex_t // server
{
	int32 m_Value; // 0x0000
};
class C_OP_ConstrainDistanceToPath : public CParticleFunctionConstraint // particles
{
	float32 m_fMinDistance; // 0x01D8
	float32 m_flMaxDistance0; // 0x01DC
	float32 m_flMaxDistanceMid; // 0x01E0
	float32 m_flMaxDistance1; // 0x01E4
	CPathParameters m_PathParameters; // 0x01F0
	float32 m_flTravelTime; // 0x0230
	ParticleAttributeIndex_t m_nFieldScale; // 0x0234
	ParticleAttributeIndex_t m_nManualTField; // 0x0238
};
class C_OP_DecayClampCount : public CParticleFunctionOperator // particles
{
	CParticleCollectionFloatInput m_nCount; // 0x01D8
};
class C_INIT_RandomAlphaWindowThreshold : public CParticleFunctionInitializer // particles
{
	float32 m_flMin; // 0x01E0
	float32 m_flMax; // 0x01E4
	float32 m_flExponent; // 0x01E8
};
class C_OP_RemapNamedModelElementEndCap : public CParticleFunctionOperator // particles
{
	CStrongHandle< InfoForResourceTypeCModel > m_hModel; // 0x01D8
	CUtlVector< CUtlString > m_inNames; // 0x01E0
	CUtlVector< CUtlString > m_outNames; // 0x01F8
	CUtlVector< CUtlString > m_fallbackNames; // 0x0210
	bool m_bModelFromRenderer; // 0x0228
	ParticleAttributeIndex_t m_nFieldInput; // 0x022C
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0230
};
class ClutterSceneObject_t // worldrenderer
{
	AABB_t m_Bounds; // 0x0000
	ObjectTypeFlags_t m_flags; // 0x0018
	int16 m_nLayer; // 0x001C
	CUtlVector< Vector > m_instancePositions; // 0x0020
	CUtlVector< float32 > m_instanceScales; // 0x0050
	CUtlVector< Color > m_instanceTintSrgb; // 0x0068
	CUtlVector< ClutterTile_t > m_tiles; // 0x0080
	CStrongHandle< InfoForResourceTypeCModel > m_renderableModel; // 0x0098
	CUtlStringToken m_materialGroup; // 0x00A0
	float32 m_flBeginCullSize; // 0x00A4
	float32 m_flEndCullSize; // 0x00A8
};
class WorldNode_t // worldrenderer
{
	CUtlVector< SceneObject_t > m_sceneObjects; // 0x0000
	CUtlVector< uint16 > m_visClusterMembership; // 0x0018
	CUtlVector< AggregateSceneObject_t > m_aggregateSceneObjects; // 0x0030
	CUtlVector< ClutterSceneObject_t > m_clutterSceneObjects; // 0x0048
	CUtlVector< AggregateRTProxySceneObject_t > m_rtProxies; // 0x0060
	CUtlVector< ExtraVertexStreamOverride_t > m_extraVertexStreamOverrides; // 0x0078
	CUtlVector< MaterialOverride_t > m_materialOverrides; // 0x0090
	CUtlVector< WorldNodeOnDiskBufferData_t > m_extraVertexStreams; // 0x00A8
	CUtlVector< AggregateInstanceStreamOnDiskData_t > m_aggregateInstanceStreams; // 0x00C0
	CUtlVector< AggregateVertexAlbedoStreamOnDiskData_t > m_vertexAlbedoStreams; // 0x00D8
	CUtlVector< AggregateVertexEmissiveStreamOnDiskData_t > m_vertexEmissiveStreams; // 0x00F0
	CUtlVector< CUtlString > m_layerNames; // 0x0108
	CUtlVector< uint8 > m_sceneObjectLayerIndices; // 0x0120
	CUtlString m_grassFileName; // 0x0138
	BakedLightingInfo_t m_nodeLightingInfo; // 0x0140
	bool m_bHasBakedGeometryFlag; // 0x0188
};
class CSndSeqInstMidiSampler : public CSndSeqInstBaseSchema // soundsystem
{
	bool m_bIsSoundEvent; // 0x0020
	bool m_bStopPrevious; // 0x0021
	uint8 m_nMinNote; // 0x0022
	uint8 m_nMaxNote; // 0x0023
	float32 m_flMinVelocityAtten; // 0x0024
	float32 m_flMaxVelocityAtten; // 0x0028
	float32 m_flAttack; // 0x002C
	float32 m_flRelease; // 0x0030
	bool m_bBeatEnvelopes; // 0x0034
	uint8 m_nNextVoiceSlot; // 0x00D4
	uint32 m_hSoundEventHash; // 0x00D8
};
class CNmCurrentSyncEventNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	int16 m_nSourceStateNodeIdx; // 0x0010
	CNmCurrentSyncEventNode::InfoType_t m_infoType; // 0x0012
};
class C_OP_DecayMaintainCount : public CParticleFunctionOperator // particles
{
	int32 m_nParticlesToMaintain; // 0x01D8
	float32 m_flDecayDelay; // 0x01DC
	int32 m_nSnapshotControlPoint; // 0x01E0
	CUtlString m_strSnapshotSubset; // 0x01E8
	bool m_bLifespanDecay; // 0x01F0
	CParticleCollectionFloatInput m_flScale; // 0x01F8
	bool m_bKillNewest; // 0x0368
};
class IPhysicsPlayerController // vphysics2
{
};
class CAnimCycle : public CCycleBase // modellib
{
};
class ModelAnimGraph2Ref_t // modellib
{
	CUtlString m_sIdentifier; // 0x0000
	CStrongHandle< InfoForResourceTypeCNmGraphDefinition > m_hGraph; // 0x0008
};
class AABBWS_t // mathlib_extended
{
	VectorWS m_vMinBounds; // 0x0000
	VectorWS m_vMaxBounds; // 0x000C
};
class C_INIT_RandomNamedModelSequence : public C_INIT_RandomNamedModelElement // particles
{
};
class C_OP_PlayEndCapWhenFinished : public CParticleFunctionPreEmission // particles
{
	bool m_bFireOnEmissionEnd; // 0x01E0
	bool m_bIncludeChildren; // 0x01E1
};
class C_INIT_RandomSecondSequence : public CParticleFunctionInitializer // particles
{
	int32 m_nSequenceMin; // 0x01E0
	int32 m_nSequenceMax; // 0x01E4
};
class C_OP_LagCompensation : public CParticleFunctionOperator // particles
{
	int32 m_nDesiredVelocityCP; // 0x01D8
	int32 m_nLatencyCP; // 0x01DC
	int32 m_nLatencyCPField; // 0x01E0
	int32 m_nDesiredVelocityCPField; // 0x01E4
};
class CParticleRemapFloatInput : public CParticleFloatInput // particleslib
{
};
class CLODComponentUpdater : public CAnimComponentUpdater // animgraphlib
{
	int32 m_nServerLOD; // 0x0030
};
class PulseRuntimeCallInfoIndex_t // pulse_runtime_lib
{
	int32 m_Value; // 0x0000
};
class inv_image_clearcolor_t // client
{
	Vector color; // 0x0000
};
class C_INIT_CreateOnModelAtHeight : public CParticleFunctionInitializer // particles
{
	bool m_bUseBones; // 0x01E0
	bool m_bForceZ; // 0x01E1
	int32 m_nControlPointNumber; // 0x01E4
	int32 m_nHeightCP; // 0x01E8
	bool m_bUseWaterHeight; // 0x01EC
	CParticleCollectionFloatInput m_flDesiredHeight; // 0x01F0
	CParticleCollectionVecInput m_vecHitBoxScale; // 0x0360
	CParticleCollectionVecInput m_vecDirectionBias; // 0x0A18
	ParticleHitboxBiasType_t m_nBiasType; // 0x10D0
	bool m_bLocalCoords; // 0x10D4
	bool m_bPreferMovingBoxes; // 0x10D5
	char[128] m_HitboxSetName; // 0x10D6
	CParticleCollectionFloatInput m_flHitboxVelocityScale; // 0x1158
	CParticleCollectionFloatInput m_flMaxBoneVelocity; // 0x12C8
};
class CNmIDSwitchNode::CDefinition : public CNmIDValueNode::CDefinition // animlib
{
	int16 m_nSwitchValueNodeIdx; // 0x0010
	int16 m_nTrueValueNodeIdx; // 0x0012
	int16 m_nFalseValueNodeIdx; // 0x0014
	CGlobalSymbol m_falseValue; // 0x0018
	CGlobalSymbol m_trueValue; // 0x0020
};
class ConstantInfo_t // mathlib_extended
{
	CUtlString m_name; // 0x0000
	CUtlStringToken m_nameToken; // 0x0008
	float32 m_flValue; // 0x000C
};
class C_INIT_MoveBetweenPoints : public CParticleFunctionInitializer // particles
{
	CPerParticleFloatInput m_flSpeedMin; // 0x01E0
	CPerParticleFloatInput m_flSpeedMax; // 0x0350
	CPerParticleFloatInput m_flEndSpread; // 0x04C0
	CPerParticleFloatInput m_flStartOffset; // 0x0630
	CPerParticleFloatInput m_flEndOffset; // 0x07A0
	int32 m_nEndControlPointNumber; // 0x0910
	bool m_bTrailBias; // 0x0914
};
class C_INIT_RandomNamedModelElement : public CParticleFunctionInitializer // particles
{
	CStrongHandle< InfoForResourceTypeCModel > m_hModel; // 0x01E0
	CUtlVector< CUtlString > m_names; // 0x01E8
	bool m_bShuffle; // 0x0200
	bool m_bLinear; // 0x0201
	bool m_bModelFromRenderer; // 0x0202
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0204
};
class C_INIT_SetHitboxToModel : public CParticleFunctionInitializer // particles
{
	int32 m_nControlPointNumber; // 0x01E0
	int32 m_nForceInModel; // 0x01E4
	bool m_bEvenDistribution; // 0x01E8
	int32 m_nDesiredHitbox; // 0x01EC
	CParticleCollectionVecInput m_vecHitBoxScale; // 0x01F0
	Vector m_vecDirectionBias; // 0x08A8
	bool m_bMaintainHitbox; // 0x08B4
	bool m_bUseBones; // 0x08B5
	char[128] m_HitboxSetName; // 0x08B6
	CParticleCollectionFloatInput m_flShellSize; // 0x0938
};
class CAnimGraphControllerManager // server
{
	CUtlVector< CAnimGraphControllerBase* > m_controllers; // 0x0000
	bool m_bGraphBindingsCreated; // 0x0090
};
class CVsndTriggerSlot // soundsystem_voicecontainers
{
	bool m_bEnableVsnd; // 0x0000
	CSoundContainerReference m_vsnd; // 0x0008
	bool m_bEnableEndcap; // 0x0028
	CSoundContainerReference m_endcapVsnd; // 0x0030
	bool m_bEnableLoopcap; // 0x0050
	CSoundContainerReference m_loopcapVsnd; // 0x0058
	float32 m_volume; // 0x0078
	float32 m_fadeOut; // 0x007C
	EVsndTriggerMode m_mode; // 0x0080
};
class CMotionGraph // animgraphlib
{
	CParamSpanUpdater m_paramSpans; // 0x0010
	CUtlVector< TagSpan_t > m_tags; // 0x0028
	CSmartPtr< CMotionNode > m_pRootNode; // 0x0040
	int32 m_nParameterCount; // 0x0048
	int32 m_nConfigStartIndex; // 0x004C
	int32 m_nConfigCount; // 0x0050
	bool m_bLoop; // 0x0054
};
class CSequenceTagSpans // animgraphlib
{
	CGlobalSymbol m_sSequenceName; // 0x0000
	CUtlVector< TagSpan_t > m_tags; // 0x0008
};
class C_OP_DistanceBetweenCPsToCP : public CParticleFunctionPreEmission // particles
{
	int32 m_nStartCP; // 0x01E0
	int32 m_nEndCP; // 0x01E4
	int32 m_nOutputCP; // 0x01E8
	int32 m_nOutputCPField; // 0x01EC
	bool m_bSetOnce; // 0x01F0
	float32 m_flInputMin; // 0x01F4
	float32 m_flInputMax; // 0x01F8
	float32 m_flOutputMin; // 0x01FC
	float32 m_flOutputMax; // 0x0200
	float32 m_flMaxTraceLength; // 0x0204
	float32 m_flLOSScale; // 0x0208
	bool m_bLOS; // 0x020C
	char[128] m_CollisionGroupName; // 0x020D
	ParticleTraceSet_t m_nTraceSet; // 0x0290
	ParticleParentSetMode_t m_nSetParent; // 0x0294
};
class C_INIT_RandomRotation : public CGeneralRandomRotation // particles
{
};
class BakedLightingInfo_t // worldrenderer
{
	uint32 m_nLightmapVersionNumber; // 0x0000
	uint32 m_nLightmapGameVersionNumber; // 0x0004
	Vector2D m_vLightmapUvScale; // 0x0008
	bool m_bHasLightmaps; // 0x0010
	bool m_bBakedShadowsGamma20; // 0x0011
	bool m_bCompressionEnabled; // 0x0012
	bool m_bSHLightmaps; // 0x0013
	uint8 m_nChartPackIterations; // 0x0014
	uint8 m_nVradQuality; // 0x0015
	CUtlVector< CStrongHandle< InfoForResourceTypeCTextureBase > > m_lightMaps; // 0x0018
	CUtlVector< BakedLightingInfo_t::BakedShadowAssignment_t > m_bakedShadows; // 0x0030
};
class KeyGroup_t // soundsystem
{
	uint8 nCenterNote; // 0x0000
	uint8 nMinNote; // 0x0001
	uint8 nMaxNote; // 0x0002
	uint8 nNumVelocityZones; // 0x0003
	VelocityZone_t* pVelocityZones; // 0x0008
};
class TargetSelectorInstanceData_t // animgraphlib
{
	CAnimNetVar< int32 > m_currentIndex; // 0x0000
	CAnimNetVar< Vector > m_vMSRootMotionAnlyzerTarget; // 0x001C
};
class CNmIDEvent : public CNmEvent // animlib
{
	CGlobalSymbol m_ID; // 0x0018
	CGlobalSymbol m_secondaryID; // 0x0020
};
class C_OP_RemapDistanceToLineSegmentToScalar : public C_OP_RemapDistanceToLineSegmentBase // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01F0
	float32 m_flMinOutputValue; // 0x01F4
	float32 m_flMaxOutputValue; // 0x01F8
};
class CAnimReplayFrame // animgraphlib
{
	CUtlVector< CUtlBinaryBlock > m_inputDataBlocks; // 0x0010
	CUtlBinaryBlock m_instanceData; // 0x0028
	CTransform m_startingLocalToWorldTransform; // 0x0040
	CTransform m_localToWorldTransform; // 0x0060
	float32 m_timeStamp; // 0x0080
};
class RsStencilStateDesc_t // rendersystemdx11
{
	bitfield:4 m_frontStencilFunc; // 0x0000
	bitfield:4 m_backStencilFunc; // 0x0000
	bitfield:1 m_bStencilEnable; // 0x0000
	bitfield:3 m_frontStencilFailOp; // 0x0000
	bitfield:3 m_frontStencilDepthFailOp; // 0x0000
	bitfield:3 m_frontStencilPassOp; // 0x0000
	bitfield:3 m_backStencilFailOp; // 0x0000
	bitfield:3 m_backStencilDepthFailOp; // 0x0000
	bitfield:3 m_backStencilPassOp; // 0x0000
	uint8 m_nStencilReadMask; // 0x0004
	uint8 m_nStencilWriteMask; // 0x0005
};
class InfoForResourceTypeWorld_t // resourcesystem
{
};
class C_INIT_RemapNamedModelSequenceToScalar : public C_INIT_RemapNamedModelElementToScalar // particles
{
};
class PulseRuntimeEntrypointIndex_t // pulse_runtime_lib
{
	int32 m_Value; // 0x0000
};
class CNmGraphNode::CDefinition // animlib
{
	int16 m_nNodeIdx; // 0x0008
};
class SndBeatEventKeyedMidiNotes_t : public SndBeatEventKeys_t // soundsystem
{
	uint8 m_nStatus; // 0x0010
	uint8 m_nNote; // 0x0011
	uint8 m_nVelocity; // 0x0012
};
class CNmEventConsumerLegacy : public CNmEventConsumer // server
{
};
class ParticlePreviewState_t // particles
{
	CUtlString m_previewModel; // 0x0000
	uint32 m_nModSpecificData; // 0x0008
	PetGroundType_t m_groundType; // 0x000C
	CUtlString m_sequenceName; // 0x0010
	int32 m_nFireParticleOnSequenceFrame; // 0x0018
	CUtlString m_hitboxSetName; // 0x0020
	CUtlString m_materialGroupName; // 0x0028
	CUtlVector< ParticlePreviewBodyGroup_t > m_vecBodyGroups; // 0x0030
	float32 m_flPlaybackSpeed; // 0x0048
	float32 m_flParticleSimulationRate; // 0x004C
	bool m_bShouldDrawHitboxes; // 0x0050
	bool m_bShouldDrawAttachments; // 0x0051
	bool m_bShouldDrawAttachmentNames; // 0x0052
	bool m_bShouldDrawControlPointAxes; // 0x0053
	bool m_bAnimationNonLooping; // 0x0054
	bool m_bSequenceNameIsAnimClipPath; // 0x0055
	Vector m_vecPreviewGravity; // 0x0058
	Vector m_vecPreviewWind; // 0x0064
};
class RnBodyDesc_t // physicslib
{
	CUtlString m_sDebugName; // 0x0000
	VectorWS m_vPosition; // 0x0008
	QuaternionStorage m_qOrientation; // 0x0014
	Vector m_vLinearVelocity; // 0x0024
	Vector m_vAngularVelocity; // 0x0030
	Vector m_vLocalMassCenter; // 0x003C
	Vector[3] m_LocalInertiaInv; // 0x0048
	float32 m_flMassInv; // 0x006C
	float32 m_flGameMass; // 0x0070
	float32 m_flMassScaleInv; // 0x0074
	float32 m_flInertiaScaleInv; // 0x0078
	float32 m_flLinearDamping; // 0x007C
	float32 m_flAngularDamping; // 0x0080
	float32 m_flLinearDragScale; // 0x0084
	float32 m_flAngularDragScale; // 0x0088
	float32 m_flLinearFluidDragScale; // 0x008C
	float32 m_flAngularFluidDragScale; // 0x0090
	Vector m_vLastAwakeForceAccum; // 0x0094
	Vector m_vLastAwakeTorqueAccum; // 0x00A0
	float32 m_flBuoyancyScale; // 0x00AC
	float32 m_flGravityScale; // 0x00B0
	float32 m_flTimeScale; // 0x00B4
	int32 m_nBodyType; // 0x00B8
	uint32 m_nGameIndex; // 0x00BC
	uint32 m_nGameFlags; // 0x00C0
	int8 m_nMinVelocityIterations; // 0x00C4
	int8 m_nMinPositionIterations; // 0x00C5
	int8 m_nMassPriority; // 0x00C6
	bool m_bEnabled; // 0x00C7
	bool m_bSleeping; // 0x00C8
	bool m_bIsContinuousEnabled; // 0x00C9
	bool m_bDragEnabled; // 0x00CA
	Vector m_vGravity; // 0x00CC
	bool m_bSpeculativeEnabled; // 0x00D8
	bool m_bHasShadowController; // 0x00D9
	DynamicContinuousContactBehavior_t m_nDynamicContinuousContactBehavior; // 0x00DA
};
class CSeqS1SeqDesc // animationsystem
{
	CBufferString m_sName; // 0x0000
	CSeqSeqDescFlag m_flags; // 0x0010
	CSeqMultiFetch m_fetch; // 0x0020
	int32 m_nLocalWeightlist; // 0x0090
	CUtlVector< CSeqAutoLayer > m_autoLayerArray; // 0x0098
	CUtlVector< CSeqIKLock > m_IKLockArray; // 0x00B0
	CSeqTransition m_transition; // 0x00C8
	KeyValues3 m_SequenceKeys; // 0x00D0
	CBufferString m_LegacyKeyValueText; // 0x00E0
	CUtlVector< CAnimActivity > m_activityArray; // 0x00F0
	CUtlVector< CFootMotion > m_footMotion; // 0x0108
};
class CNmFollowBoneTask : public CNmPoseTask // animlib
{
};
class C_OP_PinRopeSegmentParticleToParent : public CParticleFunctionOperator // particles
{
	ParticleSelection_t m_nParticleSelection; // 0x01D8
	CParticleCollectionFloatInput m_nParticleNumber; // 0x01E0
	CPerParticleFloatInput m_flInterpolation; // 0x0350
};
class C_OP_ColorInterpolateRandom : public CParticleFunctionOperator // particles
{
	Color m_ColorFadeMin; // 0x01D8
	Color m_ColorFadeMax; // 0x01F4
	float32 m_flFadeStartTime; // 0x0204
	float32 m_flFadeEndTime; // 0x0208
	ParticleAttributeIndex_t m_nFieldOutput; // 0x020C
	bool m_bEaseInOut; // 0x0210
};
class C_OP_RenderFlattenGrass : public CParticleFunctionRenderer // particles
{
	float32 m_flFlattenStrength; // 0x0228
	ParticleAttributeIndex_t m_nStrengthFieldOverride; // 0x022C
	float32 m_flRadiusScale; // 0x0230
};
class CSndSeqInstBaseSchema // soundsystem
{
	SndSeqInstrumentType_t m_nType; // 0x0008
	bool m_bStopCurrentEvents; // 0x000E
	float32 m_flBPM; // 0x0010
	float32 m_flBPMFactor; // 0x0014
	float32 m_flBPMInvFactor; // 0x0018
};
class CompositeMaterialInputContainer_t // compositematerialslib
{
	bool m_bEnabled; // 0x0000
	CompositeMaterialInputContainerSourceType_t m_nCompositeMaterialInputContainerSourceType; // 0x0004
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIMaterial2 > > m_strSpecificContainerMaterial; // 0x0008
	CUtlString m_strAttrName; // 0x00E8
	CUtlString m_strAlias; // 0x00F0
	CUtlVector< CompositeMaterialInputLooseVariable_t > m_vecLooseVariables; // 0x00F8
	CUtlString m_strAttrNameForVar; // 0x0110
	bool m_bExposeExternally; // 0x0118
};
class C_INIT_StatusEffectCitadel : public CParticleFunctionInitializer // particles
{
	float32 m_flSFXColorWarpAmount; // 0x01E0
	float32 m_flSFXNormalAmount; // 0x01E4
	float32 m_flSFXMetalnessAmount; // 0x01E8
	float32 m_flSFXRoughnessAmount; // 0x01EC
	float32 m_flSFXSelfIllumAmount; // 0x01F0
	float32 m_flSFXSScale; // 0x01F4
	float32 m_flSFXSScrollX; // 0x01F8
	float32 m_flSFXSScrollY; // 0x01FC
	float32 m_flSFXSScrollZ; // 0x0200
	float32 m_flSFXSOffsetX; // 0x0204
	float32 m_flSFXSOffsetY; // 0x0208
	float32 m_flSFXSOffsetZ; // 0x020C
	DetailCombo_t m_nDetailCombo; // 0x0210
	float32 m_flSFXSDetailAmount; // 0x0214
	float32 m_flSFXSDetailScale; // 0x0218
	float32 m_flSFXSDetailScrollX; // 0x021C
	float32 m_flSFXSDetailScrollY; // 0x0220
	float32 m_flSFXSDetailScrollZ; // 0x0224
	float32 m_flSFXSUseModelUVs; // 0x0228
};
class CSSDSMsg_LayerBase // scenesystem
{
	SceneViewId_t m_viewId; // 0x0000
	CUtlString m_ViewName; // 0x0010
	uint64 m_nLayerId; // 0x0018
	CUtlString m_LayerName; // 0x0020
	CUtlString m_displayText; // 0x0028
};
class CVoiceContainerEnvelopeAnalyzer : public CVoiceContainerAnalysisBase // soundsystem_voicecontainers
{
	EMode_t m_mode; // 0x0048
	float32 m_fAnalysisWindowMs; // 0x004C
	float32 m_flThreshold; // 0x0050
};
class CVMixFlangerProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixFlangerDesc_t m_desc; // 0x0020
};
class C_OP_DistanceToTransform : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	CPerParticleFloatInput m_flInputMin; // 0x01E0
	CPerParticleFloatInput m_flInputMax; // 0x0350
	CPerParticleFloatInput m_flOutputMin; // 0x04C0
	CPerParticleFloatInput m_flOutputMax; // 0x0630
	CParticleTransformInput m_TransformStart; // 0x07A0
	bool m_bLOS; // 0x0808
	char[128] m_CollisionGroupName; // 0x0809
	ParticleTraceSet_t m_nTraceSet; // 0x088C
	float32 m_flMaxTraceLength; // 0x0890
	float32 m_flLOSScale; // 0x0894
	ParticleSetMethod_t m_nSetMethod; // 0x0898
	bool m_bActiveRange; // 0x089C
	bool m_bAdditive; // 0x089D
	CPerParticleVecInput m_vecComponentScale; // 0x08A0
};
class C_OP_CurlNoiseForce : public CParticleFunctionForce // particles
{
	ParticleDirectionNoiseType_t m_nNoiseType; // 0x01E8
	CPerParticleVecInput m_vecNoiseFreq; // 0x01F0
	CPerParticleVecInput m_vecNoiseScale; // 0x08A8
	CPerParticleVecInput m_vecOffset; // 0x0F60
	CPerParticleVecInput m_vecOffsetRate; // 0x1618
	CPerParticleFloatInput m_flWorleySeed; // 0x1CD0
	CPerParticleFloatInput m_flWorleyJitter; // 0x1E40
};
class CSteamAudioAmbisonicsField // steamaudio
{
	CUtlVector< float32 > m_field; // 0x0000
};
class FeHingeLimit_t // physicslib
{
	uint16[6] nNode; // 0x0000
	uint32 nFlags; // 0x000C
	float32 flWeight4; // 0x0010
	float32 flWeight5; // 0x0014
	float32 flAngleCenter; // 0x0018
	float32 flAngleExtents; // 0x001C
};
class CModelConfigElement_RandomPick : public CModelConfigElement // modellib
{
	CUtlVector< CUtlString > m_Choices; // 0x0048
	CUtlVector< float32 > m_ChoiceWeights; // 0x0060
};
class CNMEventPulseState_t // server
{
	CGlobalSymbol m_eventID; // 0x0000
};
class C_OP_RenderVolumetricEmitter : public CParticleFunctionRenderer // particles
{
	CUtlString m_strChannelType; // 0x0228
	ParticleVolumetricSmokeType_t m_nType; // 0x0230
	ParticleVolumetricSmokeCreationType_t m_nCreationType; // 0x0234
	EventTypeSelection_t m_nEventType; // 0x0238
	CPerParticleVecInput m_vecPos; // 0x0240
	CPerParticleVecInput m_vecVelocity; // 0x08F8
	CPerParticleVecInput m_vPrevPosition; // 0x0FB0
	CPerParticleFloatInput m_flSpeed; // 0x1668
	CPerParticleFloatInput m_flRadius; // 0x17D8
	CPerParticleFloatInput m_flDensity; // 0x1948
	CPerParticleFloatInput m_flTemperature; // 0x1AB8
	CPerParticleFloatInput m_flMagnitude; // 0x1C28
	CPerParticleFloatInput m_flKillRadius; // 0x1D98
	CPerParticleFloatInput m_flKillDensityScale; // 0x1F08
	CPerParticleFloatInput m_flFalloff; // 0x2078
};
class C_OP_PercentageBetweenTransformsVector : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	float32 m_flInputMin; // 0x01DC
	float32 m_flInputMax; // 0x01E0
	Vector m_vecOutputMin; // 0x01E4
	Vector m_vecOutputMax; // 0x01F0
	CParticleTransformInput m_TransformStart; // 0x0200
	CParticleTransformInput m_TransformEnd; // 0x0268
	ParticleSetMethod_t m_nSetMethod; // 0x02D0
	bool m_bActiveRange; // 0x02D4
	bool m_bRadialCheck; // 0x02D5
};
class CNmEntityAttributeEventBase : public CNmEvent // animlib
{
	CNmEventTargetEntity_t m_target; // 0x0018
	CUtlString m_attributeName; // 0x0020
};
class CNmNotNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
};
class FunctionInfo_t // mathlib_extended
{
	CUtlString m_name; // 0x0008
	CUtlStringToken m_nameToken; // 0x0010
	int32 m_nParamCount; // 0x0014
	FuseFunctionIndex_t m_nIndex; // 0x0018
	bool m_bIsPure; // 0x001A
};
class AmmoIndex_t // server
{
	int8 m_Value; // 0x0000
};
class CBreakableStageHelper // server
{
	int32 m_nCurrentStage; // 0x0008
	int32 m_nStageCount; // 0x000C
};
class C_OP_SetControlPointToWaterSurface : public CParticleFunctionPreEmission // particles
{
	int32 m_nSourceCP; // 0x01E0
	int32 m_nDestCP; // 0x01E4
	int32 m_nFlowCP; // 0x01E8
	int32 m_nActiveCP; // 0x01EC
	int32 m_nActiveCPField; // 0x01F0
	CParticleCollectionFloatInput m_flRetestRate; // 0x01F8
	bool m_bAdaptiveThreshold; // 0x0368
};
class C_OP_SetAttributeToScalarExpression : public CParticleFunctionOperator // particles
{
	ScalarExpressionType_t m_nExpression; // 0x01D8
	CPerParticleFloatInput m_flInput1; // 0x01E0
	CPerParticleFloatInput m_flInput2; // 0x0350
	CParticleRemapFloatInput m_flOutputRemap; // 0x04C0
	ParticleAttributeIndex_t m_nOutputField; // 0x0630
	ParticleSetMethod_t m_nSetMethod; // 0x0634
};
class CSeqTransition // animationsystem
{
	float32 m_flFadeInTime; // 0x0000
	float32 m_flFadeOutTime; // 0x0004
};
class CNmFloatSwitchNode::CDefinition : public CNmFloatValueNode::CDefinition // animlib
{
	int16 m_nSwitchValueNodeIdx; // 0x0010
	int16 m_nTrueValueNodeIdx; // 0x0012
	int16 m_nFalseValueNodeIdx; // 0x0014
	float32 m_flFalseValue; // 0x0018
	float32 m_flTrueValue; // 0x001C
};
class CNmOrientationWarpEvent : public CNmEvent // animlib
{
};
class CAnimParameterManagerUpdater // animgraphlib
{
	CUtlVector< CSmartPtr< CAnimParameterBase > > m_parameters; // 0x0018
	CUtlHashtable< AnimParamID, int32 > m_idToIndexMap; // 0x0030
	CUtlHashtable< CUtlString, int32 > m_nameToIndexMap; // 0x0050
	CUtlVector< CAnimParamHandle > m_indexToHandle; // 0x0070
	CUtlVector< std::pair< CAnimParamHandle, CAnimVariant > > m_autoResetParams; // 0x0088
	CUtlHashtable< CAnimParamHandle, int16 > m_autoResetMap; // 0x00A0
};
class CStateUpdateData // animgraphlib
{
	CUtlString m_name; // 0x0000
	AnimScriptHandle m_hScript; // 0x0008
	CUtlVector< int32 > m_transitionIndices; // 0x0010
	CUtlVector< CStateActionUpdater > m_actions; // 0x0028
	AnimStateID m_stateID; // 0x0040
	bitfield:1 m_bIsStartState; // 0x0000
	bitfield:1 m_bIsEndState; // 0x0000
	bitfield:1 m_bIsPassthrough; // 0x0000
	bitfield:1 m_bIsPassthroughRootMotion; // 0x0000
	bitfield:1 m_bPreEvaluatePassthroughTransitionPath; // 0x0000
};
class C_OP_WaterImpulseRenderer : public CParticleFunctionRenderer // particles
{
	CPerParticleVecInput m_vecPos; // 0x0228
	CPerParticleFloatInput m_flRadius; // 0x08E0
	CPerParticleFloatInput m_flMagnitude; // 0x0A50
	CPerParticleFloatInput m_flShape; // 0x0BC0
	CPerParticleFloatInput m_flWindSpeed; // 0x0D30
	CPerParticleFloatInput m_flWobble; // 0x0EA0
	bool m_bIsRadialWind; // 0x1010
	EventTypeSelection_t m_nEventType; // 0x1014
};
class C_OP_SetChildControlPoints : public CParticleFunctionOperator // particles
{
	int32 m_nChildGroupID; // 0x01D8
	int32 m_nFirstControlPoint; // 0x01DC
	int32 m_nNumControlPoints; // 0x01E0
	CParticleCollectionFloatInput m_nFirstSourcePoint; // 0x01E8
	bool m_bReverse; // 0x0358
	bool m_bSetOrientation; // 0x0359
	ParticleOrientationType_t m_nOrientation; // 0x035C
};
class FeProxyVertexMap_t // physicslib
{
	CUtlString m_Name; // 0x0000
	float32 m_flWeight; // 0x0008
};
class FeQuad_t // physicslib
{
	uint16[4] nNode; // 0x0000
	float32 flSlack; // 0x0008
	Vector4D[4] vShape; // 0x000C
};
class CNmZeroPoseTask : public CNmPoseTask // animlib
{
};
class CSeqSynthAnimDesc // animationsystem
{
	CBufferString m_sName; // 0x0000
	CSeqSeqDescFlag m_flags; // 0x0010
	CSeqTransition m_transition; // 0x001C
	int16 m_nLocalBaseReference; // 0x0024
	int16 m_nLocalBoneMask; // 0x0026
	CUtlVector< CAnimActivity > m_activityArray; // 0x0028
};
class CBoneVelocityMetricEvaluator : public CMotionMetricEvaluator // animgraphlib
{
	int32 m_nBoneIndex; // 0x0050
};
class CFlexDesc // modellib
{
	CUtlString m_szFacs; // 0x0000
};
class CNetworkOriginQuantizedVectorWS // server
{
	CNetworkedQuantizedFloat m_vecX; // 0x0010
	CNetworkedQuantizedFloat m_vecY; // 0x0018
	CNetworkedQuantizedFloat m_vecZ; // 0x0020
};
class C_INIT_RandomTrailLength : public CParticleFunctionInitializer // particles
{
	float32 m_flMinLength; // 0x01E0
	float32 m_flMaxLength; // 0x01E4
	float32 m_flLengthRandExponent; // 0x01E8
};
class C_OP_RemapDistanceToLineSegmentBase : public CParticleFunctionOperator // particles
{
	int32 m_nCP0; // 0x01D8
	int32 m_nCP1; // 0x01DC
	float32 m_flMinInputValue; // 0x01E0
	float32 m_flMaxInputValue; // 0x01E4
	bool m_bInfiniteLine; // 0x01E8
};
class C_OP_RemapVectorComponentToScalar : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldInput; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
	int32 m_nComponent; // 0x01E0
};
class C_OP_RtEnvCull : public CParticleFunctionOperator // particles
{
	Vector m_vecTestDir; // 0x01D8
	Vector m_vecTestNormal; // 0x01E4
	bool m_bCullOnMiss; // 0x01F0
	bool m_bStickInsteadOfCull; // 0x01F1
	char[128] m_RtEnvName; // 0x01F2
	int32 m_nRTEnvCP; // 0x0274
	int32 m_nComponent; // 0x0278
};
class C_OP_RemapNamedModelBodyPartEndCap : public C_OP_RemapNamedModelElementEndCap // particles
{
};
class C_OP_RampScalarLinear : public CParticleFunctionOperator // particles
{
	float32 m_RateMin; // 0x01D8
	float32 m_RateMax; // 0x01DC
	float32 m_flStartTime_min; // 0x01E0
	float32 m_flStartTime_max; // 0x01E4
	float32 m_flEndTime_min; // 0x01E8
	float32 m_flEndTime_max; // 0x01EC
	ParticleAttributeIndex_t m_nField; // 0x0210
	bool m_bProportionalOp; // 0x0214
};
class CVoiceContainerVsndRadioButton : public CVoiceContainerBase // soundsystem_voicecontainers
{
	CUtlString m_namespace; // 0x0070
	CVsndRadioButtonSlot m_slot1; // 0x0078
	CVsndRadioButtonSlot m_slot2; // 0x0100
	CVsndRadioButtonSlot m_slot3; // 0x0188
	CVsndRadioButtonSlot m_slot4; // 0x0210
	CVsndRadioButtonSlot m_slot5; // 0x0298
	CVsndRadioButtonSlot m_slot6; // 0x0320
	CVsndRadioButtonSlot m_slot7; // 0x03A8
	CVsndRadioButtonSlot m_slot8; // 0x0430
	CVsndRadioButtonSlot m_slot9; // 0x04B8
	CVsndRadioButtonSlot m_slot10; // 0x0540
	CVsndRadioButtonSlot m_slot11; // 0x05C8
	CVsndRadioButtonSlot m_slot12; // 0x0650
	CVsndRadioButtonSlot m_slot13; // 0x06D8
	CVsndRadioButtonSlot m_slot14; // 0x0760
	CVsndRadioButtonSlot m_slot15; // 0x07E8
	CVsndRadioButtonSlot m_slot16; // 0x0870
};
class CVMixEffectChainProcessorDesc : public CVMixBaseProcessorDesc // soundsystem_lowlevel
{
	VMixEffectChainDesc_t m_desc; // 0x0020
};
class VertexPositionColor_t // physicslib
{
	Vector m_vPosition; // 0x0000
};
class CParticleCollectionVecInput : public CParticleVecInput // particleslib
{
};
class CParticleVariableRef // particleslib
{
	CKV3MemberNameWithStorage m_variableName; // 0x0000
	CPulseValueFullType m_variableType; // 0x0038
};
class TraceSettings_t // animgraphlib
{
	float32 m_flTraceHeight; // 0x0000
	float32 m_flTraceRadius; // 0x0004
};
class CNmFootIKNode::CDefinition : public CNmPassthroughNode::CDefinition // animlib
{
	CGlobalSymbol m_leftEffectorBoneID; // 0x0018
	CGlobalSymbol m_rightEffectorBoneID; // 0x0020
	int16 m_nLeftTargetNodeIdx; // 0x0028
	int16 m_nRightTargetNodeIdx; // 0x002A
	int16 m_nEnabledNodeIdx; // 0x002C
	float32 m_flBlendTimeSeconds; // 0x0030
	NmIKBlendMode_t m_blendMode; // 0x0034
	bool m_bIsTargetInWorldSpace; // 0x0035
};
class CNmOrientationWarpNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
	int16 m_nClipReferenceNodeIdx; // 0x0010
	int16 m_nTargetValueNodeIdx; // 0x0012
	bool m_bIsOffsetNode; // 0x0014
	bool m_bIsOffsetRelativeToCharacter; // 0x0015
	bool m_bWarpTranslation; // 0x0016
	CNmRootMotionData::SamplingMode_t m_samplingMode; // 0x0017
};
class CNmGraphDefinition::ReferencedGraphSlot_t // animlib
{
	int16 m_nNodeIdx; // 0x0000
	int16 m_dataSlotIdx; // 0x0002
};
class C_OP_SetControlPointFromObjectScale : public CParticleFunctionPreEmission // particles
{
	int32 m_nCPInput; // 0x01E0
	int32 m_nCPOutput; // 0x01E4
};
class C_OP_CPOffsetToPercentageBetweenCPs : public CParticleFunctionOperator // particles
{
	float32 m_flInputMin; // 0x01D8
	float32 m_flInputMax; // 0x01DC
	float32 m_flInputBias; // 0x01E0
	int32 m_nStartCP; // 0x01E4
	int32 m_nEndCP; // 0x01E8
	int32 m_nOffsetCP; // 0x01EC
	int32 m_nOuputCP; // 0x01F0
	int32 m_nInputCP; // 0x01F4
	bool m_bRadialCheck; // 0x01F8
	bool m_bScaleOffset; // 0x01F9
	Vector m_vecOffset; // 0x01FC
};
class CQuaternionAnimParameter : public CConcreteAnimParameter // animgraphlib
{
	Quaternion m_defaultValue; // 0x0080
	bool m_bInterpolate; // 0x0090
};
class CNmTargetValueNode::CDefinition : public CNmValueNode::CDefinition // animlib
{
};
class CPoseHandle // animgraphlib
{
	uint16 m_nIndex; // 0x0000
	PoseType_t m_eType; // 0x0002
};
class CSoundEnvelope // server
{
	float32 m_current; // 0x0000
	float32 m_target; // 0x0004
	float32 m_rate; // 0x0008
	bool m_forceupdate; // 0x000C
};
class Extent // navlib
{
	VectorWS lo; // 0x0000
	VectorWS hi; // 0x000C
};
class CNmAimCSTask : public CNmPoseTask // server
{
};
class C_OP_FadeIn : public CParticleFunctionOperator // particles
{
	float32 m_flFadeInTimeMin; // 0x01D8
	float32 m_flFadeInTimeMax; // 0x01DC
	float32 m_flFadeInTimeExp; // 0x01E0
	bool m_bProportional; // 0x01E4
};
class AnimNodeOutputID // modellib
{
	uint32 m_id; // 0x0000
};
class ModelMeshBufferData_t // modellib
{
	int32 m_nBlockIndex; // 0x0000
	uint32 m_nElementCount; // 0x0004
	uint32 m_nElementSizeInBytes; // 0x0008
	bool m_bMeshoptCompressed; // 0x000C
	bool m_bMeshoptIndexSequence; // 0x000D
	int8 m_nMeshoptMeshletEncodeVersion; // 0x000E
	bool m_bCompressedZSTD; // 0x000F
	bool m_bCreateBufferSRV; // 0x0010
	bool m_bCreateBufferUAV; // 0x0011
	bool m_bCreateRawBuffer; // 0x0012
	bool m_bCreatePooledBuffer; // 0x0013
	uint8 m_nBufferUsage; // 0x0014
	CUtlVector< RenderInputLayoutField_t > m_inputLayoutFields; // 0x0018
};
class C_INIT_RandomAlpha : public CParticleFunctionInitializer // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E0
	int32 m_nAlphaMin; // 0x01E4
	int32 m_nAlphaMax; // 0x01E8
	float32 m_flAlphaRandExponent; // 0x01F4
};
class C_OP_RenderVRHapticEvent : public CParticleFunctionRenderer // particles
{
	ParticleVRHandChoiceList_t m_nHand; // 0x0228
	int32 m_nOutputHandCP; // 0x022C
	int32 m_nOutputField; // 0x0230
	CPerParticleFloatInput m_flAmplitude; // 0x0238
};
class C_INIT_CreateSequentialPathV2 : public CParticleFunctionInitializer // particles
{
	CPerParticleFloatInput m_fMaxDistance; // 0x01E0
	CParticleCollectionFloatInput m_flNumToAssign; // 0x0350
	bool m_bLoop; // 0x04C0
	bool m_bCPPairs; // 0x04C1
	bool m_bSaveOffset; // 0x04C2
	CPathParameters m_PathParams; // 0x04D0
};
class CNmFloatChannelSet_t // animlib
{
	CGlobalSymbol m_ID; // 0x0000
	CUtlLeanVector< CGlobalSymbol > m_channelIDs; // 0x0008
};
class CAnimScriptBase // host
{
	bool m_bIsValid; // 0x0008
};
class RagdollCreationParams_t // server
{
	Vector m_vForce; // 0x0000
	int32 m_nForceBone; // 0x000C
	bool m_bForceCurrentWorldTransform; // 0x0010
	bool m_bUseLRURetirement; // 0x0011
	int32 m_nHealthToGrant; // 0x0014
};
class C_OP_RenderPostProcessing : public CParticleFunctionRenderer // particles
{
	CPerParticleFloatInput m_flPostProcessStrength; // 0x0228
	CStrongHandle< InfoForResourceTypeCPostProcessingResource > m_hPostTexture; // 0x0398
	ParticlePostProcessPriorityGroup_t m_nPriority; // 0x03A0
};
class C_OP_LockToSavedSequentialPath : public CParticleFunctionOperator // particles
{
	float32 m_flFadeStart; // 0x01DC
	float32 m_flFadeEnd; // 0x01E0
	bool m_bCPPairs; // 0x01E4
	CPathParameters m_PathParams; // 0x01F0
};
class VMixDualCompressorDesc_t // soundsystem_lowlevel
{
	float32 m_flRMSTimeMS; // 0x0000
	float32 m_fldbKneeWidth; // 0x0004
	float32 m_flWetMix; // 0x0008
	bool m_bPeakMode; // 0x000C
	VMixDynamicsBand_t m_bandDesc; // 0x0010
};
class FeSimdAnimStrayRadius_t // physicslib
{
	uint16[4][2] nNode; // 0x0000
	fltx4 flMaxDist; // 0x0010
	fltx4 flRelaxationFactor; // 0x0020
};
class CNmIsExternalPoseSetNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	int16 m_nExternalPoseNodeIdx; // 0x0010
};
class PlayerInputMotorInstanceData_t // animgraphlib
{
	Vector m_vInputVectorWS; // 0x0000
	Vector m_vVelocityWS; // 0x000C
	Vector m_vAccelerationWS; // 0x0018
};
class CCycleClipInstanceData // animgraphlib
{
	CAnimNetVar< float32 > m_flCycle; // 0x0000
	CAnimNetVar< float32 > m_flPrevCycle; // 0x000C
};
class RsBlendStateDesc_t // rendersystemdx11
{
	uint32 m_srcBlendBits; // 0x0000
	uint32 m_destBlendBits; // 0x0004
	uint32 m_srcBlendAlphaBits; // 0x0008
	uint32 m_destBlendAlphaBits; // 0x000C
	uint32 m_renderTargetWriteMaskBits; // 0x0010
	bitfield:30 m_blendOpBits; // 0x0000
	bitfield:1 m_bAlphaToCoverageEnable; // 0x0000
	bitfield:1 m_bIndependentBlendEnable; // 0x0000
	uint32 m_blendOpAlphaBits; // 0x0018
	uint8 m_blendEnableBits; // 0x001C
	uint8 m_srgbWriteEnableBits; // 0x001D
};
class InfoForResourceTypeCSmartProp // resourcesystem
{
};
class C_OP_RemapNamedModelSequenceOnceTimed : public C_OP_RemapNamedModelElementOnceTimed // particles
{
};
class FeVertexMapDesc_t // physicslib
{
	CUtlString sName; // 0x0000
	uint32 nNameHash; // 0x0008
	uint32 nColor; // 0x000C
	uint32 nFlags; // 0x0010
	uint16 nVertexBase; // 0x0014
	uint16 nVertexCount; // 0x0016
	uint32 nMapOffset; // 0x0018
	uint32 nNodeListOffset; // 0x001C
	Vector vCenterOfMass; // 0x0020
	float32 flVolumetricSolveStrength; // 0x002C
	int16 nScaleSourceNode; // 0x0030
	uint16 nNodeListCount; // 0x0032
};
class CPathHelperUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	float32 m_flStoppingRadius; // 0x0070
	float32 m_flStoppingSpeedScale; // 0x0074
};
class CSkillDamage // server
{
	CSkillFloat m_flDamage; // 0x0000
	float32 m_flNPCDamageScalarVsNPC; // 0x0010
	float32 m_flPhysicsForceDamage; // 0x0014
};
class C_INIT_ChaoticAttractor : public CParticleFunctionInitializer // particles
{
	float32 m_flAParm; // 0x01E0
	float32 m_flBParm; // 0x01E4
	float32 m_flCParm; // 0x01E8
	float32 m_flDParm; // 0x01EC
	float32 m_flScale; // 0x01F0
	float32 m_flSpeedMin; // 0x01F4
	float32 m_flSpeedMax; // 0x01F8
	int32 m_nBaseCP; // 0x01FC
	bool m_bUniformSpeed; // 0x0200
};
class C_INIT_SequenceFromCP : public CParticleFunctionInitializer // particles
{
	bool m_bKillUnused; // 0x01E0
	bool m_bRadiusScale; // 0x01E1
	int32 m_nCP; // 0x01E4
	Vector m_vecOffset; // 0x01E8
};
class SampleCode // animgraphlib
{
	uint8[8] m_subCode; // 0x0000
};
class FootStepTrigger // animgraphlib
{
	CUtlVector< int32 > m_tags; // 0x0000
	int32 m_nFootIndex; // 0x0018
	StepPhase m_triggerPhase; // 0x001C
};
class CPulse_DomainValue // pulse_runtime_lib
{
	PulseDomainValueType_t m_nType; // 0x0000
	CGlobalSymbolCaseSensitive m_Value; // 0x0008
	CPulseValueFullType m_RequiredRuntimeType; // 0x0010
};
class C_OP_SpringToVectorConstraint : public CParticleFunctionConstraint // particles
{
	CPerParticleFloatInput m_flRestLength; // 0x01D8
	CPerParticleFloatInput m_flMinDistance; // 0x0348
	CPerParticleFloatInput m_flMaxDistance; // 0x04B8
	CPerParticleFloatInput m_flRestingLength; // 0x0628
	CPerParticleVecInput m_vecAnchorVector; // 0x0798
};
class CParentConstraint : public CBaseConstraint // modellib
{
};
class CFootPositionMetricEvaluator : public CMotionMetricEvaluator // animgraphlib
{
	CUtlVector< int32 > m_footIndices; // 0x0050
	bool m_bIgnoreSlope; // 0x0068
};
class CNmIDBasedSelectorNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
	CUtlLeanVectorFixedGrowable< int16, 5 > m_optionNodeIndices; // 0x0010
	CUtlLeanVectorFixedGrowable< CGlobalSymbol, 5 > m_optionIDs; // 0x0028
	int16 m_nParameterNodeIdx; // 0x0058
	int16 m_nFallbackNodeIdx; // 0x005A
	bool m_bIgnoreInvalidOptions; // 0x005C
};
class CFootStride // modellib
{
	CFootCycleDefinition m_definition; // 0x0000
	CFootTrajectories m_trajectories; // 0x0040
};
class C_INIT_InitialVelocityNoise : public CParticleFunctionInitializer // particles
{
	Vector m_vecAbsVal; // 0x01E0
	Vector m_vecAbsValInv; // 0x01EC
	CPerParticleVecInput m_vecOffsetLoc; // 0x01F8
	CPerParticleFloatInput m_flOffset; // 0x08B0
	CPerParticleVecInput m_vecOutputMin; // 0x0A20
	CPerParticleVecInput m_vecOutputMax; // 0x10D8
	CPerParticleFloatInput m_flNoiseScale; // 0x1790
	CPerParticleFloatInput m_flNoiseScaleLoc; // 0x1900
	CParticleTransformInput m_TransformInput; // 0x1A70
	bool m_bIgnoreDt; // 0x1AD8
};
class C_OP_EndCapTimedDecay : public CParticleFunctionOperator // particles
{
	float32 m_flDecayTime; // 0x01D8
};
class C_OP_MovementMaintainOffset : public CParticleFunctionOperator // particles
{
	Vector m_vecOffset; // 0x01D8
	int32 m_nCP; // 0x01E4
	bool m_bRadiusScale; // 0x01E8
};
class CParticleInput // particleslib
{
};
class CNmFixedWeightBoneMaskNode::CDefinition : public CNmBoneMaskValueNode::CDefinition // animlib
{
	float32 m_flBoneWeight; // 0x0010
};
class CMotionSearchDB // animgraphlib
{
	CMotionSearchNode m_rootNode; // 0x0000
	CProductQuantizer m_residualQuantizer; // 0x0080
	CUtlVector< MotionDBIndex > m_codeIndices; // 0x00A0
};
class InfoForResourceTypeCVMixListResource // resourcesystem
{
};
class CFloatMovingAverage // server
{
};
class CFootCycleMetricEvaluator : public CMotionMetricEvaluator // animgraphlib
{
	CUtlVector< int32 > m_footIndices; // 0x0050
};
class NmCompressionSettings_t::QuantizationRange_t // animlib
{
	float32 m_flRangeStart; // 0x0000
	float32 m_flRangeLength; // 0x0004
};
class CNPCPhysicsHull // modellib
{
	CGlobalSymbol m_sName; // 0x0000
	NPCPhysicsHullType_t m_eType; // 0x0008
	float32 m_flCapsuleHeight; // 0x000C
	float32 m_flCapsuleRadius; // 0x0010
	Vector m_vCapsuleCenter1; // 0x0014
	Vector m_vCapsuleCenter2; // 0x0020
	float32 m_flGroundBoxHeight; // 0x002C
	float32 m_flGroundBoxWidth; // 0x0030
};
class CNmGraphInstance // animlib
{
};
class VariableInfo_t // mathlib_extended
{
	CUtlString m_name; // 0x0000
	CUtlStringToken m_nameToken; // 0x0008
	FuseVariableIndex_t m_nIndex; // 0x000C
	uint8 m_nNumComponents; // 0x000E
	FuseVariableType_t m_eVarType; // 0x000F
	FuseVariableAccess_t m_eAccess; // 0x0010
};
class C_OP_RadiusDecay : public CParticleFunctionOperator // particles
{
	float32 m_flMinRadius; // 0x01D8
};
class VMixDelayDesc_t // soundsystem_lowlevel
{
	VMixFilterDesc_t m_feedbackFilter; // 0x0000
	bool m_bEnableFilter; // 0x0010
	float32 m_flDelay; // 0x0014
	float32 m_flDirectGain; // 0x0018
	float32 m_flDelayGain; // 0x001C
	float32 m_flFeedbackGain; // 0x0020
	float32 m_flWidth; // 0x0024
};
class FeTaperedCapsuleStretch_t // physicslib
{
	uint16[2] nNode; // 0x0000
	uint16 nCollisionMask; // 0x0004
	uint16 nDummy; // 0x0006
	float32[2] flRadius; // 0x0008
};
class RnNode_t // physicslib
{
	Vector m_vMin; // 0x0000
	uint32 m_nChildren; // 0x000C
	Vector m_vMax; // 0x0010
	uint32 m_nTriangleOffset; // 0x001C
};
class CTransitionUpdateData // animgraphlib
{
	uint8 m_srcStateIndex; // 0x0000
	uint8 m_destStateIndex; // 0x0001
	bitfield:7 m_nHandshakeMaskToDisableFirst; // 0x0000
	bitfield:1 m_bDisabled; // 0x0000
};
class CompositeMaterial_t // compositematerialslib
{
	KeyValues3 m_TargetKVs; // 0x0008
	KeyValues3 m_PreGenerationKVs; // 0x0018
	KeyValues3 m_FinalKVs; // 0x0058
	CUtlVector< GeneratedTextureHandle_t > m_vecGeneratedTextures; // 0x0080
};
class C_OP_SetControlPointFieldFromVectorExpression : public CParticleFunctionPreEmission // particles
{
	VectorFloatExpressionType_t m_nExpression; // 0x01E0
	CParticleCollectionVecInput m_vecInput1; // 0x01E8
	CParticleCollectionVecInput m_vecInput2; // 0x08A0
	CPerParticleFloatInput m_flLerp; // 0x0F58
	CParticleRemapFloatInput m_flOutputRemap; // 0x10C8
	int32 m_nOutputCP; // 0x1238
	int32 m_nOutVectorField; // 0x123C
};
class C_INIT_PointList : public CParticleFunctionInitializer // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E0
	CUtlVector< PointDefinition_t > m_pointList; // 0x01E8
	bool m_bPlaceAlongPath; // 0x0200
	bool m_bClosedLoop; // 0x0201
	int32 m_nNumPointsAlongPath; // 0x0204
};
class CSSDSMsg_ViewRender // scenesystem
{
	SceneViewId_t m_viewId; // 0x0000
	CUtlString m_ViewName; // 0x0010
};
class FeSDFRigid_t // physicslib
{
	Vector vLocalMin; // 0x0000
	Vector vLocalMax; // 0x000C
	float32 flBounciness; // 0x0018
	uint16 nNode; // 0x001C
	uint16 nCollisionMask; // 0x001E
	uint16 nVertexMapIndex; // 0x0020
	uint16 nFlags; // 0x0022
	CUtlVector< float32 > m_Distances; // 0x0028
	int32 m_nWidth; // 0x0040
	int32 m_nHeight; // 0x0044
	int32 m_nDepth; // 0x0048
};
class CNmFootIKTask : public CNmPoseTask // animlib
{
	int32 m_nLeftEffectorBoneIdx; // 0x0070
	int32 m_nRightEffectorBoneIdx; // 0x0074
	CTransform m_leftTargetTransform; // 0x0080
	CTransform m_rightTargetTransform; // 0x00A0
	int32 m_nLeftTargetBoneIdx; // 0x00C0
	int32 m_nRightTargetBoneIdx; // 0x00C4
	CNmTarget m_leftTarget; // 0x00D0
	CNmTarget m_rightTarget; // 0x0100
	NmIKBlendMode_t m_blendMode; // 0x0130
	float32 m_flBlendWeight; // 0x0134
	bool m_bIsTargetInWorldSpace; // 0x0138
	bool m_bIsRunningFromDeserializedData; // 0x0139
};
class PulseRuntimeConstantIndex_t // pulse_runtime_lib
{
	int16 m_Value; // 0x0000
};
class EventClientFrameSimulate_t // engine2
{
	EngineLoopState_t m_LoopState; // 0x0000
	float32 m_flRealTime; // 0x0028
	float32 m_flFrameTime; // 0x002C
	bool m_bScheduleSendTickPacket; // 0x0030
};
class C_OP_DistanceCull : public CParticleFunctionOperator // particles
{
	int32 m_nControlPoint; // 0x01D8
	Vector m_vecPointOffset; // 0x01DC
	CParticleCollectionFloatInput m_flDistance; // 0x01E8
	bool m_bCullInside; // 0x0358
	ParticleAttributeIndex_t m_nAttribute; // 0x035C
};
class C_OP_SetVec : public CParticleFunctionOperator // particles
{
	CPerParticleVecInput m_InputValue; // 0x01D8
	ParticleAttributeIndex_t m_nOutputField; // 0x0890
	ParticleSetMethod_t m_nSetMethod; // 0x0894
	CPerParticleFloatInput m_Lerp; // 0x0898
	bool m_bNormalizedOutput; // 0x0A08
};
class CZeroPoseUpdateNode : public CLeafUpdateNode // animgraphlib
{
};
class CNmGraphDefinition::ExternalPoseSlot_t // animlib
{
	int16 m_nNodeIdx; // 0x0000
	CGlobalSymbol m_slotID; // 0x0008
};
class CAnimEncodeDifference // animationsystem
{
	CUtlVector< CAnimBoneDifference > m_boneArray; // 0x0000
	CUtlVector< CAnimMorphDifference > m_morphArray; // 0x0018
	CUtlVector< CAnimUserDifference > m_userArray; // 0x0030
	CUtlVector< uint8 > m_bHasRotationBitArray; // 0x0048
	CUtlVector< uint8 > m_bHasMovementBitArray; // 0x0060
	CUtlVector< uint8 > m_bHasMorphBitArray; // 0x0078
	CUtlVector< uint8 > m_bHasUserBitArray; // 0x0090
};
class CFlexOp // modellib
{
	FlexOpCode_t m_OpCode; // 0x0000
	int32 m_Data; // 0x0004
};
class CAnimParamHandleMap // animgraphlib
{
	CUtlHashtable< uint16, int16 > m_list; // 0x0000
};
class CAnimDesc // animationsystem
{
	CBufferString m_name; // 0x0000
	CAnimDesc_Flag m_flags; // 0x0010
	float32 fps; // 0x0018
	CAnimEncodedFrames m_Data; // 0x0020
	CUtlVector< CAnimMovement > m_movementArray; // 0x00F8
	CTransform m_xInitialOffset; // 0x0110
	CUtlVector< CAnimEventDefinition > m_eventArray; // 0x0130
	CUtlVector< CAnimActivity > m_activityArray; // 0x0148
	CUtlVector< CAnimLocalHierarchy > m_hierarchyArray; // 0x0160
	float32 framestalltime; // 0x0178
	Vector m_vecRootMin; // 0x017C
	Vector m_vecRootMax; // 0x0188
	CUtlVector< Vector > m_vecBoneWorldMin; // 0x0198
	CUtlVector< Vector > m_vecBoneWorldMax; // 0x01B0
	CAnimSequenceParams m_sequenceParams; // 0x01C8
};
class CBoneConstraintDotToMorph : public CBoneConstraintBase // modellib
{
	CUtlString m_sBoneName; // 0x0020
	CUtlString m_sTargetBoneName; // 0x0028
	CUtlString m_sMorphChannelName; // 0x0030
	float32[4] m_flRemap; // 0x0038
};
class CompMatMutatorCondition_t // compositematerialslib
{
	CompMatPropertyMutatorConditionType_t m_nMutatorCondition; // 0x0000
	CUtlString m_strMutatorConditionContainerName; // 0x0008
	CUtlString m_strMutatorConditionContainerVarName; // 0x0010
	CUtlString m_strMutatorConditionContainerVarValue; // 0x0018
	bool m_bPassWhenTrue; // 0x0020
};
class C_OP_MaintainSequentialPath : public CParticleFunctionOperator // particles
{
	float32 m_fMaxDistance; // 0x01D8
	float32 m_flNumToAssign; // 0x01DC
	float32 m_flCohesionStrength; // 0x01E0
	float32 m_flTolerance; // 0x01E4
	bool m_bLoop; // 0x01E8
	bool m_bUseParticleCount; // 0x01E9
	CPathParameters m_PathParams; // 0x01F0
};
class CSSDSMsg_ViewTarget // scenesystem
{
	CUtlString m_Name; // 0x0000
	uint64 m_TextureId; // 0x0008
	int32 m_nWidth; // 0x0010
	int32 m_nHeight; // 0x0014
	int32 m_nRequestedWidth; // 0x0018
	int32 m_nRequestedHeight; // 0x001C
	int32 m_nNumMipLevels; // 0x0020
	int32 m_nDepth; // 0x0024
	int32 m_nMultisampleNumSamples; // 0x0028
	int32 m_nFormat; // 0x002C
};
class CSSDSMsg_PreLayer : public CSSDSMsg_LayerBase // scenesystem
{
};
class SteamAudioReverbCompressionSettings_t // steamaudio
{
	bool m_bEnableCompression; // 0x0000
	float32 m_flQuality; // 0x0004
};
class WeightList // animgraphlib
{
	CUtlString m_name; // 0x0000
	CUtlVector< float32 > m_weights; // 0x0008
};
class MoodAnimationLayer_t // animationsystem
{
	CUtlString m_sName; // 0x0000
	bool m_bActiveListening; // 0x0008
	bool m_bActiveTalking; // 0x0009
	CUtlVector< MoodAnimation_t > m_layerAnimations; // 0x0010
	CRangeFloat m_flIntensity; // 0x0028
	CRangeFloat m_flDurationScale; // 0x0030
	bool m_bScaleWithInts; // 0x0038
	CRangeFloat m_flNextStart; // 0x003C
	CRangeFloat m_flStartOffset; // 0x0044
	CRangeFloat m_flEndOffset; // 0x004C
	float32 m_flFadeIn; // 0x0054
	float32 m_flFadeOut; // 0x0058
};
class CCurrentVelocityMetricEvaluator : public CMotionMetricEvaluator // animgraphlib
{
};
class C_OP_FadeOut : public CParticleFunctionOperator // particles
{
	float32 m_flFadeOutTimeMin; // 0x01D8
	float32 m_flFadeOutTimeMax; // 0x01DC
	float32 m_flFadeOutTimeExp; // 0x01E0
	float32 m_flFadeBias; // 0x01E4
	bool m_bProportional; // 0x0220
	bool m_bEaseInAndOut; // 0x0221
};
class VMixEQ8Desc_t // soundsystem_lowlevel
{
	VMixFilterDesc_t[8] m_stages; // 0x0000
};
class VelocityZone_t // soundsystem
{
	uint8 nMaxVel; // 0x0000
	uint8 nNextSelection; // 0x0001
	uint8 nNumSamples; // 0x0002
	uint32[4] pSamples; // 0x0004
};
class IPhysicsBody // vphysics2
{
};
class CNmPassthroughNode::CDefinition : public CNmPoseNode::CDefinition // animlib
{
	int16 m_nChildNodeIdx; // 0x0010
};
class CFootAdjustmentUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	CUtlVector< HSequence > m_clips; // 0x0078
	CPoseHandle m_hBasePoseCacheHandle; // 0x0090
	CAnimParamHandle m_facingTarget; // 0x0094
	float32 m_flTurnTimeMin; // 0x0098
	float32 m_flTurnTimeMax; // 0x009C
	float32 m_flStepHeightMax; // 0x00A0
	float32 m_flStepHeightMaxAngle; // 0x00A4
	bool m_bResetChild; // 0x00A8
	bool m_bAnimationDriven; // 0x00A9
};
class HSequence // animationsystem
{
	int32 m_Value; // 0x0000
};
class CAudioAnimTag : public CAnimTagBase // animgraphlib
{
	CUtlString m_clipName; // 0x0058
	CUtlString m_attachmentName; // 0x0060
	float32 m_flVolume; // 0x0068
	bool m_bStopWhenTagEnds; // 0x006C
	bool m_bStopWhenGraphEnds; // 0x006D
	bool m_bPlayOnServer; // 0x006E
	bool m_bPlayOnClient; // 0x006F
};
class C_OP_TwistAroundAxis : public CParticleFunctionForce // particles
{
	float32 m_fForceAmount; // 0x01E8
	Vector m_TwistAxis; // 0x01EC
	bool m_bLocalSpace; // 0x01F8
	int32 m_nControlPointNumber; // 0x01FC
};
class CParticleFunctionRenderer : public CParticleFunction // particles
{
	CParticleVisibilityInputs VisibilityInputs; // 0x01D8
	bool m_bCannotBeRefracted; // 0x0220
	bool m_bSkipRenderingOnMobile; // 0x0221
};
class C_INIT_PositionPlaceOnGround : public CParticleFunctionInitializer // particles
{
	CPerParticleFloatInput m_flOffset; // 0x01E0
	CPerParticleFloatInput m_flMaxTraceLength; // 0x0350
	CPerParticleVecInput m_vecTraceDir; // 0x04C0
	char[128] m_CollisionGroupName; // 0x0B78
	ParticleTraceSet_t m_nTraceSet; // 0x0BF8
	ParticleTraceMissBehavior_t m_nTraceMissBehavior; // 0x0C08
	bool m_bIncludeWater; // 0x0C0C
	ParticleAttributeIndex_t m_nAttribute; // 0x0C10
	bool m_bSetPXYZOnly; // 0x0C14
	bool m_bSetNormal; // 0x0C15
	ParticleAttributeIndex_t m_nGroundNormalAttribute; // 0x0C18
	bool m_bOffsetonColOnly; // 0x0C1C
	float32 m_flOffsetByRadiusFactor; // 0x0C20
	int32 m_nPreserveOffsetCP; // 0x0C24
	int32 m_nIgnoreCP; // 0x0C28
};
class C_INIT_AgeNoise : public CParticleFunctionInitializer // particles
{
	bool m_bAbsVal; // 0x01E0
	bool m_bAbsValInv; // 0x01E1
	float32 m_flOffset; // 0x01E4
	float32 m_flAgeMin; // 0x01E8
	float32 m_flAgeMax; // 0x01EC
	float32 m_flNoiseScale; // 0x01F0
	float32 m_flNoiseScaleLoc; // 0x01F4
	Vector m_vecOffsetLoc; // 0x01F8
};
class CModelConfigElement_SetRenderColor : public CModelConfigElement // modellib
{
	Color m_Color; // 0x0048
};
class CParticleFunctionForce : public CParticleFunction // particles
{
};
class C_OP_RampScalarSpline : public CParticleFunctionOperator // particles
{
	float32 m_RateMin; // 0x01D8
	float32 m_RateMax; // 0x01DC
	float32 m_flStartTime_min; // 0x01E0
	float32 m_flStartTime_max; // 0x01E4
	float32 m_flEndTime_min; // 0x01E8
	float32 m_flEndTime_max; // 0x01EC
	float32 m_flBias; // 0x01F0
	ParticleAttributeIndex_t m_nField; // 0x0220
	bool m_bProportionalOp; // 0x0224
	bool m_bEaseOut; // 0x0225
};
class CSoundEventMetaData // soundsystem
{
	CStrongHandle< InfoForResourceTypeCVMixListResource > m_soundEventVMix; // 0x0000
};
class CVoiceContainerStaticAdditiveSynth::CGainScalePerInstance // soundsystem_voicecontainers
{
	float32 m_flMinVolume; // 0x0000
	int32 m_nInstancesAtMinVolume; // 0x0004
	float32 m_flMaxVolume; // 0x0008
	int32 m_nInstancesAtMaxVolume; // 0x000C
};
class FeBuildBoxRigid_t : public FeBoxRigid_t // physicslib
{
	int32 m_nPriority; // 0x0040
	uint32 m_nVertexMapHash; // 0x0044
	uint32 m_nAntitunnelGroupBits; // 0x0048
};
class constraint_axislimit_t // vphysics2
{
	float32 flMinRotation; // 0x0000
	float32 flMaxRotation; // 0x0004
	float32 flMotorTargetAngSpeed; // 0x0008
	float32 flMotorMaxTorque; // 0x000C
};
class StanceInfo_t // animgraphlib
{
	Vector m_vPosition; // 0x0000
	float32 m_flDirection; // 0x000C
};
class CDemoSettingsComponentUpdater : public CAnimComponentUpdater // animgraphlib
{
	CAnimDemoCaptureSettings m_settings; // 0x0030
};
class IClientAlphaProperty // client
{
};
class CNavVolumeBreadthFirstSearch : public CNavVolumeCalculatedVector // server
{
	VectorWS m_vStartPos; // 0x00A8
	float32 m_flSearchDist; // 0x00B4
};
class AggregateInstanceStreamOnDiskData_t // worldrenderer
{
	uint32 m_DecodedSize; // 0x0000
	CUtlBinaryBlock m_BufferData; // 0x0008
};
class CAudioPhonemeTag // soundsystem_voicecontainers
{
	float32 m_flStartTime; // 0x0000
	float32 m_flEndTime; // 0x0004
	int32 m_nPhonemeCode; // 0x0008
};
class CNmCachedVectorNode::CDefinition : public CNmVectorValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
	NmCachedValueMode_t m_mode; // 0x0014
};
class IKSolverSettings_t // animgraphlib
{
	IKSolverType m_SolverType; // 0x0000
	int32 m_nNumIterations; // 0x0004
	EIKEndEffectorRotationFixUpMode m_EndEffectorRotationFixUpMode; // 0x0008
};
class InfoForResourceTypeCPanoramaDynamicImages // resourcesystem
{
};
class ConstraintSoundInfo // server
{
	VelocitySampler m_vSampler; // 0x0008
	SimpleConstraintSoundProfile m_soundProfile; // 0x0020
	Vector m_forwardAxis; // 0x0040
	CUtlSymbolLarge m_iszTravelSoundFwd; // 0x0050
	CUtlSymbolLarge m_iszTravelSoundBack; // 0x0058
	CUtlSymbolLarge m_iszReversalSoundSmall; // 0x0078
	CUtlSymbolLarge m_iszReversalSoundMedium; // 0x0080
	CUtlSymbolLarge m_iszReversalSoundLarge; // 0x0088
	bool m_bPlayTravelSound; // 0x0090
	bool m_bPlayReversalSound; // 0x0091
};
class C_OP_RemapSpeedtoCP : public CParticleFunctionPreEmission // particles
{
	int32 m_nInControlPointNumber; // 0x01E0
	int32 m_nOutControlPointNumber; // 0x01E4
	int32 m_nField; // 0x01E8
	float32 m_flInputMin; // 0x01EC
	float32 m_flInputMax; // 0x01F0
	float32 m_flOutputMin; // 0x01F4
	float32 m_flOutputMax; // 0x01F8
	bool m_bUseDeltaV; // 0x01FC
};
class C_INIT_CheckParticleForWater : public CParticleFunctionInitializer // particles
{
	CPerParticleFloatInput m_flRadius; // 0x01E0
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0350
	CParticleRemapFloatInput m_flOutputRemap; // 0x0358
	ParticleSetMethod_t m_nSetMethod; // 0x04C8
};
class CFeNamedJiggleBone // physicslib
{
	CUtlString m_strParentBone; // 0x0000
	CTransform m_transform; // 0x0010
	uint32 m_nJiggleParent; // 0x0030
	CFeJiggleBone m_jiggleBone; // 0x0034
};
class PulseRuntimeInvokeIndex_t // pulse_runtime_lib
{
	int32 m_Value; // 0x0000
};
class EventBugBug_t // engine2
{
};
class InfoForResourceTypeCNmSkeleton // resourcesystem
{
};
class CVMixVsndInput : public CVMixInputBase // soundsystem_lowlevel
{
	CUtlString m_defaultValue; // 0x0010
	int32 m_nProcessor; // 0x0018
};
class CNmAimCSNode::CDefinition : public CNmPassthroughNode::CDefinition // server
{
	int16 m_nVerticalAngleNodeIdx; // 0x0018
	int16 m_nHorizontalAngleNodeIdx; // 0x001A
	int16 m_nWeaponCategoryNodeIdx; // 0x001C
	int16 m_nWeaponTypeNodeIdx; // 0x001E
	int16 m_nWeaponActionNodeIdx; // 0x0020
	int16 m_nWeaponDropNodeIdx; // 0x0022
	int16 m_nIsDefusingNodeIdx; // 0x0024
	int16 m_nCrouchWeightNodeIdx; // 0x0026
	float32 m_flHandIKBlendInTimeSeconds; // 0x0028
	float32 m_flActionBlendTimeSeconds; // 0x002C
	float32 m_flPlantingBlendTimeSeconds; // 0x0030
};
class C_OP_OscillateScalarSimple : public CParticleFunctionOperator // particles
{
	float32 m_Rate; // 0x01D8
	float32 m_Frequency; // 0x01DC
	ParticleAttributeIndex_t m_nField; // 0x01E0
	float32 m_flOscMult; // 0x01E4
	float32 m_flOscAdd; // 0x01E8
};
class C_OP_SetParentControlPointsToChildCP : public CParticleFunctionPreEmission // particles
{
	int32 m_nChildGroupID; // 0x01E0
	int32 m_nChildControlPoint; // 0x01E4
	int32 m_nNumControlPoints; // 0x01E8
	int32 m_nFirstSourcePoint; // 0x01EC
	bool m_bSetOrientation; // 0x01F0
};
class C_INIT_RandomLifeTime : public CParticleFunctionInitializer // particles
{
	float32 m_fLifetimeMin; // 0x01E0
	float32 m_fLifetimeMax; // 0x01E4
	float32 m_fLifetimeRandExponent; // 0x01E8
};
class C_OP_SetRandomControlPointPosition : public CParticleFunctionPreEmission // particles
{
	bool m_bUseWorldLocation; // 0x01E0
	bool m_bOrient; // 0x01E1
	int32 m_nCP1; // 0x01E4
	int32 m_nHeadLocation; // 0x01E8
	CParticleCollectionFloatInput m_flReRandomRate; // 0x01F0
	Vector m_vecCPMinPos; // 0x0360
	Vector m_vecCPMaxPos; // 0x036C
	CParticleCollectionFloatInput m_flInterpolation; // 0x0378
};
class C_OP_ScreenSpaceDistanceToEdge : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	CPerParticleFloatInput m_flMaxDistFromEdge; // 0x01E0
	CParticleRemapFloatInput m_flOutputRemap; // 0x0350
	ParticleSetMethod_t m_nSetMethod; // 0x04C0
};
class C_OP_SetFloatCollection : public CParticleFunctionOperator // particles
{
	CParticleCollectionFloatInput m_InputValue; // 0x01D8
	ParticleAttributeIndex_t m_nOutputField; // 0x0348
	ParticleSetMethod_t m_nSetMethod; // 0x034C
	CParticleCollectionFloatInput m_Lerp; // 0x0350
};
class C_OP_ColorAdjustHSL : public CParticleFunctionOperator // particles
{
	CPerParticleFloatInput m_flHueAdjust; // 0x01D8
	CPerParticleFloatInput m_flSaturationAdjust; // 0x0348
	CPerParticleFloatInput m_flLightnessAdjust; // 0x04B8
};
class C_OP_SequenceFromModel : public CParticleFunctionOperator // particles
{
	int32 m_nControlPointNumber; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
	ParticleAttributeIndex_t m_nFieldOutputAnim; // 0x01E0
	float32 m_flInputMin; // 0x01E4
	float32 m_flInputMax; // 0x01E8
	float32 m_flOutputMin; // 0x01EC
	float32 m_flOutputMax; // 0x01F0
	ParticleSetMethod_t m_nSetMethod; // 0x01F4
};
class SceneViewId_t // scenesystem
{
	uint64 m_nViewId; // 0x0000
	uint64 m_nFrameCount; // 0x0008
};
class CSequenceGroupData // animationsystem
{
	CBufferString m_sName; // 0x0010
	uint32 m_nFlags; // 0x0020
	CUtlVector< CBufferString > m_localSequenceNameArray; // 0x0028
	CUtlVector< CSeqS1SeqDesc > m_localS1SeqDescArray; // 0x0040
	CUtlVector< CSeqS1SeqDesc > m_localMultiSeqDescArray; // 0x0058
	CUtlVector< CSeqSynthAnimDesc > m_localSynthAnimDescArray; // 0x0070
	CUtlVector< CSeqCmdSeqDesc > m_localCmdSeqDescArray; // 0x0088
	CUtlVector< CSeqBoneMaskList > m_localBoneMaskArray; // 0x00A0
	CUtlVector< CSeqScaleSet > m_localScaleSetArray; // 0x00B8
	CUtlVector< CBufferString > m_localBoneNameArray; // 0x00D0
	CBufferString m_localNodeName; // 0x00E8
	CUtlVector< CSeqPoseParamDesc > m_localPoseParamArray; // 0x00F8
	KeyValues3 m_keyValues; // 0x0110
	CUtlVector< CSeqIKLock > m_localIKAutoplayLockArray; // 0x0120
};
class EventClientProcessInput_t // engine2
{
	EngineLoopState_t m_LoopState; // 0x0000
	float32 m_flRealTime; // 0x0028
	float32 m_flTickInterval; // 0x002C
	float64 m_flTickStartTime; // 0x0030
};
class ActorMapping_t // server
{
	CUtlString m_sActorName; // 0x0000
	CHandle< CBaseEntity > m_hEntity; // 0x0008
};
class C_OP_Noise : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	float32 m_flOutputMin; // 0x01DC
	float32 m_flOutputMax; // 0x01E0
	float32 m_fl4NoiseScale; // 0x01E4
	bool m_bAdditive; // 0x01E8
	float32 m_flNoiseAnimationTimeScale; // 0x01EC
};
class CParticleFunctionInitializer : public CParticleFunction // particles
{
	int32 m_nAssociatedEmitterIndex; // 0x01D8
};
class CNmVectorNegateNode::CDefinition : public CNmVectorValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
};
class CSoundPatch // server
{
	CSoundEnvelope m_pitch; // 0x0008
	CSoundEnvelope m_volume; // 0x0018
	float32 m_shutdownTime; // 0x003C
	float32 m_flLastTime; // 0x0040
	CUtlSymbolLarge m_iszSoundScriptName; // 0x0048
	CHandle< CBaseEntity > m_hEnt; // 0x0050
	CEntityIndex m_soundEntityIndex; // 0x0054
	VectorWS m_soundOrigin; // 0x0058
	int32 m_isPlaying; // 0x0064
	CCopyRecipientFilter m_Filter; // 0x0068
	float32 m_flCloseCaptionDuration; // 0x00A0
	bool m_bUpdatedSoundOrigin; // 0x00A4
	CUtlSymbolLarge m_iszClassName; // 0x00A8
};
class C_INIT_VelocityFromCP : public CParticleFunctionInitializer // particles
{
	CParticleCollectionVecInput m_velocityInput; // 0x01E0
	CParticleTransformInput m_transformInput; // 0x0898
	float32 m_flVelocityScale; // 0x0900
	bool m_bDirectionOnly; // 0x0904
};
class C_OP_RemapVectortoCP : public CParticleFunctionOperator // particles
{
	int32 m_nOutControlPointNumber; // 0x01D8
	ParticleAttributeIndex_t m_nFieldInput; // 0x01DC
	int32 m_nParticleNumber; // 0x01E0
};
class C_INIT_ModelCull : public CParticleFunctionInitializer // particles
{
	int32 m_nControlPointNumber; // 0x01E0
	bool m_bBoundBox; // 0x01E4
	bool m_bCullOutside; // 0x01E5
	bool m_bUseBones; // 0x01E6
	char[128] m_HitboxSetName; // 0x01E7
};
class SceneObject_t // worldrenderer
{
	uint32 m_nObjectID; // 0x0000
	Vector4D[3] m_vTransform; // 0x0004
	float32 m_flFadeStartDistance; // 0x0034
	float32 m_flFadeEndDistance; // 0x0038
	Vector4D m_vTintColor; // 0x003C
	CUtlString m_skin; // 0x0050
	ObjectTypeFlags_t m_nObjectTypeFlags; // 0x0058
	Vector m_vLightingOrigin; // 0x005C
	int16 m_nOverlayRenderOrder; // 0x0068
	int16 m_nLODOverride; // 0x006A
	int32 m_nCubeMapPrecomputedHandshake; // 0x006C
	int32 m_nLightProbeVolumePrecomputedHandshake; // 0x0070
	CStrongHandle< InfoForResourceTypeCModel > m_renderableModel; // 0x0078
	CStrongHandle< InfoForResourceTypeCRenderMesh > m_renderable; // 0x0080
};
class RnCompoundDesc_t : public RnShapeDesc_t // physicslib
{
	RnCompound_t m_Compound; // 0x0018
};
class MaterialParamVector_t : public MaterialParam_t // materialsystem2
{
	Vector4D m_value; // 0x0008
};
class InfoForResourceTypeCCompositeMaterialKit // resourcesystem
{
};
class CPlayerSprayDecalRenderHelper // client
{
};
class AI_DefaultNPC_DebugSnapshotData_t::PathQuery_t // server
{
	CGlobalSymbol m_nInitialMovementId; // 0x0000
	CGlobalSymbol m_nCurrentMovementId; // 0x0008
	CGlobalSymbol m_nMode; // 0x0010
	CGlobalSymbol m_nType; // 0x0018
	CGlobalSymbol m_nState; // 0x0020
};
class C_INIT_RandomRotationSpeed : public CGeneralRandomRotation // particles
{
};
class ParticleControlPointDriver_t // particles
{
	ParticleParamID_t m_iControlPoint; // 0x0000
	ParticleAttachment_t m_iAttachType; // 0x0010
	CUtlString m_attachmentName; // 0x0018
	Vector m_vecOffset; // 0x0020
	QAngle m_angOffset; // 0x002C
	CUtlString m_entityName; // 0x0038
};
class C_OP_ExternalWindForce : public CParticleFunctionForce // particles
{
	CPerParticleVecInput m_vecSamplePosition; // 0x01E8
	CPerParticleVecInput m_vecScale; // 0x08A0
	bool m_bSampleWind; // 0x0F58
	bool m_bSampleWater; // 0x0F59
	bool m_bDampenNearWaterPlane; // 0x0F5A
	bool m_bSampleGravity; // 0x0F5B
	CPerParticleVecInput m_vecGravityForce; // 0x0F60
	bool m_bUseBasicMovementGravity; // 0x1618
	CPerParticleFloatInput m_flLocalGravityScale; // 0x1620
	CPerParticleFloatInput m_flLocalBuoyancyScale; // 0x1790
	CPerParticleVecInput m_vecBuoyancyForce; // 0x1900
};
class NodeData_t // worldrenderer
{
	int32 m_nParent; // 0x0000
	Vector m_vOrigin; // 0x0004
	Vector m_vMinBounds; // 0x0010
	Vector m_vMaxBounds; // 0x001C
	float32 m_flMinimumDistance; // 0x0028
	CUtlVector< int32 > m_ChildNodeIndices; // 0x0030
	CUtlString m_worldNodePrefix; // 0x0048
};
class FeNodeReverseOffset_t // physicslib
{
	Vector vOffset; // 0x0000
	uint16 nBoneCtrl; // 0x000C
	uint16 nTargetNode; // 0x000E
};
class CAnimationGraphInstance // animgraphlib
{
	bool m_bTagDispatchDirty; // 0x0329
};
class ParticleNamedValueConfiguration_t // particleslib
{
	CUtlString m_ConfigName; // 0x0000
	KeyValues3 m_ConfigValue; // 0x0008
	CUtlString m_BoundValuePath; // 0x0018
	ParticleAttachment_t m_iAttachType; // 0x0020
	CUtlString m_strEntityScope; // 0x0028
	CUtlString m_strAttachmentName; // 0x0030
};
class CDebugDrawHistoryData // server
{
	CHandle< CBaseEntity > m_hEntity; // 0x0000
	ESceneViewDebugOverlaysListenerDataType_t m_etype; // 0x0004
	CUtlLeanVector< Vector4D > m_vectors; // 0x0008
	CUtlLeanVector< Color > m_colors; // 0x0018
	CUtlLeanVector< float32 > m_dimensions; // 0x0028
	CUtlLeanVector< float64 > m_times; // 0x0038
	CUtlLeanVector< uint64 > m_uint64s; // 0x0048
	CUtlLeanVector< bool > m_bools; // 0x0058
	CUtlLeanVector< CUtlString > m_strings; // 0x0068
};
class CSimpleStopwatch : public CStopwatchBase // server
{
};
class CRandomNumberGeneratorParameters // particles
{
	bool m_bDistributeEvenly; // 0x0000
	int32 m_nSeed; // 0x0004
};
class C_OP_MovementRigidAttachToCP : public CParticleFunctionOperator // particles
{
	int32 m_nControlPointNumber; // 0x01D8
	int32 m_nScaleControlPoint; // 0x01DC
	int32 m_nScaleCPField; // 0x01E0
	ParticleAttributeIndex_t m_nFieldInput; // 0x01E4
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E8
	bool m_bOffsetLocal; // 0x01EC
};
class SamplerVoice_t // soundsystem
{
	uint8 nNoteNum; // 0x0000
};
class RnSphereDesc_t : public RnShapeDesc_t // physicslib
{
	RnSphere_t m_Sphere; // 0x0018
};
class CConstraintTarget // modellib
{
	Quaternion m_qOffset; // 0x0020
	Vector m_vOffset; // 0x0030
	uint32 m_nBoneHash; // 0x003C
	CUtlString m_sName; // 0x0040
	float32 m_flWeight; // 0x0048
	bool m_bIsAttachment; // 0x0059
};
class EntityIOQueuePrioritizedEvent_t // entity2
{
	GameTime_t m_flFireTime; // 0x0004
	EntityIOTargetType_t m_targetType; // 0x0008
	CUtlSymbolLarge m_pTarget; // 0x0010
	CUtlSymbolLarge m_pTargetInput; // 0x0018
	CEntityHandle m_hActivator; // 0x0020
	CEntityHandle m_hCaller; // 0x0024
	CEntityHandle m_hEntTarget; // 0x0028
	CVariantBase< CVariantDefaultAllocator > m_variantValue; // 0x0030
};
class EventModInitialized_t // engine2
{
};
class EventClientPollNetworking_t // engine2
{
	int32 m_nTickCount; // 0x0000
};
class InfoForResourceTypeCRenderMesh // resourcesystem
{
};
class CRangeInt // tier2
{
	int32[2] m_pValue; // 0x0000
};
class C_OP_ClientPhysics : public CParticleFunctionRenderer // particles
{
	CUtlString m_strPhysicsType; // 0x0228
	bool m_bStartAsleep; // 0x0230
	CParticleCollectionFloatInput m_flPlayerWakeRadius; // 0x0238
	CParticleCollectionFloatInput m_flVehicleWakeRadius; // 0x03A8
	bool m_bUseHighQualitySimulation; // 0x0518
	int32 m_nMaxParticleCount; // 0x051C
	bool m_bRespectExclusionVolumes; // 0x0520
	bool m_bKillParticles; // 0x0521
	bool m_bDeleteSim; // 0x0522
	int32 m_nControlPoint; // 0x0524
	int32 m_nForcedSimId; // 0x0528
	ParticleColorBlendType_t m_nColorBlendType; // 0x052C
	ParticleAttrBoxFlags_t m_nForcedStatusEffects; // 0x0530
	ParticleAttributeIndex_t m_nNoCollisionAttribute; // 0x0534
	ParticleAttributeIndex_t m_nZeroGravityAttribute; // 0x0538
};
class CNetworkVelocityVector // server
{
	CNetworkedQuantizedFloat m_vecX; // 0x0010
	CNetworkedQuantizedFloat m_vecY; // 0x0018
	CNetworkedQuantizedFloat m_vecZ; // 0x0020
};
class C_INIT_SetVectorAttributeToVectorExpression : public CParticleFunctionInitializer // particles
{
	VectorExpressionType_t m_nExpression; // 0x01E0
	CPerParticleVecInput m_vInput1; // 0x01E8
	CPerParticleVecInput m_vInput2; // 0x08A0
	CPerParticleFloatInput m_flLerp; // 0x0F58
	ParticleAttributeIndex_t m_nOutputField; // 0x10C8
	ParticleSetMethod_t m_nSetMethod; // 0x10CC
	bool m_bNormalizedOutput; // 0x10D0
};
class C_OP_OscillateVector : public CParticleFunctionOperator // particles
{
	Vector m_RateMin; // 0x01D8
	Vector m_RateMax; // 0x01E4
	Vector m_FrequencyMin; // 0x01F0
	Vector m_FrequencyMax; // 0x01FC
	ParticleAttributeIndex_t m_nField; // 0x0208
	bool m_bProportional; // 0x020C
	bool m_bProportionalOp; // 0x020D
	bool m_bOffset; // 0x020E
	float32 m_flStartTime_min; // 0x0210
	float32 m_flStartTime_max; // 0x0214
	float32 m_flEndTime_min; // 0x0218
	float32 m_flEndTime_max; // 0x021C
	CPerParticleFloatInput m_flOscMult; // 0x0220
	CPerParticleFloatInput m_flOscAdd; // 0x0390
	CPerParticleFloatInput m_flRateScale; // 0x0500
};
class C_OP_SetControlPointToCenter : public CParticleFunctionPreEmission // particles
{
	int32 m_nCP1; // 0x01E0
	Vector m_vecCP1Pos; // 0x01E4
	bool m_bUseAvgParticlePos; // 0x01F0
	ParticleParentSetMode_t m_nSetParent; // 0x01F4
};
class C_OP_PlanarConstraint : public CParticleFunctionConstraint // particles
{
	Vector m_PointOnPlane; // 0x01D8
	Vector m_PlaneNormal; // 0x01E4
	int32 m_nControlPointNumber; // 0x01F0
	bool m_bGlobalOrigin; // 0x01F4
	bool m_bGlobalNormal; // 0x01F5
	CPerParticleFloatInput m_flRadiusScale; // 0x01F8
	CParticleCollectionFloatInput m_flMaximumDistanceToCP; // 0x0368
	bool m_bUseOldCode; // 0x04D8
};
class CVoiceContainerStaticAdditiveSynth::CTone // soundsystem_voicecontainers
{
	CUtlVector< CVoiceContainerStaticAdditiveSynth::CHarmonic > m_harmonics; // 0x0000
	CPiecewiseCurve m_curve; // 0x0018
	bool m_bSyncInstances; // 0x0058
};
class LookData // animgraphlib
{
	CAnimNetVar< Vector > m_vLookTarget; // 0x0000
};
class CAnimDemoCaptureSettings // animgraphlib
{
	Vector2D m_vecErrorRangeSplineRotation; // 0x0000
	Vector2D m_vecErrorRangeSplineTranslation; // 0x0008
	Vector2D m_vecErrorRangeSplineScale; // 0x0010
	float32 m_flIkRotation_MaxSplineError; // 0x0018
	float32 m_flIkTranslation_MaxSplineError; // 0x001C
	Vector2D m_vecErrorRangeQuantizationRotation; // 0x0020
	Vector2D m_vecErrorRangeQuantizationTranslation; // 0x0028
	Vector2D m_vecErrorRangeQuantizationScale; // 0x0030
	float32 m_flIkRotation_MaxQuantizationError; // 0x0038
	float32 m_flIkTranslation_MaxQuantizationError; // 0x003C
	CUtlString m_baseSequence; // 0x0040
	int32 m_nBaseSequenceFrame; // 0x0048
	EDemoBoneSelectionMode m_boneSelectionMode; // 0x004C
	CUtlVector< BoneDemoCaptureSettings_t > m_bones; // 0x0050
	CUtlVector< IKDemoCaptureSettings_t > m_ikChains; // 0x0068
};
class EventClientPauseSimulate_t : public EventSimulate_t // engine2
{
};
class EventClientPreOutput_t // engine2
{
	EngineLoopState_t m_LoopState; // 0x0000
	float64 m_flRenderTime; // 0x0028
	float64 m_flRenderFrameTime; // 0x0030
	float64 m_flRenderFrameTimeUnbounded; // 0x0038
	float32 m_flRealTime; // 0x0040
	bool m_bRenderOnly; // 0x0044
};
class C_OP_RenderTrails : public CBaseTrailRenderer // particles
{
	bool m_bEnableFadingAndClamping; // 0x3258
	float32 m_flStartFadeDot; // 0x325C
	float32 m_flEndFadeDot; // 0x3260
	ParticleAttributeIndex_t m_nPrevPntSource; // 0x3264
	float32 m_flMaxLength; // 0x3268
	float32 m_flMinLength; // 0x326C
	bool m_bIgnoreDT; // 0x3270
	float32 m_flConstrainRadiusToLengthRatio; // 0x3274
	float32 m_flLengthScale; // 0x3278
	float32 m_flLengthFadeInTime; // 0x327C
	CPerParticleFloatInput m_flRadiusHeadTaper; // 0x3280
	CParticleCollectionVecInput m_vecHeadColorScale; // 0x33F0
	CPerParticleFloatInput m_flHeadAlphaScale; // 0x3AA8
	CPerParticleFloatInput m_flRadiusTaper; // 0x3C18
	CParticleCollectionVecInput m_vecTailColorScale; // 0x3D88
	CPerParticleFloatInput m_flTailAlphaScale; // 0x4440
	ParticleAttributeIndex_t m_nHorizCropField; // 0x45B0
	ParticleAttributeIndex_t m_nVertCropField; // 0x45B4
	float32 m_flForwardShift; // 0x45B8
	bool m_bFlipUVBasedOnPitchYaw; // 0x45BC
};
class CVMixAutomaticControlInput // soundsystem_lowlevel
{
	CUtlString m_name; // 0x0000
	int32 m_nControlInputIndex; // 0x0008
	bool m_bIsTrackSend; // 0x000C
	bool m_bIsStackVar; // 0x000D
};
class CNmClip // animlib
{
	CStrongHandle< InfoForResourceTypeCNmSkeleton > m_skeleton; // 0x0000
	uint32 m_nNumFrames; // 0x0008
	float32 m_flDuration; // 0x000C
	CUtlBinaryBlock m_compressedPoseData; // 0x0010
	CUtlVector< NmCompressionSettings_t > m_trackCompressionSettings; // 0x0020
	CUtlVector< uint32 > m_compressedPoseOffsets; // 0x0038
	CUtlVectorFixedGrowable< CNmClip*, 1 > m_secondaryAnimations; // 0x0078
	CUtlVectorFixedGrowable< CNmFloatChannelData*, 2 > m_floatChannelData; // 0x0098
	CNmSyncTrack m_syncTrack; // 0x00C0
	CNmRootMotionData m_rootMotion; // 0x0170
	bool m_bIsAdditive; // 0x01C0
	CUtlVector< CNmClip::ModelSpaceSamplingChainLink_t > m_modelSpaceSamplingChain; // 0x01C8
	CUtlVector< int32 > m_modelSpaceBoneSamplingIndices; // 0x01E0
};
class CBindPoseUpdateNode : public CLeafUpdateNode // animgraphlib
{
};
class LookAtOpFixedSettings_t // animgraphlib
{
	CAnimAttachment m_attachment; // 0x0000
	CAnimInputDamping m_damping; // 0x0080
	CUtlVector< LookAtBone_t > m_bones; // 0x0098
	float32 m_flYawLimit; // 0x00B0
	float32 m_flPitchLimit; // 0x00B4
	float32 m_flHysteresisInnerAngle; // 0x00B8
	float32 m_flHysteresisOuterAngle; // 0x00BC
	bool m_bRotateYawForward; // 0x00C0
	bool m_bMaintainUpDirection; // 0x00C1
	bool m_bTargetIsPosition; // 0x00C2
	bool m_bUseHysteresis; // 0x00C3
};
class CWayPointHelperUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	float32 m_flStartCycle; // 0x0074
	float32 m_flEndCycle; // 0x0078
	bool m_bOnlyGoals; // 0x007C
	bool m_bPreventOvershoot; // 0x007D
	bool m_bPreventUndershoot; // 0x007E
};
class C_OP_RemapTransformOrientationToRotations : public CParticleFunctionOperator // particles
{
	CParticleTransformInput m_TransformInput; // 0x01D8
	Vector m_vecRotation; // 0x0240
	bool m_bUseQuat; // 0x024C
	bool m_bWriteNormal; // 0x024D
};
class C_OP_SetFloatAttributeToVectorExpression : public CParticleFunctionOperator // particles
{
	VectorFloatExpressionType_t m_nExpression; // 0x01D8
	CPerParticleVecInput m_vInput1; // 0x01E0
	CPerParticleVecInput m_vInput2; // 0x0898
	CParticleRemapFloatInput m_flOutputRemap; // 0x0F50
	ParticleAttributeIndex_t m_nOutputField; // 0x10C0
	ParticleSetMethod_t m_nSetMethod; // 0x10C4
};
class C_OP_InheritFromPeerSystem : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	ParticleAttributeIndex_t m_nFieldInput; // 0x01DC
	int32 m_nIncrement; // 0x01E0
	int32 m_nGroupID; // 0x01E4
};
class CovMatrix3 // physicslib
{
	Vector m_vDiag; // 0x0000
	float32 m_flXY; // 0x000C
	float32 m_flXZ; // 0x0010
	float32 m_flYZ; // 0x0014
};
class JiggleBoneSettings_t // animgraphlib
{
	int32 m_nBoneIndex; // 0x0000
	float32 m_flSpringStrength; // 0x0004
	float32 m_flMaxTimeStep; // 0x0008
	float32 m_flDamping; // 0x000C
	Vector m_vBoundsMaxLS; // 0x0010
	Vector m_vBoundsMinLS; // 0x001C
	JiggleBoneSimSpace m_eSimSpace; // 0x0028
};
class CompositeMaterialMatchFilter_t // compositematerialslib
{
	CompositeMaterialMatchFilterType_t m_nCompositeMaterialMatchFilterType; // 0x0000
	CUtlString m_strMatchFilter; // 0x0008
	CUtlString m_strMatchValue; // 0x0010
	bool m_bPassWhenTrue; // 0x0018
};
class CEmptyGraphController : public CAnimGraphControllerBase // server
{
};
class IParticleCollection // particles
{
};
class C_OP_ConnectParentParticleToNearest : public CParticleFunctionOperator // particles
{
	int32 m_nFirstControlPoint; // 0x01D8
	int32 m_nSecondControlPoint; // 0x01DC
	bool m_bUseRadius; // 0x01E0
	CParticleCollectionFloatInput m_flRadiusScale; // 0x01E8
	CParticleCollectionFloatInput m_flParentRadiusScale; // 0x0358
};
class C_INIT_InheritFromParentParticles : public CParticleFunctionInitializer // particles
{
	float32 m_flScale; // 0x01E0
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01E4
	int32 m_nIncrement; // 0x01E8
	bool m_bRandomDistribution; // 0x01EC
	int32 m_nRandomSeed; // 0x01F0
};
class CSequenceFinishedAnimTag : public CAnimTagBase // animgraphlib
{
	CUtlString m_sequenceName; // 0x0058
};
class CVectorQuantizer // animgraphlib
{
	CUtlVector< float32 > m_centroidVectors; // 0x0000
	int32 m_nCentroids; // 0x0018
	int32 m_nDimensions; // 0x001C
};
class CNmScaleNode::CDefinition : public CNmPassthroughNode::CDefinition // animlib
{
	int16 m_nMaskNodeIdx; // 0x0018
	int16 m_nEnableNodeIdx; // 0x001A
};
class ParamSpanSample_t // animgraphlib
{
	CAnimVariant m_value; // 0x0000
	float32 m_flCycle; // 0x0014
};
class EventClientPostAdvanceTick_t : public EventPostAdvanceTick_t // engine2
{
};
class CodeGenAABB_t // server
{
	Vector m_vMinBounds; // 0x0000
	Vector m_vMaxBounds; // 0x000C
};
class CInfoChoreoAnchorPosition // server
{
	Vector m_vOriginLS; // 0x0000
	Quaternion m_qAnglesLS; // 0x0010
	Vector m_vExtentsMin; // 0x0020
	Vector m_vExtentsMax; // 0x002C
	float32 m_flRadius; // 0x0038
	bool m_bOnlyWarpPosition; // 0x003C
	CHandle< CBaseEntity > m_hParent; // 0x0040
	CInfoChoreoLocatorShapeType_t m_nShapeType; // 0x0044
};
class CSkillInt // server
{
	int32[4] m_pValue; // 0x0000
};
class CVectorExponentialMovingAverage // server
{
};
class AI_DefaultNPC_DebugSnapshotData_t : public DebugSnapshotBaseStructuredData_t // server
{
	CGlobalSymbol s_npc_current_ability; // 0x0008
	CGlobalSymbol s_npc_tactic_current; // 0x0010
	CGlobalSymbol s_npc_tactic_phase; // 0x0018
	CUtlVector< CGlobalSymbol > tactic_interrupt_conditions; // 0x0020
	AI_DefaultNPC_DebugSnapshotData_t::PathQuery_t path_query; // 0x0038
	CUtlVector< AI_DefaultNPC_DebugSnapshotData_t::PathQuery_t > path_queries_speculative; // 0x0060
};
class C_OP_CPVelocityForce : public CParticleFunctionForce // particles
{
	int32 m_nControlPointNumber; // 0x01E8
	CPerParticleFloatInput m_flScale; // 0x01F0
};
class CNmClip::ModelSpaceSamplingChainLink_t // animlib
{
	int32 m_nBoneIdx; // 0x0000
	int32 m_nParentBoneIdx; // 0x0004
	int32 m_nParentChainLinkIdx; // 0x0008
};
class CAnimScriptComponentUpdater : public CAnimComponentUpdater // animgraphlib
{
	AnimScriptHandle m_hScript; // 0x0030
};
class CDestructiblePart_DamageLevel // server
{
	CUtlString m_sName; // 0x0000
	CGlobalSymbol m_sBreakablePieceName; // 0x0008
	int32 m_nBodyGroupValue; // 0x0010
	CSkillInt m_nHealth; // 0x0014
	float32 m_flCriticalDamagePercent; // 0x0024
	EDestructiblePartDamagePassThroughType m_nDamagePassthroughType; // 0x0028
	DestructiblePartDestructionDeathBehavior_t m_nDestructionDeathBehavior; // 0x002C
	CGlobalSymbol m_sCustomDeathHandshake; // 0x0030
	bool m_bShouldDestroyOnDeath; // 0x0038
	CRangeFloat m_flDeathDestroyTime; // 0x003C
};
class FeBuildTaperedCapsuleRigid_t : public FeTaperedCapsuleRigid_t // physicslib
{
	int32 m_nPriority; // 0x0030
	uint32 m_nVertexMapHash; // 0x0034
	uint32 m_nAntitunnelGroupBits; // 0x0038
};
class CDampedPathAnimMotorUpdater : public CPathAnimMotorUpdaterBase // animgraphlib
{
	float32 m_flAnticipationTime; // 0x002C
	float32 m_flMinSpeedScale; // 0x0030
	CAnimParamHandle m_hAnticipationPosParam; // 0x0034
	CAnimParamHandle m_hAnticipationHeadingParam; // 0x0036
	float32 m_flSpringConstant; // 0x0038
	float32 m_flMinSpringTension; // 0x003C
	float32 m_flMaxSpringTension; // 0x0040
};
class CPulse_PublicOutput // pulse_runtime_lib
{
	PulseSymbol_t m_Name; // 0x0000
	CUtlString m_Description; // 0x0010
	CUtlLeanVector< CPulseRuntimeMethodArg > m_Args; // 0x0018
};
class CPhysSurfaceProperties // modellib
{
	CUtlString m_name; // 0x0000
	uint32 m_nameHash; // 0x0008
	uint32 m_baseNameHash; // 0x000C
	bool m_bHidden; // 0x0018
	CUtlString m_description; // 0x0020
	CPhysSurfacePropertiesPhysics m_physics; // 0x0028
	CPhysSurfacePropertiesVehicle m_vehicleParams; // 0x0040
	CPhysSurfacePropertiesSoundNames m_audioSounds; // 0x0048
	CPhysSurfacePropertiesAudio m_audioParams; // 0x00A8
};
class CBlendUpdateNode : public CAnimUpdateNodeBase // animgraphlib
{
	CUtlVector< CAnimUpdateNodeRef > m_children; // 0x0060
	CUtlVector< uint8 > m_sortedOrder; // 0x0078
	CUtlVector< float32 > m_targetValues; // 0x0090
	AnimValueSource m_blendValueSource; // 0x00AC
	LinearRootMotionBlendMode_t m_eLinearRootMotionBlendMode; // 0x00B0
	CAnimParamHandle m_paramIndex; // 0x00B4
	CAnimInputDamping m_damping; // 0x00B8
	BlendKeyType m_blendKeyType; // 0x00D0
	bool m_bLockBlendOnReset; // 0x00D4
	bool m_bSyncCycles; // 0x00D5
	bool m_bLoop; // 0x00D6
	bool m_bLockWhenWaning; // 0x00D7
	bool m_bIsAngle; // 0x00D8
};
class EventServerEndSimulate_t // engine2
{
	bool m_bLastTick; // 0x0000
};
class inv_image_item_t // client
{
	Vector position; // 0x0000
	QAngle angle; // 0x000C
	CUtlString pose_sequence; // 0x0018
};
class C_OP_RemapTransformVisibilityToVector : public CParticleFunctionOperator // particles
{
	ParticleSetMethod_t m_nSetMethod; // 0x01D8
	CParticleTransformInput m_TransformInput; // 0x01E0
	ParticleAttributeIndex_t m_nFieldOutput; // 0x0248
	float32 m_flInputMin; // 0x024C
	float32 m_flInputMax; // 0x0250
	Vector m_vecOutputMin; // 0x0254
	Vector m_vecOutputMax; // 0x0260
	float32 m_flRadius; // 0x026C
};
class C_OP_RenderStatusEffect : public CParticleFunctionRenderer // particles
{
	CStrongHandle< InfoForResourceTypeCTextureBase > m_pTextureColorWarp; // 0x0228
	CStrongHandle< InfoForResourceTypeCTextureBase > m_pTextureDetail2; // 0x0230
	CStrongHandle< InfoForResourceTypeCTextureBase > m_pTextureDiffuseWarp; // 0x0238
	CStrongHandle< InfoForResourceTypeCTextureBase > m_pTextureFresnelColorWarp; // 0x0240
	CStrongHandle< InfoForResourceTypeCTextureBase > m_pTextureFresnelWarp; // 0x0248
	CStrongHandle< InfoForResourceTypeCTextureBase > m_pTextureSpecularWarp; // 0x0250
	CStrongHandle< InfoForResourceTypeCTextureBase > m_pTextureEnvMap; // 0x0258
};
class FeSimdRodConstraint_t // physicslib
{
	uint16[4][2] nNode; // 0x0000
	fltx4 f4MaxDist; // 0x0010
	fltx4 f4MinDist; // 0x0020
	fltx4 f4Weight0; // 0x0030
	fltx4 f4RelaxationFactor; // 0x0040
};
class CBonePositionMetricEvaluator : public CMotionMetricEvaluator // animgraphlib
{
	int32 m_nBoneIndex; // 0x0050
};
class CNmEntityAttributeFloatEvent : public CNmEntityAttributeEventBase // animlib
{
	CPiecewiseCurve m_FloatValue; // 0x0038
};
class CFootTrajectories // modellib
{
	CUtlVector< CFootTrajectory > m_trajectories; // 0x0000
};
class ChangeAccessorFieldPathIndex_t // networksystem
{
	int32 m_Value; // 0x0000
};
class SAVE_HEADER // server
{
	int32 m_saveId; // 0x0000
	int32 m_version; // 0x0004
	int32 m_nConnectionCount; // 0x0008
	int32 m_nMapVersion; // 0x000C
	CUtlString m_sSpawnGroupName; // 0x0010
	matrix3x4a_t m_vecWorldOffset; // 0x0020
	float32 m_flSaveTime; // 0x0050
};
class GameAmmoTypeInfo_t : public AmmoTypeInfo_t // server
{
	int32 m_nBuySize; // 0x0038
	int32 m_nCost; // 0x003C
};
class C_INIT_ColorLitPerParticle : public CParticleFunctionInitializer // particles
{
	Color m_ColorMin; // 0x01F8
	Color m_ColorMax; // 0x01FC
	Color m_TintMin; // 0x0200
	Color m_TintMax; // 0x0204
	float32 m_flTintPerc; // 0x0208
	ParticleColorBlendMode_t m_nTintBlendMode; // 0x020C
	float32 m_flLightAmplification; // 0x0210
};
class C_OP_DampenToCP : public CParticleFunctionOperator // particles
{
	int32 m_nControlPointNumber; // 0x01D8
	float32 m_flRange; // 0x01DC
	float32 m_flScale; // 0x01E0
};
class C_OP_LerpVector : public CParticleFunctionOperator // particles
{
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01D8
	Vector m_vecOutput; // 0x01DC
	float32 m_flStartTime; // 0x01E8
	float32 m_flEndTime; // 0x01EC
	ParticleSetMethod_t m_nSetMethod; // 0x01F0
};
class CNmGraphDefinition::ExternalGraphSlot_t // animlib
{
	int16 m_nNodeIdx; // 0x0000
	CGlobalSymbol m_slotID; // 0x0008
};
class CAimConstraint : public CBaseConstraint // modellib
{
	Quaternion m_qAimOffset; // 0x0060
	uint32 m_nUpType; // 0x0070
};
class CStringAnimTag : public CAnimTagBase // animgraphlib
{
};
class CRagdollAnimTag : public CAnimTagBase // animgraphlib
{
	CGlobalSymbol m_profileName; // 0x0058
};
class C_OP_RenderRopes : public CBaseRendererSource2 // particles
{
	bool m_bEnableFadingAndClamping; // 0x2DF0
	float32 m_flMinSize; // 0x2DF4
	float32 m_flMaxSize; // 0x2DF8
	float32 m_flStartFadeSize; // 0x2DFC
	float32 m_flEndFadeSize; // 0x2E00
	float32 m_flStartFadeDot; // 0x2E04
	float32 m_flEndFadeDot; // 0x2E08
	CParticleCollectionRendererFloatInput m_flSubPixelAAScale; // 0x2E10
	float32 m_flRadiusTaper; // 0x2F80
	int32 m_nMinTesselation; // 0x2F84
	int32 m_nMaxTesselation; // 0x2F88
	float32 m_flTessScale; // 0x2F8C
	CParticleCollectionRendererFloatInput m_flTextureVWorldSize; // 0x2F90
	CParticleCollectionRendererFloatInput m_flTextureVScrollRate; // 0x3100
	CParticleCollectionRendererFloatInput m_flTextureVOffset; // 0x3270
	int32 m_nTextureVParamsCP; // 0x33E0
	bool m_bClampV; // 0x33E4
	int32 m_nScaleCP1; // 0x33E8
	int32 m_nScaleCP2; // 0x33EC
	float32 m_flScaleVSizeByControlPointDistance; // 0x33F0
	float32 m_flScaleVScrollByControlPointDistance; // 0x33F4
	float32 m_flScaleVOffsetByControlPointDistance; // 0x33F8
	bool m_bUseScalarForTextureCoordinate; // 0x33FD
	ParticleAttributeIndex_t m_nScalarFieldForTextureCoordinate; // 0x3400
	float32 m_flScalarAttributeTextureCoordScale; // 0x3404
	bool m_bReverseOrder; // 0x3408
	bool m_bClosedLoop; // 0x3409
	ParticleAttributeIndex_t m_nSplitField; // 0x340C
	bool m_bSortBySegmentID; // 0x3410
	ParticleOrientationChoiceList_t m_nOrientationType; // 0x3414
	ParticleAttributeIndex_t m_nVectorFieldForOrientation; // 0x3418
	bool m_bDrawAsOpaque; // 0x341C
	bool m_bGenerateNormals; // 0x341D
};
class CParticleVisibilityInputs // particles
{
	float32 m_flCameraBias; // 0x0000
	int32 m_nCPin; // 0x0004
	float32 m_flProxyRadius; // 0x0008
	float32 m_flInputMin; // 0x000C
	float32 m_flInputMax; // 0x0010
	float32 m_flInputPixelVisFade; // 0x0014
	float32 m_flNoPixelVisibilityFallback; // 0x0018
	float32 m_flDistanceInputMin; // 0x001C
	float32 m_flDistanceInputMax; // 0x0020
	float32 m_flDotInputMin; // 0x0024
	float32 m_flDotInputMax; // 0x0028
	bool m_bDotCPAngles; // 0x002C
	bool m_bDotCameraAngles; // 0x002D
	float32 m_flAlphaScaleMin; // 0x0030
	float32 m_flAlphaScaleMax; // 0x0034
	float32 m_flRadiusScaleMin; // 0x0038
	float32 m_flRadiusScaleMax; // 0x003C
	float32 m_flRadiusScaleFOVBase; // 0x0040
	bool m_bRightEye; // 0x0044
};
class BoneDemoCaptureSettings_t // animgraphlib
{
	CUtlString m_boneName; // 0x0000
	float32 m_flErrorSplineRotationMax; // 0x0008
	float32 m_flErrorSplineTranslationMax; // 0x000C
	float32 m_flErrorSplineScaleMax; // 0x0010
	float32 m_flErrorQuantizationRotationMax; // 0x0014
	float32 m_flErrorQuantizationTranslationMax; // 0x0018
	float32 m_flErrorQuantizationScaleMax; // 0x001C
};
class SolveIKChainPoseOpFixedSettings_t // animgraphlib
{
	CUtlVector< ChainToSolveData_t > m_ChainsToSolveData; // 0x0000
};
class CBodyGroupAnimTag : public CAnimTagBase // animgraphlib
{
	int32 m_nPriority; // 0x0058
	CUtlVector< CBodyGroupSetting > m_bodyGroupSettings; // 0x0060
};
class EventClientAdvanceTick_t : public EventAdvanceTick_t // engine2
{
};
class InfoForResourceTypeCMorphSetData // resourcesystem
{
};
class TimedEvent // client
{
	float32 m_TimeBetweenEvents; // 0x0000
	float32 m_fNextEvent; // 0x0004
};
class DynamicVolumeDef_t // server
{
	CHandle< CBaseEntity > m_source; // 0x0000
	CHandle< CBaseEntity > m_target; // 0x0004
	int32 m_nHullIdx; // 0x0008
	VectorWS m_vSourceAnchorPos; // 0x000C
	VectorWS m_vTargetAnchorPos; // 0x0018
	uint32 m_nAreaSrc; // 0x0024
	uint32 m_nAreaDst; // 0x0028
	bool m_bAttached; // 0x002C
};
class ragdollhierarchyjoint_t // server
{
	int32 parentIndex; // 0x0000
	int32 childIndex; // 0x0004
};
class CFiringModeInt // server
{
	int32[2] m_nValues; // 0x0000
};
class CSteamAudioProbeLineSegment // steamaudio
{
	Vector m_vStart; // 0x0000
	Vector m_vEnd; // 0x000C
	CUtlVector< float32 > m_vecIntervals; // 0x0018
	CUtlVector< int32 > m_vecProbeIndices; // 0x0030
};
class CVoiceContainerBlender : public CVoiceContainerBase // soundsystem_voicecontainers
{
	CSoundContainerReference m_firstSound; // 0x0070
	CSoundContainerReference m_secondSound; // 0x0090
	float32 m_flBlendFactor; // 0x00B0
};
class CSosGroupActionSoundeventClusterSchema : public CSosGroupActionSchema // soundsystem
{
	int32 m_nMinNearby; // 0x0008
	float32 m_flClusterEpsilon; // 0x000C
	CUtlString m_shouldPlayOpvar; // 0x0010
	CUtlString m_shouldPlayClusterChild; // 0x0018
	CUtlString m_clusterSizeOpvar; // 0x0020
	CUtlString m_groupBoundingBoxMinsOpvar; // 0x0028
	CUtlString m_groupBoundingBoxMaxsOpvar; // 0x0030
};
class CVMixCurveHeader // soundsystem_lowlevel
{
	uint32 m_nControlPointCount; // 0x0000
	uint32 m_nControlPointStart; // 0x0004
};
class CVoiceContainerEnum : public CVoiceContainerBase // soundsystem_voicecontainers
{
	CSoundContainerReferenceArray m_soundsToPlay; // 0x0070
	int32 m_iSelection; // 0x00A8
	float32 m_flCrossfadeTime; // 0x00AC
};
class CNmIsTargetSetNode::CDefinition : public CNmBoolValueNode::CDefinition // animlib
{
	int16 m_nInputValueNodeIdx; // 0x0010
};
class TwoBoneIKSettings_t // animgraphlib
{
	IkEndEffectorType m_endEffectorType; // 0x0000
	CAnimAttachment m_endEffectorAttachment; // 0x0010
	IkTargetType m_targetType; // 0x0090
	CAnimAttachment m_targetAttachment; // 0x00A0
	int32 m_targetBoneIndex; // 0x0120
	CAnimParamHandle m_hPositionParam; // 0x0124
	CAnimParamHandle m_hRotationParam; // 0x0126
	bool m_bAlwaysUseFallbackHinge; // 0x0128
	VectorAligned m_vLsFallbackHingeAxis; // 0x0130
	int32 m_nFixedBoneIndex; // 0x0140
	int32 m_nMiddleBoneIndex; // 0x0144
	int32 m_nEndBoneIndex; // 0x0148
	bool m_bMatchTargetOrientation; // 0x014C
	bool m_bConstrainTwist; // 0x014D
	float32 m_flMaxTwist; // 0x0150
};
class CModelConfigElement_AttachedModel : public CModelConfigElement // modellib
{
	CUtlString m_InstanceName; // 0x0048
	CUtlString m_EntityClass; // 0x0050
	CStrongHandle< InfoForResourceTypeCModel > m_hModel; // 0x0058
	Vector m_vOffset; // 0x0060
	QAngle m_aAngOffset; // 0x006C
	CUtlString m_AttachmentName; // 0x0078
	CUtlString m_LocalAttachmentOffsetName; // 0x0080
	ModelConfigAttachmentType_t m_AttachmentType; // 0x0088
	bool m_bBoneMergeFlex; // 0x008C
	bool m_bUserSpecifiedColor; // 0x008D
	bool m_bUserSpecifiedMaterialGroup; // 0x008E
	CUtlString m_BodygroupOnOtherModels; // 0x0090
	CUtlString m_MaterialGroupOnOtherModels; // 0x0098
};
class CompositeMaterialAssemblyProcedure_t // compositematerialslib
{
	CUtlVector< CResourceNameTyped< CWeakHandle< InfoForResourceTypeCCompositeMaterialKit > > > m_vecCompMatIncludes; // 0x0000
	CUtlVector< CompositeMaterialMatchFilter_t > m_vecMatchFilters; // 0x0018
	CUtlVector< CompositeMaterialInputContainer_t > m_vecCompositeInputContainers; // 0x0030
	CUtlVector< CompMatPropertyMutator_t > m_vecPropertyMutators; // 0x0048
};
class screenfade_t // client
{
	float32 Speed; // 0x0000
	float32 End; // 0x0004
	float32 Reset; // 0x0008
	Color m_Color; // 0x000C
	int32 Flags; // 0x0010
};
class CVectorMovingAverage // server
{
};
class C_OP_RemapDensityGradientToVectorAttribute : public CParticleFunctionOperator // particles
{
	float32 m_flRadiusScale; // 0x01D8
	ParticleAttributeIndex_t m_nFieldOutput; // 0x01DC
};
class C_OP_RopeSpringConstraint : public CParticleFunctionConstraint // particles
{
	CParticleCollectionFloatInput m_flRestLength; // 0x01D8
	CParticleCollectionFloatInput m_flMinDistance; // 0x0348
	CParticleCollectionFloatInput m_flMaxDistance; // 0x04B8
	float32 m_flAdjustmentScale; // 0x0628
	CParticleCollectionFloatInput m_flInitialRestingLength; // 0x0630
};
class IPhysicsJoint // vphysics2
{
};
class FeSpringIntegrator_t // physicslib
{
	uint16[2] nNode; // 0x0000
	float32 flSpringRestLength; // 0x0004
	float32 flSpringConstant; // 0x0008
	float32 flSpringDamping; // 0x000C
	float32 flNodeWeight0; // 0x0010
};
class PerTickSettings_t // animgraphlib
{
	CTransform m_startingLocalToWorld; // 0x0000
	CTransform m_prevLocalToWorld; // 0x0020
	CTransform m_finalLocalToWorld; // 0x0040
	CRootMotion m_rootMotion; // 0x0060
	int32 m_updateID; // 0x069C
	float32 m_flLastTimeStep; // 0x06A4
	float32 m_flPrevAnimTime; // 0x06A8
	float32 m_flNextAnimTime; // 0x06AC
	bool m_bAwaken; // 0x06B4
	bool m_bTeleported; // 0x06B5
	bool m_bIsClient; // 0x06B6
	bool m_bIsPredicted; // 0x06B7
};
class CChoreoInstanceData // animgraphlib
{
	CAnimationLayer[12] m_AnimOverlay; // 0x0000
};
class CFollowPathUpdateNode : public CUnaryUpdateNode // animgraphlib
{
	float32 m_flBlendOutTime; // 0x0074
	bool m_bBlockNonPathMovement; // 0x0078
	bool m_bStopFeetAtGoal; // 0x0079
	bool m_bScaleSpeed; // 0x007A
	float32 m_flScale; // 0x007C
	float32 m_flMinAngle; // 0x0080
	float32 m_flMaxAngle; // 0x0084
	float32 m_flSpeedScaleBlending; // 0x0088
	CAnimInputDamping m_turnDamping; // 0x0090
	AnimValueSource m_facingTarget; // 0x00A8
	CAnimParamHandle m_hParam; // 0x00AC
	float32 m_flTurnToFaceOffset; // 0x00B0
	bool m_bTurnToFace; // 0x00B4
};
class CEntityInstance // entity2
{
	CUtlSymbolLarge m_iszPrivateVScripts; // 0x0008
	CEntityIdentity* m_pEntity; // 0x0010
	CScriptComponent* m_CScriptComponent; // 0x0028
};
class CEntityComponent // entity2
{
};
class CScriptComponent : public CEntityComponent // entity2
{
	CUtlSymbolLarge m_scriptClassName; // 0x0030
};
class CEntityIdentity // entity2
{
	int32 m_nameStringTableIndex; // 0x0014
	CUtlSymbolLarge m_name; // 0x0018
	CUtlSymbolLarge m_designerName; // 0x0020
	uint32 m_flags; // 0x0030
	WorldGroupId_t m_worldGroupId; // 0x0038
	uint32 m_fDataObjectTypes; // 0x003C
	ChangeAccessorFieldPathIndex_t m_PathIndex; // 0x0040
	CEntityAttributeTable* m_pAttributes; // 0x0048
	CEntityIdentity* m_pPrev; // 0x0050
	CEntityIdentity* m_pNext; // 0x0058
	CEntityIdentity* m_pPrevByClass; // 0x0060
	CEntityIdentity* m_pNextByClass; // 0x0068
};
class CPulseCell_WaitForCursorsWithTag : public CPulseCell_WaitForCursorsWithTagBase // pulse_runtime_lib
{
	bool m_bTagSelfWhenComplete; // 0x0128
	PulseCursorCancelPriority_t m_nDesiredKillPriority; // 0x012C
};
class CPulseCell_Base // pulse_runtime_lib
{
	PulseDocNodeID_t m_nEditorNodeID; // 0x0008
};
class CPulse_ResumePoint : public CPulse_OutflowConnection // pulse_runtime_lib
{
};
class CPulseCell_PickBestOutflowSelector : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseBestOutflowRules_t m_nCheckType; // 0x0048
	PulseSelectorOutflowList_t m_OutflowList; // 0x0050
};
class CParticleBindingRealPulse : public CParticleCollectionBindingInstance // particleslib
{
};
class CPulseCell_WaitForObservable : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulseObservableExpression< bool > m_Condition; // 0x00D8
	CPulse_ResumePoint m_OnTrue; // 0x0150
};
class CPulse_OutflowConnection // pulse_runtime_lib
{
	PulseSymbol_t m_SourceOutflowName; // 0x0000
	PulseRuntimeChunkIndex_t m_nDestChunk; // 0x0010
	int32 m_nInstruction; // 0x0014
	PulseRegisterMap_t m_OutflowRegisterMap; // 0x0018
};
class CPulseGraphDef // pulse_runtime_lib
{
	PulseSymbol_t m_DomainIdentifier; // 0x0008
	CPulseValueFullType m_DomainSubType; // 0x0018
	PulseSymbol_t m_ParentMapName; // 0x0030
	PulseSymbol_t m_ParentXmlName; // 0x0040
	CUtlVector< CPulse_Chunk* > m_Chunks; // 0x0050
	CUtlVector< CPulseCell_Base* > m_Cells; // 0x0068
	CUtlVector< CPulse_Variable > m_Vars; // 0x0080
	CUtlVector< CPulse_PublicOutput > m_PublicOutputs; // 0x0098
	CUtlVector< CPulse_InvokeBinding* > m_InvokeBindings; // 0x00B0
	CUtlVector< CPulse_CallInfo* > m_CallInfos; // 0x00C8
	CUtlVector< CPulse_Constant > m_Constants; // 0x00E0
	CUtlVector< CPulse_DomainValue > m_DomainValues; // 0x00F8
	CUtlVector< CPulse_BlackboardReference > m_BlackboardReferences; // 0x0110
	CUtlVector< CPulse_OutputConnection* > m_OutputConnections; // 0x0128
};
class CPulseCell_FireCursors : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outflows; // 0x00D8
	bool m_bWaitForChildOutflows; // 0x00F0
	CPulse_ResumePoint m_OnFinished; // 0x00F8
};
class CPulseCell_Timeline::TimelineEvent_t // pulse_runtime_lib
{
	float32 m_flTimeFromPrevious; // 0x0000
	CPulse_OutflowConnection m_EventOutflow; // 0x0008
};
class CPulseCell_IntervalTimer::CursorState_t // pulse_runtime_lib
{
	GameTime_t m_StartTime; // 0x0000
	GameTime_t m_EndTime; // 0x0004
	float32 m_flWaitInterval; // 0x0008
	float32 m_flWaitIntervalHigh; // 0x000C
	bool m_bCompleteOnNextWake; // 0x0010
};
class CPulseCell_BaseRequirement : public CPulseCell_Base // pulse_runtime_lib
{
};
class CPulseCell_BaseState : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
};
class OutflowWithRequirements_t // pulse_runtime_lib
{
	CPulse_OutflowConnection m_Connection; // 0x0000
	PulseDocNodeID_t m_DestinationFlowNodeID; // 0x0048
	CUtlVector< PulseDocNodeID_t > m_RequirementNodeIDs; // 0x0050
	CUtlVector< int32 > m_nCursorStateBlockIndex; // 0x0068
};
class CPulseCell_IsRequirementValid : public CPulseCell_BaseRequirement // pulse_runtime_lib
{
};
class CPulseCell_Value_Gradient : public CPulseCell_BaseValue // pulse_runtime_lib
{
	CColorGradient m_Gradient; // 0x0048
};
class CPulseCursorFuncs // pulse_runtime_lib
{
};
class PulseNodeDynamicOutflows_t::DynamicOutflow_t // pulse_runtime_lib
{
	CGlobalSymbol m_OutflowID; // 0x0000
	CPulse_OutflowConnection m_Connection; // 0x0008
};
class CBasePulseGraphInstance // pulse_runtime_lib
{
};
class CPulseCell_Inflow_GraphHook : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_HookName; // 0x0080
};
class SignatureOutflow_Resume : public CPulse_ResumePoint // pulse_runtime_lib
{
};
class CPulseCell_Inflow_BaseEntrypoint : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseRuntimeChunkIndex_t m_EntryChunk; // 0x0048
	PulseRegisterMap_t m_RegisterMap; // 0x0050
};
class CPulseCell_WaitForCursorsWithTagBase : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	int32 m_nCursorsAllowedToWait; // 0x00D8
	CPulse_ResumePoint m_WaitComplete; // 0x00E0
};
class CPulse_InvokeBinding // pulse_runtime_lib
{
	PulseRegisterMap_t m_RegisterMap; // 0x0000
	PulseSymbol_t m_FuncName; // 0x0030
	PulseRuntimeCellIndex_t m_nCellIndex; // 0x0040
	PulseRuntimeChunkIndex_t m_nSrcChunk; // 0x0044
	int32 m_nSrcInstruction; // 0x0048
};
class CPulseCell_IntervalTimer : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_Completed; // 0x00D8
	SignatureOutflow_Continue m_OnInterval; // 0x0120
};
class CPulseTestScriptLib // pulse_runtime_lib
{
};
class CPulseCell_BaseLerp : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_WakeResume; // 0x00D8
};
class CPulseCell_Value_Curve : public CPulseCell_BaseValue // pulse_runtime_lib
{
	CPiecewiseCurve m_Curve; // 0x0048
};
class CPulseCell_Inflow_EventHandler : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_EventName; // 0x0080
};
class CPulseCell_BaseFlow : public CPulseCell_Base // pulse_runtime_lib
{
};
class CPulseCell_Outflow_CycleShuffled::InstanceState_t // pulse_runtime_lib
{
	CUtlVectorFixedGrowable< uint8, 8 > m_Shuffle; // 0x0000
	int32 m_nNextShuffle; // 0x0020
};
class CPulseCell_BaseLerp::CursorState_t // pulse_runtime_lib
{
	GameTime_t m_StartTime; // 0x0000
	GameTime_t m_EndTime; // 0x0004
};
class CPulseArraylib // pulse_runtime_lib
{
};
class SignatureOutflow_Continue : public CPulse_OutflowConnection // pulse_runtime_lib
{
};
class CPulseCell_Timeline : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CUtlVector< CPulseCell_Timeline::TimelineEvent_t > m_TimelineEvents; // 0x00D8
	bool m_bWaitForChildOutflows; // 0x00F0
	CPulse_ResumePoint m_OnFinished; // 0x00F8
};
class CPulseCell_Inflow_EntOutputHandler : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_SourceEntity; // 0x0080
	PulseSymbol_t m_SourceOutput; // 0x0090
	CPulseValueFullType m_ExpectedParamType; // 0x00A0
};
class CPulseCell_Outflow_CycleOrdered::InstanceState_t // pulse_runtime_lib
{
	int32 m_nNextIndex; // 0x0000
};
class CParticleCollectionBindingInstance : public CBasePulseGraphInstance // particleslib
{
};
class CPulseCell_LimitCount::InstanceState_t // pulse_runtime_lib
{
	int32 m_nCurrentCount; // 0x0000
};
class CPulseCell_Step_DebugLog : public CPulseCell_BaseFlow // pulse_runtime_lib
{
};
class CPulseCell_BaseYieldingInflow : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CPulse_ResumePoint m_BaseFlow_OnAfterCancel; // 0x0048
	CPulse_ResumePoint m_BaseFlow_WhileActive; // 0x0090
};
class PulseNodeDynamicOutflows_t // pulse_runtime_lib
{
	CUtlVector< PulseNodeDynamicOutflows_t::DynamicOutflow_t > m_Outflows; // 0x0000
};
class CPulseCell_IsRequirementValid::Criteria_t // pulse_runtime_lib
{
	bool m_bIsValid; // 0x0000
};
class CPulseCell_Inflow_ObservableVariableListener : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseRuntimeBlackboardReferenceIndex_t m_nBlackboardReference; // 0x0080
	bool m_bSelfReference; // 0x0082
};
class CPulseCell_Outflow_CycleOrdered : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outputs; // 0x0048
};
class PulseSelectorOutflowList_t // pulse_runtime_lib
{
	CUtlVector< OutflowWithRequirements_t > m_Outflows; // 0x0000
};
class CPulseCell_Inflow_Wait : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_WakeResume; // 0x00D8
};
class CPulseCell_Outflow_CycleShuffled : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outputs; // 0x0048
};
class CPulseCell_Inflow_Method : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_MethodName; // 0x0080
	CUtlString m_Description; // 0x0090
	bool m_bIsPublic; // 0x0098
	CPulseValueFullType m_ReturnType; // 0x00A0
	CUtlLeanVector< CPulseRuntimeMethodArg > m_Args; // 0x00B8
};
class CPulseCell_BaseValue : public CPulseCell_Base // pulse_runtime_lib
{
};
class CPulseCell_BooleanSwitchState : public CPulseCell_BaseState // pulse_runtime_lib
{
	CPulseObservableExpression< bool > m_Condition; // 0x00D8
	CPulse_OutflowConnection m_WhenTrue; // 0x0150
	CPulse_OutflowConnection m_WhenFalse; // 0x0198
};
class CPulseCell_Inflow_Yield : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_UnyieldResume; // 0x00D8
};
class CPulseMathlib // pulse_runtime_lib
{
};
class CPulseCell_Unknown : public CPulseCell_Base // pulse_runtime_lib
{
	KeyValues3 m_UnknownKeys; // 0x0048
};
class CPulseStringlib // pulse_runtime_lib
{
};
class CPulseCell_Outflow_CycleRandom : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outputs; // 0x0048
};
class CPulseCell_Step_PublicOutput : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseRuntimeOutputIndex_t m_OutputIndex; // 0x0048
};
class CPulse_BlackboardReference // pulse_runtime_lib
{
	CStrongHandle< InfoForResourceTypeIPulseGraphDef > m_hBlackboardResource; // 0x0000
	PulseSymbol_t m_BlackboardResource; // 0x0008
	PulseDocNodeID_t m_nNodeID; // 0x0018
	CGlobalSymbol m_NodeName; // 0x0020
};
class CPulseCell_Value_RandomInt : public CPulseCell_BaseValue // pulse_runtime_lib
{
};
class CAnimationLayer // animgraphlib
{
	CAnimNetVar< int32 > m_hSequence; // 0x0000
	float32 m_flPrevCycle; // 0x000C
	CAnimNetVar< float32 > m_flCycle; // 0x0010
	CAnimNetVar< float32 > m_flWeight; // 0x001C
	CAnimNetVar< int32 > m_nOrder; // 0x0028
	bool m_bLooping; // 0x0034
	int32 m_nFlags; // 0x0038
	bool m_bSequenceFinished; // 0x003C
	float32 m_flKillRate; // 0x0040
	float32 m_flKillDelay; // 0x0044
	int32 m_nPriority; // 0x0048
};
class CPulseEnumlib // pulse_runtime_lib
{
};
class CPulse_CallInfo // pulse_runtime_lib
{
	PulseSymbol_t m_PortName; // 0x0000
	PulseDocNodeID_t m_nEditorNodeID; // 0x0010
	PulseRegisterMap_t m_RegisterMap; // 0x0018
	PulseDocNodeID_t m_CallMethodID; // 0x0048
	PulseRuntimeChunkIndex_t m_nSrcChunk; // 0x004C
	int32 m_nSrcInstruction; // 0x0050
};
class CPulseCell_InlineNodeSkipSelector : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseDocNodeID_t m_nFlowNodeID; // 0x0048
	bool m_bAnd; // 0x004C
	PulseSelectorOutflowList_t m_PassOutflow; // 0x0050
	CPulse_OutflowConnection m_FailOutflow; // 0x0068
};
class CPulseCell_LimitCount : public CPulseCell_BaseRequirement // pulse_runtime_lib
{
	int32 m_nLimitCount; // 0x0048
};
class CPulseCell_Step_CallExternalMethod : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	PulseSymbol_t m_MethodName; // 0x00D8
	PulseRuntimeBlackboardReferenceIndex_t m_nBlackboardIndex; // 0x00E8
	CUtlLeanVector< CPulseRuntimeMethodArg > m_ExpectedArgs; // 0x00F0
	PulseMethodCallMode_t m_nAsyncCallMode; // 0x0100
	CPulse_ResumePoint m_OnFinished; // 0x0108
};
class CPulseCell_LimitCount::Criteria_t // pulse_runtime_lib
{
	bool m_bLimitCountPasses; // 0x0000
};
class CPulseCell_CursorQueue : public CPulseCell_WaitForCursorsWithTagBase // pulse_runtime_lib
{
	int32 m_nCursorsAllowedToRunParallel; // 0x0128
};
class CPulseCell_Value_RandomFloat : public CPulseCell_BaseValue // pulse_runtime_lib
{
};
class CPulseExecCursor // pulse_runtime_lib
{
};
class CEntityInstance // entity2
{
	CUtlSymbolLarge m_iszPrivateVScripts; // 0x0008
	CEntityIdentity* m_pEntity; // 0x0010
	CScriptComponent* m_CScriptComponent; // 0x0028
};
class CEntityComponent // entity2
{
};
class CScriptComponent : public CEntityComponent // entity2
{
	CUtlSymbolLarge m_scriptClassName; // 0x0030
};
class CEntityIdentity // entity2
{
	int32 m_nameStringTableIndex; // 0x0014
	CUtlSymbolLarge m_name; // 0x0018
	CUtlSymbolLarge m_designerName; // 0x0020
	uint32 m_flags; // 0x0030
	WorldGroupId_t m_worldGroupId; // 0x0038
	uint32 m_fDataObjectTypes; // 0x003C
	ChangeAccessorFieldPathIndex_t m_PathIndex; // 0x0040
	CEntityAttributeTable* m_pAttributes; // 0x0048
	CEntityIdentity* m_pPrev; // 0x0050
	CEntityIdentity* m_pNext; // 0x0058
	CEntityIdentity* m_pPrevByClass; // 0x0060
	CEntityIdentity* m_pNextByClass; // 0x0068
};
class CPulseCell_Step_TestDomainDestroyFakeEntity : public CPulseCell_BaseFlow // pulse_system
{
};
class CPulseCell_WaitForCursorsWithTag : public CPulseCell_WaitForCursorsWithTagBase // pulse_runtime_lib
{
	bool m_bTagSelfWhenComplete; // 0x0128
	PulseCursorCancelPriority_t m_nDesiredKillPriority; // 0x012C
};
class CPulseCell_Test_NoInflow : public CPulseCell_BaseFlow // pulse_system
{
};
class CPulseGraphInstance_TestDomain_FakeEntityOwner : public CBasePulseGraphInstance // pulse_system
{
};
class CPulseCell_Base // pulse_runtime_lib
{
	PulseDocNodeID_t m_nEditorNodeID; // 0x0008
};
class CPulse_ResumePoint : public CPulse_OutflowConnection // pulse_runtime_lib
{
};
class CTestDomainDerived_Cursor : public CPulseExecCursor // pulse_system
{
	int32 m_nCursorValueA; // 0x00D8
	int32 m_nCursorValueB; // 0x00DC
};
class CPulseCell_PickBestOutflowSelector : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseBestOutflowRules_t m_nCheckType; // 0x0048
	PulseSelectorOutflowList_t m_OutflowList; // 0x0050
};
class CPulseTestFuncs_LibraryA // pulse_system
{
};
class CPulseCell_WaitForObservable : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulseObservableExpression< bool > m_Condition; // 0x00D8
	CPulse_ResumePoint m_OnTrue; // 0x0150
};
class CPulse_OutflowConnection // pulse_runtime_lib
{
	PulseSymbol_t m_SourceOutflowName; // 0x0000
	PulseRuntimeChunkIndex_t m_nDestChunk; // 0x0010
	int32 m_nInstruction; // 0x0014
	PulseRegisterMap_t m_OutflowRegisterMap; // 0x0018
};
class CPulseGraphDef // pulse_runtime_lib
{
	PulseSymbol_t m_DomainIdentifier; // 0x0008
	CPulseValueFullType m_DomainSubType; // 0x0018
	PulseSymbol_t m_ParentMapName; // 0x0030
	PulseSymbol_t m_ParentXmlName; // 0x0040
	CUtlVector< CPulse_Chunk* > m_Chunks; // 0x0050
	CUtlVector< CPulseCell_Base* > m_Cells; // 0x0068
	CUtlVector< CPulse_Variable > m_Vars; // 0x0080
	CUtlVector< CPulse_PublicOutput > m_PublicOutputs; // 0x0098
	CUtlVector< CPulse_InvokeBinding* > m_InvokeBindings; // 0x00B0
	CUtlVector< CPulse_CallInfo* > m_CallInfos; // 0x00C8
	CUtlVector< CPulse_Constant > m_Constants; // 0x00E0
	CUtlVector< CPulse_DomainValue > m_DomainValues; // 0x00F8
	CUtlVector< CPulse_BlackboardReference > m_BlackboardReferences; // 0x0110
	CUtlVector< CPulse_OutputConnection* > m_OutputConnections; // 0x0128
};
class CPulseCell_TestYieldForever : public CPulseCell_BaseYieldingInflow // pulse_system
{
};
class CPulseGraphInstance_TestDomain_UseReadOnlyBlackboardView : public CPulseGraphInstance_TestDomain // pulse_system
{
};
class CPulseCell_TestWaitWithCursorState::InstanceState_t // pulse_system
{
	int32 m_nDummy; // 0x0000
};
class CPulseCell_FireCursors : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outflows; // 0x00D8
	bool m_bWaitForChildOutflows; // 0x00F0
	CPulse_ResumePoint m_OnFinished; // 0x00F8
};
class CPulseCell_Timeline::TimelineEvent_t // pulse_runtime_lib
{
	float32 m_flTimeFromPrevious; // 0x0000
	CPulse_OutflowConnection m_EventOutflow; // 0x0008
};
class CPulseCell_IntervalTimer::CursorState_t // pulse_runtime_lib
{
	GameTime_t m_StartTime; // 0x0000
	GameTime_t m_EndTime; // 0x0004
	float32 m_flWaitInterval; // 0x0008
	float32 m_flWaitIntervalHigh; // 0x000C
	bool m_bCompleteOnNextWake; // 0x0010
};
class CPulseCell_BaseRequirement : public CPulseCell_Base // pulse_runtime_lib
{
};
class CPulseCell_BaseState : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
};
class OutflowWithRequirements_t // pulse_runtime_lib
{
	CPulse_OutflowConnection m_Connection; // 0x0000
	PulseDocNodeID_t m_DestinationFlowNodeID; // 0x0048
	CUtlVector< PulseDocNodeID_t > m_RequirementNodeIDs; // 0x0050
	CUtlVector< int32 > m_nCursorStateBlockIndex; // 0x0068
};
class CPulseCell_IsRequirementValid : public CPulseCell_BaseRequirement // pulse_runtime_lib
{
};
class CPulseCell_Value_Gradient : public CPulseCell_BaseValue // pulse_runtime_lib
{
	CColorGradient m_Gradient; // 0x0048
};
class CPulseCell_TestWaitWithAutoTracepoints : public CPulseCell_BaseYieldingInflow // pulse_system
{
	CUtlString m_TracePrefix; // 0x00D8
	CPulse_ResumePoint m_WakeResume; // 0x00E0
};
class CPulseCursorFuncs // pulse_runtime_lib
{
};
class PulseNodeDynamicOutflows_t::DynamicOutflow_t // pulse_runtime_lib
{
	CGlobalSymbol m_OutflowID; // 0x0000
	CPulse_OutflowConnection m_Connection; // 0x0008
};
class CPulseCell_Test_MultiOutflow_WithParams : public CPulseCell_BaseFlow // pulse_system
{
	SignatureOutflow_Continue m_Out1; // 0x0048
	SignatureOutflow_Continue m_Out2; // 0x0090
};
class CBasePulseGraphInstance // pulse_runtime_lib
{
};
class CPulseCell_Inflow_GraphHook : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_HookName; // 0x0080
};
class SignatureOutflow_Resume : public CPulse_ResumePoint // pulse_runtime_lib
{
};
class CPulseCell_Test_MultiOutflow_WithParams_Yielding::CursorState_t // pulse_system
{
	int32 nTestStep; // 0x0000
};
class CPulseTurtleGraphicsCursor : public CPulseExecCursor // pulse_system
{
	Color m_Color; // 0x00D8
	Vector2D m_vPos; // 0x00DC
	float32 m_flHeadingDeg; // 0x00E4
	bool m_bPenUp; // 0x00E8
};
class CPulseCell_TestWaitWithCursorState::CursorState_t // pulse_system
{
	float32 flWaitValue; // 0x0000
	bool bFail; // 0x0004
	HYieldedCursor m_hSelfCursor; // 0x0008
	HPulseCellBase m_hSelfCellInstanceUntyped; // 0x0014
	HPulseCell< CPulseCell_TestWaitWithCursorState > m_hSelfCellInstance; // 0x001C
};
class CPulseCell_Inflow_BaseEntrypoint : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseRuntimeChunkIndex_t m_EntryChunk; // 0x0048
	PulseRegisterMap_t m_RegisterMap; // 0x0050
};
class CPulseCell_Test_MultiInflow_NoDefault : public CPulseCell_BaseFlow // pulse_system
{
};
class CPulseCell_WaitForCursorsWithTagBase : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	int32 m_nCursorsAllowedToWait; // 0x00D8
	CPulse_ResumePoint m_WaitComplete; // 0x00E0
};
class CPulse_InvokeBinding // pulse_runtime_lib
{
	PulseRegisterMap_t m_RegisterMap; // 0x0000
	PulseSymbol_t m_FuncName; // 0x0030
	PulseRuntimeCellIndex_t m_nCellIndex; // 0x0040
	PulseRuntimeChunkIndex_t m_nSrcChunk; // 0x0044
	int32 m_nSrcInstruction; // 0x0048
};
class CPulseCell_IntervalTimer : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_Completed; // 0x00D8
	SignatureOutflow_Continue m_OnInterval; // 0x0120
};
class CPulseTestScriptLib // pulse_runtime_lib
{
};
class CPulseCell_BaseLerp : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_WakeResume; // 0x00D8
};
class CPulseCell_Value_TestValue50 : public CPulseCell_BaseValue // pulse_system
{
};
class CPulseCell_Test_MultiOutflow_WithParams_Yielding : public CPulseCell_BaseYieldingInflow // pulse_system
{
	SignatureOutflow_Continue m_Out1; // 0x00D8
	SignatureOutflow_Continue m_AsyncChild1; // 0x0120
	SignatureOutflow_Continue m_AsyncChild2; // 0x0168
	SignatureOutflow_Resume m_YieldResume1; // 0x01B0
	SignatureOutflow_Resume m_YieldResume2; // 0x01F8
};
class TestComponent_tAPI // pulse_system
{
};
class CPulseCell_Value_Curve : public CPulseCell_BaseValue // pulse_runtime_lib
{
	CPiecewiseCurve m_Curve; // 0x0048
};
class CPulseCell_Inflow_EventHandler : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_EventName; // 0x0080
};
class CPulseCell_BaseFlow : public CPulseCell_Base // pulse_runtime_lib
{
};
class CPulseCell_Step_TestDomainTracepoint : public CPulseCell_BaseFlow // pulse_system
{
};
class CPulseCell_Outflow_CycleShuffled::InstanceState_t // pulse_runtime_lib
{
	CUtlVectorFixedGrowable< uint8, 8 > m_Shuffle; // 0x0000
	int32 m_nNextShuffle; // 0x0020
};
class CPulseCell_BaseLerp::CursorState_t // pulse_runtime_lib
{
	GameTime_t m_StartTime; // 0x0000
	GameTime_t m_EndTime; // 0x0004
};
class CPulseGraphInstance_TestDomain_Derived : public CPulseGraphInstance_TestDomain // pulse_system
{
	int32 m_nInstanceValueX; // 0x0158
};
class CPulseArraylib // pulse_runtime_lib
{
};
class CPulseGraphInstance_TestDomain : public CBasePulseGraphInstance // pulse_system
{
	bool m_bIsRunningUnitTests; // 0x0128
	bool m_bExplicitTimeStepping; // 0x0129
	bool m_bExpectingToDestroyWithYieldedCursors; // 0x012A
	bool m_bQuietTracepoints; // 0x012B
	bool m_bExpectingCursorTerminatedDueToMaxInstructions; // 0x012C
	int32 m_nCursorsTerminatedDueToMaxInstructions; // 0x0130
	int32 m_nNextValidateIndex; // 0x0134
	CUtlVector< CUtlString > m_Tracepoints; // 0x0138
	bool m_bTestYesOrNoPath; // 0x0150
};
class SignatureOutflow_Continue : public CPulse_OutflowConnection // pulse_runtime_lib
{
};
class CPulseCell_Timeline : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CUtlVector< CPulseCell_Timeline::TimelineEvent_t > m_TimelineEvents; // 0x00D8
	bool m_bWaitForChildOutflows; // 0x00F0
	CPulse_ResumePoint m_OnFinished; // 0x00F8
};
class CPulseCell_Inflow_EntOutputHandler : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_SourceEntity; // 0x0080
	PulseSymbol_t m_SourceOutput; // 0x0090
	CPulseValueFullType m_ExpectedParamType; // 0x00A0
};
class CPulseCell_Outflow_TestExplicitYesNo : public CPulseCell_BaseFlow // pulse_system
{
	CPulse_OutflowConnection m_Yes; // 0x0048
	CPulse_OutflowConnection m_No; // 0x0090
};
class CPulseCell_Outflow_TestRandomYesNo : public CPulseCell_BaseFlow // pulse_system
{
	CPulse_OutflowConnection m_Yes; // 0x0048
	CPulse_OutflowConnection m_No; // 0x0090
};
class CPulseCell_Outflow_CycleOrdered::InstanceState_t // pulse_runtime_lib
{
	int32 m_nNextIndex; // 0x0000
};
class CPulseCell_LimitCount::InstanceState_t // pulse_runtime_lib
{
	int32 m_nCurrentCount; // 0x0000
};
class FakeEntity_tAPI // pulse_system
{
};
class CPulseCell_Test_MultiInflow_WithDefault : public CPulseCell_BaseFlow // pulse_system
{
};
class CPulseCell_Step_DebugLog : public CPulseCell_BaseFlow // pulse_runtime_lib
{
};
class CPulseCell_BaseYieldingInflow : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CPulse_ResumePoint m_BaseFlow_OnAfterCancel; // 0x0048
	CPulse_ResumePoint m_BaseFlow_WhileActive; // 0x0090
};
class PulseNodeDynamicOutflows_t // pulse_runtime_lib
{
	CUtlVector< PulseNodeDynamicOutflows_t::DynamicOutflow_t > m_Outflows; // 0x0000
};
class CPulseCell_IsRequirementValid::Criteria_t // pulse_runtime_lib
{
	bool m_bIsValid; // 0x0000
};
class CPulseCell_Inflow_ObservableVariableListener : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseRuntimeBlackboardReferenceIndex_t m_nBlackboardReference; // 0x0080
	bool m_bSelfReference; // 0x0082
};
class CPulseCell_Outflow_CycleOrdered : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outputs; // 0x0048
};
class PulseSelectorOutflowList_t // pulse_runtime_lib
{
	CUtlVector< OutflowWithRequirements_t > m_Outflows; // 0x0000
};
class CPulseGraphInstance_TurtleGraphics : public CBasePulseGraphInstance // pulse_system
{
};
class CPulseCell_Val_TestDomainGetEntityName : public CPulseCell_BaseValue // pulse_system
{
};
class CPulseCell_Inflow_Wait : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_WakeResume; // 0x00D8
};
class CPulseCell_TestWaitWithCursorState : public CPulseCell_BaseYieldingInflow // pulse_system
{
	CPulse_ResumePoint m_WakeResume; // 0x00D8
	CPulse_ResumePoint m_WakeFail; // 0x0120
};
class CPulseCell_Outflow_CycleShuffled : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outputs; // 0x0048
};
class CPulseCell_Inflow_Method : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_MethodName; // 0x0080
	CUtlString m_Description; // 0x0090
	bool m_bIsPublic; // 0x0098
	CPulseValueFullType m_ReturnType; // 0x00A0
	CUtlLeanVector< CPulseRuntimeMethodArg > m_Args; // 0x00B8
};
class CPulseCell_BaseValue : public CPulseCell_Base // pulse_runtime_lib
{
};
class CPulseCell_BooleanSwitchState : public CPulseCell_BaseState // pulse_runtime_lib
{
	CPulseObservableExpression< bool > m_Condition; // 0x00D8
	CPulse_OutflowConnection m_WhenTrue; // 0x0150
	CPulse_OutflowConnection m_WhenFalse; // 0x0198
};
class FakeEntityDerivedB_tAPI // pulse_system
{
};
class CPulseCell_Inflow_Yield : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_UnyieldResume; // 0x00D8
};
class CPulseMathlib // pulse_runtime_lib
{
};
class CPulseCell_Unknown : public CPulseCell_Base // pulse_runtime_lib
{
	KeyValues3 m_UnknownKeys; // 0x0048
};
class CPulseStringlib // pulse_runtime_lib
{
};
class CPulseCell_Outflow_CycleRandom : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outputs; // 0x0048
};
class CPulseCell_Step_PublicOutput : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseRuntimeOutputIndex_t m_OutputIndex; // 0x0048
};
class CPulseCell_Val_TestDomainFindEntityByName : public CPulseCell_BaseValue // pulse_system
{
};
class CPulse_BlackboardReference // pulse_runtime_lib
{
	CStrongHandle< InfoForResourceTypeIPulseGraphDef > m_hBlackboardResource; // 0x0000
	PulseSymbol_t m_BlackboardResource; // 0x0008
	PulseDocNodeID_t m_nNodeID; // 0x0018
	CGlobalSymbol m_NodeName; // 0x0020
};
class CPulseCell_Value_RandomInt : public CPulseCell_BaseValue // pulse_runtime_lib
{
};
class CPulseCell_TestEnums : public CPulseCell_BaseValue // pulse_system
{
	PulseTestEnumColor_t m_nReferenceColor; // 0x0048
	PulseTestEnumFlags_t m_nReferenceFlags; // 0x004C
};
class CPulseCell_Step_TestDomainEntFire : public CPulseCell_BaseFlow // pulse_system
{
	CUtlString m_Input; // 0x0048
};
class CPulseEnumlib // pulse_runtime_lib
{
};
class FakeEntityDerivedA_tAPI // pulse_system
{
};
class CPulseCell_ExampleSelector : public CPulseCell_BaseFlow // pulse_system
{
	PulseSelectorOutflowList_t m_OutflowList; // 0x0048
};
class CPulse_CallInfo // pulse_runtime_lib
{
	PulseSymbol_t m_PortName; // 0x0000
	PulseDocNodeID_t m_nEditorNodeID; // 0x0010
	PulseRegisterMap_t m_RegisterMap; // 0x0018
	PulseDocNodeID_t m_CallMethodID; // 0x0048
	PulseRuntimeChunkIndex_t m_nSrcChunk; // 0x004C
	int32 m_nSrcInstruction; // 0x0050
};
class CPulseCell_InlineNodeSkipSelector : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseDocNodeID_t m_nFlowNodeID; // 0x0048
	bool m_bAnd; // 0x004C
	PulseSelectorOutflowList_t m_PassOutflow; // 0x0050
	CPulse_OutflowConnection m_FailOutflow; // 0x0068
};
class CPulseCell_ExampleCriteria::Criteria_t // pulse_system
{
	float32 m_flFloatValue1; // 0x0000
	float32 m_flFloatValue2; // 0x0004
	bool m_bMyBool; // 0x0008
};
class CPulseCell_ExampleCriteria : public CPulseCell_BaseRequirement // pulse_system
{
};
class CPulseCell_LimitCount : public CPulseCell_BaseRequirement // pulse_runtime_lib
{
	int32 m_nLimitCount; // 0x0048
};
class CPulseCell_Step_CallExternalMethod : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	PulseSymbol_t m_MethodName; // 0x00D8
	PulseRuntimeBlackboardReferenceIndex_t m_nBlackboardIndex; // 0x00E8
	CUtlLeanVector< CPulseRuntimeMethodArg > m_ExpectedArgs; // 0x00F0
	PulseMethodCallMode_t m_nAsyncCallMode; // 0x0100
	CPulse_ResumePoint m_OnFinished; // 0x0108
};
class CPulseCell_LimitCount::Criteria_t // pulse_runtime_lib
{
	bool m_bLimitCountPasses; // 0x0000
};
class CPulseCell_Step_TestDomainCreateFakeEntity : public CPulseCell_BaseFlow // pulse_system
{
};
class CPulseCell_TestYieldWithObservables : public CPulseCell_BaseYieldingInflow // pulse_system
{
	float32 m_flWatchForFloatValue; // 0x00D8
	CPulseObservableExpression< float32 > m_LiveFloatValue; // 0x00E0
	CUtlString m_WatchForStringValue; // 0x0158
	CPulseObservableExpression< CUtlString > m_LiveStringValue; // 0x0160
	CPulse_ResumePoint m_WakeResume; // 0x01D8
};
class CPulseCell_CursorQueue : public CPulseCell_WaitForCursorsWithTagBase // pulse_runtime_lib
{
	int32 m_nCursorsAllowedToRunParallel; // 0x0128
};
class CPulseCell_Value_RandomFloat : public CPulseCell_BaseValue // pulse_runtime_lib
{
};
class CPulseExecCursor // pulse_runtime_lib
{
};
class CPulseCell_WaitForCursorsWithTag : public CPulseCell_WaitForCursorsWithTagBase // pulse_runtime_lib
{
	bool m_bTagSelfWhenComplete; // 0x0128
	PulseCursorCancelPriority_t m_nDesiredKillPriority; // 0x012C
};
class CPulseCell_Base // pulse_runtime_lib
{
	PulseDocNodeID_t m_nEditorNodeID; // 0x0008
};
class CPulse_ResumePoint : public CPulse_OutflowConnection // pulse_runtime_lib
{
};
class CPulseCell_PickBestOutflowSelector : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseBestOutflowRules_t m_nCheckType; // 0x0048
	PulseSelectorOutflowList_t m_OutflowList; // 0x0050
};
class CParticleBindingRealPulse : public CParticleCollectionBindingInstance // particleslib
{
};
class CPulseCell_WaitForObservable : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulseObservableExpression< bool > m_Condition; // 0x00D8
	CPulse_ResumePoint m_OnTrue; // 0x0150
};
class CPulse_OutflowConnection // pulse_runtime_lib
{
	PulseSymbol_t m_SourceOutflowName; // 0x0000
	PulseRuntimeChunkIndex_t m_nDestChunk; // 0x0010
	int32 m_nInstruction; // 0x0014
	PulseRegisterMap_t m_OutflowRegisterMap; // 0x0018
};
class CPulseGraphDef // pulse_runtime_lib
{
	PulseSymbol_t m_DomainIdentifier; // 0x0008
	CPulseValueFullType m_DomainSubType; // 0x0018
	PulseSymbol_t m_ParentMapName; // 0x0030
	PulseSymbol_t m_ParentXmlName; // 0x0040
	CUtlVector< CPulse_Chunk* > m_Chunks; // 0x0050
	CUtlVector< CPulseCell_Base* > m_Cells; // 0x0068
	CUtlVector< CPulse_Variable > m_Vars; // 0x0080
	CUtlVector< CPulse_PublicOutput > m_PublicOutputs; // 0x0098
	CUtlVector< CPulse_InvokeBinding* > m_InvokeBindings; // 0x00B0
	CUtlVector< CPulse_CallInfo* > m_CallInfos; // 0x00C8
	CUtlVector< CPulse_Constant > m_Constants; // 0x00E0
	CUtlVector< CPulse_DomainValue > m_DomainValues; // 0x00F8
	CUtlVector< CPulse_BlackboardReference > m_BlackboardReferences; // 0x0110
	CUtlVector< CPulse_OutputConnection* > m_OutputConnections; // 0x0128
};
class CPulseCell_FireCursors : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outflows; // 0x00D8
	bool m_bWaitForChildOutflows; // 0x00F0
	CPulse_ResumePoint m_OnFinished; // 0x00F8
};
class CPulseCell_Timeline::TimelineEvent_t // pulse_runtime_lib
{
	float32 m_flTimeFromPrevious; // 0x0000
	CPulse_OutflowConnection m_EventOutflow; // 0x0008
};
class CPulseCell_IntervalTimer::CursorState_t // pulse_runtime_lib
{
	GameTime_t m_StartTime; // 0x0000
	GameTime_t m_EndTime; // 0x0004
	float32 m_flWaitInterval; // 0x0008
	float32 m_flWaitIntervalHigh; // 0x000C
	bool m_bCompleteOnNextWake; // 0x0010
};
class CPulseCell_BaseRequirement : public CPulseCell_Base // pulse_runtime_lib
{
};
class CPulseCell_BaseState : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
};
class OutflowWithRequirements_t // pulse_runtime_lib
{
	CPulse_OutflowConnection m_Connection; // 0x0000
	PulseDocNodeID_t m_DestinationFlowNodeID; // 0x0048
	CUtlVector< PulseDocNodeID_t > m_RequirementNodeIDs; // 0x0050
	CUtlVector< int32 > m_nCursorStateBlockIndex; // 0x0068
};
class CPulseCell_IsRequirementValid : public CPulseCell_BaseRequirement // pulse_runtime_lib
{
};
class CPulseCell_Value_Gradient : public CPulseCell_BaseValue // pulse_runtime_lib
{
	CColorGradient m_Gradient; // 0x0048
};
class CPulseCursorFuncs // pulse_runtime_lib
{
};
class PulseNodeDynamicOutflows_t::DynamicOutflow_t // pulse_runtime_lib
{
	CGlobalSymbol m_OutflowID; // 0x0000
	CPulse_OutflowConnection m_Connection; // 0x0008
};
class CBasePulseGraphInstance // pulse_runtime_lib
{
};
class CPulseCell_Inflow_GraphHook : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_HookName; // 0x0080
};
class SignatureOutflow_Resume : public CPulse_ResumePoint // pulse_runtime_lib
{
};
class CPulseCell_Inflow_BaseEntrypoint : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseRuntimeChunkIndex_t m_EntryChunk; // 0x0048
	PulseRegisterMap_t m_RegisterMap; // 0x0050
};
class CPulseCell_WaitForCursorsWithTagBase : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	int32 m_nCursorsAllowedToWait; // 0x00D8
	CPulse_ResumePoint m_WaitComplete; // 0x00E0
};
class CPulse_InvokeBinding // pulse_runtime_lib
{
	PulseRegisterMap_t m_RegisterMap; // 0x0000
	PulseSymbol_t m_FuncName; // 0x0030
	PulseRuntimeCellIndex_t m_nCellIndex; // 0x0040
	PulseRuntimeChunkIndex_t m_nSrcChunk; // 0x0044
	int32 m_nSrcInstruction; // 0x0048
};
class CPulseCell_IntervalTimer : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_Completed; // 0x00D8
	SignatureOutflow_Continue m_OnInterval; // 0x0120
};
class CPulseTestScriptLib // pulse_runtime_lib
{
};
class CPulseCell_BaseLerp : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_WakeResume; // 0x00D8
};
class CPulseCell_Value_Curve : public CPulseCell_BaseValue // pulse_runtime_lib
{
	CPiecewiseCurve m_Curve; // 0x0048
};
class CPulseCell_Inflow_EventHandler : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_EventName; // 0x0080
};
class CPulseCell_BaseFlow : public CPulseCell_Base // pulse_runtime_lib
{
};
class CPulseCell_Outflow_CycleShuffled::InstanceState_t // pulse_runtime_lib
{
	CUtlVectorFixedGrowable< uint8, 8 > m_Shuffle; // 0x0000
	int32 m_nNextShuffle; // 0x0020
};
class CPulseCell_BaseLerp::CursorState_t // pulse_runtime_lib
{
	GameTime_t m_StartTime; // 0x0000
	GameTime_t m_EndTime; // 0x0004
};
class CPulseArraylib // pulse_runtime_lib
{
};
class SignatureOutflow_Continue : public CPulse_OutflowConnection // pulse_runtime_lib
{
};
class CPulseCell_Timeline : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CUtlVector< CPulseCell_Timeline::TimelineEvent_t > m_TimelineEvents; // 0x00D8
	bool m_bWaitForChildOutflows; // 0x00F0
	CPulse_ResumePoint m_OnFinished; // 0x00F8
};
class CPulseCell_Inflow_EntOutputHandler : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_SourceEntity; // 0x0080
	PulseSymbol_t m_SourceOutput; // 0x0090
	CPulseValueFullType m_ExpectedParamType; // 0x00A0
};
class CPulseCell_Outflow_CycleOrdered::InstanceState_t // pulse_runtime_lib
{
	int32 m_nNextIndex; // 0x0000
};
class CParticleCollectionBindingInstance : public CBasePulseGraphInstance // particleslib
{
};
class CPulseCell_LimitCount::InstanceState_t // pulse_runtime_lib
{
	int32 m_nCurrentCount; // 0x0000
};
class CPulseCell_Step_DebugLog : public CPulseCell_BaseFlow // pulse_runtime_lib
{
};
class CPulseCell_BaseYieldingInflow : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CPulse_ResumePoint m_BaseFlow_OnAfterCancel; // 0x0048
	CPulse_ResumePoint m_BaseFlow_WhileActive; // 0x0090
};
class PulseNodeDynamicOutflows_t // pulse_runtime_lib
{
	CUtlVector< PulseNodeDynamicOutflows_t::DynamicOutflow_t > m_Outflows; // 0x0000
};
class CPulseCell_IsRequirementValid::Criteria_t // pulse_runtime_lib
{
	bool m_bIsValid; // 0x0000
};
class CPulseCell_Inflow_ObservableVariableListener : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseRuntimeBlackboardReferenceIndex_t m_nBlackboardReference; // 0x0080
	bool m_bSelfReference; // 0x0082
};
class CPulseCell_Outflow_CycleOrdered : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outputs; // 0x0048
};
class PulseSelectorOutflowList_t // pulse_runtime_lib
{
	CUtlVector< OutflowWithRequirements_t > m_Outflows; // 0x0000
};
class CPulseCell_Inflow_Wait : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_WakeResume; // 0x00D8
};
class CPulseCell_Outflow_CycleShuffled : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outputs; // 0x0048
};
class CPulseCell_Inflow_Method : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_MethodName; // 0x0080
	CUtlString m_Description; // 0x0090
	bool m_bIsPublic; // 0x0098
	CPulseValueFullType m_ReturnType; // 0x00A0
	CUtlLeanVector< CPulseRuntimeMethodArg > m_Args; // 0x00B8
};
class CPulseCell_BaseValue : public CPulseCell_Base // pulse_runtime_lib
{
};
class CPulseCell_BooleanSwitchState : public CPulseCell_BaseState // pulse_runtime_lib
{
	CPulseObservableExpression< bool > m_Condition; // 0x00D8
	CPulse_OutflowConnection m_WhenTrue; // 0x0150
	CPulse_OutflowConnection m_WhenFalse; // 0x0198
};
class CPulseCell_Inflow_Yield : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_UnyieldResume; // 0x00D8
};
class CPulseMathlib // pulse_runtime_lib
{
};
class CPulseCell_Unknown : public CPulseCell_Base // pulse_runtime_lib
{
	KeyValues3 m_UnknownKeys; // 0x0048
};
class CPulseStringlib // pulse_runtime_lib
{
};
class CPulseCell_Outflow_CycleRandom : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outputs; // 0x0048
};
class CPulseCell_Step_PublicOutput : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseRuntimeOutputIndex_t m_OutputIndex; // 0x0048
};
class CPulse_BlackboardReference // pulse_runtime_lib
{
	CStrongHandle< InfoForResourceTypeIPulseGraphDef > m_hBlackboardResource; // 0x0000
	PulseSymbol_t m_BlackboardResource; // 0x0008
	PulseDocNodeID_t m_nNodeID; // 0x0018
	CGlobalSymbol m_NodeName; // 0x0020
};
class CPulseCell_Value_RandomInt : public CPulseCell_BaseValue // pulse_runtime_lib
{
};
class CPulseEnumlib // pulse_runtime_lib
{
};
class CPulse_CallInfo // pulse_runtime_lib
{
	PulseSymbol_t m_PortName; // 0x0000
	PulseDocNodeID_t m_nEditorNodeID; // 0x0010
	PulseRegisterMap_t m_RegisterMap; // 0x0018
	PulseDocNodeID_t m_CallMethodID; // 0x0048
	PulseRuntimeChunkIndex_t m_nSrcChunk; // 0x004C
	int32 m_nSrcInstruction; // 0x0050
};
class CPulseCell_InlineNodeSkipSelector : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseDocNodeID_t m_nFlowNodeID; // 0x0048
	bool m_bAnd; // 0x004C
	PulseSelectorOutflowList_t m_PassOutflow; // 0x0050
	CPulse_OutflowConnection m_FailOutflow; // 0x0068
};
class CPulseCell_LimitCount : public CPulseCell_BaseRequirement // pulse_runtime_lib
{
	int32 m_nLimitCount; // 0x0048
};
class CPulseCell_Step_CallExternalMethod : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	PulseSymbol_t m_MethodName; // 0x00D8
	PulseRuntimeBlackboardReferenceIndex_t m_nBlackboardIndex; // 0x00E8
	CUtlLeanVector< CPulseRuntimeMethodArg > m_ExpectedArgs; // 0x00F0
	PulseMethodCallMode_t m_nAsyncCallMode; // 0x0100
	CPulse_ResumePoint m_OnFinished; // 0x0108
};
class CPulseCell_LimitCount::Criteria_t // pulse_runtime_lib
{
	bool m_bLimitCountPasses; // 0x0000
};
class CPulseCell_CursorQueue : public CPulseCell_WaitForCursorsWithTagBase // pulse_runtime_lib
{
	int32 m_nCursorsAllowedToRunParallel; // 0x0128
};
class CPulseCell_Value_RandomFloat : public CPulseCell_BaseValue // pulse_runtime_lib
{
};
class CPulseExecCursor // pulse_runtime_lib
{
};
class CWeaponNOVA : public CCSWeaponBaseShotgun // server
{
};
class CPointWorldText : public CModelPointEntity // server
{
	char[512] m_messageText; // 0x0770
	char[64] m_FontName; // 0x0970
	char[64] m_BackgroundMaterialName; // 0x09B0
	bool m_bEnabled; // 0x09F0
	bool m_bFullbright; // 0x09F1
	float32 m_flWorldUnitsPerPx; // 0x09F4
	float32 m_flFontSize; // 0x09F8
	float32 m_flDepthOffset; // 0x09FC
	bool m_bDrawBackground; // 0x0A00
	float32 m_flBackgroundBorderWidth; // 0x0A04
	float32 m_flBackgroundBorderHeight; // 0x0A08
	float32 m_flBackgroundWorldToUV; // 0x0A0C
	Color m_Color; // 0x0A10
	PointWorldTextJustifyHorizontal_t m_nJustifyHorizontal; // 0x0A14
	PointWorldTextJustifyVertical_t m_nJustifyVertical; // 0x0A18
	PointWorldTextReorientMode_t m_nReorientMode; // 0x0A1C
};
class CAmbientGeneric : public CPointEntity // server
{
	float32 m_radius; // 0x04A8
	float32 m_flMaxRadius; // 0x04AC
	soundlevel_t m_iSoundLevel; // 0x04B0
	dynpitchvol_t m_dpv; // 0x04B4
	bool m_fActive; // 0x0518
	bool m_fLooping; // 0x0519
	CGameSoundEventName m_iszSound; // 0x0520
	CUtlSymbolLarge m_sSourceEntName; // 0x0528
	CHandle< CBaseEntity > m_hSoundSource; // 0x0530
	CEntityIndex m_nSoundSourceEntIndex; // 0x0534
};
class CEnvEntityMaker : public CPointEntity // server
{
	Vector m_vecEntityMins; // 0x04A8
	Vector m_vecEntityMaxs; // 0x04B4
	CHandle< CBaseEntity > m_hCurrentInstance; // 0x04C0
	CHandle< CBaseEntity > m_hCurrentBlocker; // 0x04C4
	VectorWS m_vecBlockerOrigin; // 0x04C8
	QAngle m_angPostSpawnDirection; // 0x04D4
	float32 m_flPostSpawnDirectionVariance; // 0x04E0
	float32 m_flPostSpawnSpeed; // 0x04E4
	bool m_bPostSpawnUseAngles; // 0x04E8
	CUtlSymbolLarge m_iszTemplate; // 0x04F0
	CEntityIOOutput m_pOutputOnSpawned; // 0x04F8
	CEntityIOOutput m_pOutputOnFailedSpawn; // 0x0510
};
class CPulseGraphInstance_GameBlackboard : public CPulseGraphInstance_ServerEntity // server
{
};
class CPointEntity : public CBaseEntity // server
{
};
class CFilterEnemy : public CBaseFilter // server
{
	CUtlSymbolLarge m_iszEnemyName; // 0x04E0
	float32 m_flRadius; // 0x04E8
	float32 m_flOuterRadius; // 0x04EC
	int32 m_nMaxSquadmatesPerEnemy; // 0x04F0
	CUtlSymbolLarge m_iszPlayerName; // 0x04F8
};
class CCSGO_WingmanIntroCounterTerroristPosition : public CCSGO_WingmanIntroCharacterPosition // server
{
};
class CPulseCell_WaitForCursorsWithTag : public CPulseCell_WaitForCursorsWithTagBase // pulse_runtime_lib
{
	bool m_bTagSelfWhenComplete; // 0x0128
	PulseCursorCancelPriority_t m_nDesiredKillPriority; // 0x012C
};
class CFuncTrackAuto : public CFuncTrackChange // server
{
};
class CScriptedSequence : public CBaseEntity // server
{
	CUtlSymbolLarge m_iszEntry; // 0x04A8
	CUtlSymbolLarge m_iszPreIdle; // 0x04B0
	CUtlSymbolLarge m_iszPlay; // 0x04B8
	CUtlSymbolLarge m_iszPostIdle; // 0x04C0
	CUtlSymbolLarge m_iszModifierToAddOnPlay; // 0x04C8
	CUtlSymbolLarge m_iszNextScript; // 0x04D0
	CUtlSymbolLarge m_iszEntity; // 0x04D8
	CUtlSymbolLarge m_iszSyncGroup; // 0x04E0
	ScriptedMoveTo_t m_nMoveTo; // 0x04E8
	SharedMovementGait_t m_nMoveToGait; // 0x04EC
	ScriptedHeldWeaponBehavior_t m_nHeldWeaponBehavior; // 0x04F0
	ForcedCrouchState_t m_nForcedCrouchState; // 0x04F4
	bool m_bIsPlayingPreIdle; // 0x04F8
	bool m_bIsPlayingEntry; // 0x04F9
	bool m_bIsPlayingAction; // 0x04FA
	bool m_bIsPlayingPostIdle; // 0x04FB
	bool m_bDontRotateOther; // 0x04FC
	bool m_bIsRepeatable; // 0x04FD
	bool m_bShouldLeaveCorpse; // 0x04FE
	bool m_bStartOnSpawn; // 0x04FF
	bool m_bDisallowInterrupts; // 0x0500
	bool m_bCanOverrideNPCState; // 0x0501
	bool m_bDontTeleportAtEnd; // 0x0502
	bool m_bHighPriority; // 0x0503
	bool m_bHideDebugComplaints; // 0x0504
	bool m_bContinueOnDeath; // 0x0505
	bool m_bLoopPreIdleSequence; // 0x0506
	bool m_bLoopActionSequence; // 0x0507
	bool m_bLoopPostIdleSequence; // 0x0508
	bool m_bSynchPostIdles; // 0x0509
	bool m_bIgnoreLookAt; // 0x050A
	bool m_bIgnoreGravity; // 0x050B
	bool m_bDisableNPCCollisions; // 0x050C
	bool m_bKeepAnimgraphLockedPost; // 0x050D
	bool m_bDontAddModifiers; // 0x050E
	bool m_bDisableAimingWhileMoving; // 0x050F
	bool m_bIgnoreRotation; // 0x0510
	float32 m_flRadius; // 0x0514
	float32 m_flRepeat; // 0x0518
	float32 m_flPlayAnimFadeInTime; // 0x051C
	float32 m_flMoveInterpTime; // 0x0520
	float32 m_flAngRate; // 0x0524
	float32 m_flMoveSpeed; // 0x0528
	bool m_bWaitUntilMoveCompletesToStartAnimation; // 0x052C
	int32 m_nNotReadySequenceCount; // 0x0530
	GameTime_t m_startTime; // 0x0534
	bool m_bWaitForBeginSequence; // 0x0538
	int32 m_saved_effects; // 0x053C
	int32 m_savedFlags; // 0x0540
	int32 m_savedCollisionGroup; // 0x0544
	bool m_bInterruptable; // 0x0548
	bool m_sequenceStarted; // 0x0549
	bool m_bPositionRelativeToOtherEntity; // 0x054A
	CHandle< CBaseEntity > m_hTargetEnt; // 0x054C
	CHandle< CScriptedSequence > m_hNextCine; // 0x0550
	bool m_bThinking; // 0x0554
	bool m_bInitiatedSelfDelete; // 0x0555
	bool m_bIsTeleportingDueToMoveTo; // 0x0556
	bool m_bAllowCustomInterruptConditions; // 0x0557
	CHandle< CBaseAnimGraph > m_hForcedTarget; // 0x0558
	bool m_bDontCancelOtherSequences; // 0x055C
	bool m_bForceSynch; // 0x055D
	bool m_bPreventUpdateYawOnFinish; // 0x055E
	bool m_bEnsureOnNavmeshOnFinish; // 0x055F
	ScriptedOnDeath_t m_onDeathBehavior; // 0x0560
	ScriptedConflictResponse_t m_ConflictResponse; // 0x0564
	CEntityIOOutput m_OnBeginSequence; // 0x0568
	CEntityIOOutput m_OnActionStartOrLoop; // 0x0580
	CEntityIOOutput m_OnEndSequence; // 0x0598
	CEntityIOOutput m_OnPostIdleEndSequence; // 0x05B0
	CEntityIOOutput m_OnCancelSequence; // 0x05C8
	CEntityIOOutput m_OnCancelFailedSequence; // 0x05E0
	CEntityIOOutput[8] m_OnScriptEvent; // 0x05F8
	CTransform m_matOtherToMain; // 0x06C0
	CHandle< CBaseEntity > m_hInteractionMainEntity; // 0x06E0
	int32 m_iPlayerDeathBehavior; // 0x06E4
	bool m_bSkipFadeIn; // 0x06E8
};
class CFogTrigger : public CBaseTrigger // server
{
	fogparams_t m_fog; // 0x08E8
};
class CInfoTeleportDestination : public CPointEntity // server
{
};
class CPointBroadcastClientCommand : public CPointEntity // server
{
};
class CCSPlayer_PingServices : public CPlayerPawnComponent // server
{
	GameTime_t[5] m_flPlayerPingTokens; // 0x0048
	CHandle< CPlayerPing > m_hPlayerPing; // 0x005C
};
class CHEGrenade : public CBaseCSGrenade // server
{
};
class CPhysicsSpring : public CBaseEntity // server
{
	IPhysicsJoint* m_pSpringJoint; // 0x04A8
	float32 m_flFrequency; // 0x04B0
	float32 m_flDampingRatio; // 0x04B4
	float32 m_flRestLength; // 0x04B8
	CUtlSymbolLarge m_nameAttachStart; // 0x04C0
	CUtlSymbolLarge m_nameAttachEnd; // 0x04C8
	VectorWS m_start; // 0x04D0
	VectorWS m_end; // 0x04DC
	uint32 m_teleportTick; // 0x04E8
};
class CEnvMuzzleFlash : public CPointEntity // server
{
	float32 m_flScale; // 0x04A8
	CUtlSymbolLarge m_iszParentAttachment; // 0x04B0
};
class CEconItemAttribute // server
{
	uint16 m_iAttributeDefinitionIndex; // 0x0030
	float32 m_flValue; // 0x0034
	float32 m_flInitialValue; // 0x0038
	int32 m_nRefundableCurrency; // 0x003C
	bool m_bSetBonus; // 0x0040
};
class CBaseTriggerAPI // server
{
};
class CWeaponRevolver : public CCSWeaponBaseGun // server
{
};
class CFuncTrainControls : public CBaseModelEntity // server
{
};
class CBtActionCombatPositioning : public CBtNode // server
{
	CUtlString m_szSensorInputKey; // 0x0068
	CUtlString m_szIsAttackingKey; // 0x0080
	CountdownTimer m_ActionTimer; // 0x0088
	bool m_bCrouching; // 0x00A0
};
class CFuncRetakeBarrier : public CDynamicProp // server
{
};
class CHostage_API // server
{
};
class CTriggerBuoyancy : public CBaseTrigger // server
{
	CBuoyancyHelper m_BuoyancyHelper; // 0x08E8
	float32 m_flFluidDensity; // 0x0A00
};
class CTonemapController2Alias_env_tonemap_controller2 : public CTonemapController2 // server
{
};
class CPathTrack : public CPointEntity // server
{
	CHandle< CPathTrack > m_pnext; // 0x04A8
	CHandle< CPathTrack > m_pprevious; // 0x04AC
	CHandle< CPathTrack > m_paltpath; // 0x04B0
	float32 m_flSpeed; // 0x04B4
	float32 m_flRadius; // 0x04B8
	float32 m_length; // 0x04BC
	CUtlSymbolLarge m_altName; // 0x04C0
	int32 m_nIterVal; // 0x04C8
	TrackOrientationType_t m_eOrientationType; // 0x04CC
	CEntityIOOutput m_OnPass; // 0x04D0
};
class CCSGO_EndOfMatchLineupEndpoint : public CBaseEntity // server
{
};
class CPulseCell_Base // pulse_runtime_lib
{
	PulseDocNodeID_t m_nEditorNodeID; // 0x0008
};
class CTriggerProximity : public CBaseTrigger // server
{
	CHandle< CBaseEntity > m_hMeasureTarget; // 0x08E8
	CUtlSymbolLarge m_iszMeasureTarget; // 0x08F0
	float32 m_fRadius; // 0x08F8
	int32 m_nTouchers; // 0x08FC
	CEntityOutputTemplate< float32 > m_NearestEntityDistance; // 0x0900
};
class CTankTrainAI : public CPointEntity // server
{
	CHandle< CFuncTrackTrain > m_hTrain; // 0x04A8
	CHandle< CBaseEntity > m_hTargetEntity; // 0x04AC
	int32 m_soundPlaying; // 0x04B0
	CUtlSymbolLarge m_startSoundName; // 0x04C8
	CUtlSymbolLarge m_engineSoundName; // 0x04D0
	CUtlSymbolLarge m_movementSoundName; // 0x04D8
	CUtlSymbolLarge m_targetEntityName; // 0x04E0
};
class CGameText : public CRulePointEntity // server
{
	CUtlSymbolLarge m_iszMessage; // 0x0780
	hudtextparms_t m_textParms; // 0x0788
};
class CGameEnd : public CRulePointEntity // server
{
};
class CInfoDeathmatchSpawn : public SpawnPoint // server
{
};
class CCSPlayerController_InventoryServices : public CPlayerControllerComponent // server
{
	uint16 m_unMusicID; // 0x0040
	MedalRank_t[6] m_rank; // 0x0044
	int32 m_nPersonaDataPublicLevel; // 0x005C
	int32 m_nPersonaDataPublicCommendsLeader; // 0x0060
	int32 m_nPersonaDataPublicCommendsTeacher; // 0x0064
	int32 m_nPersonaDataPublicCommendsFriendly; // 0x0068
	int32 m_nPersonaDataXpTrailLevel; // 0x006C
	uint32[1] m_unEquippedPlayerSprayIDs; // 0x0F48
	uint64 m_unCurrentLoadoutHash; // 0x0F50
	CUtlVectorEmbeddedNetworkVar< ServerAuthoritativeWeaponSlot_t > m_vecServerAuthoritativeWeaponSlots; // 0x0F58
};
class CCSPlayerModernJump // server
{
	GameTick_t m_nLastActualJumpPressTick; // 0x0010
	float32 m_flLastActualJumpPressFrac; // 0x0014
	GameTick_t m_nLastUsableJumpPressTick; // 0x0018
	float32 m_flLastUsableJumpPressFrac; // 0x001C
	GameTick_t m_nLastLandedTick; // 0x0020
	float32 m_flLastLandedFrac; // 0x0024
	float32 m_flLastLandedVelocityX; // 0x0028
	float32 m_flLastLandedVelocityY; // 0x002C
	float32 m_flLastLandedVelocityZ; // 0x0030
};
class CCSGO_TeamPreviewCharacterPosition_API // server
{
};
class CPulse_ResumePoint : public CPulse_OutflowConnection // pulse_runtime_lib
{
};
class CTriggerFan : public CBaseTrigger // server
{
	Vector m_vFanOriginOffset; // 0x08E8
	Vector m_vDirection; // 0x08F4
	bool m_bPushTowardsInfoTarget; // 0x0900
	bool m_bPushAwayFromInfoTarget; // 0x0901
	Quaternion m_qNoiseDelta; // 0x0910
	CHandle< CInfoFan > m_hInfoFan; // 0x0920
	float32 m_flForce; // 0x0924
	bool m_bFalloff; // 0x0928
	CountdownTimer m_RampTimer; // 0x0930
	VectorWS m_vFanOriginWS; // 0x0948
	Vector m_vFanOriginLS; // 0x0954
	Vector m_vFanEndLS; // 0x0960
	Vector m_vNoiseDirectionTarget; // 0x096C
	CUtlSymbolLarge m_iszInfoFan; // 0x0978
	float32 m_flRopeForceScale; // 0x0980
	float32 m_flParticleForceScale; // 0x0984
	float32 m_flPlayerForce; // 0x0988
	bool m_bPlayerWindblock; // 0x098C
	float32 m_flNPCForce; // 0x0990
	float32 m_flRampTime; // 0x0994
	float32 m_fNoiseDegrees; // 0x0998
	float32 m_fNoiseSpeed; // 0x099C
	bool m_bPushPlayer; // 0x09A0
	bool m_bRampDown; // 0x09A1
	int32 m_nManagerFanIdx; // 0x09A4
};
class CPhysHingeAlias_phys_hinge_local : public CPhysHinge // server
{
};
class CLogicCase : public CLogicalEntity // server
{
	CUtlSymbolLarge[32] m_nCase; // 0x04A8
	int32 m_nShuffleCases; // 0x05A8
	int32 m_nLastShuffleCase; // 0x05AC
	uint8[32] m_uchShuffleCaseMap; // 0x05B0
	CEntityIOOutput[32] m_OnCase; // 0x05D0
	CEntityOutputTemplate< CUtlString > m_OnDefault; // 0x08D0
};
class CPulseCell_Outflow_PlayVOLine : public CPulseCell_BaseYieldingInflow // server
{
	CPulse_ResumePoint m_OnFinished; // 0x00D8
};
class CInfoGameEventProxy : public CPointEntity // server
{
	CUtlSymbolLarge m_iszEventName; // 0x04A8
	float32 m_flRange; // 0x04B0
};
class CTestPulseIOComponent_DerivedAPI // server
{
};
class CWeaponBizon : public CCSWeaponBaseGun // server
{
};
class CGamePlayerZone : public CRuleBrushEntity // server
{
	CEntityIOOutput m_OnPlayerInZone; // 0x0778
	CEntityIOOutput m_OnPlayerOutZone; // 0x0790
	CEntityOutputTemplate< int32 > m_PlayersInCount; // 0x07A8
	CEntityOutputTemplate< int32 > m_PlayersOutCount; // 0x07C8
};
class CBaseToggle : public CBaseModelEntity // server
{
	TOGGLE_STATE m_toggle_state; // 0x0770
	float32 m_flMoveDistance; // 0x0774
	float32 m_flWait; // 0x0778
	float32 m_flLip; // 0x077C
	bool m_bAlwaysFireBlockedOutputs; // 0x0780
	Vector m_vecPosition1; // 0x0784
	Vector m_vecPosition2; // 0x0790
	QAngle m_vecMoveAng; // 0x079C
	QAngle m_vecAngle1; // 0x07A8
	QAngle m_vecAngle2; // 0x07B4
	float32 m_flHeight; // 0x07C0
	CHandle< CBaseEntity > m_hActivator; // 0x07C4
	Vector m_vecFinalDest; // 0x07C8
	QAngle m_vecFinalAngle; // 0x07D4
	int32 m_movementType; // 0x07E0
	CUtlSymbolLarge m_sMaster; // 0x07E8
};
class CPulseServerCursor : public CPulseExecCursor // server
{
	CHandle< CBaseEntity > m_hActivator; // 0x00E8
	CHandle< CBaseEntity > m_hCaller; // 0x00EC
};
class CPulseCell_PlaySequence : public CPulseCell_BaseYieldingInflow // server
{
	CUtlString m_SequenceName; // 0x00D8
	PulseNodeDynamicOutflows_t m_PulseAnimEvents; // 0x00E0
	CPulse_ResumePoint m_OnFinished; // 0x00F8
};
class CInferno : public CBaseModelEntity // server
{
	VectorWS[64] m_firePositions; // 0x0770
	VectorWS[64] m_fireParentPositions; // 0x0A70
	bool[64] m_bFireIsBurning; // 0x0D70
	Vector[64] m_BurnNormal; // 0x0DB0
	int32 m_fireCount; // 0x10B0
	int32 m_nInfernoType; // 0x10B4
	int32 m_nFireEffectTickBegin; // 0x10B8
	float32 m_nFireLifetime; // 0x10BC
	bool m_bInPostEffectTime; // 0x10C0
	bool m_bWasCreatedInSmoke; // 0x10C1
	Extent m_extent; // 0x12C8
	CountdownTimer m_damageTimer; // 0x12E0
	CountdownTimer m_damageRampTimer; // 0x12F8
	Vector m_splashVelocity; // 0x1310
	Vector m_InitialSplashVelocity; // 0x131C
	VectorWS m_startPos; // 0x1328
	VectorWS m_vecOriginalSpawnLocation; // 0x1334
	IntervalTimer m_activeTimer; // 0x1340
	int32 m_fireSpawnOffset; // 0x1350
	int32 m_nMaxFlames; // 0x1354
	int32 m_nSpreadCount; // 0x1358
	CountdownTimer m_BookkeepingTimer; // 0x1360
	CountdownTimer m_NextSpreadTimer; // 0x1378
	uint16 m_nSourceItemDefIndex; // 0x1390
};
class CTouchExpansionComponent : public CEntityComponent // server
{
};
class CPulseCell_Outflow_PlaySceneBase : public CPulseCell_BaseYieldingInflow // server
{
	CPulse_ResumePoint m_OnFinished; // 0x00D8
	CUtlVector< CPulse_OutflowConnection > m_Triggers; // 0x0120
};
class CPulseCell_LerpCameraSettings : public CPulseCell_BaseLerp // server
{
	float32 m_flSeconds; // 0x0120
	PointCameraSettings_t m_Start; // 0x0124
	PointCameraSettings_t m_End; // 0x0134
};
class CWeaponSCAR20 : public CCSWeaponBaseGun // server
{
};
class CFuncInteractionLayerClip : public CBaseModelEntity // server
{
	bool m_bDisabled; // 0x0770
	CUtlSymbolLarge m_iszInteractsAs; // 0x0778
	CUtlSymbolLarge m_iszInteractsWith; // 0x0780
};
class CCSObserver_UseServices : public CPlayer_UseServices // server
{
};
class CTriggerDetectBulletFire : public CBaseTrigger // server
{
	bool m_bPlayerFireOnly; // 0x08E8
	CEntityIOOutput m_OnDetectedBulletFire; // 0x08F0
};
class CCSPlayer_UseServices : public CPlayer_UseServices // server
{
	CHandle< CBaseEntity > m_hLastKnownUseEntity; // 0x0048
	GameTime_t m_flLastUseTimeStamp; // 0x004C
	GameTime_t m_flTimeLastUsedWindow; // 0x0050
};
class CWeaponAWP : public CCSWeaponBaseGun // server
{
};
class CPulseCell_PickBestOutflowSelector : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseBestOutflowRules_t m_nCheckType; // 0x0048
	PulseSelectorOutflowList_t m_OutflowList; // 0x0050
};
class CInfoFan : public CPointEntity // server
{
	float32 m_fFanForceMaxRadius; // 0x04E8
	float32 m_fFanForceMinRadius; // 0x04EC
	float32 m_flCurveDistRange; // 0x04F0
	CUtlSymbolLarge m_FanForceCurveString; // 0x04F8
};
class CCSWeaponBase_API // server
{
};
class CGameRules // server
{
	CNetworkVarChainer __m_pChainEntity; // 0x0008
	char[128] m_szQuestName; // 0x0030
	int32 m_nQuestPhase; // 0x00B0
	uint32 m_nLastMatchTime; // 0x00B4
	uint64 m_nLastMatchTime_MatchID64; // 0x00B8
	int32 m_nTotalPausedTicks; // 0x00C0
	int32 m_nPauseStartTick; // 0x00C4
	bool m_bGamePaused; // 0x00C8
};
class CFish : public CBaseAnimGraph // server
{
	CHandle< CFishPool > m_pool; // 0x0960
	uint32 m_id; // 0x0964
	float32 m_x; // 0x0968
	float32 m_y; // 0x096C
	float32 m_z; // 0x0970
	float32 m_angle; // 0x0974
	float32 m_angleChange; // 0x0978
	Vector m_forward; // 0x097C
	Vector m_perp; // 0x0988
	VectorWS m_poolOrigin; // 0x0994
	float32 m_waterLevel; // 0x09A0
	float32 m_speed; // 0x09A4
	float32 m_desiredSpeed; // 0x09A8
	float32 m_calmSpeed; // 0x09AC
	float32 m_panicSpeed; // 0x09B0
	float32 m_avoidRange; // 0x09B4
	CountdownTimer m_turnTimer; // 0x09B8
	bool m_turnClockwise; // 0x09D0
	CountdownTimer m_goTimer; // 0x09D8
	CountdownTimer m_moveTimer; // 0x09F0
	CountdownTimer m_panicTimer; // 0x0A08
	CountdownTimer m_disperseTimer; // 0x0A20
	CountdownTimer m_proximityTimer; // 0x0A38
	CUtlVector< CFish* > m_visible; // 0x0A50
};
class CCSBot : public CBot // server
{
	VectorWS m_eyePosition; // 0x0108
	char[64] m_name; // 0x0114
	float32 m_combatRange; // 0x0154
	bool m_isRogue; // 0x0158
	CountdownTimer m_rogueTimer; // 0x0160
	bool m_diedLastRound; // 0x017C
	float32 m_safeTime; // 0x0180
	bool m_wasSafe; // 0x0184
	bool m_blindFire; // 0x018C
	CountdownTimer m_surpriseTimer; // 0x0190
	bool m_bAllowActive; // 0x01A8
	bool m_isFollowing; // 0x01A9
	CHandle< CCSPlayerPawn > m_leader; // 0x01AC
	float32 m_followTimestamp; // 0x01B0
	float32 m_allowAutoFollowTime; // 0x01B4
	CountdownTimer m_hurryTimer; // 0x01B8
	CountdownTimer m_alertTimer; // 0x01D0
	CountdownTimer m_sneakTimer; // 0x01E8
	CountdownTimer m_panicTimer; // 0x0200
	float32 m_stateTimestamp; // 0x05C8
	bool m_isAttacking; // 0x05CC
	bool m_isOpeningDoor; // 0x05CD
	CHandle< CBaseEntity > m_taskEntity; // 0x05D4
	VectorWS m_goalPosition; // 0x05E4
	CHandle< CBaseEntity > m_goalEntity; // 0x05F0
	CHandle< CBaseEntity > m_avoid; // 0x05F4
	float32 m_avoidTimestamp; // 0x05F8
	bool m_isStopping; // 0x05FC
	bool m_hasVisitedEnemySpawn; // 0x05FD
	IntervalTimer m_stillTimer; // 0x0600
	bool m_bEyeAnglesUnderPathFinderControl; // 0x0610
	int32 m_pathIndex; // 0x4F08
	GameTime_t m_areaEnteredTimestamp; // 0x4F0C
	CountdownTimer m_repathTimer; // 0x4F10
	CountdownTimer m_avoidFriendTimer; // 0x4F28
	bool m_isFriendInTheWay; // 0x4F40
	CountdownTimer m_politeTimer; // 0x4F48
	bool m_isWaitingBehindFriend; // 0x4F60
	float32 m_pathLadderEnd; // 0x4F8C
	CountdownTimer m_mustRunTimer; // 0x4FD8
	CountdownTimer m_waitTimer; // 0x4FF0
	CountdownTimer m_updateTravelDistanceTimer; // 0x5008
	float32[64] m_playerTravelDistance; // 0x5020
	uint8 m_travelDistancePhase; // 0x5120
	uint8 m_hostageEscortCount; // 0x52B8
	float32 m_hostageEscortCountTimestamp; // 0x52BC
	int32 m_desiredTeam; // 0x52C0
	bool m_hasJoined; // 0x52C4
	bool m_isWaitingForHostage; // 0x52C5
	CountdownTimer m_inhibitWaitingForHostageTimer; // 0x52C8
	CountdownTimer m_waitForHostageTimer; // 0x52E0
	VectorWS m_noisePosition; // 0x52F8
	float32 m_noiseTravelDistance; // 0x5304
	float32 m_noiseTimestamp; // 0x5308
	CCSPlayerPawn* m_noiseSource; // 0x5310
	CountdownTimer m_noiseBendTimer; // 0x5328
	VectorWS m_bentNoisePosition; // 0x5340
	bool m_bendNoisePositionValid; // 0x534C
	float32 m_lookAroundStateTimestamp; // 0x5350
	float32 m_lookAheadAngle; // 0x5354
	float32 m_lookUpAngle; // 0x5358
	float32 m_forwardAngle; // 0x535C
	float32 m_inhibitLookAroundTimestamp; // 0x5360
	VectorWS m_lookAtSpot; // 0x5368
	float32 m_lookAtSpotDuration; // 0x5378
	float32 m_lookAtSpotTimestamp; // 0x537C
	float32 m_lookAtSpotAngleTolerance; // 0x5380
	bool m_lookAtSpotClearIfClose; // 0x5384
	bool m_lookAtSpotAttack; // 0x5385
	char* m_lookAtDesc; // 0x5388
	float32 m_peripheralTimestamp; // 0x5390
	uint8 m_approachPointCount; // 0x5518
	VectorWS m_approachPointViewPosition; // 0x551C
	IntervalTimer m_viewSteadyTimer; // 0x5528
	CountdownTimer m_tossGrenadeTimer; // 0x5540
	CountdownTimer m_isAvoidingGrenade; // 0x5560
	float32 m_spotCheckTimestamp; // 0x5580
	int32 m_checkedHidingSpotCount; // 0x5988
	float32 m_lookPitch; // 0x598C
	float32 m_lookPitchVel; // 0x5990
	float32 m_lookYaw; // 0x5994
	float32 m_lookYawVel; // 0x5998
	VectorWS m_targetSpot; // 0x599C
	Vector m_targetSpotVelocity; // 0x59A8
	VectorWS m_targetSpotPredicted; // 0x59B4
	QAngle m_aimError; // 0x59C0
	QAngle m_aimGoal; // 0x59CC
	GameTime_t m_targetSpotTime; // 0x59D8
	float32 m_aimFocus; // 0x59DC
	float32 m_aimFocusInterval; // 0x59E0
	GameTime_t m_aimFocusNextUpdate; // 0x59E4
	CountdownTimer m_ignoreEnemiesTimer; // 0x59F0
	CHandle< CCSPlayerPawn > m_enemy; // 0x5A08
	bool m_isEnemyVisible; // 0x5A0C
	uint8 m_visibleEnemyParts; // 0x5A0D
	VectorWS m_lastEnemyPosition; // 0x5A10
	float32 m_lastSawEnemyTimestamp; // 0x5A1C
	float32 m_firstSawEnemyTimestamp; // 0x5A20
	float32 m_currentEnemyAcquireTimestamp; // 0x5A24
	float32 m_enemyDeathTimestamp; // 0x5A28
	float32 m_friendDeathTimestamp; // 0x5A2C
	bool m_isLastEnemyDead; // 0x5A30
	int32 m_nearbyEnemyCount; // 0x5A34
	CHandle< CCSPlayerPawn > m_bomber; // 0x5C40
	int32 m_nearbyFriendCount; // 0x5C44
	CHandle< CCSPlayerPawn > m_closestVisibleFriend; // 0x5C48
	CHandle< CCSPlayerPawn > m_closestVisibleHumanFriend; // 0x5C4C
	IntervalTimer m_attentionInterval; // 0x5C50
	CHandle< CCSPlayerPawn > m_attacker; // 0x5C60
	float32 m_attackedTimestamp; // 0x5C64
	IntervalTimer m_burnedByFlamesTimer; // 0x5C68
	int32 m_lastVictimID; // 0x5C78
	bool m_isAimingAtEnemy; // 0x5C7C
	bool m_isRapidFiring; // 0x5C7D
	IntervalTimer m_equipTimer; // 0x5C80
	CountdownTimer m_zoomTimer; // 0x5C90
	GameTime_t m_fireWeaponTimestamp; // 0x5CA8
	CountdownTimer m_lookForWeaponsOnGroundTimer; // 0x5CB0
	bool m_bIsSleeping; // 0x5CC8
	bool m_isEnemySniperVisible; // 0x5CC9
	CountdownTimer m_sawEnemySniperTimer; // 0x5CD0
	uint8 m_enemyQueueIndex; // 0x5D88
	uint8 m_enemyQueueCount; // 0x5D89
	uint8 m_enemyQueueAttendIndex; // 0x5D8A
	bool m_isStuck; // 0x5D8B
	GameTime_t m_stuckTimestamp; // 0x5D8C
	VectorWS m_stuckSpot; // 0x5D90
	CountdownTimer m_wiggleTimer; // 0x5DA0
	CountdownTimer m_stuckJumpTimer; // 0x5DB8
	GameTime_t m_nextCleanupCheckTimestamp; // 0x5DD0
	float32[10] m_avgVel; // 0x5DD4
	int32 m_avgVelIndex; // 0x5DFC
	int32 m_avgVelCount; // 0x5E00
	VectorWS m_lastOrigin; // 0x5E04
	float32 m_lastRadioRecievedTimestamp; // 0x5E14
	float32 m_lastRadioSentTimestamp; // 0x5E18
	CHandle< CCSPlayerPawn > m_radioSubject; // 0x5E1C
	VectorWS m_radioPosition; // 0x5E20
	float32 m_voiceEndTimestamp; // 0x5E2C
	int32 m_lastValidReactionQueueFrame; // 0x5E38
};
class CHandleTest : public CBaseEntity // server
{
	CHandle< CBaseEntity > m_Handle; // 0x04A8
	bool m_bSendHandle; // 0x04AC
};
class CLogicNPCCounter : public CBaseEntity // server
{
	CEntityIOOutput m_OnMinCountAll; // 0x04A8
	CEntityIOOutput m_OnMaxCountAll; // 0x04C0
	CEntityOutputTemplate< float32 > m_OnFactorAll; // 0x04D8
	CEntityOutputTemplate< float32 > m_OnMinPlayerDistAll; // 0x04F8
	CEntityIOOutput m_OnMinCount_1; // 0x0518
	CEntityIOOutput m_OnMaxCount_1; // 0x0530
	CEntityOutputTemplate< float32 > m_OnFactor_1; // 0x0548
	CEntityOutputTemplate< float32 > m_OnMinPlayerDist_1; // 0x0568
	CEntityIOOutput m_OnMinCount_2; // 0x0588
	CEntityIOOutput m_OnMaxCount_2; // 0x05A0
	CEntityOutputTemplate< float32 > m_OnFactor_2; // 0x05B8
	CEntityOutputTemplate< float32 > m_OnMinPlayerDist_2; // 0x05D8
	CEntityIOOutput m_OnMinCount_3; // 0x05F8
	CEntityIOOutput m_OnMaxCount_3; // 0x0610
	CEntityOutputTemplate< float32 > m_OnFactor_3; // 0x0628
	CEntityOutputTemplate< float32 > m_OnMinPlayerDist_3; // 0x0648
	CEntityHandle m_hSource; // 0x0668
	CUtlSymbolLarge m_iszSourceEntityName; // 0x0670
	float32 m_flDistanceMax; // 0x0678
	bool m_bDisabled; // 0x067C
	int32 m_nMinCountAll; // 0x0680
	int32 m_nMaxCountAll; // 0x0684
	int32 m_nMinFactorAll; // 0x0688
	int32 m_nMaxFactorAll; // 0x068C
	CUtlSymbolLarge m_iszNPCClassname_1; // 0x0698
	int32 m_nNPCState_1; // 0x06A0
	bool m_bInvertState_1; // 0x06A4
	int32 m_nMinCount_1; // 0x06A8
	int32 m_nMaxCount_1; // 0x06AC
	int32 m_nMinFactor_1; // 0x06B0
	int32 m_nMaxFactor_1; // 0x06B4
	float32 m_flDefaultDist_1; // 0x06BC
	CUtlSymbolLarge m_iszNPCClassname_2; // 0x06C0
	int32 m_nNPCState_2; // 0x06C8
	bool m_bInvertState_2; // 0x06CC
	int32 m_nMinCount_2; // 0x06D0
	int32 m_nMaxCount_2; // 0x06D4
	int32 m_nMinFactor_2; // 0x06D8
	int32 m_nMaxFactor_2; // 0x06DC
	float32 m_flDefaultDist_2; // 0x06E4
	CUtlSymbolLarge m_iszNPCClassname_3; // 0x06E8
	int32 m_nNPCState_3; // 0x06F0
	bool m_bInvertState_3; // 0x06F4
	int32 m_nMinCount_3; // 0x06F8
	int32 m_nMaxCount_3; // 0x06FC
	int32 m_nMinFactor_3; // 0x0700
	int32 m_nMaxFactor_3; // 0x0704
	float32 m_flDefaultDist_3; // 0x070C
};
class CCSPlayer_RadioServices : public CPlayerPawnComponent // server
{
	GameTime_t m_flGotHostageTalkTimer; // 0x0048
	GameTime_t m_flDefusingTalkTimer; // 0x004C
	GameTime_t m_flC4PlantTalkTimer; // 0x0050
	GameTime_t[3] m_flRadioTokenSlots; // 0x0054
	bool m_bIgnoreRadio; // 0x0060
};
class CWeaponSG556 : public CCSWeaponBaseGun // server
{
};
class CRagdollConstraint : public CPhysConstraint // server
{
	float32 m_xmin; // 0x0508
	float32 m_xmax; // 0x050C
	float32 m_ymin; // 0x0510
	float32 m_ymax; // 0x0514
	float32 m_zmin; // 0x0518
	float32 m_zmax; // 0x051C
	float32 m_xfriction; // 0x0520
	float32 m_yfriction; // 0x0524
	float32 m_zfriction; // 0x0528
};
class CFuncVehicleClip : public CBaseModelEntity // server
{
};
class CDEagle : public CCSWeaponBaseGun // server
{
};
class CWeaponFamas : public CCSWeaponBaseGun // server
{
};
class CEnvSplash : public CPointEntity // server
{
	float32 m_flScale; // 0x04A8
};
class CPointCameraVFOV : public CPointCamera // server
{
	float32 m_flVerticalFOV; // 0x0508
};
class CCSGO_WingmanIntroTerroristPosition : public CCSGO_WingmanIntroCharacterPosition // server
{
};
class CTestPulseIOAPI // server
{
};
class CCSWeaponBaseShotgun : public CCSWeaponBase // server
{
};
class CPrecipitationVData : public CEntitySubclassVDataBase // server
{
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > > m_szParticlePrecipitationEffect; // 0x0028
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > > m_szParticlePrecipitationPuddleEffect; // 0x0108
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > > m_szParticlePrecipitationPostEffect; // 0x01E8
	float32 m_flInnerDistance; // 0x02C8
	ParticleAttachment_t m_nAttachType; // 0x02CC
	bool m_bBatchSameVolumeType; // 0x02D0
	int32 m_nRTEnvCP; // 0x02D4
	int32 m_nRTEnvCPComponent; // 0x02D8
	CUtlString m_szModifier; // 0x02E0
	int32 m_nUseSnapshotFromSurfaceGraph; // 0x02E8
	PrecipitationFilter_t m_snapshotFilter; // 0x02EC
};
class CFuncMoveLinear : public CBaseToggle // server
{
	MoveLinearAuthoredPos_t m_authoredPosition; // 0x07F0
	QAngle m_angMoveEntitySpace; // 0x07F4
	Vector m_vecMoveDirParentSpace; // 0x0800
	CGameSoundEventName m_soundStart; // 0x0810
	CGameSoundEventName m_soundStop; // 0x0818
	CUtlSymbolLarge m_currentSound; // 0x0820
	float32 m_flBlockDamage; // 0x0828
	float32 m_flStartPosition; // 0x082C
	CEntityIOOutput m_OnFullyOpen; // 0x0838
	CEntityIOOutput m_OnFullyClosed; // 0x0850
	float32 m_flSpeed; // 0x0868
	bool m_bCreateMovableNavMesh; // 0x086C
	bool m_bAllowMovableNavMeshDockingOnEntireEntity; // 0x086D
	bool m_bCreateNavObstacle; // 0x086E
};
class CPhysMotorAPI // server
{
};
class CPulseCell_WaitForObservable : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulseObservableExpression< bool > m_Condition; // 0x00D8
	CPulse_ResumePoint m_OnTrue; // 0x0150
};
class CScriptItem : public CItem // server
{
	MoveType_t m_MoveTypeOverride; // 0x0A00
};
class CDynamicPropAlias_prop_dynamic_override : public CDynamicProp // server
{
};
class CBaseTrigger : public CBaseToggle // server
{
	CEntityIOOutput m_OnStartTouch; // 0x07F0
	CEntityIOOutput m_OnStartTouchAll; // 0x0808
	CEntityIOOutput m_OnEndTouch; // 0x0820
	CEntityIOOutput m_OnEndTouchAll; // 0x0838
	CEntityIOOutput m_OnTouching; // 0x0850
	CEntityIOOutput m_OnTouchingEachEntity; // 0x0868
	CEntityIOOutput m_OnNotTouching; // 0x0880
	CEntityIOOutput m_OnTouchingChanged; // 0x0898
	CUtlVector< CHandle< CBaseEntity > > m_hTouchingEntities; // 0x08B0
	CUtlSymbolLarge m_iFilterName; // 0x08C8
	CHandle< CBaseFilter > m_hFilter; // 0x08D0
	bool m_bDisabled; // 0x08D4
	bool m_bUseAsyncQueries; // 0x08E0
};
class CPointPush : public CPointEntity // server
{
	bool m_bEnabled; // 0x04A8
	float32 m_flMagnitude; // 0x04AC
	float32 m_flRadius; // 0x04B0
	float32 m_flInnerRadius; // 0x04B4
	float32 m_flConeOfInfluence; // 0x04B8
	CUtlSymbolLarge m_iszFilterName; // 0x04C0
	CHandle< CBaseFilter > m_hFilter; // 0x04C8
};
class CPulseCell_Step_EntFire : public CPulseCell_BaseFlow // server
{
	CUtlString m_Input; // 0x0048
};
class CCSObserver_ObserverServices : public CPlayer_ObserverServices // server
{
};
class CPlayerPing : public CBaseEntity // server
{
	CHandle< CCSPlayerPawn > m_hPlayer; // 0x04B0
	CHandle< CBaseEntity > m_hPingedEntity; // 0x04B4
	int32 m_iType; // 0x04B8
	bool m_bUrgent; // 0x04BC
	char[18] m_szPlaceName; // 0x04BD
};
class CHitboxComponent : public CEntityComponent // server
{
	float32 m_flBoundsExpandRadius; // 0x0014
};
class CRopeKeyframe : public CBaseModelEntity // server
{
	uint16 m_RopeFlags; // 0x0778
	CUtlSymbolLarge m_iNextLinkName; // 0x0780
	int16 m_Slack; // 0x0788
	float32 m_Width; // 0x078C
	float32 m_TextureScale; // 0x0790
	uint8 m_nSegments; // 0x0794
	bool m_bConstrainBetweenEndpoints; // 0x0795
	CUtlSymbolLarge m_strRopeMaterialModel; // 0x0798
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_iRopeMaterialModelIndex; // 0x07A0
	uint8 m_Subdiv; // 0x07A8
	uint8 m_nChangeCount; // 0x07A9
	int16 m_RopeLength; // 0x07AA
	uint8 m_fLockedPoints; // 0x07AC
	bool m_bCreatedFromMapFile; // 0x07AD
	float32 m_flScrollSpeed; // 0x07B0
	bool m_bStartPointValid; // 0x07B4
	bool m_bEndPointValid; // 0x07B5
	CHandle< CBaseEntity > m_hStartPoint; // 0x07B8
	CHandle< CBaseEntity > m_hEndPoint; // 0x07BC
	AttachmentHandle_t m_iStartAttachment; // 0x07C0
	AttachmentHandle_t m_iEndAttachment; // 0x07C1
};
class CSmokeGrenade : public CBaseCSGrenade // server
{
};
class CBaseCombatCharacter : public CBaseAnimGraph // server
{
	bool m_bForceServerRagdoll; // 0x0960
	CNetworkUtlVectorBase< CHandle< CEconWearable > > m_hMyWearables; // 0x0968
	float32 m_impactEnergyScale; // 0x0980
	bool m_bApplyStressDamage; // 0x0984
	bool m_bDeathEventsDispatched; // 0x0985
	CUtlVector< RelationshipOverride_t > m_vecRelationships; // 0x09C8
	CUtlSymbolLarge m_strRelationships; // 0x09E0
	Hull_t m_eHull; // 0x09E8
	uint32 m_nNavHullIdx; // 0x09EC
	CMovementStatsProperty m_movementStats; // 0x09F0
};
class CLogicGameStateReport : public CBaseEntity // server
{
	bool m_bDisabled; // 0x04A8
};
class ServerAuthoritativeWeaponSlot_t // server
{
	uint16 unClass; // 0x0030
	uint16 unSlot; // 0x0032
	uint16 unItemDefIdx; // 0x0034
};
class CPathQueryComponent : public CEntityComponent // server
{
};
class CLogicRelay : public CLogicalEntity // server
{
	CEntityIOOutput m_OnSpawn; // 0x04A8
	CEntityIOOutput m_OnTrigger; // 0x04C0
	bool m_bDisabled; // 0x04D8
	bool m_bWaitForRefire; // 0x04D9
	bool m_bTriggerOnce; // 0x04DA
	bool m_bFastRetrigger; // 0x04DB
	bool m_bPassthoughCaller; // 0x04DC
};
class SequenceHistory_t // server
{
	HSequence m_hSequence; // 0x0000
	GameTime_t m_flSeqStartTime; // 0x0004
	float32 m_flSeqFixedCycle; // 0x0008
	AnimLoopMode_t m_nSeqLoopMode; // 0x000C
	float32 m_flPlaybackRate; // 0x0010
	float32 m_flCyclesPerSecond; // 0x0014
};
class CPlayer_ItemServices : public CPlayerPawnComponent // server
{
};
class CPulse_OutflowConnection // pulse_runtime_lib
{
	PulseSymbol_t m_SourceOutflowName; // 0x0000
	PulseRuntimeChunkIndex_t m_nDestChunk; // 0x0010
	int32 m_nInstruction; // 0x0014
	PulseRegisterMap_t m_OutflowRegisterMap; // 0x0018
};
class CTestPulseIO : public CLogicalEntity // server
{
	CEntityIOOutput m_OnVariantVoid; // 0x04A8
	CEntityOutputTemplate< bool > m_OnVariantBool; // 0x04C0
	CEntityOutputTemplate< int32 > m_OnVariantInt; // 0x04E0
	CEntityOutputTemplate< float32 > m_OnVariantFloat; // 0x0500
	CEntityOutputTemplate< CUtlSymbolLarge > m_OnVariantString; // 0x0520
	CEntityOutputTemplate< Color > m_OnVariantColor; // 0x0540
	CEntityOutputTemplate< Vector > m_OnVariantVector; // 0x0560
	bool m_bAllowEmptyInputs; // 0x0588
	CTestPulseIOComponent_Derived m_TestComponent; // 0x0590
	CEntityIOOutput m_OnInternalTestVoid; // 0x05C0
	CEntityOutputTemplate< bool > m_OnInternalTestBool; // 0x05D8
	CEntityOutputTemplate< int32 > m_OnInternalTestInt; // 0x05F8
	CEntityOutputTemplate< float32 > m_OnInternalTestFloat; // 0x0618
	CEntityOutputTemplate< CUtlSymbolLarge > m_OnInternalTestString; // 0x0638
	CEntityOutputTemplate< Color > m_OnInternalTestColor; // 0x0658
	CEntityOutputTemplate< Vector > m_OnInternalTestVector; // 0x0678
	CEntityOutputTemplate< CEntityNameString > m_OnInternalTestEntityName; // 0x06A0
	CEntityOutputTemplate< CHandle< CBaseEntity > > m_OnInternalTestEntityHandle; // 0x06C0
	CEntityOutputTemplate< TestInputOutputCombinationsEnum_t > m_OnInternalTestSchemaEnum; // 0x06E0
	CEntityOutputTemplate< CTestPulseIO::FloatStringArgs_t > m_OnInternalTestFloatString; // 0x0700
	CEntityOutputTemplate< CTestPulseIO::EntityNameStringArgs_t > m_OnInternalTestEntityNameString; // 0x0728
	CEntityOutputTemplate< CTestPulseIO::EntityHandleIntArgs_t > m_OnInternalTestEntityHandleInt; // 0x0750
	CEntityOutputTemplate< CTestPulseIO::ThreeStringArgs_t > m_OnInternalTestStringStringString; // 0x0770
};
class CWeaponUMP45 : public CCSWeaponBaseGun // server
{
};
class CGamePlayerEquip : public CRulePointEntity // server
{
};
class CPointEntityFinder : public CBaseEntity // server
{
	CHandle< CBaseEntity > m_hEntity; // 0x04A8
	CUtlSymbolLarge m_iFilterName; // 0x04B0
	CHandle< CBaseFilter > m_hFilter; // 0x04B8
	CUtlSymbolLarge m_iRefName; // 0x04C0
	CHandle< CBaseEntity > m_hReference; // 0x04C8
	EntFinderMethod_t m_FindMethod; // 0x04CC
	CEntityIOOutput m_OnFoundEntity; // 0x04D0
};
class CPulseGraphDef // pulse_runtime_lib
{
	PulseSymbol_t m_DomainIdentifier; // 0x0008
	CPulseValueFullType m_DomainSubType; // 0x0018
	PulseSymbol_t m_ParentMapName; // 0x0030
	PulseSymbol_t m_ParentXmlName; // 0x0040
	CUtlVector< CPulse_Chunk* > m_Chunks; // 0x0050
	CUtlVector< CPulseCell_Base* > m_Cells; // 0x0068
	CUtlVector< CPulse_Variable > m_Vars; // 0x0080
	CUtlVector< CPulse_PublicOutput > m_PublicOutputs; // 0x0098
	CUtlVector< CPulse_InvokeBinding* > m_InvokeBindings; // 0x00B0
	CUtlVector< CPulse_CallInfo* > m_CallInfos; // 0x00C8
	CUtlVector< CPulse_Constant > m_Constants; // 0x00E0
	CUtlVector< CPulse_DomainValue > m_DomainValues; // 0x00F8
	CUtlVector< CPulse_BlackboardReference > m_BlackboardReferences; // 0x0110
	CUtlVector< CPulse_OutputConnection* > m_OutputConnections; // 0x0128
};
class CKnife : public CCSWeaponBase // server
{
	bool m_bFirstAttack; // 0x1050
};
class CLogicPlayerProxy : public CLogicalEntity // server
{
	CEntityIOOutput m_PlayerHasAmmo; // 0x04A8
	CEntityIOOutput m_PlayerHasNoAmmo; // 0x04C0
	CEntityIOOutput m_PlayerDied; // 0x04D8
	CEntityOutputTemplate< int32 > m_RequestedPlayerHealth; // 0x04F0
	CHandle< CBaseEntity > m_hPlayer; // 0x0510
};
class CCSGO_TeamIntroCharacterPosition : public CCSGO_TeamPreviewCharacterPosition // server
{
};
class CBasePlayerControllerAPI // server
{
};
class CHostageRescueZoneShim : public CBaseTrigger // server
{
};
class CSimpleMarkupVolumeTagged : public CMarkupVolumeTagged // server
{
};
class CEnvSoundscapeAlias_snd_soundscape : public CEnvSoundscape // server
{
};
class CCSPlayer_HostageServices : public CPlayerPawnComponent // server
{
	CHandle< CBaseEntity > m_hCarriedHostage; // 0x0048
	CHandle< CBaseEntity > m_hCarriedHostageProp; // 0x004C
};
class CEnvLightProbeVolumeAPI // server
{
};
class CRenderComponent : public CEntityComponent // server
{
	CNetworkVarChainer __m_pChainEntity; // 0x0010
	bool m_bIsRenderingWithViewModels; // 0x0050
	uint32 m_nSplitscreenFlags; // 0x0054
	bool m_bEnableRendering; // 0x0058
	bool m_bInterpolationReadyToDraw; // 0x00A8
};
class CWaterBullet : public CBaseAnimGraph // server
{
};
class CTriggerSoundscape : public CBaseTrigger // server
{
	CHandle< CEnvSoundscapeTriggerable > m_hSoundscape; // 0x08E8
	CUtlSymbolLarge m_SoundscapeName; // 0x08F0
	CUtlVector< CHandle< CBasePlayerPawn > > m_spectators; // 0x08F8
};
class CBaseGrenade_API // server
{
};
class CPulseCell_Outflow_PlayVOLine::CursorState_t // server
{
	CHandle< CBaseEntity > m_sceneInstance; // 0x0000
};
class CPointTeleportAPI // server
{
};
class CHostageExpresserShim : public CBaseCombatCharacter // server
{
	CAI_Expresser* m_pExpresser; // 0x0A30
};
class CPointChildModifier : public CPointEntity // server
{
	bool m_bOrphanInsteadOfDeletingChildrenOnRemove; // 0x04A8
};
class CCSPlayerLegacyJump // server
{
	bool m_bOldJumpPressed; // 0x0010
	float32 m_flJumpPressedTime; // 0x0014
};
class CWeaponHKP2000 : public CCSWeaponBaseGun // server
{
};
class CShatterGlassShardPhysics : public CBaseModelEntity // server
{
	uint32 m_hParentShard; // 0x0770
	shard_model_desc_t m_ShardDesc; // 0x0778
	ShatterGlassEntityPoolState_t m_nPoolState; // 0x07F8
	bool m_bTouchedByPlayer; // 0x07FC
};
class CPathParticleRope : public CBaseEntity // server
{
	bool m_bStartActive; // 0x04B0
	float32 m_flMaxSimulationTime; // 0x04B4
	CUtlSymbolLarge m_iszEffectName; // 0x04B8
	CUtlVector< CUtlSymbolLarge > m_PathNodes_Name; // 0x04C0
	float32 m_flParticleSpacing; // 0x04D8
	float32 m_flSlack; // 0x04DC
	float32 m_flRadius; // 0x04E0
	Color m_ColorTint; // 0x04E4
	int32 m_nEffectState; // 0x04E8
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_iEffectIndex; // 0x04F0
	CNetworkUtlVectorBase< Vector > m_PathNodes_Position; // 0x04F8
	CNetworkUtlVectorBase< Vector > m_PathNodes_TangentIn; // 0x0510
	CNetworkUtlVectorBase< Vector > m_PathNodes_TangentOut; // 0x0528
	CNetworkUtlVectorBase< Vector > m_PathNodes_Color; // 0x0540
	CNetworkUtlVectorBase< bool > m_PathNodes_PinEnabled; // 0x0558
	CNetworkUtlVectorBase< float32 > m_PathNodes_RadiusScale; // 0x0570
};
class CCredits : public CPointEntity // server
{
	CEntityIOOutput m_OnCreditsDone; // 0x04A8
	bool m_bRolledOutroCredits; // 0x04C0
	float32 m_flLogoLength; // 0x04C4
};
class CWeaponFiveSeven : public CCSWeaponBaseGun // server
{
};
class CFishPool : public CBaseEntity // server
{
	int32 m_fishCount; // 0x04B8
	float32 m_maxRange; // 0x04BC
	float32 m_swimDepth; // 0x04C0
	float32 m_waterLevel; // 0x04C4
	bool m_isDormant; // 0x04C8
	CUtlVector< CHandle< CFish > > m_fishes; // 0x04D0
	CountdownTimer m_visTimer; // 0x04E8
};
class CPlayer_MovementServices : public CPlayerPawnComponent // server
{
	int32 m_nImpulse; // 0x0048
	CInButtonState m_nButtons; // 0x0050
	uint64 m_nQueuedButtonDownMask; // 0x0070
	uint64 m_nQueuedButtonChangeMask; // 0x0078
	uint64 m_nButtonDoublePressed; // 0x0080
	uint32[64] m_pButtonPressedCmdNumber; // 0x0088
	uint32 m_nLastCommandNumberProcessed; // 0x0188
	uint64 m_nToggleButtonDownMask; // 0x0190
	float32 m_flCmdForwardMove; // 0x01A0
	float32 m_flCmdLeftMove; // 0x01A4
	float32 m_flCmdUpMove; // 0x01A8
	float32 m_flMaxspeed; // 0x01AC
	float32[4] m_arrForceSubtickMoveWhen; // 0x01B0
	float32 m_flForwardMove; // 0x01C0
	float32 m_flLeftMove; // 0x01C4
	float32 m_flUpMove; // 0x01C8
	Vector m_vecLastMovementImpulses; // 0x01CC
	QAngle m_vecOldViewAngles; // 0x0240
};
class CRagdollPropAlias_physics_prop_ragdoll : public CRagdollProp // server
{
};
class CBreakableProp : public CBaseProp // server
{
	CPropDataComponent m_CPropDataComponent; // 0x0998
	CEntityIOOutput m_OnStartDeath; // 0x09D8
	CEntityIOOutput m_OnBreak; // 0x09F0
	CEntityOutputTemplate< float32 > m_OnHealthChanged; // 0x0A08
	CEntityIOOutput m_OnTakeDamage; // 0x0A28
	float32 m_impactEnergyScale; // 0x0A40
	int32 m_iMinHealthDmg; // 0x0A44
	QAngle m_preferredCarryAngles; // 0x0A48
	float32 m_flPressureDelay; // 0x0A54
	float32 m_flDefBurstScale; // 0x0A58
	Vector m_vDefBurstOffset; // 0x0A5C
	CHandle< CBaseEntity > m_hBreaker; // 0x0A68
	PerformanceMode_t m_PerformanceMode; // 0x0A6C
	GameTime_t m_flPreventDamageBeforeTime; // 0x0A70
	BreakableContentsType_t m_BreakableContentsType; // 0x0A74
	CUtlString m_strBreakableContentsPropGroupOverride; // 0x0A78
	CUtlString m_strBreakableContentsParticleOverride; // 0x0A80
	bool m_bHasBreakPiecesOrCommands; // 0x0A88
	float32 m_explodeDamage; // 0x0A8C
	float32 m_explodeRadius; // 0x0A90
	CGlobalSymbol m_sExplosionType; // 0x0A98
	float32 m_explosionDelay; // 0x0AA0
	CUtlSymbolLarge m_explosionBuildupSound; // 0x0AA8
	CUtlSymbolLarge m_explosionCustomEffect; // 0x0AB0
	CUtlSymbolLarge m_explosionCustomSound; // 0x0AB8
	CUtlSymbolLarge m_explosionModifier; // 0x0AC0
	CHandle< CBasePlayerPawn > m_hPhysicsAttacker; // 0x0AC8
	GameTime_t m_flLastPhysicsInfluenceTime; // 0x0ACC
	float32 m_flDefaultFadeScale; // 0x0AD0
	CHandle< CBaseEntity > m_hLastAttacker; // 0x0AD4
	CUtlSymbolLarge m_iszPuntSound; // 0x0AD8
	bool m_bUsePuntSound; // 0x0AE0
	bool m_bOriginalBlockLOS; // 0x0AE1
};
class CLightEntity : public CBaseModelEntity // server
{
	CLightComponent* m_CLightComponent; // 0x0770
};
class CInfoDynamicShadowHintBox : public CInfoDynamicShadowHint // server
{
	Vector m_vBoxMins; // 0x04C0
	Vector m_vBoxMaxs; // 0x04CC
};
class CBaseAnimGraphController : public CSkeletonAnimationController // server
{
	AnimationAlgorithm_t m_nAnimationAlgorithm; // 0x0018
	ExternalAnimGraphHandle_t m_nNextExternalGraphHandle; // 0x001C
	CNetworkUtlVectorBase< CGlobalSymbol > m_vecSecondarySkeletonSlotIDs; // 0x0020
	CNetworkUtlVectorBase< CHandle< CBaseAnimGraph > > m_vecSecondarySkeletons; // 0x0038
	int32 m_nSecondarySkeletonMasterCount; // 0x0050
	float32 m_flSoundSyncTime; // 0x0054
	uint32 m_nActiveIKChainMask; // 0x0058
	HSequence m_hSequence; // 0x005C
	GameTime_t m_flSeqStartTime; // 0x0060
	float32 m_flSeqFixedCycle; // 0x0064
	AnimLoopMode_t m_nAnimLoopMode; // 0x0068
	CNetworkedQuantizedFloat m_flPlaybackRate; // 0x006C
	SequenceFinishNotifyState_t m_nNotifyState; // 0x0078
	bool m_bNetworkedAnimationInputsChanged; // 0x0079
	bool m_bNetworkedSequenceChanged; // 0x007A
	bool m_bLastUpdateSkipped; // 0x007B
	bool m_bSequenceFinished; // 0x007C
	GameTick_t m_nPrevAnimUpdateTick; // 0x0080
	CStrongHandle< InfoForResourceTypeCNmGraphDefinition > m_hGraphDefinitionAG2; // 0x0320
	CUtlVectorEmbeddedNetworkVar< AnimGraph2SerializedPoseRecipeSlot_t > m_SerializePoseRecipeAG2Slots; // 0x0328
	CNetworkUtlVectorBase< uint8 > m_SerializePoseRecipeAG2Dynamic; // 0x0390
	uint32 m_nSerializePoseRecipeAG2ActiveSlot; // 0x03A8
	int32 m_nSerializePoseRecipeVersionAG2; // 0x03AC
	int32 m_nServerGraphInstanceIteration; // 0x03C0
	int32 m_nServerSerializationContextIteration; // 0x03C4
	ResourceId_t m_primaryGraphId; // 0x03C8
	CNetworkUtlVectorBase< ResourceId_t > m_vecExternalGraphIds; // 0x03D0
	CNetworkUtlVectorBase< ResourceId_t > m_vecExternalClipIds; // 0x03E8
	CGlobalSymbol m_sAnimGraph2Identifier; // 0x0400
	CAnimGraph2InstancePtr m_pGraphInstanceAG2; // 0x0408
	CExternalAnimGraphList m_vecExternalGraphs; // 0x0628
};
class AnimGraph2SerializedPoseRecipeSlot_t // server
{
	CUtlBinaryBlock m_topology; // 0x0030
};
class CBuoyancyHelper // server
{
	IPhysicsMotionController* m_pController; // 0x0008
	CUtlStringToken m_nFluidType; // 0x0018
	float32 m_flFluidDensity; // 0x001C
	float32 m_flNeutrallyBuoyantGravity; // 0x0020
	float32 m_flNeutrallyBuoyantLinearDamping; // 0x0024
	float32 m_flNeutrallyBuoyantAngularDamping; // 0x0028
	bool m_bNeutrallyBuoyant; // 0x002C
	CUtlVector< float32 > m_vecFractionOfWheelSubmergedForWheelFriction; // 0x0030
	CUtlVector< float32 > m_vecWheelFrictionScales; // 0x0048
	CUtlVector< float32 > m_vecFractionOfWheelSubmergedForWheelDrag; // 0x0060
	CUtlVector< float32 > m_vecWheelDrag; // 0x0078
};
class COrnamentProp : public CDynamicProp // server
{
	CUtlSymbolLarge m_initialOwner; // 0x0BA0
};
class CCSPlayer_CameraServices : public CCSPlayerBase_CameraServices // server
{
};
class CModelPointEntity : public CBaseModelEntity // server
{
};
class CRectLight : public CBarnLight // server
{
	bool m_bShowLight; // 0x0A58
};
class CFilterMultiple : public CBaseFilter // server
{
	filter_t m_nFilterType; // 0x04E0
	CUtlSymbolLarge[10] m_iFilterName; // 0x04E8
	CHandle< CBaseEntity >[10] m_hFilter; // 0x0538
};
class CCSPlayerResource : public CBaseEntity // server
{
	bool[12] m_bHostageAlive; // 0x04A8
	bool[12] m_isHostageFollowingSomeone; // 0x04B4
	CEntityIndex[12] m_iHostageEntityIDs; // 0x04C0
	VectorWS m_bombsiteCenterA; // 0x04F0
	VectorWS m_bombsiteCenterB; // 0x04FC
	int32[4] m_hostageRescueX; // 0x0508
	int32[4] m_hostageRescueY; // 0x0518
	int32[4] m_hostageRescueZ; // 0x0528
	bool m_bEndMatchNextMapAllVoted; // 0x0538
	bool m_foundGoalPositions; // 0x0539
};
class CPulseCell_FireCursors : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outflows; // 0x00D8
	bool m_bWaitForChildOutflows; // 0x00F0
	CPulse_ResumePoint m_OnFinished; // 0x00F8
};
class CFuncNavBlocker : public CBaseModelEntity // server
{
	bool m_bDisabled; // 0x0778
	int32 m_nBlockedTeamNumber; // 0x077C
};
class CMoverPathNode : public CPathNode // server
{
	CEntityOutputTemplate< CUtlString > m_OnStartFromOrInSegment; // 0x0500
	CEntityOutputTemplate< CUtlString > m_OnStoppedAtOrInSegment; // 0x0520
	CEntityOutputTemplate< CUtlString > m_OnPassThrough; // 0x0540
	CEntityOutputTemplate< CUtlString > m_OnPassThroughForward; // 0x0560
	CEntityOutputTemplate< CUtlString > m_OnPassThroughReverse; // 0x0580
};
class CEnvSoundscape : public CBaseEntity // server
{
	CEntityIOOutput m_OnPlay; // 0x04A8
	float32 m_flRadius; // 0x04C0
	CGameSoundEventName m_soundEventName; // 0x04C8
	bool m_bOverrideWithEvent; // 0x04D0
	int32 m_soundscapeIndex; // 0x04D4
	int32 m_soundscapeEntityListId; // 0x04D8
	CUtlSymbolLarge[8] m_positionNames; // 0x04E0
	CHandle< CEnvSoundscape > m_hProxySoundscape; // 0x0520
	bool m_bDisabled; // 0x0524
	CUtlSymbolLarge m_soundscapeName; // 0x0528
	uint32 m_soundEventHash; // 0x0530
};
class CFuncBrush : public CBaseModelEntity // server
{
	BrushSolidities_e m_iSolidity; // 0x0770
	int32 m_iDisabled; // 0x0774
	bool m_bSolidBsp; // 0x0778
	CUtlSymbolLarge m_iszExcludedClass; // 0x0780
	bool m_bInvertExclusion; // 0x0788
	bool m_bScriptedMovement; // 0x0789
};
class CParticleSystemAPI // server
{
};
class CBodyComponentPoint : public CBodyComponent // server
{
	CGameSceneNode m_sceneNode; // 0x0080
};
class CPhysBox : public CBreakable // server
{
	int32 m_damageType; // 0x0848
	int32 m_damageToEnableMotion; // 0x084C
	float32 m_flForceToEnableMotion; // 0x0850
	Vector m_vHoverPosePosition; // 0x0854
	QAngle m_angHoverPoseAngles; // 0x0860
	bool m_bNotSolidToWorld; // 0x086C
	bool m_bEnableUseOutput; // 0x086D
	HoverPoseFlags_t m_nHoverPoseFlags; // 0x086E
	float32 m_flTouchOutputPerEntityDelay; // 0x0870
	CUtlSymbolLarge m_iszCollisionGroup; // 0x0878
	CUtlSymbolLarge m_iszInteractsAs; // 0x0880
	CUtlSymbolLarge m_iszInteractsWith; // 0x0888
	CUtlSymbolLarge m_iszInteractsExclude; // 0x0890
	CEntityIOOutput m_OnDamaged; // 0x0898
	CEntityIOOutput m_OnAwakened; // 0x08B0
	CEntityIOOutput m_OnMotionEnabled; // 0x08C8
	CEntityIOOutput m_OnPlayerUse; // 0x08E0
	CEntityIOOutput m_OnStartTouch; // 0x08F8
};
class CSoundEventAABBEntity : public CSoundEventEntity // server
{
	Vector m_vMins; // 0x0568
	Vector m_vMaxs; // 0x0574
};
class CItemSoda : public CBaseAnimGraph // server
{
};
class CPulseCell_Timeline::TimelineEvent_t // pulse_runtime_lib
{
	float32 m_flTimeFromPrevious; // 0x0000
	CPulse_OutflowConnection m_EventOutflow; // 0x0008
};
class COmniLight : public CBarnLight // server
{
	float32 m_flInnerAngle; // 0x0A58
	float32 m_flOuterAngle; // 0x0A5C
	bool m_bShowLight; // 0x0A60
};
class CTriggerVolume : public CBaseModelEntity // server
{
	CUtlSymbolLarge m_iFilterName; // 0x0770
	CHandle< CBaseFilter > m_hFilter; // 0x0778
};
class CBtNodeCondition : public CBtNodeDecorator // server
{
	bool m_bNegated; // 0x0058
};
class CPulseCell_IntervalTimer::CursorState_t // pulse_runtime_lib
{
	GameTime_t m_StartTime; // 0x0000
	GameTime_t m_EndTime; // 0x0004
	float32 m_flWaitInterval; // 0x0008
	float32 m_flWaitIntervalHigh; // 0x000C
	bool m_bCompleteOnNextWake; // 0x0010
};
class CPulseCell_BaseRequirement : public CPulseCell_Base // pulse_runtime_lib
{
};
class CEnvExplosion : public CModelPointEntity // server
{
	int32 m_iMagnitude; // 0x0770
	float32 m_flPlayerDamage; // 0x0774
	int32 m_iRadiusOverride; // 0x0778
	float32 m_flInnerRadius; // 0x077C
	float32 m_flDamageForce; // 0x0780
	CHandle< CBaseEntity > m_hInflictor; // 0x0784
	DamageTypes_t m_iCustomDamageType; // 0x0788
	bool m_bCreateDebris; // 0x078C
	CUtlSymbolLarge m_iszCustomEffectName; // 0x0798
	CUtlSymbolLarge m_iszCustomSoundName; // 0x07A0
	bool m_bSuppressParticleImpulse; // 0x07A8
	Class_T m_iClassIgnore; // 0x07AC
	Class_T m_iClassIgnore2; // 0x07B0
	CUtlSymbolLarge m_iszEntityIgnoreName; // 0x07B8
	CHandle< CBaseEntity > m_hEntityIgnore; // 0x07C0
};
class CPulseCell_BaseState : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
};
class OutflowWithRequirements_t // pulse_runtime_lib
{
	CPulse_OutflowConnection m_Connection; // 0x0000
	PulseDocNodeID_t m_DestinationFlowNodeID; // 0x0048
	CUtlVector< PulseDocNodeID_t > m_RequirementNodeIDs; // 0x0050
	CUtlVector< int32 > m_nCursorStateBlockIndex; // 0x0068
};
class CTestPulseIO::ThreeStringArgs_t // server
{
	CUtlString strArg1; // 0x0000
	CUtlString strArg2; // 0x0008
	CUtlString strArg3; // 0x0010
};
class CPulseCell_IsRequirementValid : public CPulseCell_BaseRequirement // pulse_runtime_lib
{
};
class CFootstepControl : public CBaseTrigger // server
{
	CUtlSymbolLarge m_source; // 0x08E8
	CUtlSymbolLarge m_destination; // 0x08F0
};
class CCSPlayer_ItemServices : public CPlayer_ItemServices // server
{
	bool m_bHasDefuser; // 0x0048
	bool m_bHasHelmet; // 0x0049
};
class CPulseCell_Value_Gradient : public CPulseCell_BaseValue // pulse_runtime_lib
{
	CColorGradient m_Gradient; // 0x0048
};
class CParticleSystem : public CBaseModelEntity // server
{
	char[512] m_szSnapshotFileName; // 0x0770
	bool m_bActive; // 0x0970
	bool m_bFrozen; // 0x0971
	float32 m_flFreezeTransitionDuration; // 0x0974
	int32 m_nStopType; // 0x0978
	bool m_bAnimateDuringGameplayPause; // 0x097C
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_iEffectIndex; // 0x0980
	GameTime_t m_flStartTime; // 0x0988
	float32 m_flPreSimTime; // 0x098C
	Vector[4] m_vServerControlPoints; // 0x0990
	uint8[4] m_iServerControlPointAssignments; // 0x09C0
	CHandle< CBaseEntity >[64] m_hControlPointEnts; // 0x09C4
	bool m_bDataStringLocalized; // 0x0AC4
	CUtlString m_strDataString; // 0x0AC8
	bool m_bNoSave; // 0x0AD0
	bool m_bNoFreeze; // 0x0AD1
	bool m_bNoRamp; // 0x0AD2
	bool m_bStartActive; // 0x0AD3
	CUtlSymbolLarge m_iszEffectName; // 0x0AD8
	CUtlSymbolLarge[64] m_iszControlPointNames; // 0x0AE0
	int32 m_nDataCP; // 0x0CE0
	Vector m_vecDataCPValue; // 0x0CE4
	int32 m_nTintCP; // 0x0CF0
	Color m_clrTint; // 0x0CF4
};
class CTriggerBrush : public CBaseModelEntity // server
{
	CEntityIOOutput m_OnStartTouch; // 0x0770
	CEntityIOOutput m_OnEndTouch; // 0x0788
	CEntityIOOutput m_OnUse; // 0x07A0
	int32 m_iInputFilter; // 0x07B8
	int32 m_iDontMessageParent; // 0x07BC
};
class IntervalTimer // server
{
	GameTime_t m_timestamp; // 0x0008
	WorldGroupId_t m_nWorldGroupId; // 0x000C
};
class audioparams_t // server
{
	VectorWS[8] localSound; // 0x0008
	int32 soundscapeIndex; // 0x0068
	uint8 localBits; // 0x006C
	int32 soundscapeEntityListIndex; // 0x0070
	uint32 soundEventHash; // 0x0074
};
class CSoundAreaEntityBase : public CBaseEntity // server
{
	bool m_bDisabled; // 0x04A8
	CUtlSymbolLarge m_iszSoundAreaType; // 0x04B0
	Vector m_vPos; // 0x04B8
};
class CWeaponM4A1Silencer : public CCSWeaponBaseGun // server
{
};
class CTimeline : public IntervalTimer // server
{
	float32[64] m_flValues; // 0x0010
	int32[64] m_nValueCounts; // 0x0110
	int32 m_nBucketCount; // 0x0210
	float32 m_flInterval; // 0x0214
	float32 m_flFinalValue; // 0x0218
	TimelineCompression_t m_nCompressionType; // 0x021C
	bool m_bStopped; // 0x0220
};
class CEnvCubemapAPI // server
{
};
class CPulseCursorFuncs // pulse_runtime_lib
{
};
class CTestPulseIO::FloatStringArgs_t // server
{
	float32 flOutFloat; // 0x0000
	CUtlSymbolLarge strOutString; // 0x0008
};
class CountdownTimer // server
{
	float32 m_duration; // 0x0008
	GameTime_t m_timestamp; // 0x000C
	float32 m_timescale; // 0x0010
	WorldGroupId_t m_nWorldGroupId; // 0x0014
};
class PulseNodeDynamicOutflows_t::DynamicOutflow_t // pulse_runtime_lib
{
	CGlobalSymbol m_OutflowID; // 0x0000
	CPulse_OutflowConnection m_Connection; // 0x0008
};
class CItemAssaultSuit : public CItem // server
{
};
class CBeam : public CBaseModelEntity // server
{
	float32 m_flFrameRate; // 0x0770
	float32 m_flHDRColorScale; // 0x0774
	GameTime_t m_flFireTime; // 0x0778
	float32 m_flDamage; // 0x077C
	uint8 m_nNumBeamEnts; // 0x0780
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hBaseMaterial; // 0x0788
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_nHaloIndex; // 0x0790
	BeamType_t m_nBeamType; // 0x0798
	uint32 m_nBeamFlags; // 0x079C
	CHandle< CBaseEntity >[10] m_hAttachEntity; // 0x07A0
	AttachmentHandle_t[10] m_nAttachIndex; // 0x07C8
	float32 m_fWidth; // 0x07D4
	float32 m_fEndWidth; // 0x07D8
	float32 m_fFadeLength; // 0x07DC
	float32 m_fHaloScale; // 0x07E0
	float32 m_fAmplitude; // 0x07E4
	float32 m_fStartFrame; // 0x07E8
	float32 m_fSpeed; // 0x07EC
	float32 m_flFrame; // 0x07F0
	bool m_bTurnedOff; // 0x07F4
	VectorWS m_vecEndPos; // 0x07F8
	CHandle< CBaseEntity > m_hEndEntity; // 0x0804
	int32 m_nDissolveType; // 0x0808
};
class CLogicEventListener : public CLogicalEntity // server
{
	CUtlString m_strEventName; // 0x04B8
	bool m_bIsEnabled; // 0x04C0
	int32 m_nTeam; // 0x04C4
	CEntityOutputTemplate< CUtlString > m_OnEventFired; // 0x04C8
};
class CCSGO_TeamSelectTerroristPosition : public CCSGO_TeamSelectCharacterPosition // server
{
};
class CInfoData : public CServerOnlyEntity // server
{
};
class CWeaponNegev : public CCSWeaponBaseGun // server
{
};
class CWeaponElite : public CCSWeaponBaseGun // server
{
};
class CBasePlayerPawn : public CBaseCombatCharacter // server
{
	CPlayer_WeaponServices* m_pWeaponServices; // 0x0A30
	CPlayer_ItemServices* m_pItemServices; // 0x0A38
	CPlayer_AutoaimServices* m_pAutoaimServices; // 0x0A40
	CPlayer_ObserverServices* m_pObserverServices; // 0x0A48
	CPlayer_WaterServices* m_pWaterServices; // 0x0A50
	CPlayer_UseServices* m_pUseServices; // 0x0A58
	CPlayer_FlashlightServices* m_pFlashlightServices; // 0x0A60
	CPlayer_CameraServices* m_pCameraServices; // 0x0A68
	CPlayer_MovementServices* m_pMovementServices; // 0x0A70
	CUtlVectorEmbeddedNetworkVar< ViewAngleServerChange_t > m_ServerViewAngleChanges; // 0x0A80
	QAngle v_angle; // 0x0AE8
	QAngle v_anglePrevious; // 0x0AF4
	uint32 m_iHideHUD; // 0x0B00
	sky3dparams_t m_skybox3d; // 0x0B08
	GameTime_t m_fTimeLastHurt; // 0x0B98
	GameTime_t m_flDeathTime; // 0x0B9C
	GameTime_t m_fNextSuicideTime; // 0x0BA0
	bool m_fInitHUD; // 0x0BA4
	CAI_Expresser* m_pExpresser; // 0x0BA8
	CHandle< CBasePlayerController > m_hController; // 0x0BB0
	CHandle< CBasePlayerController > m_hDefaultController; // 0x0BB4
	float32 m_fHltvReplayDelay; // 0x0BBC
	float32 m_fHltvReplayEnd; // 0x0BC0
	CEntityIndex m_iHltvReplayEntity; // 0x0BC4
	CUtlVector< sndopvarlatchdata_t > m_sndOpvarLatchData; // 0x0BC8
};
class WeaponPurchaseCount_t // server
{
	uint16 m_nItemDefIndex; // 0x0030
	uint16 m_nCount; // 0x0032
};
class CBasePulseGraphInstance // pulse_runtime_lib
{
};
class FilterHealth : public CBaseFilter // server
{
	bool m_bAdrenalineActive; // 0x04E0
	int32 m_iHealthMin; // 0x04E4
	int32 m_iHealthMax; // 0x04E8
};
class CCSSprite : public CSprite // server
{
};
class CMathColorBlend : public CLogicalEntity // server
{
	float32 m_flInMin; // 0x04A8
	float32 m_flInMax; // 0x04AC
	Color m_OutColor1; // 0x04B0
	Color m_OutColor2; // 0x04B4
	CEntityOutputTemplate< Color > m_OutValue; // 0x04B8
};
class CShower : public CModelPointEntity // server
{
	float32 m_flSpeed; // 0x0770
};
class CPulseCell_Inflow_GraphHook : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_HookName; // 0x0080
};
class CScriptNavBlocker : public CFuncNavBlocker // server
{
	Vector m_vExtent; // 0x0788
};
class CEntityBlocker : public CBaseModelEntity // server
{
};
class CCSPlace_API // server
{
};
class SignatureOutflow_Resume : public CPulse_ResumePoint // pulse_runtime_lib
{
};
class CPulseCell_Outflow_PlayVCDBase : public CPulseCell_Outflow_PlaySceneBase // server
{
};
class CPathSimpleAPI // server
{
};
class CCSObserverPawn : public CCSPlayerPawnBase // server
{
};
class CTriggerActiveWeaponDetect : public CBaseTrigger // server
{
	CEntityIOOutput m_OnTouchedActiveWeapon; // 0x08E8
	CUtlSymbolLarge m_iszWeaponClassName; // 0x0900
};
class CEnvHudHint_API // server
{
};
class CFuncLadderAlias_func_useableladder : public CFuncLadder // server
{
};
class CSpriteOriented : public CSprite // server
{
};
class CPointServerCommand : public CPointEntity // server
{
};
class shard_model_desc_t // server
{
	int32 m_nModelID; // 0x0008
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hMaterialBase; // 0x0010
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hMaterialDamageOverlay; // 0x0018
	ShardSolid_t m_solid; // 0x0020
	Vector2D m_vecPanelSize; // 0x0024
	Vector2D m_vecStressPositionA; // 0x002C
	Vector2D m_vecStressPositionB; // 0x0034
	CNetworkUtlVectorBase< Vector2D > m_vecPanelVertices; // 0x0040
	CNetworkUtlVectorBase< Vector4D > m_vInitialPanelVertices; // 0x0058
	float32 m_flGlassHalfThickness; // 0x0070
	bool m_bHasParent; // 0x0074
	bool m_bParentFrozen; // 0x0075
	CUtlStringToken m_SurfacePropStringToken; // 0x0078
};
class CPlayerSprayDecal : public CModelPointEntity // server
{
	int32 m_nUniqueID; // 0x0770
	uint32 m_unAccountID; // 0x0774
	uint32 m_unTraceID; // 0x0778
	uint32 m_rtGcTime; // 0x077C
	VectorWS m_vecEndPos; // 0x0780
	VectorWS m_vecStart; // 0x078C
	Vector m_vecLeft; // 0x0798
	Vector m_vecNormal; // 0x07A4
	int32 m_nPlayer; // 0x07B0
	int32 m_nEntity; // 0x07B4
	int32 m_nHitbox; // 0x07B8
	float32 m_flCreationTime; // 0x07BC
	int32 m_nTintID; // 0x07C0
	uint8 m_nVersion; // 0x07C4
	uint8[128] m_ubSignature; // 0x07C5
};
class CFuncWater : public CBaseModelEntity // server
{
	CBuoyancyHelper m_BuoyancyHelper; // 0x0770
};
class CCSGameModeRules // server
{
	CNetworkVarChainer __m_pChainEntity; // 0x0008
};
class CPointPrefabAPI // server
{
};
class CPulseCell_Outflow_PlayVCD::VCDRequirementInfo_t // server
{
	int32 m_nEventID; // 0x0000
	CPulse_OutflowConnection m_Outflow; // 0x0008
};
class CEconEntity : public CBaseAnimGraph // server
{
	CAttributeContainer m_AttributeManager; // 0x0978
	uint32 m_OriginalOwnerXuidLow; // 0x0C70
	uint32 m_OriginalOwnerXuidHigh; // 0x0C74
	int32 m_nFallbackPaintKit; // 0x0C78
	int32 m_nFallbackSeed; // 0x0C7C
	float32 m_flFallbackWear; // 0x0C80
	int32 m_nFallbackStatTrak; // 0x0C84
	CHandle< CBaseEntity > m_hOldProvidee; // 0x0C88
	int32 m_iOldOwnerClass; // 0x0C8C
};
class CTankTargetChange : public CPointEntity // server
{
	CVariantBase< CVariantDefaultAllocator > m_newTarget; // 0x04A8
	CUtlSymbolLarge m_newTargetName; // 0x04B8
};
class CCSPlayer_WaterServices : public CPlayer_WaterServices // server
{
	GameTime_t m_NextDrownDamageTime; // 0x0048
	int32 m_nDrownDmgRate; // 0x004C
	GameTime_t m_AirFinishedTime; // 0x0050
	float32 m_flWaterJumpTime; // 0x0054
	Vector m_vecWaterJumpVel; // 0x0058
	float32 m_flSwimSoundTime; // 0x0064
};
class CLogicDistanceCheck : public CLogicalEntity // server
{
	CUtlSymbolLarge m_iszEntityA; // 0x04A8
	CUtlSymbolLarge m_iszEntityB; // 0x04B0
	float32 m_flZone1Distance; // 0x04B8
	float32 m_flZone2Distance; // 0x04BC
	CEntityIOOutput m_InZone1; // 0x04C0
	CEntityIOOutput m_InZone2; // 0x04D8
	CEntityIOOutput m_InZone3; // 0x04F0
};
class CEnvCombinedLightProbeVolume : public CBaseEntity // server
{
	Color m_Entity_Color; // 0x1520
	float32 m_Entity_flBrightness; // 0x1524
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hCubemapTexture; // 0x1528
	bool m_Entity_bCustomCubemapTexture; // 0x1530
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_AmbientCube; // 0x1538
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SDF; // 0x1540
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_DC; // 0x1548
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_R; // 0x1550
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_G; // 0x1558
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_B; // 0x1560
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeDirectLightIndicesTexture; // 0x1568
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeDirectLightScalarsTexture; // 0x1570
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeDirectLightShadowsTexture; // 0x1578
	Vector m_Entity_vBoxMins; // 0x1580
	Vector m_Entity_vBoxMaxs; // 0x158C
	bool m_Entity_bMoveable; // 0x1598
	int32 m_Entity_nHandshake; // 0x159C
	int32 m_Entity_nEnvCubeMapArrayIndex; // 0x15A0
	int32 m_Entity_nPriority; // 0x15A4
	bool m_Entity_bStartDisabled; // 0x15A8
	float32 m_Entity_flEdgeFadeDist; // 0x15AC
	Vector m_Entity_vEdgeFadeDists; // 0x15B0
	int32 m_Entity_nLightProbeSizeX; // 0x15BC
	int32 m_Entity_nLightProbeSizeY; // 0x15C0
	int32 m_Entity_nLightProbeSizeZ; // 0x15C4
	int32 m_Entity_nLightProbeAtlasX; // 0x15C8
	int32 m_Entity_nLightProbeAtlasY; // 0x15CC
	int32 m_Entity_nLightProbeAtlasZ; // 0x15D0
	bool m_Entity_bEnabled; // 0x15E9
};
class ViewAngleServerChange_t // server
{
	FixAngleSet_t nType; // 0x0030
	QAngle qAngle; // 0x0034
	uint32 nIndex; // 0x0040
};
class CLogicDistanceAutosave : public CLogicalEntity // server
{
	CUtlSymbolLarge m_iszTargetEntity; // 0x04A8
	float32 m_flDistanceToPlayer; // 0x04B0
	bool m_bForceNewLevelUnit; // 0x04B4
	bool m_bCheckCough; // 0x04B5
	bool m_bThinkDangerous; // 0x04B6
	float32 m_flDangerousTime; // 0x04B8
};
class CLogicBranch : public CLogicalEntity // server
{
	bool m_bInValue; // 0x04A8
	CUtlVector< CHandle< CBaseEntity > > m_Listeners; // 0x04B0
	CEntityIOOutput m_OnTrue; // 0x04C8
	CEntityIOOutput m_OnFalse; // 0x04E0
};
class CPulseCell_Outflow_ScriptedSequence : public CPulseCell_BaseYieldingInflow // server
{
	CUtlString m_szSyncGroup; // 0x00D8
	int32 m_nExpectedNumSequencesInSyncGroup; // 0x00E0
	bool m_bEnsureOnNavmeshOnFinish; // 0x00E4
	bool m_bDontTeleportAtEnd; // 0x00E5
	bool m_bDisallowInterrupts; // 0x00E6
	PulseScriptedSequenceData_t m_scriptedSequenceDataMain; // 0x00E8
	CUtlVector< PulseScriptedSequenceData_t > m_vecAdditionalActors; // 0x0120
	CPulse_ResumePoint m_OnFinished; // 0x0138
	CUtlVector< CPulse_OutflowConnection > m_Triggers; // 0x0180
};
class CFuncTrackChange : public CFuncPlatRot // server
{
	CHandle< CPathTrack > m_trackTop; // 0x0840
	CHandle< CPathTrack > m_trackBottom; // 0x0844
	CHandle< CFuncTrackTrain > m_train; // 0x0848
	CUtlSymbolLarge m_trackTopName; // 0x0850
	CUtlSymbolLarge m_trackBottomName; // 0x0858
	CUtlSymbolLarge m_trainName; // 0x0860
	TRAIN_CODE m_code; // 0x0868
	int32 m_targetState; // 0x086C
	int32 m_use; // 0x0870
};
class CFuncTrackTrain : public CBaseModelEntity // server
{
	CHandle< CPathTrack > m_ppath; // 0x0770
	float32 m_length; // 0x0774
	Vector m_vPosPrev; // 0x0778
	QAngle m_angPrev; // 0x0784
	float32 m_flSpeed; // 0x0790
	Vector m_controlMins; // 0x0794
	Vector m_controlMaxs; // 0x07A0
	VectorWS m_lastBlockPos; // 0x07AC
	int32 m_lastBlockTick; // 0x07B8
	float32 m_flVolume; // 0x07BC
	float32 m_flBank; // 0x07C0
	float32 m_oldSpeed; // 0x07C4
	float32 m_flBlockDamage; // 0x07C8
	float32 m_height; // 0x07CC
	float32 m_maxSpeed; // 0x07D0
	float32 m_dir; // 0x07D4
	CGameSoundEventName m_iszSoundMove; // 0x07D8
	CGameSoundEventName m_iszSoundMovePing; // 0x07E0
	CGameSoundEventName m_iszSoundStart; // 0x07E8
	CGameSoundEventName m_iszSoundStop; // 0x07F0
	CGameSoundEventName m_strPathTarget; // 0x07F8
	float32 m_flMoveSoundMinDuration; // 0x0800
	float32 m_flMoveSoundMaxDuration; // 0x0804
	GameTime_t m_flNextMoveSoundTime; // 0x0808
	float32 m_flMoveSoundMinPitch; // 0x080C
	float32 m_flMoveSoundMaxPitch; // 0x0810
	TrainOrientationType_t m_eOrientationType; // 0x0814
	TrainVelocityType_t m_eVelocityType; // 0x0818
	CEntityIOOutput m_OnStart; // 0x0830
	CEntityIOOutput m_OnNext; // 0x0848
	CEntityIOOutput m_OnArrivedAtDestinationNode; // 0x0860
	bool m_bManualSpeedChanges; // 0x0878
	float32 m_flDesiredSpeed; // 0x087C
	GameTime_t m_flSpeedChangeTime; // 0x0880
	float32 m_flAccelSpeed; // 0x0884
	float32 m_flDecelSpeed; // 0x0888
	bool m_bAccelToSpeed; // 0x088C
	GameTime_t m_flNextMPSoundTime; // 0x0890
};
class CEnvInstructorHint : public CPointEntity // server
{
	CUtlSymbolLarge m_iszName; // 0x04A8
	CUtlSymbolLarge m_iszReplace_Key; // 0x04B0
	CUtlSymbolLarge m_iszHintTargetEntity; // 0x04B8
	int32 m_iTimeout; // 0x04C0
	int32 m_iDisplayLimit; // 0x04C4
	CUtlSymbolLarge m_iszIcon_Onscreen; // 0x04C8
	CUtlSymbolLarge m_iszIcon_Offscreen; // 0x04D0
	CUtlSymbolLarge m_iszCaption; // 0x04D8
	CUtlSymbolLarge m_iszActivatorCaption; // 0x04E0
	Color m_Color; // 0x04E8
	float32 m_fIconOffset; // 0x04EC
	float32 m_fRange; // 0x04F0
	uint8 m_iPulseOption; // 0x04F4
	uint8 m_iAlphaOption; // 0x04F5
	uint8 m_iShakeOption; // 0x04F6
	bool m_bStatic; // 0x04F7
	bool m_bNoOffscreen; // 0x04F8
	bool m_bForceCaption; // 0x04F9
	int32 m_iInstanceType; // 0x04FC
	bool m_bSuppressRest; // 0x0500
	CUtlSymbolLarge m_iszBinding; // 0x0508
	bool m_bAllowNoDrawTarget; // 0x0510
	bool m_bAutoStart; // 0x0511
	bool m_bLocalPlayerOnly; // 0x0512
};
class CEnvWind : public CBaseEntity // server
{
	CEnvWindShared m_EnvWindShared; // 0x04A8
};
class CSoundEventPathCornerEntity : public CSoundEventEntity // server
{
	CUtlSymbolLarge m_iszPathCorner; // 0x0568
	int32 m_iCountMax; // 0x0570
	float32 m_flDistanceMax; // 0x0574
	float32 m_flDistMaxSqr; // 0x0578
	float32 m_flDotProductMax; // 0x057C
	bool m_bPlaying; // 0x0580
	CNetworkUtlVectorBase< SoundeventPathCornerPairNetworked_t > m_vecCornerPairsNetworked; // 0x05A8
};
class CCSPlayerBase_CameraServices : public CPlayer_CameraServices // server
{
	uint32 m_iFOV; // 0x0178
	uint32 m_iFOVStart; // 0x017C
	GameTime_t m_flFOVTime; // 0x0180
	float32 m_flFOVRate; // 0x0184
	CHandle< CBaseEntity > m_hZoomOwner; // 0x0188
	CUtlVector< CHandle< CBaseEntity > > m_hTriggerFogList; // 0x0190
	CHandle< CBaseEntity > m_hLastFogTrigger; // 0x01A8
};
class CPulseCell_Inflow_BaseEntrypoint : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseRuntimeChunkIndex_t m_EntryChunk; // 0x0048
	PulseRegisterMap_t m_RegisterMap; // 0x0050
};
class CDynamicNavConnectionsVolume : public CTriggerMultiple // server
{
	CUtlSymbolLarge m_iszConnectionTarget; // 0x0900
	CUtlVector< DynamicVolumeDef_t > m_vecConnections; // 0x0908
	CGlobalSymbol m_sTransitionType; // 0x0920
	bool m_bConnectionsEnabled; // 0x0928
	float32 m_flTargetAreaSearchRadius; // 0x092C
	float32 m_flUpdateDistance; // 0x0930
	float32 m_flMaxConnectionDistance; // 0x0934
};
class CConstraintAnchor : public CBaseAnimGraph // server
{
	float32 m_massScale; // 0x0960
};
class CPulseCell_WaitForCursorsWithTagBase : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	int32 m_nCursorsAllowedToWait; // 0x00D8
	CPulse_ResumePoint m_WaitComplete; // 0x00E0
};
class CCSPlayerPawn : public CCSPlayerPawnBase // server
{
	CCSPlayer_BulletServices* m_pBulletServices; // 0x0D38
	CCSPlayer_HostageServices* m_pHostageServices; // 0x0D40
	CCSPlayer_BuyServices* m_pBuyServices; // 0x0D48
	CCSPlayer_ActionTrackingServices* m_pActionTrackingServices; // 0x0D50
	CCSPlayer_AimPunchServices* m_pAimPunchServices; // 0x0D58
	CCSPlayer_RadioServices* m_pRadioServices; // 0x0D60
	CCSPlayer_DamageReactServices* m_pDamageReactServices; // 0x0D68
	uint16 m_nCharacterDefIndex; // 0x0D70
	bool m_bHasFemaleVoice; // 0x0D72
	CUtlString m_strVOPrefix; // 0x0D78
	char[18] m_szLastPlaceName; // 0x0D80
	bool m_bInHostageResetZone; // 0x0E70
	bool m_bInBuyZone; // 0x0E71
	CUtlVector< CHandle< CBaseEntity > > m_TouchingBuyZones; // 0x0E78
	bool m_bWasInBuyZone; // 0x0E90
	bool m_bInHostageRescueZone; // 0x0E91
	bool m_bInBombZone; // 0x0E92
	bool m_bWasInHostageRescueZone; // 0x0E93
	int32 m_iRetakesOffering; // 0x0E94
	int32 m_iRetakesOfferingCard; // 0x0E98
	bool m_bRetakesHasDefuseKit; // 0x0E9C
	bool m_bRetakesMVPLastRound; // 0x0E9D
	int32 m_iRetakesMVPBoostItem; // 0x0EA0
	loadout_slot_t m_RetakesMVPBoostExtraUtility; // 0x0EA4
	GameTime_t m_flHealthShotBoostExpirationTime; // 0x0EA8
	float32 m_flLandingTimeSeconds; // 0x0EAC
	bool m_bIsBuyMenuOpen; // 0x0EB0
	GameTime_t m_lastLandTime; // 0x0EE8
	bool m_bOnGroundLastTick; // 0x0EEC
	int32 m_iPlayerLocked; // 0x0EF0
	GameTime_t m_flTimeOfLastInjury; // 0x0EF8
	GameTime_t m_flNextSprayDecalTime; // 0x0EFC
	bool m_bNextSprayDecalTimeExpedited; // 0x0F00
	int32 m_nRagdollDamageBone; // 0x0F04
	Vector m_vRagdollDamageForce; // 0x0F08
	char[64] m_szRagdollDamageWeaponName; // 0x0F14
	bool m_bRagdollDamageHeadshot; // 0x0F54
	VectorWS m_vRagdollServerOrigin; // 0x0F58
	CEconItemView m_EconGloves; // 0x0F68
	uint8 m_nEconGlovesChanged; // 0x1210
	QAngle m_qDeathEyeAngles; // 0x1214
	bool m_bLeftHanded; // 0x1220
	GameTime_t m_fSwitchedHandednessTime; // 0x1224
	float32 m_flViewmodelOffsetX; // 0x1228
	float32 m_flViewmodelOffsetY; // 0x122C
	float32 m_flViewmodelOffsetZ; // 0x1230
	float32 m_flViewmodelFOV; // 0x1234
	bool m_bIsWalking; // 0x1238
	float32 m_fLastGivenDefuserTime; // 0x123C
	float32 m_fLastGivenBombTime; // 0x1240
	float32 m_flDealtDamageToEnemyMostRecentTimestamp; // 0x1244
	uint32 m_iDisplayHistoryBits; // 0x1248
	float32 m_flLastAttackedTeammate; // 0x124C
	GameTime_t m_allowAutoFollowTime; // 0x1250
	bool m_bResetArmorNextSpawn; // 0x1254
	CEntityIndex m_nLastKillerIndex; // 0x1258
	EntitySpottedState_t m_entitySpottedState; // 0x1260
	int32 m_nSpotRules; // 0x1278
	bool m_bIsScoped; // 0x127C
	bool m_bResumeZoom; // 0x127D
	bool m_bIsDefusing; // 0x127E
	bool m_bIsGrabbingHostage; // 0x127F
	CSPlayerBlockingUseAction_t m_iBlockingUseActionInProgress; // 0x1280
	GameTime_t m_flEmitSoundTime; // 0x1284
	bool m_bInNoDefuseArea; // 0x1288
	CEntityIndex m_iBombSiteIndex; // 0x128C
	int32 m_nWhichBombZone; // 0x1290
	bool m_bInBombZoneTrigger; // 0x1294
	bool m_bWasInBombZoneTrigger; // 0x1295
	int32 m_iShotsFired; // 0x1298
	float32 m_flFlinchStack; // 0x129C
	float32 m_flVelocityModifier; // 0x12A0
	Vector m_vecTotalBulletForce; // 0x12A4
	bool m_bWaitForNoAttack; // 0x12B0
	float32 m_ignoreLadderJumpTime; // 0x12B4
	bool m_bKilledByHeadshot; // 0x12B8
	int32 m_LastHitBox; // 0x12BC
	CCSBot* m_pBot; // 0x12C0
	bool m_bBotAllowActive; // 0x12C8
	int32 m_nLastPickupPriority; // 0x12CC
	float32 m_flLastPickupPriorityTime; // 0x12D0
	int32 m_ArmorValue; // 0x12D4
	uint16 m_unCurrentEquipmentValue; // 0x12D8
	uint16 m_unRoundStartEquipmentValue; // 0x12DA
	uint16 m_unFreezetimeEndEquipmentValue; // 0x12DC
	int32 m_iLastWeaponFireUsercmd; // 0x12E0
	bool m_bIsSpawning; // 0x12E4
	int32 m_iDeathFlags; // 0x12F0
	bool m_bHasDeathInfo; // 0x12F4
	float32 m_flDeathInfoTime; // 0x12F8
	VectorWS m_vecDeathInfoOrigin; // 0x12FC
	uint32[5] m_vecPlayerPatchEconIndices; // 0x1308
	Color m_GunGameImmunityColor; // 0x131C
	GameTime_t m_grenadeParameterStashTime; // 0x1320
	bool m_bGrenadeParametersStashed; // 0x1324
	QAngle m_angStashedShootAngles; // 0x1328
	VectorWS m_vecStashedGrenadeThrowPosition; // 0x1334
	Vector m_vecStashedVelocity; // 0x1340
	bool m_bCommittingSuicideOnTeamChange; // 0x1358
	bool m_wasNotKilledNaturally; // 0x1359
	GameTime_t m_fImmuneToGunGameDamageTime; // 0x135C
	bool m_bGunGameImmunity; // 0x1360
	float32 m_fMolotovDamageTime; // 0x1364
	QAngle m_angEyeAngles; // 0x1368
};
class CEnvLightProbeVolume : public CBaseEntity // server
{
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_AmbientCube; // 0x14A0
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SDF; // 0x14A8
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_DC; // 0x14B0
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_R; // 0x14B8
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_G; // 0x14C0
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_B; // 0x14C8
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeDirectLightIndicesTexture; // 0x14D0
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeDirectLightScalarsTexture; // 0x14D8
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeDirectLightShadowsTexture; // 0x14E0
	Vector m_Entity_vBoxMins; // 0x14E8
	Vector m_Entity_vBoxMaxs; // 0x14F4
	bool m_Entity_bMoveable; // 0x1500
	int32 m_Entity_nHandshake; // 0x1504
	int32 m_Entity_nPriority; // 0x1508
	bool m_Entity_bStartDisabled; // 0x150C
	int32 m_Entity_nLightProbeSizeX; // 0x1510
	int32 m_Entity_nLightProbeSizeY; // 0x1514
	int32 m_Entity_nLightProbeSizeZ; // 0x1518
	int32 m_Entity_nLightProbeAtlasX; // 0x151C
	int32 m_Entity_nLightProbeAtlasY; // 0x1520
	int32 m_Entity_nLightProbeAtlasZ; // 0x1524
	bool m_Entity_bEnabled; // 0x1531
};
class SpawnPoint : public CServerOnlyPointEntity // server
{
	int32 m_iPriority; // 0x04A8
	bool m_bEnabled; // 0x04AC
	int32 m_nType; // 0x04B0
};
class CFuncMoverAPI // server
{
};
class CGameSceneNode // server
{
	CTransformWS m_nodeToWorld; // 0x0010
	CEntityInstance* m_pOwner; // 0x0030
	CGameSceneNode* m_pParent; // 0x0038
	CGameSceneNode* m_pChild; // 0x0040
	CGameSceneNode* m_pNextSibling; // 0x0048
	CGameSceneNodeHandle m_hParent; // 0x0070
	CNetworkOriginCellCoordQuantizedVector m_vecOrigin; // 0x0080
	QAngle m_angRotation; // 0x00B8
	float32 m_flScale; // 0x00C4
	VectorWS m_vecAbsOrigin; // 0x00C8
	QAngle m_angAbsRotation; // 0x00D4
	float32 m_flAbsScale; // 0x00E0
	int16 m_nParentAttachmentOrBone; // 0x00E4
	bool m_bDebugAbsOriginChanges; // 0x00E6
	bool m_bDormant; // 0x00E7
	bool m_bForceParentToBeNetworked; // 0x00E8
	bitfield:1 m_bDirtyHierarchy; // 0x0000
	bitfield:1 m_bDirtyBoneMergeInfo; // 0x0000
	bitfield:1 m_bNetworkedPositionChanged; // 0x0000
	bitfield:1 m_bNetworkedAnglesChanged; // 0x0000
	bitfield:1 m_bNetworkedScaleChanged; // 0x0000
	bitfield:1 m_bWillBeCallingPostDataUpdate; // 0x0000
	bitfield:1 m_bBoneMergeFlex; // 0x0000
	bitfield:2 m_nLatchAbsOrigin; // 0x0000
	bitfield:1 m_bDirtyBoneMergeBoneToRoot; // 0x0000
	uint8 m_nHierarchicalDepth; // 0x00EB
	uint8 m_nHierarchyType; // 0x00EC
	uint8 m_nDoNotSetAnimTimeInInvalidatePhysicsCount; // 0x00ED
	CUtlStringToken m_name; // 0x00F0
	CUtlStringToken m_hierarchyAttachName; // 0x0104
	float32 m_flClientLocalScale; // 0x0108
};
class CWeaponM249 : public CCSWeaponBaseGun // server
{
};
class CRopeKeyframeAlias_move_rope : public CRopeKeyframe // server
{
};
class CPulseServerFuncs_Sounds // server
{
};
class CPulsePhysicsConstraintsFuncs // server
{
};
class CPlayer_ObserverServices : public CPlayerPawnComponent // server
{
	uint8 m_iObserverMode; // 0x0048
	CHandle< CBaseEntity > m_hObserverTarget; // 0x004C
	ObserverMode_t m_iObserverLastMode; // 0x0050
	bool m_bForcedObserverMode; // 0x0054
};
class CCashStack : public CBaseModelEntity // server
{
	int32 m_nCashStackValue; // 0x0770
};
class CLogicScript : public CPointEntity // server
{
};
class CAttributeManager::cached_attribute_float_t // server
{
	float32 flIn; // 0x0000
	CUtlSymbolLarge iAttribHook; // 0x0008
	float32 flOut; // 0x0010
};
class CPulseGraphInstance_ServerEntity : public CBasePulseGraphInstance // server
{
	CHandle< CBaseEntity > m_hOwner; // 0x01A0
	bool m_bActivated; // 0x01A4
	CUtlSymbolLarge m_sNameFixupStaticPrefix; // 0x01A8
	CUtlSymbolLarge m_sNameFixupParent; // 0x01B0
	CUtlSymbolLarge m_sNameFixupLocal; // 0x01B8
	CUtlSymbolLarge m_sProceduralWorldNameForRelays; // 0x01C0
};
class CSceneEntityAlias_logic_choreographed_scene : public CSceneEntity // server
{
};
class CRagdollManager : public CBaseEntity // server
{
	int8 m_iCurrentMaxRagdollCount; // 0x04A8
	int32 m_iMaxRagdollCount; // 0x04AC
	bool m_bSaveImportant; // 0x04B0
	bool m_bCanTakeDamage; // 0x04B1
};
class CSoundOpvarSetBoxEntity : public CSoundOpvarSetPointEntity // server
{
	Vector m_vDistanceInnerMins; // 0x0640
	Vector m_vDistanceInnerMaxs; // 0x064C
	Vector m_vDistanceOuterMins; // 0x0658
	Vector m_vDistanceOuterMaxs; // 0x0664
	int32 m_nBoxDirection; // 0x0670
	Vector m_vInnerMins; // 0x0674
	Vector m_vInnerMaxs; // 0x0680
	Vector m_vOuterMins; // 0x068C
	Vector m_vOuterMaxs; // 0x0698
};
class CPostProcessingVolume : public CBaseTrigger // server
{
	CStrongHandle< InfoForResourceTypeCPostProcessingResource > m_hPostSettings; // 0x08F8
	float32 m_flFadeDuration; // 0x0900
	float32 m_flMinLogExposure; // 0x0904
	float32 m_flMaxLogExposure; // 0x0908
	float32 m_flMinExposure; // 0x090C
	float32 m_flMaxExposure; // 0x0910
	float32 m_flExposureCompensation; // 0x0914
	float32 m_flExposureFadeSpeedUp; // 0x0918
	float32 m_flExposureFadeSpeedDown; // 0x091C
	float32 m_flTonemapEVSmoothingRange; // 0x0920
	bool m_bMaster; // 0x0924
	bool m_bExposureControl; // 0x0925
};
class CPointProximitySensor : public CPointEntity // server
{
	bool m_bDisabled; // 0x04A8
	CHandle< CBaseEntity > m_hTargetEntity; // 0x04AC
	CEntityOutputTemplate< float32 > m_Distance; // 0x04B0
};
class CPulse_InvokeBinding // pulse_runtime_lib
{
	PulseRegisterMap_t m_RegisterMap; // 0x0000
	PulseSymbol_t m_FuncName; // 0x0030
	PulseRuntimeCellIndex_t m_nCellIndex; // 0x0040
	PulseRuntimeChunkIndex_t m_nSrcChunk; // 0x0044
	int32 m_nSrcInstruction; // 0x0048
};
class CTriggerLook : public CTriggerOnce // server
{
	CHandle< CBaseEntity > m_hLookTarget; // 0x0900
	float32 m_flFieldOfView; // 0x0904
	float32 m_flLookTime; // 0x0908
	float32 m_flLookTimeTotal; // 0x090C
	GameTime_t m_flLookTimeLast; // 0x0910
	float32 m_flTimeoutDuration; // 0x0914
	bool m_bTimeoutFired; // 0x0918
	bool m_bIsLooking; // 0x0919
	bool m_b2DFOV; // 0x091A
	bool m_bUseVelocity; // 0x091B
	bool m_bTestOcclusion; // 0x091C
	bool m_bTestAllVisibleOcclusion; // 0x091D
	CEntityIOOutput m_OnTimeout; // 0x0920
	CEntityIOOutput m_OnStartLook; // 0x0938
	CEntityIOOutput m_OnEndLook; // 0x0950
};
class CPulseCell_Outflow_PlayVCD : public CPulseCell_Outflow_PlayVCDBase // server
{
	CStrongHandle< InfoForResourceTypeCChoreoSceneResource > m_hChoreoScene; // 0x0138
	CPulse_OutflowConnection m_OnPaused; // 0x0140
	CPulse_OutflowConnection m_OnResumed; // 0x0188
	CUtlVector< CPulseCell_Outflow_PlayVCD::VCDRequirementInfo_t > m_OutRequirements; // 0x01D0
};
class CCSPointScriptEntity_API // server
{
};
class CMultiplayRules : public CGameRules // server
{
};
class CMolotovGrenade : public CBaseCSGrenade // server
{
};
class CPhysTorque : public CPhysForce // server
{
	Vector m_axis; // 0x0508
};
class CMultiSource : public CLogicalEntity // server
{
	CHandle< CBaseEntity >[32] m_rgEntities; // 0x04A8
	int32[32] m_rgTriggered; // 0x0528
	CEntityIOOutput m_OnTrigger; // 0x05A8
	int32 m_iTotal; // 0x05C0
	CUtlSymbolLarge m_globalstate; // 0x05C8
};
class CBaseCSGrenade : public CCSWeaponBase // server
{
	bool m_bRedraw; // 0x1050
	bool m_bIsHeldByPlayer; // 0x1051
	bool m_bPinPulled; // 0x1052
	bool m_bJumpThrow; // 0x1053
	bool m_bThrowAnimating; // 0x1054
	GameTime_t m_fThrowTime; // 0x1058
	float32 m_flThrowStrength; // 0x105C
	GameTime_t m_fDropTime; // 0x1060
	GameTime_t m_fPinPullTime; // 0x1064
	bool m_bJustPulledPin; // 0x1068
	GameTick_t m_nNextHoldTick; // 0x106C
	float32 m_flNextHoldFrac; // 0x1070
	CHandle< CCSWeaponBase > m_hSwitchToWeaponAfterThrow; // 0x1074
};
class CLogicAuto : public CBaseEntity // server
{
	CEntityIOOutput m_OnMapSpawn; // 0x04A8
	CEntityIOOutput m_OnDemoMapSpawn; // 0x04C0
	CEntityIOOutput m_OnNewGame; // 0x04D8
	CEntityIOOutput m_OnLoadGame; // 0x04F0
	CEntityIOOutput m_OnMapTransition; // 0x0508
	CEntityIOOutput m_OnBackgroundMap; // 0x0520
	CEntityIOOutput m_OnMultiNewMap; // 0x0538
	CEntityIOOutput m_OnMultiNewRound; // 0x0550
	CEntityIOOutput m_OnVREnabled; // 0x0568
	CEntityIOOutput m_OnVRNotEnabled; // 0x0580
	CUtlSymbolLarge m_globalstate; // 0x0598
};
class CPhysicsWire : public CBaseEntity // server
{
	int32 m_nDensity; // 0x04A8
};
class CFuncIllusionary : public CBaseModelEntity // server
{
};
class CInfoDynamicShadowHint : public CPointEntity // server
{
	bool m_bDisabled; // 0x04A8
	float32 m_flRange; // 0x04AC
	int32 m_nImportance; // 0x04B0
	int32 m_nLightChoice; // 0x04B4
	CHandle< CBaseEntity > m_hLight; // 0x04B8
};
class CMarkupVolume : public CBaseModelEntity // server
{
	bool m_bDisabled; // 0x0770
};
class CPathNode : public CPointEntity // server
{
	Vector m_vInTangentLocal; // 0x04A8
	Vector m_vOutTangentLocal; // 0x04B4
	CUtlString m_strParentPathUniqueID; // 0x04C0
	CUtlString m_strPathNodeParameter; // 0x04C8
	CTransformWS m_xWSPrevParent; // 0x04D0
	CHandle< CPathWithDynamicNodes > m_hPath; // 0x04F0
};
class CCSGO_TeamSelectCounterTerroristPosition : public CCSGO_TeamSelectCharacterPosition // server
{
};
class CPointGiveAmmo_API // server
{
};
class CTriggerRemove : public CBaseTrigger // server
{
	CEntityIOOutput m_OnRemove; // 0x08E8
};
class CLogicGameEventListener : public CLogicalEntity // server
{
	CEntityIOOutput m_OnEventFired; // 0x04B8
	CUtlSymbolLarge m_iszGameEventName; // 0x04D0
	CUtlSymbolLarge m_iszGameEventItem; // 0x04D8
	bool m_bEnabled; // 0x04E0
	bool m_bStartDisabled; // 0x04E1
};
class CServerOnlyModelEntity : public CBaseModelEntity // server
{
};
class CPulseCell_IntervalTimer : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_Completed; // 0x00D8
	SignatureOutflow_Continue m_OnInterval; // 0x0120
};
class CMarkupVolumeTagged_Nav : public CMarkupVolumeTagged // server
{
	NavScopeFlags_t m_nScopes; // 0x07B0
};
class CInfoPlayerTerrorist : public SpawnPoint // server
{
};
class CLogicAutosave : public CLogicalEntity // server
{
	bool m_bForceNewLevelUnit; // 0x04A8
	int32 m_minHitPoints; // 0x04AC
	int32 m_minHitPointsToCommit; // 0x04B0
};
class CCSGO_TeamIntroTerroristPosition : public CCSGO_TeamIntroCharacterPosition // server
{
};
class CPulseTestScriptLib // pulse_runtime_lib
{
};
class CSingleplayRules : public CGameRules // server
{
	bool m_bSinglePlayerGameEnding; // 0x00D0
};
class CEnvWindShared // server
{
	GameTime_t m_flStartTime; // 0x0008
	uint32 m_iWindSeed; // 0x000C
	uint16 m_iMinWind; // 0x0010
	uint16 m_iMaxWind; // 0x0012
	int32 m_windRadius; // 0x0014
	uint16 m_iMinGust; // 0x0018
	uint16 m_iMaxGust; // 0x001A
	float32 m_flMinGustDelay; // 0x001C
	float32 m_flMaxGustDelay; // 0x0020
	float32 m_flGustDuration; // 0x0024
	uint16 m_iGustDirChange; // 0x0028
	uint16 m_iInitialWindDir; // 0x002A
	float32 m_flInitialWindSpeed; // 0x002C
	VectorWS m_location; // 0x0030
	CEntityIOOutput m_OnGustStart; // 0x0040
	CEntityIOOutput m_OnGustEnd; // 0x0058
	CHandle< CBaseEntity > m_hEntOwner; // 0x0070
};
class CPointPrefab : public CServerOnlyPointEntity // server
{
	CUtlSymbolLarge m_targetMapName; // 0x04A8
	CUtlSymbolLarge m_forceWorldGroupID; // 0x04B0
	CUtlSymbolLarge m_associatedRelayTargetName; // 0x04B8
	bool m_fixupNames; // 0x04C0
	bool m_bLoadDynamic; // 0x04C1
	CHandle< CPointPrefab > m_associatedRelayEntity; // 0x04C4
	CUtlVector< CHandle< CBaseEntity > > m_ProceduralRelaySources; // 0x04C8
};
class CPulseCell_BaseLerp : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_WakeResume; // 0x00D8
};
class CEnvInstructorVRHint : public CPointEntity // server
{
	CUtlSymbolLarge m_iszName; // 0x04A8
	CUtlSymbolLarge m_iszHintTargetEntity; // 0x04B0
	int32 m_iTimeout; // 0x04B8
	CUtlSymbolLarge m_iszCaption; // 0x04C0
	CUtlSymbolLarge m_iszStartSound; // 0x04C8
	int32 m_iLayoutFileType; // 0x04D0
	CUtlSymbolLarge m_iszCustomLayoutFile; // 0x04D8
	int32 m_iAttachType; // 0x04E0
	float32 m_flHeightOffset; // 0x04E4
};
class CCSGameRulesProxy : public CGameRulesProxy // server
{
	CCSGameRules* m_pGameRules; // 0x04A8
};
class CPointValueRemapperAPI // server
{
};
class CPrecipitation : public CBaseTrigger // server
{
};
class CCommentaryViewPosition : public CSprite // server
{
};
class CEnvGlobal : public CLogicalEntity // server
{
	CEntityOutputTemplate< int32 > m_outCounter; // 0x04A8
	CUtlSymbolLarge m_globalstate; // 0x04C8
	int32 m_triggermode; // 0x04D0
	int32 m_initialstate; // 0x04D4
	int32 m_counter; // 0x04D8
};
class CLogicNPCCounterOBB : public CLogicNPCCounterAABB // server
{
};
class CPlatTrigger : public CBaseModelEntity // server
{
	CHandle< CFuncPlat > m_pPlatform; // 0x0770
};
class CSceneEntity : public CPointEntity // server
{
	CUtlSymbolLarge m_iszSceneFile; // 0x04B0
	CUtlSymbolLarge m_iszTarget1; // 0x04B8
	CUtlSymbolLarge m_iszTarget2; // 0x04C0
	CUtlSymbolLarge m_iszTarget3; // 0x04C8
	CUtlSymbolLarge m_iszTarget4; // 0x04D0
	CUtlSymbolLarge m_iszTarget5; // 0x04D8
	CUtlSymbolLarge m_iszTarget6; // 0x04E0
	CUtlSymbolLarge m_iszTarget7; // 0x04E8
	CUtlSymbolLarge m_iszTarget8; // 0x04F0
	CHandle< CBaseEntity > m_hTarget1; // 0x04F8
	CHandle< CBaseEntity > m_hTarget2; // 0x04FC
	CHandle< CBaseEntity > m_hTarget3; // 0x0500
	CHandle< CBaseEntity > m_hTarget4; // 0x0504
	CHandle< CBaseEntity > m_hTarget5; // 0x0508
	CHandle< CBaseEntity > m_hTarget6; // 0x050C
	CHandle< CBaseEntity > m_hTarget7; // 0x0510
	CHandle< CBaseEntity > m_hTarget8; // 0x0514
	CHandle< CBaseEntity > m_hLocatorOrigin; // 0x0518
	CUtlSymbolLarge m_sTargetAttachment; // 0x0520
	bool m_bIsPlayingBack; // 0x0528
	bool m_bPaused; // 0x0529
	bool m_bMultiplayer; // 0x052A
	bool m_bAutogenerated; // 0x052B
	float32 m_flForceClientTime; // 0x052C
	float32 m_flCurrentTime; // 0x0530
	float32 m_flFrameTime; // 0x0534
	bool m_bCancelAtNextInterrupt; // 0x0538
	float32 m_fPitch; // 0x053C
	bool m_bAutomated; // 0x0540
	int32 m_nAutomatedAction; // 0x0544
	float32 m_flAutomationDelay; // 0x0548
	float32 m_flAutomationTime; // 0x054C
	int32 m_nSpeechPriority; // 0x0550
	bool m_bPausedViaInput; // 0x0554
	bool m_bPauseAtNextInterrupt; // 0x0555
	bool m_bWaitingForActor; // 0x0556
	bool m_bWaitingForInterrupt; // 0x0557
	bool m_bInterruptedActorsScenes; // 0x0558
	bool m_bBreakOnNonIdle; // 0x0559
	bool m_bSceneFinished; // 0x055A
	CNetworkUtlVectorBase< CHandle< CBaseModelEntity > > m_hActorList; // 0x0560
	CUtlVector< CHandle< CBaseEntity > > m_hRemoveActorList; // 0x0578
	uint16 m_nSceneStringIndex; // 0x05C0
	CEntityIOOutput m_OnStart; // 0x05C8
	CEntityIOOutput m_OnCompletion; // 0x05E0
	CEntityIOOutput m_OnCanceled; // 0x05F8
	CEntityIOOutput m_OnPaused; // 0x0610
	CEntityIOOutput m_OnResumed; // 0x0628
	CEntityIOOutput m_OnPulseRequirement; // 0x0640
	CUtlVector< ActorMapping_t > m_ActorMap; // 0x0748
	CHandle< CSceneEntity > m_hInterruptScene; // 0x0788
	int32 m_nInterruptCount; // 0x078C
	bool m_bSceneMissing; // 0x0790
	bool m_bInterrupted; // 0x0791
	bool m_bCompletedEarly; // 0x0792
	bool m_bInterruptSceneFinished; // 0x0793
	bool m_bRestoring; // 0x0794
	CUtlVector< CHandle< CSceneEntity > > m_hNotifySceneCompletion; // 0x0798
	CUtlVector< CHandle< CSceneListManager > > m_hListManagers; // 0x07B0
	CUtlSymbolLarge m_iszSoundName; // 0x07C8
	CUtlSymbolLarge m_iszSequenceName; // 0x07D0
	CHandle< CBaseModelEntity > m_hActor; // 0x07D8
	CHandle< CBaseEntity > m_hActivator; // 0x07DC
	int32 m_BusyActor; // 0x07E0
	SceneOnPlayerDeath_t m_iPlayerDeathBehavior; // 0x07E4
};
class CChoreoInfoTarget : public CPointEntity // server
{
};
class CTonemapController2 : public CBaseEntity // server
{
	float32 m_flAutoExposureMin; // 0x04A8
	float32 m_flAutoExposureMax; // 0x04AC
	float32 m_flExposureAdaptationSpeedUp; // 0x04B0
	float32 m_flExposureAdaptationSpeedDown; // 0x04B4
	float32 m_flTonemapEVSmoothingRange; // 0x04B8
};
class CMapSharedEnvironment : public CLogicalEntity // server
{
	CUtlSymbolLarge m_targetMapName; // 0x04A8
};
class CTakeDamageResultAPI // server
{
};
class CNetworkedSequenceOperation // server
{
	HSequence m_hSequence; // 0x0008
	float32 m_flPrevCycle; // 0x000C
	float32 m_flCycle; // 0x0010
	CNetworkedQuantizedFloat m_flWeight; // 0x0014
	bool m_bSequenceChangeNetworked; // 0x001C
	bool m_bDiscontinuity; // 0x001D
	float32 m_flPrevCycleFromDiscontinuity; // 0x0020
	float32 m_flPrevCycleForAnimEventDetection; // 0x0024
};
class CPhysMagnet : public CBaseAnimGraph // server
{
	CEntityIOOutput m_OnMagnetAttach; // 0x0960
	CEntityIOOutput m_OnMagnetDetach; // 0x0978
	float32 m_massScale; // 0x0990
	float32 m_forceLimit; // 0x0994
	float32 m_torqueLimit; // 0x0998
	CUtlVector< magnetted_objects_t > m_MagnettedEntities; // 0x09A0
	bool m_bActive; // 0x09B8
	bool m_bHasHitSomething; // 0x09B9
	float32 m_flTotalMass; // 0x09BC
	float32 m_flRadius; // 0x09C0
	GameTime_t m_flNextSuckTime; // 0x09C4
	int32 m_iMaxObjectsAttached; // 0x09C8
};
class CEntityInstance // entity2
{
	CUtlSymbolLarge m_iszPrivateVScripts; // 0x0008
	CEntityIdentity* m_pEntity; // 0x0010
	CScriptComponent* m_CScriptComponent; // 0x0028
};
class CGameGibManager : public CBaseEntity // server
{
	bool m_bAllowNewGibs; // 0x04C0
	int32 m_iCurrentMaxPieces; // 0x04C4
	int32 m_iMaxPieces; // 0x04C8
	int32 m_iLastFrame; // 0x04CC
};
class CHandleDummy : public CBaseEntity // server
{
};
class CFuncWallToggle : public CFuncWall // server
{
};
class CCSPlayer_BulletServices : public CPlayerPawnComponent // server
{
	int32 m_totalHitsOnServer; // 0x0048
};
class CSkyCamera : public CBaseEntity // server
{
	sky3dparams_t m_skyboxData; // 0x04A8
	CUtlStringToken m_skyboxSlotToken; // 0x0538
	bool m_bUseAngles; // 0x053C
	CSkyCamera* m_pNext; // 0x0540
};
class CCSGO_EndOfMatchLineupEnd : public CCSGO_EndOfMatchLineupEndpoint // server
{
};
class CPlayer_AutoaimServices : public CPlayerPawnComponent // server
{
};
class CItemDefuserAlias_item_defuser : public CItemDefuser // server
{
};
class CPathCornerCrash : public CPathCorner // server
{
};
class CPhysPulley : public CPhysConstraint // server
{
	VectorWS m_position2; // 0x0508
	Vector[2] m_offset; // 0x0514
	float32 m_addLength; // 0x052C
	float32 m_gearRatio; // 0x0530
};
class CCSPetPlacement : public CBaseEntity // server
{
};
class CEnvWindSharedAPI // server
{
};
class CWeaponMP5SD : public CCSWeaponBaseGun // server
{
};
class CWeaponBaseItem : public CCSWeaponBase // server
{
	bool m_bSequenceInProgress; // 0x1050
	bool m_bRedraw; // 0x1051
};
class CCommentaryAuto : public CBaseEntity // server
{
	CEntityIOOutput m_OnCommentaryNewGame; // 0x04A8
	CEntityIOOutput m_OnCommentaryMidGame; // 0x04C0
	CEntityIOOutput m_OnCommentaryMultiplayerSpawn; // 0x04D8
};
class CMapInfo_API // server
{
};
class CPulseCell_Outflow_ListenForEntityOutput::CursorState_t // server
{
	CHandle< CBaseEntity > m_entity; // 0x0000
};
class ActiveModelConfig_t // server
{
	ModelConfigHandle_t m_Handle; // 0x0030
	CUtlSymbolLarge m_Name; // 0x0038
	CNetworkUtlVectorBase< CHandle< CBaseModelEntity > > m_AssociatedEntities; // 0x0040
	CNetworkUtlVectorBase< CUtlSymbolLarge > m_AssociatedEntityNames; // 0x0058
};
class CWeaponUSPSilencer : public CCSWeaponBaseGun // server
{
};
class CSoundStackSave : public CLogicalEntity // server
{
	CUtlSymbolLarge m_iszStackName; // 0x04A8
};
class CPulseCell_Value_Curve : public CPulseCell_BaseValue // pulse_runtime_lib
{
	CPiecewiseCurve m_Curve; // 0x0048
};
class CWeaponMag7 : public CCSWeaponBaseGun // server
{
};
class CLogicMeasureMovement : public CLogicalEntity // server
{
	CUtlSymbolLarge m_strMeasureTarget; // 0x04A8
	CUtlSymbolLarge m_strMeasureReference; // 0x04B0
	CUtlSymbolLarge m_strTargetReference; // 0x04B8
	CHandle< CBaseEntity > m_hMeasureTarget; // 0x04C0
	CHandle< CBaseEntity > m_hMeasureReference; // 0x04C4
	CHandle< CBaseEntity > m_hTarget; // 0x04C8
	CHandle< CBaseEntity > m_hTargetReference; // 0x04CC
	float32 m_flScale; // 0x04D0
	int32 m_nMeasureType; // 0x04D4
};
class CLogicActivityEvent : public CLogicalEntity // server
{
	int32 m_nEventType; // 0x04A8
	float32 m_flDuration; // 0x04AC
	CUtlSymbolLarge m_iszSourceEntityName; // 0x04B0
	CEntityHandle m_hSource; // 0x04B8
};
class CC4 : public CCSWeaponBase // server
{
	VectorWS m_vecLastValidPlayerHeldPosition; // 0x1080
	VectorWS m_vecLastValidDroppedPosition; // 0x108C
	bool m_bDoValidDroppedPositionCheck; // 0x1098
	bool m_bStartedArming; // 0x1099
	GameTime_t m_fArmedTime; // 0x109C
	bool m_bBombPlacedAnimation; // 0x10A0
	bool m_bIsPlantingViaUse; // 0x10A1
	EntitySpottedState_t m_entitySpottedState; // 0x10A8
	int32 m_nSpotRules; // 0x10C0
	bool[7] m_bPlayedArmingBeeps; // 0x10C4
	bool m_bBombPlanted; // 0x10CB
};
class CHostageCarriableProp : public CBaseAnimGraph // server
{
};
class CDynamicPropAlias_cable_dynamic : public CDynamicProp // server
{
};
class CLogicEventListener_API // server
{
};
class CCSObserver_CameraServices : public CCSPlayerBase_CameraServices // server
{
};
class CEnvDetailController : public CBaseEntity // server
{
	float32 m_flFadeStartDist; // 0x04A8
	float32 m_flFadeEndDist; // 0x04AC
};
class CCSPlayerPawnBase : public CBasePlayerPawn // server
{
	CTouchExpansionComponent m_CTouchExpansionComponent; // 0x0BF0
	CCSPlayer_PingServices* m_pPingServices; // 0x0C40
	GameTime_t m_blindUntilTime; // 0x0C48
	GameTime_t m_blindStartTime; // 0x0C4C
	CSPlayerState m_iPlayerState; // 0x0C50
	bool m_bRespawning; // 0x0D00
	bool m_bHasMovedSinceSpawn; // 0x0D01
	int32 m_iNumSpawns; // 0x0D04
	float32 m_flIdleTimeSinceLastAction; // 0x0D0C
	float32 m_fNextRadarUpdateTime; // 0x0D10
	float32 m_flFlashDuration; // 0x0D14
	float32 m_flFlashMaxAlpha; // 0x0D18
	float32 m_flProgressBarStartTime; // 0x0D1C
	int32 m_iProgressBarDuration; // 0x0D20
	CHandle< CCSPlayerController > m_hOriginalController; // 0x0D24
};
class CEnvSoundscapeProxy : public CEnvSoundscape // server
{
	CUtlSymbolLarge m_MainSoundscapeName; // 0x0538
};
class CPulseCell_Inflow_EventHandler : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_EventName; // 0x0080
};
class CCSPointScriptEntity : public CBaseEntity // server
{
};
class CPulseCell_BaseFlow : public CPulseCell_Base // pulse_runtime_lib
{
};
class CBombTarget : public CBaseTrigger // server
{
	CEntityIOOutput m_OnBombExplode; // 0x08E8
	CEntityIOOutput m_OnBombPlanted; // 0x0900
	CEntityIOOutput m_OnBombDefused; // 0x0918
	bool m_bIsBombSiteB; // 0x0930
	bool m_bIsHeistBombTarget; // 0x0931
	bool m_bBombPlantedHere; // 0x0932
	CUtlSymbolLarge m_szMountTarget; // 0x0938
	CHandle< CBaseEntity > m_hInstructorHint; // 0x0940
	int32 m_nBombSiteDesignation; // 0x0944
};
class CRuleEntity : public CBaseModelEntity // server
{
	CUtlSymbolLarge m_iszMaster; // 0x0770
};
class CPhysThruster : public CPhysForce // server
{
	Vector m_localOrigin; // 0x0508
};
class CInfoPlayerStart : public CPointEntity // server
{
	bool m_bDisabled; // 0x04A8
	bool m_bIsMaster; // 0x04A9
	CGlobalSymbol m_pPawnSubclass; // 0x04B0
};
class CEntityFlame : public CBaseEntity // server
{
	CHandle< CBaseEntity > m_hEntAttached; // 0x04A8
	bool m_bCheapEffect; // 0x04AC
	float32 m_flSize; // 0x04B0
	bool m_bUseHitboxes; // 0x04B4
	int32 m_iNumHitboxFires; // 0x04B8
	float32 m_flHitboxFireScale; // 0x04BC
	GameTime_t m_flLifetime; // 0x04C0
	CHandle< CBaseEntity > m_hAttacker; // 0x04C4
	float32 m_flDirectDamagePerSecond; // 0x04C8
	int32 m_iCustomDamageType; // 0x04CC
};
class CSkeletonInstance : public CGameSceneNode // server
{
	CModelState m_modelState; // 0x0120
	bool m_bUseParentRenderBounds; // 0x03B0
	bool m_bDisableSolidCollisionsForHierarchy; // 0x03B1
	bool m_bDirtyMotionType; // 0x03B2
	bool m_bIsGeneratingLatchedParentSpaceState; // 0x03B3
	CUtlStringToken m_materialGroup; // 0x03B8
	uint8 m_nHitboxSet; // 0x03BC
	bool m_bForceServerConstraintsEnabled; // 0x041C
};
class CEntityComponent // entity2
{
};
class CBasePlatTrain : public CBaseToggle // server
{
	CGameSoundEventName m_NoiseMoving; // 0x07F0
	CGameSoundEventName m_NoiseArrived; // 0x07F8
	float32 m_volume; // 0x0808
	float32 m_flTWidth; // 0x080C
	float32 m_flTLength; // 0x0810
};
class CPointTeleport : public CServerOnlyPointEntity // server
{
	VectorWS m_vSaveOrigin; // 0x04A8
	QAngle m_vSaveAngles; // 0x04B4
	bool m_bTeleportParentedEntities; // 0x04C0
	bool m_bTeleportUseCurrentAngle; // 0x04C1
};
class CTriggerGameEvent : public CBaseTrigger // server
{
	CUtlString m_strStartTouchEventName; // 0x08E8
	CUtlString m_strEndTouchEventName; // 0x08F0
	CUtlString m_strTriggerID; // 0x08F8
};
class CMessageEntity : public CPointEntity // server
{
	int32 m_radius; // 0x04A8
	CUtlSymbolLarge m_messageText; // 0x04B0
	bool m_drawText; // 0x04B8
	bool m_bDeveloperOnly; // 0x04B9
	bool m_bEnabled; // 0x04BA
};
class CEnvEntityIgniter : public CBaseEntity // server
{
	float32 m_flLifetime; // 0x04A8
};
class CPulseCell_Outflow_CycleShuffled::InstanceState_t // pulse_runtime_lib
{
	CUtlVectorFixedGrowable< uint8, 8 > m_Shuffle; // 0x0000
	int32 m_nNextShuffle; // 0x0020
};
class CPulseCell_BaseLerp::CursorState_t // pulse_runtime_lib
{
	GameTime_t m_StartTime; // 0x0000
	GameTime_t m_EndTime; // 0x0004
};
class CMarkupVolumeTagged_NavGame : public CMarkupVolumeWithRef // server
{
	NavScopeFlags_t m_nScopes; // 0x07D8
	bool m_bFloodFillAttribute; // 0x07D9
	bool m_bSplitNavSpace; // 0x07DA
};
class CMultiLightProxy : public CLogicalEntity // server
{
	CUtlSymbolLarge m_iszLightNameFilter; // 0x04A8
	CUtlSymbolLarge m_iszLightClassFilter; // 0x04B0
	float32 m_flLightRadiusFilter; // 0x04B8
	float32 m_flBrightnessDelta; // 0x04BC
	bool m_bPerformScreenFade; // 0x04C0
	float32 m_flTargetBrightnessMultiplier; // 0x04C4
	float32 m_flCurrentBrightnessMultiplier; // 0x04C8
	CUtlVector< CHandle< CLightEntity > > m_vecLights; // 0x04D0
};
class CPlantedC4_API // server
{
};
class CWeaponM4A1 : public CCSWeaponBaseGun // server
{
};
class CTriggerHostageReset : public CBaseTrigger // server
{
};
class CEconWearable : public CEconEntity // server
{
	int32 m_nForceSkin; // 0x0C90
	bool m_bAlwaysAllow; // 0x0C94
};
class CChicken_API // server
{
};
class CPulseArraylib // pulse_runtime_lib
{
};
class CWeaponMAC10 : public CCSWeaponBaseGun // server
{
};
class CFuncLadder : public CBaseModelEntity // server
{
	Vector m_vecLadderDir; // 0x0770
	CUtlVector< CHandle< CInfoLadderDismount > > m_Dismounts; // 0x0780
	Vector m_vecLocalTop; // 0x0798
	VectorWS m_vecPlayerMountPositionTop; // 0x07A4
	VectorWS m_vecPlayerMountPositionBottom; // 0x07B0
	float32 m_flAutoRideSpeed; // 0x07BC
	bool m_bDisabled; // 0x07C0
	bool m_bFakeLadder; // 0x07C1
	bool m_bHasSlack; // 0x07C2
	CUtlSymbolLarge m_surfacePropName; // 0x07C8
	CEntityIOOutput m_OnPlayerGotOnLadder; // 0x07D0
	CEntityIOOutput m_OnPlayerGotOffLadder; // 0x07E8
};
class CFogController : public CBaseEntity // server
{
	fogparams_t m_fog; // 0x04A8
	bool m_bUseAngles; // 0x0510
	int32 m_iChangedVariables; // 0x0514
};
class CPointTemplateAPI // server
{
};
class CItem : public CBaseAnimGraph // server
{
	CEntityIOOutput m_OnPlayerTouch; // 0x0968
	CEntityIOOutput m_OnPlayerPickup; // 0x0980
	bool m_bActivateWhenAtRest; // 0x0998
	CEntityIOOutput m_OnCacheInteraction; // 0x09A0
	CEntityIOOutput m_OnGlovePulled; // 0x09B8
	VectorWS m_vOriginalSpawnOrigin; // 0x09D0
	QAngle m_vOriginalSpawnAngles; // 0x09DC
	bool m_bPhysStartAsleep; // 0x09E8
};
class CTriggerPush : public CBaseTrigger // server
{
	QAngle m_angPushEntitySpace; // 0x08E8
	Vector m_vecPushDirEntitySpace; // 0x08F4
	bool m_bTriggerOnStartTouch; // 0x0900
	bool m_bUsePathSimple; // 0x0901
	CUtlSymbolLarge m_iszPathSimpleName; // 0x0908
	CHandle< CPathSimple > m_PathSimple; // 0x0910
	uint32 m_splinePushType; // 0x0914
	float32 m_flSpeed; // 0x0918
};
class CBaseProp : public CBaseAnimGraph // server
{
	bool m_bModelOverrodeBlockLOS; // 0x0960
	int32 m_iShapeType; // 0x0964
	bool m_bConformToCollisionBounds; // 0x0968
	CTransform m_mPreferredCatchTransform; // 0x0970
};
class CInfoOffscreenPanoramaTexture : public CPointEntity // server
{
	bool m_bDisabled; // 0x04A8
	int32 m_nResolutionX; // 0x04AC
	int32 m_nResolutionY; // 0x04B0
	CUtlSymbolLarge m_szPanelType; // 0x04B8
	CUtlSymbolLarge m_szLayoutFileName; // 0x04C0
	CUtlSymbolLarge m_RenderAttrName; // 0x04C8
	CNetworkUtlVectorBase< CHandle< CBaseModelEntity > > m_TargetEntities; // 0x04D0
	int32 m_nTargetChangeCount; // 0x04E8
	CNetworkUtlVectorBase< CUtlSymbolLarge > m_vecCSSClasses; // 0x04F0
	CUtlSymbolLarge m_szTargetsName; // 0x0508
	CUtlVector< CHandle< CBaseModelEntity > > m_AdditionalTargetEntities; // 0x0510
};
class CPointAngularVelocitySensor : public CPointEntity // server
{
	CHandle< CBaseEntity > m_hTargetEntity; // 0x04A8
	float32 m_flThreshold; // 0x04AC
	int32 m_nLastCompareResult; // 0x04B0
	int32 m_nLastFireResult; // 0x04B4
	GameTime_t m_flFireTime; // 0x04B8
	float32 m_flFireInterval; // 0x04BC
	float32 m_flLastAngVelocity; // 0x04C0
	QAngle m_lastOrientation; // 0x04C4
	VectorWS m_vecAxis; // 0x04D0
	bool m_bUseHelper; // 0x04DC
	CEntityOutputTemplate< float32 > m_AngularVelocity; // 0x04E0
	CEntityIOOutput m_OnLessThan; // 0x0500
	CEntityIOOutput m_OnLessThanOrEqualTo; // 0x0518
	CEntityIOOutput m_OnGreaterThan; // 0x0530
	CEntityIOOutput m_OnGreaterThanOrEqualTo; // 0x0548
	CEntityIOOutput m_OnEqualTo; // 0x0560
};
class CPlayerVisibility : public CBaseEntity // server
{
	float32 m_flVisibilityStrength; // 0x04A8
	float32 m_flFogDistanceMultiplier; // 0x04AC
	float32 m_flFogMaxDensityMultiplier; // 0x04B0
	float32 m_flFadeTime; // 0x04B4
	bool m_bStartDisabled; // 0x04B8
	bool m_bIsEnabled; // 0x04B9
};
class CPulseCell_Step_FollowEntity : public CPulseCell_BaseFlow // server
{
	CUtlString m_ParamBoneOrAttachName; // 0x0048
	CUtlString m_ParamBoneOrAttachNameChild; // 0x0050
};
class CFlashbang : public CBaseCSGrenade // server
{
};
class CBasePlayerWeapon : public CEconEntity // server
{
	GameTick_t m_nNextPrimaryAttackTick; // 0x0C90
	float32 m_flNextPrimaryAttackTickRatio; // 0x0C94
	GameTick_t m_nNextSecondaryAttackTick; // 0x0C98
	float32 m_flNextSecondaryAttackTickRatio; // 0x0C9C
	int32 m_iClip1; // 0x0CA0
	int32 m_iClip2; // 0x0CA4
	int32[2] m_pReserveAmmo; // 0x0CA8
	CEntityIOOutput m_OnPlayerUse; // 0x0CB0
};
class CCSWeaponBaseVData : public CBasePlayerWeaponVData // server
{
	CSWeaponType m_WeaponType; // 0x0520
	CSWeaponCategory m_WeaponCategory; // 0x0524
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCNmSkeleton > > m_szAnimSkeleton; // 0x0528
	Vector m_vecMuzzlePos0; // 0x0608
	Vector m_vecMuzzlePos1; // 0x0614
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > > m_szTracerParticle; // 0x0620
	gear_slot_t m_GearSlot; // 0x0700
	int32 m_GearSlotPosition; // 0x0704
	loadout_slot_t m_DefaultLoadoutSlot; // 0x0708
	int32 m_nPrice; // 0x070C
	int32 m_nKillAward; // 0x0710
	int32 m_nPrimaryReserveAmmoMax; // 0x0714
	int32 m_nSecondaryReserveAmmoMax; // 0x0718
	bool m_bMeleeWeapon; // 0x071C
	bool m_bHasBurstMode; // 0x071D
	bool m_bIsRevolver; // 0x071E
	bool m_bCannotShootUnderwater; // 0x071F
	CGlobalSymbol m_szName; // 0x0720
	CSWeaponSilencerType m_eSilencerType; // 0x0728
	int32 m_nCrosshairMinDistance; // 0x072C
	int32 m_nCrosshairDeltaDistance; // 0x0730
	bool m_bIsFullAuto; // 0x0734
	int32 m_nNumBullets; // 0x0738
	bool m_bReloadsSingleShells; // 0x073C
	CFiringModeFloat m_flCycleTime; // 0x0740
	float32 m_flCycleTimeWhenInBurstMode; // 0x0748
	float32 m_flTimeBetweenBurstShots; // 0x074C
	CFiringModeFloat m_flMaxSpeed; // 0x0750
	CFiringModeFloat m_flSpread; // 0x0758
	CFiringModeFloat m_flInaccuracyCrouch; // 0x0760
	CFiringModeFloat m_flInaccuracyStand; // 0x0768
	CFiringModeFloat m_flInaccuracyJump; // 0x0770
	CFiringModeFloat m_flInaccuracyLand; // 0x0778
	CFiringModeFloat m_flInaccuracyLadder; // 0x0780
	CFiringModeFloat m_flInaccuracyFire; // 0x0788
	CFiringModeFloat m_flInaccuracyMove; // 0x0790
	CFiringModeFloat m_flRecoilAngle; // 0x0798
	CFiringModeFloat m_flRecoilAngleVariance; // 0x07A0
	CFiringModeFloat m_flRecoilMagnitude; // 0x07A8
	CFiringModeFloat m_flRecoilMagnitudeVariance; // 0x07B0
	CFiringModeInt m_nTracerFrequency; // 0x07B8
	float32 m_flInaccuracyJumpInitial; // 0x07C0
	float32 m_flInaccuracyJumpApex; // 0x07C4
	float32 m_flInaccuracyReload; // 0x07C8
	float32 m_flDeployDuration; // 0x07CC
	float32 m_flDisallowAttackAfterReloadStartDuration; // 0x07D0
	int32 m_nBurstShotCount; // 0x07D4
	bool m_bAllowBurstHolster; // 0x07D8
	int32 m_nRecoilSeed; // 0x07DC
	int32 m_nSpreadSeed; // 0x07E0
	float32 m_flAttackMovespeedFactor; // 0x07E4
	float32 m_flInaccuracyPitchShift; // 0x07E8
	float32 m_flInaccuracyAltSoundThreshold; // 0x07EC
	CUtlString m_szUseRadioSubtitle; // 0x07F0
	bool m_bUnzoomsAfterShot; // 0x07F8
	bool m_bHideViewModelWhenZoomed; // 0x07F9
	int32 m_nZoomLevels; // 0x07FC
	int32 m_nZoomFOV1; // 0x0800
	int32 m_nZoomFOV2; // 0x0804
	float32 m_flZoomTime0; // 0x0808
	float32 m_flZoomTime1; // 0x080C
	float32 m_flZoomTime2; // 0x0810
	float32 m_flIronSightPullUpSpeed; // 0x0814
	float32 m_flIronSightPutDownSpeed; // 0x0818
	float32 m_flIronSightFOV; // 0x081C
	float32 m_flIronSightPivotForward; // 0x0820
	float32 m_flIronSightLooseness; // 0x0824
	int32 m_nDamage; // 0x0828
	float32 m_flHeadshotMultiplier; // 0x082C
	float32 m_flArmorRatio; // 0x0830
	float32 m_flPenetration; // 0x0834
	float32 m_flRange; // 0x0838
	float32 m_flRangeModifier; // 0x083C
	float32 m_flFlinchVelocityModifierLarge; // 0x0840
	float32 m_flFlinchVelocityModifierSmall; // 0x0844
	float32 m_flRecoveryTimeCrouch; // 0x0848
	float32 m_flRecoveryTimeStand; // 0x084C
	float32 m_flRecoveryTimeCrouchFinal; // 0x0850
	float32 m_flRecoveryTimeStandFinal; // 0x0854
	int32 m_nRecoveryTransitionStartBullet; // 0x0858
	int32 m_nRecoveryTransitionEndBullet; // 0x085C
	float32 m_flThrowVelocity; // 0x0860
	Vector m_vSmokeColor; // 0x0864
	CGlobalSymbol m_szAnimClass; // 0x0870
};
class CPhysForce : public CPointEntity // server
{
	IPhysicsMotionController* m_pController; // 0x04A8
	CUtlSymbolLarge m_nameAttach; // 0x04B0
	float32 m_force; // 0x04B8
	float32 m_forceTime; // 0x04BC
	CHandle< CBaseEntity > m_attachedObject; // 0x04C0
	bool m_wasRestored; // 0x04C4
	CConstantForceController m_integrator; // 0x04C8
};
class CAttributeManager // server
{
	CUtlVector< CHandle< CBaseEntity > > m_Providers; // 0x0008
	int32 m_iReapplyProvisionParity; // 0x0020
	CHandle< CBaseEntity > m_hOuter; // 0x0024
	bool m_bPreventLoopback; // 0x0028
	attributeprovidertypes_t m_ProviderType; // 0x002C
	CUtlVector< CAttributeManager::cached_attribute_float_t > m_CachedResults; // 0x0030
};
class SignatureOutflow_Continue : public CPulse_OutflowConnection // pulse_runtime_lib
{
};
class CInfoTarget : public CPointEntity // server
{
};
class CPlayer_CameraServices : public CPlayerPawnComponent // server
{
	QAngle m_vecCsViewPunchAngle; // 0x0048
	GameTick_t m_nCsViewPunchAngleTick; // 0x0054
	float32 m_flCsViewPunchAngleTickRatio; // 0x0058
	fogplayerparams_t m_PlayerFog; // 0x0060
	CHandle< CColorCorrection > m_hColorCorrectionCtrl; // 0x00A0
	CHandle< CBaseEntity > m_hViewEntity; // 0x00A4
	CHandle< CTonemapController2 > m_hTonemapController; // 0x00A8
	audioparams_t m_audio; // 0x00B0
	CNetworkUtlVectorBase< CHandle< CPostProcessingVolume > > m_PostProcessingVolumes; // 0x0128
	float32 m_flOldPlayerZ; // 0x0140
	float32 m_flOldPlayerViewOffsetZ; // 0x0144
	CUtlVector< CHandle< CEnvSoundscapeTriggerable > > m_hTriggerSoundscapeList; // 0x0160
};
class CPulseCell_Timeline : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CUtlVector< CPulseCell_Timeline::TimelineEvent_t > m_TimelineEvents; // 0x00D8
	bool m_bWaitForChildOutflows; // 0x00F0
	CPulse_ResumePoint m_OnFinished; // 0x00F8
};
class CPulseCell_Inflow_EntOutputHandler : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_SourceEntity; // 0x0080
	PulseSymbol_t m_SourceOutput; // 0x0090
	CPulseValueFullType m_ExpectedParamType; // 0x00A0
};
class CPulseFuncs_GameParticleManager // server
{
};
class CFilterAttributeInt : public CBaseFilter // server
{
	CUtlSymbolLarge m_sAttributeName; // 0x04E0
};
class CKeepUpright : public CPointEntity // server
{
	Vector m_worldGoalAxis; // 0x04B0
	Vector m_localTestAxis; // 0x04BC
	IPhysicsMotionController* m_pController; // 0x04C8
	CUtlSymbolLarge m_nameAttach; // 0x04D0
	CHandle< CBaseEntity > m_attachedObject; // 0x04D8
	float32 m_angularLimit; // 0x04DC
	bool m_bActive; // 0x04E0
	bool m_bDampAllRotation; // 0x04E1
};
class CPointTemplate : public CLogicalEntity // server
{
	CUtlSymbolLarge m_iszWorldName; // 0x04A8
	CUtlSymbolLarge m_iszSource2EntityLumpName; // 0x04B0
	CUtlSymbolLarge m_iszEntityFilterName; // 0x04B8
	float32 m_flTimeoutInterval; // 0x04C0
	bool m_bAsynchronouslySpawnEntities; // 0x04C4
	PointTemplateClientOnlyEntityBehavior_t m_clientOnlyEntityBehavior; // 0x04C8
	PointTemplateOwnerSpawnGroupType_t m_ownerSpawnGroupType; // 0x04CC
	CUtlVector< uint32 > m_createdSpawnGroupHandles; // 0x04D0
	CUtlVector< CEntityHandle > m_SpawnedEntityHandles; // 0x04E8
	HSCRIPT m_ScriptSpawnCallback; // 0x0500
	HSCRIPT m_ScriptCallbackScope; // 0x0508
	CEntityOutputTemplate< CUtlVector< CEntityHandle > > m_OnEntitySpawned; // 0x0510
};
class CEnvVolumetricFogController : public CBaseEntity // server
{
	float32 m_flScattering; // 0x04A8
	Color m_TintColor; // 0x04AC
	float32 m_flAnisotropy; // 0x04B0
	float32 m_flFadeSpeed; // 0x04B4
	float32 m_flDrawDistance; // 0x04B8
	float32 m_flFadeInStart; // 0x04BC
	float32 m_flFadeInEnd; // 0x04C0
	float32 m_flIndirectStrength; // 0x04C4
	int32 m_nVolumeDepth; // 0x04C8
	float32 m_fFirstVolumeSliceThickness; // 0x04CC
	int32 m_nIndirectTextureDimX; // 0x04D0
	int32 m_nIndirectTextureDimY; // 0x04D4
	int32 m_nIndirectTextureDimZ; // 0x04D8
	Vector m_vBoxMins; // 0x04DC
	Vector m_vBoxMaxs; // 0x04E8
	bool m_bActive; // 0x04F4
	GameTime_t m_flStartAnisoTime; // 0x04F8
	GameTime_t m_flStartScatterTime; // 0x04FC
	GameTime_t m_flStartDrawDistanceTime; // 0x0500
	float32 m_flStartAnisotropy; // 0x0504
	float32 m_flStartScattering; // 0x0508
	float32 m_flStartDrawDistance; // 0x050C
	float32 m_flDefaultAnisotropy; // 0x0510
	float32 m_flDefaultScattering; // 0x0514
	float32 m_flDefaultDrawDistance; // 0x0518
	bool m_bStartDisabled; // 0x051C
	bool m_bEnableIndirect; // 0x051D
	bool m_bIsMaster; // 0x051E
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hFogIndirectTexture; // 0x0520
	int32 m_nForceRefreshCount; // 0x0528
	float32 m_fNoiseSpeed; // 0x052C
	float32 m_fNoiseStrength; // 0x0530
	Vector m_vNoiseScale; // 0x0534
	float32 m_fWindSpeed; // 0x0540
	Vector m_vWindDirection; // 0x0544
	bool m_bFirstTime; // 0x0550
};
class CBot // server
{
	CCSPlayerController* m_pController; // 0x0010
	CCSPlayerPawn* m_pPlayer; // 0x0018
	bool m_bHasSpawned; // 0x0020
	uint32 m_id; // 0x0024
	bool m_isRunning; // 0x00C0
	bool m_isCrouching; // 0x00C1
	float32 m_forwardSpeed; // 0x00C4
	float32 m_leftSpeed; // 0x00C8
	float32 m_verticalSpeed; // 0x00CC
	uint64 m_buttonFlags; // 0x00D0
	float32 m_jumpTimestamp; // 0x00D8
	Vector m_viewForward; // 0x00DC
	int32 m_postureStackIndex; // 0x00F8
};
class CPulseCell_Step_SetAnimGraphParam : public CPulseCell_BaseFlow // server
{
	CUtlString m_ParamName; // 0x0048
};
class CPlayer_FlashlightServices : public CPlayerPawnComponent // server
{
};
class CCSPlayerController : public CBasePlayerController // server
{
	CCSPlayerController_InGameMoneyServices* m_pInGameMoneyServices; // 0x07E0
	CCSPlayerController_InventoryServices* m_pInventoryServices; // 0x07E8
	CCSPlayerController_ActionTrackingServices* m_pActionTrackingServices; // 0x07F0
	CCSPlayerController_DamageServices* m_pDamageServices; // 0x07F8
	uint32 m_iPing; // 0x0800
	bool m_bHasCommunicationAbuseMute; // 0x0804
	uint32 m_uiCommunicationMuteFlags; // 0x0808
	CUtlSymbolLarge m_szCrosshairCodes; // 0x0810
	uint8 m_iPendingTeamNum; // 0x0818
	GameTime_t m_flForceTeamTime; // 0x081C
	int32 m_iCompTeammateColor; // 0x0820
	bool m_bEverPlayedOnTeam; // 0x0824
	bool m_bAttemptedToGetColor; // 0x0825
	int32 m_iTeammatePreferredColor; // 0x0828
	bool m_bTeamChanged; // 0x082C
	bool m_bInSwitchTeam; // 0x082D
	bool m_bHasSeenJoinGame; // 0x082E
	bool m_bJustBecameSpectator; // 0x082F
	bool m_bSwitchTeamsOnNextRoundReset; // 0x0830
	bool m_bRemoveAllItemsOnNextRoundReset; // 0x0831
	GameTime_t m_flLastJoinTeamTime; // 0x0834
	CUtlSymbolLarge m_szClan; // 0x0838
	int32 m_iCoachingTeam; // 0x0840
	uint64 m_nPlayerDominated; // 0x0848
	uint64 m_nPlayerDominatingMe; // 0x0850
	int32 m_iCompetitiveRanking; // 0x0858
	int32 m_iCompetitiveWins; // 0x085C
	int8 m_iCompetitiveRankType; // 0x0860
	int32 m_iCompetitiveRankingPredicted_Win; // 0x0864
	int32 m_iCompetitiveRankingPredicted_Loss; // 0x0868
	int32 m_iCompetitiveRankingPredicted_Tie; // 0x086C
	int32 m_nEndMatchNextMapVote; // 0x0870
	uint16 m_unActiveQuestId; // 0x0874
	uint32 m_rtActiveMissionPeriod; // 0x0878
	QuestProgress::Reason m_nQuestProgressReason; // 0x087C
	uint32 m_unPlayerTvControlFlags; // 0x0880
	int32 m_iDraftIndex; // 0x08B0
	uint32 m_msQueuedModeDisconnectionTimestamp; // 0x08B4
	uint32 m_uiAbandonRecordedReason; // 0x08B8
	uint32 m_eNetworkDisconnectionReason; // 0x08BC
	bool m_bCannotBeKicked; // 0x08C0
	bool m_bEverFullyConnected; // 0x08C1
	bool m_bAbandonAllowsSurrender; // 0x08C2
	bool m_bAbandonOffersInstantSurrender; // 0x08C3
	bool m_bDisconnection1MinWarningPrinted; // 0x08C4
	bool m_bScoreReported; // 0x08C5
	int32 m_nDisconnectionTick; // 0x08C8
	bool m_bControllingBot; // 0x08D8
	bool m_bHasControlledBotThisRound; // 0x08D9
	bool m_bHasBeenControlledByPlayerThisRound; // 0x08DA
	int32 m_nBotsControlledThisRound; // 0x08DC
	bool m_bCanControlObservedBot; // 0x08E0
	CHandle< CCSPlayerPawn > m_hPlayerPawn; // 0x08E4
	CHandle< CCSObserverPawn > m_hObserverPawn; // 0x08E8
	int32 m_DesiredObserverMode; // 0x08EC
	CEntityHandle m_hDesiredObserverTarget; // 0x08F0
	bool m_bPawnIsAlive; // 0x08F4
	uint32 m_iPawnHealth; // 0x08F8
	int32 m_iPawnArmor; // 0x08FC
	bool m_bPawnHasDefuser; // 0x0900
	bool m_bPawnHasHelmet; // 0x0901
	uint16 m_nPawnCharacterDefIndex; // 0x0902
	int32 m_iPawnLifetimeStart; // 0x0904
	int32 m_iPawnLifetimeEnd; // 0x0908
	int32 m_iPawnBotDifficulty; // 0x090C
	CHandle< CCSPlayerController > m_hOriginalControllerOfCurrentPawn; // 0x0910
	int32 m_iScore; // 0x0914
	int32 m_iRoundScore; // 0x0918
	int32 m_iRoundsWon; // 0x091C
	uint8[8] m_recentKillQueue; // 0x0920
	uint8 m_nFirstKill; // 0x0928
	uint8 m_nKillCount; // 0x0929
	bool m_bMvpNoMusic; // 0x092A
	int32 m_eMvpReason; // 0x092C
	int32 m_iMusicKitID; // 0x0930
	int32 m_iMusicKitMVPs; // 0x0934
	int32 m_iMVPs; // 0x0938
	int32 m_nUpdateCounter; // 0x093C
	float32 m_flSmoothedPing; // 0x0940
	IntervalTimer m_lastHeldVoteTimer; // 0x0948
	bool m_bShowHints; // 0x0960
	int32 m_iNextTimeCheck; // 0x0964
	bool m_bJustDidTeamKill; // 0x0968
	bool m_bPunishForTeamKill; // 0x0969
	bool m_bGaveTeamDamageWarning; // 0x096A
	bool m_bGaveTeamDamageWarningThisRound; // 0x096B
	float64 m_dblLastReceivedPacketPlatFloatTime; // 0x0970
	GameTime_t m_LastTeamDamageWarningTime; // 0x0978
	GameTime_t m_LastTimePlayerWasDisconnectedForPawnsRemove; // 0x097C
	uint32 m_nSuspiciousHitCount; // 0x0980
	uint32 m_nNonSuspiciousHitStreak; // 0x0984
	bool m_bFireBulletsSeedSynchronized; // 0x0A29
};
class CPhysLength : public CPhysConstraint // server
{
	Vector[2] m_offset; // 0x0508
	VectorWS m_vecAttach; // 0x0520
	float32 m_addLength; // 0x052C
	float32 m_minLength; // 0x0530
	float32 m_totalLength; // 0x0534
};
class CTeam : public CBaseEntity // server
{
	CNetworkUtlVectorBase< CHandle< CBasePlayerController > > m_aPlayerControllers; // 0x04A8
	CNetworkUtlVectorBase< CHandle< CBasePlayerPawn > > m_aPlayers; // 0x04C0
	int32 m_iScore; // 0x04D8
	char[129] m_szTeamname; // 0x04DC
};
class CFuncConveyor_API // server
{
};
class CLogicNPCCounterAABB : public CLogicNPCCounter // server
{
	Vector m_vDistanceOuterMins; // 0x0728
	Vector m_vDistanceOuterMaxs; // 0x0734
	VectorWS m_vOuterMins; // 0x0740
	VectorWS m_vOuterMaxs; // 0x074C
};
class CPulseCell_Outflow_CycleOrdered::InstanceState_t // pulse_runtime_lib
{
	int32 m_nNextIndex; // 0x0000
};
class CChicken : public CDynamicProp // server
{
	CAttributeContainer m_AttributeManager; // 0x0BC0
	CountdownTimer m_updateTimer; // 0x0EB8
	VectorWS m_stuckAnchor; // 0x0ED0
	CountdownTimer m_collisionStuckTimer; // 0x0EE0
	bool m_isOnGround; // 0x0EF8
	Vector m_vFallVelocity; // 0x0EFC
	EChickenActivity m_desiredActivity; // 0x0F08
	EChickenActivity m_currentActivity; // 0x0F0C
	CountdownTimer m_activityTimer; // 0x0F10
	float32 m_turnRate; // 0x0F28
	CHandle< CBaseEntity > m_fleeFrom; // 0x0F2C
	CountdownTimer m_moveRateThrottleTimer; // 0x0F30
	CountdownTimer m_startleTimer; // 0x0F48
	CountdownTimer m_vocalizeTimer; // 0x0F60
	CHandle< CCSPlayerPawn > m_leader; // 0x0F78
	CountdownTimer m_reuseTimer; // 0x0F90
	CountdownTimer m_jumpTimer; // 0x0FA8
	float32 m_flLastJumpTime; // 0x0FC0
	CountdownTimer m_repathTimer; // 0x2FD0
	VectorWS m_vecPathGoal; // 0x3068
	GameTime_t m_flActiveFollowStartTime; // 0x3074
	CountdownTimer m_followMinuteTimer; // 0x3078
	CountdownTimer m_BlockDirectionTimer; // 0x3098
};
class CPhysicsPropRespawnable : public CPhysicsProp // server
{
	VectorWS m_vOriginalSpawnOrigin; // 0x0C30
	QAngle m_vOriginalSpawnAngles; // 0x0C3C
	Vector m_vOriginalMins; // 0x0C48
	Vector m_vOriginalMaxs; // 0x0C54
	float32 m_flRespawnDuration; // 0x0C60
};
class CEnvBeam : public CBeam // server
{
	int32 m_active; // 0x0810
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_spriteTexture; // 0x0818
	CUtlSymbolLarge m_iszStartEntity; // 0x0820
	CUtlSymbolLarge m_iszEndEntity; // 0x0828
	float32 m_life; // 0x0830
	float32 m_boltWidth; // 0x0834
	float32 m_noiseAmplitude; // 0x0838
	int32 m_speed; // 0x083C
	float32 m_restrike; // 0x0840
	CUtlSymbolLarge m_iszSpriteName; // 0x0848
	int32 m_frameStart; // 0x0850
	VectorWS m_vEndPointWorld; // 0x0854
	Vector m_vEndPointRelative; // 0x0860
	float32 m_radius; // 0x086C
	Touch_t m_TouchType; // 0x0870
	CUtlSymbolLarge m_iFilterName; // 0x0878
	CHandle< CBaseEntity > m_hFilter; // 0x0880
	CUtlSymbolLarge m_iszDecal; // 0x0888
	CEntityIOOutput m_OnTouchedByEntity; // 0x0890
};
class CLightSpotEntity : public CLightEntity // server
{
};
class CWeaponSawedoff : public CCSWeaponBaseShotgun // server
{
};
class CTonemapTrigger : public CBaseTrigger // server
{
	CUtlSymbolLarge m_tonemapControllerName; // 0x08E8
	CEntityHandle m_hTonemapController; // 0x08F0
};
class CEnvShake : public CPointEntity // server
{
	CUtlSymbolLarge m_limitToEntity; // 0x04A8
	float32 m_Amplitude; // 0x04B0
	float32 m_Frequency; // 0x04B4
	float32 m_Duration; // 0x04B8
	float32 m_Radius; // 0x04BC
	GameTime_t m_stopTime; // 0x04C0
	GameTime_t m_nextShake; // 0x04C4
	float32 m_currentAmp; // 0x04C8
	Vector m_maxForce; // 0x04CC
	IPhysicsMotionController* m_pShakeController; // 0x04D8
	CPhysicsShake m_shakeCallback; // 0x04E0
};
class CCSPlayer_MovementServices : public CPlayer_MovementServices_Humanoid // server
{
	CCSPlayerAnimationState m_AnimationState; // 0x0310
	bool m_bUsingGroundTopologyOffset; // 0x03F0
	float32 m_flUsingGroundTopologyOffsetTransitionSmoothing; // 0x03F4
	Vector m_vecLadderNormal; // 0x03F8
	int32 m_nLadderSurfacePropIndex; // 0x0404
	bool m_bDucked; // 0x0408
	float32 m_flDuckAmount; // 0x040C
	float32 m_flDuckSpeed; // 0x0410
	bool m_bDuckOverride; // 0x0414
	bool m_bDesiresDuck; // 0x0415
	bool m_bDucking; // 0x0416
	float32 m_flDuckRootOffset; // 0x0418
	float32 m_flDuckViewOffset; // 0x041C
	float32 m_flLastDuckTime; // 0x0420
	float32 m_flBombPlantViewOffset; // 0x0424
	Vector2D m_vecLastPositionAtFullCrouchSpeed; // 0x0430
	bool m_duckUntilOnGround; // 0x0438
	bool m_bHasWalkMovedSinceLastJump; // 0x0439
	bool m_bInStuckTest; // 0x043A
	int32 m_nTraceCount; // 0x0648
	int32 m_StuckLast; // 0x064C
	bool m_bSpeedCropped; // 0x0650
	int32 m_nOldWaterLevel; // 0x0654
	float32 m_flWaterEntryTime; // 0x0658
	Vector m_vecForward; // 0x065C
	Vector m_vecLeft; // 0x0668
	Vector m_vecUp; // 0x0674
	int32 m_nGameCodeHasMovedPlayerAfterCommand; // 0x0680
	bool m_bMadeFootstepNoise; // 0x0684
	int32 m_iFootsteps; // 0x0688
	GameTime_t m_fStashGrenadeParameterWhen; // 0x068C
	bool m_bUseFrictionStashedSpeed; // 0x0690
	float32 m_flUseFrictionStashedSpeedUntilFrac; // 0x0694
	float32 m_flFrictionStashedSpeed; // 0x0698
	float32 m_flStamina; // 0x069C
	float32 m_flHeightAtJumpStart; // 0x06A0
	float32 m_flMaxJumpHeightThisJump; // 0x06A4
	float32 m_flMaxJumpHeightLastJump; // 0x06A8
	float32 m_flStaminaAtJumpStart; // 0x06AC
	float32 m_flVelMulAtJumpStart; // 0x06B0
	float32 m_flAccumulatedJumpError; // 0x06B4
	CCSPlayerLegacyJump m_LegacyJump; // 0x06B8
	CCSPlayerModernJump m_ModernJump; // 0x06D0
	GameTick_t m_nLastJumpTick; // 0x0708
	float32 m_flLastJumpFrac; // 0x070C
	float32 m_flLastJumpVelocityZ; // 0x0710
	bool m_bJumpApexPending; // 0x0714
	float32 m_flTicksSinceLastSurfingDetected; // 0x0718
	Vector2D m_vecWalkWishVel; // 0x07A8
	bool m_bHasEverProcessedCommand; // 0x0FD0
};
class SellbackPurchaseEntry_t // server
{
	uint16 m_unDefIdx; // 0x0030
	int32 m_nCost; // 0x0034
	int32 m_nPrevArmor; // 0x0038
	bool m_bPrevHelmet; // 0x003C
	CEntityHandle m_hItem; // 0x0040
};
class CTestPulseIO::EntityNameStringArgs_t // server
{
	CEntityNameString nameA; // 0x0000
	CUtlSymbolLarge strValueB; // 0x0008
};
class CFuncMoverRouter : public CLogicalEntity // server
{
	int32 m_nMoverIndex; // 0x04B0
	bool m_bRouteToAllMovers; // 0x04B4
	CHandle< CPathMover > m_hPathMover; // 0x04B8
	CUtlSymbolLarge m_iszPathMoverName; // 0x04C0
};
class CTriggerCallback : public CBaseTrigger // server
{
};
class CSoundOpvarSetAutoRoomEntity : public CSoundOpvarSetPointEntity // server
{
	CUtlVector< SoundOpvarTraceResult_t > m_traceResults; // 0x0640
	CUtlVector< AutoRoomDoorwayPairs_t > m_doorwayPairs; // 0x0658
	float32 m_flSize; // 0x0670
	float32 m_flHeightTolerance; // 0x0674
	float32 m_flSizeSqr; // 0x0678
};
class CPulseCell_Outflow_ListenForEntityOutput : public CPulseCell_BaseYieldingInflow // server
{
	SignatureOutflow_Resume m_OnFired; // 0x00D8
	CGlobalSymbol m_strEntityOutput; // 0x0120
	CUtlString m_strEntityOutputParam; // 0x0128
	bool m_bListenUntilCanceled; // 0x0130
};
class CPushable : public CBreakable // server
{
};
class CRotatorTarget : public CPointEntity // server
{
	CEntityIOOutput m_OnArrivedAt; // 0x04A8
	RotatorTargetSpace_t m_eSpace; // 0x04C0
};
class CPhysicsEntitySolver : public CLogicalEntity // server
{
	CHandle< CBaseEntity > m_hMovingEntity; // 0x04C0
	CHandle< CBaseEntity > m_hPhysicsBlocker; // 0x04C4
	float32 m_separationDuration; // 0x04C8
	GameTime_t m_cancelTime; // 0x04CC
};
class CLogicCollisionPair : public CLogicalEntity // server
{
	CUtlSymbolLarge m_nameAttach1; // 0x04A8
	CUtlSymbolLarge m_nameAttach2; // 0x04B0
	bool m_includeHierarchy; // 0x04B8
	bool m_supportMultipleEntitiesWithSameName; // 0x04B9
	bool m_disabled; // 0x04BA
	bool m_succeeded; // 0x04BB
	bool m_allowMissing; // 0x04BC
};
class CTestEffect : public CBaseEntity // server
{
	int32 m_iLoop; // 0x04A8
	int32 m_iBeam; // 0x04AC
	CHandle< CBeam >[24] m_pBeam; // 0x04B0
	GameTime_t[24] m_flBeamTime; // 0x0510
	GameTime_t m_flStartTime; // 0x0570
};
class CPulseCell_Outflow_ScriptedSequence::CursorState_t // server
{
	CHandle< CBaseEntity > m_scriptedSequence; // 0x0000
};
class CPropDoorRotating : public CBasePropDoor // server
{
	Vector m_vecAxis; // 0x0DA0
	float32 m_flDistance; // 0x0DAC
	PropDoorRotatingSpawnPos_t m_eSpawnPosition; // 0x0DB0
	PropDoorRotatingOpenDirection_e m_eOpenDirection; // 0x0DB4
	PropDoorRotatingOpenDirection_e m_eCurrentOpenDirection; // 0x0DB8
	doorCheck_e m_eDefaultCheckDirection; // 0x0DBC
	float32 m_flAjarAngle; // 0x0DC0
	QAngle m_angRotationAjarDeprecated; // 0x0DC4
	QAngle m_angRotationClosed; // 0x0DD0
	QAngle m_angRotationOpenForward; // 0x0DDC
	QAngle m_angRotationOpenBack; // 0x0DE8
	QAngle m_angGoal; // 0x0DF4
	Vector m_vecForwardBoundsMin; // 0x0E00
	Vector m_vecForwardBoundsMax; // 0x0E0C
	Vector m_vecBackBoundsMin; // 0x0E18
	Vector m_vecBackBoundsMax; // 0x0E24
	bool m_bAjarDoorShouldntAlwaysOpen; // 0x0E30
	CHandle< CEntityBlocker > m_hEntityBlocker; // 0x0E34
};
class CEnvParticleGlow : public CParticleSystem // server
{
	float32 m_flAlphaScale; // 0x0CF8
	float32 m_flRadiusScale; // 0x0CFC
	float32 m_flSelfIllumScale; // 0x0D00
	Color m_ColorTint; // 0x0D04
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hTextureOverride; // 0x0D08
};
class CMathRemap : public CLogicalEntity // server
{
	float32 m_flInMin; // 0x04A8
	float32 m_flInMax; // 0x04AC
	float32 m_flOut1; // 0x04B0
	float32 m_flOut2; // 0x04B4
	float32 m_flOldInValue; // 0x04B8
	bool m_bEnabled; // 0x04BC
	CEntityOutputTemplate< float32 > m_OutValue; // 0x04C0
	CEntityIOOutput m_OnRoseAboveMin; // 0x04E0
	CEntityIOOutput m_OnRoseAboveMax; // 0x04F8
	CEntityIOOutput m_OnFellBelowMin; // 0x0510
	CEntityIOOutput m_OnFellBelowMax; // 0x0528
};
class CSoundOpvarSetOBBWindEntity : public CSoundOpvarSetPointBase // server
{
	Vector m_vMins; // 0x0550
	Vector m_vMaxs; // 0x055C
	Vector m_vDistanceMins; // 0x0568
	Vector m_vDistanceMaxs; // 0x0574
	float32 m_flWindMin; // 0x0580
	float32 m_flWindMax; // 0x0584
	float32 m_flWindMapMin; // 0x0588
	float32 m_flWindMapMax; // 0x058C
};
class PhysicsRagdollPose_t // server
{
	CNetworkUtlVectorBase< CTransform > m_Transforms; // 0x0008
	CHandle< CBaseEntity > m_hOwner; // 0x0020
	bool m_bSetFromDebugHistory; // 0x0024
};
class CPropDataComponent : public CEntityComponent // server
{
	float32 m_flDmgModBullet; // 0x0010
	float32 m_flDmgModClub; // 0x0014
	float32 m_flDmgModExplosive; // 0x0018
	float32 m_flDmgModFire; // 0x001C
	CUtlSymbolLarge m_iszPhysicsDamageTableName; // 0x0020
	CUtlSymbolLarge m_iszBasePropData; // 0x0028
	int32 m_nInteractions; // 0x0030
	bool m_bSpawnMotionDisabled; // 0x0034
	int32 m_nDisableTakePhysicsDamageSpawnFlag; // 0x0038
	int32 m_nMotionDisabledSpawnFlag; // 0x003C
};
class CScriptTriggerOnce : public CTriggerOnce // server
{
	Vector m_vExtent; // 0x0900
};
class CLightOrthoEntity : public CLightEntity // server
{
};
class CInfoInstructorHintHostageRescueZone : public CPointEntity // server
{
};
class CPulseCell_LimitCount::InstanceState_t // pulse_runtime_lib
{
	int32 m_nCurrentCount; // 0x0000
};
class CTriggerTeleport : public CBaseTrigger // server
{
	CUtlSymbolLarge m_iLandmark; // 0x08E8
	bool m_bUseLandmarkAngles; // 0x08F0
	bool m_bMirrorPlayer; // 0x08F1
	bool m_bCheckDestIfClearForPlayer; // 0x08F2
};
class CFuncWall : public CBaseModelEntity // server
{
	int32 m_nState; // 0x0770
};
class CBtActionAim : public CBtNode // server
{
	CUtlString m_szSensorInputKey; // 0x0068
	CUtlString m_szAimReadyKey; // 0x0080
	float32 m_flZoomCooldownTimestamp; // 0x0088
	bool m_bDoneAiming; // 0x008C
	float32 m_flLerpStartTime; // 0x0090
	float32 m_flNextLookTargetLerpTime; // 0x0094
	float32 m_flPenaltyReductionRatio; // 0x0098
	QAngle m_NextLookTarget; // 0x009C
	CountdownTimer m_AimTimer; // 0x00A8
	CountdownTimer m_SniperHoldTimer; // 0x00C0
	CountdownTimer m_FocusIntervalTimer; // 0x00D8
	bool m_bAcquired; // 0x00F0
};
class CCSGO_TeamPreviewCharacterPosition : public CBaseEntity // server
{
	int32 m_nVariant; // 0x04A8
	int32 m_nRandom; // 0x04AC
	int32 m_nOrdinal; // 0x04B0
	CUtlString m_sWeaponName; // 0x04B8
	uint64 m_xuid; // 0x04C0
	CEconItemView m_agentItem; // 0x04C8
	CEconItemView m_glovesItem; // 0x0770
	CEconItemView m_weaponItem; // 0x0A18
};
class CGameRulesProxy : public CBaseEntity // server
{
};
class CInfoLadderDismount : public CBaseEntity // server
{
};
class CPulseServerFuncs // server
{
};
class CLightEntityAPI // server
{
};
class CMessage : public CPointEntity // server
{
	CUtlSymbolLarge m_iszMessage; // 0x04A8
	float32 m_MessageVolume; // 0x04B0
	int32 m_MessageAttenuation; // 0x04B4
	float32 m_Radius; // 0x04B8
	CGameSoundEventName m_sNoise; // 0x04C0
	CEntityIOOutput m_OnShowMessage; // 0x04C8
};
class CPointVelocitySensor : public CPointEntity // server
{
	CHandle< CBaseEntity > m_hTargetEntity; // 0x04A8
	Vector m_vecAxis; // 0x04AC
	bool m_bEnabled; // 0x04B8
	float32 m_fPrevVelocity; // 0x04BC
	float32 m_flAvgInterval; // 0x04C0
	CEntityOutputTemplate< float32 > m_Velocity; // 0x04C8
};
class CCS2PawnGraphController : public CCS2WeaponGraphController // server
{
	CAnimGraph2ParamOptionalRef< bool > m_bIsDefusing; // 0x0588
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_moveType; // 0x05A0
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_moveDirectionID; // 0x05B8
	CAnimGraph2ParamOptionalRef< float32 > m_flMoveSpeedX; // 0x05D0
	CAnimGraph2ParamOptionalRef< float32 > m_flMoveSpeedY; // 0x05E8
	CAnimGraph2ParamOptionalRef< float32 > m_flMoveSpeedHorizontal; // 0x0600
	CAnimGraph2ParamOptionalRef< float32 > m_flPreviousMoveSpeedHorizontal; // 0x0618
	CAnimGraph2ParamOptionalRef< float32 > m_flCrouchAmount; // 0x0630
	CAnimGraph2ParamOptionalRef< bool > m_bIsWalking; // 0x0648
	CAnimGraph2ParamOptionalRef< float32 > m_flWeaponDropAmount; // 0x0660
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_groundAction; // 0x0678
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_groundActionDirectionID; // 0x0690
	CAnimGraph2ParamOptionalRef< float32 > m_flGroundTurnAngleOrVelocity; // 0x06A8
	CAnimGraph2ParamOptionalRef< float32 > m_flLadderCycle; // 0x06C0
	CAnimGraph2ParamOptionalRef< float32 > m_flLadderYaw; // 0x06D8
	CAnimGraph2ParamOptionalRef< float32 > m_flLadderYawBackwards; // 0x06F0
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_airAction; // 0x0708
	CAnimGraph2ParamOptionalRef< float32 > m_flAirHeightAboveGround; // 0x0720
	CAnimGraph2ParamOptionalRef< CNmTarget > m_leftFootTarget; // 0x0738
	CAnimGraph2ParamOptionalRef< CNmTarget > m_rightFootTarget; // 0x0750
	CAnimGraph2ParamOptionalRef< float32 > m_flFlashedAmount; // 0x0768
	CAnimGraph2ParamOptionalRef< float32 > m_flAimPitchAngle; // 0x0780
	CAnimGraph2ParamOptionalRef< float32 > m_flAimYawAngle; // 0x0798
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_flinchHead; // 0x07B0
	CAnimGraph2ParamOptionalRef< bool > m_flinchHeadRestart; // 0x07C8
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_flinchBody; // 0x07E0
	CAnimGraph2ParamOptionalRef< bool > m_flinchBodyRestart; // 0x07F8
	CAnimGraph2ParamOptionalRef< bool > m_flinchIsOnFire; // 0x0810
};
class EngineCountdownTimer // server
{
	float32 m_duration; // 0x0008
	float32 m_timestamp; // 0x000C
	float32 m_timescale; // 0x0010
};
class CBaseModelEntityAPI // server
{
};
class CScriptTriggerMultiple : public CTriggerMultiple // server
{
	Vector m_vExtent; // 0x0900
};
class CHostage : public CHostageExpresserShim // server
{
	CEntityIOOutput m_OnHostageBeginGrab; // 0x0A58
	CEntityIOOutput m_OnFirstPickedUp; // 0x0A70
	CEntityIOOutput m_OnDroppedNotRescued; // 0x0A88
	CEntityIOOutput m_OnRescued; // 0x0AA0
	EntitySpottedState_t m_entitySpottedState; // 0x0AB8
	int32 m_nSpotRules; // 0x0AD0
	uint32 m_uiHostageSpawnExclusionGroupMask; // 0x0AD4
	uint32 m_nHostageSpawnRandomFactor; // 0x0AD8
	bool m_bRemove; // 0x0ADC
	Vector m_vel; // 0x0AE0
	bool m_isRescued; // 0x0AEC
	bool m_jumpedThisFrame; // 0x0AED
	int32 m_nHostageState; // 0x0AF0
	CHandle< CBaseEntity > m_leader; // 0x0AF4
	CHandle< CCSPlayerPawnBase > m_lastLeader; // 0x0AF8
	CountdownTimer m_reuseTimer; // 0x0B00
	bool m_hasBeenUsed; // 0x0B18
	Vector m_accel; // 0x0B1C
	bool m_isRunning; // 0x0B28
	bool m_isCrouching; // 0x0B29
	CountdownTimer m_jumpTimer; // 0x0B30
	bool m_isWaitingForLeader; // 0x0B48
	CountdownTimer m_repathTimer; // 0x2B58
	CountdownTimer m_inhibitDoorTimer; // 0x2B70
	CountdownTimer m_inhibitObstacleAvoidanceTimer; // 0x2C00
	CountdownTimer m_wiggleTimer; // 0x2C20
	bool m_isAdjusted; // 0x2C3C
	bool m_bHandsHaveBeenCut; // 0x2C3D
	CHandle< CCSPlayerPawn > m_hHostageGrabber; // 0x2C40
	GameTime_t m_fLastGrabTime; // 0x2C44
	VectorWS m_vecPositionWhenStartedDroppingToGround; // 0x2C48
	VectorWS m_vecGrabbedPos; // 0x2C54
	GameTime_t m_flRescueStartTime; // 0x2C60
	GameTime_t m_flGrabSuccessTime; // 0x2C64
	GameTime_t m_flDropStartTime; // 0x2C68
	int32 m_nApproachRewardPayouts; // 0x2C6C
	int32 m_nPickupEventCount; // 0x2C70
	VectorWS m_vecSpawnGroundPos; // 0x2C74
	VectorWS m_vecHostageResetPosition; // 0x2CAC
};
class CEnvSpark : public CPointEntity // server
{
	float32 m_flDelay; // 0x04A8
	int32 m_nMagnitude; // 0x04AC
	int32 m_nTrailLength; // 0x04B0
	int32 m_nType; // 0x04B4
	CEntityIOOutput m_OnSpark; // 0x04B8
};
class CCSPlayerController_DamageServices : public CPlayerControllerComponent // server
{
	int32 m_nSendUpdate; // 0x0040
	CUtlVectorEmbeddedNetworkVar< CDamageRecord > m_DamageList; // 0x0048
};
class CEnvCombinedLightProbeVolumeAlias_func_combined_light_probe_volume : public CEnvCombinedLightProbeVolume // server
{
};
class CBaseModelEntity::OnDamageLevelChangedArgs_t // server
{
	HitGroup_t nHitGroup; // 0x0000
	int32 nDamageLevel; // 0x0004
	int32 nDamageLevelsRemaining; // 0x0008
	int32 nPrevDamageLevel; // 0x000C
};
class CFilterLOS : public CBaseFilter // server
{
};
class CPointOrient : public CBaseEntity // server
{
	CUtlSymbolLarge m_iszSpawnTargetName; // 0x04A8
	CHandle< CBaseEntity > m_hTarget; // 0x04B0
	bool m_bActive; // 0x04B4
	PointOrientGoalDirectionType_t m_nGoalDirection; // 0x04B8
	PointOrientConstraint_t m_nConstraint; // 0x04BC
	float32 m_flMaxTurnRate; // 0x04C0
	GameTime_t m_flLastGameTime; // 0x04C4
};
class sky3dparams_t // server
{
	int16 scale; // 0x0008
	VectorWS origin; // 0x000C
	bool bClip3DSkyBoxNearToWorldFar; // 0x0018
	float32 flClip3DSkyBoxNearToWorldFarOffset; // 0x001C
	fogparams_t fog; // 0x0020
	WorldGroupId_t m_nWorldGroupID; // 0x0088
};
class CWeaponP250 : public CCSWeaponBaseGun // server
{
};
class CDestructiblePartsComponent // server
{
	CNetworkVarChainer __m_pChainEntity; // 0x0000
	CUtlVector< uint16 > m_vecDamageTakenByHitGroup; // 0x0048
	CHandle< CBaseModelEntity > m_hOwner; // 0x0060
	CAnimGraphControllerPtr m_pAnimGraphDestructibleGraphController; // 0x0068
};
class CChangeLevel : public CBaseTrigger // server
{
	CUtlString m_sMapName; // 0x08E8
	CUtlString m_sLandmarkName; // 0x08F0
	CEntityIOOutput m_OnChangeLevel; // 0x08F8
	bool m_bTouched; // 0x0910
	bool m_bNoTouch; // 0x0911
	bool m_bNewChapter; // 0x0912
	bool m_bOnChangeLevelFired; // 0x0913
};
class CBaseButton : public CBaseToggle // server
{
	QAngle m_angMoveEntitySpace; // 0x07F0
	bool m_fStayPushed; // 0x07FC
	bool m_fRotating; // 0x07FD
	locksound_t m_ls; // 0x0800
	CGameSoundEventName m_sUseSound; // 0x0820
	CGameSoundEventName m_sLockedSound; // 0x0828
	CGameSoundEventName m_sUnlockedSound; // 0x0830
	CUtlSymbolLarge m_sOverrideAnticipationName; // 0x0838
	bool m_bLocked; // 0x0840
	bool m_bDisabled; // 0x0841
	float32 m_flSpeed; // 0x0844
	GameTime_t m_flUseLockedTime; // 0x0848
	bool m_bSolidBsp; // 0x084C
	CEntityIOOutput m_OnDamaged; // 0x0850
	CEntityIOOutput m_OnPressed; // 0x0868
	CEntityIOOutput m_OnUseLocked; // 0x0880
	CEntityIOOutput m_OnIn; // 0x0898
	CEntityIOOutput m_OnOut; // 0x08B0
	int32 m_nState; // 0x08C8
	CEntityHandle m_hConstraint; // 0x08CC
	CEntityHandle m_hConstraintParent; // 0x08D0
	bool m_bForceNpcExclude; // 0x08D4
	CUtlSymbolLarge m_sGlowEntity; // 0x08D8
	CHandle< CBaseModelEntity > m_glowEntity; // 0x08E0
	bool m_usable; // 0x08E4
	CUtlSymbolLarge m_szDisplayText; // 0x08E8
};
class CPulseCell_SoundEventStart : public CPulseCell_BaseFlow // server
{
	SoundEventStartType_t m_Type; // 0x0048
};
class CPulseCell_Step_DebugLog : public CPulseCell_BaseFlow // pulse_runtime_lib
{
};
class CItem_Healthshot : public CWeaponBaseItem // server
{
};
class CBaseGrenade : public CBaseAnimGraph // server
{
	bool m_bDamageDetonating; // 0x0968
	CEntityIOOutput m_OnPlayerPickup; // 0x0970
	CEntityIOOutput m_OnExplode; // 0x0988
	bool m_bHasWarnedAI; // 0x09A0
	bool m_bIsSmokeGrenade; // 0x09A1
	bool m_bIsLive; // 0x09A2
	float32 m_DmgRadius; // 0x09A4
	GameTime_t m_flDetonateTime; // 0x09A8
	float32 m_flWarnAITime; // 0x09AC
	float32 m_flDamage; // 0x09B0
	CUtlSymbolLarge m_iszBounceSound; // 0x09B8
	CUtlString m_ExplosionSound; // 0x09C0
	CHandle< CCSPlayerPawn > m_hThrower; // 0x09C8
	GameTime_t m_flNextAttack; // 0x09E0
	CHandle< CCSPlayerPawn > m_hOriginalThrower; // 0x09E4
};
class CColorCorrectionVolume : public CBaseTrigger // server
{
	float32 m_MaxWeight; // 0x08E8
	float32 m_FadeDuration; // 0x08EC
	float32 m_Weight; // 0x08F0
	char[512] m_lookupFilename; // 0x08F4
	float32 m_LastEnterWeight; // 0x0AF4
	GameTime_t m_LastEnterTime; // 0x0AF8
	float32 m_LastExitWeight; // 0x0AFC
	GameTime_t m_LastExitTime; // 0x0B00
};
class CCSPlayerController_ActionTrackingServices : public CPlayerControllerComponent // server
{
	CUtlVectorEmbeddedNetworkVar< CSPerRoundStats_t > m_perRoundStats; // 0x0040
	CSMatchStats_t m_matchStats; // 0x00C8
	int32 m_iNumRoundKills; // 0x0188
	int32 m_iNumRoundKillsHeadshots; // 0x018C
	float32 m_flTotalRoundDamageDealt; // 0x0190
};
class CBodyComponentBaseAnimGraph : public CBodyComponentSkeletonInstance // server
{
	CBaseAnimGraphController m_animationController; // 0x04E0
};
class CPulseCell_BaseYieldingInflow : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CPulse_ResumePoint m_BaseFlow_OnAfterCancel; // 0x0048
	CPulse_ResumePoint m_BaseFlow_WhileActive; // 0x0090
};
class PulseNodeDynamicOutflows_t // pulse_runtime_lib
{
	CUtlVector< PulseNodeDynamicOutflows_t::DynamicOutflow_t > m_Outflows; // 0x0000
};
class CFogVolume : public CServerOnlyModelEntity // server
{
	CUtlSymbolLarge m_fogName; // 0x0770
	CUtlSymbolLarge m_postProcessName; // 0x0778
	CUtlSymbolLarge m_colorCorrectionName; // 0x0780
	bool m_bDisabled; // 0x0790
	bool m_bInFogVolumesList; // 0x0791
};
class CFuncRotating : public CBaseModelEntity // server
{
	CEntityIOOutput m_OnStopped; // 0x0770
	CEntityIOOutput m_OnStarted; // 0x0788
	CEntityIOOutput m_OnReachedStart; // 0x07A0
	RotationVector m_localRotationVector; // 0x07B8
	float32 m_flSpeed; // 0x07C4
	float32 m_flFanFriction; // 0x07C8
	float32 m_flAttenuation; // 0x07CC
	float32 m_flVolume; // 0x07D0
	float32 m_flTargetSpeed; // 0x07D4
	float32 m_flMaxSpeed; // 0x07D8
	float32 m_flBlockDamage; // 0x07DC
	CGameSoundEventName m_NoiseRunning; // 0x07E0
	bool m_bReversed; // 0x07E8
	bool m_bAccelDecel; // 0x07E9
	QAngle m_prevLocalAngles; // 0x0800
	QAngle m_angStart; // 0x080C
	bool m_bStopAtStartPos; // 0x0818
	Vector m_vecClientOrigin; // 0x081C
	QAngle m_vecClientAngles; // 0x0828
};
class CTimerEntity : public CLogicalEntity // server
{
	CEntityIOOutput m_OnTimer; // 0x04A8
	CEntityIOOutput m_OnTimerHigh; // 0x04C0
	CEntityIOOutput m_OnTimerLow; // 0x04D8
	int32 m_iDisabled; // 0x04F0
	float32 m_flInitialDelay; // 0x04F4
	float32 m_flRefireTime; // 0x04F8
	bool m_bUpDownState; // 0x04FC
	int32 m_iUseRandomTime; // 0x0500
	bool m_bPauseAfterFiring; // 0x0504
	float32 m_flLowerRandomBound; // 0x0508
	float32 m_flUpperRandomBound; // 0x050C
	float32 m_flRemainingTime; // 0x0510
	bool m_bPaused; // 0x0514
};
class CBtActionMoveTo : public CBtNode // server
{
	CUtlString m_szDestinationInputKey; // 0x0060
	CUtlString m_szHidingSpotInputKey; // 0x0068
	CUtlString m_szThreatInputKey; // 0x0070
	VectorWS m_vecDestination; // 0x0078
	bool m_bAutoLookAdjust; // 0x0084
	bool m_bComputePath; // 0x0085
	float32 m_flDamagingAreasPenaltyCost; // 0x0088
	CountdownTimer m_CheckApproximateCornersTimer; // 0x0090
	CountdownTimer m_CheckHighPriorityItem; // 0x00A8
	CountdownTimer m_RepathTimer; // 0x00C0
	float32 m_flArrivalEpsilon; // 0x00D8
	float32 m_flAdditionalArrivalEpsilon2D; // 0x00DC
	float32 m_flHidingSpotCheckDistanceThreshold; // 0x00E0
	float32 m_flNearestAreaDistanceThreshold; // 0x00E4
};
class CPlayer_MovementServices_Humanoid : public CPlayer_MovementServices // server
{
	float32 m_flStepSoundTime; // 0x0258
	float32 m_flFallVelocity; // 0x025C
	Vector m_groundNormal; // 0x0260
	float32 m_flSurfaceFriction; // 0x026C
	CUtlStringToken m_surfaceProps; // 0x0270
	int32 m_nStepside; // 0x0280
	Vector m_vecSmoothedVelocity; // 0x0284
};
class CBaseEntityAPI // server
{
};
class CPulseCell_IsRequirementValid::Criteria_t // pulse_runtime_lib
{
	bool m_bIsValid; // 0x0000
};
class CWeaponG3SG1 : public CCSWeaponBaseGun // server
{
};
class CTriggerOnce : public CTriggerMultiple // server
{
};
class CSMatchStats_t : public CSPerRoundStats_t // server
{
	int32 m_iEnemy5Ks; // 0x0068
	int32 m_iEnemy4Ks; // 0x006C
	int32 m_iEnemy3Ks; // 0x0070
	int32 m_iEnemyKnifeKills; // 0x0074
	int32 m_iEnemyTaserKills; // 0x0078
	int32 m_iEnemy2Ks; // 0x007C
	int32 m_iUtility_Count; // 0x0080
	int32 m_iUtility_Successes; // 0x0084
	int32 m_iUtility_Enemies; // 0x0088
	int32 m_iFlash_Count; // 0x008C
	int32 m_iFlash_Successes; // 0x0090
	float32 m_flHealthPointsRemovedTotal; // 0x0094
	float32 m_flHealthPointsDealtTotal; // 0x0098
	int32 m_nShotsFiredTotal; // 0x009C
	int32 m_nShotsOnTargetTotal; // 0x00A0
	int32 m_i1v1Count; // 0x00A4
	int32 m_i1v1Wins; // 0x00A8
	int32 m_i1v2Count; // 0x00AC
	int32 m_i1v2Wins; // 0x00B0
	int32 m_iEntryCount; // 0x00B4
	int32 m_iEntryWins; // 0x00B8
};
class EntityRenderAttribute_t // server
{
	CUtlStringToken m_ID; // 0x0030
	Vector4D m_Values; // 0x0034
};
class CPulseCell_Inflow_ObservableVariableListener : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseRuntimeBlackboardReferenceIndex_t m_nBlackboardReference; // 0x0080
	bool m_bSelfReference; // 0x0082
};
class CFuncMonitor : public CFuncBrush // server
{
	CUtlString m_targetCamera; // 0x0790
	int32 m_nResolutionEnum; // 0x0798
	bool m_bRenderShadows; // 0x079C
	bool m_bUseUniqueColorTarget; // 0x079D
	CUtlString m_brushModelName; // 0x07A0
	CHandle< CBaseEntity > m_hTargetCamera; // 0x07A8
	bool m_bEnabled; // 0x07AC
	bool m_bDraw3DSkybox; // 0x07AD
	bool m_bStartEnabled; // 0x07AE
};
class CInfoVisibilityBox : public CBaseEntity // server
{
	int32 m_nMode; // 0x04AC
	Vector m_vBoxSize; // 0x04B0
	bool m_bEnabled; // 0x04BC
};
class CGunTarget : public CBaseToggle // server
{
	float32 m_flSpeed; // 0x07F0
	bool m_on; // 0x07F4
	CHandle< CBaseEntity > m_hTargetEnt; // 0x07F8
	CEntityIOOutput m_OnDeath; // 0x0800
};
class CSoundEventConeEntity : public CSoundEventEntity // server
{
	float32 m_flEmitterAngle; // 0x0568
	float32 m_flSweetSpotAngle; // 0x056C
	float32 m_flAttenMin; // 0x0570
	float32 m_flAttenMax; // 0x0574
	CUtlSymbolLarge m_iszParameterName; // 0x0578
};
class CCSObserverPawn_API // server
{
};
class CSoundOpvarSetOBBEntity : public CSoundOpvarSetAABBEntity // server
{
};
class CFilterMultipleAPI // server
{
};
class CDecoyProjectile : public CBaseCSGrenadeProjectile // server
{
	int32 m_nDecoyShotTick; // 0x0A78
	int32 m_shotsRemaining; // 0x0A7C
	GameTime_t m_fExpireTime; // 0x0A80
	uint16 m_decoyWeaponDefIndex; // 0x0A90
};
class CPrecipitationBlocker : public CBaseModelEntity // server
{
};
class CSoundOpvarSetPathCornerEntity : public CSoundOpvarSetPointEntity // server
{
	bool m_bUseParentedPath; // 0x0658
	float32 m_flDistMinSqr; // 0x065C
	float32 m_flDistMaxSqr; // 0x0660
	CUtlSymbolLarge m_iszPathCornerEntityName; // 0x0668
};
class CPointClientCommand : public CPointEntity // server
{
};
class CHostageRescueZone : public CHostageRescueZoneShim // server
{
};
class CWorld : public CBaseModelEntity // server
{
};
class CPathMoverEntitySpawner : public CLogicalEntity // server
{
	CUtlSymbolLarge[4] m_szSpawnTemplates; // 0x04A8
	int32 m_nSpawnIndex; // 0x04C8
	CHandle< CPathMover > m_hPathMover; // 0x04CC
	float32 m_flSpawnFrequencySeconds; // 0x04D0
	float32 m_flSpawnFrequencyDistToNearestMover; // 0x04D4
	CUtlHashtable< CHandle< CFuncMover >, PathMoverEntitySpawn > m_mapSpawnedMoverTemplates; // 0x04D8
	int32 m_nMaxActive; // 0x04F8
	int32 m_nSpawnNum; // 0x04FC
	GameTime_t m_flLastSpawnTime; // 0x0500
	bool m_bEnabled; // 0x0504
	bool m_bDestroyMoverOnArrivedAtEnd; // 0x0505
	CUtlVector< CHandle< CFuncMover > > m_vecQueuedRemovals; // 0x0508
	CEntityIOOutput m_OnTemplateSpawned; // 0x0520
	CEntityIOOutput m_OnTemplateGroupSpawned; // 0x0538
	CUtlSymbolLarge m_iszPathMoverName; // 0x0550
	bool m_bPrepopulateOnSpawn; // 0x0558
};
class CModelState // server
{
	CStrongHandle< InfoForResourceTypeCModel > m_hModel; // 0x00A0
	CUtlSymbolLarge m_ModelName; // 0x00A8
	IPhysAggregateInstance* m_pVPhysicsAggregate; // 0x00E0
	float32 m_flRootBoneOffset_x; // 0x00E8
	float32 m_flRootBoneOffset_y; // 0x00EC
	float32 m_flRootBoneOffset_z; // 0x00F0
	uint8 m_nRootBoneOffsetResetSerialNumber; // 0x00F4
	bool m_bClientClothCreationSuppressed; // 0x00F5
	uint8 m_nAnimStateNoInterpSerialNumber; // 0x01E0
	uint64 m_MeshGroupMask; // 0x01E8
	CNetworkUtlVectorBase< int32 > m_nBodyGroupChoices; // 0x0238
	int8 m_nIdealMotionType; // 0x0282
	int8 m_nForceLOD; // 0x0283
	int8 m_nClothUpdateFlags; // 0x0284
};
class CPulseCell_LerpCameraSettings::CursorState_t : public CPulseCell_BaseLerp::CursorState_t // server
{
	CHandle< CPointCamera > m_hCamera; // 0x0008
	PointCameraSettings_t m_OverlaidStart; // 0x000C
	PointCameraSettings_t m_OverlaidEnd; // 0x001C
};
class CPulseCell_Outflow_CycleOrdered : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outputs; // 0x0048
};
class CWeaponGlock : public CCSWeaponBaseGun // server
{
};
class CHEGrenadeProjectile : public CBaseCSGrenadeProjectile // server
{
};
class CTriggerGravity : public CBaseTrigger // server
{
};
class CCollisionProperty // server
{
	VPhysicsCollisionAttribute_t m_collisionAttribute; // 0x0010
	Vector m_vecMins; // 0x0040
	Vector m_vecMaxs; // 0x004C
	uint8 m_usSolidFlags; // 0x005A
	SolidType_t m_nSolidType; // 0x005B
	uint8 m_triggerBloat; // 0x005C
	SurroundingBoundsType_t m_nSurroundType; // 0x005D
	uint8 m_CollisionGroup; // 0x005E
	uint8 m_nEnablePhysics; // 0x005F
	float32 m_flBoundingRadius; // 0x0060
	Vector m_vecSpecifiedSurroundingMins; // 0x0064
	Vector m_vecSpecifiedSurroundingMaxs; // 0x0070
	Vector m_vecSurroundingMaxs; // 0x007C
	Vector m_vecSurroundingMins; // 0x0088
	Vector m_vCapsuleCenter1; // 0x0094
	Vector m_vCapsuleCenter2; // 0x00A0
	float32 m_flCapsuleRadius; // 0x00AC
};
class CWeaponGalilAR : public CCSWeaponBaseGun // server
{
};
class CFilterMassGreater : public CBaseFilter // server
{
	float32 m_fFilterMass; // 0x04E0
};
class CWeaponMP7 : public CCSWeaponBaseGun // server
{
};
class CCSWeaponBaseGun : public CCSWeaponBase // server
{
	int32 m_zoomLevel; // 0x1050
	int32 m_iBurstShotsRemaining; // 0x1054
	int32 m_silencedModelIndex; // 0x1060
	bool m_inPrecache; // 0x1064
	bool m_bNeedsBoltAction; // 0x1065
	int32 m_nRevolverCylinderIdx; // 0x1068
	bool m_bSkillReloadAvailable; // 0x106C
	bool m_bSkillReloadLiftedReloadKey; // 0x106D
	bool m_bSkillBoltInterruptAvailable; // 0x106E
	bool m_bSkillBoltLiftedFireKey; // 0x106F
};
class CEnableMotionFixup : public CBaseEntity // server
{
};
class CLogicActiveAutosave : public CLogicAutosave // server
{
	int32 m_TriggerHitPoints; // 0x04B8
	float32 m_flTimeToTrigger; // 0x04BC
	GameTime_t m_flStartTime; // 0x04C0
	float32 m_flDangerousTime; // 0x04C4
};
class CMathCounter : public CLogicalEntity // server
{
	float32 m_flMin; // 0x04A8
	float32 m_flMax; // 0x04AC
	bool m_bHitMin; // 0x04B0
	bool m_bHitMax; // 0x04B1
	bool m_bDisabled; // 0x04B2
	CEntityOutputTemplate< float32 > m_OutValue; // 0x04B8
	CEntityOutputTemplate< float32 > m_OnGetValue; // 0x04D8
	CEntityIOOutput m_OnHitMin; // 0x04F8
	CEntityIOOutput m_OnHitMax; // 0x0510
	CEntityIOOutput m_OnChangedFromMin; // 0x0528
	CEntityIOOutput m_OnChangedFromMax; // 0x0540
};
class CCSGameModeRules_ArmsRace : public CCSGameModeRules // server
{
	CNetworkUtlVectorBase< CUtlString > m_WeaponSequence; // 0x0030
};
class CAttributeContainer : public CAttributeManager // server
{
	CEconItemView m_Item; // 0x0050
};
class CCSPlace : public CServerOnlyModelEntity // server
{
	CUtlSymbolLarge m_name; // 0x0788
};
class PulseSelectorOutflowList_t // pulse_runtime_lib
{
	CUtlVector< OutflowWithRequirements_t > m_Outflows; // 0x0000
};
class CFilterContext : public CBaseFilter // server
{
	CUtlSymbolLarge m_iFilterContext; // 0x04E0
};
class CLightEnvironmentEntity : public CLightDirectionalEntity // server
{
};
class CEnvDecal : public CBaseModelEntity // server
{
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hDecalMaterial; // 0x0770
	float32 m_flWidth; // 0x0778
	float32 m_flHeight; // 0x077C
	float32 m_flDepth; // 0x0780
	uint32 m_nRenderOrder; // 0x0784
	bool m_bProjectOnWorld; // 0x0788
	bool m_bProjectOnCharacters; // 0x0789
	bool m_bProjectOnWater; // 0x078A
	float32 m_flDepthSortBias; // 0x078C
};
class CEnvVolumetricFogVolume : public CBaseEntity // server
{
	bool m_bActive; // 0x04A8
	Vector m_vBoxMins; // 0x04AC
	Vector m_vBoxMaxs; // 0x04B8
	bool m_bStartDisabled; // 0x04C4
	bool m_bIndirectUseLPVs; // 0x04C5
	float32 m_flStrength; // 0x04C8
	int32 m_nFalloffShape; // 0x04CC
	float32 m_flFalloffExponent; // 0x04D0
	float32 m_flHeightFogDepth; // 0x04D4
	float32 m_fHeightFogEdgeWidth; // 0x04D8
	float32 m_fIndirectLightStrength; // 0x04DC
	float32 m_fSunLightStrength; // 0x04E0
	float32 m_fNoiseStrength; // 0x04E4
	Color m_TintColor; // 0x04E8
	bool m_bOverrideTintColor; // 0x04EC
	bool m_bOverrideIndirectLightStrength; // 0x04ED
	bool m_bOverrideSunLightStrength; // 0x04EE
	bool m_bOverrideNoiseStrength; // 0x04EF
};
class CServerOnlyEntity : public CBaseEntity // server
{
};
class CPulseCell_PlaySequence::CursorState_t // server
{
	CHandle< CBaseAnimGraph > m_hTarget; // 0x0000
};
class CBodyComponentSkeletonInstance : public CBodyComponent // server
{
	CSkeletonInstance m_skeletonInstance; // 0x0080
};
class CItemGeneric : public CItem // server
{
	bool m_bHasTriggerRadius; // 0x0A14
	bool m_bHasPickupRadius; // 0x0A15
	float32 m_flPickupRadiusSqr; // 0x0A18
	float32 m_flTriggerRadiusSqr; // 0x0A1C
	GameTime_t m_flLastPickupCheck; // 0x0A20
	bool m_bPlayerCounterListenerAdded; // 0x0A24
	bool m_bPlayerInTriggerRadius; // 0x0A25
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_hSpawnParticleEffect; // 0x0A28
	CUtlSymbolLarge m_pAmbientSoundEffect; // 0x0A30
	bool m_bAutoStartAmbientSound; // 0x0A38
	CUtlSymbolLarge m_pSpawnScriptFunction; // 0x0A40
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_hPickupParticleEffect; // 0x0A48
	CUtlSymbolLarge m_pPickupSoundEffect; // 0x0A50
	CUtlSymbolLarge m_pPickupScriptFunction; // 0x0A58
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_hTimeoutParticleEffect; // 0x0A60
	CUtlSymbolLarge m_pTimeoutSoundEffect; // 0x0A68
	CUtlSymbolLarge m_pTimeoutScriptFunction; // 0x0A70
	CUtlSymbolLarge m_pPickupFilterName; // 0x0A78
	CHandle< CBaseFilter > m_hPickupFilter; // 0x0A80
	CEntityIOOutput m_OnPickup; // 0x0A88
	CEntityIOOutput m_OnTimeout; // 0x0AA0
	CEntityIOOutput m_OnTriggerStartTouch; // 0x0AB8
	CEntityIOOutput m_OnTriggerTouch; // 0x0AD0
	CEntityIOOutput m_OnTriggerEndTouch; // 0x0AE8
	CUtlSymbolLarge m_pAllowPickupScriptFunction; // 0x0B00
	float32 m_flPickupRadius; // 0x0B08
	float32 m_flTriggerRadius; // 0x0B0C
	CUtlSymbolLarge m_pTriggerSoundEffect; // 0x0B10
	bool m_bGlowWhenInTrigger; // 0x0B18
	Color m_glowColor; // 0x0B19
	bool m_bUseable; // 0x0B1D
	CHandle< CItemGenericTriggerHelper > m_hTriggerHelper; // 0x0B20
};
class CPointValueRemapper : public CBaseEntity // server
{
	bool m_bDisabled; // 0x04A8
	bool m_bUpdateOnClient; // 0x04A9
	ValueRemapperInputType_t m_nInputType; // 0x04AC
	CUtlSymbolLarge m_iszRemapLineStartName; // 0x04B0
	CUtlSymbolLarge m_iszRemapLineEndName; // 0x04B8
	CHandle< CBaseEntity > m_hRemapLineStart; // 0x04C0
	CHandle< CBaseEntity > m_hRemapLineEnd; // 0x04C4
	float32 m_flMaximumChangePerSecond; // 0x04C8
	float32 m_flDisengageDistance; // 0x04CC
	float32 m_flEngageDistance; // 0x04D0
	bool m_bRequiresUseKey; // 0x04D4
	ValueRemapperOutputType_t m_nOutputType; // 0x04D8
	CUtlSymbolLarge m_iszOutputEntityName; // 0x04E0
	CUtlSymbolLarge m_iszOutputEntity2Name; // 0x04E8
	CUtlSymbolLarge m_iszOutputEntity3Name; // 0x04F0
	CUtlSymbolLarge m_iszOutputEntity4Name; // 0x04F8
	CNetworkUtlVectorBase< CHandle< CBaseEntity > > m_hOutputEntities; // 0x0500
	ValueRemapperHapticsType_t m_nHapticsType; // 0x0518
	ValueRemapperMomentumType_t m_nMomentumType; // 0x051C
	float32 m_flMomentumModifier; // 0x0520
	float32 m_flSnapValue; // 0x0524
	float32 m_flCurrentMomentum; // 0x0528
	ValueRemapperRatchetType_t m_nRatchetType; // 0x052C
	float32 m_flRatchetOffset; // 0x0530
	float32 m_flInputOffset; // 0x0534
	bool m_bEngaged; // 0x0538
	bool m_bFirstUpdate; // 0x0539
	float32 m_flPreviousValue; // 0x053C
	GameTime_t m_flPreviousUpdateTickTime; // 0x0540
	VectorWS m_vecPreviousTestPoint; // 0x0544
	CHandle< CBasePlayerPawn > m_hUsingPlayer; // 0x0550
	float32 m_flCustomOutputValue; // 0x0554
	CUtlSymbolLarge m_iszSoundEngage; // 0x0558
	CUtlSymbolLarge m_iszSoundDisengage; // 0x0560
	CUtlSymbolLarge m_iszSoundReachedValueZero; // 0x0568
	CUtlSymbolLarge m_iszSoundReachedValueOne; // 0x0570
	CUtlSymbolLarge m_iszSoundMovingLoop; // 0x0578
	CEntityOutputTemplate< float32 > m_Position; // 0x0598
	CEntityOutputTemplate< float32 > m_PositionDelta; // 0x05B8
	CEntityIOOutput m_OnReachedValueZero; // 0x05D8
	CEntityIOOutput m_OnReachedValueOne; // 0x05F0
	CEntityIOOutput m_OnReachedValueCustom; // 0x0608
	CEntityIOOutput m_OnEngage; // 0x0620
	CEntityIOOutput m_OnDisengage; // 0x0638
};
class CBtNodeConditionInactive : public CBtNodeCondition // server
{
	float32 m_flRoundStartThresholdSeconds; // 0x0078
	float32 m_flSensorInactivityThresholdSeconds; // 0x007C
	CountdownTimer m_SensorInactivityTimer; // 0x0080
};
class CCSGO_TeamIntroCounterTerroristPosition : public CCSGO_TeamIntroCharacterPosition // server
{
};
class CRagdollProp : public CBaseAnimGraph // server
{
	CPropDataComponent m_CPropDataComponent; // 0x0970
	ragdoll_t m_ragdoll; // 0x09B0
	bool m_bStartDisabled; // 0x0A00
	float32 m_massScale; // 0x0A04
	float32 m_buoyancyScale; // 0x0A08
	CNetworkUtlVectorBase< bool > m_ragEnabled; // 0x0A10
	CNetworkUtlVectorBase< Vector > m_ragPos; // 0x0A28
	CNetworkUtlVectorBase< QAngle > m_ragAngles; // 0x0A40
	uint32 m_lastUpdateTickCount; // 0x0A58
	bool m_allAsleep; // 0x0A5C
	bool m_bFirstCollisionAfterLaunch; // 0x0A5D
	INavObstacle::NavObstacleType_t m_nNavObstacleType; // 0x0A60
	bool m_bUpdateNavWhenMoving; // 0x0A64
	bool m_bForceNavObstacleCut; // 0x0A65
	bool m_bAttachedToReferenceFrame; // 0x0A66
	CHandle< CBaseEntity > m_hDamageEntity; // 0x0A68
	CHandle< CBaseEntity > m_hKiller; // 0x0A6C
	CHandle< CBasePlayerPawn > m_hPhysicsAttacker; // 0x0A70
	GameTime_t m_flLastPhysicsInfluenceTime; // 0x0A74
	GameTime_t m_flFadeOutStartTime; // 0x0A78
	float32 m_flFadeTime; // 0x0A7C
	VectorWS m_vecLastOrigin; // 0x0A80
	GameTime_t m_flAwakeTime; // 0x0A8C
	GameTime_t m_flLastOriginChangeTime; // 0x0A90
	CUtlSymbolLarge m_strOriginClassName; // 0x0A98
	CUtlSymbolLarge m_strSourceClassName; // 0x0AA0
	bool m_bHasBeenPhysgunned; // 0x0AA8
	bool m_bAllowStretch; // 0x0AA9
	float32 m_flBlendWeight; // 0x0AAC
	float32 m_flDefaultFadeScale; // 0x0AB0
	CUtlVector< Vector > m_ragdollMins; // 0x0AB8
	CUtlVector< Vector > m_ragdollMaxs; // 0x0AD0
	bool m_bShouldDeleteActivationRecord; // 0x0AE8
	CUtlVector< INavObstacle* > m_vecNavObstacles; // 0x0B00
};
class CScriptComponent : public CEntityComponent // entity2
{
	CUtlSymbolLarge m_scriptClassName; // 0x0030
};
class CFuncTrain : public CBasePlatTrain // server
{
	CHandle< CBaseEntity > m_hCurrentTarget; // 0x0818
	bool m_activated; // 0x081C
	CHandle< CBaseEntity > m_hEnemy; // 0x0820
	float32 m_flBlockDamage; // 0x0824
	GameTime_t m_flNextBlockTime; // 0x0828
	CUtlSymbolLarge m_iszLastTarget; // 0x0830
	float32 m_flSpeed; // 0x0838
};
class CAI_ChangeHintGroup : public CBaseEntity // server
{
	int32 m_iSearchType; // 0x04A8
	CUtlSymbolLarge m_strSearchName; // 0x04B0
	CUtlSymbolLarge m_strNewHintGroup; // 0x04B8
	float32 m_flRadius; // 0x04C0
};
class CCSPlayer_BuyServices : public CPlayerPawnComponent // server
{
	CUtlVectorEmbeddedNetworkVar< SellbackPurchaseEntry_t > m_vecSellbackPurchaseEntries; // 0x00D0
};
class CWeaponAug : public CCSWeaponBaseGun // server
{
};
class CPhysHinge : public CPhysConstraint // server
{
	ConstraintSoundInfo m_soundInfo; // 0x0510
	CEntityIOOutput m_NotifyMinLimitReached; // 0x05A8
	CEntityIOOutput m_NotifyMaxLimitReached; // 0x05C0
	bool m_bAtMinLimit; // 0x05D8
	bool m_bAtMaxLimit; // 0x05D9
	constraint_hingeparams_t m_hinge; // 0x05DC
	float32 m_hingeFriction; // 0x061C
	float32 m_systemLoadScale; // 0x0620
	bool m_bIsAxisLocal; // 0x0624
	float32 m_flMinRotation; // 0x0628
	float32 m_flMaxRotation; // 0x062C
	float32 m_flInitialRotation; // 0x0630
	float32 m_flMotorFrequency; // 0x0634
	float32 m_flMotorDampingRatio; // 0x0638
	float32 m_flAngleSpeed; // 0x063C
	float32 m_flAngleSpeedThreshold; // 0x0640
	float32 m_flLimitsDebugVisRotation; // 0x0644
	CEntityIOOutput m_OnStartMoving; // 0x0648
	CEntityIOOutput m_OnStopMoving; // 0x0660
};
class CBuyZone : public CBaseTrigger // server
{
	int32 m_LegacyTeamNum; // 0x08E8
};
class CInfoChoreoAnchor : public CPointEntity // server
{
	CUtlVector< CInfoChoreoAnchorPosition > m_vecTargetEntries; // 0x04A8
	CUtlVector< CInfoChoreoAnchorPosition > m_vecTargetWarps; // 0x04C0
};
class DestructiblePartDamageRequestAPI // server
{
};
class CWeaponSSG08 : public CCSWeaponBaseGun // server
{
};
class CLogicRelayAPI // server
{
};
class CInfoWorldLayer : public CBaseEntity // server
{
	CEntityIOOutput m_pOutputOnEntitiesSpawned; // 0x04A8
	CUtlSymbolLarge m_worldName; // 0x04C0
	CUtlSymbolLarge m_layerName; // 0x04C8
	bool m_bWorldLayerVisible; // 0x04D0
	bool m_bEntitiesSpawned; // 0x04D1
	bool m_bCreateAsChildSpawnGroup; // 0x04D2
	uint32 m_hLayerSpawnGroup; // 0x04D4
};
class CBodyComponentBaseModelEntity : public CBodyComponentSkeletonInstance // server
{
};
class CLogicProximity : public CPointEntity // server
{
};
class CPointGiveAmmo : public CPointEntity // server
{
	CHandle< CBaseEntity > m_pActivator; // 0x04A8
};
class CCSGO_EndOfMatchLineupStart : public CCSGO_EndOfMatchLineupEndpoint // server
{
};
class FilterDamageType : public CBaseFilter // server
{
	int32 m_iDamageType; // 0x04E0
};
class CPointCamera : public CBaseEntity // server
{
	float32 m_FOV; // 0x04A8
	float32 m_Resolution; // 0x04AC
	bool m_bFogEnable; // 0x04B0
	Color m_FogColor; // 0x04B1
	float32 m_flFogStart; // 0x04B8
	float32 m_flFogEnd; // 0x04BC
	float32 m_flFogMaxDensity; // 0x04C0
	bool m_bActive; // 0x04C4
	bool m_bUseScreenAspectRatio; // 0x04C5
	float32 m_flAspectRatio; // 0x04C8
	bool m_bNoSky; // 0x04CC
	float32 m_fBrightness; // 0x04D0
	float32 m_flZFar; // 0x04D4
	float32 m_flZNear; // 0x04D8
	bool m_bCanHLTVUse; // 0x04DC
	bool m_bAlignWithParent; // 0x04DD
	bool m_bDofEnabled; // 0x04DE
	float32 m_flDofNearBlurry; // 0x04E0
	float32 m_flDofNearCrisp; // 0x04E4
	float32 m_flDofFarCrisp; // 0x04E8
	float32 m_flDofFarBlurry; // 0x04EC
	float32 m_flDofTiltToGround; // 0x04F0
	float32 m_TargetFOV; // 0x04F4
	float32 m_DegreesPerSecond; // 0x04F8
	bool m_bIsOn; // 0x04FC
	CPointCamera* m_pNext; // 0x0500
};
class CBuyZone_API // server
{
};
class CAttributeList // server
{
	CUtlVectorEmbeddedNetworkVar< CEconItemAttribute > m_Attributes; // 0x0008
	CAttributeManager* m_pManager; // 0x0070
};
class CPulseCell_Inflow_Wait : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_WakeResume; // 0x00D8
};
class CFilterProximity : public CBaseFilter // server
{
	float32 m_flRadius; // 0x04E0
};
class CCS2WeaponGraphController : public CAnimGraphControllerBase // server
{
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_action; // 0x0088
	CAnimGraph2ParamOptionalRef< bool > m_bActionReset; // 0x00A0
	CAnimGraph2ParamOptionalRef< float32 > m_flWeaponActionSpeedScale; // 0x00B8
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_weaponCategory; // 0x00D0
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_weaponType; // 0x00E8
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_weaponExtraInfo; // 0x0100
	CAnimGraph2ParamOptionalRef< float32 > m_flWeaponAmmo; // 0x0118
	CAnimGraph2ParamOptionalRef< float32 > m_flWeaponAmmoMax; // 0x0130
	CAnimGraph2ParamOptionalRef< float32 > m_flWeaponAmmoReserve; // 0x0148
	CAnimGraph2ParamOptionalRef< bool > m_bWeaponIsSilenced; // 0x0160
	CAnimGraph2ParamOptionalRef< float32 > m_flWeaponIronsightAmount; // 0x0178
	CAnimGraph2ParamOptionalRef< bool > m_bIsUsingLegacyModel; // 0x0190
	CAnimGraph2ParamOptionalRef< float32 > m_idleVariation; // 0x01A8
	CAnimGraph2ParamOptionalRef< float32 > m_deployVariation; // 0x01C0
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_attackType; // 0x01D8
	CAnimGraph2ParamOptionalRef< float32 > m_attackThrowStrength; // 0x01F0
	CAnimGraph2ParamOptionalRef< float32 > m_flAttackVariation; // 0x0208
	CAnimGraph2ParamOptionalRef< float32 > m_inspectVariation; // 0x0220
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_inspectExtraInfo; // 0x0238
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_reloadStage; // 0x0250
};
class CEffectData // server
{
	VectorWS m_vOrigin; // 0x0008
	VectorWS m_vStart; // 0x0014
	Vector m_vNormal; // 0x0020
	QAngle m_vAngles; // 0x002C
	CEntityHandle m_hEntity; // 0x0038
	CEntityHandle m_hOtherEntity; // 0x003C
	float32 m_flScale; // 0x0040
	float32 m_flMagnitude; // 0x0044
	float32 m_flRadius; // 0x0048
	CUtlStringToken m_nSurfaceProp; // 0x004C
	CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > m_nEffectIndex; // 0x0050
	uint32 m_nDamageType; // 0x0058
	uint8 m_nPenetrate; // 0x005C
	uint16 m_nMaterial; // 0x005E
	int16 m_nHitBox; // 0x0060
	uint8 m_nColor; // 0x0062
	uint8 m_fFlags; // 0x0063
	AttachmentHandle_t m_nAttachmentIndex; // 0x0064
	CUtlStringToken m_nAttachmentName; // 0x0068
	uint16 m_iEffectName; // 0x006C
};
class CEntityDissolve : public CBaseModelEntity // server
{
	float32 m_flFadeInStart; // 0x0770
	float32 m_flFadeInLength; // 0x0774
	float32 m_flFadeOutModelStart; // 0x0778
	float32 m_flFadeOutModelLength; // 0x077C
	float32 m_flFadeOutStart; // 0x0780
	float32 m_flFadeOutLength; // 0x0784
	GameTime_t m_flStartTime; // 0x0788
	EntityDissolveType_t m_nDissolveType; // 0x078C
	VectorWS m_vDissolverOrigin; // 0x0790
	uint32 m_nMagnitude; // 0x079C
};
class CCSGameRules : public CTeamplayRules // server
{
	bool m_bFreezePeriod; // 0x00D8
	bool m_bWarmupPeriod; // 0x00D9
	GameTime_t m_fWarmupPeriodEnd; // 0x00DC
	GameTime_t m_fWarmupPeriodStart; // 0x00E0
	bool m_bTerroristTimeOutActive; // 0x00E4
	bool m_bCTTimeOutActive; // 0x00E5
	float32 m_flTerroristTimeOutRemaining; // 0x00E8
	float32 m_flCTTimeOutRemaining; // 0x00EC
	int32 m_nTerroristTimeOuts; // 0x00F0
	int32 m_nCTTimeOuts; // 0x00F4
	bool m_bTechnicalTimeOut; // 0x00F8
	bool m_bMatchWaitingForResume; // 0x00F9
	int32 m_iFreezeTime; // 0x00FC
	int32 m_iRoundTime; // 0x0100
	float32 m_fMatchStartTime; // 0x0104
	GameTime_t m_fRoundStartTime; // 0x0108
	GameTime_t m_flRestartRoundTime; // 0x010C
	bool m_bGameRestart; // 0x0110
	float32 m_flGameStartTime; // 0x0114
	float32 m_timeUntilNextPhaseStarts; // 0x0118
	int32 m_gamePhase; // 0x011C
	int32 m_totalRoundsPlayed; // 0x0120
	int32 m_nRoundsPlayedThisPhase; // 0x0124
	int32 m_nOvertimePlaying; // 0x0128
	int32 m_iHostagesRemaining; // 0x012C
	bool m_bAnyHostageReached; // 0x0130
	bool m_bMapHasBombTarget; // 0x0131
	bool m_bMapHasRescueZone; // 0x0132
	bool m_bMapHasBuyZone; // 0x0133
	bool m_bIsQueuedMatchmaking; // 0x0134
	int32 m_nQueuedMatchmakingMode; // 0x0138
	bool m_bIsValveDS; // 0x013C
	bool m_bLogoMap; // 0x013D
	bool m_bPlayAllStepSoundsOnServer; // 0x013E
	int32 m_iSpectatorSlotCount; // 0x0140
	int32 m_MatchDevice; // 0x0144
	bool m_bHasMatchStarted; // 0x0148
	int32 m_nNextMapInMapgroup; // 0x014C
	char[512] m_szTournamentEventName; // 0x0150
	char[512] m_szTournamentEventStage; // 0x0350
	char[512] m_szMatchStatTxt; // 0x0550
	char[512] m_szTournamentPredictionsTxt; // 0x0750
	int32 m_nTournamentPredictionsPct; // 0x0950
	GameTime_t m_flCMMItemDropRevealStartTime; // 0x0954
	GameTime_t m_flCMMItemDropRevealEndTime; // 0x0958
	bool m_bIsDroppingItems; // 0x095C
	bool m_bIsQuestEligible; // 0x095D
	bool m_bIsHltvActive; // 0x095E
	bool m_bBombPlanted; // 0x095F
	uint16[100] m_arrProhibitedItemIndices; // 0x0960
	uint32[4] m_arrTournamentActiveCasterAccounts; // 0x0A28
	int32 m_numBestOfMaps; // 0x0A38
	int32 m_nHalloweenMaskListSeed; // 0x0A3C
	bool m_bBombDropped; // 0x0A40
	int32 m_iRoundWinStatus; // 0x0A44
	int32 m_eRoundWinReason; // 0x0A48
	bool m_bTCantBuy; // 0x0A4C
	bool m_bCTCantBuy; // 0x0A4D
	int32[30] m_iMatchStats_RoundResults; // 0x0A50
	int32[30] m_iMatchStats_PlayersAlive_CT; // 0x0AC8
	int32[30] m_iMatchStats_PlayersAlive_T; // 0x0B40
	float32[32] m_TeamRespawnWaveTimes; // 0x0BB8
	GameTime_t[32] m_flNextRespawnWave; // 0x0C38
	VectorWS m_vMinimapMins; // 0x0CB8
	VectorWS m_vMinimapMaxs; // 0x0CC4
	float32[8] m_MinimapVerticalSectionHeights; // 0x0CD0
	uint64 m_ullLocalMatchID; // 0x0CF0
	int32[10] m_nEndMatchMapGroupVoteTypes; // 0x0CF8
	int32[10] m_nEndMatchMapGroupVoteOptions; // 0x0D20
	int32 m_nEndMatchMapVoteWinner; // 0x0D48
	int32 m_iNumConsecutiveCTLoses; // 0x0D4C
	int32 m_iNumConsecutiveTerroristLoses; // 0x0D50
	bool m_bHasHostageBeenTouched; // 0x0D70
	GameTime_t m_flIntermissionStartTime; // 0x0D74
	GameTime_t m_flIntermissionEndTime; // 0x0D78
	bool m_bLevelInitialized; // 0x0D7C
	int32 m_iTotalRoundsPlayed; // 0x0D80
	int32 m_iUnBalancedRounds; // 0x0D84
	bool m_endMatchOnRoundReset; // 0x0D88
	bool m_endMatchOnThink; // 0x0D89
	int32 m_iNumTerrorist; // 0x0D8C
	int32 m_iNumCT; // 0x0D90
	int32 m_iNumSpawnableTerrorist; // 0x0D94
	int32 m_iNumSpawnableCT; // 0x0D98
	CUtlVector< int32 > m_arrSelectedHostageSpawnIndices; // 0x0DA0
	int32 m_nSpawnPointsRandomSeed; // 0x0DB8
	bool m_bFirstConnected; // 0x0DBC
	bool m_bCompleteReset; // 0x0DBD
	bool m_bPickNewTeamsOnReset; // 0x0DBE
	bool m_bScrambleTeamsOnRestart; // 0x0DBF
	bool m_bSwapTeamsOnRestart; // 0x0DC0
	CUtlVector< int32 > m_nEndMatchTiedVotes; // 0x0DC8
	bool m_bNeedToAskPlayersForContinueVote; // 0x0DE4
	uint32 m_numQueuedMatchmakingAccounts; // 0x0DE8
	float32 m_fAvgPlayerRank; // 0x0DEC
	char* m_pQueuedMatchmakingReservationString; // 0x0DF0
	uint32 m_numTotalTournamentDrops; // 0x0DF8
	uint32 m_numSpectatorsCountMax; // 0x0DFC
	uint32 m_numSpectatorsCountMaxTV; // 0x0E00
	uint32 m_numSpectatorsCountMaxLnk; // 0x0E04
	int32 m_nCTsAliveAtFreezetimeEnd; // 0x0E10
	int32 m_nTerroristsAliveAtFreezetimeEnd; // 0x0E14
	bool m_bForceTeamChangeSilent; // 0x0E18
	bool m_bLoadingRoundBackupData; // 0x0E19
	int32 m_nMatchInfoShowType; // 0x0E50
	float32 m_flMatchInfoDecidedTime; // 0x0E54
	int32 mTeamDMLastWinningTeamNumber; // 0x0E70
	float32 mTeamDMLastThinkTime; // 0x0E74
	float32 m_flTeamDMLastAnnouncementTime; // 0x0E78
	int32 m_iAccountTerrorist; // 0x0E7C
	int32 m_iAccountCT; // 0x0E80
	int32 m_iSpawnPointCount_Terrorist; // 0x0E84
	int32 m_iSpawnPointCount_CT; // 0x0E88
	int32 m_iMaxNumTerrorists; // 0x0E8C
	int32 m_iMaxNumCTs; // 0x0E90
	int32 m_iLoserBonusMostRecentTeam; // 0x0E94
	float32 m_tmNextPeriodicThink; // 0x0E98
	bool m_bVoiceWonMatchBragFired; // 0x0E9C
	float32 m_fWarmupNextChatNoticeTime; // 0x0EA0
	int32 m_iHostagesRescued; // 0x0EA8
	int32 m_iHostagesTouched; // 0x0EAC
	float32 m_flNextHostageAnnouncement; // 0x0EB0
	bool m_bNoTerroristsKilled; // 0x0EB4
	bool m_bNoCTsKilled; // 0x0EB5
	bool m_bNoEnemiesKilled; // 0x0EB6
	bool m_bCanDonateWeapons; // 0x0EB7
	float32 m_firstKillTime; // 0x0EBC
	float32 m_firstBloodTime; // 0x0EC4
	bool m_hostageWasInjured; // 0x0EE0
	bool m_hostageWasKilled; // 0x0EE1
	bool m_bVoteCalled; // 0x0EF0
	bool m_bServerVoteOnReset; // 0x0EF1
	float32 m_flVoteCheckThrottle; // 0x0EF4
	bool m_bBuyTimeEnded; // 0x0EF8
	int32 m_nLastFreezeEndBeep; // 0x0EFC
	bool m_bTargetBombed; // 0x0F00
	bool m_bBombDefused; // 0x0F01
	bool m_bMapHasBombZone; // 0x0F02
	VectorWS m_vecMainCTSpawnPos; // 0x0F50
	CUtlVector< CHandle< SpawnPoint > > m_CTSpawnPointsMasterList; // 0x0F60
	CUtlVector< CHandle< SpawnPoint > > m_TerroristSpawnPointsMasterList; // 0x0F78
	bool m_bRespawningAllRespawnablePlayers; // 0x0F90
	int32 m_iNextCTSpawnPoint; // 0x0F94
	float32 m_flCTSpawnPointUsedTime; // 0x0F98
	int32 m_iNextTerroristSpawnPoint; // 0x0F9C
	float32 m_flTerroristSpawnPointUsedTime; // 0x0FA0
	CUtlVector< CHandle< SpawnPoint > > m_CTSpawnPoints; // 0x0FA8
	CUtlVector< CHandle< SpawnPoint > > m_TerroristSpawnPoints; // 0x0FC0
	bool m_bIsUnreservedGameServer; // 0x0FD8
	float32 m_fAutobalanceDisplayTime; // 0x0FDC
	bool m_bAllowWeaponSwitch; // 0x1018
	bool m_bRoundTimeWarningTriggered; // 0x1019
	GameTime_t m_phaseChangeAnnouncementTime; // 0x101C
	float32 m_fNextUpdateTeamClanNamesTime; // 0x1020
	GameTime_t m_flLastThinkTime; // 0x1024
	float32 m_fAccumulatedRoundOffDamage; // 0x1028
	int32 m_nShorthandedBonusLastEvalRound; // 0x102C
	int32 m_nMatchAbortedEarlyReason; // 0x1078
	bool m_bHasTriggeredRoundStartMusic; // 0x107C
	bool m_bSwitchingTeamsAtRoundReset; // 0x107D
	CCSGameModeRules* m_pGameModeRules; // 0x1098
	KeyValues3 m_BtGlobalBlackboard; // 0x10A0
	CHandle< CBaseEntity > m_hPlayerResource; // 0x1138
	CRetakeGameRules m_RetakeRules; // 0x1140
	CUtlVector< int32 >[4] m_arrTeamUniqueKillWeaponsMatch; // 0x1330
	bool[4] m_bTeamLastKillUsedUniqueWeaponMatch; // 0x1390
	uint8 m_nMatchEndCount; // 0x13B8
	int32 m_nTTeamIntroVariant; // 0x13BC
	int32 m_nCTTeamIntroVariant; // 0x13C0
	bool m_bTeamIntroPeriod; // 0x13C4
	GameTime_t m_fTeamIntroPeriodEnd; // 0x13C8
	bool m_bPlayedTeamIntroVO; // 0x13CC
	int32 m_iRoundEndWinnerTeam; // 0x13D0
	int32 m_eRoundEndReason; // 0x13D4
	bool m_bRoundEndShowTimerDefend; // 0x13D8
	int32 m_iRoundEndTimerTime; // 0x13DC
	CUtlString m_sRoundEndFunFactToken; // 0x13E0
	CPlayerSlot m_iRoundEndFunFactPlayerSlot; // 0x13E8
	int32 m_iRoundEndFunFactData1; // 0x13EC
	int32 m_iRoundEndFunFactData2; // 0x13F0
	int32 m_iRoundEndFunFactData3; // 0x13F4
	CUtlString m_sRoundEndMessage; // 0x13F8
	int32 m_iRoundEndPlayerCount; // 0x1400
	bool m_bRoundEndNoMusic; // 0x1404
	int32 m_iRoundEndLegacy; // 0x1408
	uint8 m_nRoundEndCount; // 0x140C
	int32 m_iRoundStartRoundNumber; // 0x1410
	uint8 m_nRoundStartCount; // 0x1414
	float64 m_flLastPerfSampleTime; // 0x5420
};
class CEnvSkyAPI // server
{
};
class CPulseCell_Outflow_CycleShuffled : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outputs; // 0x0048
};
class CBaseCSGrenadeProjectile : public CBaseGrenade // server
{
	VectorWS m_vInitialPosition; // 0x09F0
	Vector m_vInitialVelocity; // 0x09FC
	int32 m_nBounces; // 0x0A08
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_nExplodeEffectIndex; // 0x0A10
	int32 m_nExplodeEffectTickBegin; // 0x0A18
	VectorWS m_vecExplodeEffectOrigin; // 0x0A1C
	GameTime_t m_flSpawnTime; // 0x0A28
	uint8 m_unOGSExtraFlags; // 0x0A2C
	bool m_bDetonationRecorded; // 0x0A2D
	uint16 m_nItemIndex; // 0x0A2E
	VectorWS m_vecOriginalSpawnLocation; // 0x0A30
	GameTime_t m_flLastBounceSoundTime; // 0x0A3C
	RotationVector m_vecGrenadeSpin; // 0x0A40
	Vector m_vecLastHitSurfaceNormal; // 0x0A4C
	int32 m_nTicksAtZeroVelocity; // 0x0A58
	bool m_bHasEverHitEnemy; // 0x0A5C
};
class CPhysConstraint : public CLogicalEntity // server
{
	IPhysicsJoint* m_hJoint; // 0x04A8
	CUtlSymbolLarge m_nameAttach1; // 0x04B0
	CUtlSymbolLarge m_nameAttach2; // 0x04B8
	CHandle< CBaseEntity > m_hAttach1; // 0x04C0
	CHandle< CBaseEntity > m_hAttach2; // 0x04C4
	CUtlSymbolLarge m_nameAttachment1; // 0x04C8
	CUtlSymbolLarge m_nameAttachment2; // 0x04D0
	CGameSoundEventName m_breakSound; // 0x04D8
	float32 m_forceLimit; // 0x04E0
	float32 m_torqueLimit; // 0x04E4
	float32 m_minTeleportDistance; // 0x04E8
	bool m_bSnapObjectPositions; // 0x04EC
	bool m_bTreatEntity1AsInfiniteMass; // 0x04ED
	CEntityIOOutput m_OnBreak; // 0x04F0
};
class CLogicAchievement : public CLogicalEntity // server
{
	bool m_bDisabled; // 0x04A8
	CUtlSymbolLarge m_iszAchievementEventID; // 0x04B0
	CEntityIOOutput m_OnFired; // 0x04B8
};
class CCSPlayerController_InventoryServices::NetworkedLoadoutSlot_t // server
{
	CEconItemView* pItem; // 0x0000
	uint16 team; // 0x0008
	uint16 slot; // 0x000A
};
class CLightComponent : public CEntityComponent // server
{
	CNetworkVarChainer __m_pChainEntity; // 0x0038
	Color m_Color; // 0x0075
	Color m_SecondaryColor; // 0x0079
	float32 m_flBrightness; // 0x0080
	float32 m_flBrightnessScale; // 0x0084
	float32 m_flBrightnessMult; // 0x0088
	float32 m_flRange; // 0x008C
	float32 m_flFalloff; // 0x0090
	float32 m_flAttenuation0; // 0x0094
	float32 m_flAttenuation1; // 0x0098
	float32 m_flAttenuation2; // 0x009C
	float32 m_flTheta; // 0x00A0
	float32 m_flPhi; // 0x00A4
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hLightCookie; // 0x00A8
	int32 m_nCascades; // 0x00B0
	int32 m_nCastShadows; // 0x00B4
	int32 m_nShadowWidth; // 0x00B8
	int32 m_nShadowHeight; // 0x00BC
	bool m_bRenderDiffuse; // 0x00C0
	int32 m_nRenderSpecular; // 0x00C4
	bool m_bRenderTransmissive; // 0x00C8
	float32 m_flOrthoLightWidth; // 0x00CC
	float32 m_flOrthoLightHeight; // 0x00D0
	int32 m_nStyle; // 0x00D4
	CUtlString m_Pattern; // 0x00D8
	int32 m_nCascadeRenderStaticObjects; // 0x00E0
	float32 m_flShadowCascadeCrossFade; // 0x00E4
	float32 m_flShadowCascadeDistanceFade; // 0x00E8
	float32 m_flShadowCascadeDistance0; // 0x00EC
	float32 m_flShadowCascadeDistance1; // 0x00F0
	float32 m_flShadowCascadeDistance2; // 0x00F4
	float32 m_flShadowCascadeDistance3; // 0x00F8
	int32 m_nShadowCascadeResolution0; // 0x00FC
	int32 m_nShadowCascadeResolution1; // 0x0100
	int32 m_nShadowCascadeResolution2; // 0x0104
	int32 m_nShadowCascadeResolution3; // 0x0108
	bool m_bUsesBakedShadowing; // 0x010C
	int32 m_nShadowPriority; // 0x0110
	int32 m_nBakedShadowIndex; // 0x0114
	int32 m_nLightPathUniqueId; // 0x0118
	int32 m_nLightMapUniqueId; // 0x011C
	bool m_bRenderToCubemaps; // 0x0120
	bool m_bAllowSSTGeneration; // 0x0121
	int32 m_nDirectLight; // 0x0124
	int32 m_nBounceLight; // 0x0128
	float32 m_flBounceScale; // 0x012C
	float32 m_flFadeMinDist; // 0x0130
	float32 m_flFadeMaxDist; // 0x0134
	float32 m_flShadowFadeMinDist; // 0x0138
	float32 m_flShadowFadeMaxDist; // 0x013C
	bool m_bEnabled; // 0x0140
	bool m_bFlicker; // 0x0141
	bool m_bPrecomputedFieldsValid; // 0x0142
	Vector m_vPrecomputedBoundsMins; // 0x0144
	Vector m_vPrecomputedBoundsMaxs; // 0x0150
	Vector m_vPrecomputedOBBOrigin; // 0x015C
	QAngle m_vPrecomputedOBBAngles; // 0x0168
	Vector m_vPrecomputedOBBExtent; // 0x0174
	float32 m_flPrecomputedMaxRange; // 0x0180
	int32 m_nFogLightingMode; // 0x0184
	float32 m_flFogContributionStength; // 0x0188
	float32 m_flNearClipPlane; // 0x018C
	Color m_SkyColor; // 0x0190
	float32 m_flSkyIntensity; // 0x0194
	Color m_SkyAmbientBounce; // 0x0198
	bool m_bUseSecondaryColor; // 0x019C
	bool m_bMixedShadows; // 0x019D
	GameTime_t m_flLightStyleStartTime; // 0x01A0
	float32 m_flCapsuleLength; // 0x01A4
	float32 m_flMinRoughness; // 0x01A8
	bool m_bPvsModifyEntity; // 0x01B8
};
class CCSWeaponBase : public CBasePlayerWeapon // server
{
	bool m_bRemoveable; // 0x0CD8
	bool m_bPlayerAmmoStockOnPickup; // 0x0CD9
	bool m_bRequireUseToTouch; // 0x0CDA
	WeaponGameplayAnimState m_iWeaponGameplayAnimState; // 0x0CDC
	GameTime_t m_flWeaponGameplayAnimStateTimestamp; // 0x0CE0
	GameTime_t m_flInspectCancelCompleteTime; // 0x0CE4
	bool m_bInspectPending; // 0x0CE8
	bool m_bInspectShouldLoop; // 0x0CE9
	int32 m_nLastEmptySoundCmdNum; // 0x0D14
	bool m_bFireOnEmpty; // 0x0D30
	CEntityIOOutput m_OnPlayerPickup; // 0x0D38
	CSWeaponMode m_weaponMode; // 0x0D50
	float32 m_flTurningInaccuracyDelta; // 0x0D54
	Vector m_vecTurningInaccuracyEyeDirLast; // 0x0D58
	float32 m_flTurningInaccuracy; // 0x0D64
	float32 m_fAccuracyPenalty; // 0x0D68
	GameTime_t m_flLastAccuracyUpdateTime; // 0x0D6C
	float32 m_fAccuracySmoothedForZoom; // 0x0D70
	int32 m_iRecoilIndex; // 0x0D74
	float32 m_flRecoilIndex; // 0x0D78
	bool m_bBurstMode; // 0x0D7C
	GameTick_t m_nPostponeFireReadyTicks; // 0x0D80
	float32 m_flPostponeFireReadyFrac; // 0x0D84
	bool m_bInReload; // 0x0D88
	GameTick_t m_nDeployTick; // 0x0D8C
	GameTime_t m_flDroppedAtTime; // 0x0D90
	bool m_bIsHauledBack; // 0x0D98
	bool m_bSilencerOn; // 0x0D99
	GameTime_t m_flTimeSilencerSwitchComplete; // 0x0D9C
	float32 m_flWeaponActionPlaybackRate; // 0x0DA0
	int32 m_iOriginalTeamNumber; // 0x0DA4
	int32 m_iMostRecentTeamNumber; // 0x0DA8
	bool m_bDroppedNearBuyZone; // 0x0DAC
	float32 m_flNextAttackRenderTimeOffset; // 0x0DB0
	bool m_bCanBePickedUp; // 0x0DC8
	bool m_bUseCanOverrideNextOwnerTouchTime; // 0x0DC9
	GameTime_t m_nextOwnerTouchTime; // 0x0DCC
	GameTime_t m_nextPrevOwnerTouchTime; // 0x0DD0
	GameTime_t m_nextPrevOwnerUseTime; // 0x0DD8
	CHandle< CCSPlayerPawn > m_hPrevOwner; // 0x0DDC
	GameTick_t m_nDropTick; // 0x0DE0
	bool m_bWasActiveWeaponWhenDropped; // 0x0DE4
	bool m_donated; // 0x0E04
	GameTime_t m_fLastShotTime; // 0x0E08
	bool m_bWasOwnedByCT; // 0x0E0C
	bool m_bWasOwnedByTerrorist; // 0x0E0D
	int32 m_numRemoveUnownedWeaponThink; // 0x0E10
	CIronSightController m_IronSightController; // 0x0E70
	int32 m_iIronSightMode; // 0x0E88
	GameTime_t m_flLastLOSTraceFailureTime; // 0x0E8C
	float32 m_flWatTickOffset; // 0x0E90
	GameTime_t m_flLastShakeTime; // 0x0EA0
};
class CPointClientUIDialog : public CBaseClientUIEntity // server
{
	CHandle< CBaseEntity > m_hActivator; // 0x08D0
	bool m_bStartEnabled; // 0x08D4
};
class CLogicLineToEntity : public CLogicalEntity // server
{
	CEntityOutputTemplate< Vector > m_Line; // 0x04A8
	CUtlSymbolLarge m_SourceName; // 0x04D0
	CHandle< CBaseEntity > m_StartEntity; // 0x04D8
	CHandle< CBaseEntity > m_EndEntity; // 0x04DC
};
class CSoundAreaEntitySphere : public CSoundAreaEntityBase // server
{
	float32 m_flRadius; // 0x04C8
};
class CCSPlayer_ActionTrackingServices : public CPlayerPawnComponent // server
{
	CHandle< CBasePlayerWeapon > m_hLastWeaponBeforeC4AutoSwitch; // 0x01F8
	bool m_bIsRescuing; // 0x0224
	WeaponPurchaseTracker_t m_weaponPurchasesThisMatch; // 0x0228
	WeaponPurchaseTracker_t m_weaponPurchasesThisRound; // 0x0298
};
class CTestPulseIOComponent_API // server
{
};
class CPhysicalButton : public CBaseButton // server
{
};
class CInfoSpawnGroupLoadUnload : public CLogicalEntity // server
{
	CEntityIOOutput m_OnSpawnGroupLoadStarted; // 0x04A8
	CEntityIOOutput m_OnSpawnGroupLoadFinished; // 0x04C0
	CEntityIOOutput m_OnSpawnGroupUnloadStarted; // 0x04D8
	CEntityIOOutput m_OnSpawnGroupUnloadFinished; // 0x04F0
	CUtlSymbolLarge m_iszSpawnGroupName; // 0x0508
	CUtlSymbolLarge m_iszSpawnGroupFilterName; // 0x0510
	CUtlSymbolLarge m_iszLandmarkName; // 0x0518
	CUtlString m_sFixedSpawnGroupName; // 0x0520
	float32 m_flTimeoutInterval; // 0x0528
	bool m_bAutoActivate; // 0x052C
	bool m_bUnloadingStarted; // 0x052D
	bool m_bQueueActiveSpawnGroupChange; // 0x052E
	bool m_bQueueFinishLoading; // 0x052F
};
class CSoundAreaEntityOrientedBox : public CSoundAreaEntityBase // server
{
	Vector m_vMin; // 0x04C8
	Vector m_vMax; // 0x04D4
};
class CCSObserver_MovementServices : public CPlayer_MovementServices // server
{
};
class CPulseCell_Outflow_ListenForAnimgraphTag : public CPulseCell_BaseYieldingInflow // server
{
	CPulse_ResumePoint m_OnStart; // 0x00D8
	CPulse_ResumePoint m_OnEnd; // 0x0120
	CGlobalSymbol m_TagName; // 0x0168
};
class CBodyComponent : public CEntityComponent // server
{
	CGameSceneNode* m_pSceneNode; // 0x0008
	CNetworkVarChainer __m_pChainEntity; // 0x0048
};
class CPulseCell_Inflow_Method : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_MethodName; // 0x0080
	CUtlString m_Description; // 0x0090
	bool m_bIsPublic; // 0x0098
	CPulseValueFullType m_ReturnType; // 0x00A0
	CUtlLeanVector< CPulseRuntimeMethodArg > m_Args; // 0x00B8
};
class CDecoyGrenade : public CBaseCSGrenade // server
{
};
class CEconItemView : public IEconItemInterface // server
{
	uint16 m_iItemDefinitionIndex; // 0x0038
	int32 m_iEntityQuality; // 0x003C
	uint32 m_iEntityLevel; // 0x0040
	uint64 m_iItemID; // 0x0048
	uint32 m_iItemIDHigh; // 0x0050
	uint32 m_iItemIDLow; // 0x0054
	uint32 m_iAccountID; // 0x0058
	uint32 m_iInventoryPosition; // 0x005C
	bool m_bInitialized; // 0x0068
	CAttributeList m_AttributeList; // 0x0070
	CAttributeList m_NetworkedDynamicAttributes; // 0x00E8
	char[161] m_szCustomName; // 0x0160
	char[161] m_szCustomNameOverride; // 0x0201
};
class CGameStateReportAPI // server
{
};
class CIncendiaryGrenade : public CMolotovGrenade // server
{
};
class CBaseDMStart : public CPointEntity // server
{
	CUtlSymbolLarge m_Master; // 0x04A8
};
class CBaseModelEntity : public CBaseEntity // server
{
	CRenderComponent* m_CRenderComponent; // 0x04A8
	CHitboxComponent m_CHitboxComponent; // 0x04B0
	CChoreoComponent* m_pChoreoComponent; // 0x04C8
	HitGroup_t m_nDestructiblePartInitialStateDestructed0; // 0x04D0
	HitGroup_t m_nDestructiblePartInitialStateDestructed1; // 0x04D4
	HitGroup_t m_nDestructiblePartInitialStateDestructed2; // 0x04D8
	HitGroup_t m_nDestructiblePartInitialStateDestructed3; // 0x04DC
	HitGroup_t m_nDestructiblePartInitialStateDestructed4; // 0x04E0
	int32 m_nDestructiblePartInitialStateDestructed0_PartIndex; // 0x04E4
	int32 m_nDestructiblePartInitialStateDestructed1_PartIndex; // 0x04E8
	int32 m_nDestructiblePartInitialStateDestructed2_PartIndex; // 0x04EC
	int32 m_nDestructiblePartInitialStateDestructed3_PartIndex; // 0x04F0
	int32 m_nDestructiblePartInitialStateDestructed4_PartIndex; // 0x04F4
	bool m_bDestructiblePartInitialStateDestructed0_GenerateBreakpieces; // 0x04F8
	bool m_bDestructiblePartInitialStateDestructed1_GenerateBreakpieces; // 0x04F9
	bool m_bDestructiblePartInitialStateDestructed2_GenerateBreakpieces; // 0x04FA
	bool m_bDestructiblePartInitialStateDestructed3_GenerateBreakpieces; // 0x04FB
	bool m_bDestructiblePartInitialStateDestructed4_GenerateBreakpieces; // 0x04FC
	CDestructiblePartsComponent* m_pDestructiblePartsSystemComponent; // 0x0500
	CEntityOutputTemplate< CBaseModelEntity::OnDamageLevelChangedArgs_t > m_OnDestructibleHitGroupDamageLevelChanged; // 0x0508
	GameTime_t m_flDissolveStartTime; // 0x0530
	CEntityIOOutput m_OnIgnite; // 0x0538
	RenderMode_t m_nRenderMode; // 0x0550
	RenderFx_t m_nRenderFX; // 0x0551
	bool m_bAllowFadeInView; // 0x0552
	Color m_clrRender; // 0x0570
	CUtlVectorEmbeddedNetworkVar< EntityRenderAttribute_t > m_vecRenderAttributes; // 0x0578
	bool m_bRenderToCubemaps; // 0x05E0
	bool m_bNoInterpolate; // 0x05E1
	CCollisionProperty m_Collision; // 0x05E8
	CGlowProperty m_Glow; // 0x06A0
	float32 m_flGlowBackfaceMult; // 0x06F8
	float32 m_fadeMinDist; // 0x06FC
	float32 m_fadeMaxDist; // 0x0700
	float32 m_flFadeScale; // 0x0704
	float32 m_flShadowStrength; // 0x0708
	uint8 m_nObjectCulling; // 0x070C
	CUtlOrderedMap< CGlobalSymbol, int32 > m_bodyGroupChoices; // 0x0710
	CNetworkViewOffsetVector m_vecViewOffset; // 0x0738
	uint32[1] m_bvDisabledHitGroups; // 0x0768
};
class fogplayerparams_t // server
{
	CHandle< CFogController > m_hCtrl; // 0x0008
	float32 m_flTransitionTime; // 0x000C
	Color m_OldColor; // 0x0010
	float32 m_flOldStart; // 0x0014
	float32 m_flOldEnd; // 0x0018
	float32 m_flOldMaxDensity; // 0x001C
	float32 m_flOldHDRColorScale; // 0x0020
	float32 m_flOldFarZ; // 0x0024
	Color m_NewColor; // 0x0028
	float32 m_flNewStart; // 0x002C
	float32 m_flNewEnd; // 0x0030
	float32 m_flNewMaxDensity; // 0x0034
	float32 m_flNewHDRColorScale; // 0x0038
	float32 m_flNewFarZ; // 0x003C
};
class CGlowProperty // server
{
	Vector m_fGlowColor; // 0x0008
	int32 m_iGlowType; // 0x0030
	int32 m_iGlowTeam; // 0x0034
	int32 m_nGlowRange; // 0x0038
	int32 m_nGlowRangeMin; // 0x003C
	Color m_glowColorOverride; // 0x0040
	bool m_bFlashing; // 0x0044
	float32 m_flGlowTime; // 0x0048
	float32 m_flGlowStartTime; // 0x004C
	bool m_bEligibleForScreenHighlight; // 0x0050
	bool m_bGlowing; // 0x0051
};
class CInstancedSceneEntity : public CSceneEntity // server
{
	CHandle< CBaseEntity > m_hOwner; // 0x07F0
	bool m_bHadOwner; // 0x07F4
	float32 m_flPostSpeakDelay; // 0x07F8
	float32 m_flPreDelay; // 0x07FC
	bool m_bIsBackground; // 0x0800
	bool m_bRemoveOnCompletion; // 0x0801
	CHandle< CBaseEntity > m_hTarget; // 0x0804
};
class CPulseCell_BaseValue : public CPulseCell_Base // pulse_runtime_lib
{
};
class CCitadelSoundOpvarSetOBB : public CBaseEntity // server
{
	CUtlSymbolLarge m_iszStackName; // 0x04A8
	CUtlSymbolLarge m_iszOperatorName; // 0x04B0
	CUtlSymbolLarge m_iszOpvarName; // 0x04B8
	Vector m_vDistanceInnerMins; // 0x04C0
	Vector m_vDistanceInnerMaxs; // 0x04CC
	Vector m_vDistanceOuterMins; // 0x04D8
	Vector m_vDistanceOuterMaxs; // 0x04E4
	int32 m_nAABBDirection; // 0x04F0
};
class CSoundEventParameter : public CBaseEntity // server
{
	CUtlSymbolLarge m_iszParamName; // 0x04C0
	float32 m_flFloatValue; // 0x04C8
};
class CPlayer_WaterServices : public CPlayerPawnComponent // server
{
};
class CPulseCell_BooleanSwitchState : public CPulseCell_BaseState // pulse_runtime_lib
{
	CPulseObservableExpression< bool > m_Condition; // 0x00D8
	CPulse_OutflowConnection m_WhenTrue; // 0x0150
	CPulse_OutflowConnection m_WhenFalse; // 0x0198
};
class CRotButton : public CBaseButton // server
{
};
class CEnvViewPunch : public CPointEntity // server
{
	float32 m_flRadius; // 0x04A8
	QAngle m_angViewPunch; // 0x04AC
};
class CDamageRecord // server
{
	CHandle< CCSPlayerPawn > m_PlayerDamager; // 0x0030
	CHandle< CCSPlayerPawn > m_PlayerRecipient; // 0x0034
	CHandle< CCSPlayerController > m_hPlayerControllerDamager; // 0x0038
	CHandle< CCSPlayerController > m_hPlayerControllerRecipient; // 0x003C
	CUtlString m_szPlayerDamagerName; // 0x0040
	CUtlString m_szPlayerRecipientName; // 0x0048
	uint64 m_DamagerXuid; // 0x0050
	uint64 m_RecipientXuid; // 0x0058
	float32 m_flBulletsDamage; // 0x0060
	float32 m_flDamage; // 0x0064
	float32 m_flActualHealthRemoved; // 0x0068
	int32 m_iNumHits; // 0x006C
	int32 m_iLastBulletUpdate; // 0x0070
	bool m_bIsOtherEnemy; // 0x0074
	EKillTypes_t m_killType; // 0x0075
};
class VPhysicsCollisionAttribute_t // server
{
	uint64 m_nInteractsAs; // 0x0008
	uint64 m_nInteractsWith; // 0x0010
	uint64 m_nInteractsExclude; // 0x0018
	uint32 m_nEntityId; // 0x0020
	uint32 m_nOwnerId; // 0x0024
	uint16 m_nHierarchyId; // 0x0028
	uint16 m_nDetailLayerMask; // 0x002A
	uint8 m_nDetailLayerMaskType; // 0x002C
	uint8 m_nTargetDetailLayer; // 0x002D
	uint8 m_nCollisionGroup; // 0x002E
	uint8 m_nCollisionFunctionMask; // 0x002F
};
class CItemKevlar : public CItem // server
{
};
class CFuncShatterglass : public CBaseModelEntity // server
{
	matrix3x4_t m_matPanelTransform; // 0x0770
	matrix3x4_t m_matPanelTransformWsTemp; // 0x07A0
	CUtlVector< uint32 > m_vecShatterGlassShards; // 0x07D0
	Vector2D m_PanelSize; // 0x07E8
	GameTime_t m_flLastShatterSoundEmitTime; // 0x07F0
	GameTime_t m_flLastCleanupTime; // 0x07F4
	GameTime_t m_flInitAtTime; // 0x07F8
	float32 m_flGlassThickness; // 0x07FC
	float32 m_flSpawnInvulnerability; // 0x0800
	bool m_bBreakSilent; // 0x0804
	bool m_bBreakShardless; // 0x0805
	bool m_bBroken; // 0x0806
	bool m_bGlassNavIgnore; // 0x0807
	bool m_bGlassInFrame; // 0x0808
	bool m_bStartBroken; // 0x0809
	uint8 m_iInitialDamageType; // 0x080A
	CUtlSymbolLarge m_szDamagePositioningEntityName01; // 0x0810
	CUtlSymbolLarge m_szDamagePositioningEntityName02; // 0x0818
	CUtlSymbolLarge m_szDamagePositioningEntityName03; // 0x0820
	CUtlSymbolLarge m_szDamagePositioningEntityName04; // 0x0828
	CUtlVector< VectorWS > m_vInitialDamagePositions; // 0x0830
	CUtlVector< VectorWS > m_vExtraDamagePositions; // 0x0848
	CUtlVector< Vector4D > m_vInitialPanelVertices; // 0x0860
	CEntityIOOutput m_OnBroken; // 0x0878
	uint8 m_iSurfaceType; // 0x0890
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hMaterialDamageBase; // 0x0898
};
class CNavWalkable : public CPointEntity // server
{
};
class CPlantedC4 : public CBaseAnimGraph // server
{
	bool m_bBombTicking; // 0x09B8
	GameTime_t m_flC4Blow; // 0x09BC
	int32 m_nBombSite; // 0x09C0
	int32 m_nSourceSoundscapeHash; // 0x09C4
	bool m_bAbortDetonationBecauseWorldIsFrozen; // 0x09C8
	CAttributeContainer m_AttributeManager; // 0x09D0
	CEntityIOOutput m_OnBombDefused; // 0x0CC8
	CEntityIOOutput m_OnBombBeginDefuse; // 0x0CE0
	CEntityIOOutput m_OnBombDefuseAborted; // 0x0CF8
	bool m_bCannotBeDefused; // 0x0D10
	EntitySpottedState_t m_entitySpottedState; // 0x0D18
	int32 m_nSpotRules; // 0x0D30
	bool m_bHasExploded; // 0x0D34
	bool m_bBombDefused; // 0x0D35
	bool m_bTrainingPlacedByPlayer; // 0x0D36
	float32 m_flTimerLength; // 0x0D38
	bool m_bBeingDefused; // 0x0D3C
	GameTime_t m_fLastDefuseTime; // 0x0D44
	float32 m_flDefuseLength; // 0x0D4C
	GameTime_t m_flDefuseCountDown; // 0x0D50
	CHandle< CCSPlayerPawn > m_hBombDefuser; // 0x0D54
	int32 m_iProgressBarTime; // 0x0D58
	bool m_bVoiceAlertFired; // 0x0D5C
	bool[4] m_bVoiceAlertPlayed; // 0x0D5D
	GameTime_t m_flNextBotBeepTime; // 0x0D64
	QAngle m_angCatchUpToPlayerEye; // 0x0D6C
	GameTime_t m_flLastSpinDetectionTime; // 0x0D78
};
class CEnvSoundscapeProxyAlias_snd_soundscape_proxy : public CEnvSoundscapeProxy // server
{
};
class CVoteController : public CBaseEntity // server
{
	int32 m_iActiveIssueIndex; // 0x04A8
	int32 m_iOnlyTeamToVote; // 0x04AC
	int32[5] m_nVoteOptionCount; // 0x04B0
	int32 m_nPotentialVotes; // 0x04C4
	bool m_bIsYesNoVote; // 0x04C8
	CountdownTimer m_acceptingVotesTimer; // 0x04D0
	CountdownTimer m_executeCommandTimer; // 0x04E8
	CountdownTimer m_resetVoteTimer; // 0x0500
	int32[64] m_nVotesCast; // 0x0518
	CPlayerSlot m_playerHoldingVote; // 0x0618
	CPlayerSlot m_playerOverrideForVote; // 0x061C
	int32 m_nHighestCountIndex; // 0x0620
	CUtlVector< CBaseIssue* > m_potentialIssues; // 0x0628
	CUtlVector< char* > m_VoteOptions; // 0x0640
};
class CFootstepControl_API // server
{
};
class CPulseCell_Inflow_Yield : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_UnyieldResume; // 0x00D8
};
class CPulseMathlib // pulse_runtime_lib
{
};
class CPhysImpact : public CPointEntity // server
{
	float32 m_damage; // 0x04A8
	float32 m_distance; // 0x04AC
	CUtlSymbolLarge m_directionEntityName; // 0x04B0
};
class CCSPlayerPawnBase_API // server
{
};
class CBaseEntity : public CEntityInstance // server
{
	CBodyComponent* m_CBodyComponent; // 0x0030
	CNetworkTransmitComponent m_NetworkTransmitComponent; // 0x0038
	CUtlVector< thinkfunc_t > m_aThinkFunctions; // 0x0248
	int32 m_iCurrentThinkContext; // 0x0260
	GameTick_t m_nLastThinkTick; // 0x0264
	bool m_bDisabledContextThinks; // 0x0268
	CTypedBitVec< 64 > m_isSteadyState; // 0x0278
	float32 m_lastNetworkChange; // 0x0280
	BASEPTR m_think; // 0x0288
	CUtlVector< ResponseContext_t > m_ResponseContexts; // 0x0290
	CUtlSymbolLarge m_iszResponseContext; // 0x02A8
	ENTITYFUNCPTR m_pfnTouch; // 0x02B0
	USEPTR m_pfnUse; // 0x02B8
	ENTITYFUNCPTR m_pfnBlocked; // 0x02C0
	BASEPTR m_pfnMoveDone; // 0x02C8
	int32 m_iHealth; // 0x02D0
	int32 m_iMaxHealth; // 0x02D4
	uint8 m_lifeState; // 0x02D8
	float32 m_flDamageAccumulator; // 0x02DC
	bool m_bTakesDamage; // 0x02E0
	TakeDamageFlags_t m_nTakeDamageFlags; // 0x02E8
	EntityPlatformTypes_t m_nPlatformType; // 0x02F0
	MoveCollide_t m_MoveCollide; // 0x02F2
	MoveType_t m_MoveType; // 0x02F3
	MoveType_t m_nPreviouslySetMoveType; // 0x02F4
	MoveType_t m_nActualMoveType; // 0x02F5
	uint8 m_nWaterTouch; // 0x02F6
	uint8 m_nSlimeTouch; // 0x02F7
	bool m_bRestoreInHierarchy; // 0x02F8
	CUtlSymbolLarge m_target; // 0x0300
	CHandle< CBaseFilter > m_hDamageFilter; // 0x0308
	CUtlSymbolLarge m_iszDamageFilterName; // 0x0310
	float32 m_flMoveDoneTime; // 0x0318
	CUtlStringToken m_nSubclassID; // 0x031C
	float32 m_flAnimTime; // 0x0328
	float32 m_flSimulationTime; // 0x032C
	GameTime_t m_flCreateTime; // 0x0330
	bool m_bClientSideRagdoll; // 0x0334
	uint8 m_ubInterpolationFrame; // 0x0335
	VectorWS m_vPrevVPhysicsUpdatePos; // 0x0338
	uint8 m_iTeamNum; // 0x0344
	CUtlSymbolLarge m_iGlobalname; // 0x0348
	int32 m_iSentToClients; // 0x0350
	CUtlString m_sUniqueHammerID; // 0x0358
	uint32 m_spawnflags; // 0x0360
	GameTick_t m_nNextThinkTick; // 0x0364
	int32 m_nSimulationTick; // 0x0368
	CEntityIOOutput m_OnKilled; // 0x0370
	uint32 m_fFlags; // 0x0388
	Vector m_vecAbsVelocity; // 0x038C
	CNetworkVelocityVector m_vecVelocity; // 0x0398
	Vector m_vecBaseVelocity; // 0x03C8
	int32 m_nPushEnumCount; // 0x03D4
	CCollisionProperty* m_pCollision; // 0x03D8
	CHandle< CBaseEntity > m_hEffectEntity; // 0x03E0
	CHandle< CBaseEntity > m_hOwnerEntity; // 0x03E4
	uint32 m_fEffects; // 0x03E8
	CHandle< CBaseEntity > m_hGroundEntity; // 0x03EC
	int32 m_nGroundBodyIndex; // 0x03F0
	float32 m_flFriction; // 0x03F4
	float32 m_flElasticity; // 0x03F8
	float32 m_flGravityScale; // 0x03FC
	float32 m_flTimeScale; // 0x0400
	float32 m_flWaterLevel; // 0x0404
	bool m_bGravityDisabled; // 0x0408
	bool m_bAnimatedEveryTick; // 0x0409
	float32 m_flActualGravityScale; // 0x040C
	bool m_bGravityActuallyDisabled; // 0x0410
	bool m_bDisableLowViolence; // 0x0411
	uint8 m_nWaterType; // 0x0412
	int32 m_iEFlags; // 0x0414
	CEntityIOOutput m_OnUser1; // 0x0418
	CEntityIOOutput m_OnUser2; // 0x0430
	CEntityIOOutput m_OnUser3; // 0x0448
	CEntityIOOutput m_OnUser4; // 0x0460
	int32 m_iInitialTeamNum; // 0x0478
	GameTime_t m_flNavIgnoreUntilTime; // 0x047C
	QAngle m_vecAngVelocity; // 0x0480
	bool m_bNetworkQuantizeOriginAndAngles; // 0x048C
	bool m_bLagCompensate; // 0x048D
	CHandle< CBaseEntity > m_pBlocker; // 0x0490
	float32 m_flLocalTime; // 0x0494
	float32 m_flVPhysicsUpdateLocalTime; // 0x0498
	BloodType m_nBloodType; // 0x049C
	CPulseGraphInstance_ServerEntity* m_pPulseGraphInstance; // 0x04A0
};
class CPlayer_UseServices : public CPlayerPawnComponent // server
{
};
class CGameSceneNodeHandle // server
{
	CEntityHandle m_hOwner; // 0x0008
	CUtlStringToken m_name; // 0x000C
};
class CMarkupVolumeWithRef : public CMarkupVolumeTagged // server
{
	bool m_bUseRef; // 0x07B8
	Vector m_vRefPosEntitySpace; // 0x07BC
	VectorWS m_vRefPosWorldSpace; // 0x07C8
	float32 m_flRefDot; // 0x07D4
};
class CGameMoney_API // server
{
};
class CCSGO_TeamSelectCharacterPosition : public CCSGO_TeamPreviewCharacterPosition // server
{
};
class CPulseCell_Unknown : public CPulseCell_Base // pulse_runtime_lib
{
	KeyValues3 m_UnknownKeys; // 0x0048
};
class CFuncPlatRot : public CFuncPlat // server
{
	QAngle m_end; // 0x0828
	QAngle m_start; // 0x0834
};
class CRagdollMagnet : public CPointEntity // server
{
	bool m_bDisabled; // 0x04A8
	float32 m_radius; // 0x04AC
	float32 m_force; // 0x04B0
	VectorWS m_axis; // 0x04B4
};
class CInfoInstructorHintTarget : public CPointEntity // server
{
};
class CSpriteAlias_env_glow : public CSprite // server
{
};
class CFireCrackerBlast : public CInferno // server
{
};
class CSpotlightEnd : public CBaseModelEntity // server
{
	float32 m_flLightScale; // 0x0770
	float32 m_Radius; // 0x0774
	Vector m_vSpotlightDir; // 0x0778
	VectorWS m_vSpotlightOrg; // 0x0784
};
class CPulseStringlib // pulse_runtime_lib
{
};
class CEnvSky : public CBaseModelEntity // server
{
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hSkyMaterial; // 0x0770
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hSkyMaterialLightingOnly; // 0x0778
	bool m_bStartDisabled; // 0x0780
	Color m_vTintColor; // 0x0781
	Color m_vTintColorLightingOnly; // 0x0785
	float32 m_flBrightnessScale; // 0x078C
	int32 m_nFogType; // 0x0790
	float32 m_flFogMinStart; // 0x0794
	float32 m_flFogMinEnd; // 0x0798
	float32 m_flFogMaxStart; // 0x079C
	float32 m_flFogMaxEnd; // 0x07A0
	bool m_bEnabled; // 0x07A4
};
class CInfoSpawnGroupLandmark : public CPointEntity // server
{
};
class CPointAngleSensor : public CPointEntity // server
{
	bool m_bDisabled; // 0x04A8
	CUtlSymbolLarge m_nLookAtName; // 0x04B0
	CHandle< CBaseEntity > m_hTargetEntity; // 0x04B8
	CHandle< CBaseEntity > m_hLookAtEntity; // 0x04BC
	float32 m_flDuration; // 0x04C0
	float32 m_flDotTolerance; // 0x04C4
	GameTime_t m_flFacingTime; // 0x04C8
	bool m_bFired; // 0x04CC
	CEntityIOOutput m_OnFacingLookat; // 0x04D0
	CEntityIOOutput m_OnNotFacingLookat; // 0x04E8
	CEntityOutputTemplate< Vector > m_TargetDir; // 0x0500
	CEntityOutputTemplate< float32 > m_FacingPercentage; // 0x0528
};
class CEnvWindController : public CBaseEntity // server
{
	CEnvWindShared m_EnvWindShared; // 0x04A8
	float32 m_fDirectionVariation; // 0x05D8
	float32 m_fSpeedVariation; // 0x05DC
	float32 m_fTurbulence; // 0x05E0
	float32 m_fVolumeHalfExtentXY; // 0x05E4
	float32 m_fVolumeHalfExtentZ; // 0x05E8
	int32 m_nVolumeResolutionXY; // 0x05EC
	int32 m_nVolumeResolutionZ; // 0x05F0
	int32 m_nClipmapLevels; // 0x05F4
	bool m_bIsMaster; // 0x05F8
	bool m_bFirstTime; // 0x05F9
};
class CSPerRoundStats_t // server
{
	int32 m_iKills; // 0x0030
	int32 m_iDeaths; // 0x0034
	int32 m_iAssists; // 0x0038
	int32 m_iDamage; // 0x003C
	int32 m_iEquipmentValue; // 0x0040
	int32 m_iMoneySaved; // 0x0044
	int32 m_iKillReward; // 0x0048
	int32 m_iLiveTime; // 0x004C
	int32 m_iHeadShotKills; // 0x0050
	int32 m_iObjective; // 0x0054
	int32 m_iCashEarned; // 0x0058
	int32 m_iUtilityDamage; // 0x005C
	int32 m_iEnemiesFlashed; // 0x0060
};
class CGenericConstraint : public CPhysConstraint // server
{
	bool m_bPlaceAnchorsAtConstraintTransform; // 0x0510
	JointMotion_t m_nLinearMotionX; // 0x0514
	JointMotion_t m_nLinearMotionY; // 0x0518
	JointMotion_t m_nLinearMotionZ; // 0x051C
	float32 m_flLinearFrequencyX; // 0x0520
	float32 m_flLinearFrequencyY; // 0x0524
	float32 m_flLinearFrequencyZ; // 0x0528
	float32 m_flLinearDampingRatioX; // 0x052C
	float32 m_flLinearDampingRatioY; // 0x0530
	float32 m_flLinearDampingRatioZ; // 0x0534
	float32 m_flMaxLinearImpulseX; // 0x0538
	float32 m_flMaxLinearImpulseY; // 0x053C
	float32 m_flMaxLinearImpulseZ; // 0x0540
	float32 m_flBreakAfterTimeX; // 0x0544
	float32 m_flBreakAfterTimeY; // 0x0548
	float32 m_flBreakAfterTimeZ; // 0x054C
	GameTime_t m_flBreakAfterTimeStartTimeX; // 0x0550
	GameTime_t m_flBreakAfterTimeStartTimeY; // 0x0554
	GameTime_t m_flBreakAfterTimeStartTimeZ; // 0x0558
	float32 m_flBreakAfterTimeThresholdX; // 0x055C
	float32 m_flBreakAfterTimeThresholdY; // 0x0560
	float32 m_flBreakAfterTimeThresholdZ; // 0x0564
	float32 m_flNotifyForceX; // 0x0568
	float32 m_flNotifyForceY; // 0x056C
	float32 m_flNotifyForceZ; // 0x0570
	float32 m_flNotifyForceMinTimeX; // 0x0574
	float32 m_flNotifyForceMinTimeY; // 0x0578
	float32 m_flNotifyForceMinTimeZ; // 0x057C
	GameTime_t m_flNotifyForceLastTimeX; // 0x0580
	GameTime_t m_flNotifyForceLastTimeY; // 0x0584
	GameTime_t m_flNotifyForceLastTimeZ; // 0x0588
	bool m_bAxisNotifiedX; // 0x058C
	bool m_bAxisNotifiedY; // 0x058D
	bool m_bAxisNotifiedZ; // 0x058E
	JointMotion_t m_nAngularMotionX; // 0x0590
	JointMotion_t m_nAngularMotionY; // 0x0594
	JointMotion_t m_nAngularMotionZ; // 0x0598
	float32 m_flAngularFrequencyX; // 0x059C
	float32 m_flAngularFrequencyY; // 0x05A0
	float32 m_flAngularFrequencyZ; // 0x05A4
	float32 m_flAngularDampingRatioX; // 0x05A8
	float32 m_flAngularDampingRatioY; // 0x05AC
	float32 m_flAngularDampingRatioZ; // 0x05B0
	float32 m_flMaxAngularImpulseX; // 0x05B4
	float32 m_flMaxAngularImpulseY; // 0x05B8
	float32 m_flMaxAngularImpulseZ; // 0x05BC
	CEntityIOOutput m_NotifyForceReachedX; // 0x05C0
	CEntityIOOutput m_NotifyForceReachedY; // 0x05D8
	CEntityIOOutput m_NotifyForceReachedZ; // 0x05F0
};
class CPulseCell_Outflow_CycleRandom : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outputs; // 0x0048
};
class CPulseCell_Step_PublicOutput : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseRuntimeOutputIndex_t m_OutputIndex; // 0x0048
};
class CEnvLaser : public CBeam // server
{
	CUtlSymbolLarge m_iszLaserTarget; // 0x0810
	CHandle< CSprite > m_pSprite; // 0x0818
	CUtlSymbolLarge m_iszSpriteName; // 0x0820
	Vector m_firePosition; // 0x0828
	float32 m_flStartFrame; // 0x0834
};
class CSoundOpvarSetEntity : public CBaseEntity // server
{
	CUtlSymbolLarge m_iszStackName; // 0x04C0
	CUtlSymbolLarge m_iszOperatorName; // 0x04C8
	CUtlSymbolLarge m_iszOpvarName; // 0x04D0
	int32 m_nOpvarType; // 0x04D8
	int32 m_nOpvarIndex; // 0x04DC
	float32 m_flOpvarValue; // 0x04E0
	CUtlSymbolLarge m_OpvarValueString; // 0x04E8
	bool m_bSetOnSpawn; // 0x04F0
};
class CEnvBeverage : public CBaseEntity // server
{
	bool m_CanInDispenser; // 0x04A8
	int32 m_nBeverageType; // 0x04AC
};
class CPhysMotor : public CLogicalEntity // server
{
	CUtlSymbolLarge m_nameAttach; // 0x04A8
	CUtlSymbolLarge m_nameAnchor; // 0x04B0
	CHandle< CBaseEntity > m_hAttachedObject; // 0x04B8
	CHandle< CBaseEntity > m_hAnchorObject; // 0x04BC
	float32 m_spinUp; // 0x04C0
	float32 m_spinDown; // 0x04C4
	float32 m_flMotorFriction; // 0x04C8
	float32 m_additionalAcceleration; // 0x04CC
	float32 m_angularAcceleration; // 0x04D0
	float32 m_flTorqueScale; // 0x04D4
	float32 m_flTargetSpeed; // 0x04D8
	float32 m_flSpeedWhenSpinUpOrSpinDownStarted; // 0x04DC
	IPhysicsBody* m_pFixedWorldBody; // 0x04E0
	IPhysicsJoint* m_pMotorJoint; // 0x04E8
	CMotorController m_motor; // 0x04F0
};
class CLogicGameEvent : public CLogicalEntity // server
{
	CUtlSymbolLarge m_iszEventName; // 0x04A8
};
class CBaseAnimGraphAPI // server
{
};
class CPhysicsPropMultiplayer : public CPhysicsProp // server
{
};
class CPhysExplosion : public CPointEntity // server
{
	bool m_bExplodeOnSpawn; // 0x04A8
	float32 m_flMagnitude; // 0x04AC
	float32 m_flDamage; // 0x04B0
	float32 m_radius; // 0x04B4
	CUtlSymbolLarge m_targetEntityName; // 0x04B8
	float32 m_flInnerRadius; // 0x04C0
	float32 m_flPushScale; // 0x04C4
	bool m_bConvertToDebrisWhenPossible; // 0x04C8
	bool m_bAffectInvulnerableEnts; // 0x04C9
	bool m_bDisablePushClamp; // 0x04CA
	CEntityIOOutput m_OnPushedPlayer; // 0x04D0
};
class CSplineConstraint : public CPhysConstraint // server
{
	Vector m_vAnchorOffsetRestore; // 0x0558
	CHandle< CBaseEntity > m_hSplineEntity; // 0x0564
	IPhysicsBody* m_pSplineBody; // 0x0568
	bool m_bEnableLateralConstraint; // 0x0570
	bool m_bEnableVerticalConstraint; // 0x0571
	bool m_bEnableAngularConstraint; // 0x0572
	bool m_bEnableLimit; // 0x0573
	bool m_bFireEventsOnPath; // 0x0574
	float32 m_flLinearFrequency; // 0x0578
	float32 m_flLinarDampingRatio; // 0x057C
	float32 m_flJointFriction; // 0x0580
	float32 m_flTransitionTime; // 0x0584
	VectorWS m_vPreSolveAnchorPos; // 0x0598
	GameTime_t m_StartTransitionTime; // 0x05A4
	Vector m_vTangentSpaceAnchorAtTransitionStart; // 0x05A8
};
class CLogicCompare : public CLogicalEntity // server
{
	float32 m_flInValue; // 0x04A8
	float32 m_flCompareValue; // 0x04AC
	CEntityOutputTemplate< float32 > m_OnLessThan; // 0x04B0
	CEntityOutputTemplate< float32 > m_OnEqualTo; // 0x04D0
	CEntityOutputTemplate< float32 > m_OnNotEqualTo; // 0x04F0
	CEntityOutputTemplate< float32 > m_OnGreaterThan; // 0x0510
};
class CCSGameModeRules_Noop : public CCSGameModeRules // server
{
};
class CPulse_BlackboardReference // pulse_runtime_lib
{
	CStrongHandle< InfoForResourceTypeIPulseGraphDef > m_hBlackboardResource; // 0x0000
	PulseSymbol_t m_BlackboardResource; // 0x0008
	PulseDocNodeID_t m_nNodeID; // 0x0018
	CGlobalSymbol m_NodeName; // 0x0020
};
class CFuncTankTrain : public CFuncTrackTrain // server
{
	CEntityIOOutput m_OnDeath; // 0x0898
};
class CPointClientUIWorldPanel : public CBaseClientUIEntity // server
{
	bool m_bIgnoreInput; // 0x08D0
	bool m_bLit; // 0x08D1
	bool m_bFollowPlayerAcrossTeleport; // 0x08D2
	float32 m_flWidth; // 0x08D4
	float32 m_flHeight; // 0x08D8
	float32 m_flDPI; // 0x08DC
	float32 m_flInteractDistance; // 0x08E0
	float32 m_flDepthOffset; // 0x08E4
	uint32 m_unOwnerContext; // 0x08E8
	uint32 m_unHorizontalAlign; // 0x08EC
	uint32 m_unVerticalAlign; // 0x08F0
	uint32 m_unOrientation; // 0x08F4
	bool m_bAllowInteractionFromAllSceneWorlds; // 0x08F8
	CNetworkUtlVectorBase< CUtlSymbolLarge > m_vecCSSClasses; // 0x0900
	bool m_bOpaque; // 0x0918
	bool m_bNoDepth; // 0x0919
	bool m_bVisibleWhenParentNoDraw; // 0x091A
	bool m_bRenderBackface; // 0x091B
	bool m_bUseOffScreenIndicator; // 0x091C
	bool m_bExcludeFromSaveGames; // 0x091D
	bool m_bGrabbable; // 0x091E
	bool m_bOnlyRenderToTexture; // 0x091F
	bool m_bDisableMipGen; // 0x0920
	int32 m_nExplicitImageLayout; // 0x0924
	bool m_bIgnoreParentOrientation; // 0x0928
};
class CSoundEventSphereEntity : public CSoundEventEntity // server
{
	float32 m_flRadius; // 0x0568
};
class CCSPlayerController_InGameMoneyServices : public CPlayerControllerComponent // server
{
	bool m_bReceivesMoneyNextRound; // 0x0040
	int32 m_iMoneyEarnedForNextRound; // 0x0044
	int32 m_iAccount; // 0x0048
	int32 m_iStartAccount; // 0x004C
	int32 m_iTotalCashSpent; // 0x0050
	int32 m_iCashSpentThisRound; // 0x0054
};
class CCSPlayer_AimPunchServices : public CPlayerPawnComponent // server
{
	GameTick_t m_predictableBaseTick; // 0x0048
	float32 m_predictableBaseTickInterpAmount; // 0x004C
	QAngle m_predictableBaseAngle; // 0x0050
	QAngle m_predictableBaseAngleVel; // 0x005C
	GameTick_t m_unpredictableBaseTick; // 0x00A0
	QAngle m_unpredictableBaseAngle; // 0x00A4
};
class CRuleBrushEntity : public CRuleEntity // server
{
};
class CMapVetoPickController : public CBaseEntity // server
{
	bool m_bPlayedIntroVcd; // 0x04A8
	bool m_bNeedToPlayFiveSecondsRemaining; // 0x04A9
	float64 m_dblPreMatchDraftSequenceTime; // 0x04C8
	bool m_bPreMatchDraftStateChanged; // 0x04D0
	int32 m_nDraftType; // 0x04D4
	int32 m_nTeamWinningCoinToss; // 0x04D8
	int32[64] m_nTeamWithFirstChoice; // 0x04DC
	int32[7] m_nVoteMapIdsList; // 0x05DC
	int32[64] m_nAccountIDs; // 0x05F8
	int32[64] m_nMapId0; // 0x06F8
	int32[64] m_nMapId1; // 0x07F8
	int32[64] m_nMapId2; // 0x08F8
	int32[64] m_nMapId3; // 0x09F8
	int32[64] m_nMapId4; // 0x0AF8
	int32[64] m_nMapId5; // 0x0BF8
	int32[64] m_nStartingSide0; // 0x0CF8
	int32 m_nCurrentPhase; // 0x0DF8
	int32 m_nPhaseStartTick; // 0x0DFC
	int32 m_nPhaseDurationTicks; // 0x0E00
	CEntityOutputTemplate< CUtlSymbolLarge > m_OnMapVetoed; // 0x0E08
	CEntityOutputTemplate< CUtlSymbolLarge > m_OnMapPicked; // 0x0E28
	CEntityOutputTemplate< int32 > m_OnSidesPicked; // 0x0E48
	CEntityOutputTemplate< int32 > m_OnNewPhaseStarted; // 0x0E68
	CEntityOutputTemplate< int32 > m_OnLevelTransition; // 0x0E88
};
class CFuncPropRespawnZone : public CBaseEntity // server
{
};
class CFilterModel : public CBaseFilter // server
{
	CUtlSymbolLarge m_iFilterModel; // 0x04E0
};
class CWeaponP90 : public CCSWeaponBaseGun // server
{
};
class CNavSpaceInfo : public CPointEntity // server
{
};
class CPhysSlideConstraint : public CPhysConstraint // server
{
	VectorWS m_axisEnd; // 0x0510
	float32 m_slideFriction; // 0x051C
	float32 m_systemLoadScale; // 0x0520
	float32 m_initialOffset; // 0x0524
	bool m_bEnableLinearConstraint; // 0x0528
	bool m_bEnableAngularConstraint; // 0x0529
	float32 m_flMotorFrequency; // 0x052C
	float32 m_flMotorDampingRatio; // 0x0530
	bool m_bUseEntityPivot; // 0x0534
	ConstraintSoundInfo m_soundInfo; // 0x0538
};
class CPulseGameBlackboard : public CBaseEntity // server
{
	CUtlString m_strGraphName; // 0x04B0
	CUtlString m_strStateBlob; // 0x04B8
};
class CSoundEventEntityAlias_snd_event_point : public CSoundEventEntity // server
{
};
class CChoreoComponent // server
{
	CNetworkVarChainer __m_pChainEntity; // 0x0008
	CHandle< CBaseModelEntity > m_hOwner; // 0x0030
	int32 m_nExernalChoreoGraphCount; // 0x0034
	CGlobalSymbol m_sActiveExternalChoreoGraphSlotID; // 0x0038
	SceneEventId_t m_nNextSceneEventId; // 0x0070
	GameTime_t m_flAllowResponsesEndTime; // 0x0074
};
class CPulseCell_Value_RandomInt : public CPulseCell_BaseValue // pulse_runtime_lib
{
};
class CPointGamestatsCounter : public CPointEntity // server
{
	CUtlSymbolLarge m_strStatisticName; // 0x04A8
	bool m_bDisabled; // 0x04B0
};
class CTextureBasedAnimatable : public CBaseModelEntity // server
{
	bool m_bLoop; // 0x0770
	float32 m_flFPS; // 0x0774
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hPositionKeys; // 0x0778
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hRotationKeys; // 0x0780
	Vector m_vAnimationBoundsMin; // 0x0788
	Vector m_vAnimationBoundsMax; // 0x0794
	float32 m_flStartTime; // 0x07A0
	float32 m_flStartFrame; // 0x07A4
};
class CSprite : public CBaseModelEntity // server
{
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hSpriteMaterial; // 0x0770
	CHandle< CBaseEntity > m_hAttachedToEntity; // 0x0778
	AttachmentHandle_t m_nAttachment; // 0x077C
	float32 m_flSpriteFramerate; // 0x0780
	float32 m_flFrame; // 0x0784
	GameTime_t m_flDieTime; // 0x0788
	uint32 m_nBrightness; // 0x0798
	float32 m_flBrightnessDuration; // 0x079C
	float32 m_flSpriteScale; // 0x07A0
	float32 m_flScaleDuration; // 0x07A4
	bool m_bWorldSpaceScale; // 0x07A8
	float32 m_flGlowProxySize; // 0x07AC
	float32 m_flHDRColorScale; // 0x07B0
	GameTime_t m_flLastTime; // 0x07B4
	float32 m_flMaxFrame; // 0x07B8
	float32 m_flStartScale; // 0x07BC
	float32 m_flDestScale; // 0x07C0
	GameTime_t m_flScaleTimeStart; // 0x07C4
	int32 m_nStartBrightness; // 0x07C8
	int32 m_nDestBrightness; // 0x07CC
	GameTime_t m_flBrightnessTimeStart; // 0x07D0
	int32 m_nSpriteWidth; // 0x07D4
	int32 m_nSpriteHeight; // 0x07D8
	float32 m_flSpeed; // 0x07DC
};
class CBaseMoveBehavior : public CPathKeyFrame // server
{
	int32 m_iPositionInterpolator; // 0x04F0
	int32 m_iRotationInterpolator; // 0x04F4
	float32 m_flAnimStartTime; // 0x04F8
	float32 m_flAnimEndTime; // 0x04FC
	float32 m_flAverageSpeedAcrossFrame; // 0x0500
	CHandle< CPathKeyFrame > m_pCurrentKeyFrame; // 0x0504
	CHandle< CPathKeyFrame > m_pTargetKeyFrame; // 0x0508
	CHandle< CPathKeyFrame > m_pPreKeyFrame; // 0x050C
	CHandle< CPathKeyFrame > m_pPostKeyFrame; // 0x0510
	float32 m_flTimeIntoFrame; // 0x0514
	int32 m_iDirection; // 0x0518
};
class CDynamicLight : public CBaseModelEntity // server
{
	uint8 m_ActualFlags; // 0x0770
	uint8 m_Flags; // 0x0771
	uint8 m_LightStyle; // 0x0772
	bool m_On; // 0x0773
	float32 m_Radius; // 0x0774
	int32 m_Exponent; // 0x0778
	float32 m_InnerAngle; // 0x077C
	float32 m_OuterAngle; // 0x0780
	float32 m_SpotRadius; // 0x0784
};
class CWeaponTaser : public CCSWeaponBaseGun // server
{
	GameTime_t m_fFireTime; // 0x1070
	int32 m_nLastAttackTick; // 0x1074
};
class CEnvCubemapBox : public CEnvCubemap // server
{
};
class CRotDoor : public CBaseDoor // server
{
	bool m_bSolidBsp; // 0x0978
};
class CPathMover : public CPathWithDynamicNodes // server
{
	CUtlVector< CHandle< CFuncMover > > m_vecMovers; // 0x05F0
	CUtlVector< CHandle< CPathMoverEntitySpawner > > m_vecSpawners; // 0x0608
	CUtlSymbolLarge m_iszMoverSpawnerName; // 0x0620
	CHandle< CFuncMoverRouter > m_hMoverRouter; // 0x0628
	CUtlSymbolLarge m_iszMoverRouterName; // 0x0630
	float32 m_flSampleSpacing; // 0x0638
};
class CFuncVPhysicsClip : public CBaseModelEntity // server
{
	bool m_bDisabled; // 0x0770
};
class CPhysFixed : public CPhysConstraint // server
{
	float32 m_flLinearFrequency; // 0x0508
	float32 m_flLinearDampingRatio; // 0x050C
	float32 m_flAngularFrequency; // 0x0510
	float32 m_flAngularDampingRatio; // 0x0514
	bool m_bEnableLinearConstraint; // 0x0518
	bool m_bEnableAngularConstraint; // 0x0519
	CUtlSymbolLarge m_sBoneName1; // 0x0520
	CUtlSymbolLarge m_sBoneName2; // 0x0528
};
class CLogicNavigation : public CLogicalEntity // server
{
	bool m_isOn; // 0x04B0
	navproperties_t m_navProperty; // 0x04B4
};
class CPathSimple : public CBaseEntity // server
{
	CPathQueryComponent m_CPathQueryComponent; // 0x04B0
	CUtlString m_pathString; // 0x05A0
	bool m_bClosedLoop; // 0x05A8
};
class CPathParticleRopeAlias_path_particle_rope_clientside : public CPathParticleRope // server
{
};
class CCSPointPulseAPI // server
{
};
class CEnvWindVolume : public CBaseEntity // server
{
	bool m_bActive; // 0x04A8
	Vector m_vBoxMins; // 0x04AC
	Vector m_vBoxMaxs; // 0x04B8
	bool m_bStartDisabled; // 0x04C4
	int32 m_nShape; // 0x04C8
	float32 m_fWindSpeedMultiplier; // 0x04CC
	float32 m_fWindTurbulenceMultiplier; // 0x04D0
	float32 m_fWindSpeedVariationMultiplier; // 0x04D4
	float32 m_fWindDirectionVariationMultiplier; // 0x04D8
};
class CFuncElectrifiedVolume : public CFuncBrush // server
{
	CUtlSymbolLarge m_EffectName; // 0x0790
	CUtlSymbolLarge m_EffectInterpenetrateName; // 0x0798
	CUtlSymbolLarge m_EffectZapName; // 0x07A0
	CUtlSymbolLarge m_iszEffectSource; // 0x07A8
};
class CCSMinimapBoundary : public CBaseEntity // server
{
};
class EntitySpottedState_t // server
{
	bool m_bSpotted; // 0x0008
	uint32[2] m_bSpottedByMask; // 0x000C
};
class fogparams_t // server
{
	Vector dirPrimary; // 0x0008
	Color colorPrimary; // 0x0014
	Color colorSecondary; // 0x0018
	Color colorPrimaryLerpTo; // 0x001C
	Color colorSecondaryLerpTo; // 0x0020
	float32 start; // 0x0024
	float32 end; // 0x0028
	float32 farz; // 0x002C
	float32 maxdensity; // 0x0030
	float32 exponent; // 0x0034
	float32 HDRColorScale; // 0x0038
	float32 skyboxFogFactor; // 0x003C
	float32 skyboxFogFactorLerpTo; // 0x0040
	float32 startLerpTo; // 0x0044
	float32 endLerpTo; // 0x0048
	float32 maxdensityLerpTo; // 0x004C
	GameTime_t lerptime; // 0x0050
	float32 duration; // 0x0054
	float32 blendtobackground; // 0x0058
	float32 scattering; // 0x005C
	float32 locallightscale; // 0x0060
	bool enable; // 0x0064
	bool blend; // 0x0065
	bool m_bPadding2; // 0x0066
	bool m_bPadding; // 0x0067
};
class CSoundEventOBBEntity : public CSoundEventEntity // server
{
	Vector m_vMins; // 0x0568
	Vector m_vMaxs; // 0x0574
};
class CBaseEntity_SharedAPI // server
{
};
class CFlashbangProjectile : public CBaseCSGrenadeProjectile // server
{
	float32 m_flTimeToDetonate; // 0x0A60
	uint8 m_numOpponentsHit; // 0x0A64
	uint8 m_numTeammatesHit; // 0x0A65
};
class CTriggerMultiple : public CBaseTrigger // server
{
	CEntityIOOutput m_OnTrigger; // 0x08E8
};
class CPhysBallSocket : public CPhysConstraint // server
{
	float32 m_flJointFriction; // 0x0508
	bool m_bEnableSwingLimit; // 0x050C
	float32 m_flSwingLimit; // 0x0510
	bool m_bEnableTwistLimit; // 0x0514
	float32 m_flMinTwistAngle; // 0x0518
	float32 m_flMaxTwistAngle; // 0x051C
};
class CDebugHistory : public CBaseEntity // server
{
	int32 m_nNpcEvents; // 0x3E84E8
};
class CSoundOpvarSetPointBase : public CBaseEntity // server
{
	bool m_bDisabled; // 0x04A8
	CEntityHandle m_hSource; // 0x04AC
	CUtlSymbolLarge m_iszSourceEntityName; // 0x04C8
	VectorWS m_vLastPosition; // 0x0520
	float32 m_flRefreshTime; // 0x052C
	CUtlSymbolLarge m_iszStackName; // 0x0530
	CUtlSymbolLarge m_iszOperatorName; // 0x0538
	CUtlSymbolLarge m_iszOpvarName; // 0x0540
	int32 m_iOpvarIndex; // 0x0548
	bool m_bUseAutoCompare; // 0x054C
	bool m_bFastRefresh; // 0x054D
};
class CExplosionTypeData // server
{
	CSoundEventName m_SoundName; // 0x0000
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > > m_ParticleEffect; // 0x0010
	bool m_bIsIncindiary; // 0x00F0
	bool m_bHasForces; // 0x00F1
	CGlobalSymbol m_DecalType; // 0x00F8
};
class CPathKeyFrame : public CLogicalEntity // server
{
	Vector m_Origin; // 0x04A8
	QAngle m_Angles; // 0x04B4
	Quaternion m_qAngle; // 0x04C0
	CUtlSymbolLarge m_iNextKey; // 0x04D0
	float32 m_flNextTime; // 0x04D8
	CHandle< CPathKeyFrame > m_pNextKey; // 0x04DC
	CHandle< CPathKeyFrame > m_pPrevKey; // 0x04E0
	float32 m_flMoveSpeed; // 0x04E4
};
class CCSPlayerController_API // server
{
};
class CWeaponCZ75a : public CCSWeaponBaseGun // server
{
	bool m_bMagazineRemoved; // 0x1070
};
class CScriptTriggerPush : public CTriggerPush // server
{
	Vector m_vExtent; // 0x0920
};
class CRevertSaved : public CModelPointEntity // server
{
	float32 m_loadTime; // 0x0770
	float32 m_Duration; // 0x0774
	float32 m_HoldTime; // 0x0778
};
class CPulseEnumlib // pulse_runtime_lib
{
};
class CTriggerBombReset : public CBaseTrigger // server
{
};
class CTriggerHurt : public CBaseTrigger // server
{
	float32 m_flOriginalDamage; // 0x08E8
	float32 m_flDamage; // 0x08EC
	float32 m_flDamageCap; // 0x08F0
	GameTime_t m_flLastDmgTime; // 0x08F4
	float32 m_flForgivenessDelay; // 0x08F8
	DamageTypes_t m_bitsDamageInflict; // 0x08FC
	int32 m_damageModel; // 0x0900
	bool m_bNoDmgForce; // 0x0904
	Vector m_vDamageForce; // 0x0908
	bool m_thinkAlways; // 0x0914
	float32 m_hurtThinkPeriod; // 0x0918
	CEntityIOOutput m_OnHurt; // 0x0920
	CEntityIOOutput m_OnHurtPlayer; // 0x0938
	CUtlVector< CHandle< CBaseEntity > > m_hurtEntities; // 0x0950
};
class CCSPlayer_WeaponServices : public CPlayer_WeaponServices // server
{
	GameTime_t m_flNextAttack; // 0x00C0
	CHandle< CBasePlayerWeapon > m_hSavedWeapon; // 0x00C4
	int32 m_nTimeToMelee; // 0x00C8
	int32 m_nTimeToSecondary; // 0x00CC
	int32 m_nTimeToPrimary; // 0x00D0
	int32 m_nTimeToSniperRifle; // 0x00D4
	bool m_bIsBeingGivenItem; // 0x00D8
	bool m_bIsPickingUpItemWithUse; // 0x00D9
	bool m_bPickedUpWeapon; // 0x00DA
	bool m_bDisableAutoDeploy; // 0x00DB
	bool m_bIsPickingUpGroundWeapon; // 0x00DC
	CNetworkUtlVectorBase< uint8 > m_networkAnimTiming; // 0x1860
	bool m_bBlockInspectUntilNextGraphUpdate; // 0x1878
};
class CRetakeGameRules // server
{
	int32 m_nMatchSeed; // 0x0138
	bool m_bBlockersPresent; // 0x013C
	bool m_bRoundInProgress; // 0x013D
	int32 m_iFirstSecondHalfRound; // 0x0140
	int32 m_iBombSite; // 0x0144
	CHandle< CCSPlayerPawn > m_hBombPlanter; // 0x0148
};
class CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable : public CEnvSoundscapeTriggerable // server
{
};
class CInfoInstructorHintBombTargetA : public CPointEntity // server
{
};
class CTeamplayRules : public CMultiplayRules // server
{
};
class CScriptTriggerHurt : public CTriggerHurt // server
{
	Vector m_vExtent; // 0x0970
};
class CCSGO_WingmanIntroCharacterPosition : public CCSGO_TeamIntroCharacterPosition // server
{
};
class SpawnPoint_API // server
{
};
class CWeaponMP9 : public CCSWeaponBaseGun // server
{
};
class CTriggerDetectExplosion : public CBaseTrigger // server
{
	CEntityIOOutput m_OnDetectedExplosion; // 0x0910
};
class CFilterName : public CBaseFilter // server
{
	CUtlSymbolLarge m_iFilterName; // 0x04E0
};
class CSmokeGrenadeProjectile : public CBaseCSGrenadeProjectile // server
{
	int32 m_nSmokeEffectTickBegin; // 0x0A88
	bool m_bDidSmokeEffect; // 0x0A8C
	int32 m_nRandomSeed; // 0x0A90
	Vector m_vSmokeColor; // 0x0A94
	VectorWS m_vSmokeDetonationPos; // 0x0AA0
	CNetworkUtlVectorBase< uint8 > m_VoxelFrameData; // 0x0AB0
	int32 m_nVoxelFrameDataSize; // 0x0AC8
	int32 m_nVoxelUpdate; // 0x0ACC
	GameTime_t m_flLastBounce; // 0x0AD0
	GameTime_t m_fllastSimulationTime; // 0x0AD4
	bool m_bExplodeFromInferno; // 0x2D58
	bool m_bDidGroundScorch; // 0x2D59
};
class CBlood : public CPointEntity // server
{
	QAngle m_vecSprayAngles; // 0x04A8
	Vector m_vecSprayDir; // 0x04B4
	float32 m_flAmount; // 0x04C0
	BloodType m_Color; // 0x04C4
};
class CCSTeam : public CTeam // server
{
	int32 m_nLastRecievedShorthandedRoundBonus; // 0x0560
	int32 m_nShorthandedRoundBonusStartRound; // 0x0564
	bool m_bSurrendered; // 0x0568
	char[512] m_szTeamMatchStat; // 0x0569
	int32 m_numMapVictories; // 0x076C
	int32 m_scoreFirstHalf; // 0x0770
	int32 m_scoreSecondHalf; // 0x0774
	int32 m_scoreOvertime; // 0x0778
	char[129] m_szClanTeamname; // 0x077C
	uint32 m_iClanID; // 0x0800
	char[8] m_szTeamFlagImage; // 0x0804
	char[8] m_szTeamLogoImage; // 0x080C
	float32 m_flNextResourceTime; // 0x0814
	int32 m_iLastUpdateSentAt; // 0x0818
};
class CRulePointEntity : public CRuleEntity // server
{
	int32 m_Score; // 0x0778
};
class CPulse_CallInfo // pulse_runtime_lib
{
	PulseSymbol_t m_PortName; // 0x0000
	PulseDocNodeID_t m_nEditorNodeID; // 0x0010
	PulseRegisterMap_t m_RegisterMap; // 0x0018
	PulseDocNodeID_t m_CallMethodID; // 0x0048
	PulseRuntimeChunkIndex_t m_nSrcChunk; // 0x004C
	int32 m_nSrcInstruction; // 0x0050
};
class CFuncMoveLinearAlias_momentary_door : public CFuncMoveLinear // server
{
};
class CBaseAnimGraph : public CBaseModelEntity // server
{
	CAnimGraphControllerManager m_graphControllerManager; // 0x0770
	CAnimGraphControllerPtr m_pMainGraphController; // 0x0808
	bool m_bInitiallyPopulateInterpHistory; // 0x0810
	CEntityOutputTemplate< float32 > m_OnLayerCycleUpdated; // 0x0818
	CEntityIOOutput m_OnExternalChoreoGraphChanged; // 0x0838
	IChoreoServices* m_pChoreoServices; // 0x0850
	bool m_bAnimGraphUpdateEnabled; // 0x0858
	bool m_bAnimationUpdateScheduled; // 0x0859
	Vector m_vecForce; // 0x085C
	int32 m_nForceBone; // 0x0868
	IPhysicsRagdollControl* m_pRagdollControl; // 0x0878
	PhysicsRagdollPose_t m_RagdollPose; // 0x0880
	bool m_bRagdollEnabled; // 0x08A8
	bool m_bRagdollClientSide; // 0x08A9
	CTransform m_xParentedRagdollRootInEntitySpace; // 0x08B0
};
class CEnvCubemapFog : public CBaseEntity // server
{
	float32 m_flEndDistance; // 0x04A8
	float32 m_flStartDistance; // 0x04AC
	float32 m_flFogFalloffExponent; // 0x04B0
	bool m_bHeightFogEnabled; // 0x04B4
	float32 m_flFogHeightWidth; // 0x04B8
	float32 m_flFogHeightEnd; // 0x04BC
	float32 m_flFogHeightStart; // 0x04C0
	float32 m_flFogHeightExponent; // 0x04C4
	float32 m_flLODBias; // 0x04C8
	bool m_bActive; // 0x04CC
	bool m_bStartDisabled; // 0x04CD
	float32 m_flFogMaxOpacity; // 0x04D0
	int32 m_nCubemapSourceType; // 0x04D4
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hSkyMaterial; // 0x04D8
	CUtlSymbolLarge m_iszSkyEntity; // 0x04E0
	int32 m_nHeightFogType; // 0x04E8
	int32 m_nFogHeightBlendMode; // 0x04EC
	int32 m_nFogHeightCoordinateSpace; // 0x04F0
	int32 m_nDistanceFogType; // 0x04F4
	CUtlSymbolLarge m_DistanceFogCurveString; // 0x04F8
	CUtlSymbolLarge m_HeightFogCurveString; // 0x0500
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hFogCubemapTexture; // 0x0598
	bool m_bHasHeightFogEnd; // 0x05A0
	bool m_bFirstTime; // 0x05A1
};
class CMapVetoPickController_API // server
{
};
class CPulseCell_InlineNodeSkipSelector : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseDocNodeID_t m_nFlowNodeID; // 0x0048
	bool m_bAnd; // 0x004C
	PulseSelectorOutflowList_t m_PassOutflow; // 0x0050
	CPulse_OutflowConnection m_FailOutflow; // 0x0068
};
class CBaseDoor : public CBaseToggle // server
{
	QAngle m_angMoveEntitySpace; // 0x0800
	Vector m_vecMoveDirParentSpace; // 0x080C
	locksound_t m_ls; // 0x0818
	bool m_bForceClosed; // 0x0838
	bool m_bDoorGroup; // 0x0839
	bool m_bLocked; // 0x083A
	bool m_bIgnoreDebris; // 0x083B
	bool m_bNoNPCs; // 0x083C
	FuncDoorSpawnPos_t m_eSpawnPosition; // 0x0840
	float32 m_flBlockDamage; // 0x0844
	CGameSoundEventName m_NoiseMoving; // 0x0848
	CGameSoundEventName m_NoiseArrived; // 0x0850
	CGameSoundEventName m_NoiseMovingClosed; // 0x0858
	CGameSoundEventName m_NoiseArrivedClosed; // 0x0860
	CUtlSymbolLarge m_ChainTarget; // 0x0868
	CEntityIOOutput m_OnBlockedClosing; // 0x0870
	CEntityIOOutput m_OnBlockedOpening; // 0x0888
	CEntityIOOutput m_OnUnblockedClosing; // 0x08A0
	CEntityIOOutput m_OnUnblockedOpening; // 0x08B8
	CEntityIOOutput m_OnFullyClosed; // 0x08D0
	CEntityIOOutput m_OnFullyOpen; // 0x08E8
	CEntityIOOutput m_OnClose; // 0x0900
	CEntityIOOutput m_OnOpen; // 0x0918
	CEntityIOOutput m_OnLockedUse; // 0x0930
	bool m_bLoopMoveSound; // 0x0948
	bool m_bCreateNavObstacle; // 0x0968
	float32 m_flSpeed; // 0x096C
	bool m_isChaining; // 0x0970
	bool m_bIsUsable; // 0x0971
};
class CBarnLightAPI // server
{
};
class CServerOnlyPointEntity : public CServerOnlyEntity // server
{
};
class CGameMoney : public CRulePointEntity // server
{
	CEntityIOOutput m_OnMoneySpent; // 0x0780
	CEntityIOOutput m_OnMoneySpentFail; // 0x0798
	int32 m_nMoney; // 0x07B0
	CUtlString m_strAwardText; // 0x07B8
};
class CFlashbangProjectile_API // server
{
};
class CEnvHudHint : public CPointEntity // server
{
	CUtlSymbolLarge m_iszMessage; // 0x04A8
};
class CNullEntity : public CBaseEntity // server
{
};
class CLogicalEntity : public CServerOnlyEntity // server
{
};
class CItemDefuser : public CItem // server
{
	EntitySpottedState_t m_entitySpottedState; // 0x0A00
	int32 m_nSpotRules; // 0x0A18
};
class CItemGenericTriggerHelper : public CBaseModelEntity // server
{
	CHandle< CItemGeneric > m_hParentItem; // 0x0770
};
class CPlayer_WeaponServices : public CPlayerPawnComponent // server
{
	CNetworkUtlVectorBase< CHandle< CBasePlayerWeapon > > m_hMyWeapons; // 0x0048
	CHandle< CBasePlayerWeapon > m_hActiveWeapon; // 0x0060
	CHandle< CBasePlayerWeapon > m_hLastWeapon; // 0x0064
	uint16[32] m_iAmmo; // 0x0068
	bool m_bPreventWeaponPickup; // 0x00A8
};
class CRagdollPropAttached : public CRagdollProp // server
{
	uint32 m_boneIndexAttached; // 0x0B20
	uint32 m_ragdollAttachedObjectIndex; // 0x0B24
	Vector m_attachmentPointBoneSpace; // 0x0B28
	Vector m_attachmentPointRagdollSpace; // 0x0B34
	bool m_bShouldDetach; // 0x0B40
	bool m_bShouldDeleteAttachedActivationRecord; // 0x0B50
};
class CItemDogtags : public CItem // server
{
	CHandle< CCSPlayerPawn > m_OwningPlayer; // 0x0A00
	CHandle< CCSPlayerPawn > m_KillingPlayer; // 0x0A04
};
class CFuncPlat : public CBasePlatTrain // server
{
	float32 m_flSpeed; // 0x0818
	CUtlSymbolLarge m_sNoise; // 0x0820
};
class CBarnLight : public CBaseModelEntity // server
{
	bool m_bEnabled; // 0x0770
	int32 m_nColorMode; // 0x0774
	Color m_Color; // 0x0778
	float32 m_flColorTemperature; // 0x077C
	float32 m_flBrightness; // 0x0780
	float32 m_flBrightnessScale; // 0x0784
	int32 m_nDirectLight; // 0x0788
	int32 m_nBakedShadowIndex; // 0x078C
	int32 m_nLightPathUniqueId; // 0x0790
	int32 m_nLightMapUniqueId; // 0x0794
	int32 m_nLuminaireShape; // 0x0798
	float32 m_flLuminaireSize; // 0x079C
	float32 m_flLuminaireAnisotropy; // 0x07A0
	CUtlString m_LightStyleString; // 0x07A8
	GameTime_t m_flLightStyleStartTime; // 0x07B0
	CNetworkUtlVectorBase< CUtlString > m_QueuedLightStyleStrings; // 0x07B8
	CNetworkUtlVectorBase< CUtlString > m_LightStyleEvents; // 0x07D0
	CNetworkUtlVectorBase< CHandle< CBaseModelEntity > > m_LightStyleTargets; // 0x07E8
	CEntityIOOutput[4] m_StyleEvent; // 0x0800
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hLightCookie; // 0x0880
	float32 m_flShape; // 0x0888
	float32 m_flSoftX; // 0x088C
	float32 m_flSoftY; // 0x0890
	float32 m_flSkirt; // 0x0894
	float32 m_flSkirtNear; // 0x0898
	Vector m_vSizeParams; // 0x089C
	float32 m_flRange; // 0x08A8
	Vector m_vShear; // 0x08AC
	int32 m_nBakeSpecularToCubemaps; // 0x08B8
	Vector m_vBakeSpecularToCubemapsSize; // 0x08BC
	float32 m_flBakeSpecularToCubemapsScale; // 0x08C8
	int32 m_nCastShadows; // 0x08CC
	int32 m_nShadowMapSize; // 0x08D0
	int32 m_nShadowPriority; // 0x08D4
	bool m_bContactShadow; // 0x08D8
	bool m_bForceShadowsEnabled; // 0x08D9
	int32 m_nBounceLight; // 0x08DC
	float32 m_flBounceScale; // 0x08E0
	float32 m_flMinRoughness; // 0x08E4
	Vector m_vAlternateColor; // 0x08E8
	float32 m_fAlternateColorBrightness; // 0x08F4
	int32 m_nFog; // 0x08F8
	float32 m_flFogStrength; // 0x08FC
	int32 m_nFogShadows; // 0x0900
	float32 m_flFogScale; // 0x0904
	float32 m_flFadeSizeStart; // 0x0908
	float32 m_flFadeSizeEnd; // 0x090C
	float32 m_flShadowFadeSizeStart; // 0x0910
	float32 m_flShadowFadeSizeEnd; // 0x0914
	bool m_bPrecomputedFieldsValid; // 0x0918
	Vector m_vPrecomputedBoundsMins; // 0x091C
	Vector m_vPrecomputedBoundsMaxs; // 0x0928
	Vector m_vPrecomputedOBBOrigin; // 0x0934
	QAngle m_vPrecomputedOBBAngles; // 0x0940
	Vector m_vPrecomputedOBBExtent; // 0x094C
	int32 m_nPrecomputedSubFrusta; // 0x0958
	Vector m_vPrecomputedOBBOrigin0; // 0x095C
	QAngle m_vPrecomputedOBBAngles0; // 0x0968
	Vector m_vPrecomputedOBBExtent0; // 0x0974
	Vector m_vPrecomputedOBBOrigin1; // 0x0980
	QAngle m_vPrecomputedOBBAngles1; // 0x098C
	Vector m_vPrecomputedOBBExtent1; // 0x0998
	Vector m_vPrecomputedOBBOrigin2; // 0x09A4
	QAngle m_vPrecomputedOBBAngles2; // 0x09B0
	Vector m_vPrecomputedOBBExtent2; // 0x09BC
	Vector m_vPrecomputedOBBOrigin3; // 0x09C8
	QAngle m_vPrecomputedOBBAngles3; // 0x09D4
	Vector m_vPrecomputedOBBExtent3; // 0x09E0
	Vector m_vPrecomputedOBBOrigin4; // 0x09EC
	QAngle m_vPrecomputedOBBAngles4; // 0x09F8
	Vector m_vPrecomputedOBBExtent4; // 0x0A04
	Vector m_vPrecomputedOBBOrigin5; // 0x0A10
	QAngle m_vPrecomputedOBBAngles5; // 0x0A1C
	Vector m_vPrecomputedOBBExtent5; // 0x0A28
	bool m_bPvsModifyEntity; // 0x0A34
	bool m_bTransmitAlways; // 0x0A35
	CNetworkUtlVectorBase< uint16 > m_VisClusters; // 0x0A38
};
class CInstructorEventEntity : public CPointEntity // server
{
	CUtlSymbolLarge m_iszName; // 0x04A8
	CUtlSymbolLarge m_iszHintTargetEntity; // 0x04B0
	CHandle< CBasePlayerPawn > m_hTargetPlayer; // 0x04B8
};
class CWeaponTec9 : public CCSWeaponBaseGun // server
{
};
class CPathCorner : public CPointEntity // server
{
	float32 m_flSpeed; // 0x04A8
	float32 m_flWait; // 0x04AC
	float32 m_flRadius; // 0x04B0
	CEntityIOOutput m_OnPass; // 0x04B8
};
class CTriggerSndSosOpvar : public CBaseTrigger // server
{
	CUtlVector< CHandle< CBaseEntity > > m_hTouchingPlayers; // 0x08E8
	VectorWS m_flPosition; // 0x0900
	float32 m_flCenterSize; // 0x090C
	float32 m_flMinVal; // 0x0910
	float32 m_flMaxVal; // 0x0914
	CUtlSymbolLarge m_opvarName; // 0x0918
	CUtlSymbolLarge m_stackName; // 0x0920
	CUtlSymbolLarge m_operatorName; // 0x0928
	bool m_bVolIs2D; // 0x0930
	char[256] m_opvarNameChar; // 0x0931
	char[256] m_stackNameChar; // 0x0A31
	char[256] m_operatorNameChar; // 0x0B31
	Vector m_VecNormPos; // 0x0C34
	float32 m_flNormCenterSize; // 0x0C40
};
class CPulseCell_LimitCount : public CPulseCell_BaseRequirement // pulse_runtime_lib
{
	int32 m_nLimitCount; // 0x0048
};
class CPulseCell_Step_CallExternalMethod : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	PulseSymbol_t m_MethodName; // 0x00D8
	PulseRuntimeBlackboardReferenceIndex_t m_nBlackboardIndex; // 0x00E8
	CUtlLeanVector< CPulseRuntimeMethodArg > m_ExpectedArgs; // 0x00F0
	PulseMethodCallMode_t m_nAsyncCallMode; // 0x0100
	CPulse_ResumePoint m_OnFinished; // 0x0108
};
class CPointCommentaryNode : public CBaseAnimGraph // server
{
	CUtlSymbolLarge m_iszPreCommands; // 0x0960
	CUtlSymbolLarge m_iszPostCommands; // 0x0968
	CUtlSymbolLarge m_iszCommentaryFile; // 0x0970
	CUtlSymbolLarge m_iszViewTarget; // 0x0978
	CHandle< CBaseEntity > m_hViewTarget; // 0x0980
	CHandle< CBaseEntity > m_hViewTargetAngles; // 0x0984
	CUtlSymbolLarge m_iszViewPosition; // 0x0988
	CHandle< CBaseEntity > m_hViewPosition; // 0x0990
	CHandle< CBaseEntity > m_hViewPositionMover; // 0x0994
	bool m_bPreventMovement; // 0x0998
	bool m_bUnderCrosshair; // 0x0999
	bool m_bUnstoppable; // 0x099A
	GameTime_t m_flFinishedTime; // 0x099C
	VectorWS m_vecFinishOrigin; // 0x09A0
	QAngle m_vecOriginalAngles; // 0x09AC
	QAngle m_vecFinishAngles; // 0x09B8
	bool m_bPreventChangesWhileMoving; // 0x09C4
	bool m_bDisabled; // 0x09C5
	VectorWS m_vecTeleportOrigin; // 0x09C8
	GameTime_t m_flAbortedPlaybackAt; // 0x09D4
	CEntityIOOutput m_pOnCommentaryStarted; // 0x09D8
	CEntityIOOutput m_pOnCommentaryStopped; // 0x09F0
	bool m_bActive; // 0x0A08
	GameTime_t m_flStartTime; // 0x0A0C
	float32 m_flStartTimeInCommentary; // 0x0A10
	CUtlSymbolLarge m_iszTitle; // 0x0A18
	CUtlSymbolLarge m_iszSpeakers; // 0x0A20
	int32 m_iNodeNumber; // 0x0A28
	int32 m_iNodeNumberMax; // 0x0A2C
	bool m_bListenedTo; // 0x0A30
};
class CMomentaryRotButton : public CRotButton // server
{
	CEntityOutputTemplate< float32 > m_Position; // 0x08F0
	CEntityIOOutput m_OnUnpressed; // 0x0910
	CEntityIOOutput m_OnFullyOpen; // 0x0928
	CEntityIOOutput m_OnFullyClosed; // 0x0940
	CEntityIOOutput m_OnReachedPosition; // 0x0958
	int32 m_lastUsed; // 0x0970
	QAngle m_start; // 0x0974
	QAngle m_end; // 0x0980
	float32 m_IdealYaw; // 0x098C
	CUtlSymbolLarge m_sNoise; // 0x0990
	bool m_bUpdateTarget; // 0x0998
	int32 m_direction; // 0x099C
	float32 m_returnSpeed; // 0x09A0
	float32 m_flStartPosition; // 0x09A4
};
class CSceneListManager : public CLogicalEntity // server
{
	CUtlVector< CHandle< CSceneListManager > > m_hListManagers; // 0x04A8
	CUtlSymbolLarge[16] m_iszScenes; // 0x04C0
	CHandle< CBaseEntity >[16] m_hScenes; // 0x0540
};
class CEnvTilt : public CPointEntity // server
{
	float32 m_Duration; // 0x04A8
	float32 m_Radius; // 0x04AC
	float32 m_TiltTime; // 0x04B0
	GameTime_t m_stopTime; // 0x04B4
};
class CEnvSoundscapeTriggerable : public CEnvSoundscape // server
{
};
class CFuncMover : public CBaseModelEntity // server
{
	CUtlSymbolLarge m_iszPathName; // 0x0770
	CHandle< CPathMover > m_hPathMover; // 0x0778
	CHandle< CPathMover > m_hPrevPathMover; // 0x077C
	CUtlSymbolLarge m_iszPathNodeStart; // 0x0780
	CUtlSymbolLarge m_iszPathNodeEnd; // 0x0788
	bool m_bIgnoreEndNode; // 0x0790
	CFuncMover::Move_t m_eMoveType; // 0x0794
	bool m_bIsReversing; // 0x0798
	float32 m_flStartSpeed; // 0x079C
	float32 m_flPathLocation; // 0x07A0
	float32 m_flT; // 0x07A4
	int32 m_nCurrentNodeIndex; // 0x07A8
	int32 m_nPreviousNodeIndex; // 0x07AC
	SolidType_t m_eSolidType; // 0x07B0
	bool m_bIsMoving; // 0x07B1
	float32 m_flTimeToReachMaxSpeed; // 0x07B4
	float32 m_flDistanceToReachMaxSpeed; // 0x07B8
	float32 m_flTimeToReachZeroSpeed; // 0x07BC
	float32 m_flComputedDistanceToReachMaxSpeed; // 0x07C0
	float32 m_flComputedDistanceToReachZeroSpeed; // 0x07C4
	float32 m_flStartCurveScale; // 0x07C8
	float32 m_flStopCurveScale; // 0x07CC
	float32 m_flDistanceToReachZeroSpeed; // 0x07D0
	GameTime_t m_flTimeMovementStart; // 0x07D4
	GameTime_t m_flTimeMovementStop; // 0x07D8
	CHandle< CMoverPathNode > m_hStopAtNode; // 0x07DC
	float32 m_flPathLocationToBeginStop; // 0x07E0
	float32 m_flPathLocationStart; // 0x07E4
	float32 m_flBeginStopT; // 0x07E8
	CGameSoundEventName m_iszStartForwardSound; // 0x07F0
	CGameSoundEventName m_iszLoopForwardSound; // 0x07F8
	CGameSoundEventName m_iszStopForwardSound; // 0x0800
	CGameSoundEventName m_iszStartReverseSound; // 0x0808
	CGameSoundEventName m_iszLoopReverseSound; // 0x0810
	CGameSoundEventName m_iszStopReverseSound; // 0x0818
	CGameSoundEventName m_iszArriveAtDestinationSound; // 0x0820
	CEntityIOOutput m_OnMovementEnd; // 0x0840
	bool m_bStartAtClosestPoint; // 0x0858
	bool m_bStartAtEnd; // 0x0859
	bool m_bStartFollowingClosestMover; // 0x085A
	CFuncMover::OrientationUpdate_t m_eOrientationUpdate; // 0x085C
	GameTime_t m_flTimeStartOrientationChange; // 0x0860
	float32 m_flTimeToBlendToNewOrientation; // 0x0864
	float32 m_flDurationBlendToNewOrientationRan; // 0x0868
	bool m_bCreateMovableNavMesh; // 0x086C
	bool m_bCreateMovableSurfaceGraph; // 0x086D
	bool m_bAllowMovableNavMeshDockingOnEntireEntity; // 0x086E
	CEntityOutputTemplate< CUtlString > m_OnNodePassed; // 0x0870
	CUtlSymbolLarge m_iszOrientationMatchEntityName; // 0x0890
	CHandle< CBaseEntity > m_hOrientationMatchEntity; // 0x0898
	float32 m_flTimeToTraverseToNextNode; // 0x089C
	Vector m_vLerpToNewPosStartInPathEntitySpace; // 0x08A0
	Vector m_vLerpToNewPosEndInPathEntitySpace; // 0x08AC
	float32 m_flLerpToPositionT; // 0x08B8
	float32 m_flLerpToPositionDeltaT; // 0x08BC
	CEntityIOOutput m_OnLerpToPositionComplete; // 0x08C0
	bool m_bIsPaused; // 0x08D8
	CFuncMover::TransitionToPathNodeAction_t m_eTransitionedToPathNodeAction; // 0x08DC
	Quaternion m_qTransitionSourceOrientation; // 0x08E0
	int32 m_nDelayedTeleportToNode; // 0x08F0
	bool m_bIsImGuiLogging; // 0x08F4
	bool m_bIsImGuiEntTextLogging; // 0x08F5
	float32 m_flSpeed; // 0x08F8
	CHandle< CBaseEntity > m_hFollowEntity; // 0x08FC
	float32 m_flFollowDistance; // 0x0900
	float32 m_flFollowMinimumSpeed; // 0x0904
	float32 m_flCurFollowEntityT; // 0x0908
	float32 m_flCurFollowSpeed; // 0x090C
	CUtlSymbolLarge m_strOrientationFaceEntityName; // 0x0910
	CHandle< CBaseEntity > m_hOrientationFaceEntity; // 0x0918
	CEntityIOOutput m_OnStart; // 0x0920
	CEntityIOOutput m_OnStartForward; // 0x0938
	CEntityIOOutput m_OnStartReverse; // 0x0950
	CEntityIOOutput m_OnStop; // 0x0968
	CEntityIOOutput m_OnStopped; // 0x0980
	bool m_bNextNodeReturnsCurrent; // 0x0998
	bool m_bStartedMoving; // 0x0999
	CFuncMover::FollowEntityDirection_t m_eFollowEntityDirection; // 0x09B8
	CHandle< CFuncMover > m_hFollowMover; // 0x09BC
	CUtlSymbolLarge m_iszFollowEntityName; // 0x09C0
	CUtlSymbolLarge m_iszFollowMoverEntityName; // 0x09C8
	float32 m_flFollowMoverDistance; // 0x09D0
	float32 m_flFollowMoverRatio; // 0x09D4
	float32 m_flFollowMoverCalculatedDistance; // 0x09D8
	float32 m_flFollowMoverSpringStrength; // 0x09DC
	int32 m_nFollowMoverConstraintPriority; // 0x09E0
	Vector2D m_vecFollowMoverCouplerRange; // 0x09E4
	bool m_bFollowConstraintsInitialized; // 0x09EC
	CFuncMover::FollowConstraint_t m_eFollowConstraint; // 0x09F0
	float32 m_flFollowMoverSpeed; // 0x09F4
	float32 m_flFollowMoverVelocity; // 0x09F8
	GameTick_t m_nTickMovementRan; // 0x09FC
	FuncMoverMovementSummary_t m_movementSummary; // 0x0A00
	bool m_bStopFromBeginStopTarget; // 0x0A20
	bool m_bQueueStop; // 0x0A21
	bool m_bQueueStopMoving; // 0x0A22
	bool m_bQueueSetupPathMover; // 0x0A23
	CFuncMover::PathRebuildStrategy_t m_ePathRebuildStrategy; // 0x0A24
};
class CPhysicsProp : public CBreakableProp // server
{
	CEntityIOOutput m_MotionEnabled; // 0x0B00
	CEntityIOOutput m_OnAwakened; // 0x0B18
	CEntityIOOutput m_OnAwake; // 0x0B30
	CEntityIOOutput m_OnAsleep; // 0x0B48
	CEntityIOOutput m_OnPlayerUse; // 0x0B60
	CEntityIOOutput m_OnOutOfWorld; // 0x0B78
	CEntityIOOutput m_OnPlayerPickup; // 0x0B90
	bool m_bForceNavIgnore; // 0x0BA8
	bool m_bNoNavmeshBlocker; // 0x0BA9
	bool m_bForceNpcExclude; // 0x0BAA
	float32 m_massScale; // 0x0BAC
	float32 m_buoyancyScale; // 0x0BB0
	int32 m_damageType; // 0x0BB4
	int32 m_damageToEnableMotion; // 0x0BB8
	float32 m_flForceToEnableMotion; // 0x0BBC
	bool m_bThrownByPlayer; // 0x0BC0
	bool m_bDroppedByPlayer; // 0x0BC1
	bool m_bTouchedByPlayer; // 0x0BC2
	bool m_bFirstCollisionAfterLaunch; // 0x0BC3
	bool m_bHasBeenAwakened; // 0x0BC4
	bool m_bIsOverrideProp; // 0x0BC5
	GameTime_t m_flLastBurn; // 0x0BC8
	DynamicContinuousContactBehavior_t m_nDynamicContinuousContactBehavior; // 0x0BCC
	GameTime_t m_fNextCheckDisableMotionContactsTime; // 0x0BD0
	int32 m_iInitialGlowState; // 0x0BD4
	int32 m_nGlowRange; // 0x0BD8
	int32 m_nGlowRangeMin; // 0x0BDC
	Color m_glowColor; // 0x0BE0
	bool m_bShouldAutoConvertBackFromDebris; // 0x0BE4
	bool m_bMuteImpactEffects; // 0x0BE5
	INavObstacle::NavObstacleType_t m_nNavObstacleType; // 0x0BE8
	bool m_bUpdateNavWhenMoving; // 0x0BEC
	bool m_bForceNavObstacleCut; // 0x0BED
	bool m_bAllowObstacleConvexHullMerging; // 0x0BEE
	bool m_bAcceptDamageFromHeldObjects; // 0x0BEF
	bool m_bEnableUseOutput; // 0x0BF0
	CPhysicsProp::CrateType_t m_CrateType; // 0x0BF4
	CUtlSymbolLarge[4] m_strItemClass; // 0x0BF8
	int32[4] m_nItemCount; // 0x0C18
	bool m_bRemovableForAmmoBalancing; // 0x0C28
	bool m_bAwake; // 0x0C29
	bool m_bAttachedToReferenceFrame; // 0x0C2A
};
class CFuncNavObstruction : public CBaseModelEntity // server
{
	bool m_bDisabled; // 0x0788
	bool m_bUseAsyncObstacleUpdate; // 0x0789
};
class CPhysWheelConstraint : public CPhysConstraint // server
{
	float32 m_flSuspensionFrequency; // 0x0508
	float32 m_flSuspensionDampingRatio; // 0x050C
	float32 m_flSuspensionHeightOffset; // 0x0510
	bool m_bEnableSuspensionLimit; // 0x0514
	float32 m_flMinSuspensionOffset; // 0x0518
	float32 m_flMaxSuspensionOffset; // 0x051C
	bool m_bEnableSteeringLimit; // 0x0520
	float32 m_flMinSteeringAngle; // 0x0524
	float32 m_flMaxSteeringAngle; // 0x0528
	float32 m_flSteeringAxisFriction; // 0x052C
	float32 m_flSpinAxisFriction; // 0x0530
	CHandle< CBaseEntity > m_hSteeringMimicsEntity; // 0x0534
};
class CSkyboxReference : public CBaseEntity // server
{
	WorldGroupId_t m_worldGroupId; // 0x04A8
	CHandle< CSkyCamera > m_hSkyCamera; // 0x04AC
};
class CPointPulse : public CBaseEntity // server
{
};
class CCSPlayerPawn_API // server
{
};
class CMolotovProjectile : public CBaseCSGrenadeProjectile // server
{
	bool m_bIsIncGrenade; // 0x0A60
	bool m_bDetonated; // 0x0A78
	IntervalTimer m_stillTimer; // 0x0A80
};
class CFilterClass : public CBaseFilter // server
{
	CUtlSymbolLarge m_iFilterClass; // 0x04E0
};
class CPathWithDynamicNodes : public CPathSimple // server
{
	CNetworkUtlVectorBase< CHandle< CPathNode > > m_vecPathNodes; // 0x05B0
	CTransform m_xInitialPathWorldToLocal; // 0x05D0
};
class CColorCorrection : public CBaseEntity // server
{
	float32 m_flFadeInDuration; // 0x04A8
	float32 m_flFadeOutDuration; // 0x04AC
	float32 m_flStartFadeInWeight; // 0x04B0
	float32 m_flStartFadeOutWeight; // 0x04B4
	GameTime_t m_flTimeStartFadeIn; // 0x04B8
	GameTime_t m_flTimeStartFadeOut; // 0x04BC
	float32 m_flMaxWeight; // 0x04C0
	bool m_bStartDisabled; // 0x04C4
	bool m_bEnabled; // 0x04C5
	bool m_bMaster; // 0x04C6
	bool m_bClientSide; // 0x04C7
	bool m_bExclusive; // 0x04C8
	float32 m_MinFalloff; // 0x04CC
	float32 m_MaxFalloff; // 0x04D0
	float32 m_flCurWeight; // 0x04D4
	char[512] m_netlookupFilename; // 0x04D8
	CUtlSymbolLarge m_lookupFilename; // 0x06D8
};
class CPropDoorRotatingBreakable : public CPropDoorRotating // server
{
	bool m_bBreakable; // 0x0E40
	bool m_isAbleToCloseAreaPortals; // 0x0E41
	int32 m_currentDamageState; // 0x0E44
	CUtlVector< CUtlSymbolLarge > m_damageStates; // 0x0E48
};
class CLightDirectionalEntity : public CLightEntity // server
{
};
class CBaseClientUIEntity : public CBaseModelEntity // server
{
	bool m_bEnabled; // 0x0770
	CUtlSymbolLarge m_DialogXMLName; // 0x0778
	CUtlSymbolLarge m_PanelClassName; // 0x0780
	CUtlSymbolLarge m_PanelID; // 0x0788
	CEntityOutputTemplate< CUtlString > m_CustomOutput0; // 0x0790
	CEntityOutputTemplate< CUtlString > m_CustomOutput1; // 0x07B0
	CEntityOutputTemplate< CUtlString > m_CustomOutput2; // 0x07D0
	CEntityOutputTemplate< CUtlString > m_CustomOutput3; // 0x07F0
	CEntityOutputTemplate< CUtlString > m_CustomOutput4; // 0x0810
	CEntityOutputTemplate< CUtlString > m_CustomOutput5; // 0x0830
	CEntityOutputTemplate< CUtlString > m_CustomOutput6; // 0x0850
	CEntityOutputTemplate< CUtlString > m_CustomOutput7; // 0x0870
	CEntityOutputTemplate< CUtlString > m_CustomOutput8; // 0x0890
	CEntityOutputTemplate< CUtlString > m_CustomOutput9; // 0x08B0
};
class CBreakable : public CBaseModelEntity // server
{
	CPropDataComponent m_CPropDataComponent; // 0x0778
	Materials m_Material; // 0x07B8
	CHandle< CBaseEntity > m_hBreaker; // 0x07BC
	Explosions m_Explosion; // 0x07C0
	CUtlSymbolLarge m_iszSpawnObject; // 0x07C8
	float32 m_flPressureDelay; // 0x07D0
	int32 m_iMinHealthDmg; // 0x07D4
	CUtlSymbolLarge m_iszPropData; // 0x07D8
	float32 m_impactEnergyScale; // 0x07E0
	EOverrideBlockLOS_t m_nOverrideBlockLOS; // 0x07E4
	CEntityIOOutput m_OnStartDeath; // 0x07E8
	CEntityIOOutput m_OnBreak; // 0x0800
	CEntityOutputTemplate< float32 > m_OnHealthChanged; // 0x0818
	PerformanceMode_t m_PerformanceMode; // 0x0838
	CHandle< CBasePlayerPawn > m_hPhysicsAttacker; // 0x083C
	GameTime_t m_flLastPhysicsInfluenceTime; // 0x0840
};
class CInfoLandmark : public CPointEntity // server
{
};
class CBaseFilter : public CLogicalEntity // server
{
	bool m_bNegated; // 0x04A8
	CEntityIOOutput m_OnPass; // 0x04B0
	CEntityIOOutput m_OnFail; // 0x04C8
};
class WeaponPurchaseTracker_t // server
{
	CUtlVectorEmbeddedNetworkVar< WeaponPurchaseCount_t > m_weaponPurchases; // 0x0008
};
class CPulseCell_Outflow_PlaySceneBase::CursorState_t // server
{
	CHandle< CBaseEntity > m_sceneInstance; // 0x0000
	CHandle< CBaseEntity > m_mainActor; // 0x0004
	CUtlHashtable< PulseCursorID_t, int32 > m_cursorIDToEventID; // 0x0008
};
class CMapInfo : public CPointEntity // server
{
	int32 m_iBuyingStatus; // 0x04A8
	float32 m_flBombRadius; // 0x04AC
	int32 m_iPetPopulation; // 0x04B0
	bool m_bUseNormalSpawnsForDM; // 0x04B4
	bool m_bDisableAutoGeneratedDMSpawns; // 0x04B5
	float32 m_flBotMaxVisionDistance; // 0x04B8
	int32 m_iHostageCount; // 0x04BC
	bool m_bFadePlayerVisibilityFarZ; // 0x04C0
	bool m_bRainTraceToSkyEnabled; // 0x04C1
	bool m_bGPUCullSkybox; // 0x04C2
	float32 m_flEnvRainStrength; // 0x04C4
	float32 m_flEnvPuddleRippleStrength; // 0x04C8
	float32 m_flEnvPuddleRippleDirection; // 0x04CC
	float32 m_flEnvWetnessCoverage; // 0x04D0
	float32 m_flEnvWetnessDryingAmount; // 0x04D4
};
class CGradientFog : public CBaseEntity // server
{
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hGradientFogTexture; // 0x04A8
	float32 m_flFogStartDistance; // 0x04B0
	float32 m_flFogEndDistance; // 0x04B4
	bool m_bHeightFogEnabled; // 0x04B8
	float32 m_flFogStartHeight; // 0x04BC
	float32 m_flFogEndHeight; // 0x04C0
	float32 m_flFarZ; // 0x04C4
	float32 m_flFogMaxOpacity; // 0x04C8
	float32 m_flFogFalloffExponent; // 0x04CC
	float32 m_flFogVerticalExponent; // 0x04D0
	Color m_fogColor; // 0x04D4
	float32 m_flFogStrength; // 0x04D8
	float32 m_flFadeTime; // 0x04DC
	bool m_bStartDisabled; // 0x04E0
	bool m_bIsEnabled; // 0x04E1
	bool m_bGradientFogNeedsTextures; // 0x04E2
};
class CSoundOpvarSetAABBEntity : public CSoundOpvarSetBoxEntity // server
{
};
class CPulseCell_Outflow_PlaySequence : public CPulseCell_Outflow_PlaySceneBase // server
{
	CUtlString m_ParamSequenceName; // 0x0138
};
class CPulseCell_Outflow_PlayDynamicVCD : public CPulseCell_Outflow_PlayVCDBase // server
{
};
class CPointClientUIWorldTextPanel : public CPointClientUIWorldPanel // server
{
	char[512] m_messageText; // 0x0930
};
class CEntityIdentity // entity2
{
	int32 m_nameStringTableIndex; // 0x0014
	CUtlSymbolLarge m_name; // 0x0018
	CUtlSymbolLarge m_designerName; // 0x0020
	uint32 m_flags; // 0x0030
	WorldGroupId_t m_worldGroupId; // 0x0038
	uint32 m_fDataObjectTypes; // 0x003C
	ChangeAccessorFieldPathIndex_t m_PathIndex; // 0x0040
	CEntityAttributeTable* m_pAttributes; // 0x0048
	CEntityIdentity* m_pPrev; // 0x0050
	CEntityIdentity* m_pNext; // 0x0058
	CEntityIdentity* m_pPrevByClass; // 0x0060
	CEntityIdentity* m_pNextByClass; // 0x0068
};
class CPulseCell_LimitCount::Criteria_t // pulse_runtime_lib
{
	bool m_bLimitCountPasses; // 0x0000
};
class CFuncRotator : public CBaseModelEntity // server
{
	CFuncRotator::Rotate_t m_eRotateType; // 0x0770
	bool m_bIsRotating; // 0x0774
	SolidType_t m_eSolidType; // 0x0775
	float32 m_flSpeed; // 0x0778
	float32 m_flTimeToCompleteRotation; // 0x077C
	CHandle< CBaseEntity > m_hRotatorTarget; // 0x0780
	CUtlSymbolLarge m_strRotatorTarget; // 0x0788
	CUtlVector< Quaternion > m_vecLocalRotationHistory; // 0x0790
	CEntityIOOutput m_OnRotationStarted; // 0x07A8
	CEntityIOOutput m_OnRotationCompleted; // 0x07C0
	CEntityIOOutput m_OnOscillate; // 0x07D8
	CEntityIOOutput m_OnOscillateStartArrive; // 0x07F0
	CEntityIOOutput m_OnOscillateStartDepart; // 0x0808
	CEntityIOOutput m_OnOscillateEndArrive; // 0x0820
	CEntityIOOutput m_OnOscillateEndDepart; // 0x0838
	GameTick_t m_nTickRotateRan; // 0x0850
	bool m_bStartedRotating; // 0x0854
	FuncRotatorRotationSummary_t m_rotationSummary; // 0x0858
	float32 m_flTimeToReachMaxSpeed; // 0x0860
	float32 m_flTimeToReachZeroSpeed; // 0x0864
	GameTime_t m_flTimeRotationStart; // 0x0868
	GameTime_t m_flTimeRotationStop; // 0x086C
	float32 m_flStartSpeed; // 0x0870
	Quaternion m_qSpawnOrientation; // 0x0880
	bool m_bRecordHistory; // 0x0890
	bool m_bReturningToPreviousRotation; // 0x0891
	bool m_bReturningToInitialRotation; // 0x0892
	float32 m_flMinYawRotation; // 0x0894
	float32 m_flMaxYawRotation; // 0x0898
	int32 m_nOscillationCount; // 0x089C
	bool m_bOscillationFromStart; // 0x08A0
	CGameSoundEventName m_iszStartSound; // 0x08A8
	CGameSoundEventName m_iszLoopSound; // 0x08B0
	CGameSoundEventName m_iszStopSound; // 0x08D0
	float32 m_flTargetAngle; // 0x08D8
	float32 m_flCurrentAngle; // 0x08DC
	CFuncRotator::RotationAxis_t m_eRotationAxis; // 0x08E0
	float32 m_flSpeedDriftFromOverRotate; // 0x08E4
};
class CSoundEventEntity : public CBaseEntity // server
{
	bool m_bStartOnSpawn; // 0x04A8
	bool m_bToLocalPlayer; // 0x04A9
	bool m_bStopOnNew; // 0x04AA
	bool m_bSaveRestore; // 0x04AB
	bool m_bSavedIsPlaying; // 0x04AC
	float32 m_flSavedElapsedTime; // 0x04B0
	CUtlSymbolLarge m_iszSourceEntityName; // 0x04B8
	CUtlSymbolLarge m_iszAttachmentName; // 0x04C0
	CEntityOutputTemplate< SndOpEventGuid_t > m_onGUIDChanged; // 0x04C8
	CEntityIOOutput m_onSoundFinished; // 0x04F8
	float32 m_flClientCullRadius; // 0x0510
	CUtlSymbolLarge m_iszSoundName; // 0x0540
	CEntityHandle m_hSource; // 0x055C
	int32 m_nEntityIndexSelection; // 0x0560
};
class CInfoPlayerCounterterrorist : public SpawnPoint // server
{
};
class CEnvFade : public CLogicalEntity // server
{
	Color m_fadeColor; // 0x04A8
	float32 m_Duration; // 0x04AC
	float32 m_HoldDuration; // 0x04B0
	CEntityIOOutput m_OnBeginFade; // 0x04B8
};
class CBasePlayerVData : public CEntitySubclassVDataBase // server
{
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCModel > > m_sModelName; // 0x0028
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCModel > > m_sModelNameAg2Override; // 0x0108
	CSkillFloat m_flHeadDamageMultiplier; // 0x01E8
	CSkillFloat m_flChestDamageMultiplier; // 0x01F8
	CSkillFloat m_flStomachDamageMultiplier; // 0x0208
	CSkillFloat m_flArmDamageMultiplier; // 0x0218
	CSkillFloat m_flLegDamageMultiplier; // 0x0228
	float32 m_flHoldBreathTime; // 0x0238
	float32 m_flDrowningDamageInterval; // 0x023C
	int32 m_nDrowningDamageInitial; // 0x0240
	int32 m_nDrowningDamageMax; // 0x0244
	int32 m_nWaterSpeed; // 0x0248
	float32 m_flUseRange; // 0x024C
	float32 m_flUseAngleTolerance; // 0x0250
	float32 m_flCrouchTime; // 0x0254
};
class CTriggerImpact : public CTriggerMultiple // server
{
	float32 m_flMagnitude; // 0x0900
	float32 m_flNoise; // 0x0904
	float32 m_flViewkick; // 0x0908
	CEntityOutputTemplate< Vector > m_pOutputForce; // 0x0910
};
class CCSGameModeRules_Deathmatch : public CCSGameModeRules // server
{
	GameTime_t m_flDMBonusStartTime; // 0x0030
	float32 m_flDMBonusTimeLength; // 0x0034
	CUtlString m_sDMBonusWeapon; // 0x0038
};
class CTestPulseIO::EntityHandleIntArgs_t // server
{
	CEntityHandle handleA; // 0x0000
	int32 valueB; // 0x0004
};
class CPulseCell_CursorQueue : public CPulseCell_WaitForCursorsWithTagBase // pulse_runtime_lib
{
	int32 m_nCursorsAllowedToRunParallel; // 0x0128
};
class CPulseCell_Value_RandomFloat : public CPulseCell_BaseValue // pulse_runtime_lib
{
};
class CPulseExecCursor // pulse_runtime_lib
{
};
class CBasePropDoor : public CDynamicProp // server
{
	float32 m_flAutoReturnDelay; // 0x0BB0
	CUtlVector< CHandle< CBasePropDoor > > m_hDoorList; // 0x0BB8
	int32 m_nHardwareType; // 0x0BD0
	bool m_bNeedsHardware; // 0x0BD4
	DoorState_t m_eDoorState; // 0x0BD8
	bool m_bLocked; // 0x0BDC
	bool m_bNoNPCs; // 0x0BDD
	VectorWS m_closedPosition; // 0x0BE0
	QAngle m_closedAngles; // 0x0BEC
	CHandle< CBaseEntity > m_hBlocker; // 0x0BF8
	bool m_bFirstBlocked; // 0x0BFC
	locksound_t m_ls; // 0x0C00
	bool m_bForceClosed; // 0x0C20
	VectorWS m_vecLatchWorldPosition; // 0x0C24
	CHandle< CBaseEntity > m_hActivator; // 0x0C30
	float32 m_flSpeed; // 0x0C34
	CGameSoundEventName m_SoundMoving; // 0x0C50
	CGameSoundEventName m_SoundOpen; // 0x0C58
	CGameSoundEventName m_SoundClose; // 0x0C60
	CGameSoundEventName m_SoundLock; // 0x0C68
	CGameSoundEventName m_SoundUnlock; // 0x0C70
	CGameSoundEventName m_SoundLatch; // 0x0C78
	CGameSoundEventName m_SoundPound; // 0x0C80
	CGameSoundEventName m_SoundJiggle; // 0x0C88
	CGameSoundEventName m_SoundLockedAnim; // 0x0C90
	int32 m_numCloseAttempts; // 0x0C98
	CUtlStringToken m_nPhysicsMaterial; // 0x0C9C
	CUtlSymbolLarge m_SlaveName; // 0x0CA0
	CHandle< CBasePropDoor > m_hMaster; // 0x0CA8
	CEntityIOOutput m_OnBlockedClosing; // 0x0CB0
	CEntityIOOutput m_OnBlockedOpening; // 0x0CC8
	CEntityIOOutput m_OnUnblockedClosing; // 0x0CE0
	CEntityIOOutput m_OnUnblockedOpening; // 0x0CF8
	CEntityIOOutput m_OnFullyClosed; // 0x0D10
	CEntityIOOutput m_OnFullyOpen; // 0x0D28
	CEntityIOOutput m_OnClose; // 0x0D40
	CEntityIOOutput m_OnOpen; // 0x0D58
	CEntityIOOutput m_OnLockedUse; // 0x0D70
	CEntityIOOutput m_OnAjarOpen; // 0x0D88
};
class CLogicBranchList : public CLogicalEntity // server
{
	CUtlSymbolLarge[16] m_nLogicBranchNames; // 0x04A8
	CUtlVector< CHandle< CBaseEntity > > m_LogicBranchList; // 0x0528
	CLogicBranchList::LogicBranchListenerLastState_t m_eLastState; // 0x0540
	CEntityIOOutput m_OnAllTrue; // 0x0548
	CEntityIOOutput m_OnAllFalse; // 0x0560
	CEntityIOOutput m_OnMixed; // 0x0578
};
class CBtActionParachutePositioning : public CBtNode // server
{
	CountdownTimer m_ActionTimer; // 0x0058
};
class CAK47 : public CCSWeaponBaseGun // server
{
};
class CDynamicProp : public CBreakableProp // server
{
	bool m_bCreateNavObstacle; // 0x0AF8
	bool m_bNavObstacleUpdatesOverridden; // 0x0AF9
	bool m_bUseHitboxesForRenderBox; // 0x0AFA
	bool m_bUseAnimGraph; // 0x0AFB
	CEntityIOOutput m_pOutputAnimBegun; // 0x0B00
	CEntityIOOutput m_pOutputAnimOver; // 0x0B18
	CEntityIOOutput m_pOutputAnimLoopCycleOver; // 0x0B30
	CEntityIOOutput m_OnAnimReachedStart; // 0x0B48
	CEntityIOOutput m_OnAnimReachedEnd; // 0x0B60
	CUtlSymbolLarge m_iszIdleAnim; // 0x0B78
	AnimLoopMode_t m_nIdleAnimLoopMode; // 0x0B80
	bool m_bRandomizeCycle; // 0x0B84
	bool m_bStartDisabled; // 0x0B85
	bool m_bFiredStartEndOutput; // 0x0B86
	bool m_bForceNpcExclude; // 0x0B87
	bool m_bCreateMovableSurfaceGraph; // 0x0B88
	bool m_bCreateNonSolid; // 0x0B89
	bool m_bIsOverrideProp; // 0x0B8A
	int32 m_iInitialGlowState; // 0x0B8C
	int32 m_nGlowRange; // 0x0B90
	int32 m_nGlowRangeMin; // 0x0B94
	Color m_glowColor; // 0x0B98
	int32 m_nGlowTeam; // 0x0B9C
};
class CHostageAlias_info_hostage_spawn : public CHostage // server
{
};
class CFilterTeam : public CBaseFilter // server
{
	int32 m_iFilterTeam; // 0x04E0
};
class CFuncConveyor : public CBaseModelEntity // server
{
	CUtlSymbolLarge m_szConveyorModels; // 0x0770
	float32 m_flTransitionDurationSeconds; // 0x0778
	float32 m_flSpeed; // 0x077C
	QAngle m_angMoveEntitySpace; // 0x0780
	Vector m_vecMoveDirEntitySpace; // 0x078C
	float32 m_flTargetSpeed; // 0x0798
	GameTick_t m_nTransitionStartTick; // 0x079C
	int32 m_nTransitionDurationTicks; // 0x07A0
	float32 m_flTransitionStartSpeed; // 0x07A4
	CNetworkUtlVectorBase< CHandle< CBaseEntity > > m_hConveyorModels; // 0x07A8
};
class CTriggerPhysics : public CBaseTrigger // server
{
	IPhysicsMotionController* m_pController; // 0x08F0
	float32 m_gravityScale; // 0x08F8
	float32 m_linearLimit; // 0x08FC
	float32 m_linearDamping; // 0x0900
	float32 m_angularLimit; // 0x0904
	float32 m_angularDamping; // 0x0908
	float32 m_linearForce; // 0x090C
	float32 m_flFrequency; // 0x0910
	float32 m_flDampingRatio; // 0x0914
	Vector m_vecLinearForcePointAt; // 0x0918
	bool m_bCollapseToForcePoint; // 0x0924
	VectorWS m_vecLinearForcePointAtWorld; // 0x0928
	Vector m_vecLinearForceDirection; // 0x0934
	bool m_bConvertToDebrisWhenPossible; // 0x0940
};
class CInfoInstructorHintBombTargetB : public CPointEntity // server
{
};
class CFuncTimescale : public CBaseEntity // server
{
	float32 m_flDesiredTimescale; // 0x04A8
	float32 m_flAcceleration; // 0x04AC
	float32 m_flMinBlendRate; // 0x04B0
	float32 m_flBlendDeltaMultiplier; // 0x04B4
	bool m_isStarted; // 0x04B8
};
class CBasePlayerWeaponVData : public CEntitySubclassVDataBase // server
{
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCModel > > m_szWorldModel; // 0x0028
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCModel > > m_szWorldModelAg2Override; // 0x0108
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCModel > > m_sToolsOnlyOwnerModelName; // 0x01E8
	bool m_bBuiltRightHanded; // 0x02C8
	bool m_bAllowFlipping; // 0x02C9
	CAttachmentNameSymbolWithStorage m_sMuzzleAttachment; // 0x02D0
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > > m_szMuzzleFlashParticle; // 0x02F0
	CUtlString m_szMuzzleFlashParticleConfig; // 0x03D0
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > > m_szBarrelSmokeParticle; // 0x03D8
	uint8 m_nMuzzleSmokeShotThreshold; // 0x04B8
	float32 m_flMuzzleSmokeTimeout; // 0x04BC
	float32 m_flMuzzleSmokeDecrementRate; // 0x04C0
	bool m_bGenerateMuzzleLight; // 0x04C4
	bool m_bLinkedCooldowns; // 0x04C5
	ItemFlagTypes_t m_iFlags; // 0x04C6
	int32 m_iWeight; // 0x04C8
	bool m_bAutoSwitchTo; // 0x04CC
	bool m_bAutoSwitchFrom; // 0x04CD
	AmmoIndex_t m_nPrimaryAmmoType; // 0x04CE
	AmmoIndex_t m_nSecondaryAmmoType; // 0x04CF
	int32 m_iMaxClip1; // 0x04D0
	int32 m_iMaxClip2; // 0x04D4
	int32 m_iDefaultClip1; // 0x04D8
	int32 m_iDefaultClip2; // 0x04DC
	bool m_bReserveAmmoAsClips; // 0x04E0
	bool m_bTreatAsSingleClip; // 0x04E1
	bool m_bKeepLoadedAmmo; // 0x04E2
	RumbleEffect_t m_iRumbleEffect; // 0x04E4
	float32 m_flDropSpeed; // 0x04E8
	int32 m_iSlot; // 0x04EC
	int32 m_iPosition; // 0x04F0
	CUtlOrderedMap< WeaponSound_t, CSoundEventName > m_aShootSounds; // 0x04F8
};
class CSoundOpvarSetPointEntity : public CSoundOpvarSetPointBase // server
{
	CEntityIOOutput m_OnEnter; // 0x0550
	CEntityIOOutput m_OnExit; // 0x0568
	bool m_bAutoDisable; // 0x0580
	float32 m_flDistanceMin; // 0x05C4
	float32 m_flDistanceMax; // 0x05C8
	float32 m_flDistanceMapMin; // 0x05CC
	float32 m_flDistanceMapMax; // 0x05D0
	float32 m_flOcclusionRadius; // 0x05D4
	float32 m_flOcclusionMin; // 0x05D8
	float32 m_flOcclusionMax; // 0x05DC
	float32 m_flValSetOnDisable; // 0x05E0
	bool m_bSetValueOnDisable; // 0x05E4
	bool m_bReloading; // 0x05E5
	int32 m_nSimulationMode; // 0x05E8
	int32 m_nVisibilitySamples; // 0x05EC
	Vector m_vDynamicProxyPoint; // 0x05F0
	float32 m_flDynamicMaximumOcclusion; // 0x05FC
	CEntityHandle m_hDynamicEntity; // 0x0600
	CUtlSymbolLarge m_iszDynamicEntityName; // 0x0608
	float32 m_flPathingDistanceNormFactor; // 0x0610
	VectorWS m_vPathingSourcePos; // 0x0614
	VectorWS m_vPathingListenerPos; // 0x0620
	Vector m_vPathingDirection; // 0x062C
	int32 m_nPathingSourceIndex; // 0x0638
};
class CEnvCombinedLightProbeVolumeAPI // server
{
};
class CInfoTargetServerOnly : public CServerOnlyPointEntity // server
{
};
class CServerRagdollTrigger : public CBaseTrigger // server
{
};
class CDynamicPropAlias_dynamic_prop : public CDynamicProp // server
{
};
class CMarkupVolumeTagged : public CMarkupVolume // server
{
	CUtlVector< CGlobalSymbol > m_GroupNames; // 0x0778
	CUtlVector< CGlobalSymbol > m_Tags; // 0x0790
	bool m_bIsGroup; // 0x07A8
	bool m_bGroupByPrefab; // 0x07A9
	bool m_bGroupByVolume; // 0x07AA
	bool m_bGroupOtherGroups; // 0x07AB
	bool m_bIsInGroup; // 0x07AC
};
class CInfoParticleTarget : public CPointEntity // server
{
};
class CEnvCubemap : public CBaseEntity // server
{
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hCubemapTexture; // 0x0528
	bool m_Entity_bCustomCubemapTexture; // 0x0530
	float32 m_Entity_flInfluenceRadius; // 0x0534
	Vector m_Entity_vBoxProjectMins; // 0x0538
	Vector m_Entity_vBoxProjectMaxs; // 0x0544
	bool m_Entity_bMoveable; // 0x0550
	int32 m_Entity_nHandshake; // 0x0554
	int32 m_Entity_nEnvCubeMapArrayIndex; // 0x0558
	int32 m_Entity_nPriority; // 0x055C
	float32 m_Entity_flEdgeFadeDist; // 0x0560
	Vector m_Entity_vEdgeFadeDists; // 0x0564
	float32 m_Entity_flDiffuseScale; // 0x0570
	bool m_Entity_bStartDisabled; // 0x0574
	bool m_Entity_bDefaultEnvMap; // 0x0575
	bool m_Entity_bDefaultSpecEnvMap; // 0x0576
	bool m_Entity_bIndoorCubeMap; // 0x0577
	bool m_Entity_bCopyDiffuseFromDefaultCubemap; // 0x0578
	bool m_Entity_bEnabled; // 0x0588
};
class CCSPlayer_DamageReactServices : public CPlayerPawnComponent // server
{
};
class CWeaponXM1014 : public CCSWeaponBaseShotgun // server
{
};
class CTriggerLerpObject : public CBaseTrigger // server
{
	CUtlSymbolLarge m_iszLerpTarget; // 0x08E8
	CHandle< CBaseEntity > m_hLerpTarget; // 0x08F0
	CUtlSymbolLarge m_iszLerpTargetAttachment; // 0x08F8
	AttachmentHandle_t m_hLerpTargetAttachment; // 0x0900
	float32 m_flLerpDuration; // 0x0904
	bool m_bAttachedEntityWasParented; // 0x0908
	bool m_bLerpRestoreMoveType; // 0x0909
	bool m_bSingleLerpObject; // 0x090A
	CUtlVector< lerpdata_t > m_vecLerpingObjects; // 0x0910
	CUtlSymbolLarge m_iszLerpEffect; // 0x0928
	CUtlSymbolLarge m_iszLerpSound; // 0x0930
	bool m_bAttachTouchingObject; // 0x0938
	CHandle< CBaseEntity > m_hEntityToWaitForDisconnect; // 0x093C
	CEntityIOOutput m_OnLerpStarted; // 0x0940
	CEntityIOOutput m_OnLerpFinished; // 0x0958
	CEntityIOOutput m_OnDetached; // 0x0970
};
class CPhysicsPropOverride : public CPhysicsProp // server
{
};
class CTriggerSave : public CBaseTrigger // server
{
	bool m_bForceNewLevelUnit; // 0x08E8
	float32 m_fDangerousTimer; // 0x08EC
	int32 m_minHitPoints; // 0x08F0
	float32 m_flRetriggerDelay; // 0x08F4
};
class CPointHurt : public CPointEntity // server
{
	int32 m_nDamage; // 0x04A8
	DamageTypes_t m_bitsDamageType; // 0x04AC
	float32 m_flRadius; // 0x04B0
	float32 m_flDelay; // 0x04B4
	CUtlSymbolLarge m_strTarget; // 0x04B8
	CHandle< CBaseEntity > m_pActivator; // 0x04C0
};
class CBaseAnimGraphAlias_baseanimating : public CBaseAnimGraph // server
{
};
class CBasePlayerController : public CBaseEntity // server
{
	uint64 m_nInButtonsWhichAreToggles; // 0x04B0
	uint32 m_nTickBase; // 0x04B8
	CHandle< CBasePlayerPawn > m_hPawn; // 0x04E0
	bool m_bKnownTeamMismatch; // 0x04E4
	CSplitScreenSlot m_nSplitScreenSlot; // 0x04E8
	CHandle< CBasePlayerController > m_hSplitOwner; // 0x04EC
	CUtlVector< CHandle< CBasePlayerController > > m_hSplitScreenPlayers; // 0x04F0
	bool m_bIsHLTV; // 0x0508
	PlayerConnectedState m_iConnected; // 0x050C
	PlayerConnectedState m_iMostConnected; // 0x0510
	char[128] m_iszPlayerName; // 0x0514
	CUtlString m_szNetworkIDString; // 0x0598
	float32 m_fLerpTime; // 0x05A0
	bool m_bLagCompensation; // 0x05A4
	bool m_bPredict; // 0x05A5
	bool m_bIsLowViolence; // 0x05AC
	bool m_bGamePaused; // 0x05AD
	ChatIgnoreType_t m_iIgnoreGlobalChat; // 0x06E8
	float32 m_flLastPlayerTalkTime; // 0x06EC
	float32 m_flLastEntitySteadyState; // 0x06F0
	int32 m_nAvailableEntitySteadyState; // 0x06F4
	bool m_bHasAnySteadyStateEnts; // 0x06F8
	uint64 m_steamID; // 0x0708
	bool m_bNoClipEnabled; // 0x0710
	uint32 m_iDesiredFOV; // 0x0714
};
class C_CSGO_TeamIntroCharacterPosition : public C_CSGO_TeamPreviewCharacterPosition // client
{
};
class C_FireCrackerBlast : public C_Inferno // client
{
};
class CCSGO_WingmanIntroCounterTerroristPosition : public CCSGO_WingmanIntroCharacterPosition // client
{
};
class CPulseCell_WaitForCursorsWithTag : public CPulseCell_WaitForCursorsWithTagBase // pulse_runtime_lib
{
	bool m_bTagSelfWhenComplete; // 0x0128
	PulseCursorCancelPriority_t m_nDesiredKillPriority; // 0x012C
};
class C_SceneEntity::QueuedEvents_t // client
{
	float32 starttime; // 0x0000
};
class CCSPlayer_PingServices : public CPlayerPawnComponent // client
{
	CHandle< C_PlayerPing > m_hPlayerPing; // 0x0048
};
class CEconItemAttribute // client
{
	uint16 m_iAttributeDefinitionIndex; // 0x0030
	float32 m_flValue; // 0x0034
	float32 m_flInitialValue; // 0x0038
	int32 m_nRefundableCurrency; // 0x003C
	bool m_bSetBonus; // 0x0040
};
class CBaseTriggerAPI // client
{
};
class CFuncRetakeBarrier : public C_DynamicProp // client
{
};
class C_EnvWindShared // client
{
	GameTime_t m_flStartTime; // 0x0008
	uint32 m_iWindSeed; // 0x000C
	uint16 m_iMinWind; // 0x0010
	uint16 m_iMaxWind; // 0x0012
	int32 m_windRadius; // 0x0014
	uint16 m_iMinGust; // 0x0018
	uint16 m_iMaxGust; // 0x001A
	float32 m_flMinGustDelay; // 0x001C
	float32 m_flMaxGustDelay; // 0x0020
	float32 m_flGustDuration; // 0x0024
	uint16 m_iGustDirChange; // 0x0028
	uint16 m_iInitialWindDir; // 0x002A
	float32 m_flInitialWindSpeed; // 0x002C
	VectorWS m_location; // 0x0030
	CHandle< C_BaseEntity > m_hEntOwner; // 0x003C
};
class C_SkyCamera : public C_BaseEntity // client
{
	sky3dparams_t m_skyboxData; // 0x0600
	CUtlStringToken m_skyboxSlotToken; // 0x0690
	bool m_bUseAngles; // 0x0694
	C_SkyCamera* m_pNext; // 0x0698
};
class CPulseCell_Base // pulse_runtime_lib
{
	PulseDocNodeID_t m_nEditorNodeID; // 0x0008
};
class C_FuncRotating : public C_BaseModelEntity // client
{
};
class C_CSGO_PreviewPlayer_API // client
{
};
class C_SoundOpvarSetPointBase : public C_BaseEntity // client
{
	CUtlSymbolLarge m_iszStackName; // 0x0600
	CUtlSymbolLarge m_iszOperatorName; // 0x0608
	CUtlSymbolLarge m_iszOpvarName; // 0x0610
	int32 m_iOpvarIndex; // 0x0618
	bool m_bUseAutoCompare; // 0x061C
	bool m_bFastRefresh; // 0x061D
};
class C_EnvCubemapFog : public C_BaseEntity // client
{
	float32 m_flEndDistance; // 0x0600
	float32 m_flStartDistance; // 0x0604
	float32 m_flFogFalloffExponent; // 0x0608
	bool m_bHeightFogEnabled; // 0x060C
	float32 m_flFogHeightWidth; // 0x0610
	float32 m_flFogHeightEnd; // 0x0614
	float32 m_flFogHeightStart; // 0x0618
	float32 m_flFogHeightExponent; // 0x061C
	float32 m_flLODBias; // 0x0620
	bool m_bActive; // 0x0624
	bool m_bStartDisabled; // 0x0625
	float32 m_flFogMaxOpacity; // 0x0628
	int32 m_nCubemapSourceType; // 0x062C
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hSkyMaterial; // 0x0630
	CUtlSymbolLarge m_iszSkyEntity; // 0x0638
	int32 m_nHeightFogType; // 0x0640
	int32 m_nFogHeightBlendMode; // 0x0644
	int32 m_nFogHeightCoordinateSpace; // 0x0648
	int32 m_nDistanceFogType; // 0x064C
	CUtlSymbolLarge m_DistanceFogCurveString; // 0x0650
	CUtlSymbolLarge m_HeightFogCurveString; // 0x0658
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hFogCubemapTexture; // 0x06F0
	bool m_bHasHeightFogEnd; // 0x06F8
	bool m_bFirstTime; // 0x06F9
};
class C_CSGO_TeamSelectTerroristPosition : public C_CSGO_TeamSelectCharacterPosition // client
{
};
class C_EnvParticleGlow : public C_ParticleSystem // client
{
	float32 m_flAlphaScale; // 0x1580
	float32 m_flRadiusScale; // 0x1584
	float32 m_flSelfIllumScale; // 0x1588
	Color m_ColorTint; // 0x158C
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hTextureOverride; // 0x1590
};
class CCS_PortraitWorldCallbackHandler : public C_BaseEntity // client
{
};
class CCSPlayerController_InventoryServices : public CPlayerControllerComponent // client
{
	CUtlVector< CCSPlayerController_InventoryServices::NetworkedLoadoutSlot_t > m_vecNetworkableLoadout; // 0x0040
	uint16 m_unMusicID; // 0x0058
	MedalRank_t[6] m_rank; // 0x005C
	int32 m_nPersonaDataPublicLevel; // 0x0074
	int32 m_nPersonaDataPublicCommendsLeader; // 0x0078
	int32 m_nPersonaDataPublicCommendsTeacher; // 0x007C
	int32 m_nPersonaDataPublicCommendsFriendly; // 0x0080
	int32 m_nPersonaDataXpTrailLevel; // 0x0084
	C_UtlVectorEmbeddedNetworkVar< ServerAuthoritativeWeaponSlot_t > m_vecServerAuthoritativeWeaponSlots; // 0x0088
};
class CCSPlayerModernJump // client
{
	GameTick_t m_nLastActualJumpPressTick; // 0x0010
	float32 m_flLastActualJumpPressFrac; // 0x0014
	GameTick_t m_nLastUsableJumpPressTick; // 0x0018
	float32 m_flLastUsableJumpPressFrac; // 0x001C
	GameTick_t m_nLastLandedTick; // 0x0020
	float32 m_flLastLandedFrac; // 0x0024
	float32 m_flLastLandedVelocityX; // 0x0028
	float32 m_flLastLandedVelocityY; // 0x002C
	float32 m_flLastLandedVelocityZ; // 0x0030
};
class CCSGO_TeamPreviewCharacterPosition_API // client
{
};
class C_EconEntity::AttachedModelData_t // client
{
	int32 m_iModelDisplayFlags; // 0x0000
};
class CPulse_ResumePoint : public CPulse_OutflowConnection // pulse_runtime_lib
{
};
class CTriggerFan : public C_BaseTrigger // client
{
	Vector m_vFanOriginOffset; // 0x1098
	Vector m_vDirection; // 0x10A4
	bool m_bPushTowardsInfoTarget; // 0x10B0
	bool m_bPushAwayFromInfoTarget; // 0x10B1
	Quaternion m_qNoiseDelta; // 0x10C0
	CHandle< CInfoFan > m_hInfoFan; // 0x10D0
	float32 m_flForce; // 0x10D4
	bool m_bFalloff; // 0x10D8
	CountdownTimer m_RampTimer; // 0x10E0
};
class C_HostageCarriableProp : public CBaseAnimGraph // client
{
};
class C_BulletHitModel : public CBaseAnimGraph // client
{
	matrix3x4_t m_matLocal; // 0x1180
	int32 m_iBoneIndex; // 0x11B0
	CHandle< C_BaseEntity > m_hPlayerParent; // 0x11B4
	bool m_bIsHit; // 0x11B8
	float32 m_flTimeCreated; // 0x11BC
	VectorWS m_vecStartPos; // 0x11C0
};
class C_FuncElectrifiedVolume : public C_FuncBrush // client
{
	ParticleIndex_t m_nAmbientEffect; // 0x0FB0
	CUtlSymbolLarge m_EffectName; // 0x0FB8
	bool m_bState; // 0x0FC0
};
class C_MapVetoPickController : public C_BaseEntity // client
{
	int32 m_nDraftType; // 0x0610
	int32 m_nTeamWinningCoinToss; // 0x0614
	int32[64] m_nTeamWithFirstChoice; // 0x0618
	int32[7] m_nVoteMapIdsList; // 0x0718
	int32[64] m_nAccountIDs; // 0x0734
	int32[64] m_nMapId0; // 0x0834
	int32[64] m_nMapId1; // 0x0934
	int32[64] m_nMapId2; // 0x0A34
	int32[64] m_nMapId3; // 0x0B34
	int32[64] m_nMapId4; // 0x0C34
	int32[64] m_nMapId5; // 0x0D34
	int32[64] m_nStartingSide0; // 0x0E34
	int32 m_nCurrentPhase; // 0x0F34
	int32 m_nPhaseStartTick; // 0x0F38
	int32 m_nPhaseDurationTicks; // 0x0F3C
	int32 m_nPostDataUpdateTick; // 0x0F40
	bool m_bDisabledHud; // 0x0F44
};
class C_EnvVolumetricFogVolume : public C_BaseEntity // client
{
	bool m_bActive; // 0x0600
	Vector m_vBoxMins; // 0x0604
	Vector m_vBoxMaxs; // 0x0610
	bool m_bStartDisabled; // 0x061C
	bool m_bIndirectUseLPVs; // 0x061D
	float32 m_flStrength; // 0x0620
	int32 m_nFalloffShape; // 0x0624
	float32 m_flFalloffExponent; // 0x0628
	float32 m_flHeightFogDepth; // 0x062C
	float32 m_fHeightFogEdgeWidth; // 0x0630
	float32 m_fIndirectLightStrength; // 0x0634
	float32 m_fSunLightStrength; // 0x0638
	float32 m_fNoiseStrength; // 0x063C
	Color m_TintColor; // 0x0640
	bool m_bOverrideTintColor; // 0x0644
	bool m_bOverrideIndirectLightStrength; // 0x0645
	bool m_bOverrideSunLightStrength; // 0x0646
	bool m_bOverrideNoiseStrength; // 0x0647
};
class C_CSGO_EndOfMatchCharacterPosition : public C_CSGO_TeamPreviewCharacterPosition // client
{
};
class CPulseCell_PlaySequence : public CPulseCell_BaseYieldingInflow // client
{
	CUtlString m_SequenceName; // 0x00D8
	PulseNodeDynamicOutflows_t m_PulseAnimEvents; // 0x00E0
	CPulse_ResumePoint m_OnFinished; // 0x00F8
};
class C_BaseEntityAPI // client
{
};
class C_BarnLight : public C_BaseModelEntity // client
{
	bool m_bEnabled; // 0x0FB0
	int32 m_nColorMode; // 0x0FB4
	Color m_Color; // 0x0FB8
	float32 m_flColorTemperature; // 0x0FBC
	float32 m_flBrightness; // 0x0FC0
	float32 m_flBrightnessScale; // 0x0FC4
	int32 m_nDirectLight; // 0x0FC8
	int32 m_nBakedShadowIndex; // 0x0FCC
	int32 m_nLightPathUniqueId; // 0x0FD0
	int32 m_nLightMapUniqueId; // 0x0FD4
	int32 m_nLuminaireShape; // 0x0FD8
	float32 m_flLuminaireSize; // 0x0FDC
	float32 m_flLuminaireAnisotropy; // 0x0FE0
	CUtlString m_LightStyleString; // 0x0FE8
	GameTime_t m_flLightStyleStartTime; // 0x0FF0
	C_NetworkUtlVectorBase< CUtlString > m_QueuedLightStyleStrings; // 0x0FF8
	C_NetworkUtlVectorBase< CUtlString > m_LightStyleEvents; // 0x1010
	C_NetworkUtlVectorBase< CHandle< C_BaseModelEntity > > m_LightStyleTargets; // 0x1028
	CEntityIOOutput[4] m_StyleEvent; // 0x1040
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hLightCookie; // 0x10A0
	float32 m_flShape; // 0x10A8
	float32 m_flSoftX; // 0x10AC
	float32 m_flSoftY; // 0x10B0
	float32 m_flSkirt; // 0x10B4
	float32 m_flSkirtNear; // 0x10B8
	Vector m_vSizeParams; // 0x10BC
	float32 m_flRange; // 0x10C8
	Vector m_vShear; // 0x10CC
	int32 m_nBakeSpecularToCubemaps; // 0x10D8
	Vector m_vBakeSpecularToCubemapsSize; // 0x10DC
	float32 m_flBakeSpecularToCubemapsScale; // 0x10E8
	int32 m_nCastShadows; // 0x10EC
	int32 m_nShadowMapSize; // 0x10F0
	int32 m_nShadowPriority; // 0x10F4
	bool m_bContactShadow; // 0x10F8
	bool m_bForceShadowsEnabled; // 0x10F9
	int32 m_nBounceLight; // 0x10FC
	float32 m_flBounceScale; // 0x1100
	float32 m_flMinRoughness; // 0x1104
	Vector m_vAlternateColor; // 0x1108
	float32 m_fAlternateColorBrightness; // 0x1114
	int32 m_nFog; // 0x1118
	float32 m_flFogStrength; // 0x111C
	int32 m_nFogShadows; // 0x1120
	float32 m_flFogScale; // 0x1124
	float32 m_flFadeSizeStart; // 0x1128
	float32 m_flFadeSizeEnd; // 0x112C
	float32 m_flShadowFadeSizeStart; // 0x1130
	float32 m_flShadowFadeSizeEnd; // 0x1134
	bool m_bPrecomputedFieldsValid; // 0x1138
	Vector m_vPrecomputedBoundsMins; // 0x113C
	Vector m_vPrecomputedBoundsMaxs; // 0x1148
	Vector m_vPrecomputedOBBOrigin; // 0x1154
	QAngle m_vPrecomputedOBBAngles; // 0x1160
	Vector m_vPrecomputedOBBExtent; // 0x116C
	int32 m_nPrecomputedSubFrusta; // 0x1178
	Vector m_vPrecomputedOBBOrigin0; // 0x117C
	QAngle m_vPrecomputedOBBAngles0; // 0x1188
	Vector m_vPrecomputedOBBExtent0; // 0x1194
	Vector m_vPrecomputedOBBOrigin1; // 0x11A0
	QAngle m_vPrecomputedOBBAngles1; // 0x11AC
	Vector m_vPrecomputedOBBExtent1; // 0x11B8
	Vector m_vPrecomputedOBBOrigin2; // 0x11C4
	QAngle m_vPrecomputedOBBAngles2; // 0x11D0
	Vector m_vPrecomputedOBBExtent2; // 0x11DC
	Vector m_vPrecomputedOBBOrigin3; // 0x11E8
	QAngle m_vPrecomputedOBBAngles3; // 0x11F4
	Vector m_vPrecomputedOBBExtent3; // 0x1200
	Vector m_vPrecomputedOBBOrigin4; // 0x120C
	QAngle m_vPrecomputedOBBAngles4; // 0x1218
	Vector m_vPrecomputedOBBExtent4; // 0x1224
	Vector m_vPrecomputedOBBOrigin5; // 0x1230
	QAngle m_vPrecomputedOBBAngles5; // 0x123C
	Vector m_vPrecomputedOBBExtent5; // 0x1248
	bool m_bInitialBoneSetup; // 0x1298
	C_NetworkUtlVectorBase< uint16 > m_VisClusters; // 0x12A0
};
class CPulseCell_LerpCameraSettings : public CPulseCell_BaseLerp // client
{
	float32 m_flSeconds; // 0x0120
	PointCameraSettings_t m_Start; // 0x0124
	PointCameraSettings_t m_End; // 0x0134
};
class CPointOffScreenIndicatorUi : public C_PointClientUIWorldPanel // client
{
	bool m_bBeenEnabled; // 0x1210
	bool m_bHide; // 0x1211
	float32 m_flSeenTargetTime; // 0x1214
	C_PointClientUIWorldPanel* m_pTargetPanel; // 0x1218
};
class CCSObserver_UseServices : public CPlayer_UseServices // client
{
};
class C_PostProcessingVolume : public C_BaseTrigger // client
{
	CStrongHandle< InfoForResourceTypeCPostProcessingResource > m_hPostSettings; // 0x10A8
	float32 m_flFadeDuration; // 0x10B0
	float32 m_flMinLogExposure; // 0x10B4
	float32 m_flMaxLogExposure; // 0x10B8
	float32 m_flMinExposure; // 0x10BC
	float32 m_flMaxExposure; // 0x10C0
	float32 m_flExposureCompensation; // 0x10C4
	float32 m_flExposureFadeSpeedUp; // 0x10C8
	float32 m_flExposureFadeSpeedDown; // 0x10CC
	float32 m_flTonemapEVSmoothingRange; // 0x10D0
	bool m_bMaster; // 0x10D4
	bool m_bExposureControl; // 0x10D5
};
class CCSPlayer_UseServices : public CPlayer_UseServices // client
{
};
class C_BaseModelEntity::Emphasized_Phoneme // client
{
	CUtlString m_sClassName; // 0x0000
	float32 m_flAmount; // 0x0018
	bool m_bRequired; // 0x001C
	bool m_bBasechecked; // 0x001D
	bool m_bValid; // 0x001E
};
class C_CSGO_CounterTerroristWingmanIntroCamera : public C_CSGO_TeamPreviewCamera // client
{
};
class CPulseCell_PickBestOutflowSelector : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseBestOutflowRules_t m_nCheckType; // 0x0048
	PulseSelectorOutflowList_t m_OutflowList; // 0x0050
};
class CInfoFan : public C_PointEntity // client
{
	float32 m_fFanForceMaxRadius; // 0x0640
	float32 m_fFanForceMinRadius; // 0x0644
	float32 m_flCurveDistRange; // 0x0648
	CUtlSymbolLarge m_FanForceCurveString; // 0x0650
};
class CCSWeaponBase_API // client
{
};
class C_VoteController : public C_BaseEntity // client
{
	int32 m_iActiveIssueIndex; // 0x0610
	int32 m_iOnlyTeamToVote; // 0x0614
	int32[5] m_nVoteOptionCount; // 0x0618
	int32 m_nPotentialVotes; // 0x062C
	bool m_bVotesDirty; // 0x0630
	bool m_bTypeDirty; // 0x0631
	bool m_bIsYesNoVote; // 0x0632
};
class C_C4 : public C_CSWeaponBase // client
{
	ParticleIndex_t m_activeLightParticleIndex; // 0x1CE0
	C4LightEffect_t m_eActiveLightEffect; // 0x1CE4
	bool m_bStartedArming; // 0x1CE8
	GameTime_t m_fArmedTime; // 0x1CEC
	bool m_bBombPlacedAnimation; // 0x1CF0
	bool m_bIsPlantingViaUse; // 0x1CF1
	EntitySpottedState_t m_entitySpottedState; // 0x1CF8
	int32 m_nSpotRules; // 0x1D10
	bool[7] m_bPlayedArmingBeeps; // 0x1D14
	bool m_bBombPlanted; // 0x1D1B
};
class C_CSPlayerPawnBase : public C_BasePlayerPawn // client
{
	CCSPlayer_PingServices* m_pPingServices; // 0x13F0
	CSPlayerState m_previousPlayerState; // 0x13F8
	CSPlayerState m_iPlayerState; // 0x13FC
	bool m_bHasMovedSinceSpawn; // 0x1400
	GameTime_t m_flLastSpawnTimeIndex; // 0x1404
	int32 m_iProgressBarDuration; // 0x1408
	float32 m_flProgressBarStartTime; // 0x140C
	GameTime_t m_flClientDeathTime; // 0x1410
	float32 m_flFlashBangTime; // 0x1414
	float32 m_flFlashScreenshotAlpha; // 0x1418
	float32 m_flFlashOverlayAlpha; // 0x141C
	bool m_bFlashBuildUp; // 0x1420
	bool m_bFlashDspHasBeenCleared; // 0x1421
	bool m_bFlashScreenshotHasBeenGrabbed; // 0x1422
	float32 m_flFlashMaxAlpha; // 0x1424
	float32 m_flFlashDuration; // 0x1428
	GameTime_t m_flClientHealthFadeChangeTimestamp; // 0x142C
	int32 m_nClientHealthFadeParityValue; // 0x1430
	float32 m_fNextThinkPushAway; // 0x1434
	float32 m_flCurrentMusicStartTime; // 0x143C
	float32 m_flMusicRoundStartTime; // 0x1440
	bool m_bDeferStartMusicOnWarmup; // 0x1444
	float32 m_flLastSmokeOverlayAlpha; // 0x1448
	float32 m_flLastSmokeAge; // 0x144C
	Vector m_vLastSmokeOverlayColor; // 0x1450
	CHandle< CCSPlayerController > m_hOriginalController; // 0x1478
};
class C_BreakableProp : public CBaseProp // client
{
	CPropDataComponent m_CPropDataComponent; // 0x11B0
	CEntityIOOutput m_OnStartDeath; // 0x11F0
	CEntityIOOutput m_OnBreak; // 0x1208
	CEntityOutputTemplate< float32 > m_OnHealthChanged; // 0x1220
	CEntityIOOutput m_OnTakeDamage; // 0x1240
	float32 m_impactEnergyScale; // 0x1258
	int32 m_iMinHealthDmg; // 0x125C
	float32 m_flPressureDelay; // 0x1260
	float32 m_flDefBurstScale; // 0x1264
	Vector m_vDefBurstOffset; // 0x1268
	CHandle< C_BaseEntity > m_hBreaker; // 0x1274
	PerformanceMode_t m_PerformanceMode; // 0x1278
	GameTime_t m_flPreventDamageBeforeTime; // 0x127C
	BreakableContentsType_t m_BreakableContentsType; // 0x1280
	CUtlString m_strBreakableContentsPropGroupOverride; // 0x1288
	CUtlString m_strBreakableContentsParticleOverride; // 0x1290
	bool m_bHasBreakPiecesOrCommands; // 0x1298
	float32 m_explodeDamage; // 0x129C
	float32 m_explodeRadius; // 0x12A0
	CGlobalSymbol m_sExplosionType; // 0x12A8
	float32 m_explosionDelay; // 0x12B0
	CUtlSymbolLarge m_explosionBuildupSound; // 0x12B8
	CUtlSymbolLarge m_explosionCustomEffect; // 0x12C0
	CUtlSymbolLarge m_explosionCustomSound; // 0x12C8
	CUtlSymbolLarge m_explosionModifier; // 0x12D0
	CHandle< C_BasePlayerPawn > m_hPhysicsAttacker; // 0x12D8
	GameTime_t m_flLastPhysicsInfluenceTime; // 0x12DC
	float32 m_flDefaultFadeScale; // 0x12E0
	CHandle< C_BaseEntity > m_hLastAttacker; // 0x12E4
};
class CCSGO_WingmanIntroTerroristPosition : public CCSGO_WingmanIntroCharacterPosition // client
{
};
class CPrecipitationVData : public CEntitySubclassVDataBase // client
{
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > > m_szParticlePrecipitationEffect; // 0x0028
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > > m_szParticlePrecipitationPuddleEffect; // 0x0108
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > > m_szParticlePrecipitationPostEffect; // 0x01E8
	float32 m_flInnerDistance; // 0x02C8
	ParticleAttachment_t m_nAttachType; // 0x02CC
	bool m_bBatchSameVolumeType; // 0x02D0
	int32 m_nRTEnvCP; // 0x02D4
	int32 m_nRTEnvCPComponent; // 0x02D8
	CUtlString m_szModifier; // 0x02E0
	int32 m_nUseSnapshotFromSurfaceGraph; // 0x02E8
	PrecipitationFilter_t m_snapshotFilter; // 0x02EC
};
class C_RetakeGameRules // client
{
	int32 m_nMatchSeed; // 0x0138
	bool m_bBlockersPresent; // 0x013C
	bool m_bRoundInProgress; // 0x013D
	int32 m_iFirstSecondHalfRound; // 0x0140
	int32 m_iBombSite; // 0x0144
	CHandle< C_CSPlayerPawn > m_hBombPlanter; // 0x0148
};
class CPulseCell_WaitForObservable : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulseObservableExpression< bool > m_Condition; // 0x00D8
	CPulse_ResumePoint m_OnTrue; // 0x0150
};
class C_SoundAreaEntitySphere : public C_SoundAreaEntityBase // client
{
	float32 m_flRadius; // 0x0628
};
class CPulseCell_Step_EntFire : public CPulseCell_BaseFlow // client
{
	CUtlString m_Input; // 0x0048
};
class C_WeaponAWP : public C_CSWeaponBaseGun // client
{
};
class C_BaseButton : public C_BaseToggle // client
{
	CHandle< C_BaseModelEntity > m_glowEntity; // 0x0FB0
	bool m_usable; // 0x0FB4
	CUtlSymbolLarge m_szDisplayText; // 0x0FB8
};
class CCSObserver_ObserverServices : public CPlayer_ObserverServices // client
{
	ObserverInterpState_t m_obsInterpState; // 0x0068
};
class CHitboxComponent : public CEntityComponent // client
{
	float32 m_flBoundsExpandRadius; // 0x0014
};
class ServerAuthoritativeWeaponSlot_t // client
{
	uint16 unClass; // 0x0030
	uint16 unSlot; // 0x0032
	uint16 unItemDefIdx; // 0x0034
};
class C_CSMinimapBoundary : public C_BaseEntity // client
{
};
class CPathQueryComponent : public CEntityComponent // client
{
};
class C_Precipitation : public C_BaseTrigger // client
{
	float32 m_flDensity; // 0x1098
	float32 m_flParticleInnerDist; // 0x10A8
	char* m_pParticleDef; // 0x10B0
	TimedEvent[1] m_tParticlePrecipTraceTimer; // 0x10C4
	bool[1] m_bActiveParticlePrecipEmitter; // 0x10CC
	bool m_bParticlePrecipInitialized; // 0x10CD
	bool m_bHasSimulatedSinceLastSceneObjectUpdate; // 0x10CE
	int32 m_nAvailableSheetSequencesMaxIndex; // 0x10D0
};
class CLogicRelay : public CLogicalEntity // client
{
	CEntityIOOutput m_OnSpawn; // 0x0600
	CEntityIOOutput m_OnTrigger; // 0x0618
	bool m_bDisabled; // 0x0630
	bool m_bWaitForRefire; // 0x0631
	bool m_bTriggerOnce; // 0x0632
	bool m_bFastRetrigger; // 0x0633
	bool m_bPassthoughCaller; // 0x0634
};
class SequenceHistory_t // client
{
	HSequence m_hSequence; // 0x0000
	GameTime_t m_flSeqStartTime; // 0x0004
	float32 m_flSeqFixedCycle; // 0x0008
	AnimLoopMode_t m_nSeqLoopMode; // 0x000C
	float32 m_flPlaybackRate; // 0x0010
	float32 m_flCyclesPerSecond; // 0x0014
};
class CPlayer_ItemServices : public CPlayerPawnComponent // client
{
};
class CPulse_OutflowConnection // pulse_runtime_lib
{
	PulseSymbol_t m_SourceOutflowName; // 0x0000
	PulseRuntimeChunkIndex_t m_nDestChunk; // 0x0010
	int32 m_nInstruction; // 0x0014
	PulseRegisterMap_t m_OutflowRegisterMap; // 0x0018
};
class C_WeaponUMP45 : public C_CSWeaponBaseGun // client
{
};
class C_WeaponG3SG1 : public C_CSWeaponBaseGun // client
{
};
class C_SpotlightEnd : public C_BaseModelEntity // client
{
	float32 m_flLightScale; // 0x0FB0
	float32 m_Radius; // 0x0FB4
};
class C_Fish : public CBaseAnimGraph // client
{
	VectorWS m_pos; // 0x1180
	Vector m_vel; // 0x118C
	QAngle m_angles; // 0x1198
	int32 m_localLifeState; // 0x11A4
	float32 m_deathDepth; // 0x11A8
	float32 m_deathAngle; // 0x11AC
	float32 m_buoyancy; // 0x11B0
	CountdownTimer m_wiggleTimer; // 0x11B8
	float32 m_wigglePhase; // 0x11D0
	float32 m_wiggleRate; // 0x11D4
	VectorWS m_actualPos; // 0x11D8
	QAngle m_actualAngles; // 0x11E4
	VectorWS m_poolOrigin; // 0x11F0
	float32 m_waterLevel; // 0x11FC
	bool m_gotUpdate; // 0x1200
	float32 m_x; // 0x1204
	float32 m_y; // 0x1208
	float32 m_z; // 0x120C
	float32 m_angle; // 0x1210
	float32[20] m_errorHistory; // 0x1214
	int32 m_errorHistoryIndex; // 0x1264
	int32 m_errorHistoryCount; // 0x1268
	float32 m_averageError; // 0x126C
};
class C_WeaponFamas : public C_CSWeaponBaseGun // client
{
};
class C_EnvVolumetricFogController : public C_BaseEntity // client
{
	float32 m_flScattering; // 0x0600
	Color m_TintColor; // 0x0604
	float32 m_flAnisotropy; // 0x0608
	float32 m_flFadeSpeed; // 0x060C
	float32 m_flDrawDistance; // 0x0610
	float32 m_flFadeInStart; // 0x0614
	float32 m_flFadeInEnd; // 0x0618
	float32 m_flIndirectStrength; // 0x061C
	int32 m_nVolumeDepth; // 0x0620
	float32 m_fFirstVolumeSliceThickness; // 0x0624
	int32 m_nIndirectTextureDimX; // 0x0628
	int32 m_nIndirectTextureDimY; // 0x062C
	int32 m_nIndirectTextureDimZ; // 0x0630
	Vector m_vBoxMins; // 0x0634
	Vector m_vBoxMaxs; // 0x0640
	bool m_bActive; // 0x064C
	GameTime_t m_flStartAnisoTime; // 0x0650
	GameTime_t m_flStartScatterTime; // 0x0654
	GameTime_t m_flStartDrawDistanceTime; // 0x0658
	float32 m_flStartAnisotropy; // 0x065C
	float32 m_flStartScattering; // 0x0660
	float32 m_flStartDrawDistance; // 0x0664
	float32 m_flDefaultAnisotropy; // 0x0668
	float32 m_flDefaultScattering; // 0x066C
	float32 m_flDefaultDrawDistance; // 0x0670
	bool m_bStartDisabled; // 0x0674
	bool m_bEnableIndirect; // 0x0675
	bool m_bIsMaster; // 0x0676
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hFogIndirectTexture; // 0x0678
	int32 m_nForceRefreshCount; // 0x0680
	float32 m_fNoiseSpeed; // 0x0684
	float32 m_fNoiseStrength; // 0x0688
	Vector m_vNoiseScale; // 0x068C
	float32 m_fWindSpeed; // 0x0698
	Vector m_vWindDirection; // 0x069C
	bool m_bFirstTime; // 0x06A8
};
class CPulseGraphDef // pulse_runtime_lib
{
	PulseSymbol_t m_DomainIdentifier; // 0x0008
	CPulseValueFullType m_DomainSubType; // 0x0018
	PulseSymbol_t m_ParentMapName; // 0x0030
	PulseSymbol_t m_ParentXmlName; // 0x0040
	CUtlVector< CPulse_Chunk* > m_Chunks; // 0x0050
	CUtlVector< CPulseCell_Base* > m_Cells; // 0x0068
	CUtlVector< CPulse_Variable > m_Vars; // 0x0080
	CUtlVector< CPulse_PublicOutput > m_PublicOutputs; // 0x0098
	CUtlVector< CPulse_InvokeBinding* > m_InvokeBindings; // 0x00B0
	CUtlVector< CPulse_CallInfo* > m_CallInfos; // 0x00C8
	CUtlVector< CPulse_Constant > m_Constants; // 0x00E0
	CUtlVector< CPulse_DomainValue > m_DomainValues; // 0x00F8
	CUtlVector< CPulse_BlackboardReference > m_BlackboardReferences; // 0x0110
	CUtlVector< CPulse_OutputConnection* > m_OutputConnections; // 0x0128
};
class C_EnvDetailController : public C_BaseEntity // client
{
	float32 m_flFadeStartDist; // 0x0600
	float32 m_flFadeEndDist; // 0x0604
};
class C_EnvWindVolume : public C_BaseEntity // client
{
	bool m_bActive; // 0x0600
	Vector m_vBoxMins; // 0x0604
	Vector m_vBoxMaxs; // 0x0610
	bool m_bStartDisabled; // 0x061C
	int32 m_nShape; // 0x0620
	float32 m_fWindSpeedMultiplier; // 0x0624
	float32 m_fWindTurbulenceMultiplier; // 0x0628
	float32 m_fWindSpeedVariationMultiplier; // 0x062C
	float32 m_fWindDirectionVariationMultiplier; // 0x0630
};
class CBasePlayerControllerAPI // client
{
};
class CHostageRescueZoneShim : public C_BaseTrigger // client
{
};
class CEnvSoundscapeAlias_snd_soundscape : public CEnvSoundscape // client
{
};
class CCSPlayer_HostageServices : public CPlayerPawnComponent // client
{
	CHandle< C_BaseEntity > m_hCarriedHostage; // 0x0048
	CHandle< C_BaseEntity > m_hCarriedHostageProp; // 0x004C
};
class C_GameRulesProxy : public C_BaseEntity // client
{
};
class CEnvLightProbeVolumeAPI // client
{
};
class CRenderComponent : public CEntityComponent // client
{
	CNetworkVarChainer __m_pChainEntity; // 0x0010
	bool m_bIsRenderingWithViewModels; // 0x0050
	uint32 m_nSplitscreenFlags; // 0x0054
	bool m_bEnableRendering; // 0x0058
	bool m_bInterpolationReadyToDraw; // 0x00A8
};
class C_Team : public C_BaseEntity // client
{
	C_NetworkUtlVectorBase< CHandle< CBasePlayerController > > m_aPlayerControllers; // 0x0600
	C_NetworkUtlVectorBase< CHandle< C_BasePlayerPawn > > m_aPlayers; // 0x0618
	int32 m_iScore; // 0x0630
	char[129] m_szTeamname; // 0x0634
};
class CBaseGrenade_API // client
{
};
class C_PathParticleRopeAlias_path_particle_rope_clientside : public C_PathParticleRope // client
{
};
class CPointChildModifier : public C_PointEntity // client
{
	bool m_bOrphanInsteadOfDeletingChildrenOnRemove; // 0x0600
};
class CCSPlayerLegacyJump // client
{
	bool m_bOldJumpPressed; // 0x0010
	float32 m_flJumpPressedTime; // 0x0014
};
class C_WeaponNOVA : public C_CSWeaponBaseShotgun // client
{
};
class C_CS2HudModelAddon : public C_LateUpdatedAnimating // client
{
};
class C_DEagle : public C_CSWeaponBaseGun // client
{
};
class C_TriggerMultiple : public C_BaseTrigger // client
{
};
class C_CSGO_TeamPreviewCamera : public C_CSGO_MapPreviewCameraPath // client
{
	int32 m_nVariant; // 0x0688
};
class C_ColorCorrectionVolume : public C_BaseTrigger // client
{
	float32 m_LastEnterWeight; // 0x1098
	GameTime_t m_LastEnterTime; // 0x109C
	float32 m_LastExitWeight; // 0x10A0
	GameTime_t m_LastExitTime; // 0x10A4
	bool m_bEnabled; // 0x10A8
	float32 m_MaxWeight; // 0x10AC
	float32 m_FadeDuration; // 0x10B0
	float32 m_Weight; // 0x10B4
	char[512] m_lookupFilename; // 0x10B8
};
class CPlayer_MovementServices : public CPlayerPawnComponent // client
{
	int32 m_nImpulse; // 0x0048
	CInButtonState m_nButtons; // 0x0050
	uint64 m_nQueuedButtonDownMask; // 0x0070
	uint64 m_nQueuedButtonChangeMask; // 0x0078
	uint64 m_nButtonDoublePressed; // 0x0080
	uint32[64] m_pButtonPressedCmdNumber; // 0x0088
	uint32 m_nLastCommandNumberProcessed; // 0x0188
	uint64 m_nToggleButtonDownMask; // 0x0190
	float32 m_flCmdForwardMove; // 0x01A0
	float32 m_flCmdLeftMove; // 0x01A4
	float32 m_flCmdUpMove; // 0x01A8
	float32 m_flMaxspeed; // 0x01AC
	float32[4] m_arrForceSubtickMoveWhen; // 0x01B0
	float32 m_flForwardMove; // 0x01C0
	float32 m_flLeftMove; // 0x01C4
	float32 m_flUpMove; // 0x01C8
	Vector m_vecLastMovementImpulses; // 0x01CC
	QAngle m_vecOldViewAngles; // 0x0240
};
class CInfoDynamicShadowHintBox : public CInfoDynamicShadowHint // client
{
	Vector m_vBoxMins; // 0x0618
	Vector m_vBoxMaxs; // 0x0624
};
class CBaseAnimGraphController : public CSkeletonAnimationController // client
{
	AnimationAlgorithm_t m_nAnimationAlgorithm; // 0x0018
	ExternalAnimGraphHandle_t m_nNextExternalGraphHandle; // 0x001C
	C_NetworkUtlVectorBase< CGlobalSymbol > m_vecSecondarySkeletonSlotIDs; // 0x0020
	C_NetworkUtlVectorBase< CHandle< CBaseAnimGraph > > m_vecSecondarySkeletons; // 0x0038
	int32 m_nSecondarySkeletonMasterCount; // 0x0050
	float32 m_flSoundSyncTime; // 0x0058
	uint32 m_nActiveIKChainMask; // 0x005C
	HSequence m_hSequence; // 0x00B0
	GameTime_t m_flSeqStartTime; // 0x00B4
	float32 m_flSeqFixedCycle; // 0x00B8
	AnimLoopMode_t m_nAnimLoopMode; // 0x00BC
	CNetworkedQuantizedFloat m_flPlaybackRate; // 0x00C0
	SequenceFinishNotifyState_t m_nNotifyState; // 0x00CC
	bool m_bNetworkedAnimationInputsChanged; // 0x00CD
	bool m_bNetworkedSequenceChanged; // 0x00CE
	bool m_bLastUpdateSkipped; // 0x00CF
	bool m_bSequenceFinished; // 0x00D0
	GameTick_t m_nPrevAnimUpdateTick; // 0x00D4
	CStrongHandle< InfoForResourceTypeCNmGraphDefinition > m_hGraphDefinitionAG2; // 0x0370
	C_UtlVectorEmbeddedNetworkVar< AnimGraph2SerializedPoseRecipeSlot_t > m_SerializePoseRecipeAG2Slots; // 0x0378
	C_NetworkUtlVectorBase< uint8 > m_SerializePoseRecipeAG2Dynamic; // 0x03E0
	uint32 m_nSerializePoseRecipeAG2ActiveSlot; // 0x03F8
	int32 m_nSerializePoseRecipeVersionAG2; // 0x03FC
	int32 m_nServerGraphInstanceIteration; // 0x0400
	int32 m_nServerSerializationContextIteration; // 0x0404
	ResourceId_t m_primaryGraphId; // 0x0408
	C_NetworkUtlVectorBase< ResourceId_t > m_vecExternalGraphIds; // 0x0410
	C_NetworkUtlVectorBase< ResourceId_t > m_vecExternalClipIds; // 0x0428
	CGlobalSymbol m_sAnimGraph2Identifier; // 0x0440
	CAnimGraph2InstancePtr m_pGraphInstanceAG2; // 0x0448
	CExternalAnimGraphList m_vecExternalGraphs; // 0x0668
	AnimationAlgorithm_t m_nPrevAnimationAlgorithm; // 0x0699
};
class C_ColorCorrection : public C_BaseEntity // client
{
	VectorWS m_vecOrigin; // 0x0600
	float32 m_MinFalloff; // 0x060C
	float32 m_MaxFalloff; // 0x0610
	float32 m_flFadeInDuration; // 0x0614
	float32 m_flFadeOutDuration; // 0x0618
	float32 m_flMaxWeight; // 0x061C
	float32 m_flCurWeight; // 0x0620
	char[512] m_netlookupFilename; // 0x0624
	bool m_bEnabled; // 0x0824
	bool m_bMaster; // 0x0825
	bool m_bClientSide; // 0x0826
	bool m_bExclusive; // 0x0827
	bool[1] m_bEnabledOnClient; // 0x0828
	float32[1] m_flCurWeightOnClient; // 0x082C
	bool[1] m_bFadingIn; // 0x0830
	float32[1] m_flFadeStartWeight; // 0x0834
	float32[1] m_flFadeStartTime; // 0x0838
	float32[1] m_flFadeDuration; // 0x083C
};
class AnimGraph2SerializedPoseRecipeSlot_t // client
{
	CUtlBinaryBlock m_topology; // 0x0030
};
class CBuoyancyHelper // client
{
	IPhysicsMotionController* m_pController; // 0x0008
	CUtlStringToken m_nFluidType; // 0x0018
	float32 m_flFluidDensity; // 0x001C
	float32 m_flNeutrallyBuoyantGravity; // 0x0020
	float32 m_flNeutrallyBuoyantLinearDamping; // 0x0024
	float32 m_flNeutrallyBuoyantAngularDamping; // 0x0028
	bool m_bNeutrallyBuoyant; // 0x002C
	CUtlVector< float32 > m_vecFractionOfWheelSubmergedForWheelFriction; // 0x0030
	CUtlVector< float32 > m_vecWheelFrictionScales; // 0x0048
	CUtlVector< float32 > m_vecFractionOfWheelSubmergedForWheelDrag; // 0x0060
	CUtlVector< float32 > m_vecWheelDrag; // 0x0078
};
class C_PhysBox : public C_Breakable // client
{
};
class CCSPlayer_CameraServices : public CCSPlayerBase_CameraServices // client
{
	float32 m_flDeathCamTilt; // 0x02A8
	Vector m_vClientScopeInaccuracy; // 0x02B0
};
class CFilterMultiple : public CBaseFilter // client
{
	filter_t m_nFilterType; // 0x0638
	CUtlSymbolLarge[10] m_iFilterName; // 0x0640
	CHandle< C_BaseEntity >[10] m_hFilter; // 0x0690
};
class CPulseCell_FireCursors : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outflows; // 0x00D8
	bool m_bWaitForChildOutflows; // 0x00F0
	CPulse_ResumePoint m_OnFinished; // 0x00F8
};
class CEnvSoundscape : public C_BaseEntity // client
{
	CEntityIOOutput m_OnPlay; // 0x0600
	float32 m_flRadius; // 0x0618
	CGameSoundEventName m_soundEventName; // 0x0620
	bool m_bOverrideWithEvent; // 0x0628
	int32 m_soundscapeIndex; // 0x062C
	int32 m_soundscapeEntityListId; // 0x0630
	CUtlSymbolLarge[8] m_positionNames; // 0x0638
	CHandle< CEnvSoundscape > m_hProxySoundscape; // 0x0678
	bool m_bDisabled; // 0x067C
	CUtlSymbolLarge m_soundscapeName; // 0x0680
	uint32 m_soundEventHash; // 0x0688
};
class C_SoundEventEntityAlias_snd_event_point : public C_SoundEventEntity // client
{
};
class C_FogController : public C_BaseEntity // client
{
	fogparams_t m_fog; // 0x0600
	bool m_bUseAngles; // 0x0668
	int32 m_iChangedVariables; // 0x066C
};
class C_SoundOpvarSetOBBWindEntity : public C_SoundOpvarSetPointBase // client
{
};
class C_MolotovGrenade : public C_BaseCSGrenade // client
{
};
class C_NetTestBaseCombatCharacter : public C_BaseCombatCharacter // client
{
};
class CParticleSystemAPI // client
{
};
class CBodyComponentPoint : public CBodyComponent // client
{
	CGameSceneNode m_sceneNode; // 0x0080
};
class C_WeaponM4A1Silencer : public C_CSWeaponBaseGun // client
{
};
class C_EconItemView : public IEconItemInterface // client
{
	bool m_bInventoryImageRgbaRequested; // 0x0060
	bool m_bInventoryImageTriedCache; // 0x0061
	int32 m_nInventoryImageRgbaWidth; // 0x0080
	int32 m_nInventoryImageRgbaHeight; // 0x0084
	char[260] m_szCurrentLoadCachedFileName; // 0x0088
	bool m_bRestoreCustomMaterialAfterPrecache; // 0x01B8
	uint16 m_iItemDefinitionIndex; // 0x01BA
	int32 m_iEntityQuality; // 0x01BC
	uint32 m_iEntityLevel; // 0x01C0
	uint64 m_iItemID; // 0x01C8
	uint32 m_iItemIDHigh; // 0x01D0
	uint32 m_iItemIDLow; // 0x01D4
	uint32 m_iAccountID; // 0x01D8
	uint32 m_iInventoryPosition; // 0x01DC
	bool m_bInitialized; // 0x01E8
	bool m_bDisallowSOC; // 0x01E9
	bool m_bIsStoreItem; // 0x01EA
	bool m_bIsTradeItem; // 0x01EB
	int32 m_iEntityQuantity; // 0x01EC
	int32 m_iRarityOverride; // 0x01F0
	int32 m_iQualityOverride; // 0x01F4
	int32 m_iOriginOverride; // 0x01F8
	uint8 m_ubStyleOverride; // 0x01FC
	uint8 m_unClientFlags; // 0x01FD
	CAttributeList m_AttributeList; // 0x0208
	CAttributeList m_NetworkedDynamicAttributes; // 0x0280
	char[161] m_szCustomName; // 0x02F8
	char[161] m_szCustomNameOverride; // 0x0399
	bool m_bInitializedTags; // 0x0468
};
class CPulseCell_Timeline::TimelineEvent_t // pulse_runtime_lib
{
	float32 m_flTimeFromPrevious; // 0x0000
	CPulse_OutflowConnection m_EventOutflow; // 0x0008
};
class CPulseCell_IntervalTimer::CursorState_t // pulse_runtime_lib
{
	GameTime_t m_StartTime; // 0x0000
	GameTime_t m_EndTime; // 0x0004
	float32 m_flWaitInterval; // 0x0008
	float32 m_flWaitIntervalHigh; // 0x000C
	bool m_bCompleteOnNextWake; // 0x0010
};
class CPulseCell_BaseRequirement : public CPulseCell_Base // pulse_runtime_lib
{
};
class CPulseCell_BaseState : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
};
class OutflowWithRequirements_t // pulse_runtime_lib
{
	CPulse_OutflowConnection m_Connection; // 0x0000
	PulseDocNodeID_t m_DestinationFlowNodeID; // 0x0048
	CUtlVector< PulseDocNodeID_t > m_RequirementNodeIDs; // 0x0050
	CUtlVector< int32 > m_nCursorStateBlockIndex; // 0x0068
};
class CPulseCell_IsRequirementValid : public CPulseCell_BaseRequirement // pulse_runtime_lib
{
};
class C_SoundEventPathCornerEntity : public C_SoundEventEntity // client
{
	C_NetworkUtlVectorBase< SoundeventPathCornerPairNetworked_t > m_vecCornerPairsNetworked; // 0x06C0
};
class C_InfoVisibilityBox : public C_BaseEntity // client
{
	int32 m_nMode; // 0x0604
	Vector m_vBoxSize; // 0x0608
	bool m_bEnabled; // 0x0614
};
class CCSPlayer_ItemServices : public CPlayer_ItemServices // client
{
	bool m_bHasDefuser; // 0x0048
	bool m_bHasHelmet; // 0x0049
};
class CPulseCell_Value_Gradient : public CPulseCell_BaseValue // pulse_runtime_lib
{
	CColorGradient m_Gradient; // 0x0048
};
class CGrenadeTracer_API // client
{
};
class IntervalTimer // client
{
	GameTime_t m_timestamp; // 0x0008
	WorldGroupId_t m_nWorldGroupId; // 0x000C
};
class audioparams_t // client
{
	VectorWS[8] localSound; // 0x0008
	int32 soundscapeIndex; // 0x0068
	uint8 localBits; // 0x006C
	int32 soundscapeEntityListIndex; // 0x0070
	uint32 soundEventHash; // 0x0074
};
class C_PathParticleRope : public C_BaseEntity // client
{
	bool m_bStartActive; // 0x0608
	float32 m_flMaxSimulationTime; // 0x060C
	CUtlSymbolLarge m_iszEffectName; // 0x0610
	CUtlVector< CUtlSymbolLarge > m_PathNodes_Name; // 0x0618
	float32 m_flParticleSpacing; // 0x0630
	float32 m_flSlack; // 0x0634
	float32 m_flRadius; // 0x0638
	Color m_ColorTint; // 0x063C
	int32 m_nEffectState; // 0x0640
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_iEffectIndex; // 0x0648
	C_NetworkUtlVectorBase< Vector > m_PathNodes_Position; // 0x0650
	C_NetworkUtlVectorBase< Vector > m_PathNodes_TangentIn; // 0x0668
	C_NetworkUtlVectorBase< Vector > m_PathNodes_TangentOut; // 0x0680
	C_NetworkUtlVectorBase< Vector > m_PathNodes_Color; // 0x0698
	C_NetworkUtlVectorBase< bool > m_PathNodes_PinEnabled; // 0x06B0
	C_NetworkUtlVectorBase< float32 > m_PathNodes_RadiusScale; // 0x06C8
};
class C_DecoyProjectile : public C_BaseCSGrenadeProjectile // client
{
	int32 m_nDecoyShotTick; // 0x1260
	int32 m_nClientLastKnownDecoyShotTick; // 0x1264
	GameTime_t m_flTimeParticleEffectSpawn; // 0x1288
};
class C_AttributeContainer : public CAttributeManager // client
{
	C_EconItemView m_Item; // 0x0050
	int32 m_iExternalItemProviderRegisteredToken; // 0x04C0
	uint64 m_ullRegisteredAsItemID; // 0x04C8
};
class C_CSWeaponBase : public C_BasePlayerWeapon // client
{
	WeaponGameplayAnimState m_iWeaponGameplayAnimState; // 0x1778
	GameTime_t m_flWeaponGameplayAnimStateTimestamp; // 0x177C
	GameTime_t m_flInspectCancelCompleteTime; // 0x1780
	bool m_bInspectPending; // 0x1784
	bool m_bInspectShouldLoop; // 0x1785
	float32 m_flCrosshairDistance; // 0x17B0
	int32 m_iAmmoLastCheck; // 0x17B4
	int32 m_nLastEmptySoundCmdNum; // 0x17B8
	bool m_bFireOnEmpty; // 0x17BC
	CEntityIOOutput m_OnPlayerPickup; // 0x17C0
	CSWeaponMode m_weaponMode; // 0x17D8
	float32 m_flTurningInaccuracyDelta; // 0x17DC
	Vector m_vecTurningInaccuracyEyeDirLast; // 0x17E0
	float32 m_flTurningInaccuracy; // 0x17EC
	float32 m_fAccuracyPenalty; // 0x17F0
	GameTime_t m_flLastAccuracyUpdateTime; // 0x17F4
	float32 m_fAccuracySmoothedForZoom; // 0x17F8
	int32 m_iRecoilIndex; // 0x17FC
	float32 m_flRecoilIndex; // 0x1800
	bool m_bBurstMode; // 0x1804
	GameTime_t m_flLastBurstModeChangeTime; // 0x1808
	GameTick_t m_nPostponeFireReadyTicks; // 0x180C
	float32 m_flPostponeFireReadyFrac; // 0x1810
	bool m_bInReload; // 0x1814
	GameTick_t m_nDeployTick; // 0x1818
	GameTime_t m_flDroppedAtTime; // 0x181C
	bool m_bIsHauledBack; // 0x1824
	bool m_bSilencerOn; // 0x1825
	GameTime_t m_flTimeSilencerSwitchComplete; // 0x1828
	float32 m_flWeaponActionPlaybackRate; // 0x182C
	int32 m_iOriginalTeamNumber; // 0x1830
	int32 m_iMostRecentTeamNumber; // 0x1834
	bool m_bDroppedNearBuyZone; // 0x1838
	float32 m_flNextAttackRenderTimeOffset; // 0x183C
	bool m_bClearWeaponIdentifyingUGC; // 0x18E0
	bool m_bVisualsDataSet; // 0x18E1
	bool m_bUIWeapon; // 0x18E2
	int32 m_nCustomEconReloadEventId; // 0x18E4
	bool m_bCanBePickedUp; // 0x18F0
	GameTime_t m_nextPrevOwnerUseTime; // 0x18F4
	CHandle< C_CSPlayerPawn > m_hPrevOwner; // 0x18F8
	GameTick_t m_nDropTick; // 0x18FC
	bool m_bWasActiveWeaponWhenDropped; // 0x1900
	bool m_donated; // 0x1924
	GameTime_t m_fLastShotTime; // 0x1928
	bool m_bWasOwnedByCT; // 0x192C
	bool m_bWasOwnedByTerrorist; // 0x192D
	float32 m_flNextClientFireBulletTime; // 0x1930
	float32 m_flNextClientFireBulletTime_Repredict; // 0x1934
	C_IronSightController m_IronSightController; // 0x1990
	int32 m_iIronSightMode; // 0x1A40
	GameTime_t m_flLastLOSTraceFailureTime; // 0x1AB8
	float32 m_flWatTickOffset; // 0x1B18
	GameTime_t m_flLastShakeTime; // 0x1B2C
};
class CTimeline : public IntervalTimer // client
{
	float32[64] m_flValues; // 0x0010
	int32[64] m_nValueCounts; // 0x0110
	int32 m_nBucketCount; // 0x0210
	float32 m_flInterval; // 0x0214
	float32 m_flFinalValue; // 0x0218
	TimelineCompression_t m_nCompressionType; // 0x021C
	bool m_bStopped; // 0x0220
};
class CEnvCubemapAPI // client
{
};
class CPulseCursorFuncs // pulse_runtime_lib
{
};
class C_TonemapController2 : public C_BaseEntity // client
{
	float32 m_flAutoExposureMin; // 0x0600
	float32 m_flAutoExposureMax; // 0x0604
	float32 m_flExposureAdaptationSpeedUp; // 0x0608
	float32 m_flExposureAdaptationSpeedDown; // 0x060C
	float32 m_flTonemapEVSmoothingRange; // 0x0610
};
class CountdownTimer // client
{
	float32 m_duration; // 0x0008
	GameTime_t m_timestamp; // 0x000C
	float32 m_timescale; // 0x0010
	WorldGroupId_t m_nWorldGroupId; // 0x0014
};
class PulseNodeDynamicOutflows_t::DynamicOutflow_t // pulse_runtime_lib
{
	CGlobalSymbol m_OutflowID; // 0x0000
	CPulse_OutflowConnection m_Connection; // 0x0008
};
class C_CSGO_PreviewModel_API // client
{
};
class C_WeaponMag7 : public C_CSWeaponBaseGun // client
{
};
class WeaponPurchaseCount_t // client
{
	uint16 m_nItemDefIndex; // 0x0030
	uint16 m_nCount; // 0x0032
};
class CBasePulseGraphInstance // pulse_runtime_lib
{
};
class FilterHealth : public CBaseFilter // client
{
	bool m_bAdrenalineActive; // 0x0638
	int32 m_iHealthMin; // 0x063C
	int32 m_iHealthMax; // 0x0640
};
class C_PointClientUIHUD : public C_BaseClientUIEntity // client
{
	bool m_bCheckCSSClasses; // 0x0FE8
	bool m_bIgnoreInput; // 0x1160
	float32 m_flWidth; // 0x1164
	float32 m_flHeight; // 0x1168
	float32 m_flDPI; // 0x116C
	float32 m_flInteractDistance; // 0x1170
	float32 m_flDepthOffset; // 0x1174
	uint32 m_unOwnerContext; // 0x1178
	uint32 m_unHorizontalAlign; // 0x117C
	uint32 m_unVerticalAlign; // 0x1180
	uint32 m_unOrientation; // 0x1184
	bool m_bAllowInteractionFromAllSceneWorlds; // 0x1188
	C_NetworkUtlVectorBase< CUtlSymbolLarge > m_vecCSSClasses; // 0x1190
};
class CPulseCell_Inflow_GraphHook : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_HookName; // 0x0080
};
class SignatureOutflow_Resume : public CPulse_ResumePoint // pulse_runtime_lib
{
};
class CPathSimpleAPI // client
{
};
class C_InfoLadderDismount : public C_BaseEntity // client
{
};
class C_PointCommentaryNode : public CBaseAnimGraph // client
{
	bool m_bActive; // 0x1198
	bool m_bWasActive; // 0x1199
	GameTime_t m_flEndTime; // 0x119C
	GameTime_t m_flStartTime; // 0x11A0
	float32 m_flStartTimeInCommentary; // 0x11A4
	CUtlSymbolLarge m_iszCommentaryFile; // 0x11A8
	CUtlSymbolLarge m_iszTitle; // 0x11B0
	CUtlSymbolLarge m_iszSpeakers; // 0x11B8
	int32 m_iNodeNumber; // 0x11C0
	int32 m_iNodeNumberMax; // 0x11C4
	bool m_bListenedTo; // 0x11C8
	CSoundPatch* m_sndCommentary; // 0x11D0
	CHandle< C_BaseEntity > m_hViewPosition; // 0x11D8
	bool m_bRestartAfterRestore; // 0x11DC
};
class CSpriteOriented : public C_Sprite // client
{
};
class shard_model_desc_t // client
{
	int32 m_nModelID; // 0x0008
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hMaterialBase; // 0x0010
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hMaterialDamageOverlay; // 0x0018
	ShardSolid_t m_solid; // 0x0020
	Vector2D m_vecPanelSize; // 0x0024
	Vector2D m_vecStressPositionA; // 0x002C
	Vector2D m_vecStressPositionB; // 0x0034
	C_NetworkUtlVectorBase< Vector2D > m_vecPanelVertices; // 0x0040
	C_NetworkUtlVectorBase< Vector4D > m_vInitialPanelVertices; // 0x0058
	float32 m_flGlassHalfThickness; // 0x0070
	bool m_bHasParent; // 0x0074
	bool m_bParentFrozen; // 0x0075
	CUtlStringToken m_SurfacePropStringToken; // 0x0078
};
class C_KeychainModule : public C_CS2WeaponModuleBase // client
{
	uint32 m_nKeychainDefID; // 0x1188
	uint32 m_nKeychainSeed; // 0x118C
};
class CFuncWater : public C_BaseModelEntity // client
{
	CBuoyancyHelper m_BuoyancyHelper; // 0x0FB0
};
class CCSPlayer_GlowServices : public CPlayerPawnComponent // client
{
};
class CCSGameModeRules // client
{
	CNetworkVarChainer __m_pChainEntity; // 0x0008
};
class C_Flashbang : public C_BaseCSGrenade // client
{
};
class C_PointClientUIWorldTextPanel : public C_PointClientUIWorldPanel // client
{
	char[512] m_messageText; // 0x1210
};
class C_CSObserverPawn_API // client
{
};
class CCSPlayer_WaterServices : public CPlayer_WaterServices // client
{
	float32 m_flWaterJumpTime; // 0x0048
	Vector m_vecWaterJumpVel; // 0x004C
	float32 m_flSwimSoundTime; // 0x0058
};
class C_CSObserverPawn : public C_CSPlayerPawnBase // client
{
	CEntityHandle m_hDetectParentChange; // 0x1480
};
class ViewAngleServerChange_t // client
{
	FixAngleSet_t nType; // 0x0030
	QAngle qAngle; // 0x0034
	uint32 nIndex; // 0x0040
};
class C_FuncLadder : public C_BaseModelEntity // client
{
	Vector m_vecLadderDir; // 0x0FB0
	CUtlVector< CHandle< C_InfoLadderDismount > > m_Dismounts; // 0x0FC0
	Vector m_vecLocalTop; // 0x0FD8
	VectorWS m_vecPlayerMountPositionTop; // 0x0FE4
	VectorWS m_vecPlayerMountPositionBottom; // 0x0FF0
	float32 m_flAutoRideSpeed; // 0x0FFC
	bool m_bDisabled; // 0x1000
	bool m_bFakeLadder; // 0x1001
	bool m_bHasSlack; // 0x1002
};
class C_WeaponMP5SD : public C_CSWeaponBaseGun // client
{
};
class C_World : public C_BaseModelEntity // client
{
};
class C_CSGO_TeamSelectCounterTerroristPosition : public C_CSGO_TeamSelectCharacterPosition // client
{
};
class C_WeaponGalilAR : public C_CSWeaponBaseGun // client
{
};
class CCSPlayerBase_CameraServices : public CPlayer_CameraServices // client
{
	uint32 m_iFOV; // 0x0290
	uint32 m_iFOVStart; // 0x0294
	GameTime_t m_flFOVTime; // 0x0298
	float32 m_flFOVRate; // 0x029C
	CHandle< C_BaseEntity > m_hZoomOwner; // 0x02A0
	float32 m_flLastShotFOV; // 0x02A4
};
class C_TeamplayRules : public C_MultiplayRules // client
{
};
class CPulseCell_Inflow_BaseEntrypoint : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseRuntimeChunkIndex_t m_EntryChunk; // 0x0048
	PulseRegisterMap_t m_RegisterMap; // 0x0050
};
class C_WeaponSG556 : public C_CSWeaponBaseGun // client
{
};
class C_CSPlayerPawn : public C_CSPlayerPawnBase // client
{
	CCSPlayer_BulletServices* m_pBulletServices; // 0x1490
	CCSPlayer_HostageServices* m_pHostageServices; // 0x1498
	CCSPlayer_BuyServices* m_pBuyServices; // 0x14A0
	CCSPlayer_GlowServices* m_pGlowServices; // 0x14A8
	CCSPlayer_ActionTrackingServices* m_pActionTrackingServices; // 0x14B0
	CCSPlayer_AimPunchServices* m_pAimPunchServices; // 0x14B8
	CCSPlayer_DamageReactServices* m_pDamageReactServices; // 0x14C0
	GameTime_t m_flHealthShotBoostExpirationTime; // 0x14C8
	GameTime_t m_flLastFiredWeaponTime; // 0x14CC
	bool m_bHasFemaleVoice; // 0x14D0
	float32 m_flLandingTimeSeconds; // 0x14D4
	float32 m_flOldFallVelocity; // 0x14D8
	char[18] m_szLastPlaceName; // 0x14DC
	bool m_bPrevDefuser; // 0x14EE
	bool m_bPrevHelmet; // 0x14EF
	int32 m_nPrevArmorVal; // 0x14F0
	int32 m_nPrevGrenadeAmmoCount; // 0x14F4
	uint32 m_unPreviousWeaponHash; // 0x14F8
	uint32 m_unWeaponHash; // 0x14FC
	bool m_bInBuyZone; // 0x1500
	bool m_bPreviouslyInBuyZone; // 0x1501
	bool m_bInLanding; // 0x1502
	float32 m_flLandingStartTime; // 0x1504
	bool m_bInHostageRescueZone; // 0x1508
	bool m_bInBombZone; // 0x1509
	bool m_bIsBuyMenuOpen; // 0x150A
	GameTime_t m_flTimeOfLastInjury; // 0x150C
	GameTime_t m_flNextSprayDecalTime; // 0x1510
	int32 m_iRetakesOffering; // 0x1670
	int32 m_iRetakesOfferingCard; // 0x1674
	bool m_bRetakesHasDefuseKit; // 0x1678
	bool m_bRetakesMVPLastRound; // 0x1679
	int32 m_iRetakesMVPBoostItem; // 0x167C
	loadout_slot_t m_RetakesMVPBoostExtraUtility; // 0x1680
	bool m_bNeedToReApplyGloves; // 0x1685
	C_EconItemView m_EconGloves; // 0x1688
	uint8 m_nEconGlovesChanged; // 0x1AF8
	bool m_bMustSyncRagdollState; // 0x1AF9
	int32 m_nRagdollDamageBone; // 0x1AFC
	Vector m_vRagdollDamageForce; // 0x1B00
	char[64] m_szRagdollDamageWeaponName; // 0x1B0C
	bool m_bRagdollDamageHeadshot; // 0x1B4C
	VectorWS m_vRagdollServerOrigin; // 0x1B50
	GameTime_t m_lastLandTime; // 0x1B5C
	bool m_bOnGroundLastTick; // 0x1B60
	CHandle< C_CS2HudModelArms > m_hHudModelArms; // 0x1B7C
	QAngle m_qDeathEyeAngles; // 0x1B80
	bool m_bLeftHanded; // 0x1B8C
	GameTime_t m_fSwitchedHandednessTime; // 0x1B90
	float32 m_flViewmodelOffsetX; // 0x1B94
	float32 m_flViewmodelOffsetY; // 0x1B98
	float32 m_flViewmodelOffsetZ; // 0x1B9C
	float32 m_flViewmodelFOV; // 0x1BA0
	uint32[5] m_vecPlayerPatchEconIndices; // 0x1BA4
	Color m_GunGameImmunityColor; // 0x1BE8
	CUtlVector< C_BulletHitModel* > m_vecBulletHitModels; // 0x1C38
	bool m_bIsWalking; // 0x1C50
	EntitySpottedState_t m_entitySpottedState; // 0x1C58
	bool m_bIsScoped; // 0x1C70
	bool m_bResumeZoom; // 0x1C71
	bool m_bIsDefusing; // 0x1C72
	bool m_bIsGrabbingHostage; // 0x1C73
	CSPlayerBlockingUseAction_t m_iBlockingUseActionInProgress; // 0x1C74
	GameTime_t m_flEmitSoundTime; // 0x1C78
	bool m_bInNoDefuseArea; // 0x1C7C
	int32 m_nWhichBombZone; // 0x1C80
	int32 m_iShotsFired; // 0x1C84
	float32 m_flFlinchStack; // 0x1C88
	float32 m_flVelocityModifier; // 0x1C8C
	bool m_bWaitForNoAttack; // 0x1C90
	float32 m_ignoreLadderJumpTime; // 0x1C94
	bool m_bKilledByHeadshot; // 0x1C99
	int32 m_ArmorValue; // 0x1C9C
	uint16 m_unCurrentEquipmentValue; // 0x1CA0
	uint16 m_unRoundStartEquipmentValue; // 0x1CA2
	uint16 m_unFreezetimeEndEquipmentValue; // 0x1CA4
	CEntityIndex m_nLastKillerIndex; // 0x1CA8
	bool m_bOldIsScoped; // 0x1CAC
	bool m_bHasDeathInfo; // 0x1CAD
	float32 m_flDeathInfoTime; // 0x1CB0
	VectorWS m_vecDeathInfoOrigin; // 0x1CB4
	GameTime_t m_grenadeParameterStashTime; // 0x1CF0
	bool m_bGrenadeParametersStashed; // 0x1CF4
	QAngle m_angStashedShootAngles; // 0x1CF8
	VectorWS m_vecStashedGrenadeThrowPosition; // 0x1D04
	Vector m_vecStashedVelocity; // 0x1D10
	bool m_bShouldAutobuyDMWeapons; // 0x3250
	GameTime_t m_fImmuneToGunGameDamageTime; // 0x3254
	bool m_bGunGameImmunity; // 0x3258
	GameTime_t m_fImmuneToGunGameDamageTimeLast; // 0x325C
	float32 m_fMolotovDamageTime; // 0x3260
	ParticleIndex_t m_nPlayerInfernoBodyFx; // 0x32CC
	QAngle m_angEyeAngles; // 0x3340
	GameTime_t[4] m_arrOldEyeAnglesTimes; // 0x33D0
	QAngle[4] m_arrOldEyeAngles; // 0x33E0
	QAngle m_angEyeAnglesVelocity; // 0x3410
	CEntityIndex m_iIDEntIndex; // 0x341C
	CountdownTimer m_delayTargetIDTimer; // 0x3420
	CEntityIndex m_iTargetItemEntIdx; // 0x3438
	CEntityIndex m_iOldIDEntIndex; // 0x343C
	CountdownTimer m_holdTargetIDTimer; // 0x3440
};
class C_CSGO_TeamIntroTerroristPosition : public C_CSGO_TeamIntroCharacterPosition // client
{
};
class CPulseCell_WaitForCursorsWithTagBase : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	int32 m_nCursorsAllowedToWait; // 0x00D8
	CPulse_ResumePoint m_WaitComplete; // 0x00E0
};
class C_Hostage : public C_BaseCombatCharacter // client
{
	EntitySpottedState_t m_entitySpottedState; // 0x1208
	CHandle< C_BaseEntity > m_leader; // 0x1220
	CountdownTimer m_reuseTimer; // 0x1228
	Vector m_vel; // 0x1240
	bool m_isRescued; // 0x124C
	bool m_jumpedThisFrame; // 0x124D
	int32 m_nHostageState; // 0x1250
	bool m_bHandsHaveBeenCut; // 0x1254
	CHandle< C_CSPlayerPawn > m_hHostageGrabber; // 0x1258
	GameTime_t m_fLastGrabTime; // 0x125C
	VectorWS m_vecGrabbedPos; // 0x1260
	GameTime_t m_flRescueStartTime; // 0x126C
	GameTime_t m_flGrabSuccessTime; // 0x1270
	GameTime_t m_flDropStartTime; // 0x1274
	GameTime_t m_flDeadOrRescuedTime; // 0x1278
	CountdownTimer m_blinkTimer; // 0x1280
	VectorWS m_lookAt; // 0x1298
	CountdownTimer m_lookAroundTimer; // 0x12A8
	bool m_isInit; // 0x12C0
	AttachmentHandle_t m_eyeAttachment; // 0x12C1
	AttachmentHandle_t m_chestAttachment; // 0x12C2
	CBasePlayerController* m_pPredictionOwner; // 0x12C8
	GameTime_t m_fNewestAlphaThinkTime; // 0x12D0
};
class C_fogplayerparams_t // client
{
	CHandle< C_FogController > m_hCtrl; // 0x0008
	float32 m_flTransitionTime; // 0x000C
	Color m_OldColor; // 0x0010
	float32 m_flOldStart; // 0x0014
	float32 m_flOldEnd; // 0x0018
	float32 m_flOldMaxDensity; // 0x001C
	float32 m_flOldHDRColorScale; // 0x0020
	float32 m_flOldFarZ; // 0x0024
	Color m_NewColor; // 0x0028
	float32 m_flNewStart; // 0x002C
	float32 m_flNewEnd; // 0x0030
	float32 m_flNewMaxDensity; // 0x0034
	float32 m_flNewHDRColorScale; // 0x0038
	float32 m_flNewFarZ; // 0x003C
};
class CGameSceneNode // client
{
	CTransformWS m_nodeToWorld; // 0x0010
	CEntityInstance* m_pOwner; // 0x0030
	CGameSceneNode* m_pParent; // 0x0038
	CGameSceneNode* m_pChild; // 0x0040
	CGameSceneNode* m_pNextSibling; // 0x0048
	CGameSceneNodeHandle m_hParent; // 0x0070
	CNetworkOriginCellCoordQuantizedVector m_vecOrigin; // 0x0080
	QAngle m_angRotation; // 0x00B8
	float32 m_flScale; // 0x00C4
	VectorWS m_vecAbsOrigin; // 0x00C8
	QAngle m_angAbsRotation; // 0x00D4
	float32 m_flAbsScale; // 0x00E0
	Vector m_vecWrappedLocalOrigin; // 0x00E4
	QAngle m_angWrappedLocalRotation; // 0x00F0
	float32 m_flWrappedScale; // 0x00FC
	int16 m_nParentAttachmentOrBone; // 0x0100
	bool m_bDebugAbsOriginChanges; // 0x0102
	bool m_bDormant; // 0x0103
	bool m_bForceParentToBeNetworked; // 0x0104
	bitfield:1 m_bDirtyHierarchy; // 0x0000
	bitfield:1 m_bDirtyBoneMergeInfo; // 0x0000
	bitfield:1 m_bNetworkedPositionChanged; // 0x0000
	bitfield:1 m_bNetworkedAnglesChanged; // 0x0000
	bitfield:1 m_bNetworkedScaleChanged; // 0x0000
	bitfield:1 m_bWillBeCallingPostDataUpdate; // 0x0000
	bitfield:1 m_bBoneMergeFlex; // 0x0000
	bitfield:2 m_nLatchAbsOrigin; // 0x0000
	bitfield:1 m_bDirtyBoneMergeBoneToRoot; // 0x0000
	uint8 m_nHierarchicalDepth; // 0x0107
	uint8 m_nHierarchyType; // 0x0108
	uint8 m_nDoNotSetAnimTimeInInvalidatePhysicsCount; // 0x0109
	CUtlStringToken m_name; // 0x010C
	CUtlStringToken m_hierarchyAttachName; // 0x0120
	float32 m_flClientLocalScale; // 0x0124
};
class CPlayer_ObserverServices : public CPlayerPawnComponent // client
{
	uint8 m_iObserverMode; // 0x0048
	CHandle< C_BaseEntity > m_hObserverTarget; // 0x004C
	ObserverMode_t m_iObserverLastMode; // 0x0050
	bool m_bForcedObserverMode; // 0x0054
	float32 m_flObserverChaseDistance; // 0x0058
	GameTime_t m_flObserverChaseDistanceCalcTime; // 0x005C
};
class CCashStack : public C_BaseModelEntity // client
{
	int32 m_nCashStackValue; // 0x0FB0
};
class C_SoundAreaEntityBase : public C_BaseEntity // client
{
	bool m_bDisabled; // 0x0600
	bool m_bWasEnabled; // 0x0608
	CUtlSymbolLarge m_iszSoundAreaType; // 0x0610
	Vector m_vPos; // 0x0618
};
class C_PlayerVisibility : public C_BaseEntity // client
{
	float32 m_flVisibilityStrength; // 0x0600
	float32 m_flFogDistanceMultiplier; // 0x0604
	float32 m_flFogMaxDensityMultiplier; // 0x0608
	float32 m_flFadeTime; // 0x060C
	bool m_bStartDisabled; // 0x0610
	bool m_bIsEnabled; // 0x0611
};
class CAttributeManager::cached_attribute_float_t // client
{
	float32 flIn; // 0x0000
	CUtlSymbolLarge iAttribHook; // 0x0008
	float32 flOut; // 0x0010
};
class C_BasePlayerWeapon : public C_EconEntity // client
{
	GameTick_t m_nNextPrimaryAttackTick; // 0x16F0
	float32 m_flNextPrimaryAttackTickRatio; // 0x16F4
	GameTick_t m_nNextSecondaryAttackTick; // 0x16F8
	float32 m_flNextSecondaryAttackTickRatio; // 0x16FC
	int32 m_iClip1; // 0x1700
	int32 m_iClip2; // 0x1704
	int32[2] m_pReserveAmmo; // 0x1708
};
class CRagdollManager : public C_BaseEntity // client
{
	int8 m_iCurrentMaxRagdollCount; // 0x0600
};
class CSoundOpvarSetBoxEntity : public C_SoundOpvarSetPointEntity // client
{
};
class C_HEGrenade : public C_BaseCSGrenade // client
{
};
class C_EnvSky : public C_BaseModelEntity // client
{
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hSkyMaterial; // 0x0FB0
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hSkyMaterialLightingOnly; // 0x0FB8
	bool m_bStartDisabled; // 0x0FC0
	Color m_vTintColor; // 0x0FC1
	Color m_vTintColorLightingOnly; // 0x0FC5
	float32 m_flBrightnessScale; // 0x0FCC
	int32 m_nFogType; // 0x0FD0
	float32 m_flFogMinStart; // 0x0FD4
	float32 m_flFogMinEnd; // 0x0FD8
	float32 m_flFogMaxStart; // 0x0FDC
	float32 m_flFogMaxEnd; // 0x0FE0
	bool m_bEnabled; // 0x0FE4
};
class CPulse_InvokeBinding // pulse_runtime_lib
{
	PulseRegisterMap_t m_RegisterMap; // 0x0000
	PulseSymbol_t m_FuncName; // 0x0030
	PulseRuntimeCellIndex_t m_nCellIndex; // 0x0040
	PulseRuntimeChunkIndex_t m_nSrcChunk; // 0x0044
	int32 m_nSrcInstruction; // 0x0048
};
class C_EnvWindController : public C_BaseEntity // client
{
	C_EnvWindShared m_EnvWindShared; // 0x0600
	float32 m_fDirectionVariation; // 0x06F8
	float32 m_fSpeedVariation; // 0x06FC
	float32 m_fTurbulence; // 0x0700
	float32 m_fVolumeHalfExtentXY; // 0x0704
	float32 m_fVolumeHalfExtentZ; // 0x0708
	int32 m_nVolumeResolutionXY; // 0x070C
	int32 m_nVolumeResolutionZ; // 0x0710
	int32 m_nClipmapLevels; // 0x0714
	bool m_bIsMaster; // 0x0718
	bool m_bFirstTime; // 0x0719
};
class C_GameRules // client
{
	CNetworkVarChainer __m_pChainEntity; // 0x0008
	int32 m_nTotalPausedTicks; // 0x0030
	int32 m_nPauseStartTick; // 0x0034
	bool m_bGamePaused; // 0x0038
};
class C_WeaponMAC10 : public C_CSWeaponBaseGun // client
{
};
class C_CSGO_MapPreviewCameraPath : public C_BaseEntity // client
{
	float32 m_flZFar; // 0x0600
	float32 m_flZNear; // 0x0604
	bool m_bLoop; // 0x0608
	bool m_bVerticalFOV; // 0x0609
	bool m_bConstantSpeed; // 0x060A
	float32 m_flDuration; // 0x060C
	float32 m_flPathLength; // 0x0650
	float32 m_flPathDuration; // 0x0654
	bool m_bDofEnabled; // 0x066C
	float32 m_flDofNearBlurry; // 0x0670
	float32 m_flDofNearCrisp; // 0x0674
	float32 m_flDofFarCrisp; // 0x0678
	float32 m_flDofFarBlurry; // 0x067C
	float32 m_flDofTiltToGround; // 0x0680
};
class C_PointWorldText : public C_ModelPointEntity // client
{
	bool m_bForceRecreateNextUpdate; // 0x0FB8
	int32 m_nTextWidthPx; // 0x0FD0
	int32 m_nTextHeightPx; // 0x0FD4
	char[512] m_messageText; // 0x0FD8
	char[64] m_FontName; // 0x11D8
	char[64] m_BackgroundMaterialName; // 0x1218
	bool m_bEnabled; // 0x1258
	bool m_bFullbright; // 0x1259
	float32 m_flWorldUnitsPerPx; // 0x125C
	float32 m_flFontSize; // 0x1260
	float32 m_flDepthOffset; // 0x1264
	bool m_bDrawBackground; // 0x1268
	float32 m_flBackgroundBorderWidth; // 0x126C
	float32 m_flBackgroundBorderHeight; // 0x1270
	float32 m_flBackgroundWorldToUV; // 0x1274
	Color m_Color; // 0x1278
	PointWorldTextJustifyHorizontal_t m_nJustifyHorizontal; // 0x127C
	PointWorldTextJustifyVertical_t m_nJustifyVertical; // 0x1280
	PointWorldTextReorientMode_t m_nReorientMode; // 0x1284
};
class C_RopeKeyframe : public C_BaseModelEntity // client
{
	CBitVec< 10 > m_LinksTouchingSomething; // 0x0FB8
	int32 m_nLinksTouchingSomething; // 0x0FBC
	bool m_bApplyWind; // 0x0FC0
	int32 m_fPrevLockedPoints; // 0x0FC4
	int32 m_iForcePointMoveCounter; // 0x0FC8
	bool[2] m_bPrevEndPointPos; // 0x0FCC
	VectorWS[2] m_vPrevEndPointPos; // 0x0FD0
	float32 m_flCurScroll; // 0x0FE8
	float32 m_flScrollSpeed; // 0x0FEC
	uint16 m_RopeFlags; // 0x0FF0
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_iRopeMaterialModelIndex; // 0x0FF8
	uint8 m_nSegments; // 0x1270
	CHandle< C_BaseEntity > m_hStartPoint; // 0x1274
	CHandle< C_BaseEntity > m_hEndPoint; // 0x1278
	AttachmentHandle_t m_iStartAttachment; // 0x127C
	AttachmentHandle_t m_iEndAttachment; // 0x127D
	uint8 m_Subdiv; // 0x127E
	int16 m_RopeLength; // 0x1280
	int16 m_Slack; // 0x1282
	float32 m_TextureScale; // 0x1284
	uint8 m_fLockedPoints; // 0x1288
	uint8 m_nChangeCount; // 0x1289
	float32 m_Width; // 0x128C
	C_RopeKeyframe::CPhysicsDelegate m_PhysicsDelegate; // 0x1290
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hMaterial; // 0x12A0
	int32 m_TextureHeight; // 0x12A8
	Vector m_vecImpulse; // 0x12AC
	Vector m_vecPreviousImpulse; // 0x12B8
	float32 m_flCurrentGustTimer; // 0x12C4
	float32 m_flCurrentGustLifetime; // 0x12C8
	float32 m_flTimeToNextGust; // 0x12CC
	Vector m_vWindDir; // 0x12D0
	Vector m_vColorMod; // 0x12DC
	VectorWS[2] m_vCachedEndPointAttachmentPos; // 0x12E8
	QAngle[2] m_vCachedEndPointAttachmentAngle; // 0x1300
	bool m_bConstrainBetweenEndpoints; // 0x1318
	bitfield:1 m_bEndPointAttachmentPositionsDirty; // 0x0000
	bitfield:1 m_bEndPointAttachmentAnglesDirty; // 0x0000
	bitfield:1 m_bNewDataThisFrame; // 0x0000
	bitfield:1 m_bPhysicsInitted; // 0x0000
};
class C_BaseToggle : public C_BaseModelEntity // client
{
};
class C_EnvCubemapBox : public C_EnvCubemap // client
{
};
class C_EnvCombinedLightProbeVolumeAlias_func_combined_light_probe_volume : public C_EnvCombinedLightProbeVolume // client
{
};
class C_RopeKeyframe::CPhysicsDelegate // client
{
	C_RopeKeyframe* m_pKeyframe; // 0x0008
};
class CInfoDynamicShadowHint : public C_PointEntity // client
{
	bool m_bDisabled; // 0x0600
	float32 m_flRange; // 0x0604
	int32 m_nImportance; // 0x0608
	int32 m_nLightChoice; // 0x060C
	CHandle< C_BaseEntity > m_hLight; // 0x0610
};
class CPathNode : public C_PointEntity // client
{
	Vector m_vInTangentLocal; // 0x0600
	Vector m_vOutTangentLocal; // 0x060C
	CUtlString m_strParentPathUniqueID; // 0x0618
	CUtlString m_strPathNodeParameter; // 0x0620
	CTransformWS m_xWSPrevParent; // 0x0630
	CHandle< CPathWithDynamicNodes > m_hPath; // 0x0650
};
class C_FuncMoveLinear : public C_BaseToggle // client
{
};
class CServerOnlyModelEntity : public C_BaseModelEntity // client
{
};
class C_CSGO_TeamSelectCamera : public C_CSGO_TeamPreviewCamera // client
{
};
class CPulseCell_IntervalTimer : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_Completed; // 0x00D8
	SignatureOutflow_Continue m_OnInterval; // 0x0120
};
class C_WeaponXM1014 : public C_CSWeaponBaseShotgun // client
{
};
class C_WorldModelGloves : public CBaseAnimGraph // client
{
};
class C_PhysicsPropMultiplayer : public C_PhysicsProp // client
{
};
class C_SoundEventOBBEntity : public C_SoundEventEntity // client
{
	Vector m_vMins; // 0x06C0
	Vector m_vMaxs; // 0x06CC
};
class CPulseTestScriptLib // pulse_runtime_lib
{
};
class CPulseCell_BaseLerp : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_WakeResume; // 0x00D8
};
class C_WeaponAug : public C_CSWeaponBaseGun // client
{
};
class C_BasePropDoor : public C_DynamicProp // client
{
	DoorState_t m_eDoorState; // 0x13D0
	bool m_modelChanged; // 0x13D4
	bool m_bLocked; // 0x13D5
	bool m_bNoNPCs; // 0x13D6
	VectorWS m_closedPosition; // 0x13D8
	QAngle m_closedAngles; // 0x13E4
	CHandle< C_BasePropDoor > m_hMaster; // 0x13F0
	VectorWS m_vWhereToSetLightingOrigin; // 0x13F4
};
class CPointValueRemapperAPI // client
{
};
class CChoreoInfoTarget : public C_PointEntity // client
{
};
class C_CsmFovOverride_API // client
{
};
class CTakeDamageResultAPI // client
{
};
class CNetworkedSequenceOperation // client
{
	HSequence m_hSequence; // 0x0008
	float32 m_flPrevCycle; // 0x000C
	float32 m_flCycle; // 0x0010
	CNetworkedQuantizedFloat m_flWeight; // 0x0014
	bool m_bSequenceChangeNetworked; // 0x001C
	bool m_bDiscontinuity; // 0x001D
	float32 m_flPrevCycleFromDiscontinuity; // 0x0020
	float32 m_flPrevCycleForAnimEventDetection; // 0x0024
};
class C_Item_Healthshot : public C_WeaponBaseItem // client
{
};
class CEntityInstance // entity2
{
	CUtlSymbolLarge m_iszPrivateVScripts; // 0x0008
	CEntityIdentity* m_pEntity; // 0x0010
	CScriptComponent* m_CScriptComponent; // 0x0028
};
class C_BaseModelEntity : public C_BaseEntity // client
{
	CRenderComponent* m_CRenderComponent; // 0x0AF0
	CHitboxComponent m_CHitboxComponent; // 0x0AF8
	CChoreoComponent* m_pChoreoComponent; // 0x0B10
	HitGroup_t m_nDestructiblePartInitialStateDestructed0; // 0x0B18
	HitGroup_t m_nDestructiblePartInitialStateDestructed1; // 0x0B1C
	HitGroup_t m_nDestructiblePartInitialStateDestructed2; // 0x0B20
	HitGroup_t m_nDestructiblePartInitialStateDestructed3; // 0x0B24
	HitGroup_t m_nDestructiblePartInitialStateDestructed4; // 0x0B28
	int32 m_nDestructiblePartInitialStateDestructed0_PartIndex; // 0x0B2C
	int32 m_nDestructiblePartInitialStateDestructed1_PartIndex; // 0x0B30
	int32 m_nDestructiblePartInitialStateDestructed2_PartIndex; // 0x0B34
	int32 m_nDestructiblePartInitialStateDestructed3_PartIndex; // 0x0B38
	int32 m_nDestructiblePartInitialStateDestructed4_PartIndex; // 0x0B3C
	bool m_bDestructiblePartInitialStateDestructed0_GenerateBreakpieces; // 0x0B40
	bool m_bDestructiblePartInitialStateDestructed1_GenerateBreakpieces; // 0x0B41
	bool m_bDestructiblePartInitialStateDestructed2_GenerateBreakpieces; // 0x0B42
	bool m_bDestructiblePartInitialStateDestructed3_GenerateBreakpieces; // 0x0B43
	bool m_bDestructiblePartInitialStateDestructed4_GenerateBreakpieces; // 0x0B44
	CDestructiblePartsComponent* m_pDestructiblePartsSystemComponent; // 0x0B48
	bool m_bInitModelEffects; // 0x0C70
	bool m_bDoingModelEffects; // 0x0C71
	int32 m_iOldHealth; // 0x0C74
	RenderMode_t m_nRenderMode; // 0x0C78
	RenderFx_t m_nRenderFX; // 0x0C79
	bool m_bAllowFadeInView; // 0x0C7A
	Color m_clrRender; // 0x0C98
	C_UtlVectorEmbeddedNetworkVar< EntityRenderAttribute_t > m_vecRenderAttributes; // 0x0CA0
	bool m_bRenderToCubemaps; // 0x0D20
	bool m_bNoInterpolate; // 0x0D21
	CCollisionProperty m_Collision; // 0x0D28
	CGlowProperty m_Glow; // 0x0DE0
	float32 m_flGlowBackfaceMult; // 0x0E38
	float32 m_fadeMinDist; // 0x0E3C
	float32 m_fadeMaxDist; // 0x0E40
	float32 m_flFadeScale; // 0x0E44
	float32 m_flShadowStrength; // 0x0E48
	uint8 m_nObjectCulling; // 0x0E4C
	DecalRtEncoding_t m_nRequiredDecalRtEncoding; // 0x0E4D
	CUtlOrderedMap< CGlobalSymbol, int32 > m_bodyGroupChoices; // 0x0E50
	CNetworkViewOffsetVector m_vecViewOffset; // 0x0E78
	CClientAlphaProperty* m_pClientAlphaProperty; // 0x0F58
	Color m_ClientOverrideTint; // 0x0F60
	bool m_bUseClientOverrideTint; // 0x0F64
	uint32[1] m_bvDisabledHitGroups; // 0x0FA0
};
class CCSPlayer_BulletServices : public CPlayerPawnComponent // client
{
	int32 m_totalHitsOnServer; // 0x0048
};
class C_SoundOpvarSetAutoRoomEntity : public C_SoundOpvarSetPointEntity // client
{
};
class C_EnvCombinedLightProbeVolume : public C_BaseEntity // client
{
	Color m_Entity_Color; // 0x1678
	float32 m_Entity_flBrightness; // 0x167C
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hCubemapTexture; // 0x1680
	bool m_Entity_bCustomCubemapTexture; // 0x1688
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_AmbientCube; // 0x1690
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SDF; // 0x1698
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_DC; // 0x16A0
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_R; // 0x16A8
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_G; // 0x16B0
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_B; // 0x16B8
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeDirectLightIndicesTexture; // 0x16C0
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeDirectLightScalarsTexture; // 0x16C8
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeDirectLightShadowsTexture; // 0x16D0
	Vector m_Entity_vBoxMins; // 0x16D8
	Vector m_Entity_vBoxMaxs; // 0x16E4
	bool m_Entity_bMoveable; // 0x16F0
	int32 m_Entity_nHandshake; // 0x16F4
	int32 m_Entity_nEnvCubeMapArrayIndex; // 0x16F8
	int32 m_Entity_nPriority; // 0x16FC
	bool m_Entity_bStartDisabled; // 0x1700
	float32 m_Entity_flEdgeFadeDist; // 0x1704
	Vector m_Entity_vEdgeFadeDists; // 0x1708
	int32 m_Entity_nLightProbeSizeX; // 0x1714
	int32 m_Entity_nLightProbeSizeY; // 0x1718
	int32 m_Entity_nLightProbeSizeZ; // 0x171C
	int32 m_Entity_nLightProbeAtlasX; // 0x1720
	int32 m_Entity_nLightProbeAtlasY; // 0x1724
	int32 m_Entity_nLightProbeAtlasZ; // 0x1728
	bool m_Entity_bEnabled; // 0x1741
};
class CCSGO_EndOfMatchLineupEnd : public C_CSGO_EndOfMatchLineupEndpoint // client
{
};
class C_MultiplayRules : public C_GameRules // client
{
};
class CPlayer_AutoaimServices : public CPlayerPawnComponent // client
{
};
class CEnvWindSharedAPI // client
{
};
class C_LightDirectionalEntity : public C_LightEntity // client
{
};
class CMapInfo_API // client
{
};
class C_BaseEntity : public CEntityInstance // client
{
	CBodyComponent* m_CBodyComponent; // 0x0030
	CNetworkTransmitComponent m_NetworkTransmitComponent; // 0x0038
	GameTick_t m_nLastThinkTick; // 0x0328
	CGameSceneNode* m_pGameSceneNode; // 0x0330
	CRenderComponent* m_pRenderComponent; // 0x0338
	CCollisionProperty* m_pCollision; // 0x0340
	int32 m_iMaxHealth; // 0x0348
	int32 m_iHealth; // 0x034C
	float32 m_flDamageAccumulator; // 0x0350
	uint8 m_lifeState; // 0x0354
	bool m_bTakesDamage; // 0x0355
	TakeDamageFlags_t m_nTakeDamageFlags; // 0x0358
	EntityPlatformTypes_t m_nPlatformType; // 0x0360
	uint8 m_ubInterpolationFrame; // 0x0361
	CHandle< C_BaseEntity > m_hSceneObjectController; // 0x0364
	int32 m_nNoInterpolationTick; // 0x0368
	int32 m_nVisibilityNoInterpolationTick; // 0x036C
	float32 m_flProxyRandomValue; // 0x0370
	int32 m_iEFlags; // 0x0374
	uint8 m_nWaterType; // 0x0378
	bool m_bInterpolateEvenWithNoModel; // 0x0379
	bool m_bPredictionEligible; // 0x037A
	bool m_bApplyLayerMatchIDToModel; // 0x037B
	CUtlStringToken m_tokLayerMatchID; // 0x037C
	CUtlStringToken m_nSubclassID; // 0x0380
	int32 m_nSimulationTick; // 0x0390
	int32 m_iCurrentThinkContext; // 0x0394
	CUtlVector< thinkfunc_t > m_aThinkFunctions; // 0x0398
	bool m_bDisabledContextThinks; // 0x03B0
	float32 m_flAnimTime; // 0x03B4
	float32 m_flSimulationTime; // 0x03B8
	uint8 m_nSceneObjectOverrideFlags; // 0x03BC
	bool m_bHasSuccessfullyInterpolated; // 0x03BD
	bool m_bHasAddedVarsToInterpolation; // 0x03BE
	bool m_bRenderEvenWhenNotSuccessfullyInterpolated; // 0x03BF
	int32[2] m_nInterpolationLatchDirtyFlags; // 0x03C0
	uint16[11] m_ListEntry; // 0x03C8
	GameTime_t m_flCreateTime; // 0x03E0
	uint16 m_EntClientFlags; // 0x03E4
	bool m_bClientSideRagdoll; // 0x03E6
	uint8 m_iTeamNum; // 0x03E7
	uint32 m_spawnflags; // 0x03E8
	GameTick_t m_nNextThinkTick; // 0x03EC
	uint32 m_fFlags; // 0x03F4
	Vector m_vecAbsVelocity; // 0x03F8
	CNetworkVelocityVector m_vecServerVelocity; // 0x0404
	CNetworkVelocityVector m_vecVelocity; // 0x0430
	Vector m_vecBaseVelocity; // 0x0510
	CHandle< C_BaseEntity > m_hEffectEntity; // 0x051C
	CHandle< C_BaseEntity > m_hOwnerEntity; // 0x0520
	MoveCollide_t m_MoveCollide; // 0x0524
	MoveType_t m_MoveType; // 0x0525
	MoveType_t m_nActualMoveType; // 0x0526
	float32 m_flWaterLevel; // 0x0528
	uint32 m_fEffects; // 0x052C
	CHandle< C_BaseEntity > m_hGroundEntity; // 0x0530
	int32 m_nGroundBodyIndex; // 0x0534
	float32 m_flFriction; // 0x0538
	float32 m_flElasticity; // 0x053C
	float32 m_flGravityScale; // 0x0540
	float32 m_flTimeScale; // 0x0544
	bool m_bAnimatedEveryTick; // 0x0548
	bool m_bGravityDisabled; // 0x0549
	GameTime_t m_flNavIgnoreUntilTime; // 0x054C
	uint16 m_hThink; // 0x0550
	uint8 m_fBBoxVisFlags; // 0x0560
	float32 m_flActualGravityScale; // 0x0564
	bool m_bGravityActuallyDisabled; // 0x0568
	bool m_bPredictable; // 0x0569
	bool m_bRenderWithViewModels; // 0x056A
	int32 m_nFirstPredictableCommand; // 0x056C
	int32 m_nLastPredictableCommand; // 0x0570
	CHandle< C_BaseEntity > m_hOldMoveParent; // 0x0574
	CParticleProperty m_Particles; // 0x0578
	QAngle m_vecAngVelocity; // 0x05A8
	int32 m_DataChangeEventRef; // 0x05B4
	CUtlVector< CEntityHandle > m_dependencies; // 0x05B8
	int32 m_nCreationTick; // 0x05D0
	bool m_bAnimTimeChanged; // 0x05E1
	bool m_bSimulationTimeChanged; // 0x05E2
	CUtlString m_sUniqueHammerID; // 0x05F0
	BloodType m_nBloodType; // 0x05F8
};
class ActiveModelConfig_t // client
{
	ModelConfigHandle_t m_Handle; // 0x0030
	CUtlSymbolLarge m_Name; // 0x0038
	C_NetworkUtlVectorBase< CHandle< C_BaseModelEntity > > m_AssociatedEntities; // 0x0040
	C_NetworkUtlVectorBase< CUtlSymbolLarge > m_AssociatedEntityNames; // 0x0058
};
class C_WeaponSSG08 : public C_CSWeaponBaseGun // client
{
};
class CPulseCell_Value_Curve : public CPulseCell_BaseValue // pulse_runtime_lib
{
	CPiecewiseCurve m_Curve; // 0x0048
};
class C_Chicken : public C_DynamicProp // client
{
	CHandle< C_CSPlayerPawn > m_leader; // 0x13C8
	C_AttributeContainer m_AttributeManager; // 0x13D0
	bool m_bAttributesInitialized; // 0x18A0
	ParticleIndex_t m_hWaterWakeParticles; // 0x18A4
	bool m_bIsPreviewModel; // 0x18A8
};
class C_BasePlayerPawn : public C_BaseCombatCharacter // client
{
	CPlayer_WeaponServices* m_pWeaponServices; // 0x1208
	CPlayer_ItemServices* m_pItemServices; // 0x1210
	CPlayer_AutoaimServices* m_pAutoaimServices; // 0x1218
	CPlayer_ObserverServices* m_pObserverServices; // 0x1220
	CPlayer_WaterServices* m_pWaterServices; // 0x1228
	CPlayer_UseServices* m_pUseServices; // 0x1230
	CPlayer_FlashlightServices* m_pFlashlightServices; // 0x1238
	CPlayer_CameraServices* m_pCameraServices; // 0x1240
	CPlayer_MovementServices* m_pMovementServices; // 0x1248
	C_UtlVectorEmbeddedNetworkVar< ViewAngleServerChange_t > m_ServerViewAngleChanges; // 0x1258
	QAngle v_angle; // 0x12C0
	QAngle v_anglePrevious; // 0x12CC
	uint32 m_iHideHUD; // 0x12D8
	sky3dparams_t m_skybox3d; // 0x12E0
	GameTime_t m_flDeathTime; // 0x1370
	Vector m_vecPredictionError; // 0x1374
	GameTime_t m_flPredictionErrorTime; // 0x1380
	Vector m_vecLastCameraSetupLocalOrigin; // 0x13A0
	GameTime_t m_flLastCameraSetupTime; // 0x13AC
	float32 m_flFOVSensitivityAdjust; // 0x13B0
	float32 m_flMouseSensitivity; // 0x13B4
	Vector m_vOldOrigin; // 0x13B8
	float32 m_flOldSimulationTime; // 0x13C4
	int32 m_nLastExecutedCommandNumber; // 0x13C8
	int32 m_nLastExecutedCommandTick; // 0x13CC
	CHandle< CBasePlayerController > m_hController; // 0x13D0
	CHandle< CBasePlayerController > m_hDefaultController; // 0x13D4
	bool m_bIsSwappingToPredictableController; // 0x13D8
};
class C_SoundOpvarSetAABBEntity : public CSoundOpvarSetBoxEntity // client
{
};
class C_WeaponBizon : public C_CSWeaponBaseGun // client
{
};
class C_StattrakModule : public C_CS2WeaponModuleBase // client
{
	bool m_bKnife; // 0x1188
};
class CCSObserver_CameraServices : public CCSPlayerBase_CameraServices // client
{
	CHandle< C_PostProcessingVolume > m_hPrevPostProcessingVolume; // 0x02A8
};
class CEnvSoundscapeProxy : public CEnvSoundscape // client
{
	CUtlSymbolLarge m_MainSoundscapeName; // 0x0690
};
class C_SoundEventEntity : public C_BaseEntity // client
{
	bool m_bStartOnSpawn; // 0x0600
	bool m_bToLocalPlayer; // 0x0601
	bool m_bStopOnNew; // 0x0602
	bool m_bSaveRestore; // 0x0603
	bool m_bSavedIsPlaying; // 0x0604
	float32 m_flSavedElapsedTime; // 0x0608
	CUtlSymbolLarge m_iszSourceEntityName; // 0x0610
	CUtlSymbolLarge m_iszAttachmentName; // 0x0618
	CEntityOutputTemplate< SndOpEventGuid_t > m_onGUIDChanged; // 0x0620
	CEntityIOOutput m_onSoundFinished; // 0x0650
	float32 m_flClientCullRadius; // 0x0668
	CUtlSymbolLarge m_iszSoundName; // 0x0698
	CEntityHandle m_hSource; // 0x06B4
	int32 m_nEntityIndexSelection; // 0x06B8
	bitfield:1 m_bClientSideOnly; // 0x0000
};
class CPulseCell_Inflow_EventHandler : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_EventName; // 0x0080
};
class C_LightOrthoEntity : public C_LightEntity // client
{
};
class CPulseCell_BaseFlow : public CPulseCell_Base // pulse_runtime_lib
{
};
class CBombTarget : public C_BaseTrigger // client
{
	bool m_bBombPlantedHere; // 0x1098
};
class C_Knife : public C_CSWeaponBase // client
{
	bool m_bFirstAttack; // 0x1CE0
};
class C_CSGO_TerroristWingmanIntroCamera : public C_CSGO_TeamPreviewCamera // client
{
};
class CSkeletonInstance : public CGameSceneNode // client
{
	CModelState m_modelState; // 0x0140
	bool m_bUseParentRenderBounds; // 0x03F0
	bool m_bDisableSolidCollisionsForHierarchy; // 0x03F1
	bool m_bDirtyMotionType; // 0x03F2
	bool m_bIsGeneratingLatchedParentSpaceState; // 0x03F3
	CUtlStringToken m_materialGroup; // 0x03F8
	uint8 m_nHitboxSet; // 0x03FC
};
class CEntityComponent // entity2
{
};
class C_ItemDogtags : public C_Item // client
{
	CHandle< C_CSPlayerPawn > m_OwningPlayer; // 0x17F0
	CHandle< C_CSPlayerPawn > m_KillingPlayer; // 0x17F4
};
class C_LateUpdatedAnimating : public CBaseAnimGraph // client
{
};
class CPulseCell_Outflow_CycleShuffled::InstanceState_t // pulse_runtime_lib
{
	CUtlVectorFixedGrowable< uint8, 8 > m_Shuffle; // 0x0000
	int32 m_nNextShuffle; // 0x0020
};
class CPulseCell_BaseLerp::CursorState_t // pulse_runtime_lib
{
	GameTime_t m_StartTime; // 0x0000
	GameTime_t m_EndTime; // 0x0004
};
class C_BaseClientUIEntity : public C_BaseModelEntity // client
{
	bool m_bEnabled; // 0x0FB8
	CUtlSymbolLarge m_DialogXMLName; // 0x0FC0
	CUtlSymbolLarge m_PanelClassName; // 0x0FC8
	CUtlSymbolLarge m_PanelID; // 0x0FD0
};
class CPulseArraylib // pulse_runtime_lib
{
};
class C_WeaponUSPSilencer : public C_CSWeaponBaseGun // client
{
};
class C_MolotovProjectile : public C_BaseCSGrenadeProjectile // client
{
	bool m_bIsIncGrenade; // 0x1260
};
class C_TriggerLerpObject : public C_BaseTrigger // client
{
};
class CPointTemplateAPI // client
{
};
class C_WeaponRevolver : public C_CSWeaponBaseGun // client
{
};
class C_WeaponElite : public C_CSWeaponBaseGun // client
{
};
class C_DynamicPropAlias_cable_dynamic : public C_DynamicProp // client
{
};
class CBaseProp : public CBaseAnimGraph // client
{
	bool m_bModelOverrodeBlockLOS; // 0x1180
	int32 m_iShapeType; // 0x1184
	bool m_bConformToCollisionBounds; // 0x1188
	CTransform m_mPreferredCatchTransform; // 0x1190
};
class CInfoOffscreenPanoramaTexture : public C_PointEntity // client
{
	bool m_bDisabled; // 0x0600
	int32 m_nResolutionX; // 0x0604
	int32 m_nResolutionY; // 0x0608
	CUtlSymbolLarge m_szPanelType; // 0x0610
	CUtlSymbolLarge m_szLayoutFileName; // 0x0618
	CUtlSymbolLarge m_RenderAttrName; // 0x0620
	C_NetworkUtlVectorBase< CHandle< C_BaseModelEntity > > m_TargetEntities; // 0x0628
	int32 m_nTargetChangeCount; // 0x0640
	C_NetworkUtlVectorBase< CUtlSymbolLarge > m_vecCSSClasses; // 0x0648
	CUtlSymbolLarge m_szTargetsName; // 0x0660
	CUtlVector< CHandle< C_BaseModelEntity > > m_AdditionalTargetEntities; // 0x0668
	bool m_bCheckCSSClasses; // 0x07E0
};
class CCSWeaponBaseVData : public CBasePlayerWeaponVData // client
{
	CSWeaponType m_WeaponType; // 0x0520
	CSWeaponCategory m_WeaponCategory; // 0x0524
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCNmSkeleton > > m_szAnimSkeleton; // 0x0528
	Vector m_vecMuzzlePos0; // 0x0608
	Vector m_vecMuzzlePos1; // 0x0614
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > > m_szTracerParticle; // 0x0620
	gear_slot_t m_GearSlot; // 0x0700
	int32 m_GearSlotPosition; // 0x0704
	loadout_slot_t m_DefaultLoadoutSlot; // 0x0708
	int32 m_nPrice; // 0x070C
	int32 m_nKillAward; // 0x0710
	int32 m_nPrimaryReserveAmmoMax; // 0x0714
	int32 m_nSecondaryReserveAmmoMax; // 0x0718
	bool m_bMeleeWeapon; // 0x071C
	bool m_bHasBurstMode; // 0x071D
	bool m_bIsRevolver; // 0x071E
	bool m_bCannotShootUnderwater; // 0x071F
	CGlobalSymbol m_szName; // 0x0720
	CSWeaponSilencerType m_eSilencerType; // 0x0728
	int32 m_nCrosshairMinDistance; // 0x072C
	int32 m_nCrosshairDeltaDistance; // 0x0730
	bool m_bIsFullAuto; // 0x0734
	int32 m_nNumBullets; // 0x0738
	bool m_bReloadsSingleShells; // 0x073C
	CFiringModeFloat m_flCycleTime; // 0x0740
	float32 m_flCycleTimeWhenInBurstMode; // 0x0748
	float32 m_flTimeBetweenBurstShots; // 0x074C
	CFiringModeFloat m_flMaxSpeed; // 0x0750
	CFiringModeFloat m_flSpread; // 0x0758
	CFiringModeFloat m_flInaccuracyCrouch; // 0x0760
	CFiringModeFloat m_flInaccuracyStand; // 0x0768
	CFiringModeFloat m_flInaccuracyJump; // 0x0770
	CFiringModeFloat m_flInaccuracyLand; // 0x0778
	CFiringModeFloat m_flInaccuracyLadder; // 0x0780
	CFiringModeFloat m_flInaccuracyFire; // 0x0788
	CFiringModeFloat m_flInaccuracyMove; // 0x0790
	CFiringModeFloat m_flRecoilAngle; // 0x0798
	CFiringModeFloat m_flRecoilAngleVariance; // 0x07A0
	CFiringModeFloat m_flRecoilMagnitude; // 0x07A8
	CFiringModeFloat m_flRecoilMagnitudeVariance; // 0x07B0
	CFiringModeInt m_nTracerFrequency; // 0x07B8
	float32 m_flInaccuracyJumpInitial; // 0x07C0
	float32 m_flInaccuracyJumpApex; // 0x07C4
	float32 m_flInaccuracyReload; // 0x07C8
	float32 m_flDeployDuration; // 0x07CC
	float32 m_flDisallowAttackAfterReloadStartDuration; // 0x07D0
	int32 m_nBurstShotCount; // 0x07D4
	bool m_bAllowBurstHolster; // 0x07D8
	int32 m_nRecoilSeed; // 0x07DC
	int32 m_nSpreadSeed; // 0x07E0
	float32 m_flAttackMovespeedFactor; // 0x07E4
	float32 m_flInaccuracyPitchShift; // 0x07E8
	float32 m_flInaccuracyAltSoundThreshold; // 0x07EC
	CUtlString m_szUseRadioSubtitle; // 0x07F0
	bool m_bUnzoomsAfterShot; // 0x07F8
	bool m_bHideViewModelWhenZoomed; // 0x07F9
	int32 m_nZoomLevels; // 0x07FC
	int32 m_nZoomFOV1; // 0x0800
	int32 m_nZoomFOV2; // 0x0804
	float32 m_flZoomTime0; // 0x0808
	float32 m_flZoomTime1; // 0x080C
	float32 m_flZoomTime2; // 0x0810
	float32 m_flIronSightPullUpSpeed; // 0x0814
	float32 m_flIronSightPutDownSpeed; // 0x0818
	float32 m_flIronSightFOV; // 0x081C
	float32 m_flIronSightPivotForward; // 0x0820
	float32 m_flIronSightLooseness; // 0x0824
	int32 m_nDamage; // 0x0828
	float32 m_flHeadshotMultiplier; // 0x082C
	float32 m_flArmorRatio; // 0x0830
	float32 m_flPenetration; // 0x0834
	float32 m_flRange; // 0x0838
	float32 m_flRangeModifier; // 0x083C
	float32 m_flFlinchVelocityModifierLarge; // 0x0840
	float32 m_flFlinchVelocityModifierSmall; // 0x0844
	float32 m_flRecoveryTimeCrouch; // 0x0848
	float32 m_flRecoveryTimeStand; // 0x084C
	float32 m_flRecoveryTimeCrouchFinal; // 0x0850
	float32 m_flRecoveryTimeStandFinal; // 0x0854
	int32 m_nRecoveryTransitionStartBullet; // 0x0858
	int32 m_nRecoveryTransitionEndBullet; // 0x085C
	float32 m_flThrowVelocity; // 0x0860
	Vector m_vSmokeColor; // 0x0864
	CGlobalSymbol m_szAnimClass; // 0x0870
};
class CAttributeManager // client
{
	CUtlVector< CHandle< C_BaseEntity > > m_Providers; // 0x0008
	int32 m_iReapplyProvisionParity; // 0x0020
	CHandle< C_BaseEntity > m_hOuter; // 0x0024
	bool m_bPreventLoopback; // 0x0028
	attributeprovidertypes_t m_ProviderType; // 0x002C
	CUtlVector< CAttributeManager::cached_attribute_float_t > m_CachedResults; // 0x0030
};
class SignatureOutflow_Continue : public CPulse_OutflowConnection // pulse_runtime_lib
{
};
class CInfoTarget : public C_PointEntity // client
{
};
class CPlayer_CameraServices : public CPlayerPawnComponent // client
{
	QAngle m_vecCsViewPunchAngle; // 0x0048
	GameTick_t m_nCsViewPunchAngleTick; // 0x0054
	float32 m_flCsViewPunchAngleTickRatio; // 0x0058
	C_fogplayerparams_t m_PlayerFog; // 0x0060
	CHandle< C_ColorCorrection > m_hColorCorrectionCtrl; // 0x00A0
	CHandle< C_BaseEntity > m_hViewEntity; // 0x00A4
	CHandle< C_TonemapController2 > m_hTonemapController; // 0x00A8
	audioparams_t m_audio; // 0x00B0
	C_NetworkUtlVectorBase< CHandle< C_PostProcessingVolume > > m_PostProcessingVolumes; // 0x0128
	float32 m_flOldPlayerZ; // 0x0140
	float32 m_flOldPlayerViewOffsetZ; // 0x0144
	fogparams_t m_CurrentFog; // 0x0148
	CHandle< C_FogController > m_hOldFogController; // 0x01B0
	bool[5] m_bOverrideFogColor; // 0x01B4
	Color[5] m_OverrideFogColor; // 0x01B9
	bool[5] m_bOverrideFogStartEnd; // 0x01CD
	float32[5] m_fOverrideFogStart; // 0x01D4
	float32[5] m_fOverrideFogEnd; // 0x01E8
	CHandle< C_PostProcessingVolume > m_hActivePostProcessingVolume; // 0x01FC
	QAngle m_angDemoViewAngles; // 0x0200
};
class CPulseCell_Timeline : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CUtlVector< CPulseCell_Timeline::TimelineEvent_t > m_TimelineEvents; // 0x00D8
	bool m_bWaitForChildOutflows; // 0x00F0
	CPulse_ResumePoint m_OnFinished; // 0x00F8
};
class CPulseCell_Inflow_EntOutputHandler : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_SourceEntity; // 0x0080
	PulseSymbol_t m_SourceOutput; // 0x0090
	CPulseValueFullType m_ExpectedParamType; // 0x00A0
};
class C_BaseCSGrenade : public C_CSWeaponBase // client
{
	bool m_bClientPredictDelete; // 0x1CE0
	bool m_bRedraw; // 0x1CE1
	bool m_bIsHeldByPlayer; // 0x1CE2
	bool m_bPinPulled; // 0x1CE3
	bool m_bJumpThrow; // 0x1CE4
	bool m_bThrowAnimating; // 0x1CE5
	GameTime_t m_fThrowTime; // 0x1CE8
	float32 m_flThrowStrength; // 0x1CF0
	GameTime_t m_fDropTime; // 0x1D68
	GameTime_t m_fPinPullTime; // 0x1D6C
	bool m_bJustPulledPin; // 0x1D70
	GameTick_t m_nNextHoldTick; // 0x1D74
	float32 m_flNextHoldFrac; // 0x1D78
	CHandle< C_CSWeaponBase > m_hSwitchToWeaponAfterThrow; // 0x1D7C
};
class CFilterAttributeInt : public CBaseFilter // client
{
	CUtlSymbolLarge m_sAttributeName; // 0x0638
};
class CPointTemplate : public CLogicalEntity // client
{
	CUtlSymbolLarge m_iszWorldName; // 0x0600
	CUtlSymbolLarge m_iszSource2EntityLumpName; // 0x0608
	CUtlSymbolLarge m_iszEntityFilterName; // 0x0610
	float32 m_flTimeoutInterval; // 0x0618
	bool m_bAsynchronouslySpawnEntities; // 0x061C
	PointTemplateClientOnlyEntityBehavior_t m_clientOnlyEntityBehavior; // 0x0620
	PointTemplateOwnerSpawnGroupType_t m_ownerSpawnGroupType; // 0x0624
	CUtlVector< uint32 > m_createdSpawnGroupHandles; // 0x0628
	CUtlVector< CEntityHandle > m_SpawnedEntityHandles; // 0x0640
	HSCRIPT m_ScriptSpawnCallback; // 0x0658
	HSCRIPT m_ScriptCallbackScope; // 0x0660
	CEntityOutputTemplate< CUtlVector< CEntityHandle > > m_OnEntitySpawned; // 0x0668
};
class CPlayer_FlashlightServices : public CPlayerPawnComponent // client
{
};
class CCSPlayerController : public CBasePlayerController // client
{
	CCSPlayerController_InGameMoneyServices* m_pInGameMoneyServices; // 0x0810
	CCSPlayerController_InventoryServices* m_pInventoryServices; // 0x0818
	CCSPlayerController_ActionTrackingServices* m_pActionTrackingServices; // 0x0820
	CCSPlayerController_DamageServices* m_pDamageServices; // 0x0828
	uint32 m_iPing; // 0x0830
	bool m_bHasCommunicationAbuseMute; // 0x0834
	uint32 m_uiCommunicationMuteFlags; // 0x0838
	CUtlSymbolLarge m_szCrosshairCodes; // 0x0840
	uint8 m_iPendingTeamNum; // 0x0848
	GameTime_t m_flForceTeamTime; // 0x084C
	int32 m_iCompTeammateColor; // 0x0850
	bool m_bEverPlayedOnTeam; // 0x0854
	GameTime_t m_flPreviousForceJoinTeamTime; // 0x0858
	CUtlSymbolLarge m_szClan; // 0x0860
	CUtlString m_sSanitizedPlayerName; // 0x0868
	int32 m_iCoachingTeam; // 0x0870
	uint64 m_nPlayerDominated; // 0x0878
	uint64 m_nPlayerDominatingMe; // 0x0880
	int32 m_iCompetitiveRanking; // 0x0888
	int32 m_iCompetitiveWins; // 0x088C
	int8 m_iCompetitiveRankType; // 0x0890
	int32 m_iCompetitiveRankingPredicted_Win; // 0x0894
	int32 m_iCompetitiveRankingPredicted_Loss; // 0x0898
	int32 m_iCompetitiveRankingPredicted_Tie; // 0x089C
	int32 m_nEndMatchNextMapVote; // 0x08A0
	uint16 m_unActiveQuestId; // 0x08A4
	uint32 m_rtActiveMissionPeriod; // 0x08A8
	QuestProgress::Reason m_nQuestProgressReason; // 0x08AC
	uint32 m_unPlayerTvControlFlags; // 0x08B0
	int32 m_iDraftIndex; // 0x08E0
	uint32 m_msQueuedModeDisconnectionTimestamp; // 0x08E4
	uint32 m_uiAbandonRecordedReason; // 0x08E8
	uint32 m_eNetworkDisconnectionReason; // 0x08EC
	bool m_bCannotBeKicked; // 0x08F0
	bool m_bEverFullyConnected; // 0x08F1
	bool m_bAbandonAllowsSurrender; // 0x08F2
	bool m_bAbandonOffersInstantSurrender; // 0x08F3
	bool m_bDisconnection1MinWarningPrinted; // 0x08F4
	bool m_bScoreReported; // 0x08F5
	int32 m_nDisconnectionTick; // 0x08F8
	bool m_bControllingBot; // 0x0908
	bool m_bHasControlledBotThisRound; // 0x0909
	bool m_bHasBeenControlledByPlayerThisRound; // 0x090A
	int32 m_nBotsControlledThisRound; // 0x090C
	bool m_bCanControlObservedBot; // 0x0910
	CHandle< C_CSPlayerPawn > m_hPlayerPawn; // 0x0914
	CHandle< C_CSObserverPawn > m_hObserverPawn; // 0x0918
	bool m_bPawnIsAlive; // 0x091C
	uint32 m_iPawnHealth; // 0x0920
	int32 m_iPawnArmor; // 0x0924
	bool m_bPawnHasDefuser; // 0x0928
	bool m_bPawnHasHelmet; // 0x0929
	uint16 m_nPawnCharacterDefIndex; // 0x092A
	int32 m_iPawnLifetimeStart; // 0x092C
	int32 m_iPawnLifetimeEnd; // 0x0930
	int32 m_iPawnBotDifficulty; // 0x0934
	CHandle< CCSPlayerController > m_hOriginalControllerOfCurrentPawn; // 0x0938
	int32 m_iScore; // 0x093C
	uint8[8] m_recentKillQueue; // 0x0940
	uint8 m_nFirstKill; // 0x0948
	uint8 m_nKillCount; // 0x0949
	bool m_bMvpNoMusic; // 0x094A
	int32 m_eMvpReason; // 0x094C
	int32 m_iMusicKitID; // 0x0950
	int32 m_iMusicKitMVPs; // 0x0954
	int32 m_iMVPs; // 0x0958
	bool m_bIsPlayerNameDirty; // 0x095C
	bool m_bFireBulletsSeedSynchronized; // 0x095D
};
class C_CSGO_TeamIntroCounterTerroristPosition : public C_CSGO_TeamIntroCharacterPosition // client
{
};
class C_CSGO_PreviewModel : public CBaseAnimGraph // client
{
	CUtlString m_defaultAnim; // 0x1180
	AnimLoopMode_t m_nDefaultAnimLoopMode; // 0x1188
	float32 m_flInitialModelScale; // 0x118C
	CUtlString m_sInitialWeaponState; // 0x1190
};
class C_CSGO_TeamSelectCharacterPosition : public C_CSGO_TeamPreviewCharacterPosition // client
{
};
class CPulseCell_Outflow_CycleOrdered::InstanceState_t // pulse_runtime_lib
{
	int32 m_nNextIndex; // 0x0000
};
class C_SoundEventAABBEntity : public C_SoundEventEntity // client
{
	Vector m_vMins; // 0x06C0
	Vector m_vMaxs; // 0x06CC
};
class CCSPlayer_MovementServices : public CPlayer_MovementServices_Humanoid // client
{
	CCSPlayerAnimationState m_AnimationState; // 0x0310
	bool m_bUsingGroundTopologyOffset; // 0x03F0
	float32 m_flUsingGroundTopologyOffsetTransitionSmoothing; // 0x03F4
	Vector m_vecLadderNormal; // 0x03F8
	int32 m_nLadderSurfacePropIndex; // 0x0404
	bool m_bDucked; // 0x0408
	float32 m_flDuckAmount; // 0x040C
	float32 m_flDuckSpeed; // 0x0410
	bool m_bDuckOverride; // 0x0414
	bool m_bDesiresDuck; // 0x0415
	bool m_bDucking; // 0x0416
	float32 m_flDuckRootOffset; // 0x0418
	float32 m_flDuckViewOffset; // 0x041C
	float32 m_flLastDuckTime; // 0x0420
	float32 m_flBombPlantViewOffset; // 0x0424
	Vector2D m_vecLastPositionAtFullCrouchSpeed; // 0x0430
	bool m_duckUntilOnGround; // 0x0438
	bool m_bHasWalkMovedSinceLastJump; // 0x0439
	bool m_bInStuckTest; // 0x043A
	int32 m_nTraceCount; // 0x0648
	int32 m_StuckLast; // 0x064C
	bool m_bSpeedCropped; // 0x0650
	int32 m_nOldWaterLevel; // 0x0654
	float32 m_flWaterEntryTime; // 0x0658
	Vector m_vecForward; // 0x065C
	Vector m_vecLeft; // 0x0668
	Vector m_vecUp; // 0x0674
	int32 m_nGameCodeHasMovedPlayerAfterCommand; // 0x0680
	GameTime_t m_fStashGrenadeParameterWhen; // 0x0684
	bool m_bUseFrictionStashedSpeed; // 0x0688
	float32 m_flUseFrictionStashedSpeedUntilFrac; // 0x068C
	float32 m_flFrictionStashedSpeed; // 0x0690
	float32 m_flStamina; // 0x0694
	float32 m_flHeightAtJumpStart; // 0x0698
	float32 m_flMaxJumpHeightThisJump; // 0x069C
	float32 m_flMaxJumpHeightLastJump; // 0x06A0
	float32 m_flStaminaAtJumpStart; // 0x06A4
	float32 m_flVelMulAtJumpStart; // 0x06A8
	float32 m_flAccumulatedJumpError; // 0x06AC
	CCSPlayerLegacyJump m_LegacyJump; // 0x06B0
	CCSPlayerModernJump m_ModernJump; // 0x06C8
	GameTick_t m_nLastJumpTick; // 0x0700
	float32 m_flLastJumpFrac; // 0x0704
	float32 m_flLastJumpVelocityZ; // 0x0708
	bool m_bJumpApexPending; // 0x070C
	float32 m_flTicksSinceLastSurfingDetected; // 0x0710
	bool m_bWasSurfing; // 0x0714
	Vector2D m_vecWalkWishVel; // 0x07A4
	bool m_bHasEverProcessedCommand; // 0x0FD0
};
class SellbackPurchaseEntry_t // client
{
	uint16 m_unDefIdx; // 0x0030
	int32 m_nCost; // 0x0034
	int32 m_nPrevArmor; // 0x0038
	bool m_bPrevHelmet; // 0x003C
	CEntityHandle m_hItem; // 0x0040
};
class C_TintController : public C_BaseEntity // client
{
};
class C_WeaponBaseItem : public C_CSWeaponBase // client
{
	bool m_bSequenceInProgress; // 0x1CE0
	bool m_bRedraw; // 0x1CE1
};
class CWaterSplasher : public C_BaseModelEntity // client
{
};
class C_FuncBrush : public C_BaseModelEntity // client
{
};
class PhysicsRagdollPose_t // client
{
	C_NetworkUtlVectorBase< CTransform > m_Transforms; // 0x0008
	CHandle< C_BaseEntity > m_hOwner; // 0x0020
	bool m_bSetFromDebugHistory; // 0x0024
};
class CPropDataComponent : public CEntityComponent // client
{
	float32 m_flDmgModBullet; // 0x0010
	float32 m_flDmgModClub; // 0x0014
	float32 m_flDmgModExplosive; // 0x0018
	float32 m_flDmgModFire; // 0x001C
	CUtlSymbolLarge m_iszPhysicsDamageTableName; // 0x0020
	CUtlSymbolLarge m_iszBasePropData; // 0x0028
	int32 m_nInteractions; // 0x0030
	bool m_bSpawnMotionDisabled; // 0x0034
	int32 m_nDisableTakePhysicsDamageSpawnFlag; // 0x0038
	int32 m_nMotionDisabledSpawnFlag; // 0x003C
};
class CPulseCell_LimitCount::InstanceState_t // pulse_runtime_lib
{
	int32 m_nCurrentCount; // 0x0000
};
class C_WeaponCZ75a : public C_CSWeaponBaseGun // client
{
	bool m_bMagazineRemoved; // 0x1D10
};
class CLightEntityAPI // client
{
};
class C_DynamicLight : public C_BaseModelEntity // client
{
	uint8 m_Flags; // 0x0FB0
	uint8 m_LightStyle; // 0x0FB1
	float32 m_Radius; // 0x0FB4
	int32 m_Exponent; // 0x0FB8
	float32 m_InnerAngle; // 0x0FBC
	float32 m_OuterAngle; // 0x0FC0
	float32 m_SpotRadius; // 0x0FC4
};
class CCS2PawnGraphController : public CCS2WeaponGraphController // client
{
	CAnimGraph2ParamOptionalRef< bool > m_bIsDefusing; // 0x02A0
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_moveType; // 0x02B8
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_moveDirectionID; // 0x02D0
	CAnimGraph2ParamOptionalRef< float32 > m_flMoveSpeedX; // 0x02E8
	CAnimGraph2ParamOptionalRef< float32 > m_flMoveSpeedY; // 0x0300
	CAnimGraph2ParamOptionalRef< float32 > m_flMoveSpeedHorizontal; // 0x0318
	CAnimGraph2ParamOptionalRef< float32 > m_flPreviousMoveSpeedHorizontal; // 0x0330
	CAnimGraph2ParamOptionalRef< float32 > m_flCrouchAmount; // 0x0348
	CAnimGraph2ParamOptionalRef< bool > m_bIsWalking; // 0x0360
	CAnimGraph2ParamOptionalRef< float32 > m_flWeaponDropAmount; // 0x0378
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_groundAction; // 0x0390
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_groundActionDirectionID; // 0x03A8
	CAnimGraph2ParamOptionalRef< float32 > m_flGroundTurnAngleOrVelocity; // 0x03C0
	CAnimGraph2ParamOptionalRef< float32 > m_flLadderCycle; // 0x03D8
	CAnimGraph2ParamOptionalRef< float32 > m_flLadderYaw; // 0x03F0
	CAnimGraph2ParamOptionalRef< float32 > m_flLadderYawBackwards; // 0x0408
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_airAction; // 0x0420
	CAnimGraph2ParamOptionalRef< float32 > m_flAirHeightAboveGround; // 0x0438
	CAnimGraph2ParamOptionalRef< CNmTarget > m_leftFootTarget; // 0x0450
	CAnimGraph2ParamOptionalRef< CNmTarget > m_rightFootTarget; // 0x0468
	CAnimGraph2ParamOptionalRef< float32 > m_flFlashedAmount; // 0x0480
	CAnimGraph2ParamOptionalRef< float32 > m_flAimPitchAngle; // 0x0498
	CAnimGraph2ParamOptionalRef< float32 > m_flAimYawAngle; // 0x04B0
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_flinchHead; // 0x04C8
	CAnimGraph2ParamOptionalRef< bool > m_flinchHeadRestart; // 0x04E0
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_flinchBody; // 0x04F8
	CAnimGraph2ParamOptionalRef< bool > m_flinchBodyRestart; // 0x0510
	CAnimGraph2ParamOptionalRef< bool > m_flinchIsOnFire; // 0x0528
};
class EngineCountdownTimer // client
{
	float32 m_duration; // 0x0008
	float32 m_timestamp; // 0x000C
	float32 m_timescale; // 0x0010
};
class CBaseModelEntityAPI // client
{
};
class C_SoundEventSphereEntity : public C_SoundEventEntity // client
{
	float32 m_flRadius; // 0x06C0
};
class CCSPlayerController_DamageServices : public CPlayerControllerComponent // client
{
	int32 m_nSendUpdate; // 0x0040
	C_UtlVectorEmbeddedNetworkVar< CDamageRecord > m_DamageList; // 0x0048
};
class C_CSGO_TeamPreviewModel : public C_CSGO_PreviewPlayer // client
{
};
class C_TonemapController2Alias_env_tonemap_controller2 : public C_TonemapController2 // client
{
};
class C_Inferno : public C_BaseModelEntity // client
{
	ParticleIndex_t m_nfxFireDamageEffect; // 0x0FF0
	CStrongHandle< InfoForResourceTypeIParticleSnapshot > m_hInfernoPointsSnapshot; // 0x0FF8
	CStrongHandle< InfoForResourceTypeIParticleSnapshot > m_hInfernoFillerPointsSnapshot; // 0x1000
	CStrongHandle< InfoForResourceTypeIParticleSnapshot > m_hInfernoOutlinePointsSnapshot; // 0x1008
	CStrongHandle< InfoForResourceTypeIParticleSnapshot > m_hInfernoClimbingOutlinePointsSnapshot; // 0x1010
	CStrongHandle< InfoForResourceTypeIParticleSnapshot > m_hInfernoDecalsSnapshot; // 0x1018
	VectorWS[64] m_firePositions; // 0x1020
	VectorWS[64] m_fireParentPositions; // 0x1320
	bool[64] m_bFireIsBurning; // 0x1620
	Vector[64] m_BurnNormal; // 0x1660
	int32 m_fireCount; // 0x1960
	int32 m_nInfernoType; // 0x1964
	float32 m_nFireLifetime; // 0x1968
	bool m_bInPostEffectTime; // 0x196C
	int32 m_lastFireCount; // 0x1970
	int32 m_nFireEffectTickBegin; // 0x1974
	int32 m_drawableCount; // 0x8580
	bool m_blosCheck; // 0x8584
	int32 m_nlosperiod; // 0x8588
	float32 m_maxFireHalfWidth; // 0x858C
	float32 m_maxFireHeight; // 0x8590
	VectorWS m_minBounds; // 0x8594
	VectorWS m_maxBounds; // 0x85A0
	float32 m_flLastGrassBurnThink; // 0x85AC
};
class CFilterLOS : public CBaseFilter // client
{
};
class CPointOrient : public C_BaseEntity // client
{
	CUtlSymbolLarge m_iszSpawnTargetName; // 0x0600
	CHandle< C_BaseEntity > m_hTarget; // 0x0608
	bool m_bActive; // 0x060C
	PointOrientGoalDirectionType_t m_nGoalDirection; // 0x0610
	PointOrientConstraint_t m_nConstraint; // 0x0614
	float32 m_flMaxTurnRate; // 0x0618
	GameTime_t m_flLastGameTime; // 0x061C
};
class C_GlobalLight : public C_BaseEntity // client
{
	uint16 m_WindClothForceHandle; // 0x0AC0
};
class C_EnvWindClientside : public C_BaseEntity // client
{
	C_EnvWindShared m_EnvWindShared; // 0x0600
};
class sky3dparams_t // client
{
	int16 scale; // 0x0008
	VectorWS origin; // 0x000C
	bool bClip3DSkyBoxNearToWorldFar; // 0x0018
	float32 flClip3DSkyBoxNearToWorldFarOffset; // 0x001C
	fogparams_t fog; // 0x0020
	WorldGroupId_t m_nWorldGroupID; // 0x0088
};
class C_FlashbangProjectile : public C_BaseCSGrenadeProjectile // client
{
};
class C_SoundEventConeEntity : public C_SoundEventEntity // client
{
	float32 m_flEmitterAngle; // 0x06C0
	float32 m_flSweetSpotAngle; // 0x06C4
	float32 m_flAttenMin; // 0x06C8
	float32 m_flAttenMax; // 0x06CC
	CUtlSymbolLarge m_iszParameterName; // 0x06D0
};
class CDestructiblePartsComponent // client
{
	CNetworkVarChainer __m_pChainEntity; // 0x0000
	CUtlVector< uint16 > m_vecDamageTakenByHitGroup; // 0x0048
	CHandle< C_BaseModelEntity > m_hOwner; // 0x0060
	CAnimGraphControllerPtr m_pAnimGraphDestructibleGraphController; // 0x0068
};
class C_WeaponP90 : public C_CSWeaponBaseGun // client
{
};
class C_EnvWind : public C_BaseEntity // client
{
	C_EnvWindShared m_EnvWindShared; // 0x0600
};
class C_CSGO_TerroristTeamIntroCamera : public C_CSGO_TeamPreviewCamera // client
{
};
class C_CSPlayerPawnBase_API // client
{
};
class CPulseCell_Step_DebugLog : public CPulseCell_BaseFlow // pulse_runtime_lib
{
};
class CCSPlayerController_ActionTrackingServices : public CPlayerControllerComponent // client
{
	C_UtlVectorEmbeddedNetworkVar< CSPerRoundStats_t > m_perRoundStats; // 0x0040
	CSMatchStats_t m_matchStats; // 0x00A8
	int32 m_iNumRoundKills; // 0x0128
	int32 m_iNumRoundKillsHeadshots; // 0x012C
	float32 m_flTotalRoundDamageDealt; // 0x0130
};
class CBodyComponentBaseAnimGraph : public CBodyComponentSkeletonInstance // client
{
	CBaseAnimGraphController m_animationController; // 0x0510
};
class C_CSGO_PreviewModelAlias_csgo_item_previewmodel : public C_CSGO_PreviewModel // client
{
};
class C_InfoInstructorHintHostageRescueZone : public C_PointEntity // client
{
};
class CPulseCell_BaseYieldingInflow : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CPulse_ResumePoint m_BaseFlow_OnAfterCancel; // 0x0048
	CPulse_ResumePoint m_BaseFlow_WhileActive; // 0x0090
};
class PulseNodeDynamicOutflows_t // pulse_runtime_lib
{
	CUtlVector< PulseNodeDynamicOutflows_t::DynamicOutflow_t > m_Outflows; // 0x0000
};
class C_TriggerBuoyancy : public C_BaseTrigger // client
{
	CBuoyancyHelper m_BuoyancyHelper; // 0x1098
	float32 m_flFluidDensity; // 0x11B0
};
class CPlayer_MovementServices_Humanoid : public CPlayer_MovementServices // client
{
	float32 m_flStepSoundTime; // 0x0258
	float32 m_flFallVelocity; // 0x025C
	Vector m_groundNormal; // 0x0260
	float32 m_flSurfaceFriction; // 0x026C
	CUtlStringToken m_surfaceProps; // 0x0270
	int32 m_nStepside; // 0x0280
};
class CPulseCell_IsRequirementValid::Criteria_t // pulse_runtime_lib
{
	bool m_bIsValid; // 0x0000
};
class C_WeaponTec9 : public C_CSWeaponBaseGun // client
{
};
class C_PhysPropClientside : public C_BreakableProp // client
{
	GameTime_t m_flTouchDelta; // 0x12F0
	GameTime_t m_fDeathTime; // 0x12F4
	VectorWS m_vecDamagePosition; // 0x12F8
	Vector m_vecDamageDirection; // 0x1304
	DamageTypes_t m_nDamageType; // 0x1310
};
class C_BaseDoor : public C_BaseToggle // client
{
	bool m_bIsUsable; // 0x0FB0
};
class CSMatchStats_t : public CSPerRoundStats_t // client
{
	int32 m_iEnemy5Ks; // 0x0068
	int32 m_iEnemy4Ks; // 0x006C
	int32 m_iEnemy3Ks; // 0x0070
	int32 m_iEnemyKnifeKills; // 0x0074
	int32 m_iEnemyTaserKills; // 0x0078
};
class EntityRenderAttribute_t // client
{
	CUtlStringToken m_ID; // 0x0030
	Vector4D m_Values; // 0x0034
};
class CPulseCell_Inflow_ObservableVariableListener : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseRuntimeBlackboardReferenceIndex_t m_nBlackboardReference; // 0x0080
	bool m_bSelfReference; // 0x0082
};
class CFilterMultipleAPI // client
{
};
class CHostageRescueZone : public CHostageRescueZoneShim // client
{
};
class CModelState // client
{
	CStrongHandle< InfoForResourceTypeCModel > m_hModel; // 0x00A0
	CUtlSymbolLarge m_ModelName; // 0x00A8
	IPhysAggregateInstance* m_pVPhysicsAggregate; // 0x00E0
	float32 m_flRootBoneOffset_x; // 0x00E8
	float32 m_flRootBoneOffset_y; // 0x00EC
	float32 m_flRootBoneOffset_z; // 0x00F0
	uint8 m_nRootBoneOffsetResetSerialNumber; // 0x00F4
	bool m_bClientClothCreationSuppressed; // 0x0110
	uint8 m_nAnimStateNoInterpSerialNumber; // 0x0200
	uint64 m_MeshGroupMask; // 0x0208
	C_NetworkUtlVectorBase< int32 > m_nBodyGroupChoices; // 0x0258
	int8 m_nIdealMotionType; // 0x02A2
	int8 m_nForceLOD; // 0x02A3
	int8 m_nClothUpdateFlags; // 0x02A4
};
class CPulseCell_LerpCameraSettings::CursorState_t : public CPulseCell_BaseLerp::CursorState_t // client
{
	CHandle< C_PointCamera > m_hCamera; // 0x0008
	PointCameraSettings_t m_OverlaidStart; // 0x000C
	PointCameraSettings_t m_OverlaidEnd; // 0x001C
};
class CPulseCell_Outflow_CycleOrdered : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outputs; // 0x0048
};
class C_CSWeaponBaseGun : public C_CSWeaponBase // client
{
	int32 m_zoomLevel; // 0x1CE0
	int32 m_iBurstShotsRemaining; // 0x1CE4
	int32 m_iSilencerBodygroup; // 0x1CE8
	int32 m_silencedModelIndex; // 0x1CF8
	bool m_inPrecache; // 0x1CFC
	bool m_bNeedsBoltAction; // 0x1CFD
	int32 m_nRevolverCylinderIdx; // 0x1D00
};
class C_CSGameRulesProxy : public C_GameRulesProxy // client
{
	C_CSGameRules* m_pGameRules; // 0x0600
};
class CCollisionProperty // client
{
	VPhysicsCollisionAttribute_t m_collisionAttribute; // 0x0010
	Vector m_vecMins; // 0x0040
	Vector m_vecMaxs; // 0x004C
	uint8 m_usSolidFlags; // 0x005A
	SolidType_t m_nSolidType; // 0x005B
	uint8 m_triggerBloat; // 0x005C
	SurroundingBoundsType_t m_nSurroundType; // 0x005D
	uint8 m_CollisionGroup; // 0x005E
	uint8 m_nEnablePhysics; // 0x005F
	float32 m_flBoundingRadius; // 0x0060
	Vector m_vecSpecifiedSurroundingMins; // 0x0064
	Vector m_vecSpecifiedSurroundingMaxs; // 0x0070
	Vector m_vecSurroundingMaxs; // 0x007C
	Vector m_vecSurroundingMins; // 0x0088
	Vector m_vCapsuleCenter1; // 0x0094
	Vector m_vCapsuleCenter2; // 0x00A0
	float32 m_flCapsuleRadius; // 0x00AC
};
class C_WeaponP250 : public C_CSWeaponBaseGun // client
{
};
class CFilterMassGreater : public CBaseFilter // client
{
	float32 m_fFilterMass; // 0x0638
};
class C_ShatterGlassShardPhysics : public C_BaseModelEntity // client
{
	shard_model_desc_t m_ShardDesc; // 0x0FB8
};
class C_EntityDissolve : public C_BaseModelEntity // client
{
	GameTime_t m_flStartTime; // 0x0FB8
	float32 m_flFadeInStart; // 0x0FBC
	float32 m_flFadeInLength; // 0x0FC0
	float32 m_flFadeOutModelStart; // 0x0FC4
	float32 m_flFadeOutModelLength; // 0x0FC8
	float32 m_flFadeOutStart; // 0x0FCC
	float32 m_flFadeOutLength; // 0x0FD0
	GameTime_t m_flNextSparkTime; // 0x0FD4
	EntityDissolveType_t m_nDissolveType; // 0x0FD8
	VectorWS m_vDissolverOrigin; // 0x0FDC
	uint32 m_nMagnitude; // 0x0FE8
	bool m_bCoreExplode; // 0x0FEC
	bool m_bLinkedToServerEnt; // 0x0FED
};
class C_SoundOpvarSetOBBEntity : public C_SoundOpvarSetAABBEntity // client
{
};
class CCSGameModeRules_ArmsRace : public CCSGameModeRules // client
{
	C_NetworkUtlVectorBase< CUtlString > m_WeaponSequence; // 0x0030
};
class C_FuncMonitor : public C_FuncBrush // client
{
	CUtlString m_targetCamera; // 0x0FB0
	int32 m_nResolutionEnum; // 0x0FB8
	bool m_bRenderShadows; // 0x0FBC
	bool m_bUseUniqueColorTarget; // 0x0FBD
	CUtlString m_brushModelName; // 0x0FC0
	CHandle< C_BaseEntity > m_hTargetCamera; // 0x0FC8
	bool m_bEnabled; // 0x0FCC
	bool m_bDraw3DSkybox; // 0x0FCD
};
class C_ClientRagdoll : public CBaseAnimGraph // client
{
	bool m_bFadeOut; // 0x1180
	bool m_bImportant; // 0x1181
	GameTime_t m_flEffectTime; // 0x1184
	GameTime_t m_gibDespawnTime; // 0x1188
	int32 m_iCurrentFriction; // 0x118C
	int32 m_iMinFriction; // 0x1190
	int32 m_iMaxFriction; // 0x1194
	int32 m_iFrictionAnimState; // 0x1198
	bool m_bReleaseRagdoll; // 0x119C
	AttachmentHandle_t m_iEyeAttachment; // 0x119D
	bool m_bFadingOut; // 0x119E
	float32[10] m_flScaleEnd; // 0x11A0
	GameTime_t[10] m_flScaleTimeStart; // 0x11C8
	GameTime_t[10] m_flScaleTimeEnd; // 0x11F0
};
class PulseSelectorOutflowList_t // pulse_runtime_lib
{
	CUtlVector< OutflowWithRequirements_t > m_Outflows; // 0x0000
};
class CPulseCell_PlaySequence::CursorState_t // client
{
	CHandle< CBaseAnimGraph > m_hTarget; // 0x0000
};
class CBodyComponentSkeletonInstance : public CBodyComponent // client
{
	CSkeletonInstance m_skeletonInstance; // 0x0080
};
class C_CS2WeaponModuleBase : public CBaseAnimGraph // client
{
};
class C_CSGO_TeamPreviewCharacterPosition : public C_BaseEntity // client
{
	int32 m_nVariant; // 0x0600
	int32 m_nRandom; // 0x0604
	int32 m_nOrdinal; // 0x0608
	CUtlString m_sWeaponName; // 0x0610
	uint64 m_xuid; // 0x0618
	C_EconItemView m_agentItem; // 0x0620
	C_EconItemView m_glovesItem; // 0x0A90
	C_EconItemView m_weaponItem; // 0x0F00
};
class C_SmokeGrenadeProjectile : public C_BaseCSGrenadeProjectile // client
{
	int32 m_nSmokeEffectTickBegin; // 0x1278
	bool m_bDidSmokeEffect; // 0x127C
	int32 m_nRandomSeed; // 0x1280
	Vector m_vSmokeColor; // 0x1284
	VectorWS m_vSmokeDetonationPos; // 0x1290
	C_NetworkUtlVectorBase< uint8 > m_VoxelFrameData; // 0x12A0
	int32 m_nVoxelFrameDataSize; // 0x12B8
	int32 m_nVoxelUpdate; // 0x12BC
	bool m_bSmokeVolumeDataReceived; // 0x12C0
	bool m_bSmokeEffectSpawned; // 0x12C1
};
class CScriptComponent : public CEntityComponent // entity2
{
	CUtlSymbolLarge m_scriptClassName; // 0x0030
};
class CCSPlayer_BuyServices : public CPlayerPawnComponent // client
{
	C_UtlVectorEmbeddedNetworkVar< SellbackPurchaseEntry_t > m_vecSellbackPurchaseEntries; // 0x0048
};
class C_PortraitWorldCallbackHandler : public C_BaseEntity // client
{
};
class C_DynamicProp : public C_BreakableProp // client
{
	bool m_bUseHitboxesForRenderBox; // 0x12F0
	bool m_bUseAnimGraph; // 0x12F1
	CEntityIOOutput m_pOutputAnimBegun; // 0x12F8
	CEntityIOOutput m_pOutputAnimOver; // 0x1310
	CEntityIOOutput m_pOutputAnimLoopCycleOver; // 0x1328
	CEntityIOOutput m_OnAnimReachedStart; // 0x1340
	CEntityIOOutput m_OnAnimReachedEnd; // 0x1358
	CUtlSymbolLarge m_iszIdleAnim; // 0x1370
	AnimLoopMode_t m_nIdleAnimLoopMode; // 0x1378
	bool m_bRandomizeCycle; // 0x137C
	bool m_bStartDisabled; // 0x137D
	bool m_bFiredStartEndOutput; // 0x137E
	bool m_bForceNpcExclude; // 0x137F
	bool m_bCreateMovableSurfaceGraph; // 0x1380
	bool m_bCreateNonSolid; // 0x1381
	bool m_bIsOverrideProp; // 0x1382
	int32 m_iInitialGlowState; // 0x1384
	int32 m_nGlowRange; // 0x1388
	int32 m_nGlowRangeMin; // 0x138C
	Color m_glowColor; // 0x1390
	int32 m_nGlowTeam; // 0x1394
	int32 m_iCachedFrameCount; // 0x1398
	Vector m_vecCachedRenderMins; // 0x139C
	Vector m_vecCachedRenderMaxs; // 0x13A8
};
class C_CSTeam : public C_Team // client
{
	char[512] m_szTeamMatchStat; // 0x06B8
	int32 m_numMapVictories; // 0x08B8
	bool m_bSurrendered; // 0x08BC
	int32 m_scoreFirstHalf; // 0x08C0
	int32 m_scoreSecondHalf; // 0x08C4
	int32 m_scoreOvertime; // 0x08C8
	char[129] m_szClanTeamname; // 0x08CC
	uint32 m_iClanID; // 0x0950
	char[8] m_szTeamFlagImage; // 0x0954
	char[8] m_szTeamLogoImage; // 0x095C
};
class C_CS2HudModelWeapon : public C_CS2HudModelBase // client
{
};
class C_TextureBasedAnimatable : public C_BaseModelEntity // client
{
	bool m_bLoop; // 0x0FB0
	float32 m_flFPS; // 0x0FB4
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hPositionKeys; // 0x0FB8
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hRotationKeys; // 0x0FC0
	Vector m_vAnimationBoundsMin; // 0x0FC8
	Vector m_vAnimationBoundsMax; // 0x0FD4
	float32 m_flStartTime; // 0x0FE0
	float32 m_flStartFrame; // 0x0FE4
};
class C_LightEnvironmentEntity : public C_LightDirectionalEntity // client
{
};
class DestructiblePartDamageRequestAPI // client
{
};
class CLogicRelayAPI // client
{
};
class C_TriggerPhysics : public C_BaseTrigger // client
{
	float32 m_gravityScale; // 0x1098
	float32 m_linearLimit; // 0x109C
	float32 m_linearDamping; // 0x10A0
	float32 m_angularLimit; // 0x10A4
	float32 m_angularDamping; // 0x10A8
	float32 m_linearForce; // 0x10AC
	float32 m_flFrequency; // 0x10B0
	float32 m_flDampingRatio; // 0x10B4
	Vector m_vecLinearForcePointAt; // 0x10B8
	bool m_bCollapseToForcePoint; // 0x10C4
	VectorWS m_vecLinearForcePointAtWorld; // 0x10C8
	Vector m_vecLinearForceDirection; // 0x10D4
	bool m_bConvertToDebrisWhenPossible; // 0x10E0
};
class C_PropDoorRotating : public C_BasePropDoor // client
{
};
class C_HandleTest : public C_BaseEntity // client
{
	CHandle< C_BaseEntity > m_Handle; // 0x0600
	bool m_bSendHandle; // 0x0604
};
class CInfoWorldLayer : public C_BaseEntity // client
{
	CEntityIOOutput m_pOutputOnEntitiesSpawned; // 0x0600
	CUtlSymbolLarge m_worldName; // 0x0618
	CUtlSymbolLarge m_layerName; // 0x0620
	bool m_bWorldLayerVisible; // 0x0628
	bool m_bEntitiesSpawned; // 0x0629
	bool m_bCreateAsChildSpawnGroup; // 0x062A
	uint32 m_hLayerSpawnGroup; // 0x062C
	bool m_bWorldLayerActuallyVisible; // 0x0630
};
class CBodyComponentBaseModelEntity : public CBodyComponentSkeletonInstance // client
{
};
class C_Multimeter : public CBaseAnimGraph // client
{
	CHandle< C_PlantedC4 > m_hTargetC4; // 0x1180
};
class C_BaseTrigger : public C_BaseToggle // client
{
	CEntityIOOutput m_OnStartTouch; // 0x0FB0
	CEntityIOOutput m_OnStartTouchAll; // 0x0FC8
	CEntityIOOutput m_OnEndTouch; // 0x0FE0
	CEntityIOOutput m_OnEndTouchAll; // 0x0FF8
	CEntityIOOutput m_OnTouching; // 0x1010
	CEntityIOOutput m_OnTouchingEachEntity; // 0x1028
	CEntityIOOutput m_OnNotTouching; // 0x1040
	CEntityIOOutput m_OnTouchingChanged; // 0x1058
	CUtlVector< CHandle< C_BaseEntity > > m_hTouchingEntities; // 0x1070
	CUtlSymbolLarge m_iFilterName; // 0x1088
	CHandle< CBaseFilter > m_hFilter; // 0x1090
	bool m_bDisabled; // 0x1094
};
class FilterDamageType : public CBaseFilter // client
{
	int32 m_iDamageType; // 0x0638
};
class CAttributeList // client
{
	C_UtlVectorEmbeddedNetworkVar< CEconItemAttribute > m_Attributes; // 0x0008
	CAttributeManager* m_pManager; // 0x0070
};
class CPulseCell_Inflow_Wait : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_WakeResume; // 0x00D8
};
class CFilterProximity : public CBaseFilter // client
{
	float32 m_flRadius; // 0x0638
};
class CCS2WeaponGraphController : public CAnimGraphControllerBase // client
{
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_action; // 0x0088
	CAnimGraph2ParamOptionalRef< bool > m_bActionReset; // 0x00A0
	CAnimGraph2ParamOptionalRef< float32 > m_flWeaponActionSpeedScale; // 0x00B8
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_weaponCategory; // 0x00D0
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_weaponType; // 0x00E8
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_weaponExtraInfo; // 0x0100
	CAnimGraph2ParamOptionalRef< float32 > m_flWeaponAmmo; // 0x0118
	CAnimGraph2ParamOptionalRef< float32 > m_flWeaponAmmoMax; // 0x0130
	CAnimGraph2ParamOptionalRef< float32 > m_flWeaponAmmoReserve; // 0x0148
	CAnimGraph2ParamOptionalRef< bool > m_bWeaponIsSilenced; // 0x0160
	CAnimGraph2ParamOptionalRef< float32 > m_flWeaponIronsightAmount; // 0x0178
	CAnimGraph2ParamOptionalRef< bool > m_bIsUsingLegacyModel; // 0x0190
	CAnimGraph2ParamOptionalRef< float32 > m_idleVariation; // 0x01A8
	CAnimGraph2ParamOptionalRef< float32 > m_deployVariation; // 0x01C0
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_attackType; // 0x01D8
	CAnimGraph2ParamOptionalRef< float32 > m_attackThrowStrength; // 0x01F0
	CAnimGraph2ParamOptionalRef< float32 > m_flAttackVariation; // 0x0208
	CAnimGraph2ParamOptionalRef< float32 > m_inspectVariation; // 0x0220
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_inspectExtraInfo; // 0x0238
	CAnimGraph2ParamOptionalRef< CGlobalSymbol > m_reloadStage; // 0x0250
};
class CEffectData // client
{
	VectorWS m_vOrigin; // 0x0008
	VectorWS m_vStart; // 0x0014
	Vector m_vNormal; // 0x0020
	QAngle m_vAngles; // 0x002C
	CEntityHandle m_hEntity; // 0x0038
	CEntityHandle m_hOtherEntity; // 0x003C
	float32 m_flScale; // 0x0040
	float32 m_flMagnitude; // 0x0044
	float32 m_flRadius; // 0x0048
	CUtlStringToken m_nSurfaceProp; // 0x004C
	CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > m_nEffectIndex; // 0x0050
	uint32 m_nDamageType; // 0x0058
	uint8 m_nPenetrate; // 0x005C
	uint16 m_nMaterial; // 0x005E
	int16 m_nHitBox; // 0x0060
	uint8 m_nColor; // 0x0062
	uint8 m_fFlags; // 0x0063
	AttachmentHandle_t m_nAttachmentIndex; // 0x0064
	CUtlStringToken m_nAttachmentName; // 0x0068
	uint16 m_iEffectName; // 0x006C
};
class C_ParticleSystem : public C_BaseModelEntity // client
{
	char[512] m_szSnapshotFileName; // 0x0FB0
	bool m_bActive; // 0x11B0
	bool m_bFrozen; // 0x11B1
	float32 m_flFreezeTransitionDuration; // 0x11B4
	int32 m_nStopType; // 0x11B8
	bool m_bAnimateDuringGameplayPause; // 0x11BC
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_iEffectIndex; // 0x11C0
	GameTime_t m_flStartTime; // 0x11C8
	float32 m_flPreSimTime; // 0x11CC
	Vector[4] m_vServerControlPoints; // 0x11D0
	uint8[4] m_iServerControlPointAssignments; // 0x1200
	CHandle< C_BaseEntity >[64] m_hControlPointEnts; // 0x1204
	bool m_bDataStringLocalized; // 0x1304
	CUtlString m_strDataString; // 0x1308
	bool m_bNoSave; // 0x1310
	bool m_bNoFreeze; // 0x1311
	bool m_bNoRamp; // 0x1312
	bool m_bStartActive; // 0x1313
	CUtlSymbolLarge m_iszEffectName; // 0x1318
	CUtlSymbolLarge[64] m_iszControlPointNames; // 0x1320
	int32 m_nDataCP; // 0x1520
	Vector m_vecDataCPValue; // 0x1524
	int32 m_nTintCP; // 0x1530
	Color m_clrTint; // 0x1534
	bool m_bOldActive; // 0x1558
	bool m_bOldFrozen; // 0x1559
};
class CEnvSkyAPI // client
{
};
class CPulseCell_Outflow_CycleShuffled : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outputs; // 0x0048
};
class C_WeaponSCAR20 : public C_CSWeaponBaseGun // client
{
};
class C_FuncMover : public C_BaseToggle // client
{
};
class CCSPlayerController_InventoryServices::NetworkedLoadoutSlot_t // client
{
	C_EconItemView* pItem; // 0x0000
	uint16 team; // 0x0008
	uint16 slot; // 0x000A
};
class CLightComponent : public CEntityComponent // client
{
	CNetworkVarChainer __m_pChainEntity; // 0x0038
	Color m_Color; // 0x0075
	Color m_SecondaryColor; // 0x0079
	float32 m_flBrightness; // 0x0080
	float32 m_flBrightnessScale; // 0x0084
	float32 m_flBrightnessMult; // 0x0088
	float32 m_flRange; // 0x008C
	float32 m_flFalloff; // 0x0090
	float32 m_flAttenuation0; // 0x0094
	float32 m_flAttenuation1; // 0x0098
	float32 m_flAttenuation2; // 0x009C
	float32 m_flTheta; // 0x00A0
	float32 m_flPhi; // 0x00A4
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hLightCookie; // 0x00A8
	int32 m_nCascades; // 0x00B0
	int32 m_nCastShadows; // 0x00B4
	int32 m_nShadowWidth; // 0x00B8
	int32 m_nShadowHeight; // 0x00BC
	bool m_bRenderDiffuse; // 0x00C0
	int32 m_nRenderSpecular; // 0x00C4
	bool m_bRenderTransmissive; // 0x00C8
	float32 m_flOrthoLightWidth; // 0x00CC
	float32 m_flOrthoLightHeight; // 0x00D0
	int32 m_nStyle; // 0x00D4
	CUtlString m_Pattern; // 0x00D8
	int32 m_nCascadeRenderStaticObjects; // 0x00E0
	float32 m_flShadowCascadeCrossFade; // 0x00E4
	float32 m_flShadowCascadeDistanceFade; // 0x00E8
	float32 m_flShadowCascadeDistance0; // 0x00EC
	float32 m_flShadowCascadeDistance1; // 0x00F0
	float32 m_flShadowCascadeDistance2; // 0x00F4
	float32 m_flShadowCascadeDistance3; // 0x00F8
	int32 m_nShadowCascadeResolution0; // 0x00FC
	int32 m_nShadowCascadeResolution1; // 0x0100
	int32 m_nShadowCascadeResolution2; // 0x0104
	int32 m_nShadowCascadeResolution3; // 0x0108
	bool m_bUsesBakedShadowing; // 0x010C
	int32 m_nShadowPriority; // 0x0110
	int32 m_nBakedShadowIndex; // 0x0114
	int32 m_nLightPathUniqueId; // 0x0118
	int32 m_nLightMapUniqueId; // 0x011C
	bool m_bRenderToCubemaps; // 0x0120
	bool m_bAllowSSTGeneration; // 0x0121
	int32 m_nDirectLight; // 0x0124
	int32 m_nBounceLight; // 0x0128
	float32 m_flBounceScale; // 0x012C
	float32 m_flFadeMinDist; // 0x0130
	float32 m_flFadeMaxDist; // 0x0134
	float32 m_flShadowFadeMinDist; // 0x0138
	float32 m_flShadowFadeMaxDist; // 0x013C
	bool m_bEnabled; // 0x0140
	bool m_bFlicker; // 0x0141
	bool m_bPrecomputedFieldsValid; // 0x0142
	Vector m_vPrecomputedBoundsMins; // 0x0144
	Vector m_vPrecomputedBoundsMaxs; // 0x0150
	Vector m_vPrecomputedOBBOrigin; // 0x015C
	QAngle m_vPrecomputedOBBAngles; // 0x0168
	Vector m_vPrecomputedOBBExtent; // 0x0174
	float32 m_flPrecomputedMaxRange; // 0x0180
	int32 m_nFogLightingMode; // 0x0184
	float32 m_flFogContributionStength; // 0x0188
	float32 m_flNearClipPlane; // 0x018C
	Color m_SkyColor; // 0x0190
	float32 m_flSkyIntensity; // 0x0194
	Color m_SkyAmbientBounce; // 0x0198
	bool m_bUseSecondaryColor; // 0x019C
	bool m_bMixedShadows; // 0x019D
	GameTime_t m_flLightStyleStartTime; // 0x01A0
	float32 m_flCapsuleLength; // 0x01A4
	float32 m_flMinRoughness; // 0x01A8
};
class C_DecoyGrenade : public C_BaseCSGrenade // client
{
};
class C_WaterBullet : public CBaseAnimGraph // client
{
};
class CCSPlayer_ActionTrackingServices : public CPlayerPawnComponent // client
{
	CHandle< C_BasePlayerWeapon > m_hLastWeaponBeforeC4AutoSwitch; // 0x0048
	bool m_bIsRescuing; // 0x004C
	WeaponPurchaseTracker_t m_weaponPurchasesThisMatch; // 0x0050
	WeaponPurchaseTracker_t m_weaponPurchasesThisRound; // 0x00C0
};
class C_EnvCubemap : public C_BaseEntity // client
{
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hCubemapTexture; // 0x0680
	bool m_Entity_bCustomCubemapTexture; // 0x0688
	float32 m_Entity_flInfluenceRadius; // 0x068C
	Vector m_Entity_vBoxProjectMins; // 0x0690
	Vector m_Entity_vBoxProjectMaxs; // 0x069C
	bool m_Entity_bMoveable; // 0x06A8
	int32 m_Entity_nHandshake; // 0x06AC
	int32 m_Entity_nEnvCubeMapArrayIndex; // 0x06B0
	int32 m_Entity_nPriority; // 0x06B4
	float32 m_Entity_flEdgeFadeDist; // 0x06B8
	Vector m_Entity_vEdgeFadeDists; // 0x06BC
	float32 m_Entity_flDiffuseScale; // 0x06C8
	bool m_Entity_bStartDisabled; // 0x06CC
	bool m_Entity_bDefaultEnvMap; // 0x06CD
	bool m_Entity_bDefaultSpecEnvMap; // 0x06CE
	bool m_Entity_bIndoorCubeMap; // 0x06CF
	bool m_Entity_bCopyDiffuseFromDefaultCubemap; // 0x06D0
	bool m_Entity_bEnabled; // 0x06E0
};
class CCSObserver_MovementServices : public CPlayer_MovementServices // client
{
};
class CBodyComponent : public CEntityComponent // client
{
	CGameSceneNode* m_pSceneNode; // 0x0008
	CNetworkVarChainer __m_pChainEntity; // 0x0048
};
class CPulseCell_Inflow_Method : public CPulseCell_Inflow_BaseEntrypoint // pulse_runtime_lib
{
	PulseSymbol_t m_MethodName; // 0x0080
	CUtlString m_Description; // 0x0090
	bool m_bIsPublic; // 0x0098
	CPulseValueFullType m_ReturnType; // 0x00A0
	CUtlLeanVector< CPulseRuntimeMethodArg > m_Args; // 0x00B8
};
class C_BaseCombatCharacter : public CBaseAnimGraph // client
{
	C_NetworkUtlVectorBase< CHandle< C_EconWearable > > m_hMyWearables; // 0x1180
	AttachmentHandle_t m_leftFootAttachment; // 0x1198
	AttachmentHandle_t m_rightFootAttachment; // 0x1199
	C_BaseCombatCharacter::WaterWakeMode_t m_nWaterWakeMode; // 0x119C
	float32 m_flWaterWorldZ; // 0x11A0
	float32 m_flWaterNextTraceTime; // 0x11A4
};
class CGlowProperty // client
{
	Vector m_fGlowColor; // 0x0008
	int32 m_iGlowType; // 0x0030
	int32 m_iGlowTeam; // 0x0034
	int32 m_nGlowRange; // 0x0038
	int32 m_nGlowRangeMin; // 0x003C
	Color m_glowColorOverride; // 0x0040
	bool m_bFlashing; // 0x0044
	float32 m_flGlowTime; // 0x0048
	float32 m_flGlowStartTime; // 0x004C
	bool m_bEligibleForScreenHighlight; // 0x0050
	bool m_bGlowing; // 0x0051
};
class C_PointClientUIDialog : public C_BaseClientUIEntity // client
{
	CHandle< C_BaseEntity > m_hActivator; // 0x0FE0
	bool m_bStartEnabled; // 0x0FE4
};
class CPulseCell_BaseValue : public CPulseCell_Base // pulse_runtime_lib
{
};
class C_WeaponHKP2000 : public C_CSWeaponBaseGun // client
{
};
class C_FootstepControl : public C_BaseTrigger // client
{
	CUtlSymbolLarge m_source; // 0x1098
	CUtlSymbolLarge m_destination; // 0x10A0
};
class CCitadelSoundOpvarSetOBB : public C_BaseEntity // client
{
	CUtlSymbolLarge m_iszStackName; // 0x0618
	CUtlSymbolLarge m_iszOperatorName; // 0x0620
	CUtlSymbolLarge m_iszOpvarName; // 0x0628
	Vector m_vDistanceInnerMins; // 0x0630
	Vector m_vDistanceInnerMaxs; // 0x063C
	Vector m_vDistanceOuterMins; // 0x0648
	Vector m_vDistanceOuterMaxs; // 0x0654
	int32 m_nAABBDirection; // 0x0660
};
class C_CSGO_EndOfMatchLineupStart : public C_CSGO_EndOfMatchLineupEndpoint // client
{
};
class CPlayer_WaterServices : public CPlayerPawnComponent // client
{
};
class CPulseCell_BooleanSwitchState : public CPulseCell_BaseState // pulse_runtime_lib
{
	CPulseObservableExpression< bool > m_Condition; // 0x00D8
	CPulse_OutflowConnection m_WhenTrue; // 0x0150
	CPulse_OutflowConnection m_WhenFalse; // 0x0198
};
class CDamageRecord // client
{
	CHandle< C_CSPlayerPawn > m_PlayerDamager; // 0x0030
	CHandle< C_CSPlayerPawn > m_PlayerRecipient; // 0x0034
	CHandle< CCSPlayerController > m_hPlayerControllerDamager; // 0x0038
	CHandle< CCSPlayerController > m_hPlayerControllerRecipient; // 0x003C
	CUtlString m_szPlayerDamagerName; // 0x0040
	CUtlString m_szPlayerRecipientName; // 0x0048
	uint64 m_DamagerXuid; // 0x0050
	uint64 m_RecipientXuid; // 0x0058
	float32 m_flBulletsDamage; // 0x0060
	float32 m_flDamage; // 0x0064
	float32 m_flActualHealthRemoved; // 0x0068
	int32 m_iNumHits; // 0x006C
	int32 m_iLastBulletUpdate; // 0x0070
	bool m_bIsOtherEnemy; // 0x0074
	EKillTypes_t m_killType; // 0x0075
};
class VPhysicsCollisionAttribute_t // client
{
	uint64 m_nInteractsAs; // 0x0008
	uint64 m_nInteractsWith; // 0x0010
	uint64 m_nInteractsExclude; // 0x0018
	uint32 m_nEntityId; // 0x0020
	uint32 m_nOwnerId; // 0x0024
	uint16 m_nHierarchyId; // 0x0028
	uint16 m_nDetailLayerMask; // 0x002A
	uint8 m_nDetailLayerMaskType; // 0x002C
	uint8 m_nTargetDetailLayer; // 0x002D
	uint8 m_nCollisionGroup; // 0x002E
	uint8 m_nCollisionFunctionMask; // 0x002F
};
class C_DynamicPropAlias_dynamic_prop : public C_DynamicProp // client
{
};
class CEnvSoundscapeProxyAlias_snd_soundscape_proxy : public CEnvSoundscapeProxy // client
{
};
class C_OmniLight : public C_BarnLight // client
{
	float32 m_flInnerAngle; // 0x12C0
	float32 m_flOuterAngle; // 0x12C4
	bool m_bShowLight; // 0x12C8
};
class C_SceneEntity : public C_PointEntity // client
{
	bool m_bIsPlayingBack; // 0x0608
	bool m_bPaused; // 0x0609
	bool m_bMultiplayer; // 0x060A
	bool m_bAutogenerated; // 0x060B
	bool m_bAllRequirementsComplete; // 0x060C
	float32 m_flForceClientTime; // 0x0610
	uint16 m_nSceneStringIndex; // 0x0614
	bool m_bClientOnly; // 0x0616
	CHandle< C_BaseModelEntity > m_hOwner; // 0x0618
	C_NetworkUtlVectorBase< CHandle< C_BaseModelEntity > > m_hActorList; // 0x0620
	bool m_bWasPlaying; // 0x0638
	CUtlVector< C_SceneEntity::QueuedEvents_t > m_QueuedEvents; // 0x0648
	float32 m_flCurrentTime; // 0x0660
};
class CFootstepControl_API // client
{
};
class CPulseCell_Inflow_Yield : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	CPulse_ResumePoint m_UnyieldResume; // 0x00D8
};
class CPulseMathlib // pulse_runtime_lib
{
};
class C_NametagModule : public C_CS2WeaponModuleBase // client
{
	CUtlString m_strNametagString; // 0x1188
};
class C_CSGO_TeamPreviewCamera_API // client
{
};
class C_EconEntity : public CBaseAnimGraph // client
{
	float32 m_flFlexDelayTime; // 0x1190
	float32* m_flFlexDelayedWeight; // 0x1198
	bool m_bAttributesInitialized; // 0x11A0
	C_AttributeContainer m_AttributeManager; // 0x11A8
	uint32 m_OriginalOwnerXuidLow; // 0x1678
	uint32 m_OriginalOwnerXuidHigh; // 0x167C
	int32 m_nFallbackPaintKit; // 0x1680
	int32 m_nFallbackSeed; // 0x1684
	float32 m_flFallbackWear; // 0x1688
	int32 m_nFallbackStatTrak; // 0x168C
	bool m_bClientside; // 0x1690
	bool m_bParticleSystemsCreated; // 0x1691
	CUtlVector< int32 > m_vecAttachedParticles; // 0x1698
	CHandle< CBaseAnimGraph > m_hViewmodelAttachment; // 0x16B0
	int32 m_iOldTeam; // 0x16B4
	bool m_bAttachmentDirty; // 0x16B8
	int32 m_nUnloadedModelIndex; // 0x16BC
	int32 m_iNumOwnerValidationRetries; // 0x16C0
	CHandle< C_BaseEntity > m_hOldProvidee; // 0x16D0
	CUtlVector< C_EconEntity::AttachedModelData_t > m_vecAttachedModels; // 0x16D8
};
class CPlayer_UseServices : public CPlayerPawnComponent // client
{
};
class C_PointValueRemapper : public C_BaseEntity // client
{
	bool m_bDisabled; // 0x0600
	bool m_bDisabledOld; // 0x0601
	bool m_bUpdateOnClient; // 0x0602
	ValueRemapperInputType_t m_nInputType; // 0x0604
	CHandle< C_BaseEntity > m_hRemapLineStart; // 0x0608
	CHandle< C_BaseEntity > m_hRemapLineEnd; // 0x060C
	float32 m_flMaximumChangePerSecond; // 0x0610
	float32 m_flDisengageDistance; // 0x0614
	float32 m_flEngageDistance; // 0x0618
	bool m_bRequiresUseKey; // 0x061C
	ValueRemapperOutputType_t m_nOutputType; // 0x0620
	C_NetworkUtlVectorBase< CHandle< C_BaseEntity > > m_hOutputEntities; // 0x0628
	ValueRemapperHapticsType_t m_nHapticsType; // 0x0640
	ValueRemapperMomentumType_t m_nMomentumType; // 0x0644
	float32 m_flMomentumModifier; // 0x0648
	float32 m_flSnapValue; // 0x064C
	float32 m_flCurrentMomentum; // 0x0650
	ValueRemapperRatchetType_t m_nRatchetType; // 0x0654
	float32 m_flRatchetOffset; // 0x0658
	float32 m_flInputOffset; // 0x065C
	bool m_bEngaged; // 0x0660
	bool m_bFirstUpdate; // 0x0661
	float32 m_flPreviousValue; // 0x0664
	GameTime_t m_flPreviousUpdateTickTime; // 0x0668
	VectorWS m_vecPreviousTestPoint; // 0x066C
};
class CGameSceneNodeHandle // client
{
	CEntityHandle m_hOwner; // 0x0008
	CUtlStringToken m_name; // 0x000C
};
class CPulseCell_Unknown : public CPulseCell_Base // pulse_runtime_lib
{
	KeyValues3 m_UnknownKeys; // 0x0048
};
class C_WeaponMP7 : public C_CSWeaponBaseGun // client
{
};
class CPulseStringlib // pulse_runtime_lib
{
};
class CSPerRoundStats_t // client
{
	int32 m_iKills; // 0x0030
	int32 m_iDeaths; // 0x0034
	int32 m_iAssists; // 0x0038
	int32 m_iDamage; // 0x003C
	int32 m_iEquipmentValue; // 0x0040
	int32 m_iMoneySaved; // 0x0044
	int32 m_iKillReward; // 0x0048
	int32 m_iLiveTime; // 0x004C
	int32 m_iHeadShotKills; // 0x0050
	int32 m_iObjective; // 0x0054
	int32 m_iCashEarned; // 0x0058
	int32 m_iUtilityDamage; // 0x005C
	int32 m_iEnemiesFlashed; // 0x0060
};
class CPulseCell_Outflow_CycleRandom : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	CUtlVector< CPulse_OutflowConnection > m_Outputs; // 0x0048
};
class CPulseCell_Step_PublicOutput : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseRuntimeOutputIndex_t m_OutputIndex; // 0x0048
};
class C_CS2HudModelBase : public C_LateUpdatedAnimating // client
{
};
class C_CSGameRules : public C_TeamplayRules // client
{
	bool m_bFreezePeriod; // 0x0040
	bool m_bWarmupPeriod; // 0x0041
	GameTime_t m_fWarmupPeriodEnd; // 0x0044
	GameTime_t m_fWarmupPeriodStart; // 0x0048
	bool m_bTerroristTimeOutActive; // 0x004C
	bool m_bCTTimeOutActive; // 0x004D
	float32 m_flTerroristTimeOutRemaining; // 0x0050
	float32 m_flCTTimeOutRemaining; // 0x0054
	int32 m_nTerroristTimeOuts; // 0x0058
	int32 m_nCTTimeOuts; // 0x005C
	bool m_bTechnicalTimeOut; // 0x0060
	bool m_bMatchWaitingForResume; // 0x0061
	int32 m_iFreezeTime; // 0x0064
	int32 m_iRoundTime; // 0x0068
	float32 m_fMatchStartTime; // 0x006C
	GameTime_t m_fRoundStartTime; // 0x0070
	GameTime_t m_flRestartRoundTime; // 0x0074
	bool m_bGameRestart; // 0x0078
	float32 m_flGameStartTime; // 0x007C
	float32 m_timeUntilNextPhaseStarts; // 0x0080
	int32 m_gamePhase; // 0x0084
	int32 m_totalRoundsPlayed; // 0x0088
	int32 m_nRoundsPlayedThisPhase; // 0x008C
	int32 m_nOvertimePlaying; // 0x0090
	int32 m_iHostagesRemaining; // 0x0094
	bool m_bAnyHostageReached; // 0x0098
	bool m_bMapHasBombTarget; // 0x0099
	bool m_bMapHasRescueZone; // 0x009A
	bool m_bMapHasBuyZone; // 0x009B
	bool m_bIsQueuedMatchmaking; // 0x009C
	int32 m_nQueuedMatchmakingMode; // 0x00A0
	bool m_bIsValveDS; // 0x00A4
	bool m_bLogoMap; // 0x00A5
	bool m_bPlayAllStepSoundsOnServer; // 0x00A6
	int32 m_iSpectatorSlotCount; // 0x00A8
	int32 m_MatchDevice; // 0x00AC
	bool m_bHasMatchStarted; // 0x00B0
	int32 m_nNextMapInMapgroup; // 0x00B4
	char[512] m_szTournamentEventName; // 0x00B8
	char[512] m_szTournamentEventStage; // 0x02B8
	char[512] m_szMatchStatTxt; // 0x04B8
	char[512] m_szTournamentPredictionsTxt; // 0x06B8
	int32 m_nTournamentPredictionsPct; // 0x08B8
	GameTime_t m_flCMMItemDropRevealStartTime; // 0x08BC
	GameTime_t m_flCMMItemDropRevealEndTime; // 0x08C0
	bool m_bIsDroppingItems; // 0x08C4
	bool m_bIsQuestEligible; // 0x08C5
	bool m_bIsHltvActive; // 0x08C6
	bool m_bBombPlanted; // 0x08C7
	uint16[100] m_arrProhibitedItemIndices; // 0x08C8
	uint32[4] m_arrTournamentActiveCasterAccounts; // 0x0990
	int32 m_numBestOfMaps; // 0x09A0
	int32 m_nHalloweenMaskListSeed; // 0x09A4
	bool m_bBombDropped; // 0x09A8
	int32 m_iRoundWinStatus; // 0x09AC
	int32 m_eRoundWinReason; // 0x09B0
	bool m_bTCantBuy; // 0x09B4
	bool m_bCTCantBuy; // 0x09B5
	int32[30] m_iMatchStats_RoundResults; // 0x09B8
	int32[30] m_iMatchStats_PlayersAlive_CT; // 0x0A30
	int32[30] m_iMatchStats_PlayersAlive_T; // 0x0AA8
	float32[32] m_TeamRespawnWaveTimes; // 0x0B20
	GameTime_t[32] m_flNextRespawnWave; // 0x0BA0
	VectorWS m_vMinimapMins; // 0x0C20
	VectorWS m_vMinimapMaxs; // 0x0C2C
	float32[8] m_MinimapVerticalSectionHeights; // 0x0C38
	uint64 m_ullLocalMatchID; // 0x0C58
	int32[10] m_nEndMatchMapGroupVoteTypes; // 0x0C60
	int32[10] m_nEndMatchMapGroupVoteOptions; // 0x0C88
	int32 m_nEndMatchMapVoteWinner; // 0x0CB0
	int32 m_iNumConsecutiveCTLoses; // 0x0CB4
	int32 m_iNumConsecutiveTerroristLoses; // 0x0CB8
	int32 m_nMatchAbortedEarlyReason; // 0x0D78
	bool m_bHasTriggeredRoundStartMusic; // 0x0D7C
	bool m_bSwitchingTeamsAtRoundReset; // 0x0D7D
	CCSGameModeRules* m_pGameModeRules; // 0x0D98
	C_RetakeGameRules m_RetakeRules; // 0x0DA0
	uint8 m_nMatchEndCount; // 0x0EF8
	int32 m_nTTeamIntroVariant; // 0x0EFC
	int32 m_nCTTeamIntroVariant; // 0x0F00
	bool m_bTeamIntroPeriod; // 0x0F04
	int32 m_iRoundEndWinnerTeam; // 0x0F08
	int32 m_eRoundEndReason; // 0x0F0C
	bool m_bRoundEndShowTimerDefend; // 0x0F10
	int32 m_iRoundEndTimerTime; // 0x0F14
	CUtlString m_sRoundEndFunFactToken; // 0x0F18
	CPlayerSlot m_iRoundEndFunFactPlayerSlot; // 0x0F20
	int32 m_iRoundEndFunFactData1; // 0x0F24
	int32 m_iRoundEndFunFactData2; // 0x0F28
	int32 m_iRoundEndFunFactData3; // 0x0F2C
	CUtlString m_sRoundEndMessage; // 0x0F30
	int32 m_iRoundEndPlayerCount; // 0x0F38
	bool m_bRoundEndNoMusic; // 0x0F3C
	int32 m_iRoundEndLegacy; // 0x0F40
	uint8 m_nRoundEndCount; // 0x0F44
	int32 m_iRoundStartRoundNumber; // 0x0F48
	uint8 m_nRoundStartCount; // 0x0F4C
	float64 m_flLastPerfSampleTime; // 0x4F58
};
class CBaseAnimGraphAPI // client
{
};
class CGrenadeTracer : public C_BaseModelEntity // client
{
	float32 m_flTracerDuration; // 0x0FC8
	GrenadeType_t m_nType; // 0x0FCC
};
class CCSGameModeRules_Noop : public CCSGameModeRules // client
{
};
class CPulse_BlackboardReference // pulse_runtime_lib
{
	CStrongHandle< InfoForResourceTypeIPulseGraphDef > m_hBlackboardResource; // 0x0000
	PulseSymbol_t m_BlackboardResource; // 0x0008
	PulseDocNodeID_t m_nNodeID; // 0x0018
	CGlobalSymbol m_NodeName; // 0x0020
};
class C_BaseCSGrenadeProjectile : public C_BaseGrenade // client
{
	VectorWS m_vInitialPosition; // 0x11C8
	Vector m_vInitialVelocity; // 0x11D4
	int32 m_nBounces; // 0x11E0
	CStrongHandle< InfoForResourceTypeIParticleSystemDefinition > m_nExplodeEffectIndex; // 0x11E8
	int32 m_nExplodeEffectTickBegin; // 0x11F0
	VectorWS m_vecExplodeEffectOrigin; // 0x11F4
	GameTime_t m_flSpawnTime; // 0x1200
	Vector vecLastTrailLinePos; // 0x1204
	GameTime_t flNextTrailLineTime; // 0x1210
	bool m_bExplodeEffectBegan; // 0x1214
	bool m_bCanCreateGrenadeTrail; // 0x1215
	ParticleIndex_t m_nSnapshotTrajectoryEffectIndex; // 0x1218
	CStrongHandle< InfoForResourceTypeIParticleSnapshot > m_hSnapshotTrajectoryParticleSnapshot; // 0x1220
	CUtlVector< Vector > m_arrTrajectoryTrailPoints; // 0x1228
	CUtlVector< float32 > m_arrTrajectoryTrailPointCreationTimes; // 0x1240
	float32 m_flTrajectoryTrailEffectCreationTime; // 0x1258
};
class C_GradientFog : public C_BaseEntity // client
{
	CStrongHandle< InfoForResourceTypeCTextureBase > m_hGradientFogTexture; // 0x0600
	float32 m_flFogStartDistance; // 0x0608
	float32 m_flFogEndDistance; // 0x060C
	bool m_bHeightFogEnabled; // 0x0610
	float32 m_flFogStartHeight; // 0x0614
	float32 m_flFogEndHeight; // 0x0618
	float32 m_flFarZ; // 0x061C
	float32 m_flFogMaxOpacity; // 0x0620
	float32 m_flFogFalloffExponent; // 0x0624
	float32 m_flFogVerticalExponent; // 0x0628
	Color m_fogColor; // 0x062C
	float32 m_flFogStrength; // 0x0630
	float32 m_flFadeTime; // 0x0634
	bool m_bStartDisabled; // 0x0638
	bool m_bIsEnabled; // 0x0639
	bool m_bGradientFogNeedsTextures; // 0x063A
};
class CCSPlayerController_InGameMoneyServices : public CPlayerControllerComponent // client
{
	int32 m_iAccount; // 0x0040
	int32 m_iStartAccount; // 0x0044
	int32 m_iTotalCashSpent; // 0x0048
	int32 m_iCashSpentThisRound; // 0x004C
};
class CCSPlayer_AimPunchServices : public CPlayerPawnComponent // client
{
	GameTick_t m_predictableBaseTick; // 0x0048
	float32 m_predictableBaseTickInterpAmount; // 0x004C
	QAngle m_predictableBaseAngle; // 0x0050
	QAngle m_predictableBaseAngleVel; // 0x005C
	GameTick_t m_unpredictableBaseTick; // 0x00A0
	QAngle m_unpredictableBaseAngle; // 0x00A4
};
class C_HEGrenadeProjectile : public C_BaseCSGrenadeProjectile // client
{
};
class CFilterModel : public CBaseFilter // client
{
	CUtlSymbolLarge m_iFilterModel; // 0x0638
};
class C_SoundAreaEntityOrientedBox : public C_SoundAreaEntityBase // client
{
	Vector m_vMin; // 0x0628
	Vector m_vMax; // 0x0634
};
class C_SoundOpvarSetPointEntity : public C_SoundOpvarSetPointBase // client
{
};
class CPulseGameBlackboard : public C_BaseEntity // client
{
	CUtlString m_strGraphName; // 0x0608
	CUtlString m_strStateBlob; // 0x0610
};
class CChoreoComponent // client
{
	CNetworkVarChainer __m_pChainEntity; // 0x0008
	CHandle< C_BaseModelEntity > m_hOwner; // 0x0030
	int32 m_nExernalChoreoGraphCount; // 0x0034
	CGlobalSymbol m_sActiveExternalChoreoGraphSlotID; // 0x0038
	SceneEventId_t m_nNextSceneEventId; // 0x0070
	GameTime_t m_flAllowResponsesEndTime; // 0x0074
};
class CPulseCell_Value_RandomInt : public CPulseCell_BaseValue // pulse_runtime_lib
{
};
class C_CSWeaponBaseShotgun : public C_CSWeaponBase // client
{
};
class C_RagdollPropAttached : public C_RagdollProp // client
{
	uint32 m_boneIndexAttached; // 0x1208
	uint32 m_ragdollAttachedObjectIndex; // 0x120C
	Vector m_attachmentPointBoneSpace; // 0x1210
	Vector m_attachmentPointRagdollSpace; // 0x121C
	Vector m_vecOffset; // 0x1228
	float32 m_parentTime; // 0x1234
	bool m_bHasParent; // 0x1238
};
class C_ModelPointEntity : public C_BaseModelEntity // client
{
};
class C_CSGO_PreviewPlayer : public C_CSPlayerPawn // client
{
	CGlobalSymbol m_animgraphCharacterModeString; // 0x3460
	float32 m_flInitialModelScale; // 0x3468
};
class C_RectLight : public C_BarnLight // client
{
	bool m_bShowLight; // 0x12C0
};
class C_CSPlayerPawn_API // client
{
};
class CPathSimple : public C_BaseEntity // client
{
	CPathQueryComponent m_CPathQueryComponent; // 0x0610
	CUtlString m_pathString; // 0x0700
	bool m_bClosedLoop; // 0x0708
};
class C_FuncTrackTrain : public C_BaseModelEntity // client
{
	int32 m_nLongAxis; // 0x0FB0
	float32 m_flRadius; // 0x0FB4
	float32 m_flLineLength; // 0x0FB8
};
class C_EconWearable : public C_EconEntity // client
{
	int32 m_nForceSkin; // 0x16F0
	bool m_bAlwaysAllow; // 0x16F4
};
class C_EnvDecal : public C_BaseModelEntity // client
{
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hDecalMaterial; // 0x0FB0
	float32 m_flWidth; // 0x0FB8
	float32 m_flHeight; // 0x0FBC
	float32 m_flDepth; // 0x0FC0
	uint32 m_nRenderOrder; // 0x0FC4
	bool m_bProjectOnWorld; // 0x0FC8
	bool m_bProjectOnCharacters; // 0x0FC9
	bool m_bProjectOnWater; // 0x0FCA
	float32 m_flDepthSortBias; // 0x0FCC
};
class EntitySpottedState_t // client
{
	bool m_bSpotted; // 0x0008
	uint32[2] m_bSpottedByMask; // 0x000C
};
class fogparams_t // client
{
	Vector dirPrimary; // 0x0008
	Color colorPrimary; // 0x0014
	Color colorSecondary; // 0x0018
	Color colorPrimaryLerpTo; // 0x001C
	Color colorSecondaryLerpTo; // 0x0020
	float32 start; // 0x0024
	float32 end; // 0x0028
	float32 farz; // 0x002C
	float32 maxdensity; // 0x0030
	float32 exponent; // 0x0034
	float32 HDRColorScale; // 0x0038
	float32 skyboxFogFactor; // 0x003C
	float32 skyboxFogFactorLerpTo; // 0x0040
	float32 startLerpTo; // 0x0044
	float32 endLerpTo; // 0x0048
	float32 maxdensityLerpTo; // 0x004C
	GameTime_t lerptime; // 0x0050
	float32 duration; // 0x0054
	float32 blendtobackground; // 0x0058
	float32 scattering; // 0x005C
	float32 locallightscale; // 0x0060
	bool enable; // 0x0064
	bool blend; // 0x0065
	bool m_bPadding2; // 0x0066
	bool m_bPadding; // 0x0067
};
class C_WeaponM4A1 : public C_CSWeaponBaseGun // client
{
};
class C_Item : public C_EconEntity // client
{
	char[256] m_pReticleHintTextName; // 0x16F0
};
class C_CSPetPlacement : public C_BaseEntity // client
{
};
class CBaseEntity_SharedAPI // client
{
};
class C_Beam : public C_BaseModelEntity // client
{
	float32 m_flFrameRate; // 0x0FB0
	float32 m_flHDRColorScale; // 0x0FB4
	GameTime_t m_flFireTime; // 0x0FB8
	float32 m_flDamage; // 0x0FBC
	uint8 m_nNumBeamEnts; // 0x0FC0
	int32 m_queryHandleHalo; // 0x0FC4
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hBaseMaterial; // 0x0FE8
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_nHaloIndex; // 0x0FF0
	BeamType_t m_nBeamType; // 0x0FF8
	uint32 m_nBeamFlags; // 0x0FFC
	CHandle< C_BaseEntity >[10] m_hAttachEntity; // 0x1000
	AttachmentHandle_t[10] m_nAttachIndex; // 0x1028
	float32 m_fWidth; // 0x1034
	float32 m_fEndWidth; // 0x1038
	float32 m_fFadeLength; // 0x103C
	float32 m_fHaloScale; // 0x1040
	float32 m_fAmplitude; // 0x1044
	float32 m_fStartFrame; // 0x1048
	float32 m_fSpeed; // 0x104C
	float32 m_flFrame; // 0x1050
	bool m_bTurnedOff; // 0x1054
	VectorWS m_vecEndPos; // 0x1058
	CHandle< C_BaseEntity > m_hEndEntity; // 0x1064
};
class C_EnvLightProbeVolume : public C_BaseEntity // client
{
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_AmbientCube; // 0x15F8
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SDF; // 0x1600
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_DC; // 0x1608
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_R; // 0x1610
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_G; // 0x1618
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeTexture_SH2_B; // 0x1620
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeDirectLightIndicesTexture; // 0x1628
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeDirectLightScalarsTexture; // 0x1630
	CStrongHandle< InfoForResourceTypeCTextureBase > m_Entity_hLightProbeDirectLightShadowsTexture; // 0x1638
	Vector m_Entity_vBoxMins; // 0x1640
	Vector m_Entity_vBoxMaxs; // 0x164C
	bool m_Entity_bMoveable; // 0x1658
	int32 m_Entity_nHandshake; // 0x165C
	int32 m_Entity_nPriority; // 0x1660
	bool m_Entity_bStartDisabled; // 0x1664
	int32 m_Entity_nLightProbeSizeX; // 0x1668
	int32 m_Entity_nLightProbeSizeY; // 0x166C
	int32 m_Entity_nLightProbeSizeZ; // 0x1670
	int32 m_Entity_nLightProbeAtlasX; // 0x1674
	int32 m_Entity_nLightProbeAtlasY; // 0x1678
	int32 m_Entity_nLightProbeAtlasZ; // 0x167C
	bool m_Entity_bEnabled; // 0x1689
};
class CExplosionTypeData // client
{
	CSoundEventName m_SoundName; // 0x0000
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > > m_ParticleEffect; // 0x0010
	bool m_bIsIncindiary; // 0x00F0
	bool m_bHasForces; // 0x00F1
	CGlobalSymbol m_DecalType; // 0x00F8
};
class CCSPlayerController_API // client
{
};
class C_FuncConveyor : public C_BaseModelEntity // client
{
	Vector m_vecMoveDirEntitySpace; // 0x0FB8
	float32 m_flTargetSpeed; // 0x0FC4
	GameTick_t m_nTransitionStartTick; // 0x0FC8
	int32 m_nTransitionDurationTicks; // 0x0FCC
	float32 m_flTransitionStartSpeed; // 0x0FD0
	C_NetworkUtlVectorBase< CHandle< C_BaseEntity > > m_hConveyorModels; // 0x0FD8
	float32 m_flCurrentConveyorOffset; // 0x0FF0
	float32 m_flCurrentConveyorSpeed; // 0x0FF4
};
class CPulseEnumlib // pulse_runtime_lib
{
};
class CCSPlayer_WeaponServices : public CPlayer_WeaponServices // client
{
	GameTime_t m_flNextAttack; // 0x00D0
	uint32 m_nOldTotalShootPositionHistoryCount; // 0x00D4
	uint32 m_nOldTotalInputHistoryCount; // 0x0370
	C_NetworkUtlVectorBase< uint8 > m_networkAnimTiming; // 0x1588
	bool m_bBlockInspectUntilNextGraphUpdate; // 0x15A0
};
class C_PhysMagnet : public CBaseAnimGraph // client
{
	CUtlVector< int32 > m_aAttachedObjectsFromServer; // 0x1180
	CUtlVector< CHandle< C_BaseEntity > > m_aAttachedObjects; // 0x1198
};
class CEnvSoundscapeTriggerableAlias_snd_soundscape_triggerable : public CEnvSoundscapeTriggerable // client
{
};
class C_Breakable : public C_BaseModelEntity // client
{
};
class C_PlantedC4 : public CBaseAnimGraph // client
{
	bool m_bBombTicking; // 0x11A0
	int32 m_nBombSite; // 0x11A4
	int32 m_nSourceSoundscapeHash; // 0x11A8
	EntitySpottedState_t m_entitySpottedState; // 0x11B0
	GameTime_t m_flNextGlow; // 0x11C8
	GameTime_t m_flNextBeep; // 0x11CC
	GameTime_t m_flC4Blow; // 0x11D0
	bool m_bCannotBeDefused; // 0x11D4
	bool m_bHasExploded; // 0x11D5
	float32 m_flTimerLength; // 0x11D8
	bool m_bBeingDefused; // 0x11DC
	float32 m_bTriggerWarning; // 0x11E0
	float32 m_bExplodeWarning; // 0x11E4
	bool m_bC4Activated; // 0x11E8
	bool m_bTenSecWarning; // 0x11E9
	float32 m_flDefuseLength; // 0x11EC
	GameTime_t m_flDefuseCountDown; // 0x11F0
	bool m_bBombDefused; // 0x11F4
	CHandle< C_CSPlayerPawn > m_hBombDefuser; // 0x11F8
	C_AttributeContainer m_AttributeManager; // 0x1200
	CHandle< C_Multimeter > m_hDefuserMultimeter; // 0x16D0
	GameTime_t m_flNextRadarFlashTime; // 0x16D4
	bool m_bRadarFlash; // 0x16D8
	CHandle< C_CSPlayerPawn > m_pBombDefuser; // 0x16DC
	GameTime_t m_fLastDefuseTime; // 0x16E0
	CBasePlayerController* m_pPredictionOwner; // 0x16E8
	VectorWS m_vecC4ExplodeSpectatePos; // 0x16F0
	QAngle m_vecC4ExplodeSpectateAng; // 0x16FC
	float32 m_flC4ExplodeSpectateDuration; // 0x1708
};
class C_CSGO_MapPreviewCameraPath_API // client
{
};
class CCSGO_WingmanIntroCharacterPosition : public C_CSGO_TeamIntroCharacterPosition // client
{
};
class CFilterName : public CBaseFilter // client
{
	CUtlSymbolLarge m_iFilterName; // 0x0638
};
class C_RagdollProp : public CBaseAnimGraph // client
{
	C_NetworkUtlVectorBase< bool > m_ragEnabled; // 0x1180
	C_NetworkUtlVectorBase< Vector > m_ragPos; // 0x1198
	C_NetworkUtlVectorBase< QAngle > m_ragAngles; // 0x11B0
	float32 m_flBlendWeight; // 0x11C8
	CHandle< C_BaseEntity > m_hRagdollSource; // 0x11CC
	AttachmentHandle_t m_iEyeAttachment; // 0x11D0
	float32 m_flBlendWeightCurrent; // 0x11D4
	CUtlVector< int32 > m_parentPhysicsBoneIndices; // 0x11D8
	CUtlVector< int32 > m_worldSpaceBoneComputationOrder; // 0x11F0
};
class CPulse_CallInfo // pulse_runtime_lib
{
	PulseSymbol_t m_PortName; // 0x0000
	PulseDocNodeID_t m_nEditorNodeID; // 0x0010
	PulseRegisterMap_t m_RegisterMap; // 0x0018
	PulseDocNodeID_t m_CallMethodID; // 0x0048
	PulseRuntimeChunkIndex_t m_nSrcChunk; // 0x004C
	int32 m_nSrcInstruction; // 0x0050
};
class C_MapPreviewParticleSystem : public C_ParticleSystem // client
{
};
class CBaseAnimGraph : public C_BaseModelEntity // client
{
	CAnimGraphControllerManager m_graphControllerManager; // 0x0FB0
	CAnimGraphControllerPtr m_pMainGraphController; // 0x1048
	bool m_bInitiallyPopulateInterpHistory; // 0x1050
	bool m_bSuppressAnimEventSounds; // 0x1052
	CEntityOutputTemplate< float32 > m_OnLayerCycleUpdated; // 0x1058
	CEntityIOOutput m_OnExternalChoreoGraphChanged; // 0x1078
	bool m_bAnimGraphUpdateEnabled; // 0x1098
	bool m_bAnimationUpdateScheduled; // 0x1099
	Vector m_vecForce; // 0x109C
	int32 m_nForceBone; // 0x10A8
	CBaseAnimGraph* m_pClientsideRagdoll; // 0x10B0
	bool m_bBuiltRagdoll; // 0x10B8
	IPhysicsRagdollControl* m_pRagdollControl; // 0x10C8
	PhysicsRagdollPose_t m_RagdollPose; // 0x10D0
	bool m_bRagdollEnabled; // 0x1118
	bool m_bRagdollClientSide; // 0x1119
	bool m_bHasAnimatedMaterialAttributes; // 0x1128
};
class CPulseCell_InlineNodeSkipSelector : public CPulseCell_BaseFlow // pulse_runtime_lib
{
	PulseDocNodeID_t m_nFlowNodeID; // 0x0048
	bool m_bAnd; // 0x004C
	PulseSelectorOutflowList_t m_PassOutflow; // 0x0050
	CPulse_OutflowConnection m_FailOutflow; // 0x0068
};
class C_LightEntity : public C_BaseModelEntity // client
{
	CLightComponent* m_CLightComponent; // 0x0FB0
};
class CBarnLightAPI // client
{
};
class C_WeaponM249 : public C_CSWeaponBaseGun // client
{
};
class C_LocalTempEntity : public CBaseAnimGraph // client
{
	int32 flags; // 0x1180
	GameTime_t die; // 0x1184
	float32 m_flFrameMax; // 0x1188
	float32 x; // 0x118C
	float32 y; // 0x1190
	float32 fadeSpeed; // 0x1194
	float32 bounceFactor; // 0x1198
	int32 hitSound; // 0x119C
	int32 priority; // 0x11A0
	Vector tentOffset; // 0x11A4
	QAngle m_vecTempEntAngVelocity; // 0x11B0
	int32 tempent_renderamt; // 0x11BC
	Vector m_vecNormal; // 0x11C0
	float32 m_flSpriteScale; // 0x11CC
	int32 m_nFlickerFrame; // 0x11D0
	float32 m_flFrameRate; // 0x11D4
	float32 m_flFrame; // 0x11D8
	char* m_pszImpactEffect; // 0x11E0
	char* m_pszParticleEffect; // 0x11E8
	bool m_bParticleCollision; // 0x11F0
	int32 m_iLastCollisionFrame; // 0x11F4
	VectorWS m_vLastCollisionOrigin; // 0x11F8
	Vector m_vecTempEntVelocity; // 0x1204
	VectorWS m_vecPrevAbsOrigin; // 0x1210
	Vector m_vecTempEntAcceleration; // 0x121C
};
class CFlashbangProjectile_API // client
{
};
class C_WeaponTaser : public C_CSWeaponBaseGun // client
{
	GameTime_t m_fFireTime; // 0x1D10
	int32 m_nLastAttackTick; // 0x1D14
};
class C_PointEntity : public C_BaseEntity // client
{
};
class C_SingleplayRules : public C_GameRules // client
{
};
class CLogicalEntity : public C_BaseEntity // client
{
};
class C_PrecipitationBlocker : public C_BaseModelEntity // client
{
};
class C_CSGO_CounterTerroristTeamIntroCamera : public C_CSGO_TeamPreviewCamera // client
{
};
class C_SoundOpvarSetPathCornerEntity : public C_SoundOpvarSetPointEntity // client
{
};
class CPlayer_WeaponServices : public CPlayerPawnComponent // client
{
	C_NetworkUtlVectorBase< CHandle< C_BasePlayerWeapon > > m_hMyWeapons; // 0x0048
	CHandle< C_BasePlayerWeapon > m_hActiveWeapon; // 0x0060
	CHandle< C_BasePlayerWeapon > m_hLastWeapon; // 0x0064
	uint16[32] m_iAmmo; // 0x0068
};
class C_WeaponNegev : public C_CSWeaponBaseGun // client
{
};
class C_WeaponFiveSeven : public C_CSWeaponBaseGun // client
{
};
class C_WeaponSawedoff : public C_CSWeaponBaseShotgun // client
{
};
class C_TriggerVolume : public C_BaseModelEntity // client
{
};
class CPulseCell_LimitCount : public CPulseCell_BaseRequirement // pulse_runtime_lib
{
	int32 m_nLimitCount; // 0x0048
};
class CPulseCell_Step_CallExternalMethod : public CPulseCell_BaseYieldingInflow // pulse_runtime_lib
{
	PulseSymbol_t m_MethodName; // 0x00D8
	PulseRuntimeBlackboardReferenceIndex_t m_nBlackboardIndex; // 0x00E8
	CUtlLeanVector< CPulseRuntimeMethodArg > m_ExpectedArgs; // 0x00F0
	PulseMethodCallMode_t m_nAsyncCallMode; // 0x0100
	CPulse_ResumePoint m_OnFinished; // 0x0108
};
class C_WeaponMP9 : public C_CSWeaponBaseGun // client
{
};
class C_DynamicPropAlias_prop_dynamic_override : public C_DynamicProp // client
{
};
class CEnvSoundscapeTriggerable : public CEnvSoundscape // client
{
};
class C_PlayerPing : public C_BaseEntity // client
{
	CHandle< C_CSPlayerPawn > m_hPlayer; // 0x0630
	CHandle< C_BaseEntity > m_hPingedEntity; // 0x0634
	int32 m_iType; // 0x0638
	bool m_bUrgent; // 0x063C
	char[18] m_szPlaceName; // 0x063D
};
class C_AK47 : public C_CSWeaponBaseGun // client
{
};
class C_CSGO_MapPreviewCameraPathNode : public C_BaseEntity // client
{
	CUtlSymbolLarge m_szParentPathUniqueID; // 0x0600
	int32 m_nPathIndex; // 0x0608
	Vector m_vInTangentLocal; // 0x060C
	Vector m_vOutTangentLocal; // 0x0618
	float32 m_flFOV; // 0x0624
	float32 m_flCameraSpeed; // 0x0628
	float32 m_flEaseIn; // 0x062C
	float32 m_flEaseOut; // 0x0630
	Vector m_vInTangentWorld; // 0x0634
	Vector m_vOutTangentWorld; // 0x0640
};
class C_CSPlayerResource : public C_BaseEntity // client
{
	bool[12] m_bHostageAlive; // 0x0600
	bool[12] m_isHostageFollowingSomeone; // 0x060C
	CEntityIndex[12] m_iHostageEntityIDs; // 0x0618
	VectorWS m_bombsiteCenterA; // 0x0648
	VectorWS m_bombsiteCenterB; // 0x0654
	int32[4] m_hostageRescueX; // 0x0660
	int32[4] m_hostageRescueY; // 0x0670
	int32[4] m_hostageRescueZ; // 0x0680
	bool m_bEndMatchNextMapAllVoted; // 0x0690
	bool m_foundGoalPositions; // 0x0691
};
class CSkyboxReference : public C_BaseEntity // client
{
	WorldGroupId_t m_worldGroupId; // 0x0600
	CHandle< C_SkyCamera > m_hSkyCamera; // 0x0604
};
class C_IncendiaryGrenade : public C_MolotovGrenade // client
{
};
class CFilterClass : public CBaseFilter // client
{
	CUtlSymbolLarge m_iFilterClass; // 0x0638
};
class C_PointCameraVFOV : public C_PointCamera // client
{
	float32 m_flVerticalFOV; // 0x0660
};
class C_PointCamera : public C_BaseEntity // client
{
	float32 m_FOV; // 0x0600
	float32 m_Resolution; // 0x0604
	bool m_bFogEnable; // 0x0608
	Color m_FogColor; // 0x0609
	float32 m_flFogStart; // 0x0610
	float32 m_flFogEnd; // 0x0614
	float32 m_flFogMaxDensity; // 0x0618
	bool m_bActive; // 0x061C
	bool m_bUseScreenAspectRatio; // 0x061D
	float32 m_flAspectRatio; // 0x0620
	bool m_bNoSky; // 0x0624
	float32 m_fBrightness; // 0x0628
	float32 m_flZFar; // 0x062C
	float32 m_flZNear; // 0x0630
	bool m_bCanHLTVUse; // 0x0634
	bool m_bAlignWithParent; // 0x0635
	bool m_bDofEnabled; // 0x0636
	float32 m_flDofNearBlurry; // 0x0638
	float32 m_flDofNearCrisp; // 0x063C
	float32 m_flDofFarCrisp; // 0x0640
	float32 m_flDofFarBlurry; // 0x0644
	float32 m_flDofTiltToGround; // 0x0648
	float32 m_TargetFOV; // 0x064C
	float32 m_DegreesPerSecond; // 0x0650
	bool m_bIsOn; // 0x0654
	C_PointCamera* m_pNext; // 0x0658
};
class CPathWithDynamicNodes : public CPathSimple // client
{
	C_NetworkUtlVectorBase< CHandle< CPathNode > > m_vecPathNodes; // 0x0710
	CTransform m_xInitialPathWorldToLocal; // 0x0730
};
class CBaseFilter : public CLogicalEntity // client
{
	bool m_bNegated; // 0x0600
	CEntityIOOutput m_OnPass; // 0x0608
	CEntityIOOutput m_OnFail; // 0x0620
};
class WeaponPurchaseTracker_t // client
{
	C_UtlVectorEmbeddedNetworkVar< WeaponPurchaseCount_t > m_weaponPurchases; // 0x0008
};
class CMapInfo : public C_PointEntity // client
{
	int32 m_iBuyingStatus; // 0x0600
	float32 m_flBombRadius; // 0x0604
	int32 m_iPetPopulation; // 0x0608
	bool m_bUseNormalSpawnsForDM; // 0x060C
	bool m_bDisableAutoGeneratedDMSpawns; // 0x060D
	float32 m_flBotMaxVisionDistance; // 0x0610
	int32 m_iHostageCount; // 0x0614
	bool m_bFadePlayerVisibilityFarZ; // 0x0618
	bool m_bRainTraceToSkyEnabled; // 0x0619
	bool m_bGPUCullSkybox; // 0x061A
	float32 m_flEnvRainStrength; // 0x061C
	float32 m_flEnvPuddleRippleStrength; // 0x0620
	float32 m_flEnvPuddleRippleDirection; // 0x0624
	float32 m_flEnvWetnessCoverage; // 0x0628
	float32 m_flEnvWetnessDryingAmount; // 0x062C
};
class C_CSGO_EndOfMatchCamera : public C_CSGO_TeamPreviewCamera // client
{
};
class C_BaseGrenade : public CBaseAnimGraph // client
{
	bool m_bHasWarnedAI; // 0x1180
	bool m_bIsSmokeGrenade; // 0x1181
	bool m_bIsLive; // 0x1182
	float32 m_DmgRadius; // 0x1184
	GameTime_t m_flDetonateTime; // 0x1188
	float32 m_flWarnAITime; // 0x118C
	float32 m_flDamage; // 0x1190
	CUtlSymbolLarge m_iszBounceSound; // 0x1198
	CUtlString m_ExplosionSound; // 0x11A0
	CHandle< C_CSPlayerPawn > m_hThrower; // 0x11A8
	GameTime_t m_flNextAttack; // 0x11C0
	CHandle< C_CSPlayerPawn > m_hOriginalThrower; // 0x11C4
};
class C_PlayerSprayDecal : public C_ModelPointEntity // client
{
	int32 m_nUniqueID; // 0x0FB0
	uint32 m_unAccountID; // 0x0FB4
	uint32 m_unTraceID; // 0x0FB8
	uint32 m_rtGcTime; // 0x0FBC
	VectorWS m_vecEndPos; // 0x0FC0
	VectorWS m_vecStart; // 0x0FCC
	Vector m_vecLeft; // 0x0FD8
	Vector m_vecNormal; // 0x0FE4
	int32 m_nPlayer; // 0x0FF0
	int32 m_nEntity; // 0x0FF4
	int32 m_nHitbox; // 0x0FF8
	float32 m_flCreationTime; // 0x0FFC
	int32 m_nTintID; // 0x1000
	uint8 m_nVersion; // 0x1004
	uint8[128] m_ubSignature; // 0x1005
	CPlayerSprayDecalRenderHelper m_SprayRenderHelper; // 0x1090
};
class CEntityIdentity // entity2
{
	int32 m_nameStringTableIndex; // 0x0014
	CUtlSymbolLarge m_name; // 0x0018
	CUtlSymbolLarge m_designerName; // 0x0020
	uint32 m_flags; // 0x0030
	WorldGroupId_t m_worldGroupId; // 0x0038
	uint32 m_fDataObjectTypes; // 0x003C
	ChangeAccessorFieldPathIndex_t m_PathIndex; // 0x0040
	CEntityAttributeTable* m_pAttributes; // 0x0048
	CEntityIdentity* m_pPrev; // 0x0050
	CEntityIdentity* m_pNext; // 0x0058
	CEntityIdentity* m_pPrevByClass; // 0x0060
	CEntityIdentity* m_pNextByClass; // 0x0068
};
class CPulseCell_LimitCount::Criteria_t // pulse_runtime_lib
{
	bool m_bLimitCountPasses; // 0x0000
};
class C_CS2HudModelArms : public C_CS2HudModelBase // client
{
};
class CBasePlayerVData : public CEntitySubclassVDataBase // client
{
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCModel > > m_sModelName; // 0x0028
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCModel > > m_sModelNameAg2Override; // 0x0108
	CSkillFloat m_flHeadDamageMultiplier; // 0x01E8
	CSkillFloat m_flChestDamageMultiplier; // 0x01F8
	CSkillFloat m_flStomachDamageMultiplier; // 0x0208
	CSkillFloat m_flArmDamageMultiplier; // 0x0218
	CSkillFloat m_flLegDamageMultiplier; // 0x0228
	float32 m_flHoldBreathTime; // 0x0238
	float32 m_flDrowningDamageInterval; // 0x023C
	int32 m_nDrowningDamageInitial; // 0x0240
	int32 m_nDrowningDamageMax; // 0x0244
	int32 m_nWaterSpeed; // 0x0248
	float32 m_flUseRange; // 0x024C
	float32 m_flUseAngleTolerance; // 0x0250
	float32 m_flCrouchTime; // 0x0254
};
class C_LightSpotEntity : public C_LightEntity // client
{
};
class CCSGameModeRules_Deathmatch : public CCSGameModeRules // client
{
	GameTime_t m_flDMBonusStartTime; // 0x0030
	float32 m_flDMBonusTimeLength; // 0x0034
	CUtlString m_sDMBonusWeapon; // 0x0038
};
class CPulseCell_CursorQueue : public CPulseCell_WaitForCursorsWithTagBase // pulse_runtime_lib
{
	int32 m_nCursorsAllowedToRunParallel; // 0x0128
};
class CPulseCell_Value_RandomFloat : public CPulseCell_BaseValue // pulse_runtime_lib
{
};
class CPulseExecCursor // pulse_runtime_lib
{
};
class C_Sprite : public C_BaseModelEntity // client
{
	CStrongHandle< InfoForResourceTypeIMaterial2 > m_hSpriteMaterial; // 0x0FB0
	CHandle< C_BaseEntity > m_hAttachedToEntity; // 0x0FB8
	AttachmentHandle_t m_nAttachment; // 0x0FBC
	float32 m_flSpriteFramerate; // 0x0FC0
	float32 m_flFrame; // 0x0FC4
	GameTime_t m_flDieTime; // 0x0FC8
	uint32 m_nBrightness; // 0x0FD8
	float32 m_flBrightnessDuration; // 0x0FDC
	float32 m_flSpriteScale; // 0x0FE0
	float32 m_flScaleDuration; // 0x0FE4
	bool m_bWorldSpaceScale; // 0x0FE8
	float32 m_flGlowProxySize; // 0x0FEC
	float32 m_flHDRColorScale; // 0x0FF0
	GameTime_t m_flLastTime; // 0x0FF4
	float32 m_flMaxFrame; // 0x0FF8
	float32 m_flStartScale; // 0x0FFC
	float32 m_flDestScale; // 0x1000
	GameTime_t m_flScaleTimeStart; // 0x1004
	int32 m_nStartBrightness; // 0x1008
	int32 m_nDestBrightness; // 0x100C
	GameTime_t m_flBrightnessTimeStart; // 0x1010
	int32 m_nSpriteWidth; // 0x1020
	int32 m_nSpriteHeight; // 0x1024
	float32 m_flSpeed; // 0x1028
};
class C_CsmFovOverride : public C_BaseEntity // client
{
	CUtlString m_cameraName; // 0x0600
	float32 m_flCsmFovOverrideValue; // 0x0608
};
class C_WeaponGlock : public C_CSWeaponBaseGun // client
{
};
class C_PhysicsProp : public C_BreakableProp // client
{
	bool m_bAwake; // 0x12F0
};
class CFilterTeam : public CBaseFilter // client
{
	int32 m_iFilterTeam; // 0x0638
};
class CBasePlayerWeaponVData : public CEntitySubclassVDataBase // client
{
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCModel > > m_szWorldModel; // 0x0028
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCModel > > m_szWorldModelAg2Override; // 0x0108
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeCModel > > m_sToolsOnlyOwnerModelName; // 0x01E8
	bool m_bBuiltRightHanded; // 0x02C8
	bool m_bAllowFlipping; // 0x02C9
	CAttachmentNameSymbolWithStorage m_sMuzzleAttachment; // 0x02D0
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > > m_szMuzzleFlashParticle; // 0x02F0
	CUtlString m_szMuzzleFlashParticleConfig; // 0x03D0
	CResourceNameTyped< CWeakHandle< InfoForResourceTypeIParticleSystemDefinition > > m_szBarrelSmokeParticle; // 0x03D8
	uint8 m_nMuzzleSmokeShotThreshold; // 0x04B8
	float32 m_flMuzzleSmokeTimeout; // 0x04BC
	float32 m_flMuzzleSmokeDecrementRate; // 0x04C0
	bool m_bGenerateMuzzleLight; // 0x04C4
	bool m_bLinkedCooldowns; // 0x04C5
	ItemFlagTypes_t m_iFlags; // 0x04C6
	int32 m_iWeight; // 0x04C8
	bool m_bAutoSwitchTo; // 0x04CC
	bool m_bAutoSwitchFrom; // 0x04CD
	AmmoIndex_t m_nPrimaryAmmoType; // 0x04CE
	AmmoIndex_t m_nSecondaryAmmoType; // 0x04CF
	int32 m_iMaxClip1; // 0x04D0
	int32 m_iMaxClip2; // 0x04D4
	int32 m_iDefaultClip1; // 0x04D8
	int32 m_iDefaultClip2; // 0x04DC
	bool m_bReserveAmmoAsClips; // 0x04E0
	bool m_bTreatAsSingleClip; // 0x04E1
	bool m_bKeepLoadedAmmo; // 0x04E2
	RumbleEffect_t m_iRumbleEffect; // 0x04E4
	float32 m_flDropSpeed; // 0x04E8
	int32 m_iSlot; // 0x04EC
	int32 m_iPosition; // 0x04F0
	CUtlOrderedMap< WeaponSound_t, CSoundEventName > m_aShootSounds; // 0x04F8
};
class CEnvCombinedLightProbeVolumeAPI // client
{
};
class C_SmokeGrenade : public C_BaseCSGrenade // client
{
};
class C_CSGO_PreviewPlayerAlias_csgo_player_previewmodel : public C_CSGO_PreviewPlayer // client
{
};
class CInfoParticleTarget : public C_PointEntity // client
{
};
class CCSPlayer_DamageReactServices : public CPlayerPawnComponent // client
{
};
class C_PointClientUIWorldPanel : public C_BaseClientUIEntity // client
{
	bool m_bForceRecreateNextUpdate; // 0x0FE8
	bool m_bMoveViewToPlayerNextThink; // 0x0FE9
	bool m_bCheckCSSClasses; // 0x0FEA
	CTransform m_anchorDeltaTransform; // 0x0FF0
	CPointOffScreenIndicatorUi* m_pOffScreenIndicator; // 0x1180
	bool m_bIgnoreInput; // 0x11A8
	bool m_bLit; // 0x11A9
	bool m_bFollowPlayerAcrossTeleport; // 0x11AA
	float32 m_flWidth; // 0x11AC
	float32 m_flHeight; // 0x11B0
	float32 m_flDPI; // 0x11B4
	float32 m_flInteractDistance; // 0x11B8
	float32 m_flDepthOffset; // 0x11BC
	uint32 m_unOwnerContext; // 0x11C0
	uint32 m_unHorizontalAlign; // 0x11C4
	uint32 m_unVerticalAlign; // 0x11C8
	uint32 m_unOrientation; // 0x11CC
	bool m_bAllowInteractionFromAllSceneWorlds; // 0x11D0
	C_NetworkUtlVectorBase< CUtlSymbolLarge > m_vecCSSClasses; // 0x11D8
	bool m_bOpaque; // 0x11F0
	bool m_bNoDepth; // 0x11F1
	bool m_bVisibleWhenParentNoDraw; // 0x11F2
	bool m_bRenderBackface; // 0x11F3
	bool m_bUseOffScreenIndicator; // 0x11F4
	bool m_bExcludeFromSaveGames; // 0x11F5
	bool m_bGrabbable; // 0x11F6
	bool m_bOnlyRenderToTexture; // 0x11F7
	bool m_bDisableMipGen; // 0x11F8
	int32 m_nExplicitImageLayout; // 0x11FC
	bool m_bIgnoreParentOrientation; // 0x1200
};
class C_EntityFlame : public C_BaseEntity // client
{
	CHandle< C_BaseEntity > m_hEntAttached; // 0x0600
	CHandle< C_BaseEntity > m_hOldAttached; // 0x0628
	bool m_bCheapEffect; // 0x062C
};
class CBaseAnimGraphAlias_baseanimating : public CBaseAnimGraph // client
{
};
class C_CSGO_MapPreviewCameraPathNode_API // client
{
};
class CBasePlayerController : public C_BaseEntity // client
{
	C_CommandContext m_CommandContext; // 0x0608
	uint64 m_nInButtonsWhichAreToggles; // 0x06B0
	uint32 m_nTickBase; // 0x06B8
	CHandle< C_BasePlayerPawn > m_hPawn; // 0x06BC
	bool m_bKnownTeamMismatch; // 0x06C0
	CHandle< C_BasePlayerPawn > m_hPredictedPawn; // 0x06C4
	CSplitScreenSlot m_nSplitScreenSlot; // 0x06C8
	CHandle< CBasePlayerController > m_hSplitOwner; // 0x06CC
	CUtlVector< CHandle< CBasePlayerController > > m_hSplitScreenPlayers; // 0x06D0
	bool m_bIsHLTV; // 0x06E8
	PlayerConnectedState m_iConnected; // 0x06EC
	PlayerConnectedState m_iMostConnected; // 0x06F0
	char[128] m_iszPlayerName; // 0x06F4
	uint64 m_steamID; // 0x0780
	bool m_bIsLocalPlayerController; // 0x0788
	bool m_bNoClipEnabled; // 0x0789
	uint32 m_iDesiredFOV; // 0x078C
};
class C_CSGO_EndOfMatchLineupEndpoint : public C_BaseEntity // client
{
};

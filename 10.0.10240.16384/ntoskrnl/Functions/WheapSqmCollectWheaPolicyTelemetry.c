// WheapSqmCollectWheaPolicyTelemetry 
 
int WheapSqmCollectWheaPolicyTelemetry()
{
  int v0; // r0

  WheapSqmDwordCommon(5, (int)WHEA_SQM_EVENT_SETDWORD, 7201, WheaRegistryKeysPresent);
  WheapSqmDwordCommon(5, (int)WHEA_SQM_EVENT_SETDWORD, 7310, WheapPolicyDisableOffline != 0);
  WheapSqmDwordCommon(5, (int)WHEA_SQM_EVENT_SETDWORD, 7197, WheapPolicyMemPersistOffline != 0);
  WheapSqmDwordCommon(5, (int)WHEA_SQM_EVENT_SETDWORD, 7200, WheapPolicyMemPfaDisable == 0);
  WheapSqmDwordCommon(5, (int)WHEA_SQM_EVENT_SETDWORD, 7199, WheapPolicyMemPfaPageCount);
  WheapSqmDwordCommon(5, (int)WHEA_SQM_EVENT_SETDWORD, 7198, WheapPolicyMemPfaThreshold);
  v0 = _rt_udiv64((unsigned int)dword_989680, WheapPolicyMemPfaTimeout);
  return WheapSqmDwordCommon(5, (int)WHEA_SQM_EVENT_SETDWORD, 7251, v0);
}

// RtlValidSid 
 
BOOL __fastcall RtlValidSid(_BYTE *a1)
{
  if ( (unsigned int)a1 <= MmUserProbeAddress )
    return 0;
  return a1 && (*a1 & 0xF) == 1 && (unsigned __int8)a1[1] <= 0xFu;
}

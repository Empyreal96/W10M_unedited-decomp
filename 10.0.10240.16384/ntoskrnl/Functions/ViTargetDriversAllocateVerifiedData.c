// ViTargetDriversAllocateVerifiedData 
 
_DWORD *__fastcall ViTargetDriversAllocateVerifiedData(int a1)
{
  _BYTE *v2; // r0
  _DWORD *v3; // r4
  unsigned int v4; // r1

  v2 = (_BYTE *)ExAllocatePoolWithTag(512, 168, 1146512982);
  v3 = v2;
  if ( v2 )
  {
    memset(v2, 0, 168);
    *v3 = a1;
    v3[5] = -1737090752;
    v3[2] = v3 + 2;
    v3[3] = v3 + 2;
    v3[6] = 0;
    v3[7] = 0;
    v3[8] = 0;
    v3[9] = 0;
    v3[34] = v3 + 34;
    v3[35] = v3 + 34;
  }
  else
  {
    __dmb(0xBu);
    do
      v4 = __ldrex(ViTargetAllocationFailures);
    while ( __strex(1u, ViTargetAllocationFailures) );
    __dmb(0xBu);
  }
  return v3;
}

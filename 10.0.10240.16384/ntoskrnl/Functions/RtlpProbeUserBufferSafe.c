// RtlpProbeUserBufferSafe 
 
int __fastcall RtlpProbeUserBufferSafe(int a1, int a2)
{
  int v2; // r2
  int v3; // r1
  int v4; // r0

  if ( (a2 & 7) != 0 )
  {
    v2 = a2;
    v3 = a1;
    v4 = 9;
    goto LABEL_7;
  }
  v2 = a2 - 8;
  if ( *(_BYTE *)(a2 - 1) == 5 )
    v2 -= 8 * *(unsigned __int8 *)(a2 - 2);
  if ( (*(_BYTE *)(v2 + 7) & 0x3F) == 0 )
  {
    v3 = a1;
    v4 = 8;
LABEL_7:
    RtlpLogHeapFailure(v4, v3, v2, 0, 0);
    v2 = 0;
  }
  return v2;
}

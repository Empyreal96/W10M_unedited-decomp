// MiModifiedWriterNoReservationSort 
 
int __fastcall MiModifiedWriterNoReservationSort(_DWORD *a1, _DWORD *a2)
{
  int v2; // r1
  int v3; // r5
  unsigned int v4; // r0
  unsigned int v5; // r3
  unsigned int v6; // r2
  unsigned int v7; // r3
  int result; // r0

  v2 = MmPfnDatabase + 24 * *a2;
  v3 = MmPfnDatabase + 24 * *a1;
  v4 = *(_DWORD *)(v2 + 20) & 0xFFFFF;
  v5 = *(_DWORD *)(v3 + 20) & 0xFFFFF;
  if ( v5 < v4 )
    return -1;
  if ( v5 > v4 )
    goto LABEL_7;
  v6 = *(_DWORD *)(v2 + 4) | 0x80000000;
  v7 = *(_DWORD *)(v3 + 4) | 0x80000000;
  if ( v7 < v6 )
    return -1;
  if ( v7 > v6 )
LABEL_7:
    result = 1;
  else
    result = 0;
  return result;
}

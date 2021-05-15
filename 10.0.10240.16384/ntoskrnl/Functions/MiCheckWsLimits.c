// MiCheckWsLimits 
 
int __fastcall MiCheckWsLimits(int a1, unsigned int *a2, unsigned int *a3, char a4, char a5)
{
  unsigned int v5; // r5
  unsigned int v6; // r4
  int result; // r0
  int v11; // r3
  int v12; // r2
  int v13; // r2

  v5 = *a2;
  v6 = *a3;
  result = 0;
  if ( *a2 > *a3 )
    return sub_5101B8(0);
  if ( v6 > MiMaximumWorkingSet )
  {
    v6 = MiMaximumWorkingSet;
    result = 1073741826;
  }
  if ( v5 > MiMaximumWorkingSet )
  {
    v5 = MiMaximumWorkingSet;
    result = 1073741826;
  }
  if ( v5 < 0x14 )
  {
    v5 = 20;
    result = 1073741826;
    if ( v6 < 0x14 )
      v6 = 20;
  }
  v11 = *(_DWORD *)(a1 + 92);
  if ( v11 )
    v12 = *(_DWORD *)(v11 + 4);
  else
    v12 = 20;
  if ( v12 + 4 >= v6 )
  {
    if ( (a5 & 1) == 0 )
      goto LABEL_31;
    v6 = v12 + 5;
    result = 1073741826;
  }
  if ( (a4 & 4) == 0 )
  {
    v13 = *(unsigned __int8 *)(a1 + 112);
    if ( ((v13 & 0xFFFFFF80) != 128 || (a4 & 8) != 0) && (a4 & 1) == 0 && ((v13 & 0x40) == 0 || (a4 & 2) != 0) )
      goto LABEL_18;
  }
  if ( v5 + 4 >= v6 )
  {
    if ( (a5 & 1) == 0 )
      goto LABEL_31;
    v6 = v5 + 5;
    result = 1073741826;
  }
  if ( (*(_BYTE *)(a1 + 112) & 7u) < 2 || v6 >= 0x1000 )
    goto LABEL_18;
  if ( (a5 & 1) == 0 )
LABEL_31:
    JUMPOUT(0x5101C6);
  v6 = 4096;
  result = 1073741826;
LABEL_18:
  *a2 = v5;
  *a3 = v6;
  return result;
}

// SepBuildCapeSecurityDescriptor 
 
int __fastcall SepBuildCapeSecurityDescriptor(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int result; // r0
  int v8; // r1
  __int16 v9; // r3
  unsigned __int8 *v10; // r2
  int v11; // r2
  bool v12; // zf
  BOOL v13; // r3

  result = RtlCreateSecurityDescriptor(a1, *a2);
  if ( result < 0 )
    return result;
  *(_WORD *)(a1 + 2) |= 3u;
  v9 = *((_WORD *)a2 + 1);
  if ( (v9 & 4) == 0 )
    goto LABEL_3;
  if ( (*((_WORD *)a2 + 1) & 0x8000) == 0 )
  {
    v10 = (unsigned __int8 *)*((_DWORD *)a2 + 4);
    goto LABEL_8;
  }
  v11 = *((_DWORD *)a2 + 4);
  if ( v11 )
    v10 = &a2[v11];
  else
LABEL_3:
    v10 = 0;
LABEL_8:
  v12 = (v9 & 4) == 0;
  if ( (v9 & 4) != 0 )
    v8 = 1;
  v13 = (v9 & 8) != 0;
  if ( v12 )
    v8 = 0;
  result = RtlSetDaclSecurityDescriptor(a1, v8, v10, v13, a4);
  if ( result >= 0 )
    result = RtlSetSaclSecurityDescriptor(a1, 1, a3, 0);
  return result;
}

// SeCaptureSid 
 
int __fastcall SeCaptureSid(unsigned int a1, int a2, int a3, int a4, int a5, char a6, int *a7)
{
  unsigned int v7; // r6
  unsigned __int8 *v9; // r3
  int v10; // r10
  int v11; // r0
  int v12; // r9
  int v13; // r0
  unsigned int v14; // r4
  int v15; // r1

  v7 = a1;
  if ( (_BYTE)a2 )
  {
    v9 = (unsigned __int8 *)(a1 + 1);
    if ( a1 + 1 >= MmUserProbeAddress )
      v9 = (unsigned __int8 *)MmUserProbeAddress;
    v10 = *v9;
    v11 = RtlLengthRequiredSid(v10);
    v12 = v11;
    if ( v11 )
    {
      if ( (v7 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v11);
      if ( v11 + v7 > MmUserProbeAddress || v11 + v7 < v7 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
  }
  else
  {
    if ( !a6 )
    {
      *a7 = a1;
      return 0;
    }
    v10 = *(unsigned __int8 *)(a1 + 1);
    v12 = RtlLengthRequiredSid(v10);
  }
  v13 = ExAllocatePoolWithTag(1, v12, 1767073107);
  *a7 = v13;
  if ( !v13 )
    return -1073741670;
  memmove(v13, v7, v12);
  *(_BYTE *)(*a7 + 1) = v10;
  v14 = *a7;
  if ( !RtlValidSid(*a7, v15) )
  {
    ExFreePoolWithTag(v14);
    *a7 = 0;
    return -1073741704;
  }
  return 0;
}

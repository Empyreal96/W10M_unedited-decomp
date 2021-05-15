// SepBuildDaclWithAllApplicationPackageSid 
 
int __fastcall SepBuildDaclWithAllApplicationPackageSid(unsigned __int8 *a1, int a2, unsigned __int8 **a3)
{
  int v6; // r7
  int v7; // r4
  int v8; // r0
  int v9; // r10
  int v10; // r4
  unsigned __int8 *v11; // r0
  unsigned __int8 *v12; // r5
  unsigned int v14; // [sp+8h] [bp-38h] BYREF
  unsigned int v15; // [sp+Ch] [bp-34h] BYREF
  unsigned int v16; // [sp+10h] [bp-30h] BYREF
  int v17; // [sp+14h] [bp-2Ch]

  v6 = 0;
  v7 = RtlQueryInformationAcl(a1, &v16, 0xCu, 2);
  if ( v7 >= 0 )
  {
    v7 = RtlQueryInformationAcl(a1, &v14, 4u, 1);
    if ( v7 >= 0 )
    {
      v8 = RtlLengthSid(SeAllAppPackagesSid);
      v9 = v17;
      v10 = v8 + 8;
      v11 = (unsigned __int8 *)ExAllocatePoolWithTag(1, v17 + 2 * (v8 + 8), 1683187027);
      v12 = v11;
      if ( v11 )
      {
        memset(v11, 0, v9 + 2 * v10);
        v7 = RtlCreateAcl((int)v12, v9 + 2 * v10, v14);
        if ( v7 < 0 )
          goto LABEL_13;
        if ( a2 )
          v6 = 16;
        v7 = RtlpAddKnownAce(v12, v14, v6 | 3, 131097, (_BYTE *)SeAllAppPackagesSid, 0);
        if ( v7 < 0
          || (v7 = RtlpAddKnownAce(v12, v14, v6 | 0xA, 0x80000000, (_BYTE *)SeAllAppPackagesSid, 0), v7 < 0)
          || (v7 = RtlGetAce(a1, 0, (int)&v15), v7 < 0)
          || (v7 = RtlAddAce(v12, v14, 2u, v15, v9 - 8), v7 < 0) )
        {
LABEL_13:
          ExFreePoolWithTag((unsigned int)v12);
        }
        else
        {
          *a3 = v12;
        }
      }
      else
      {
        v7 = -1073741801;
      }
    }
  }
  return v7;
}

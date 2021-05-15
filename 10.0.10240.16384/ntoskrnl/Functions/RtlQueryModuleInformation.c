// RtlQueryModuleInformation 
 
int __fastcall RtlQueryModuleInformation(unsigned int *a1, int a2, int a3)
{
  int v3; // r6
  unsigned int *v4; // r10
  char *v6; // r5
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r9
  char *v10; // r8
  int v11; // r10
  int v12; // r1
  int v13; // [sp+4h] [bp-14Ch]
  char v15[320]; // [sp+10h] [bp-140h] BYREF

  v3 = a3;
  v4 = a1;
  if ( a2 != 268 )
    return sub_8114BC();
  if ( (a3 & 3) != 0 )
    return -1073741583;
  v6 = v15;
  while ( 1 )
  {
    v7 = ZwQuerySystemInformation();
    v8 = v7;
    if ( v7 != -1073741820 && v7 < 0 )
      break;
    if ( !v3 )
    {
      v9 = -241970064;
      v8 = 0;
LABEL_13:
      *v4 = v9;
      break;
    }
    if ( v7 >= 0 )
    {
      v9 = 268 * *(_DWORD *)v6;
      if ( *v4 < v9 )
      {
        v8 = -1073741789;
      }
      else
      {
        v13 = 0;
        if ( *(_DWORD *)v6 )
        {
          v10 = v6;
          v11 = v3;
          do
          {
            *(_DWORD *)v11 = *((_DWORD *)v10 + 3);
            *(_DWORD *)(v11 + 4) = *((_DWORD *)v10 + 4);
            *(_WORD *)(v11 + 8) = *((_WORD *)v10 + 15);
            memmove(v11 + 10, (int)(v10 + 32), 0x100u);
            v12 = v13;
            v3 += 4;
            ++v13;
            v11 += 268;
            v10 += 284;
          }
          while ( (unsigned int)(v12 + 1) < *(_DWORD *)v6 );
          v4 = a1;
        }
      }
      goto LABEL_13;
    }
    if ( v6 != v15 )
      ExFreePoolWithTag((unsigned int)v6);
    v6 = (char *)ExAllocatePoolWithQuotaTag(9u, 0, 1416393810);
    if ( !v6 )
      return -1073741670;
  }
  if ( v6 != v15 )
    ExFreePoolWithTag((unsigned int)v6);
  return v8;
}

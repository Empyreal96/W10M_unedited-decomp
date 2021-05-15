// sub_8AB370 
 
int __fastcall sub_8AB370(int a1)
{
  unsigned int *v2; // r6
  int v3; // r5
  int i; // r7
  unsigned int *v5; // r0
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r7
  unsigned int *v9; // r5
  char v11[8]; // [sp+10h] [bp-38h] BYREF
  unsigned __int16 v12[24]; // [sp+18h] [bp-30h] BYREF

  qmemcpy(v12, "\\??\\x:", 12);
  v2 = 0;
  v12[4] = *(_WORD *)dword_63282C;
  RtlInitUnicodeString((unsigned int)v11, v12);
  v3 = 32;
  for ( i = 0; ; i = 1 )
  {
    if ( v2 )
      ExFreePoolWithTag((unsigned int)v2);
    v5 = (unsigned int *)ExAllocatePoolWithTag(1, v3, 542329939);
    v2 = v5;
    if ( !v5 )
      break;
    memset(v5, 0, v3);
    v6 = sub_8AB264((int)v11, 5636096, 0, 0, (int)v2, v3, 0, 0);
    v7 = v6;
    if ( v6 >= 0 )
    {
      v8 = 0;
      if ( *v2 )
      {
        v9 = v2;
        do
        {
          sub_8AB448(a1, v9[2]);
          ++v8;
          v9 += 6;
        }
        while ( v8 < *v2 );
      }
LABEL_12:
      ExFreePoolWithTag((unsigned int)v2);
      return v7;
    }
    if ( v6 != -2147483643 || i )
      goto LABEL_12;
    v3 += 24 * (*v2 - 1);
  }
  return -1073741670;
}

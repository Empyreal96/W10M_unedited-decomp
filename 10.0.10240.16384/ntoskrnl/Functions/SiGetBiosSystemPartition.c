// SiGetBiosSystemPartition 
 
int __fastcall SiGetBiosSystemPartition(int *a1, int a2, int a3)
{
  int v4; // r7
  int v5; // r4
  char *v6; // r6
  unsigned int v7; // r5
  char *v8; // r0
  unsigned int v9; // r4
  unsigned int v10; // r0
  unsigned int v11; // r1
  unsigned int v12; // r2
  char *v14; // [sp+8h] [bp-20h] BYREF
  int v15[7]; // [sp+Ch] [bp-1Ch] BYREF

  v14 = 0;
  v15[0] = 0;
  v4 = 0;
  v5 = SiGetBiosSystemDisk((int *)&v14, a2, a3, 0);
  v6 = v14;
  if ( v5 < 0 )
    goto LABEL_17;
  v5 = SiGetDriveLayoutInformation((unsigned __int16 *)v14, v15);
  v7 = v15[0];
  if ( v5 >= 0 )
  {
    if ( !*(_DWORD *)v15[0] )
    {
      v8 = wcsstr(v6, (char *)L"\\Partition0");
      if ( v8 )
        *(_WORD *)v8 = 0;
      v9 = 2 * (wcslen((unsigned __int16 *)v6) + 21);
      v4 = ExAllocatePoolWithTag(1, v9, 1263556947);
      if ( !v4 )
      {
        v5 = -1073741670;
        goto LABEL_12;
      }
      v10 = *(_DWORD *)(v7 + 4);
      v11 = 0;
      v12 = v7 + 48;
      if ( v10 )
      {
        while ( !*(_BYTE *)(v12 + 33) )
        {
          ++v11;
          v12 += 144;
          if ( v11 >= v10 )
            goto LABEL_11;
        }
        swprintf_s(v4, v9 >> 1, (int)L"%s\\Partition%lu", v6, *(_DWORD *)(v12 + 24));
        *a1 = v4;
        v5 = 0;
        goto LABEL_12;
      }
    }
LABEL_11:
    v5 = -1073740718;
  }
LABEL_12:
  if ( v7 )
    ExFreePoolWithTag(v7);
  if ( v5 < 0 && v4 )
    ExFreePoolWithTag(v4);
LABEL_17:
  if ( v6 )
    ExFreePoolWithTag((unsigned int)v6);
  return v5;
}

// ExpFindDiskSignature 
 
int __fastcall ExpFindDiskSignature(unsigned int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, char a6)
{
  _DWORD *v6; // r7
  _DWORD *v7; // r9
  unsigned int v8; // r5
  _DWORD *v9; // r6
  int v10; // r8
  int v11; // r4
  int v12; // r0
  unsigned int v13; // r1
  unsigned int v15; // r9
  _DWORD *v16; // r7
  unsigned int v20; // [sp+14h] [bp-4Ch]
  _DWORD *v21; // [sp+18h] [bp-48h] BYREF
  _DWORD *v22; // [sp+1Ch] [bp-44h]
  unsigned int v23; // [sp+20h] [bp-40h]
  int v24; // [sp+28h] [bp-38h]

  v6 = a5;
  v7 = a4;
  v22 = a3;
  v8 = 0;
  v9 = 0;
  v21 = 0;
  v10 = 0;
  v11 = ZwQuerySystemInformation();
  if ( v11 >= 0 )
  {
    v12 = ExAllocatePoolWithTag(512, 76, 1920364101);
    v20 = v12;
    if ( v12 )
    {
      if ( v24 )
      {
        swprintf_s(v12, 38, (int)L"\\Device\\Harddisk%lu\\Partition0", 0);
        v11 = ExpGetPartitionTableInfo(v20, &v21);
        v8 = (unsigned int)v21;
        if ( v11 < 0 )
          JUMPOUT(0x815296);
        if ( *v21 != (a6 == 1) )
          goto LABEL_28;
        v13 = a1;
        if ( a6 != 1 )
          return sub_815284();
        v15 = 0;
        v23 = v21[1];
        if ( v23 )
        {
          v16 = v21 + 12;
          while ( 1 )
          {
            v9 = v16;
            if ( !memcmp((unsigned int)(v16 + 12), v13, 16) )
              break;
            ++v15;
            v13 = a1;
            v16 += 36;
            if ( v15 >= v23 )
              goto LABEL_14;
          }
          v10 = 1;
        }
LABEL_14:
        if ( v10 != 1 )
LABEL_28:
          JUMPOUT(0x81528E);
        v7 = a4;
        v6 = a5;
      }
      if ( !v10 )
        v11 = -1073741766;
      if ( v10 == 1 )
      {
        *a2 = v9[6];
        *v22 = 0;
        if ( v7 )
        {
          *v7 = v9[2];
          v7[1] = v9[3];
        }
        if ( v6 )
        {
          *v6 = v9[4];
          v6[1] = v9[5];
        }
        ExFreePoolWithTag(v8);
      }
      ExFreePoolWithTag(v20);
    }
    else
    {
      v11 = -1073741670;
    }
  }
  return v11;
}

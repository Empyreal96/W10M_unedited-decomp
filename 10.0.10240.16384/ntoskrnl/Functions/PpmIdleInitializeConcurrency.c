// PpmIdleInitializeConcurrency 
 
int __fastcall PpmIdleInitializeConcurrency(int a1, int *a2)
{
  int v2; // r6
  int v4; // r7
  int v5; // r5
  int v6; // r4
  int v7; // r1
  int v8; // r2
  int v9; // r3
  _BYTE *v10; // r0
  unsigned int v11; // r2
  int v13; // [sp+0h] [bp-38h] BYREF
  int v14; // [sp+4h] [bp-34h]
  int v15; // [sp+8h] [bp-30h]
  _DWORD v16[10]; // [sp+10h] [bp-28h] BYREF

  v2 = *(_DWORD *)(a1 + 8);
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v4 = (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v2 >> 16))
                       + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v2 >> 24))
                       + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v2 >> 8))
                       + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v2));
  if ( v2 )
  {
    v14 = 0;
    v13 = v2;
    v15 = 0;
    v5 = 0;
  }
  else
  {
    v5 = -1073741275;
  }
  KeSetSystemGroupAffinityThread((int)&v13, v16);
  v6 = ExAllocatePoolWithTag(512, 8 * (v4 + 5), 1884115024);
  KeRevertToUserGroupAffinityThread((int)v16, v7, v8, v9);
  if ( v6 )
  {
    v10 = memset((_BYTE *)v6, 0, 8 * (v4 + 5));
    *(_DWORD *)v6 = 0;
    *(_DWORD *)(v6 + 4) = v4;
    *(_QWORD *)(v6 + 16) = PpmQueryTime((int)v10, v11);
  }
  else
  {
    v5 = -1073741670;
  }
  *a2 = v6;
  return v5;
}

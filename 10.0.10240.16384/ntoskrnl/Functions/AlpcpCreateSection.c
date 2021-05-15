// AlpcpCreateSection 
 
int __fastcall AlpcpCreateSection(int a1, int a2, int a3, int a4, int a5)
{
  char v5; // r6
  _BYTE *v7; // r0
  _DWORD *v8; // r4
  int v11; // r3
  int v12; // r0
  int v13[10]; // [sp+10h] [bp-28h] BYREF

  v5 = a2;
  if ( a2 && a4 )
    return -1073741811;
  v7 = (_BYTE *)AlpcpAllocateBlob(AlpcSectionType, 40, 1);
  v8 = v7;
  if ( !v7 )
    return -1073741670;
  memset(v7, 0, 40);
  v8[4] = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v8[1] = (a5 + AlpcpRegionGranularity - 1) & ~(AlpcpRegionGranularity - 1);
  v8[8] = v8 + 8;
  v8[9] = v8 + 8;
  if ( a4 )
  {
    v11 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    v12 = ObReferenceObjectByHandle(a4, 6, MmSectionObjectType, v11, v13);
    *v8 = v13[0];
  }
  else
  {
    v13[0] = v8[1];
    v13[1] = 0;
    v8[6] = v8[6] ^ ((unsigned __int8)v8[6] ^ (unsigned __int8)(2 * v5)) & 2 | 1;
    v12 = MmCreateSection(v8, 983071, 0, v13, 4, 0x8000000, 0, 0);
  }
  return sub_7F5990(v12);
}

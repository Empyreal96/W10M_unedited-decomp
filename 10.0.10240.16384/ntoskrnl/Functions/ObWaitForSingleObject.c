// ObWaitForSingleObject 
 
int __fastcall ObWaitForSingleObject(int a1, int a2, int a3, _DWORD *a4, int *a5)
{
  char v6; // r10
  int v7; // r4
  int v8; // r6
  int v9; // r5
  signed int v10; // r0
  int v12; // [sp+10h] [bp-28h] BYREF
  int v13; // [sp+14h] [bp-24h]
  _DWORD *v14; // [sp+18h] [bp-20h]

  v12 = a2;
  v13 = a3;
  v14 = a4;
  v6 = a3;
  v7 = ObReferenceObjectByHandleWithTag(a1, 0x100000, 0, (char)a2, 1951883855, &v12, 0);
  if ( v7 >= 0 )
  {
    v8 = v12;
    v9 = ObTypeIndexTable[*(unsigned __int8 *)(v12 - 12) ^ (unsigned __int8)((unsigned __int16)(v12 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
    v10 = *(_DWORD *)(v9 + 16);
    if ( (v10 & 1) != 0 )
    {
      if ( (v10 & 2) != 0 )
      {
        if ( (*(_DWORD *)(*(unsigned __int16 *)(v9 + 124) + v12) & *(_DWORD *)(v9 + 120)) == *(_DWORD *)(v9 + 120) )
          v10 = *(_DWORD *)(*(unsigned __int16 *)(v9 + 126) + v12);
        else
          v10 = v10 + v12 - 3;
      }
      else
      {
        v10 = *(_DWORD *)(v10 + v12 - 1);
      }
    }
    else if ( v10 >= 0 )
    {
      v10 += v12;
    }
    v7 = KeWaitForSingleObject(v10, 6, v6, a4, a5);
    v13 = v7;
    ObfDereferenceObjectWithTag(v8);
  }
  return v7;
}

// ObOpenObjectByPointer 
 
int __fastcall ObOpenObjectByPointer(int a1, int a2, char *a3, int a4, int a5, char a6, _DWORD *a7)
{
  int v8; // r5
  int result; // r0
  int v13; // r4
  unsigned int v14; // r0
  int v15; // r4
  int v16; // r5
  int v17; // r0
  char v18; // [sp+18h] [bp-178h] BYREF
  char v19[7]; // [sp+19h] [bp-177h] BYREF
  int v20; // [sp+20h] [bp-170h] BYREF
  char v21[4]; // [sp+24h] [bp-16Ch] BYREF
  int v22; // [sp+28h] [bp-168h]
  int v23; // [sp+2Ch] [bp-164h]
  char v24[120]; // [sp+30h] [bp-160h] BYREF
  char v25[232]; // [sp+A8h] [bp-E8h] BYREF

  *a7 = 0;
  v8 = a5;
  result = ObReferenceObjectByPointerWithTag(a1, 0, a5, a6);
  if ( result >= 0 )
  {
    if ( !a5 )
      v8 = ObTypeIndexTable[*(unsigned __int8 *)(a1 - 12) ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
    if ( (*(_DWORD *)(v8 + 48) & a2) != 0 || (*(_BYTE *)(a1 - 9) & 1) != 0 && *(_DWORD *)(a1 - 8) )
    {
      ++ObpInvalidOpenByPointer;
      ObfDereferenceObjectWithTag(a1);
      result = -1073741811;
    }
    else
    {
      if ( !a3 )
      {
        v13 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v23 = *(_DWORD *)(v13 + 176);
        if ( !v14 )
          return sub_7BE6F4(0);
        v20 = PsReferenceImpersonationTokenEx(v14, 0, v19, &v18, v21, 0);
        v22 = PsReferencePrimaryToken(v13);
        v15 = SepCreateAccessStateFromSubjectContext(&v20, (int)v24, (int)v25, a4, (_DWORD *)(v8 + 52));
        if ( v15 < 0 )
        {
          ObfDereferenceObjectWithTag(a1);
          return v15;
        }
        a3 = v24;
      }
      v16 = ObpCreateHandle(1, a1, 0, a3, 0, a2, a6, 0, 0, a7);
      if ( v16 < 0 )
        ObfDereferenceObjectWithTag(a1);
      if ( a3 == v24 )
      {
        SepDeleteAccessState((int)a3);
        ObFastDereferenceObject(
          (_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 244),
          *((_DWORD *)a3 + 9));
        v17 = *((_DWORD *)a3 + 7);
        *((_DWORD *)a3 + 9) = 0;
        if ( v17 )
          ObfDereferenceObject(v17);
        *((_DWORD *)a3 + 7) = 0;
      }
      result = v16;
    }
  }
  return result;
}

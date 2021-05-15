// PopPowerRequestActionInfo 
 
int __fastcall PopPowerRequestActionInfo(int a1, int a2, int a3, int a4)
{
  int v5; // r7
  int v6; // r2
  int v7; // r4
  int v8; // r3
  int v9; // r5
  unsigned int v10; // r1
  int v11; // r0
  int v13; // [sp+8h] [bp-18h] BYREF
  int v14[5]; // [sp+Ch] [bp-14h] BYREF

  v13 = a3;
  v14[0] = a4;
  v5 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v7 = ObReferenceObjectByHandle(*(_DWORD *)a1, 0, PopPowerRequestObjectType, v5, (int)v14, 0);
  if ( v7 >= 0 )
  {
    v8 = *(_DWORD *)(a1 + 4);
    v9 = v14[0];
    if ( v8 == 3 )
    {
      if ( v5 )
      {
        v7 = SeIsAppContainerOrIdentifyLevelContext(0, &v13);
        if ( v7 < 0 )
          goto LABEL_18;
        if ( (_BYTE)v13 )
        {
          v7 = -1073741790;
          goto LABEL_18;
        }
      }
    }
    else if ( v8 == 4 && v5 != 1 )
    {
      v7 = -1073741637;
LABEL_18:
      ObfDereferenceObject(v9);
      return v7;
    }
    v10 = *(_DWORD *)(a1 + 4);
    if ( *(_BYTE *)(a1 + 8) )
    {
      if ( *(_BYTE *)(v9 + 72) )
        v11 = PopSetSpecialRequest((_DWORD *)v9, v10, *(_DWORD *)(a1 + 12));
      else
        v11 = PoSetPowerRequestInternal(v9, v10, v6, 0);
    }
    else if ( *(_BYTE *)(v9 + 72) )
    {
      v11 = PopClearSpecialRequest((_DWORD *)v9, v10);
    }
    else
    {
      v11 = PoClearPowerRequestInternal(v9, v10, v6, 0);
    }
    v7 = v11;
    goto LABEL_18;
  }
  return v7;
}

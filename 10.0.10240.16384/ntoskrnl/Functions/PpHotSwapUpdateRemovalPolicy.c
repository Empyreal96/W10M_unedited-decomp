// PpHotSwapUpdateRemovalPolicy 
 
int __fastcall PpHotSwapUpdateRemovalPolicy(int a1)
{
  int result; // r0
  int v3; // r5
  int v4; // r3
  int v5; // r2
  int v6; // r2
  int v7; // [sp+10h] [bp-18h] BYREF
  int v8; // [sp+14h] [bp-14h] BYREF
  int v9; // [sp+18h] [bp-10h] BYREF
  int v10[3]; // [sp+1Ch] [bp-Ch] BYREF

  v8 = 0;
  result = PiHotSwapGetDetachableNode(a1, &v9);
  v3 = v9;
  if ( !v9 )
  {
    *(_BYTE *)(a1 + 318) = 1;
    *(_BYTE *)(a1 + 319) = 1;
    return result;
  }
  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 16) + 32);
  v5 = v4 & 0x300;
  if ( (v4 & 0x4000) != 0 )
    goto LABEL_18;
  if ( (v4 & 0x8000) != 0 )
  {
LABEL_17:
    v6 = 3;
    goto LABEL_10;
  }
  if ( v5 == 512 )
  {
LABEL_18:
    v6 = 2;
    goto LABEL_10;
  }
  if ( v5 == 768 )
    goto LABEL_17;
  if ( a1 != v9 )
  {
    v6 = 6;
LABEL_10:
    v7 = v6;
    goto LABEL_11;
  }
  PiHotSwapGetDefaultBusRemovalPolicy(a1, &v7);
  v6 = v7;
LABEL_11:
  if ( a1 != v3 && v6 > *(unsigned __int8 *)(*(_DWORD *)(a1 + 8) + 318) )
  {
    LOBYTE(v6) = *(_BYTE *)(*(_DWORD *)(a1 + 8) + 318);
    v7 = (unsigned __int8)v6;
  }
  v10[0] = 4;
  *(_BYTE *)(a1 + 318) = v6;
  *(_BYTE *)(a1 + 319) = v6;
  result = CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), 0, 34, (int)&v8, (int)&v7, (int)v10);
  if ( result >= 0 )
    result = sub_7C9C80();
  return result;
}

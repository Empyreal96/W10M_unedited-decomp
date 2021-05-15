// CmpGetVirtualizationID 
 
int __fastcall CmpGetVirtualizationID(int a1)
{
  int v2; // r0
  int v3; // r7
  int v4; // r4
  int v5; // r5
  int v6; // r1
  int v7; // r0
  int v8; // r2
  int v9; // r3
  bool v11; // [sp+8h] [bp-70h] BYREF
  unsigned __int16 v12; // [sp+10h] [bp-68h] BYREF
  int v13; // [sp+12h] [bp-66h]
  __int16 v14; // [sp+16h] [bp-62h]
  int v15; // [sp+18h] [bp-60h] BYREF
  int v16; // [sp+1Ch] [bp-5Ch] BYREF
  char v17[88]; // [sp+20h] [bp-58h] BYREF

  v12 = 0;
  v13 = 0;
  v14 = 0;
  v2 = PsReferenceEffectiveToken((_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0), &v16, &v11, &v15, 0);
  v3 = v16;
  v4 = v2;
  if ( v16 == 2 && v15 < 2 )
  {
    if ( v2 )
      ObfDereferenceObject(v2);
    v4 = PsReferencePrimaryToken(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
    v3 = 1;
  }
  SeQueryUserSidToken(v4, (int)v17, 0x44u, 0);
  v5 = RtlConvertSidToUnicodeString(&v12, v17, 1);
  if ( v5 >= 0 )
  {
    v6 = (unsigned __int16)(v12 + 20);
    *(_WORD *)(a1 + 2) = v12 + 20;
    v7 = ExAllocatePoolWithTag(1, v6, 1700154691);
    *(_DWORD *)(a1 + 4) = v7;
    if ( v7 )
    {
      RtlCopyUnicodeString((unsigned __int16 *)a1, &v12);
      RtlAppendUnicodeToString((unsigned __int16 *)a1, (int)L"_Classes", v8, v9);
    }
    else
    {
      v5 = -1073741670;
    }
  }
  if ( v3 == 1 )
  {
    ObFastDereferenceObject((_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 244), v4);
  }
  else if ( v4 )
  {
    ObfDereferenceObject(v4);
  }
  RtlFreeAnsiString(&v12);
  return v5;
}

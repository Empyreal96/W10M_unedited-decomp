// RtlRaiseException 
 
int __fastcall RtlRaiseException(int a1)
{
  int v2; // r4
  int v3; // r6
  _DWORD *v4; // r0
  int result; // r0
  int v6; // [sp+10h] [bp-1C0h] BYREF
  int v7; // [sp+14h] [bp-1BCh] BYREF
  int v8; // [sp+18h] [bp-1B8h] BYREF
  _DWORD v9[16]; // [sp+20h] [bp-1B0h] BYREF
  unsigned int v10; // [sp+60h] [bp-170h]

  v2 = -1073741786;
  RtlpCaptureContext((int)v9);
  v3 = v10;
  v4 = (_DWORD *)RtlLookupFunctionEntry(v10, &v6, 0);
  if ( !v4 )
LABEL_4:
    RtlRaiseStatus(v2);
  RtlVirtualUnwind(0, v6, v3, v4, v9, &v8, &v7, 0);
  *(_DWORD *)(a1 + 12) = v10;
  result = RtlDispatchException(a1, (int)v9);
  if ( !result )
  {
    v2 = ZwRaiseException();
    goto LABEL_4;
  }
  return result;
}

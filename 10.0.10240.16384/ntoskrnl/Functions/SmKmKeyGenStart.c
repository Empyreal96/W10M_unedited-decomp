// SmKmKeyGenStart 
 
int __fastcall SmKmKeyGenStart(int a1, const struct _UNICODE_STRING *a2, int a3, int a4)
{
  int v6; // r7
  unsigned __int16 *v7; // r0
  unsigned __int16 *v8; // r6
  int v10; // r1
  __int16 v11; // r3
  int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a3;
  v12[1] = a4;
  if ( a2 )
  {
    v6 = a2->Length;
    v7 = (unsigned __int16 *)SmAlloc(v6 + 2, 1196125555);
    v8 = v7;
    if ( !v7 )
      return -1073741670;
    RtlStringCbCopyUnicodeString(v7, v6 + 2, a2);
    *(_WORD *)(a1 + 12) = 0;
    *(_WORD *)(a1 + 14) = 0;
    *(_DWORD *)(a1 + 16) = 0;
    if ( sub_5B3C84(v8, v10, v12) >= 0 )
    {
      v11 = v12[0];
      *(_DWORD *)(a1 + 16) = v8;
      v11 *= 2;
      *(_WORD *)(a1 + 12) = v11;
      *(_WORD *)(a1 + 14) = v11 + 2;
    }
  }
  return 0;
}

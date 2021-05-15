// sub_96910C 
 
void __fastcall sub_96910C(int a1, int a2, int a3, int a4, unsigned int a5)
{
  unsigned int v5; // r6
  int v6; // r5
  unsigned __int16 *i; // r7
  int v8; // r8
  int v9; // r0

  v5 = a5;
  v6 = *(_DWORD *)(a5 + 12);
  for ( i = (unsigned __int16 *)(*(_DWORD *)(a5 + 8) + a5); v6; i = (unsigned __int16 *)((char *)i + v8) )
  {
    RtlInitUnicodeString((unsigned int)&a5, i);
    v8 = HIWORD(a5);
    LOWORD(a5) = HIWORD(a5);
    v9 = PipLookupGroupName((unsigned __int16 *)&a5, 0);
    if ( v9 )
    {
      if ( !*(_DWORD *)(v9 + 16) )
        break;
    }
    v6 -= v8;
  }
  ExFreePoolWithTag(v5);
  JUMPOUT(0x95147A);
}

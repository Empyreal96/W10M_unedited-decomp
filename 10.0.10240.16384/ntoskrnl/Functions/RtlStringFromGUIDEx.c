// RtlStringFromGUIDEx 
 
int __fastcall RtlStringFromGUIDEx(int a1, int a2, int a3)
{
  int v5; // r0
  int result; // r0

  if ( a3 )
  {
    *(_WORD *)(a2 + 2) = 78;
    v5 = ExpAllocateStringRoutine(78);
    *(_DWORD *)(a2 + 4) = v5;
    if ( v5 )
    {
LABEL_3:
      *(_WORD *)a2 = 76;
      swprintf_s(
        *(_DWORD *)(a2 + 4),
        *(unsigned __int16 *)(a2 + 2) >> 1,
        (int)L"{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
        *(_DWORD *)a1,
        *(unsigned __int16 *)(a1 + 4),
        *(unsigned __int16 *)(a1 + 6),
        *(unsigned __int8 *)(a1 + 8),
        *(unsigned __int8 *)(a1 + 9),
        *(unsigned __int8 *)(a1 + 10),
        *(unsigned __int8 *)(a1 + 11),
        *(unsigned __int8 *)(a1 + 12),
        *(unsigned __int8 *)(a1 + 13),
        *(unsigned __int8 *)(a1 + 14),
        *(unsigned __int8 *)(a1 + 15));
      return 0;
    }
    result = -1073741801;
  }
  else
  {
    if ( *(unsigned __int16 *)(a2 + 2) >= 0x4Eu )
      goto LABEL_3;
    result = -1073741789;
  }
  return result;
}

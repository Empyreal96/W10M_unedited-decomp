// SddlpUuidToString 
 
int __fastcall SddlpUuidToString(int a1, int *a2)
{
  int v4; // r0

  v4 = ExAllocatePoolWithTag(1, 74, 1683187027);
  *a2 = v4;
  if ( !v4 )
    return 0;
  swprintf_s(
    v4,
    37,
    (int)L"%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
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
  return 1;
}

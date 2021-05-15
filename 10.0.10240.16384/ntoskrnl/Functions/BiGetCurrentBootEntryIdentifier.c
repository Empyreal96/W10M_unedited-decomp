// BiGetCurrentBootEntryIdentifier 
 
int __fastcall BiGetCurrentBootEntryIdentifier(_DWORD *a1)
{
  int result; // r0
  int v3; // [sp-4h] [bp-30h]
  int v4; // [sp+0h] [bp-2Ch]
  int v5; // [sp+4h] [bp-28h]
  int v6; // [sp+8h] [bp-24h]

  result = ZwQuerySystemInformation();
  if ( result >= 0 )
  {
    *a1 = v3;
    a1[1] = v4;
    a1[2] = v5;
    a1[3] = v6;
  }
  return result;
}

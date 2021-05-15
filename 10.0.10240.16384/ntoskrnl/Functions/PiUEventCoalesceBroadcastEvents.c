// PiUEventCoalesceBroadcastEvents 
 
int __fastcall PiUEventCoalesceBroadcastEvents(int result)
{
  int v1; // r5
  int i; // r4
  int v3; // r1
  unsigned __int16 v4[4]; // [sp+0h] [bp-20h] BYREF
  unsigned __int16 v5[12]; // [sp+8h] [bp-18h] BYREF

  v1 = result;
  for ( i = PiUEventBroadcastEventQueue; (int *)i != &PiUEventBroadcastEventQueue; i = *(_DWORD *)i )
  {
    v3 = *(_DWORD *)(i + 12);
    if ( v3 == *(_DWORD *)(v1 + 12) && *(_DWORD *)(i + 16) == *(_DWORD *)(v1 + 16) )
    {
      if ( v3 == 3 )
      {
        result = memcmp(i + 20, v1 + 20, 16);
        if ( !result )
        {
          RtlInitUnicodeString((unsigned int)v5, (unsigned __int16 *)(v1 + 36));
          RtlInitUnicodeString((unsigned int)v4, (unsigned __int16 *)(i + 36));
          result = RtlEqualUnicodeString(v5, v4, 1);
          if ( result )
            goto LABEL_7;
        }
      }
      else if ( v3 != 2 || (result = memcmp(v1 + 20, i + 20, 16)) == 0 )
      {
LABEL_7:
        *(_BYTE *)(i + 8) = 0;
        return result;
      }
    }
  }
  return result;
}

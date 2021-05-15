// PnpSetPlugPlayEvent 
 
unsigned __int8 *__fastcall PnpSetPlugPlayEvent(unsigned __int8 *result, int a2)
{
  unsigned __int8 *v2; // r10
  int v3; // r9
  unsigned __int8 *v4; // r7
  int v5; // r3
  int v6; // r4
  int v7; // r5
  int v8; // r3
  int v9; // [sp+0h] [bp-20h]

  v2 = result;
  if ( !dword_630874 )
  {
    v3 = *(_DWORD *)(*(_DWORD *)(a2 + 176) + 20);
    if ( v3 )
    {
      v9 = *(unsigned __int16 *)(v3 + 20) + 68;
      result = PnpCreateDeviceEventEntry(*(unsigned __int16 *)(v3 + 20) + 132);
      v4 = result;
      if ( result )
      {
        v5 = *((_DWORD *)v2 + 1);
        v6 = *((_DWORD *)v2 + 2);
        v7 = *((_DWORD *)v2 + 3);
        *((_DWORD *)result + 16) = *(_DWORD *)v2;
        *((_DWORD *)result + 17) = v5;
        *((_DWORD *)result + 18) = v6;
        *((_DWORD *)result + 19) = v7;
        *((_DWORD *)result + 23) = v9;
        if ( PnpCompareGuid(v2, (int)&GUID_DEVICE_ENUMERATED) )
          v8 = 4;
        else
          v8 = 1;
        *((_DWORD *)v4 + 20) = v8;
        memmove((int)(v4 + 100), *(_DWORD *)(v3 + 24), *(unsigned __int16 *)(v3 + 20));
        *(_WORD *)&v4[2 * (*(unsigned __int16 *)(v3 + 20) >> 1) + 100] = 0;
        if ( PnpCompareGuid(v2, (int)&GUID_DEVICE_ENUMERATED) || PnpCompareGuid(v2, (int)&GUID_DEVICE_ARRIVAL) )
        {
          *((_DWORD *)v4 + 24) = 0;
          result = (unsigned __int8 *)PnpInsertEventInQueue(v4);
        }
        else
        {
          result = (unsigned __int8 *)sub_7CBE0C();
        }
      }
    }
  }
  return result;
}

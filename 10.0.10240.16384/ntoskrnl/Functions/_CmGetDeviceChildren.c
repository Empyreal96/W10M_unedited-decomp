// _CmGetDeviceChildren 
 
int __fastcall CmGetDeviceChildren(int a1, unsigned __int16 *a2, _WORD *a3, unsigned int *a4)
{
  _WORD *v4; // r4
  unsigned int v7; // r5
  int result; // r0
  unsigned int v9; // r7
  unsigned int v10; // r1
  int v11; // [sp+0h] [bp-360h]
  int v12; // [sp+0h] [bp-360h]
  unsigned int v13; // [sp+10h] [bp-350h] BYREF
  unsigned int v14; // [sp+14h] [bp-34Ch] BYREF
  char v15[8]; // [sp+18h] [bp-348h] BYREF
  char v16[400]; // [sp+20h] [bp-340h] BYREF
  unsigned __int16 v17[216]; // [sp+1B0h] [bp-1B0h] BYREF

  v4 = a3;
  if ( a3 )
  {
    if ( *a4 )
      *a3 = 0;
    else
      v4 = 0;
  }
  else
  {
    *a4 = 0;
  }
  v7 = *a4;
  *a4 = 0;
  result = RtlInitUnicodeStringEx((int)v15, a2);
  if ( result >= 0 )
  {
    result = NtPlugPlayGetDeviceRelatedDevice(a1, (int)v15, 2, (int)v16, v11, (int)&v13);
    if ( result >= 0 )
    {
      if ( v13 )
      {
        v9 = v13 + 1;
        if ( v7 )
        {
          v14 = 2 * v7;
          if ( !PnpMultiSzAppend(v4, &v14, v16) )
          {
            v4 = 0;
            v7 = 0;
          }
        }
        result = RtlStringCchCopyExW(v17, 200, v16, 0, 0, 2048);
        if ( result >= 0 )
        {
          result = RtlInitUnicodeStringEx((int)v15, v17);
          if ( result >= 0 )
          {
            while ( 1 )
            {
              result = NtPlugPlayGetDeviceRelatedDevice(a1, (int)v15, 3, (int)v16, v12, (int)&v13);
              if ( result == -1073741810 || !v13 )
                break;
              if ( result < 0 )
                return result;
              if ( v13 > 0xC8 )
                return -1073741811;
              v10 = 2 * (v13 - 1);
              if ( v10 >= 0x190 )
                _report_rangecheckfailure();
              v9 += v13;
              *(_WORD *)&v16[v10] = 0;
              if ( v7 )
              {
                v14 = 2 * v7;
                if ( !PnpMultiSzAppend(v4, &v14, v16) )
                {
                  v4 = 0;
                  v7 = 0;
                }
              }
              result = RtlStringCchCopyExW(v17, 200, v16, 0, 0, 2048);
              if ( result < 0 )
                return result;
              result = RtlInitUnicodeStringEx((int)v15, v17);
              if ( result < 0 )
                goto LABEL_29;
            }
            result = 0;
LABEL_29:
            if ( result >= 0 )
            {
              *a4 = v9;
              if ( v7 < v9 )
                result = -1073741789;
            }
          }
        }
      }
      else
      {
        result = -1073741275;
      }
    }
  }
  return result;
}

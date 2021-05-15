// _PnpCtxGetCachedContextBaseKey 
 
int __fastcall PnpCtxGetCachedContextBaseKey(_DWORD *a1, int a2, int *a3)
{
  int v4; // r4
  unsigned int v5; // r7
  int v6; // r6
  const __int16 *v9; // r8
  int v10; // r1
  int v11; // r0
  int v13; // r2
  int v14; // [sp+18h] [bp-28h] BYREF
  int v15[9]; // [sp+1Ch] [bp-24h] BYREF

  v4 = 0;
  v5 = 0;
  v6 = 0;
  v14 = 0;
  v15[0] = 0;
  v9 = 0;
  switch ( a2 )
  {
    case 1:
      v6 = 0;
      if ( *(_DWORD *)(*a1 + 12) )
      {
        v4 = *(_DWORD *)(*a1 + 12);
        v14 = v4;
      }
      else
      {
        v6 = -1073741772;
      }
      goto LABEL_4;
    case 2:
      v10 = 2;
      goto LABEL_3;
    case 3:
      v10 = 3;
      goto LABEL_3;
    case 4:
      v10 = 4;
LABEL_3:
      v11 = SysCtxGetCachedContextBaseKey(*a1, v10, &v14);
      v4 = v14;
      v6 = v11;
      goto LABEL_4;
    case 5:
      v4 = a1[2];
      goto LABEL_9;
    case 6:
      v4 = a1[3];
      goto LABEL_9;
    case 7:
      v4 = a1[4];
      goto LABEL_9;
    case 8:
      v4 = a1[5];
      goto LABEL_9;
    case 9:
      v4 = a1[6];
      goto LABEL_9;
    case 10:
      v4 = a1[7];
      goto LABEL_9;
    case 11:
      v4 = a1[8];
      goto LABEL_9;
    case 12:
      v4 = a1[9];
LABEL_9:
      v14 = v4;
      goto LABEL_5;
    default:
      v6 = -1073741811;
LABEL_4:
      if ( v6 < 0 )
        return v6;
LABEL_5:
      if ( v4 )
      {
        *a3 = v4;
        return v6;
      }
      if ( a2 >= 5 && a2 <= 12 )
      {
        v6 = SysCtxGetCachedContextBaseKey(*a1, 4, v15);
        if ( v6 >= 0 )
        {
          switch ( a2 )
          {
            case 5:
              v9 = L"Enum";
              v5 = PnpGetEnumSecurityDescriptor();
              if ( v5 )
                break;
              return -1073741595;
            case 6:
              v9 = L"Services";
              goto LABEL_18;
            case 7:
              v9 = L"Control\\Class";
              goto LABEL_18;
            case 8:
              v9 = L"Control\\DeviceClasses";
              goto LABEL_18;
            case 9:
              v9 = L"Control\\DeviceContainers";
              goto LABEL_18;
            case 10:
              v9 = L"Control\\CriticalDeviceDatabase";
              goto LABEL_18;
            case 11:
              v9 = L"Control\\CoDeviceInstallers";
              goto LABEL_18;
            case 12:
              v9 = L"Hardware Profiles";
LABEL_18:
              v5 = 0;
              break;
            default:
              v6 = -1073741811;
              break;
          }
          if ( v6 >= 0 )
          {
            v6 = SysCtxRegCreateTree(*a1, v15[0], v9, 0, 0x2000000, v5);
            if ( v6 >= 0 )
            {
              v13 = v14;
              switch ( a2 )
              {
                case 5:
                  a1[2] = v14;
                  break;
                case 6:
                  a1[3] = v14;
                  break;
                case 7:
                  a1[4] = v14;
                  break;
                case 8:
                  a1[5] = v14;
                  break;
                case 9:
                  a1[6] = v14;
                  break;
                case 10:
                  a1[7] = v14;
                  break;
                case 11:
                  a1[8] = v14;
                  break;
                case 12:
                  a1[9] = v14;
                  break;
                default:
                  v6 = -1073741811;
                  break;
              }
              if ( v6 >= 0 )
                *a3 = v13;
            }
          }
          if ( v5 )
            ExFreePoolWithTag(v5);
        }
        return v6;
      }
      return sub_7C6B24();
  }
}

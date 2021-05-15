// EtwpPsProvTracePriority 
 
int EtwpPsProvTracePriority(int result, int a2, ...)
{
  int *v2; // r2
  int v3; // [sp+20h] [bp-68h] BYREF
  int v4; // [sp+24h] [bp-64h] BYREF
  int v5[19]; // [sp+28h] [bp-60h] BYREF
  int varg_r2; // [sp+80h] [bp-8h] BYREF
  va_list varg_r2a; // [sp+80h] [bp-8h]
  va_list varg_r3; // [sp+84h] [bp-4h] BYREF

  va_start(varg_r3, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(varg_r3, _DWORD);
  switch ( a2 )
  {
    case 1328:
      v2 = ThreadCpuPriorityChange;
      break;
    case 1329:
      v2 = ThreadCpuBasePriorityChange;
      break;
    case 1331:
      v2 = ThreadPagePriorityChange;
      break;
    case 1332:
      v2 = ThreadIoPriorityChange;
      break;
    default:
      return result;
  }
  v4 = *(_DWORD *)(result + 876);
  v5[0] = (int)&v4;
  v5[1] = 0;
  v5[2] = 4;
  v5[3] = 0;
  v3 = *(_DWORD *)(result + 880);
  v5[4] = (int)&v3;
  v5[5] = 0;
  v5[6] = 4;
  v5[7] = 0;
  va_copy((va_list)&v5[8], varg_r2a);
  v5[9] = 0;
  v5[10] = 1;
  v5[11] = 0;
  va_copy((va_list)&v5[12], varg_r3);
  v5[13] = 0;
  v5[14] = 1;
  v5[15] = 0;
  return EtwWriteEx(EtwpPsProvRegHandle, dword_61A934, (int)v2, (int)&EtwpPsProvRegHandle, 0, 0, 1, 0, 0, 4, (int)v5);
}

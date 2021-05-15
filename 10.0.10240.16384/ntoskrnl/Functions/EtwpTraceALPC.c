// EtwpTraceALPC 
 
int *__fastcall EtwpTraceALPC(int *result, int a2)
{
  int *v2; // [sp+8h] [bp-20h] BYREF
  int v3; // [sp+Ch] [bp-1Ch]
  int v4; // [sp+10h] [bp-18h]
  int v5; // [sp+14h] [bp-14h]

  switch ( result[2] )
  {
    case 1:
      v2 = result + 3;
      v3 = 0;
      v4 = 4;
      v5 = 0;
      result = EtwTraceKernelEvent((int *)&v2, 1, 0x100000u, 6689, 4200706);
      break;
    case 2:
      v2 = result + 3;
      v3 = 0;
      v4 = 4;
      v5 = 0;
      result = EtwTraceKernelEvent((int *)&v2, 1, 0x100000u, 6690, 4200706);
      break;
    case 3:
      v2 = result + 3;
      v3 = 0;
      v4 = 4;
      v5 = 0;
      result = EtwTraceKernelEvent((int *)&v2, 1, 0x100000u, 6691, 4200706);
      break;
    case 4:
      v2 = result + 3;
      v3 = 0;
      v4 = a2 - 12;
      v5 = 0;
      result = EtwTraceKernelEvent((int *)&v2, 1, 0x100000u, 6692, 4200706);
      break;
    case 5:
      v2 = result + 3;
      v3 = 0;
      v4 = 4;
      v5 = 0;
      result = EtwTraceKernelEvent((int *)&v2, 1, 0x100000u, 6693, 4200706);
      break;
    case 6:
      v2 = result + 3;
      v3 = 0;
      v4 = 4;
      v5 = 0;
      result = EtwTraceKernelEvent((int *)&v2, 1, 0x100000u, 6694, 4200706);
      break;
    case 7:
      v2 = result + 3;
      v3 = 0;
      v4 = 4;
      v5 = 0;
      result = EtwTraceKernelEvent((int *)&v2, 1, 0x100000u, 6695, 4200706);
      break;
    case 8:
      v2 = result + 3;
      v3 = 0;
      v4 = 8;
      v5 = 0;
      result = EtwTraceKernelEvent((int *)&v2, 1, 0x100000u, 6696, 4200706);
      break;
    case 9:
      v2 = result + 3;
      v3 = 0;
      v4 = 4;
      v5 = 0;
      result = EtwTraceKernelEvent((int *)&v2, 1, 0x100000u, 6697, 4200706);
      break;
    default:
      return result;
  }
  return result;
}
